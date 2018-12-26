//
// Created by t on 23/12/18.
//

#include "EntercCommand.h"

//wait for an input of enter from the user
void EntercCommand::doCommand(std::vector<string> *inputVec) {
    cout << "press enter to continue: " << endl;
    char c = getc(stdin);
}

void EntercCommand::setSymbolTable(SymbolsTable *symbols) {

}
