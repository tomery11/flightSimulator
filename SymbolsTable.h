//
// Created by t on 17/12/18.
//

#ifndef FLIGHTSIMULATOR_SYMBOLSTABLE_H
#define FLIGHTSIMULATOR_SYMBOLSTABLE_H
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

//a singleton
class SymbolsTable {
    bool symbolsExist = false;
    static SymbolsTable *symbolsSingleton;
    //vars that exist in program
    map<string,double> symbolsMap;
    //all vars from simulation
    map<string,double> simulatorOutput;
    //vars order in simulation output
    vector<string> varsOrder;
    //binded vars in program
    map<string, string> bindedVars;
    //queue of values to be set to simulation
    queue<pair<string,int>> setQueue;
    SymbolsTable();
public:
    static SymbolsTable* getSymbols();
    void addVar(string name, string bind);
    void addVar(string name, double value);
    bool exist(string var);
    void updateServer(string values);
    void set(string var, double value);
    pair<string, double> getMessage();
    double getVarValue(string name);
    ~SymbolsTable();

};


#endif //FLIGHTSIMULATOR_SYMBOLSTABLE_H
