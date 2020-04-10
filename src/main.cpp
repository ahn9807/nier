/*
Load AUTOMATA information from xml and parse it.
edited by juno 2020/4/6
 */
#include <nier/main.h>
#include <nier/scene.h>
#include "automata_dfa.cpp"
#include <nier/automata.h>
#include <nier/parser.h>

using namespace std;
using namespace tinyxml2;
using namespace nier;

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Syntax error %s <scene.xml>\n", argv[0]);
        return -1;
    }
    
    Scene* scene = LoadFromXML(argv[1]);
    
    if(scene == nullptr) {
        printf("Loading XML Error... process terminated!\n");
        return -1;
    }
    
    if(argc  == 3) {
        printf("Result: %s\n", scene->GetAutomata()->Process(scene, argv[2]) == true ? "Accepted" : "Rejected");
    } else {
        printf("Plase input the language you want to check\n");
        std::string lang;
        std::cin >> lang;
        printf("Result: %s\n", scene->GetAutomata()->Process(scene, lang) == true ? "Accepted" : "Rejected");
    }

    return 0;
}

