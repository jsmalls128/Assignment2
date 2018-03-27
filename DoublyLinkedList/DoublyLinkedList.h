#include "ItemType.h"
struct NodeType{
  ItemType data;
  NodeType* next;
  NodeType* back;
};

class DoublyLinkedList{
  
  int length;                 
  NodeType *head;                       // Points to start of list or NULL
  NodeType *current;                    // Points to the current pointer
  
  public:
    DoublyLinkedList();                 // Creates a DoublyLinkedList
    ~DoublyLinkedList();                // Frees all nodes in a DoublyLinkedList
    int lengthIs() const;               // returns length of the list
    void insertItem(ItemType &item);    // inserts an item in a sorted manner
    void deleteItem(ItemType &item);    // deletes the node that contains the item
    void print();                       // prints the contents of the list
    void additivePairs(ItemType &item); // finds the amount and additive pairs of the item
};