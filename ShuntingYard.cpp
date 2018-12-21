//
// Created by Tomer Yona on 2018-12-20.
//

#include "ShuntingYard.h"
/*
 * this function checks if the give character is
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
/*this funtion will eventually return the final expression after all caculations*/
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
                myQueue.push("0,");
            }
            string number = prepareNumber(expr,i);
            myQueue.push(number+",");

        }


        /*in this condition we check if the current character is an operator and the we check if top of
         * the stack is an operator that has a priority i.e: '*' has a priority over '+' so
         * if it has a priority then we push it into the queue otherwise we push it into the stack*/
        else if(isOperator(expr[i])){
            /*this case i take is whether the following number is negative such as -4
             * this also takes care of the priority*/
            if(expr[i] == '+' || expr[i] == '-' ){
                if(expr[i]=='-'){
                    isNegative=true;
                }

                while( !myStack.empty() && (myStack.top() == '*' || myStack.top() == '/')){
                    string opr_toPush;
                    opr_toPush.push_back(myStack.top());
                    myQueue.push(opr_toPush+",");
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
                myQueue.push(opr_toPush+",");
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
    /*after all iterations we want to empty the stack and insert the operators into the our queue*/
    while(!myStack.empty()){
        string opr_toPush;
        opr_toPush.push_back(myStack.top());
        myQueue.push(opr_toPush+",");
    }
    return postfix_calc(myQueue);
}


/*this functions recieves a string and int as parameter and as long is a valid number then loop
 * keeps on running and in the end returns to caller the valid number as string*/
string ShuntingYard::prepareNumber(string expr, int i) {
    string toReturn;
    while(isdigit(expr[i])){
        toReturn+= expr[i];
        i++;
    }
    return toReturn;
}




/* i need to finish this function-- this is according to Reverse Polish notation algoritm*/
Expression *ShuntingYard::postfix_calc(queue<string>& myQueue) {
    stack <Expression*> exprStack;

    while(!myQueue.empty()){
        //case if the next value in our postfix queue is a number
        if(isValid_number(myQueue.front())){
        Number* number= new Number(myQueue.front());
        myQueue.pop();

            //caution for not popping out value
        if(!myQueue.empty() && myQueue.front()==","){
            //pop the delimeter value ","
            myQueue.pop();
        }

        exprStack.push(number);
        }
        //this case is if the next value is an operator
        else{
            Expression* right_num = exprStack.top();
            exprStack.pop();

            //caution for not popping out value
            if(!myQueue.empty() && myQueue.front()==","){
                //pop the delimeter value ","
                myQueue.pop();
            }
            Expression* left_num= exprStack.top();
            exprStack.pop();
            //caution for not popping out value
            if(!myQueue.empty() && myQueue.front()==","){
                //pop the delimeter value ","
                myQueue.pop();
            }

            char oper_toCalc= myQueue.front()[0];

            switch(oper_toCalc){
                case '+':{
                    Plus* plus= new Plus(left_num,right_num);
                    exprStack.push(plus);
                    myQueue.pop();
                    //caution for not popping out value
                    if(!myQueue.empty() && myQueue.front()==","){
                        //pop the delimeter value ","
                        myQueue.pop();
                    }

                    break;
                }
                case '-':{
                    Minus* minus= new Minus(left_num,right_num);
                    exprStack.push(minus);
                    myQueue.pop();
                    //caution for not popping out value
                    if(!myQueue.empty() && myQueue.front()==","){
                        //pop the delimeter value ","
                        myQueue.pop();
                    }
                    break;
                }
                case '*':{
                    Multiply* multiply= new Multiply(left_num,right_num);
                    exprStack.push(multiply);
                    myQueue.pop();
                    //caution for not popping out value
                    if(!myQueue.empty() && myQueue.front()==","){
                        //pop the delimeter value ","
                        myQueue.pop();
                    }
                    break;
                }
                case '/':{
                    Divide* divide= new Divide(left_num,right_num);
                    exprStack.push(divide);
                    myQueue.pop();
                    //caution for not popping out value
                    if(!myQueue.empty() && myQueue.front()==","){
                        //pop the delimeter value ","
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
    for(int i = 0; i < number.length(); i++){
        if(isNumber(number[i])){
            ans=true;
        }
    }
    return ans;
}

