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
#include "ParseUtils.h"
#include "LoopCondition.h"
#include "IfCondition.h"
#include "ConditionParser.h"
//for shunting yard test
#include "BinaryExpression.h"
#include "Expression.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Multiply.h"
#include "Divide.h"
#include "ShuntingYard.h"
///home/t/CLionProjects/flightSimulator/script
using namespace std;


//get a file as argument or no arguments for getting lines from the user.
int main(int argc, char *argv[]) {

    std::string input;
    vector<string> inputVec;
    //create symbol map - variable name and it's bind
    SymbolsTable *symbols = new SymbolsTable();
    ParseUtils *parseUtils = new ParseUtils(symbols);

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
                    cout << "line1: " << input << endl;
                    //send for lexer and parser
                    parseUtils->lexer(&input, &inputVec);
                    parseUtils->parser(&inputVec);
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
                parseUtils->lexer(&input, &inputVec);
                parseUtils->parser(&inputVec);

            } while (input != "exit");
        } else { //two and more arguments are not allowed
            throw "bad argument number";
        }
    } catch (char const *exception) {
        printf("%s", exception);
    }
    cout << "sleep" << endl;
    while(true) {
        sleep(900);
    }
    delete symbols;
    symbols = NULL;
    delete parseUtils;
    parseUtils = NULL;
    return 0;
}
