#include "PriorityQueue.h"
#include <string>

using namespace std;

template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue() {

  listLength = 0;
  front = NULL;
  rear = NULL;
  maxLength = -1;
  
}
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.

template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue(int max) {

  listLength = 0;
  front = NULL;
  rear = NULL;
  maxLength = max;
  
}
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
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& anotherQue) {
  listLength = anotherQue.listLength;
  front = anotherQue.front;
  rear = anotherQue.rear;
  maxLength = anotherQue.maxLength;
}
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
  if (listLength == 0) {
    return true;
  }
  //Otherwise, it is not empty
  return false;
}

template <class ItemType>
bool PriorityQueue<ItemType>::isFull() const {

  if (maxLength != listLength || maxLength == -1) {
    return false;
  }
  return true;
  
}
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)

template <class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType newItem, int prio) {
  if (isFull()) {
    throw FullQueue();
  }

  NodeType<ItemType>* insert = new NodeType<ItemType>;
  insert->info = newItem;
  insert->priority = prio;
  if (isEmpty()) {
    insert->next = NULL;
    front = insert;
    rear = insert;
    listLength++;
  } else {
    bool found = false;
    NodeType<ItemType>* location = front;
    NodeType<ItemType>* prev = front;
    //need to put new item in the front
    if (location->priority > prio) {
      insert->next = location;
      front = insert;
      listLength++;
      found = true;
    } else {
      //need to put the new item in the middle
      location = location->next;
    }
    while (found == false) {

      //need to append the new item
      if(location == NULL) {
	location = insert;
	insert->next = NULL;
	prev->next = insert;
	rear = insert;
	listLength++;
	found = true;
      } else if (location->priority > prio) {
	prev->next = insert;
	insert->next = location;
	listLength++;
	found = true;
      }
      /*
      if (!found) {
	location = location->next;
	prev = prev->next;
      }
      */
      location = location->next;
      prev = prev->next;
    }
    
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
  } else {
  //Here, the first node and its value are given to temp holders
  NodeType<ItemType>* temp = front;
  ItemType tempret = front->info;
  item = tempret;
  //Here, the front pointer moves forward and decriments listLength
  front = front->next;
  listLength--;
  //Here, the dequeued node is deleted and its value returned
  delete temp;
  return tempret;
  }
  return item;
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
