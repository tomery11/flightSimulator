//
// Created by Tomer Yona on 2018-12-22.
//

#include "LoopCondition.h"

void LoopCondition::doCommand(vector<string> *inputVec) {
    set(inputVec);
    while (meetsCondition()) {
        doTheCommands();
        cout << "end of loop" << endl;
    }
}
