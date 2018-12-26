//
// Created by t on 17/12/18.
//

#include "SymbolsTable.h"


SymbolsTable::SymbolsTable() {
    this->symbolsExist = true;
    varsOrder.push_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
    varsOrder.push_back("/instrumentation/altimeter/indicated-altitude-ft");
    varsOrder.push_back("/instrumentation/altimeter/pressure-alt-ft");
    varsOrder.push_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
    varsOrder.push_back("/instrumentation/attitude-indicator/indicated-roll-deg");
    varsOrder.push_back("/instrumentation/attitude-indicator/internal-pitch-deg");
    varsOrder.push_back("/instrumentation/attitude-indicator/internal-roll-deg");
    varsOrder.push_back("/instrumentation/encoder/indicated-altitude-ft");
    varsOrder.push_back("/instrumentation/encoder/pressure-alt-ft");
    varsOrder.push_back("/instrumentation/gps/indicated-altitude-ft");
    varsOrder.push_back("/instrumentation/gps/indicated-ground-speed-kt");
    varsOrder.push_back("/instrumentation/gps/indicated-vertical-speed");
    varsOrder.push_back("/instrumentation/heading-indicator/indicated-heading-deg");
    varsOrder.push_back("/instrumentation/magnetic-compass/indicated-heading-deg");
    varsOrder.push_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
    varsOrder.push_back("/instrumentation/turn-indicator/indicated-turn-rate");
    varsOrder.push_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    varsOrder.push_back("/controls/flight/aileron");
    varsOrder.push_back("/controls/flight/elevator");
    varsOrder.push_back("/controls/flight/rudder");
    varsOrder.push_back("/controls/flight/flaps");
    varsOrder.push_back("/controls/engines/engine/throttle");
    varsOrder.push_back("/engines/engine/rpm");
}

//get the symbols singleton
SymbolsTable* SymbolsTable::getSymbols() {
    if(symbolsExist) {
        return this->symbolsSingleton;
    }
    this->symbolsSingleton = new SymbolsTable();
    return this->symbolsSingleton;
}

//add a binded variable
void SymbolsTable::addVar(string name, string bind) {
    //add bind
    this->bindedVars.insert(pair<string,string>(name, bind));
    //add var and it's binded bind
    this->symbolsMap.insert(pair<string, double>(name, this->simulatorOutput.find(name)->second));
    cout << "inserted name: " << name << " insterted bind " << bind << endl;
}

void SymbolsTable::addVar(string name, double value) {
    //add var and it's value
    this->symbolsMap.insert(pair<string, double>(name, value));
    cout << "inserted name: " << name << " insterted value " << value << endl;
}

//check if a variable already exist
bool SymbolsTable::exist(string var) {
    return this->symbolsMap.count(var) == 1;
}

//get a string with values delimited by ',' and update the simulatorOutput and binded varsOrder
void SymbolsTable::updateServer(string values) {
    //parse and put in simulatorOutput map and update binded var
    string digits;
    unsigned long varNum = 0;
    //go over the input and parse. delimiter is ',' and '\n'
    for(int i = 0; i < values.length(); i++) {
        //if reached end of a number
        if (values[i] == ',' || values[i] == '\n') {
            //if word is not empty, put in the map
            if (!digits.empty()) {
                simulatorOutput[varsOrder.at(varNum)] = stod(digits);
                //if in binded varsOrder, update the var in symbolMap as well
                if (this->bindedVars.count(varsOrder.at(varNum)) > 0) {
                    this->symbolsMap.find(varsOrder.at(varNum))->second = stod(digits);
                }
                varNum++;
            }
        } else {
            //if not end of number, add the digit to digits
            digits += values[i];
        }
    }
}


//set a variable's bind to be sent to the simulation
void SymbolsTable::set(string var, double value) {
    if (exist(var)) {
        //push to the set queue
        this->setQueue.push(make_pair(var, value));
    } else {
        throw "no such variable ";
    }
}

//return a pair with the message for the simulation. 0 in both values if there is none.
pair<string, double> SymbolsTable::getMessage() {
    pair<string, double> message;
    if (this->setQueue.empty()) {
        message.first = "0";
        message.second = 0;
    } else {
        message = this->setQueue.front();
        this->setQueue.pop();
    }
    return message;
}

double SymbolsTable::getVarValue(string name) {
    if (exist(name)) {
        return this->symbolsMap.find(name)->second;
    }
    for(auto it=symbolsMap.begin(); it!=symbolsMap.end(); ++it){
        cout<<' '<<(*it).first << ' ' << (*it).second <<endl;
    }
    throw "no such variable";
}

~SymbolsTable::SymbolsTable() {
    delete this->
}




