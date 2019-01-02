//
// Created by t on 22/12/18.
//

#include "PrintCommand.h"

PrintCommand::PrintCommand(SymbolsTable *symbols) {
    this->symbols = symbols;
}

//print
void PrintCommand::doCommand(std::vector<string> *inputVec) {
    //if need to print a string(start with "), print it
    if (inputVec->at(1)[0] == '"') {
    	string print = "";
    	//if only one word to print
    	if (inputVec->size() == 2) {
    		print += inputVec->at(1).substr(1, inputVec->at(1).length() - 2);
    	} else if (inputVec->size() > 2) { //if more than one word to print
        	print += inputVec->at(1).substr(1, inputVec->at(1).length() - 1);
       		for (auto it = inputVec->begin() + 2; it < inputVec->end() - 1; it++) {
        		print += " ";
        		print += (*it);
        	}
        	print += " ";
        	print += inputVec->at(inputVec->size() - 1).substr(0, inputVec->at(inputVec->size() - 1).length() - 1);
    	}
        cout << print << endl;
    } else if (this->symbols->exist(inputVec->at(1))) { //print a variable value
        //if need to print a var, print it's value
        //cout << "print command: to get var value" << endl;
        double print = this->symbols->getVarValue(inputVec->at(1));
        cout << print << endl;
    } else {
    	throw "bad print command";
    }
}

void PrintCommand::setSymbolTable(SymbolsTable *symbols) {

}


