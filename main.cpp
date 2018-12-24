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
#include "ConnectCommand.h"
#include "VarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "EntercCommand.h"
///home/t/CLionProjects/flightSimulator/script
using namespace std;


void lexer(const string *input, vector<string> *inputVec){
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
                //remove
                inputVec->push_back(line.substr(prev, pos - prev));
            }
            prev = pos + 1;
        }
        //add last word
        if (prev < line.length()) {
            inputVec->push_back(line.substr(prev, string::npos));
        }
    }
    ///n?
}

void parser(vector <string> *inputVec, const map<string,Command*> *mapCommand, SymbolsTable *symbols){
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

//get a file as argument or no arguments for getting lines from the user.
int main(int argc, char *argv[]) {
    std::string input;
    vector<string> inputVec;
    //create symbol map - variable name and it's bind
    SymbolsTable symbols;
    //create map string Command
    map<string, Command *> commandMap;
    //add commands: openServerCommand
    OpenServerCommand server = OpenServerCommand();
    server.setSymbolTable(&symbols);
    commandMap["openDataServer"] = (Command *) &server;
    //connect command
    ConnectCommand connect = ConnectCommand();
    connect.setSymbolTable(&symbols);
    commandMap["connect"] = (Command *) &connect;
    //var command
    VarCommand varCommand = VarCommand();
    varCommand.setSymbols(&symbols);
    commandMap["var"] = (Command *) &varCommand;
    //print command
    PrintCommand printCommand = PrintCommand(&symbols);
    commandMap["print"] = (Command *) &printCommand;
    //sleep command
    SleepCommand sleepCommand = SleepCommand();
    commandMap["sleep"] = (Command *) &sleepCommand;
    //enterc command
    EntercCommand entercCommand = EntercCommand();
    commandMap["enterc"] = (Command *) &entercCommand;

    //run a script
    try {
        //one argument to get the script from a file
        if (argc == 2) {
            //open the file
            fstream scriptFile(argv[1]);
            //if failed
            if (scriptFile.fail()) {
                throw "bad file";
            }
            //if open
            if (scriptFile.is_open()) {
                //parse the lines, one at a time
                getline(scriptFile, input);
                while (!input.empty()) { //todo: in case there is no new line at the end of the file there is a loop on the last line
                    cout << "line: " << input << endl;
                    //send for lexer and parser
                    lexer(&input, &inputVec);
                    parser(&inputVec, &commandMap, &symbols);
                    //get the next line from the file
                    getline(scriptFile, input);
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

            } while (input != "exit");
        } else { //two and more arguments are not allowed
            throw "bad argument number";
        }
    } catch (char const *exception) {
        printf("%s", exception);
    }
    return 0;
}
