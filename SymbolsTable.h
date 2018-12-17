//
// Created by t on 17/12/18.
//

#ifndef FLIGHTSIMULATOR_SYMBOLSTABLE_H
#define FLIGHTSIMULATOR_SYMBOLSTABLE_H
#include <map>
using namespace std;

class SymbolsTable {
    map<string,float> symbolsMap;
public:
    SymbolsTable();
    bool exist(string var);
    bool set(string var, float value);
};


#endif //FLIGHTSIMULATOR_SYMBOLSTABLE_H
