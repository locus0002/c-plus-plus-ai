#include "Vehicle.h"
#include "2d/C2DMatrix.h"
#include "2d/Geometry.h"
#include "SteeringBehaviors.h"
#include "2d/Transformations.h"
#include "GameWorld.h"
#include "misc/CellSpacePartition.h"
#include "misc/cgdi.h"

using std::vector;
using std::list;


//----------------------------- ctor -------------------------------------
//------------------------------------------------------------------------
Vehicle::Vehicle(GameWorld* world,
               Vector2D position,
               double    rotation,
               Vector2D velocity,
               double    mass,
               double    max_force,
               double    max_speed,
               double    max_turn_rate,
               double    scale):    MovingEntity(position,
                                                 scale,
                                                 velocity,
                                                 max_speed,
                                                 Vector2D(sin(rotation),-cos(rotation)),
                                                 mass,
                                                 Vector2D(scale,scale),
                                                 max_turn_rate,
                                                 max_force),

                                       m_pWorld(world),
                                       m_vSmoothedHeading(Vector2D(0,0)),
                                       m_bSmoothingOn(false),
                                       m_dTimeElapsed(0.0),
                                       m_bLeader(false),
                                       m_bRanAway(false),
                                       m_bTail(true)
{  
  InitializeBuffer();

  //set up the steering behavior class
  m_pSteering = new SteeringBehavior(this);    

  //set up the smoother
  m_pHeadingSmoother = new Smoother<Vector2D>(Prm.NumSamplesForSmoothing, Vector2D(0.0, 0.0)); 
  
 
}


//---------------------------- dtor -------------------------------------
//-----------------------------------------------------------------------
Vehicle::~Vehicle()
{
  delete m_pSteering;
  delete m_pHeadingSmoother;
}

//------------------------------ Update ----------------------------------
//
//  Updates the vehicle's position from a series of steering behaviors
//------------------------------------------------------------------------
void Vehicle::Update(double time_elapsed)
{    
  //update the time elapsed
  m_dTimeElapsed = time_elapsed;

  //keep a record of its old position so we can update its cell later
  //in this method
  Vector2D OldPos = Pos();


  Vector2D SteeringForce;

  //calculate the combined force from each steering behavior in the 
  //vehicle's list
  SteeringForce = m_pSteering->Calculate();
    
  //Acceleration = Force/Mass
  Vector2D acceleration = SteeringForce / m_dMass;

  //update velocity
  m_vVelocity += acceleration * time_elapsed; 

  //make sure vehicle does not exceed maximum velocity
  m_vVelocity.Truncate(m_dMaxSpeed);

  //update the position
  m_vPos += m_vVelocity * time_elapsed;

  //update the heading if the vehicle has a non zero velocity
  
  if (m_vVelocity.LengthSq() > 0.00000001)
  {    
    m_vHeading = Vec2DNormalize(m_vVelocity);
    m_vSide = m_vHeading.Perp();
  }

  //EnforceNonPenetrationConstraint(this, World()->Agents());

  //treat the screen as a toroid
  WrapAround(m_vPos, m_pWorld->cxClient(), m_pWorld->cyClient());

  //update the vehicle's current cell if space partitioning is turned on
  if (Steering()->isSpacePartitioningOn())
  {
    World()->CellSpace()->UpdateEntity(this, OldPos);
  }

  if (isSmoothingOn())
  {
    m_vSmoothedHeading = m_pHeadingSmoother->Update(Heading());
  }
}


//-------------------------------- Render -------------------------------------
//-----------------------------------------------------------------------------
void Vehicle::Render(const bool& isCircle)
{ 
  //a vector to hold the transformed vertices
  static std::vector<Vector2D>  m_vecVehicleVBTrans;

  //render neighboring vehicles in different colors if requested
  if (m_pWorld->RenderNeighbors())
  {
    if (ID() == 0) gdi->RedPen();
    else if(IsTagged()) gdi->GreenPen();
    else gdi->BluePen();
  }

  else
  {
    gdi->BluePen();
  }

  if (Steering()->isInterposeOn())
  {
    gdi->RedPen();
  }

  if (Steering()->isHideOn())
  {
    gdi->GreenPen();
  }
  
  if (Steering()->isMoveStraightOn()) 
  {
      gdi->DarkGreenBrush();
      gdi->DarkGreenPen();
  }

  if (isSmoothingOn())
  { 
    m_vecVehicleVBTrans = WorldTransform(m_vecVehicleVB,
                                         Pos(),
                                         SmoothedHeading(),
                                         SmoothedHeading().Perp(),
                                         Scale());
  }

  else
  {
    m_vecVehicleVBTrans = WorldTransform(m_vecVehicleVB,
                                         Pos(),
                                         Heading(),
                                         Side(),
                                         Scale());
  }

  //-----------------------------------------------------------------
  //  Vladimir Aca
  //  I had to use a trick to avoid the heads (triangles) of the 
  //  vehicles transform into small dots due to the abrupt
  //  changes of directions because of the forces that act on 
  //  the vehicle. That is the reason because the sheep are black dots
  //-----------------------------------------------------------------
  if (isCircle) {
      gdi->BlackBrush();
      gdi->BlackPen();
      gdi->Circle(Pos(), 3);
  }
  else {
      gdi->ClosedShape(m_vecVehicleVBTrans);
  }
  //render any visual aids / and or user options
  if (m_pWorld->ViewKeys())
  {
    Steering()->RenderAids();
  }
}
//----------------------------- OccurredDisplacement -----------------------------
//
//  validates if occurred a change of vehicle's position
//-----------------------------------------------------------------------------
bool Vehicle::OccurredDisplacement(const Vector2D& oldPos)
{
    int oldX = trunc(oldPos.x);
    int oldY = trunc(oldPos.y);
    int newX = trunc(m_vPos.x);
    int newY = trunc(m_vPos.y);
    return oldX != newX && oldY != newY;
}


//----------------------------- InitializeBuffer -----------------------------
//
//  fills the vehicle's shape buffer with its vertices
//-----------------------------------------------------------------------------
void Vehicle::InitializeBuffer()
{
  const int NumVehicleVerts = 3;

  Vector2D vehicle[NumVehicleVerts] = {Vector2D(-1.0f,0.6f),
                                        Vector2D(1.0f,0.0f),
                                        Vector2D(-1.0f,-0.6f)};

  //setup the vertex buffers and calculate the bounding radius
  for (int vtx=0; vtx<NumVehicleVerts; ++vtx)
  {
    m_vecVehicleVB.push_back(vehicle[vtx]);
  }
}