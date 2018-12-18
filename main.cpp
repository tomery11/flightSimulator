#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>
#include "Command.h"
#include <map>
#include <fstream>
#include "DataReaderServer.h"
#include "OpenServerCommand.h"
#include "SymbolsTable.h"

using namespace std;


void lexer(const string *input, vector<string> *inputVec){

    cout << "lexer" << endl;
    string line;
    std::istringstream iss(*input);
    //if not in while loop or in if condition, delete the vector contents
    if (!inputVec->empty() && (inputVec->at(0) != "while" || inputVec->at(0) != "if")) {
        inputVec->clear();
    }
    //go over the line and parses according to to the token
    while(std::getline(iss,line)){
        std::size_t prev = 0, pos;
        while ((pos = line.find_first_of(" \t", prev)) != string::npos) {
            if (pos > prev) {
                inputVec->push_back(line.substr(prev, pos - prev));
                cout << "pushed: " << line.substr(prev, pos - prev) << endl;
            }
            prev = pos + 1;
        }
        //add last word
        if (prev < line.length()) {
            inputVec->push_back(line.substr(prev, string::npos));
            cout << "pushed: " << line.substr(prev, string::npos) << endl;
        }
    }
    ///n?
    cout << "end of lexer" << endl;
}

void parser(vector <string> *inputVec, const map<string,Command*> *mapCommand, SymbolsTable *symbols){
    cout << "parser" << endl;
    //
    //todo handle the case where { and } are not in their own lines
    //if in while loop or in if condition and haven't reached end, return without doing the command
    if (!inputVec->empty() && (inputVec->at(0) == "while" || inputVec->at(0) == "if") &&
        inputVec->at(inputVec->size()) != "}") {
                return;
    }
    //do the command
    //print test

    for(auto it=inputVec->begin(); it!=inputVec->end(); ++it){
        cout<<' '<<*it<<endl;
    }

    //find in commands
    Command *c;
    if (mapCommand->count(inputVec->at(0)) > 0) {
        c = mapCommand->find(inputVec->at(0))->second;
        c->doCommand(inputVec);
    } else { //find in variables
        if (symbols->exist(inputVec->at(0))) {
            //todo set the variable value
            //symbols->set(inputVec->at(0), inputVec->at(3)->)
        } else {
            throw "bad input: not a command or a variable";
        }
    }
    cout << "end of parser" << endl;
}

//get a file as argument or no arguments for getting lines from the user.
int main(int argc, char *argv[]) {
    std::string input;
    vector<string> inputVec;
    //create symbol map - variable name and it's value
    SymbolsTable symbols;
    //create map string Command
    map<string, Command *> commandMap;
    //add commands
    OpenServerCommand server = OpenServerCommand();
    server.setSymbolTable(&symbols);
    commandMap["test"] = (Command *) &server;

    //run a script
    try {
        //one argument to get the script from a file
        if (argc == 2) { //todo
            //open the file
            fstream scriptFile(argv[1]);
            //if failed
            if (scriptFile.fail()) {
                throw "bad file";
            }
            //if open
            if (scriptFile.is_open()) {
                string line;
                //parse the lines, one at a time
                getline(scriptFile, line);
                while (!line.empty()) { //todo: in case there is no new line at the end of the file there is a loop on the last line
                    cout << line << endl;
                    //send for lexer and parser
                    lexer(&input, &inputVec);
                    parser(&inputVec, &commandMap, &symbols);
                    //get the next line from the file
                    getline(scriptFile, line);
                }
                scriptFile.close();
            }
        } else if (argc == 1) { //no argument for per line parsing
            do {
                //get the next line from the user
                getline(std::cin, input);
                //send for lexer and parser
                lexer(&input, &inputVec);
                parser(&inputVec, &commandMap, &symbols);

            } while (input != "print \"done\"");
        } else { //two and more arguments are not allowed
            throw "bad argument number";
        }
    } catch (char const *exception) {
        printf("%s", exception);
    }
    return 0;
}
