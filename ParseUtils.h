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
#include "Expression.h"
#include "BinaryExpression.h"
#include "Number.h"
#include "ParseUtils.h"
#include "ConditionParser.h"

#include "ConnectCommand.h"
#include "VarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"

#include "EntercCommand.h"
#include "OpenServerCommand.h"

using namespace std;

class ParseUtils{
    map <string, Command*> commandMap;
public:
    ParseUtils(SymbolsTable *symbols);
    void parseByDelimiter(string inputStr, string token, vector<string> *outputVec);
    void lexer(const string *input, vector<string> *inputVec);
    void parser(vector <string> *inputVec,  SymbolsTable *symbols);
};



#endif //FLIGHTSIMULATOR_PARSE_UTILS_H
