#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>
#include <array>

using namespace std;
/*
plant Spirea 10
flower Hydrangea 30 false lilac
flower Rose 6 false white
plant Mint 4
-1
==============================================
Plant 1 Information:
   Plant name: Spirea
   Cost: 10

Plant 2 Information:
   Plant name: Hydrangea
   Cost: 30
   Annual: false
   Color of flowers: lilac

Plant 3 Information:
   Plant name: Rose
   Cost: 6
   Annual: false
   Color of flowers: white

Plant 4 Information:
   Plant name: Mint
   Cost: 4

*/

// TODO: Define a PrintVector function that prints an vector of plant (or flower) object pointers
void PrintVector(vector<Plant*> garden) {

    Plant *p = new Plant();
    for (int i = 0; (unsigned)i < garden.size(); ++i) {
        cout << "Plant " << i + 1 << " Information:" << endl;
        p = garden.at(i);
        p->PrintInfo();
        cout << "\n";
    }
}

int main() {
    // TODO: Declare a vector called myGarden that can hold object of type plant pointer
    vector<Plant*> myGarden;
    string input;
    cin >> input;

    while (input != "-1") {

        if (input == "plant") {
            Plant* p = new Plant();

            cin >> input;
            p->SetPlantName(input);
            cin >> input;
            p->SetPlantCost(stoi(input));
            myGarden.push_back(p);

        }
        else {
            Flower* f = new Flower();
            bool c;

            cin >> input;
            f->SetPlantName(input);
            cin >> input;
            f->SetPlantCost(stoi(input));
            cin >> input;
            if (input == "true") c = true;
            else c = false;
            f->SetPlantType(c);
            cin >> input;
            f->SetColorOfFlowers(input);
            myGarden.push_back(f);

        }

        cin >> input;
    }

    // TODO: Call the method PrintVector to print myGarden
    PrintVector(myGarden);

    for (size_t i = 0; i < myGarden.size(); ++i) {
        delete myGarden.at(i);
    }

    return 0;
}
