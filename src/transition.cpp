//
//  transition.cpp
//  nier
//
//  Created by Junho on 2020/04/08.
//

#include <nier/transition.h>

NIER_NAMESPACE_BEGIN

std::vector<std::string> Transition::Move(std::string start, std::string input) {
    for(int i=0;i<m_transitions->size();i++) {
        if(start == m_transitions->at(i).m_start) {
            return m_transitions->at(i).pairs.find(input)->second;
        }
    }
    
    return std::vector<std::string>();
}

NIER_NAMESPACE_END
