//
// Created by Tomer Yona on 2018-12-22.
//

#include "ConditionParser.h"

void ConditionParser::set(Expression *leftExpr, Expression *rightExpr, string condition_opr) {
    this->leftExpr = leftExpr;
    this->rightExpr = rightExpr;
    this->condition_opr = condition_opr;
    //commands inside

}

bool ConditionParser::meetsCondition() {
    double leftNum = leftExpr->calculate();
    double rightNum = rightExpr->calculate();

    if(condition_opr == ">"){
        return (leftNum > rightNum);
    }

    if(condition_opr == "<"){
        return (leftNum < rightNum);
    }

    if(condition_opr == "=="){
        return (leftNum == rightNum);
    }

    if(condition_opr == ">="){
        return (leftNum >= rightNum);
    }

    if(condition_opr == "<="){
        return (leftNum <= rightNum);
    }

    return false;
}

