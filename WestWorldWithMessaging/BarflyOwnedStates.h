#ifndef BARFLY_OWN_STATES_H
#define BARFLY_OWN_STATES_H

//------------------------------------------------------------------------
//
//  Name:   BarflyOwnedStates.h
//
//  Desc:   All barfly states are declared
//
//  Author: Vladimir Aca 2020
//
//------------------------------------------------------------------------

#include "../Common/FSM/State.h"

class BarFly;
struct Telegram;

//------------------------------------------------------------------
//  In this state, the barfly can change his state to drink or dance
//------------------------------------------------------------------
class EnterSalon: public State<BarFly> {
    private:
        EnterSalon() {}
        EnterSalon(const EnterSalon&);
        EnterSalon& operator=(const EnterSalon&);
    public:

        static EnterSalon* Instance();
        virtual void Enter(BarFly* barfly);
        virtual void Execute(BarFly* barfly);
        virtual void Exit(BarFly* barfly);
        virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};

//------------------------------------------------------------------
//  The barfly is having a good time dancing, but his tiredness and 
//  thirstiness can increase
//------------------------------------------------------------------
class Dance: public State<BarFly> {
    private:
        Dance() {}
        Dance(const Dance&);
        Dance& operator=(const Dance&);
    public:
        static Dance* Instance();
        virtual void Enter(BarFly* barfly);
        virtual void Execute(BarFly* barfly);
        virtual void Exit(BarFly* barfly);
        virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};

//------------------------------------------------------------------
//  After being drunk or hurt and beaten, the barfly has to be at 
//  home recovery until gets well
//------------------------------------------------------------------
class GoHomeNRecovery: public State<BarFly> {
    private:
        GoHomeNRecovery() {}
        GoHomeNRecovery(const GoHomeNRecovery&);
        GoHomeNRecovery& operator=(const GoHomeNRecovery&);
    public:
        static GoHomeNRecovery* Instance();
        virtual void Enter(BarFly* barfly);
        virtual void Execute(BarFly* barfly);
        virtual void Exit(BarFly* barfly);
        virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};

//------------------------------------------------------------------
//  During this state, the barfly can be involved in a fight because 
//  of his drinking  way or if he is lucky, he can come back to the 
//  dance floor 
//------------------------------------------------------------------
class Drink: public State<BarFly> {
    private:
        Drink() {}
        Drink(const Drink&);
        Drink& operator=(const Drink&);
    public:
        static Drink* Instance();
        virtual void Enter(BarFly* barfly);
        virtual void Execute(BarFly* barfly);
        virtual void Exit(BarFly* barfly);
        virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};
//------------------------------------------------------------------
//  Someone replies to his insults and results in a fight, the 
//  barfly has no chance to win it, because he is completely drunk,
//  and his tiredness increases which helps him to decide when to stop
//  fight or until his contender finishes the fight
//------------------------------------------------------------------

class FightBF: public State<BarFly> {
    private:
        FightBF() {}
        FightBF(const FightBF&);
        FightBF& operator=(const FightBF&);
    public:
        static FightBF* Instance();
        virtual void Enter(BarFly* barfly);
        virtual void Execute(BarFly* barfly);
        virtual void Exit(BarFly* barfly);
        virtual bool OnMessage(BarFly* barfly, const Telegram& msg);
};


#endif