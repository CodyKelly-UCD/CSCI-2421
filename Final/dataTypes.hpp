#ifndef dataTypes_hpp
#define dataTypes_hpp

#include <string>
#include <vector>
#include <iostream>
#include "BSTree.h"

using namespace std;

struct movieData
{
    
};

struct actorActressData
{
    string name = "";
    string award = "";
    bool winner = false;
    int year = 0;
    string film = "";
};

struct awardStruct
{
    string awardName;
    string filmName;
    int year;
    bool winner;
    friend ostream& operator<< (ostream& out, const vector<awardStruct> *awards);
};

struct movieStruct
{
    
};

typedef BSTree<vector<awardStruct> *, string> actorActressTree;
typedef BSTree<vector<movieStruct> *, string> movieTree;

ostream& operator<< (ostream& out, const vector<awardStruct> *awards);
ostream& operator<< (ostream& out, awardStruct awards);

#endif /* dataTypes_hpp */
