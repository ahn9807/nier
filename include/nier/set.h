//
//  set.h
//  nier
//
//  Created by Junho on 2020/04/08.
//

#pragma once

#include "common.h"
#include "language.h"
#include "object.h"
#include "set.h"
#include <set>

NIER_NAMESPACE_BEGIN

class Set {
public:
    ~Set() {}
    void Insert(NierObject* a);
    NierObject Remove(NierObject* a);
    bool Find(NierObject a) {return false;}
    NierObject GetNext(NierObject* o);
private:
    std::set<NierObject*> m_object;
};


NIER_NAMESPACE_END
