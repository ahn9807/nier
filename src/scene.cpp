//
//  scene.cpp
//  nier
//
//  Created by Junho on 2020/04/08.
//
#include <nier/scene.h>
#include <nier/automata.h>

NIER_NAMESPACE_BEGIN

void Scene::SetAutomata(Automata *automata) {
    this->m_automata = automata;
}

Automata* Scene::GetAutomata() {
    return this->m_automata;
}

NIER_NAMESPACE_END
