//
// Created by t on 24/12/18.
//

#ifndef FLIGHTSIMULATOR_PARSE_UTILS_H
#define FLIGHTSIMULATOR_PARSE_UTILS_H
#include <string>
#include <vector>
#include <map>
#include "Command.h"
#include "SymbolsTable.h"
#include <sstream>

using namespace std;

class ParseUtils{
    map <string, Command*> commandMap;
    SymbolsTable *symbols;
public:
    ParseUtils(SymbolsTable *symbols);
    void parseByDelimiter(string inputStr, string token, vector<string> *outputVec);
    void lexer(const string *input, vector<string> *inputVec);
    void parser(vector <string> *inputVec);
    ~ParseUtils();
};



#endif //FLIGHTSIMULATOR_PARSE_UTILS_H
