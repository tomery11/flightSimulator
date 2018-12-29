//
// Created by t on 24/12/18.
//

#include "ParseUtils.h"
#include "ConditionParser.h"
#include "ConnectCommand.h"
#include "VarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "EntercCommand.h"
#include "OpenServerCommand.h"
#include "LoopCondition.h"
#include "IfCondition.h"

//parse by delimiter. input is string to delimit, token and vector for output
void ParseUtils::parseByDelimiter(string inputStr, string token, vector<string> *outputVec) {
    //go over the inputStr and parses according to to the token
    std::size_t prev = 0, pos;
    while ((pos = inputStr.find_first_of(token, prev)) != string::npos) {
        if (pos > prev) {
            //remove
            outputVec->push_back(inputStr.substr(prev, pos - prev));
        }
        prev = pos + 1;
    }
    //add last word
    if (prev < inputStr.length()) {
        outputVec->push_back(inputStr.substr(prev, string::npos));
    }
}

//lexer. perform the commands in the string input
void ParseUtils::lexer(const string *input, vector<string> *inputVec){
    string line;
    std::istringstream iss(*input);
    //if not in while loop or in if condition, delete the vector contents
    if (!inputVec->empty() && ((!(inputVec->at(0) == "while" || inputVec->at(0) == "if"))
                                || ((inputVec->at(0) == "while" || inputVec->at(0) == "if")
                                        && inputVec->at(inputVec->size() - 1) == "}"))) {
        inputVec->clear();
    }
    //go over the line and parses according to to the token
    while(std::getline(iss,line)){
        parseByDelimiter(line," \t", inputVec);
    }
}

//parser. perform the commands in the string vector input
void ParseUtils::parser(vector <string> *inputVec){
    //todo handle the case where { and } are not in their own lines
    //if in while loop or in if condition and haven't reached end, return without doing the command
    if (!inputVec->empty() && (inputVec->at(0) == "while" || inputVec->at(0) == "if") &&
        inputVec->at(inputVec->size() - 1) != "}") {
        return;
    }
    //do the command
    //print test

    for(auto it=inputVec->begin(); it!=inputVec->end(); ++it){
        //cout<<' '<<*it<<endl;
    }

    //find in commands
    Command *c;
    if (!inputVec->empty() && (this->commandMap.count(inputVec->at(0)) > 0)) {
        //cout << this->commandMap.find(inputVec->at(0))->first <<endl;
        c = this->commandMap.find(inputVec->at(0))->second;
        c->setSymbolTable(this->symbols);
        c->doCommand(inputVec);
    } else { //find in variables
        if (!inputVec->empty() && symbols->exist(inputVec->at(0))) {
            //cout << "found in varsOrder" << endl;
            //set the variable bind
            symbols->set(inputVec->at(0), stod(inputVec->at(2)));
        } else {
            throw "bad input: not a command or a variable";
        }
    }
}

ParseUtils::ParseUtils(SymbolsTable *symbols1) {

    this->symbols = symbols1;
    //cout << this->symbols->exist("g") << endl;
    //add commands: openServerCommand
    OpenServerCommand *server = new OpenServerCommand();
    server->setSymbolTable(symbols);
    commandMap["openDataServer"] = (Command *) server;
    //connect command
    ConnectCommand *connect = new ConnectCommand();
    connect->setSymbolTable(symbols);
    commandMap["connect"] = (Command *) connect;
    //var command
    VarCommand *varCommand = new VarCommand();
    varCommand->setSymbolTable(symbols);
    commandMap["var"] = (Command *) varCommand;
    //print command
    PrintCommand *printCommand = new PrintCommand(symbols);
    commandMap["print"] = (Command *) printCommand;
    //sleep command
    SleepCommand *sleepCommand = new SleepCommand();
    commandMap["sleep"] = (Command *) sleepCommand;
    //enterc command
    EntercCommand *entercCommand = new EntercCommand();
    commandMap["enterc"] = (Command *) entercCommand;
    //while command
    LoopCondition *loopCommand = new LoopCondition();
    commandMap["while"] = (Command *) loopCommand;
    //if command
    IfCondition *ifCommand = new IfCondition();
    commandMap["if"] = (Command *) ifCommand;

}

ParseUtils::~ParseUtils() {
    //cout << "end of parse utils" << endl;
    for(auto it=this->commandMap.begin(); it!=commandMap.end(); ++it){
        delete (*it).second;
        (*it).second = NULL;
    }
}

