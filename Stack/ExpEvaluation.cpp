#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
#include "Stack.h"
#include "OptrPriority.h"

int index(char op) {
    switch (op) {
        case '+': return ADD; break;
        case '-': return SUB; break;
        case '*': return MUL; break;
        case '/': return DIV; break;
        case '^': return POW; break;
        case '!': return FAC; break;
        case '(': return LP; break;
        case ')': return RP; break;
        case '\0': return EOE; break;
        default: return -1;
    }
}

char orderBetween(char op1, char op2) {
    return pri[index(op1)][index(op2)];    
}

float fac(float opnd) {
    int n = (int)opnd;
    int f = 1;
    while (n) f *= n--; 
    return (float)f; 
}

float calc(char op, float d1, float d2) {
    switch(op) {
        case '+': return d1 + d2;
        case '-': return d1 - d2;
        case '*': return d1 * d2;
        case '/': return d1 / d2;
        case '^': return pow(d1, d2);
        default : exit(-1);
    }
}

void readNumber(char* & exp, Stack<float> & opnd) {
    float num = (*exp) - '0';
    while (isdigit(*(++exp))) 
        (num *= 10)  += ((*exp) - '0');
    opnd.push(num);
}

float eval(char* exp) {
    Stack<float> opnd; Stack<char> optr;
    optr.push('\0');
    while (!optr.empty()) {
        if (isdigit(*exp))
            readNumber(exp, opnd);
        else //当前是操作符
            switch(orderBetween(optr.top(), *exp)) {
                case '<':
                    optr.push(*exp); exp++;
                    break;
                case '=':
                    optr.pop(); exp++;  // (和) 或者 \0和\0一起退出历史舞台
                    break;
                case '>': { 
                    char op = optr.pop();
                    if ('!' == op) opnd.push(fac(opnd.pop()));
                    else {
                        float d2 = opnd.pop(); float d1 = opnd.pop();
                        opnd.push(calc(op, d1, d2));
                    }
                }
                break;
                case ' ': cout << "Invalid expression!" << endl; exit(-1);
            }
    }
    return opnd.pop();
}


int main() {
    cout << eval("(1+2^3!-4)*(5!-(6-(7-(89-0!))))") << endl;
    return 0;
}
