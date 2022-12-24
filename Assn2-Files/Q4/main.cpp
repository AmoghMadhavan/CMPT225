
#include "Queue.h"
#include <iostream>
using namespace std;


int main () {
    Queue Q;


    Q.dequeue();
   cout<<Q.peek()<<endl;

    //enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        int x = Q.peek();
        cout << "frontmost vall " << x << endl;  
        Q.enqueue(i);
        cout << "enqueue " << i << endl;


    }


    // dequeue 2x elements
    for (int i = 0; i < 2; i++) {
       // int y = Q.peek();
        Q.dequeue();

        int x = Q.peek();
        cout << "frontmost vall " << x << endl;
        //cout<<"val "<<x<<endl;
    }



    // enqueue 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) {
        Q.enqueue(i);
        cout << "enqueue " << i << endl;
        
        int x = Q.peek();
        cout << "frontmost vall " << x << endl;  

    }

    cout << "vall " << Q.peek() << endl;



    // // dequeue all elements
    while (!Q.isEmpty()) {
        int y = Q.peek();
        Q.dequeue();
        int x = Q.peek();
        cout << "frontmost vall " << x << endl;
    }
    cout << "vall " << Q.peek() << endl;

    return 0;
}

