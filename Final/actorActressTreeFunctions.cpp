#include "actorActressTreeFunctions.hpp"

void modifyAward(awardStruct *award)
{
    int userChoice = 0;
    string menu =
    "What would you like to modify:\n"
    "1) Award name\n"
    "2) Film name\n"
    "3) Year\n"
    "4) Winner\n"
    "5) Back\n";
    
    while (userChoice != 5)
    {
        clearScreen();
        cout << *award;
        userChoice = getInput(menu, 5);
        
        switch (userChoice)
        {
            case 1:
            {
                cin.ignore();
                cout << "Enter a new name for this award: ";
                getline(cin, award->awardName);
                break;
            }
            case 2:
            {
                cout << "Enter a new name for the film: ";
                cin.ignore();
                getline(cin, award->filmName);
                break;
            }
            case 3:
            {
                award->year = getYearFromUser();
                break;
            }
            case 4:
            {
                award->winner = !award->winner;
                break;
            }
            default:
                break;
        }
    }
}

void modifyAANode(Node<vector<awardStruct>*, string> *node, actorActressTree *aaTree)
{
    int userChoice = 0;
    string menu1 =
    "What field would you like to modify:\n"
    "1) Actor/Actress name\n"
    "2) Awards\n"
    "3) Nothing - go back\n";
    clearScreen();
    userChoice = getInput(menu1, 3);
    
    switch (userChoice)
    {
        case 1:
        {
            string name;
            clearScreen();
            cout << "Please enter a new name for the actor/actress: ";
            cin.ignore();
            getline(cin, name);
            vector<awardStruct> *awards = node->Data();
            aaTree->deleteNode(node->Key());
            aaTree->addNode(name, awards);
            node = aaTree->findNode(name);
            modifyAANode(node, aaTree);
            break;
        }
        case 2:
        {
            int awardChoice = 0;
            while (awardChoice != -1)
            {
                vector<awardStruct> *awards = node->Data();
                awardStruct *award;
                clearScreen();
                cout << awards;
                awardChoice = getInput("Please enter the award number or 0 to go back: ", node->Data()->size(), false);
                if (awardChoice == 0)
                    return;
                award = &awards->at(awardChoice - 1);
                modifyAward(award);
            }
            break;
        }
        case 3:
            return;
            
        default:
            break;
    }
}

Node<vector<awardStruct> *, string>* partialAANodeSearch(actorActressTree *aaTree, string searchTerm)
{
    vector<Node<vector<awardStruct> *, string> *> vec, searchVec;
    aaTree->fillVector(vec);
    string str1, str2;
    int count = 1;
    int choice = 0;
    
    for (auto node : vec)
    {
        if (node->Key().find(searchTerm) != string::npos)
        {
            searchVec.push_back(node);
        }
    }
    
    if (searchVec.size() != 0)
    {
        clearScreen();
        for (auto node : searchVec)
        {
            cout << "Actor/Actress #" << count << endl;
            cout << "Actor/Actress Name: " << node->Key() << endl;
            cout << endl;
            count++;
        }
        
        choice = getInput("Please enter the number of the actor/actress: ", searchVec.size());
        
        return searchVec[choice - 1];
    }
    
    return nullptr;
}

void addAARecord(actorActressTree *aaTree)
{
    vector<awardStruct> *awards = new vector<awardStruct>;
    string name;
    
    clearScreen();
    cout << "Please enter a name for the actor/actress you'd like to add: ";
    cin.ignore();
    getline(cin, name);
    aaTree->addNode(name, awards);
}

Node<vector<awardStruct> *, string>* searchForAANode(actorActressTree *aaTree)
{
    Node<vector<awardStruct> *, string> *node = nullptr;
    int choice = 0;
    string searchMenu =
    "Would you like to perform a:\n"
    "1) Partial search\n"
    "2) Complete search\n";
    
    clearScreen();
    choice = getInput(searchMenu, 2);
    
    switch (choice)
    {
        case 1:
        {
            string searchTerm;
            clearScreen();
            cout << "Please enter search term: ";
            getline(cin, searchTerm);
            getline(cin, searchTerm);
            node = partialAANodeSearch(aaTree, searchTerm);
            if (node == nullptr)
            {
                clearScreen();
                cout << "Actor or actress with the name " << searchTerm
                << " not found. Please try again.\n\nPress enter to continue.";
                cin.get();
                node = searchForAANode(aaTree);
            }
            break;
        }
            
        case 2:
        {
            string searchTerm;
            clearScreen();
            cout << "Please enter search term: ";
            getline(cin, searchTerm);
            getline(cin, searchTerm);
            node = aaTree->findNode(searchTerm);
            if (node == nullptr)
            {
                clearScreen();
                cout << "Actor or actress with the name " << searchTerm
                << " not found. Please try again.\n\nPress enter to continue.";
                cin.get();
                node = searchForAANode(aaTree);
            }
            break;
        }
            
        default:
            break;
    }
    
    return node;
}

void searchAAFields()
{
    int choice = 0;
    string menuString =
    "What field would you like to search?\n"
    "1) Award name\n"
    "2) Film name\n"
    "3) Year\n"
    "4) Winner\n"
    "5) Back\n";
    vector<Node<vector<awardStruct> *, string>> vec, searchVec;
    
    choice = getInput(menuString, 5);
    switch (choice)
    {
        case 1:
        {
            
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        default:
            break;
    }
}

void aaDatabaseMenu(actorActressTree *aaTree)
{
    int menuChoice = 0;
    string menuString =
    "Would you like to:\n"
    "1) Add a record\n"
    "2) Search for and modify a record\n"
    "4) Search for and delete a field\n"
    "5) Sort by a field\n"
    "6) Perform a complete search on a field\n"
    "7) Perform a partial search on a field\n"
    "8) Save to .csv file\n"
    "9) Back";
    clearScreen();
    menuChoice = getInput(menuString, 9);
    
    switch (menuChoice)
    {
        case 1:
            addAARecord(aaTree);
            break;
            
        case 2:
            Node<vector<awardStruct> *, string> *aaNode;
            aaNode = searchForAANode(aaTree);
            modifyAANode(aaNode, aaTree);
            break;
            
        case 3:
        {
            Node<vector<awardStruct> *, string> *aaNode;
            aaNode = searchForAANode(aaTree);
            aaTree->deleteNode(aaNode->Key());
            break;
        }
            
        case 8:
        {
            ofstream aaFile("actor-actress.csv");
            aaTree->toFile(aaFile);
            aaFile.close();
            break;
        }
            
        case 9:
            return;
            break;
            
        default:
            aaDatabaseMenu(aaTree);
            break;
    }
}

vector<actorActressData> getAADataFromFile(BSTree<vector<awardStruct> *, string> *aaTree)
{
    vector<actorActressData> aadata;
    ifstream file("actor-actress.csv");
    
    // Ignore first line of file
    file.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while (!file.eof())
    {
        actorActressData newData;
        
        // Get year from file
        newData.year = getIntFromFile(file);
        
        // Get award name
        getline(file, newData.award, ',');
        
        // Get winner bool
        newData.winner = getBoolFromFile(file);
        
        // Get the name of the actor/actress who was considered
        getline(file, newData.name, ',');
        
        // Finally, get name of film
        getline(file, newData.film, '\n');
        
        // If there was a comma at the end of the film, we can ignore it
        if (newData.film.back() == ',')
        {
            newData.film.pop_back();
        }
        
        // Ignore the rest of the line
        eat_white(file);
        
        aadata.push_back(newData);
    }
    file.close();
    
    for (auto data : aadata)
    {
        awardStruct newAward;
        newAward.filmName = data.film;
        newAward.year = data.year;
        newAward.winner = data.winner;
        newAward.awardName = data.award;
        
        // Find actor
        auto actor = aaTree->findNode(data.name);
        if (actor == nullptr)
        {
            // If the actor doesn't exist yet, make a new one
            vector<awardStruct> *awards = new vector<awardStruct>;
            awards->push_back(newAward);
            aaTree->addNode(data.name, awards);
        }
        else
        {
            actor->Data()->push_back(newAward);
        }
    }
    
    return aadata;
}
