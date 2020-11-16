#include "Minner.h"

class State
{
    private:
        
    public:
        State(/* args */);
        virtual ~State() {}
        virtual void Enter(Minner*) = 0;
        virtual void Execute(Minner*) = 0;
        virtual void Exit(Minner*) = 0;
};

State::State(/* args */)
{
}

State::~State()
{
}
