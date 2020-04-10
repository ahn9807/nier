//
//  transition.h
//  nier
//
//  Created by Junho on 2020/04/08.
//

#pragma once

#include "common.h"
#include <map>
#include <unordered_map>

NIER_NAMESPACE_BEGIN

struct DeltaFunction {
    std::string m_start;
    std::unordered_map<std::string, std::vector<std::string> > pairs;
};

class Transition {
public:
    Transition() {m_transitions = new std::vector<DeltaFunction>();};
    ~Transition() {};
    void PutDeltaFunction(std::string startNode, std::vector<std::string> input, std::vector<std::string> output) {
        for(int i=0;i<m_transitions->size();i++) {
            if(m_transitions->at(i).m_start == startNode) {
                for(int j=0;j<input.size();j++) {
                    m_transitions->at(i).pairs[input.at(j)] = output;
                    return;
                }
            }
        }
        
        DeltaFunction df;
        df.m_start = startNode;
        for(int i=0;i<input.size();i++) {
            df.pairs[input.at(i)] = output;
        }
        m_transitions->push_back(df);
    }
    std::vector<std::string> Move(std::string startNode, std::string input);
    
private:
    std::vector<DeltaFunction>* m_transitions;
};

NIER_NAMESPACE_END
