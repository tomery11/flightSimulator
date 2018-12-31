//
// Created by Tomer Yona on 2018-12-19.
//

#include "BinaryExpression.h"
#include "Number.h"

BinaryExpression::BinaryExpression(Expression *leftExp, Expression *rightExp) {
    this->left=leftExp;
    this->right=rightExp;

}
BinaryExpression::~BinaryExpression() {
    free(this->left);
    free(this->right);
}