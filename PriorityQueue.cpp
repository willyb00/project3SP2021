#include "PriorityQueue.h"
#include <string>

using namespace std;

template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue() {
  
}
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.

template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue(int max);
    // Parameterized class constructor.

template <class ItemType>
PriorityQueue<ItemType>::~PriorityQueue() {
  //This pointer will be used to delete nodes
  NodeType<ItemType>* tempPtr;
  //While the first node isn't NULL, delete it, and then move forward
  while(front != NULL)
  {
    tempPtr = front;
    front = front->next;
    delete tempPtr;
  }
  listLength = 0;
}
    // Class destructor.

template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue& anotherQue);
    // Copy constructor

template <class ItemType>
void PriorityQueue<ItemType>::makeEmpty() {
  //This pointer will be used to delete nodes
  NodeType<ItemType>* tempPtr;
  //The rear pointer is set to NULL, because it will not be needed anymore
  rear = NULL;
  //While the first node isn't NULL, delete it, and then move forward
  while(front != NULL)
  {
    tempPtr = front;
    front = front->next;
    delete tempPtr;
  }
  listLength = 0;
}
    
template <class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
  //If the length is 0, the list is empty
  if (length == 0) {
    return true;
  }
  //Otherwise, it is not empty
  return false;
}

template <class ItemType>
bool PriorityQueue<ItemType>::isFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)

template <class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem, int prio = 1) {
  if (isFull()) {
    throw FullQueue();
  }
  
}
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.

template <class ItemType>
ItemType PriorityQueue<ItemType>::dequeue(ItemType& item) {
  //If the queue is empty, throw an exception
  if (isEmpty()) {
    throw EmptyQueue();
  }
  //Here, the first node and its value are given to temp holders
  NodeType<ItemType>* temp = front;
  ItemType tempret = temp->info;
  //Here, the front pointer moves forward and decriments listLength
  front = front->next;
  listLength--;
  //Here, the dequeued node is deleted and its value returned
  delete temp;
  return tempret;
}

template <class ItemType>
ItemType PriorityQueue<ItemType>::peek() {
  if (isEmpty()) {
    throw EmptyQueue();
  }
  //Here, the front node's value is returned and the queue is unchanged
  return front->info;
}

template <class ItemType>
int PriorityQueue<ItemType>::peekPriority() {
  if (isEmpty()) {
    throw EmptyQueue();
  }
  //Here, the front node's priority is returned and the queue is unchanged
  return front->priority;
}

template <class ItemType>
int PriorityQueue<ItemType>::length() {
  return listLength;
}

template <class ItemType>
void PriorityQueue<ItemType>::printQueue(ofstream& outFile) {
  NodeType<ItemType>* temp = front;
  outFile << "Queue: ";
  while (temp != NULL) {
    outFile << temp->info << " ";
    temp = temp->next;
  }
}
