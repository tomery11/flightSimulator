#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>
#include "Command.h"
#include <map>
#include <fstream>
#include "DataReaderServer.h"

using namespace std;


void lexer(const string *input, vector<string> inputVec){

    cout << "lexer" << endl;
    //todo add more whitespaces to token?
    string token = " \t";
    std::istringstream iss(*input);
    //if not in while loop or in if condition, delete the vector contents
    if (!inputVec.empty() && (inputVec.at(0) != "while" || inputVec.at(0) != "if")) {
        inputVec.clear();
    }
    //go over the line and parses according to to the token
    while(std::getline(iss,token,' ')){
        inputVec.push_back(token);
    }
    ///n?
    cout << "end of lexer" << endl;
}

void parser(const vector <string> *inputVec, const map<string,Command*> *mapCommand){
    //
    cout<<"parser"<<endl;
    //todo handle the case where { and } are not in their own lines
    //if in while loop or in if condition and haven't reached end, return without doing the command
    if (!inputVec->empty() && (inputVec->at(0) == "while" || inputVec->at(0) == "if") &&
        inputVec->at(inputVec->size()-2) != "}") {
        cout<<"don't do the command"<<endl;
                return;
    }
    cout<<"after if in parser"<<endl;
    //do the command
    //print test

    for(auto it=inputVec->begin(); it!=inputVec->end(); ++it){
        cout << "after parser"<<endl;
        cout<<' '<<*it<<endl;
    }
    //mapCommand.find(inputVec.at(0))->doCommand(inputVec);
}

//get a file as argument or no arguments for getting lines from the user.
int main(int argc, char *argv[]) {
    std::string input;
    vector<string> inputVec;
    //create map string Command
    map<string, Command *> commandMap;
    DataReaderServer server = DataReaderServer();
    commandMap["test"] = (Command *) &server;

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
                    lexer(&input, inputVec);
                    parser(&inputVec, &commandMap);
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
                lexer(&input, inputVec);
                parser(&inputVec, &commandMap);

            } while (input != "print \"done\"");
        } else { //two and more arguments are not allowed
            throw "bad argument number";
        }
    } catch (char const *exception) {
        printf("%s", exception);
    }
    return 0;

}