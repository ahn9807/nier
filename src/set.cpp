//
//  set.cpp
//  nier
//
//  Created by Junho on 2020/04/08.
//

#include <nier/set.h>

NIER_NAMESPACE_BEGIN

void Set::Insert(NierObject *a) {
    m_object.insert(a);
}

NIER_NAMESPACE_END
