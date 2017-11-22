/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}



void Queue::move_to_front(int key){
    Queue::NodePointer prev;
    Queue::NodePointer cur = myFront;
    if (empty()){
        cout << "No Elements in the q" << endl;
    }
    do {
        if (cur->data==key) {
            
            if (cur==myFront){return;}
            if (!(cur->next)) {
                myBack = prev;
            }
            prev->next = cur->next;
            cur->next = myFront;
            myFront = cur;
            return;
        }
        
        if (!(cur->next)) {
            cout << "key not found"<< endl;
            return;
        }
        prev = cur;
        cur = cur->next;
    } while (1);
}





void Queue::merge_two_queues(Queue::Queue q2){
    Queue::NodePointer prev1;
    
    // make node from q2[0]->data
    // q2.myFront = q2.myFront->next
    if (empty()){
        if (q2.empty()){
            return;
        }
        enqueue(q2.myFront->data);
        q2.myFront = q2.myFront->next;
    }
    
    for (Queue::NodePointer p2 = q2.myFront; p2 != 0; p2 = p2->next) {
        for (Queue::NodePointer p1 = myFront; p1 != 0; p1 = p1->next) {
            Queue::NodePointer cur1 = p1;
            
            Queue::NodePointer cur2 = new Queue::Node(p2->data);
            cur2->next = p2->next;
            int v2 = cur2->data;
            int v1 = cur1->data;
            
            
            if (v2 < v1 && cur1 == myFront) {
                cur2->next = cur1;
                myFront = cur2;
                break;
            } else if (v2 < v1 && cur1 != myFront) {
                prev1->next = cur2;
                cur2->next = cur1;
                break;
            }
            
            if (v2 >= v1) {     ///if at the last element of q1 and the element in q2 is greater
                if (cur1 == myBack) {
                    cur1->next = cur2;
                    myBack = cur2;
                    break;
                }
                
            }
            
            prev1 = cur1;
            
        }
    }
}



/*
 void Queue::merge_two_queues(Queue::Queue q2){
 Queue::NodePointer prev1;
 for (Queue::NodePointer p2 = q2.myFront; p2 != 0; p2 = p2->next) {
 for (Queue::NodePointer p1 = myFront; p1 != 0; p1 = p1->next) {
 Queue::NodePointer cur1 = p1;
 Queue::NodePointer cur2 = new Queue::Node(p2->data);
 cur2->next = p2->next;
 int v2 = cur2->data;
 int v1 = cur1->data;
 
 if (v2 < v1 && cur1 == myFront) {
 cur2->next = cur1;
 myFront = cur2;
 break;
 } else if (v2 < v1 && cur1 != myFront) {
 prev1->next = cur2;
 cur2->next = cur1;
 break;
 }
 
 if (v2 >= v1) {     ///if at the last element of q1 and the element in q2 is greater
 if (cur1 == myBack) {
 cur1->next = cur2;
 myBack = cur2;
 break;
 }
 
 }
 
 prev1 = cur1;
 cout << "val1 | val2"<< endl;
 cout << v1 << "    | " << v2 << endl;
 }
 }
 }
 */


