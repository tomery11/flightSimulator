//
// Created by t on 17/12/18.
//

#include "SymbolsTable.h"


SymbolsTable::SymbolsTable() {

}

//check if a variable already exist
bool SymbolsTable::exist(string var) {
    return this->symbolsMap.count(var) == 1;
}

//set a variable's value (only inside the program, not on simulator)
bool SymbolsTable::set(string var, float value) {
    //if (exist(var)) {
     //   auto it = this->symbolsMap.find(var);
     //   it->second = value;
     //   return true;
    //}
    return false;
}

