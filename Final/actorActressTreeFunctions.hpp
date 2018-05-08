#ifndef actorActressTreeFunctions_hpp
#define actorActressTreeFunctions_hpp
#include "Node.h"
#include "dataTypes.hpp"
#include "functions.hpp"

void modifyAward(awardStruct *award);

void modifyAANode(Node<vector<awardStruct>*, string> *node, actorActressTree *aaTree);

Node<vector<awardStruct> *, string>* partialAANodeSearch(actorActressTree *aaTree, string searchTerm);

Node<vector<awardStruct> *, string>* searchForAANode(actorActressTree *aaTree);

void aaDatabaseMenu(actorActressTree *aaTree);

vector<actorActressData> getAADataFromFile(BSTree<vector<awardStruct> *, string> *aaTree);

#endif /* actorActressTreeFunctions_hpp */
