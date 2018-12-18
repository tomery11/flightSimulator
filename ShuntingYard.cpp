//
// Created by Tomer Yona on 2018-12-20.
//

#include "ShuntingYard.h"
/*
 * this function checks if the give charcatar is
 */
bool ShuntingYard::isNumber(char a) {
    bool ans= false;
    if( a > 47 && a < 58 )
        ans = true;
    return ans;
}

bool ShuntingYard::isOperator(char a) {
    bool ans = false;
    if ( a == '+' || a == '-' || a == '*' || a == '/' )
        ans = true;
    return ans;
}

Expression *ShuntingYard::algorithm(string expr) {
    /* the queue is for storing mostly numbers according to shunting yard algorithm*/
    queue<string> myQueue;
    /*the stack is for storing operators and brackets according to shunting yard algorithm*/
    stack<char> myStack;
    bool isNegative=false;
    for(int i = 0; i < expr.length(); i++){


        /*in this condition we check whether the givin char is a digit if it is, we keep on checking if there are
         * anymore digits following the original digit and after we have found the complete number we
         * push it into the queue, if the number is negative then after we push the current number
         * into the queue we push also zero into the queue for example -4= 0-4*/
        if ( isdigit(expr[i]) ){

            if(isNegative){
                myQueue.push("0");
            }
            string number = prepareNumber(expr,i);
            myQueue.push(number);
        }


        /*in this condition we check if the current character is an operator and the we check if top of
         * the stack is an operator that has a priority i.e: '*' has a priority over '+' so
         * if it has a priority then we push it into the queue otherwise we push it into the stack*/
        else if(isOperator(expr[i])){
            /*in this case I take care if we have the expression "4- -5" then I push
             * the value zero into the queue and later on it will be dequeued  0-4-5*/
            if(expr[i] == '+' || expr[i] == '-' ){
                if(expr[i]=='-'){
                    isNegative=true;
                }

                while( !myStack.empty() && (myStack.top() == '*' || myStack.top() == '/')){
                    string opr_toPush;
                    opr_toPush.push_back(myStack.top());
                    myQueue.push(opr_toPush);
                    myStack.pop();
                }
                myStack.push(expr[i]);
            }
            else if(expr[i] == '*' || expr[i] == '/'){
                myStack.push(expr[i]);
            }


        }
        else if(expr[i] == '('){
            myStack.push(expr[i]);
            isNegative=false;

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
            isNegative=false;
        }
        //I assumed that " " spaces splits the expressions
        else if(expr[i]==' '){
            expr.substr(1,expr.length());
            isNegative=false;
        }

    }
    return convert_toExpr(myQueue);
}

string ShuntingYard::prepareNumber(string expr, int i) {
    string toReturn;
    while(isdigit(expr[i])){
        toReturn+= expr[i];
        i++;
    }
    return toReturn;
}
/*need to finish this function*/
Expression *ShuntingYard::convert_toExpr(queue<string>& myQueue) {
    reverseContent(myQueue);
    while(!myQueue.empty()){

    }
    return nullptr;
}



/*this function reverses all the content of the given queue*/
void ShuntingYard::reverseContent(queue<string> &myQueue) {
    stack<string> tmpStack;
    while(!myQueue.empty()){
        tmpStack.push(myQueue.front());
        myQueue.pop();
    }
    while(!tmpStack.empty()){
        myQueue.push(tmpStack.top());
        tmpStack.pop();
    }
}

