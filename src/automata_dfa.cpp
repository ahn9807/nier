//
//  automata_dfa.cpp
//  nier
//
//  Created by Junho on 2020/04/08.
//

#include <nier/automata.h>
#include <nier/scene.h>

NIER_NAMESPACE_BEGIN
class Automata_dfa : public Automata {
public:
    Automata_dfa() {}
    bool Process(const Scene* scene, std::string lang) {
        std::string finalNode = Move(scene, scene->m_initialState->front(), lang);
        for(int i=0;i<scene->m_finalState->size();i++) {
            if(finalNode == scene->m_finalState->at(i)) {
                return true;
            }
        }
        
        return false;
    }
    std::string Move(const Scene* scene, const std::string currentNode, std::string lang) {
        if(lang.length() == 0) {
            return currentNode;
        }
        
        std::string nextLang = lang;
        
        std::vector<std::string> nextNode = scene->m_transitionFunction->Move(currentNode, lang.substr(0,1));
        
        if(nextNode.size() == 0) {
            return EMPTY;
        }
        
        return Move(scene, nextNode.at(0), nextLang.erase(0,1));
    }
};
NIER_NAMESPACE_END
