
#include "ConditionParser.h"
#include "ShuntingYard.h"

void ConditionParser::set(vector<string> *inputVec) {
    //cout << "loop start =====================" << endl;
    //for(auto it=inputVec->begin(); it!=inputVec->end(); ++it){
    //    cout << (*it) << " ";
    //}
    firstExp = "";
    secondExp = "";
    condition_opr = "";
    lineCommandsVec.clear();
    parseUtils1 = new ParseUtils(symbolsTable);
    //handle the condition:
    string condition = "";
    //extract the condition
    auto it = inputVec->begin() + 1;
    for(; (*it) != "{"; ++it){
        if ((*it) != " ") {
            condition += (*it);
        }
    }
    //cout << "condition: " << condition << endl;
    //create the expressions and condition operation
    bool found = false;
    for (unsigned int i = 0; i < condition.length(); i++) {
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
            } else {
                //not operator - add to first expression
                firstExp.insert(firstExp.length(), 1, condition[i]);
            }
        } else {
            //after the operator, insert to second expression
            secondExp.insert(secondExp.length(), 1, condition[i]);
        }
    }
    //handle the commands:
    string line = "";
    for (it = it + 1; (*it) != "}"; ++it){
        if ((*it) == "\n") {
            this->lineCommandsVec.push_back(line);
            line = "";
        } else {
            line += (*it) += " ";
            //cout << line << endl;
        }
    }
}

bool ConditionParser::meetsCondition() {
    double leftNum = myAlgo.evaluate(this->firstExp, symbolsTable);
    double rightNum = myAlgo.evaluate(this->secondExp, symbolsTable);
    //cout << firstExp << endl;
    //cout << symbolsTable->getVarValue(firstExp) << endl;
    //cout << leftNum << condition_opr << rightNum << endl;
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

void ConditionParser::setSymbolTable(SymbolsTable *symbolsTable) {
    this->symbolsTable=symbolsTable;
}

void ConditionParser::doTheCommands() {
    vector<string> inputVec;
    //cout << "do the commands------------------------";
    for(auto it = lineCommandsVec.begin() + 1; it != lineCommandsVec.end(); ++it){
        //cout << "line: " << (*it) << endl;
        parseUtils1->lexer(&(*it), &inputVec);
        parseUtils1->parser(&inputVec);
    }
        //cout << "line commands: " << lineCommandsVec << endl;
        //lineCommandsVec = lineCommandsVec.substr(1,lineCommandsVec.length() - 1);
        //cout << "line commands: " << lineCommandsVec << endl;
        //cout << "sent to parser from loop: " << (*it) << endl;

    
    /*
    cout << "doing the commands" <<endl;
    string input;
    vector<string> inputVec;
    for(auto it=commandsVec.begin(); it!=commandsVec.end(); ++it){
        if((*it)!="\n"){
            cout << input<<endl;
            input += (*it)+=" ";
            continue;
        }
        else{
            cout << "should be a full line command: " << input << endl;
            parseUtils1->lexer(&input, &inputVec);
            parseUtils1->parser(&inputVec);
            //cout<<input<<' ';
            input="";
        }
    }
    */
}

ConditionParser::~ConditionParser() {
    //cout << "ConditionParser deleted" << endl;
    delete this->parseUtils1;
    this->parseUtils1=NULL;
}



