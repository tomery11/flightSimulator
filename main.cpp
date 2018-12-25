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
#include "parse_utils.h"
#include "LoopCondition.h"
#include "IfCondition.h"
#include "ConditionParser.h"
///home/t/CLionProjects/flightSimulator/script
using namespace std;


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
    //while command
    LoopCondition loopCommand = LoopCondition();
    commandMap["while"] = (Command *) &loopCommand;
    //if command
    IfCondition ifCommand = IfCondition();
    commandMap["if"] = (Command *) &ifCommand;

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
                while (!input.empty()) { //todo: stop loop on last line
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
