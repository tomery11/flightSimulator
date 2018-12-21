//
// Created by Tomer Yona on 2018-12-19.
//

#include "Number.h"

Number::Number(double value) {
    this->value=value;

}

Number::Number(string value) {
    this->value=stod(value);

}

Number::Number(int value) {
    this->value=value;

}
