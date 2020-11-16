#include "BaseGameEntity.h"
#include "State.h"
#include "StateMachine.h"

class Minner: public BaseGameEntity
{
    private:
        StateMachine<Minner>* m_pStateMachine;
        location_type m_Location;
        int m_iGoldCarried;
        int m_iMoneryInBank;
        int m_iThirst;
        int m_iFatigue;
    public:
        Minner(int id);
        ~Minner();
        void Update();
        void ChangeState(State<Minner>* pNewState);
        void RevertToPreviousState();
};