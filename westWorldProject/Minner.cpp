#include "Minner.h"

void Minner::Update() {
    this->m_iThirst += 1;
    if (this->m_pCurrentState) {
        this->m_pCurrentState->Execute(this);
    }
}
void Minner::ChangeState(State* pNewState) {
    assert(this->m_pCurrentState && pNewState);
    this->m_pCurrentState->Exit(this);
    this->m_pCurrentState = pNewState;
    this->m_pCurrentState->Enter(this);
}