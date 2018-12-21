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
    stack<string> operatorStack;
    stack<Expression> operandStack;
    bool pending_operand;
    reverseContent(myQueue);
    string token;
    while(!myQueue.empty()){

        token=myQueue.front();
        //pops out the number/operator from queue
        myQueue.pop();
        if(isOperator(token[0])){
            string opr_toPush;
            opr_toPush.push_back(token[0]);
            pending_operand= false;
            continue;
        }
        else {
            string operand;
            while (!myQueue.empty() && myQueue.front() != ",") {
                operand += myQueue.front();
                double double_operand= stod(operand);
                myQueue.pop();
            }
            if (pending_operand) {
                while(!operandStack.empty()){
                    Number operand_left=operandStack.top();
                    operandStack.pop();
                    string curr_operator= operatorStack.top();
                    operatorStack.pop();
                    string operand_right=operandStack.top();
                    operandStack.pop();
                    //need to caclulate the current operand ---> do here calculation
                }


            }
            //push here the operand into the operand stack ----> push here to stack
            pending_operand=true;
            //double double_expr = stod(operandStack.top());
            //Expression num= new Number(operandStack.top());




        }




        //pops out the comma that seprates between values in queue
        myQueue.pop();
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

