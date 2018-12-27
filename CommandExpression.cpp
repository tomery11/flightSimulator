//
// Created by Tomer Yona on 2018-12-21.
//

#include "CommandExpression.h"
using namespace std;


CommandExpression::CommandExpression(Command *c, std::vector<string> *parameters) {
    this->c=c;
    this->parameters= parameters;

}

double CommandExpression::calculate() {
    c->doCommand(parameters);
    return 0;
}
