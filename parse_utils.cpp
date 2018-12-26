//
// Created by t on 24/12/18.
//

#include "parse_utils.h"

//parse by delimiter. input is string to delimit, token and vector for output
void parseByDelimiter(string inputStr, string token, vector<string> *outputVec) {
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
void lexer(const string *input, vector<string> *inputVec){
    string line;
    std::istringstream iss(*input);
    //if not in while loop or in if condition, delete the vector contents
    if (!inputVec->empty() && !(inputVec->at(0) == "while" || inputVec->at(0) == "if")) {
        inputVec->clear();
    }
    //go over the line and parses according to to the token
    while(std::getline(iss,line)){
        parseByDelimiter(line," \t", inputVec);
    }
}

//parser. perform the commands in the string vector input
void parser(vector <string> *inputVec, const map<string,Command*> *mapCommand, SymbolsTable *symbols){
    cout << "lexer" << endl;
    //todo handle the case where { and } are not in their own lines
    //if in while loop or in if condition and haven't reached end, return without doing the command
    if (!inputVec->empty() && ((inputVec->at(0) == "while" || inputVec->at(0) == "if") &&
        inputVec->at(inputVec->size() - 1) != "}")) {
        if (inputVec->size() > 2) {
            //add \n as a delimiter to the vector
            inputVec->push_back("\n");
        }
        for(auto it=inputVec->begin(); it!=inputVec->end(); ++it){
            cout<<' '<<*it<<endl;
        }
        return;
    }
    //do the command
    for(auto it=inputVec->begin(); it!=inputVec->end(); ++it){
        cout<<' '<<*it<<endl;
    }


    //find in commands
    Command *c;
    if (!inputVec->empty() && (mapCommand->count(inputVec->at(0)) > 0)) {
        c = mapCommand->find(inputVec->at(0))->second;
        c->doCommand(inputVec);
    } else { //find in variables
        if (!inputVec->empty() && symbols->exist(inputVec->at(0))) {
            cout << "found in varsOrder" << endl;
            //set the variable bind
            symbols->set(inputVec->at(0), stod(inputVec->at(2)));
        } else {
            throw "bad input: not a command or a variable";
        }
    }
}

