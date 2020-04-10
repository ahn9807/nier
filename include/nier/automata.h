//
//  automata.h
//  nier
//
//  Created by Junho on 2020/04/08.
//

#pragma once
#include "common.h"
#include "transition.h"

NIER_NAMESPACE_BEGIN

class Scene;

class Automata {
public:
    virtual ~Automata() {}
    virtual bool Process(const Scene* scene, std::string input) { return false; }
};

NIER_NAMESPACE_END


