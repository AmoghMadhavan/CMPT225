
#include "Stack.cpp"

#include <iostream>

using namespace std;


int main () {
    Stack stk;

    // push 1, 2, 3, 4, 5

    stk.push(2);

    // cout<< stk.peek()<<endl;

    // stk.pop();

    // cout<< stk.peek();
  
    for (int i = 1; i <= 5; i++) {
        stk.push(i);
        cout << "push " << i << endl;
    }

    // pop top two
    for (int i = 0; i < 2; i++) {
        int x = stk.pop();
        int y = stk.peek();
        cout << "pop " << x << ", top " << y << endl;
    }
    for (int i = 0; i < 2; i++) {
        int x = stk.pop();
        int y = stk.peek();
        cout << "pop " << x << ", top " << y << endl;
    }


    // // push 6, 7, 8, 9, 10
    for (int i = 6; i <= 11; i++) {
        stk.push(i);
        cout << "push " << i << endl;
    }


    // // pop all
    while (!stk.isEmpty()) {
        int x = stk.pop();
        int y = stk.peek();
        cout << "pop " << x << " top " << y<<endl;
    }


    return 0;
}

