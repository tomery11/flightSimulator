
#include "ConditionParser.h"


void ConditionParser::set(vector<string> *inputVec) {
    //handle the condition:
    string condition;
    //extract the condition
    for(auto it=inputVec->begin() + 1; (*it) != "{"; ++it){
        condition += (*it);
    }
    cout << "condition: " << condition << endl;
    //create the expressions and condition operation
    bool found = false;

    for (int i = 0; i < condition.length(); i++) {
        //if found the operator already
        if (!found) {
            //for the operator
            if(condition[i] == '>' || condition[i] == '<' || condition[i] == '=' || condition[i] == '!') {
                found = true;
                //check for two chars operator and add them
                if(condition[i + 1] == '=') {
                    this->condition_opr.insert(0, 1, condition[i]);
                    this->condition_opr.insert(1, 1, condition[i + 1]);
                    i++;
                } else {
                    //if one char operation, add it
                    this->condition_opr.insert(0, 1, condition[i]);
                }
            }
            //not operator - add to first expression
            firstExp.insert(firstExp.length(), 1, condition[i]);
        }
        //after the operator, insert to second expression
        secondExp.insert(secondExp.length(), 1, condition[i]);
    }
    //todo handle the commands:

}

bool ConditionParser::meetsCondition() {
    double leftNum = myAlgo.evaluate(this->firstExp);
    double rightNum = myAlgo.evaluate(this->secondExp);

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

    if(condition_opr == "!="){
        return (leftNum <= rightNum);
    }
    return false;
}



