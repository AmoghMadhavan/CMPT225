/* 
 * Eval.cpp
 *
 * Description: Implementation of the pseudocode which does arithmetic from infix to postfix.  evaluate a single well-formed arithmetic expression from standard input, and display the result on standard output.
 * Class Invariant: single well-formed arithmetic expression from standard input
 * Need to be inputted from files else EOF won't be called.
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: February 18, 2022
 */

#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>
using namespace std;



int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();

    //pseudocode implementation which was provided.
    while ((t.tt != eof)||(!opstack.isEmpty())){
        if(t.tt != eof && t.tt == integer){
            numstack.push(t);
            t = S.getnext();
        }
        else if(t.tt == lptok){
            opstack.push(t);
            t = S.getnext();
        }
        else if(t.tt == rptok){
            if(opstack.peek().tt == lptok){
                opstack.pop();
                t = S.getnext();
            }
            else{
                //operation perfomed it could be + - * /
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();
                Token result;
                if (op.tt == pltok){
                    result.val = y.val + x.val;
                }
                else if (op.tt == mitok){
                    result.val = y.val - x.val;
                }
                else if (op.tt == slashtok){
                    result.val = y.val / x.val;
                }
                else if (op.tt == asttok){
                    result.val = y.val * x.val;
                }
                numstack.push(result);
            }
        }
        else if((t.tt == pltok)||(t.tt == mitok)||(t.tt == eof)){
            if((!opstack.isEmpty())&&((opstack.peek().tt == pltok)||(opstack.peek().tt == mitok)||(opstack.peek().tt == slashtok)||(opstack.peek().tt == asttok))){
                //operation perfomed it could be + - * /
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();
                Token result;
                if (op.tt == pltok){
                    result.val = y.val + x.val;
                }
                else if (op.tt == mitok){
                    result.val = y.val - x.val;
                }
                else if (op.tt == slashtok){
                    result.val = y.val / x.val;
                }
                else if (op.tt == asttok){
                    result.val = y.val * x.val;
                }
                numstack.push(result);
            }
            else{
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if((t.tt == asttok)||(t.tt == slashtok)){
            if((!opstack.isEmpty())&&((opstack.peek().tt == asttok)||(opstack.peek().tt == slashtok))){
                //operation perfomed it could be + - * /
                Token x = numstack.pop();
                Token y = numstack.pop();
                Token op = opstack.pop();
                Token result;
                if (op.tt == pltok){
                    result.val = y.val + x.val;
                }
                else if (op.tt == mitok){
                    result.val = y.val - x.val;
                }
                else if (op.tt == slashtok){
                    result.val = y.val / x.val;
                }
                else if (op.tt == asttok){
                    result.val = y.val * x.val;
                }
                numstack.push(result);
            }
            else{
                opstack.push(t);
                t = S.getnext();
            }
        }
    }
    //answer is printed out.
    cout<<numstack.pop().val<<endl;

    return 0;
}

