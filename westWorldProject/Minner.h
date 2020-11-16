#include "BaseGameEntity.h"
#include "State.h"

class Minner: public BaseGameEntity
{
    private:
        State* m_pCurrentState;
        location_type m_Location;
        int m_iGoldCarried;
        int m_iMoneryInBank;
        int m_iThirst;
        int m_iFatigue;
    public:
        Minner(int ID);
        ~Minner();
        void Update();
        void ChangeState(State* pNewState);
};