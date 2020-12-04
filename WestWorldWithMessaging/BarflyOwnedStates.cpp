#include "BarflyOwnedStates.h"
#include "../Common/FSM/State.h"
#include "BarFly.h"
#include "Locations.h"
#include "EntityNames.h"
#include <iostream>
#include "../Common/misc/utils.h"
#include "../Common/Messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"

using namespace std;

// ------------------------------------ methods for ENTERSALON
EnterSalon* EnterSalon::Instance() {
    static EnterSalon instance;
    return &instance;
}

void EnterSalon::Enter(BarFly* barfly) {
    if (barfly->Location() != saloon) {
        cout << endl << GetNameOfEntity(barfly->ID()) << ": Enter to the salon";
        barfly->changeLocation(saloon);
    }
}

void EnterSalon::Execute(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": Havin' fun";
    if (RandBool()) {
        barfly->GetFSM()->ChangeState(Dance::Instance());
    } else {
        barfly->GetFSM()->ChangeState(Drink::Instance());
    }
}

void EnterSalon::Exit(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": Ready to dance and drink HARD!";
}

bool EnterSalon::OnMessage(BarFly* barfly, const Telegram& msg) {
    return false;
}

//------------------------------------------------- methods for Dancing
Dance* Dance::Instance() {
    static Dance instance;
    return &instance;
}

void Dance::Enter(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": Let's go to the dance floor";
}
void Dance::Execute(BarFly* barfly) {
    barfly->increaseFatigue();
    cout << endl << GetNameOfEntity(barfly->ID()) << ": Dancin' until down";
    if (barfly->Fatigued() || barfly->isDrunk()) {
        barfly->GetFSM()->ChangeState(GoHomeNRecovery::Instance());
    }
    else {
        barfly->GetFSM()->ChangeState(Drink::Instance());
    }
}
void Dance::Exit(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": The twerkin' is so intense";
}

bool Dance::OnMessage(BarFly* barfly, const Telegram& msg) {
    return false;
}

//---------------------------------------------------- methods for drinking
Drink* Drink::Instance() {
    static Drink instance;
    return &instance;
}

void Drink::Enter(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": Let's have vodka, CHEERS!";
}

void Drink::Execute(BarFly* barfly) {
    barfly->decreaseSobriety();
    barfly->increaseDrinks();
    cout << endl << GetNameOfEntity(barfly->ID()) << ": glug! glug! glug!";
    if (barfly->isDrunk()) {
        cout << endl << GetNameOfEntity(barfly->ID()) << ": What it's your problem!!!";
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
                                barfly->ID(),
                                ent_Miner_Bob,
                                Msg_Insult,
                                NULL);
    } else {
        if (RandBool()) {
            barfly->GetFSM()->ChangeState(Dance::Instance());
        } else {
            cout << endl << GetNameOfEntity(barfly->ID()) << ": More vodka, CHEERS!";
        }
    }
    
}
void Drink::Exit(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": Let's have FUN!!";
}
bool Drink::OnMessage(BarFly* barfly, const Telegram& msg) {
    SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    switch (msg.Msg)
    {
        case Msg_ReplyInsult:
            cout << endl << GetNameOfEntity(barfly->ID()) << ": Let's fight m#@$ f@#$!!";
            barfly->GetFSM()->ChangeState(FightBF::Instance());
            return true;
    }
    return false;
}

//----------------------------------------------------- methods for HOME

GoHomeNRecovery* GoHomeNRecovery::Instance() {
    static GoHomeNRecovery instance;
    return &instance;
}

void GoHomeNRecovery::Enter(BarFly* barfly) {
    if (barfly->Location() != barflyHome) {
        cout << endl << GetNameOfEntity(barfly->ID()) << ": Home sweet home";
        barfly->changeLocation(barflyHome);
    }
}

void GoHomeNRecovery::Execute(BarFly* barfly) {
    if (barfly->Sobriety() != 0)  {
        barfly->increaseSobriety();
    }
    if (barfly->Fatigue() != 0)  {
        barfly->decreaseFatigue();
    }
    if (barfly->Fatigue() == 0 && barfly->Sobriety() == 0) {
        cout << endl << GetNameOfEntity(barfly->ID()) << ": 'am rested very well";
        barfly->GetFSM()->ChangeState(EnterSalon::Instance());
    } else {
        cout << endl << GetNameOfEntity(barfly->ID()) << ": I need to rest and to sleep well";
    }
}
void GoHomeNRecovery::Exit(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": It's time to hang out";
}
bool GoHomeNRecovery::OnMessage(BarFly* barfly, const Telegram& msg) {
    return false;
}

//----------------------------------------------------- methods for FightBF

FightBF* FightBF::Instance() {
    static FightBF instance;
    return &instance;
}

void FightBF::Enter(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": Pum!" << endl << "Plum!" << endl << "Cataplam!";
}
void FightBF::Execute(BarFly* barfly) {
    barfly->increaseFatigue();
    if (barfly->Fatigued()) {
        cout << endl << GetNameOfEntity(barfly->ID()) << ": I surrender... you win!!";
        barfly->GetFSM()->ChangeState(GoHomeNRecovery::Instance());
    } else {
        cout << endl << GetNameOfEntity(barfly->ID()) << ": I have more for you!";
    }
}
void FightBF::Exit(BarFly* barfly) {
    cout << endl << GetNameOfEntity(barfly->ID()) << ": I lost... time to go home and recovery";
}
bool FightBF::OnMessage(BarFly* barfly, const Telegram& msg) {
    SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    switch (msg.Msg)
    {
        case Msg_FinishFight:
            cout << endl << GetNameOfEntity(barfly->ID()) << ": You win m@#$ f#$%!! :(";
            barfly->GetFSM()->ChangeState(GoHomeNRecovery::Instance());
            return true;
    }
    return false;
}