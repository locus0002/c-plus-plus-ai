#ifndef BAR_FLY
#define BAR_FLY
//------------------------------------------------------------------------
//
//  Name:   BarFly.h
//
//  Desc:   A class defining a bar fly.
//
//  Author: Vladimir Aca 2020
//
//------------------------------------------------------------------------

#include "BaseGameEntity.h"
#include "Locations.h"
#include "../Common/misc/ConsoleUtils.h"
#include "BarFlyOwnedStates.h"
#include "../Common/FSM/StateMachine.h"

// class State;
struct Telegram;

//the amount of sobriety
const int DrunkLevel         = -5;
//the max amount of drinks
const int MaxDrinks          = 4;
//above this value a miner is tired
const int TirednessThresholdBF = 5;

class BarFly: public BaseGameEntity {
    private:
        StateMachine<BarFly>* m_pStateMachine;
        location_type         m_Location;
        int                   m_Sobriety;
        int                   m_Drinks;
        int                   m_Fatigue;

    public:
        BarFly(int id): m_Location(barflyHome),
                        m_Sobriety(0),
                        m_Drinks(0),
                        m_Fatigue(0),
                        BaseGameEntity(id) {

            this->m_pStateMachine = new StateMachine<BarFly>(this);
            this->m_pStateMachine->SetCurrentState(GoHomeNRecovery::Instance());
        }
        ~BarFly() { delete this->m_pStateMachine; }
        void Update();
        virtual bool HandleMessage(const Telegram& msg);
        StateMachine<BarFly>* GetFSM() const { return this->m_pStateMachine; }

        location_type Location() { return this->m_Location; }
        void changeLocation(location_type newLocation) { this->m_Location = newLocation; }

        int Sobriety() const { return this->m_Sobriety; }
        bool isDrunk() const { return this->m_Sobriety < DrunkLevel; }
        void increaseSobriety() { this->m_Sobriety++; }
        void decreaseSobriety() { this->m_Sobriety--; }

        int Drinks() const { return this->m_Drinks; }
        void resetDrinks() { this->m_Drinks = 0; }
        void increaseDrinks() { this->m_Drinks++; }

        bool Fatigued() const { return this->m_Fatigue > TirednessThresholdBF; }
        int Fatigue() const { return this->m_Fatigue; }
        void increaseFatigue() { this->m_Fatigue++; }
        void decreaseFatigue() { this->m_Fatigue--; }
};

#endif