#include "MinerOwnedStates.h"
#include <iostream>
using namespace std;

void EnterMineAndDigForNugget::Enter(Minner* pMiner) {

    if (pMiner->Location() != goldmine) {
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": Walkin to the gold mine";
        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Exit(Minner* pMiner) {

    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": Ah'm leavin' the gold mine with man pockets full o'sweet gold";
}

void EnterMineAndDigForNugget::Execute(Minner* pMiner) {

    pMiner->AddToGoldCarried(1);
    pMiner->IncreaseFatigue();
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": Pickin' up a nugget";
    if (pMiner->PocketsFull()) {
        pMiner->ChangeState(VisitBankAndDepositGold::Instance());
    }
    if (pMiner->Thirsty()) {
        pMiner->ChangeState(QuenchThirst::Instance());
    }
}
