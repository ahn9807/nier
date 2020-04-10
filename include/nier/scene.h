//
//  scene.h
//  nier
//
//  Created by Junho on 2020/04/08.
//

#pragma once
#include "common.h"
#include "automata.h"
#include "object.h"
#include "transition.h"
#include <set>

NIER_NAMESPACE_BEGIN

class Scene {
public:
    void SetAutomata(Automata *automata);
    Automata* GetAutomata();
    std::vector<std::string>* m_internalState;
    std::vector<std::string>* m_inputAlphabet;
    Transition* m_transitionFunction;
    std::vector<std::string>* m_initialState;
    std::vector<std::string>* m_finalState;
private:
    Automata *m_automata;
};

NIER_NAMESPACE_END
