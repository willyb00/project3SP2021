// Header file for Queue ADT. 

#include <new>
#include <cstddef>
#include <fstream>
class FullQueue
{};  

class EmptyQueue
{};  
template <class ItemType>
struct NodeType {
  ItemType info;
  NodeType<ItemType>* next;
  int priority;
}
template <class ItemType>
class PriorityQueue
{
public: 
  PriorityQueue();
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.
  PriorityQueue(int max);
    // Parameterized class constructor.
  ~PriorityQueue();
    // Class destructor.
  PriorityQueue(const PriorityQueue& anotherQue);
    // Copy constructor
    void makeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.
    bool isEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    bool isFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)
  void enqueue(ItemType newItem, int prio);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    ItemType dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
  ItemType peek();
  int peekPriority();
  int length();
  void printQueue(ofstream&);
private:
  int listLength;
  NodeType<ItemType>* front;
  NodeType<ItemType>* rear;
  int maxLength;
};

