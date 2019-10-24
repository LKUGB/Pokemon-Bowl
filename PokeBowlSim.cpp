#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int strtoi(string s) {
    return atoi(s.c_str());
}

int main() {

    vector<int> pokeNumber;

    ifstream inFS;
    // open file
    inFS.open("../Pokemon.dat");
    // check whether open file is successful
    if (!inFS.is_open()) {
        cout << "Unable to open Pokemon.dat" << endl;
        return -1;
    }

    string line;

    // skips first row
    getline(inFS, line);
    // read in each line until end of file
    while (getline(inFS, line)) {
        istringstream pokemon(line);
        string substring;

        // read in Pokemon number
        getline(pokemon, substring, ',');
        int num = strtoi(substring);

        // read in Pokemon name
        getline(pokemon, substring, ',');
        string name = substring;

        // ignore next few columns
        getline(pokemon, substring, ',');
        getline(pokemon, substring, ',');
        getline(pokemon, substring, ',');
        getline(pokemon, substring, ',');

        // read in attack
        getline(pokemon, substring, ',');
        int attack = strtoi(substring);

        // read in defense
        getline(pokemon, substring, ',');
        int defense = strtoi(substring);

        // read in special attack
        getline(pokemon, substring, ',');
        int spAttack = strtoi(substring);

        // read in special defense
        getline(pokemon, substring, ',');
        int spDefense = strtoi(substring);

        // assign a random Combat Power
        int combatPower = rand() % 3991 + 10;

        bool isDuplicate = false;

        for( int i = 0; i < pokeNumber.size(); i++ ) {
            if( num == pokeNumber.at(i)) {
                isDuplicate = true;
            }
        }

        // At this point, read in a file with:
        // num (int), name (string), attack (int), defense (int), spAttack (int), spDefense (int)
        // Initialized combatPower (int) to a random value 10 to 4000

        // FINISH ME

    }
    // close file
    inFS.close();


    // FINISH ME
}