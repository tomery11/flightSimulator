
#include "ConditionParser.h"

void ConditionParser::set(vector<string> *inputVec) {
    parseUtils = new ParseUtils(&symbols);
    cout << "condition parser" << endl;
    for(auto it=inputVec->begin(); it!=inputVec->end(); ++it){
        cout<<*it;
    }
    //handle the condition:
    string condition;
    //extract the condition
    auto it=inputVec->begin() + 1;
    for(; (*it) != "{"; ++it){
        condition += (*it);
    }
    //extract the commands strings
    for(it=it + 1; (*it) != "}"; ++it){
            this->commandsVec.push_back(*it);
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
    cout << firstExp << condition_opr << secondExp << endl;
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

void ConditionParser::doTheCommands() {
    string input;
    vector<string> inputVec;
    cout << "do the commands!" << endl;
    for(auto it=commandsVec.begin(); it!=commandsVec.end(); ++it){
        if ((*it) != "\n") { //build a line to make a single command of
            input += (*it) += " ";
            continue;
        } else { //end of line, make the command
            parseUtils.lexer(&input, &inputVec);
            parseUtils.parser(&inputVec, &symbols);
            cout << input << ' ';
            input = "";
        }
    }
    cout << "end do the commands!" << endl;
}

ConditionParser::~ConditionParser() {
    delete this->parseUtils;
    this->parseUtils = NULL;
}
