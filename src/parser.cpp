//
//  parser.cpp
//  nier
//
//  Created by Junho on 2020/04/08.
//

#include <nier/parser.h>
#include "automata_dfa.cpp"

using namespace std;
using namespace tinyxml2;
using namespace nier;

NIER_NAMESPACE_BEGIN

Scene* LoadFromXML(char* path_to_file) {
    Scene* scene = new Scene();
    string automata_type;
    XMLDocument doc;
    
    if(XML_SUCCESS == doc.LoadFile(path_to_file)) {
        XMLNode *node = doc.FirstChild();
        XMLElement* element;
        
        //Automata 종류 파악
        element = node->FirstChildElement("automata");
        automata_type = element->Attribute("type");
        
        if(automata_type == "dfa") {
            printf("DFA Automata\n");
            scene->SetAutomata(new Automata_dfa());
        }
        
        //internal state
        if(node->FirstChildElement("internal")) {
            element = node->FirstChildElement("internal");
            std::string temp = element->Attribute("value");
            printf("Internal States: %s\n",temp.c_str());
            scene->m_internalState = new vector<std::string>();
            split(temp, scene->m_internalState);
        } else {
            printf("Loading xml ... internal states are not contained!\n");
        }
        
        //input alphabet
        if(node->FirstChildElement("alphabet")) {
            element = node->FirstChildElement("alphabet");
            std::string temp = element->Attribute("value");
            printf("Input Alphabets: %s\n",temp.c_str());
            scene->m_inputAlphabet = new vector<std::string>();
            split(temp, scene->m_inputAlphabet);
        } else {
            printf("Loading xml ... input alpahbets are not contained!\n");
        }
        
        //transition functions
        if(node->FirstChildElement("transition")) {
            scene->m_transitionFunction = new Transition();
            element = node->FirstChildElement("transition");
            XMLElement* element_ = element->FirstChildElement("set");
            while(element_ != nullptr) {
                std::string startNode = element_->Attribute("start");
                std::string inputString = element_->Attribute("input");
                std::string outputString = element_->Attribute("output");
                std::vector<std::string> input;
                split(inputString, &input);
                std::vector<std::string> output;
                split(outputString, &output);
                printf("delta function: {%s,(%s)}->(%s)\n", startNode.c_str(),inputString.c_str(),outputString.c_str());
                scene->m_transitionFunction->PutDeltaFunction(startNode, input, output);
                element_ = element_->NextSiblingElement();
            }
        }
        
        //initial state
        if(node->FirstChildElement("initial")) {
            element = node->FirstChildElement("initial");
            std::string temp = element->Attribute("value");
            printf("Initial States: %s\n",temp.c_str());
            scene->m_initialState = new vector<std::string>();
            split(temp, scene->m_initialState);
        } else {
            printf("Loading xml ... initial states are not contained!\n");
        }
        
        //final state
        if(node->FirstChildElement("final")) {
            element = node->FirstChildElement("final");
            std::string temp = element->Attribute("value");
            printf("Final States: %s\n",temp.c_str());
            scene->m_finalState = new vector<std::string>();
            split(temp, scene->m_finalState);
        } else {
            printf("Loading xml ... final states are not contained!\n");
        }
        
    } else {
        printf("Load xml error %s", path_to_file);
        return nullptr;
    }
    
    return scene;
}


NIER_NAMESPACE_END
