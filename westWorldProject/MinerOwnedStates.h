#include "State.h"
#include "Minner.h"

class EnterMineAndDigForNugget: public State<Minner>
{
    private:
        EnterMineAndDigForNugget(){}
    public:
        static EnterMineAndDigForNugget* Instance();
        virtual void Enter(Minner* pMiner);
        virtual void Execute(Minner* pMiner);
        virtual void Exit(Minner* pMiner);
};