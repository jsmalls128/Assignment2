#include "ItemType.h"
struct NodeType{
  ItemType data;
  NodeType* next;
};

class CircularLinkedList{
  
  int length;                         // The length of the list
  NodeType *head;                     // Points to start of list or NULL
  NodeType *current;                  // Points to the current pointer
  
  public:
    CircularLinkedList();             // Creates a CircularLinkedList
    ~CircularLinkedList();            // Frees all nodes in a CircularLinkedList
    int lengthIs() const;             // Returns length of the list
    void insertItem(ItemType &item);  // Inserts an item in a sorted manner
    void deleteItem(ItemType &item);  // Deletes the node that contains the item
    void print();                     // prints the contents of the list
};