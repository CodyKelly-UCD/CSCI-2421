#ifndef dataTypes_hpp
#define dataTypes_hpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct movieData
{
    
};

struct nominationData
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

ostream& operator<< (ostream& out, const vector<awardStruct> *awards);

#endif /* dataTypes_hpp */
