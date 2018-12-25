//
// Created by Tomer Yona on 2018-12-20.
//

#ifndef FLIGHTSIMULATOR_SHUNTINGYARD_H
#define FLIGHTSIMULATOR_SHUNTINGYARD_H

#include <queue>
#include <stack>
#include <string>
#include "Expression.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Multiply.h"
#include "Divide.h"
#include "SymbolsTable.h"
using namespace std;
class ShuntingYard {


private:
    bool isNumber(char a);
    bool isOperator(char a);
    Expression* algorithm(string expr);
    string prepareNumber(string expr, int i);
    Expression* postfix_calc(queue<string>& myQueue);
    bool isValid_number(string number);
    bool isChar(char a);
    string prepareVariable(string expr,int i);

public:
    double evaluate(string &mathematical_exp);
};


#endif //FLIGHTSIMULATOR_SHUNTINGYARD_H
