# Steering Behavior - Flock Of Sheep
> I implemented a simulation of the behavior of a herding dog and a flock of sheeps

## Herding Dog (Triangle)

- The moves of this agent are controlled by a user (keyboard inputs)

## The flock of Sheep (Black Dots)

- These agents have a combination of behaviors
- The agents can form groups if these are enough close to each of them
- If some agent of a group identifies the herding dog because this one is in the range of the vision of the agent (sheep), the agent will try to stay away from the herding dog
- If some agent of a group identifies that some of their neighbors (sheep) are running away, the agent will start to follow them
- The agents (sheep) that already saw the herding dog, will try to stay in the last position where the herding dog guided them, otherwise, the agents (sheep) can walk around

## Before
<p align="center" >
    <img src="https://github.com/locus0002/c-plus-plus-ai/blob/master/images/flock_sheep1.png?raw=true" />
</p>

## After
<p align="center" >
    <img src="https://github.com/locus0002/c-plus-plus-ai/blob/master/images/flock_sheep2.png?raw=true" />
</p>

If you are curious about the code, here is the list of the modifications and new implementations
- [MoveStraight](https://github.com/locus0002/c-plus-plus-ai/blob/791f34870d1b75a3a0e7ab2af5a5d545f6d8e3ba/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1436)
- [Modification in Flee Behavior](https://github.com/locus0002/c-plus-plus-ai/blob/791f34870d1b75a3a0e7ab2af5a5d545f6d8e3ba/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L746)
- The class [Vehicle.cpp](Buckland_Chapter3-Steering%20Behaviors/Vehicle.cpp) and [Vehicle.h](Buckland_Chapter3-Steering%20Behaviors/Vehicle.h) was modified to add new features that help to implement the "flock of sheep behavior"
- [Control by the keyboard](https://github.com/locus0002/c-plus-plus-ai/blob/791f34870d1b75a3a0e7ab2af5a5d545f6d8e3ba/Buckland_Chapter3-Steering%20Behaviors/SteeringBehaviors.cpp#L1819)
- [TurnDirection](https://github.com/locus0002/c-plus-plus-ai/blob/791f34870d1b75a3a0e7ab2af5a5d545f6d8e3ba/Buckland_Chapter3-Steering%20Behaviors/MovingEntity.h#L156)

You can watch it in action, just hit the [link](https://www.linkedin.com/feed/update/urn:li:activity:6759507835865878529/)