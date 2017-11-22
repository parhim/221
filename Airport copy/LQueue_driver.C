/*---------------------------------------------------------------------
 Driver program to test the Queue class.
 ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;


void print(Queue q)
{ q.display(cout); }

int main(void) {
    Queue q1;
    cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;
    
    cout << "How many elements to add to the queue? ";
    int numItems;
    cin >> numItems;
    for (int i = 1; i <= numItems ; i += 1){
        cout << "item : " << i << endl;
        int k;
        cin >> k;
        q1.enqueue(k);
    }
       
    cout << "Contents of queue q1 (via  print):\n";
    print(q1);
    cout << endl;
    
    
    Queue q2;
    cout << "How many elements to add to the queue 2? ";
    int numItems2;
    cin >> numItems2;
    for (int i = 1; i <= numItems2; i += 1){
        cout << "item : " << i << endl;
        int k;
        cin >> k;
        q2.enqueue(k);
    }
    cout << "Contents of queue q2 :\n";
    print(q2);
    q1.merge_two_queues(q2);
    cout << "Contents of queue q1 after merge:\n";
    print(q1);
    cout << endl;
    
    cout << "Queue q2 empty? " << q2.empty() << endl;
    
    
    
    cout << "Front value in q2: " << q2.front() << endl;
    
    while (!q1.empty())
    {
        cout << "Remove front -- Queue contents: ";
        q1.dequeue();
        q1.display(cout);
    }
    cout << "Queue q1 empty? " << q1.empty() << endl;
    cout << "Front value in q1?" << endl << q1.front() << endl;
    cout << "Trying to remove front of q2: " << endl;
    q1.dequeue();
    //system("PAUSE");
    return 0;
}
