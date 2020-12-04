#ifndef BARFLY_OWN_STATES_H
#define BARFLY_OWN_STATES_H

#include "../Common/FSM/State.h"

class BarFly;
struct Telegram;

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