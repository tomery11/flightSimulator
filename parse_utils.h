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

using namespace std;

void parseByDelimiter(string inputStr, string token, vector<string> *outputVec);
void lexer(const string *input, vector<string> *inputVec);
void parser(vector <string> *inputVec, const map<string,Command*> *mapCommand, SymbolsTable *symbols);
void strToExpression(string &input, Expression *expression);

#endif //FLIGHTSIMULATOR_PARSE_UTILS_H
