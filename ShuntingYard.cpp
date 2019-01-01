//
// Created by Tomer Yona on 2018-12-20.
//

#include "ShuntingYard.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Multiply.h"
#include "Divide.h"

/*
 * this function checks if the give character is
 */
bool ShuntingYard::isNumber(char a) {
    bool ans= false;
    if( a > 47 && a < 58 )
        ans = true;
    return ans;
}
/*this funtion check if the given char is a math operator*/
bool ShuntingYard::isOperator(char a) {
    bool ans = false;
    if ( a == '+' || a == '-' || a == '*' || a == '/' )
        ans = true;
    return ans;
}
/*this funtion will eventually return the final expression after all caculations*/
Expression *ShuntingYard::algorithm(string expr, SymbolsTable *currTable) {
    /* the queue is for storing mostly numbers according to shunting yard algorithm*/
    queue<string> myQueue;
    /*the stack is for storing operators and brackets according to shunting yard algorithm*/
    stack<char> myStack;

    bool doubleOperator=false;
    char oper_toSave;
    for(unsigned int i = 0; i < expr.length(); i++){
        /*in this condition we check whether the givin char is a digit if it is, we keep on checking if there are
         * anymore digits following the original digit and after we have found the complete number we
         * push it into the queue, if the number is negative then after we push the current number
         * into the queue we push also zero into the queue for example -4= 0-4*/
        if ( isNumber(expr[i])|| isChar(expr[i]) ){
            string number;
            if(isNumber(expr[i])){
                number = prepareNumber(expr,i);
                i = i + number.length() - 1;
                myQueue.push(number);
            }
            //in this case we take care of var type for example "roll"
            else{
                //cout << "shunt input: " << expr << endl;
                string var = prepareVariable(expr,i);
                //cout << "shunt middle: " << var << endl;
                i = i + var.length() - 1;
                //cout << "shunting yard: to get var value" << endl;
                double d_number = currTable->getVarValue(var);

                number = to_string(d_number);
                myQueue.push(number);
            }

            doubleOperator=false;
        }
        /*in this condition we check if the current character is an operator and the we check if top of
         * the stack is an operator that has a priority i.e: '*' has a priority over '+' so
         * if it has a priority then we push it into the queue otherwise we push it into the stack*/
        else if(isOperator(expr[i])){

            /*this case i take is whether the following number is negative such as -4
             * this also takes care of the priority*/
            if(expr[i] == '+' || expr[i] == '-' ){
                if((expr[i]=='-'&& doubleOperator) || (expr[i]=='-' && i==0)){
                   // myStack.push('(');
                    myQueue.push("0");
                    if((expr[i]=='-'&& doubleOperator)){
                        oper_toSave=myStack.top();
                        myStack.pop();
                    }

                }

                while( !myStack.empty() && (myStack.top() == '*' || myStack.top() == '/')){
                    string opr_toPush;
                    opr_toPush.push_back(myStack.top());
                    myQueue.push(opr_toPush);
                    myStack.pop();
                }

                if(doubleOperator){
                    myStack.push(oper_toSave);
                }
                myStack.push(expr[i]);
            }
            else if(expr[i] == '*' || expr[i] == '/'){
                myStack.push(expr[i]);
            }
            doubleOperator=true;
        }
        else if(expr[i] == '('){
            myStack.push(expr[i]);
            doubleOperator=false;

        }
        /* this case is if expr[i]==')' */
        else if(expr[i]==')'){
            while(!myStack.empty() && myStack.top()!= '(' && myStack.top() != ')'){
                string opr_toPush;
                opr_toPush.push_back(myStack.top());
                myQueue.push(opr_toPush);
                myStack.pop();
            }
            myStack.pop();
            //isNegative=false;
            doubleOperator=false;
        }
        //I assumed that " " spaces splits the expressions
        else if(expr[i]==' '){
            expr.substr(1,expr.length());
            //isNegative=false;
        }
    }
    /*after all iterations we want to empty the stack and insert the operators into the our queue*/
    while(!myStack.empty()){
        string opr_toPush;
        opr_toPush.push_back(myStack.top());
        myStack.pop();
        myQueue.push(opr_toPush);
    }

    return postfix_calc(myQueue);
}


/*this functions recieves a string and int as parameter and as long is a valid number then loop
 * keeps on running and in the end returns to caller the valid number as string*/
string ShuntingYard::prepareNumber(string expr, int i) {
    string toReturn;
    int num_dot= 0;
    while(isdigit(expr[i])||(expr[i]=='.' && num_dot<2)){
        if(expr[i]=='.'){
            num_dot++;
        }
        if(num_dot==2)
            throw ("illeagal expression");
        toReturn+= expr[i];
        i++;
    }
    return toReturn;
}




/* this function computes the mathimatical expression when is in postfix notation*/
Expression *ShuntingYard::postfix_calc(queue<string>& myQueue) {
    stack <Expression*> exprStack;

    while(!myQueue.empty()){
        //case if the next bind in our postfix queue is a number
        if(isValid_number(myQueue.front())){
            Number* number= new Number(myQueue.front());
            addToDeleteVec(number);
             myQueue.pop();

            //caution for not popping out bind
            if(!myQueue.empty() && myQueue.front()==","){
                 //pop the delimeter bind ","
                 myQueue.pop();
            }

            exprStack.push(number);
        }
        //this case is if the next bind is an operator
        else{
            Expression* right_num = exprStack.top();
            exprStack.pop();

            //caution for not popping out bind
            if(!myQueue.empty() && myQueue.front()==","){
                //pop the delimeter bind ","
                myQueue.pop();
            }
            Expression* left_num= exprStack.top();
            exprStack.pop();
            //caution for not popping out bind
            if(!myQueue.empty() && myQueue.front()==","){
                //pop the delimeter bind ","
                myQueue.pop();
            }

            char oper_toCalc= myQueue.front()[0];

            switch(oper_toCalc){
                case '+':{
                    Plus* plus= new Plus(left_num,right_num);
                    //i added this on 24.12 to check if 5+5=10 and is inserted into the stack
                    double add_toStack = plus->calculate();
                    delete(plus);
                    Number* number= new Number(add_toStack);
                    addToDeleteVec(number);
                    exprStack.push(number);
                    myQueue.pop();
                    //caution for not popping out bind
                    if(!myQueue.empty() && myQueue.front()==","){
                        //pop the delimeter bind ","
                        myQueue.pop();
                    }

                    break;
                }
                case '-':{
                    Minus* minus= new Minus(left_num,right_num);
                    double add_toStack = minus->calculate();
                    delete(minus);
                    Number* number= new Number(add_toStack);
                    addToDeleteVec(number);
                    exprStack.push(number);
                    myQueue.pop();
                    //caution for not popping out bind
                    if(!myQueue.empty() && myQueue.front()==","){
                        //pop the delimeter bind ","
                        myQueue.pop();
                    }
                    break;
                }
                case '*':{
                    Multiply* multiply= new Multiply(left_num,right_num);
                    double add_toStack = multiply->calculate();
                    delete(multiply);
                    Number* number= new Number(add_toStack);
                    addToDeleteVec(number);
                    exprStack.push(number);
                    myQueue.pop();
                    //caution for not popping out bind
                    if(!myQueue.empty() && myQueue.front()==","){
                        //pop the delimeter bind ","
                        myQueue.pop();
                    }
                    break;
                }
                case '/':{
                    Divide* divide= new Divide(left_num,right_num);
                    double add_toStack = divide->calculate();
                    delete(divide);
                    Number* number= new Number(add_toStack);
                    addToDeleteVec(number);
                    exprStack.push(number);
                    myQueue.pop();
                    //caution for not popping out bind
                    if(!myQueue.empty() && myQueue.front()==","){
                        //pop the delimeter bind ","
                        myQueue.pop();
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }


    return exprStack.top();
}




bool ShuntingYard::isValid_number(string number) {
    bool ans=false;
    for(unsigned int i = 0; i < number.length(); i++){
        if(isNumber(number[i])){
            ans=true;
        }
    }
    return ans;
}

double ShuntingYard::evaluate(string &mathematical_exp, SymbolsTable *currTable) {
    Expression *calcExp= algorithm(mathematical_exp, currTable);
    double toReturn = calcExp->calculate();
    delete(calcExp);
    return toReturn;
}

/*checks if the char is a letter*/
bool ShuntingYard::isChar(char a) {
    bool ans=false;
    if(a>96 && a<123)
        ans=true;
    return ans;
}
/*this function prepares a var from the given string and returns the string of it
 * for example "roll/5" will return the string "roll"*/
string ShuntingYard::prepareVariable(string expr, int i) {
    string toReturn;
    while(isChar(expr[i]) || isNumber(expr[i])){
        toReturn+= expr[i];
        i++;
    }
    return toReturn;
}
/*in this function we put the "new" objects created in a vector and when destructor is called data will be deleted*/
void ShuntingYard::addToDeleteVec(Expression *exp) {
    this->vecToDelete.push_back(exp);
}

