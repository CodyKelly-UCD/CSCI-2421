#include "dataTypes.hpp"

ostream& operator<< (ostream& out, const awardStruct award)
{
    cout << "Award name: " << award.awardName << endl;
    cout << "Film: " << award.filmName << endl;
    cout << "Year: " << award.year << endl;
    cout << "Winner: ";
    if (award.winner)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    cout << endl;
    return out;
}

ostream& operator<< (ostream& out, const vector<awardStruct> *awards)
{
    int count = 1;
    for (auto award : *awards)
    {
        cout << "Award #" << count++ << endl;
        cout << award;
    }
    return out;
}
