//------------------------------------------------------------------------
//
//  Name:   BarFly.cpp
//
//  Desc:   Definitions of missing functions in BarFly.h
//
//  Author: Vladimir Aca 2020
//
//------------------------------------------------------------------------
#include "BarFly.h"

void BarFly::Update() {
    SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    m_pStateMachine->Update();
}

bool BarFly::HandleMessage(const Telegram& msg) {
    return m_pStateMachine->HandleMessage(msg);
}