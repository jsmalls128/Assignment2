#include "CircularLinkedList.h"
 
CircularLinkedList::CircularLinkedList(){
  this->length = 0;
  this->head = NULL;
  this->current = NULL;
} // CircularLinkedList

CircularLinkedList::~CircularLinkedList(){
  NodeType* tempPtr;
  current = head->next;
  while (current != head){
    tempPtr = current->next;
    delete current;
    current = tempPtr; 
  }
  this->length = 0;
  delete head;
} // ~CircularLinkedList

int CircularLinkedList::lengthIs() const{
  return this->length;
} // lengthIs

void CircularLinkedList::insertItem(ItemType &item){
  if(length == 0){                     // Case for handling inserting into an empty list
    NodeType* newNode = new NodeType;
    newNode->data = item;
    head = newNode;
    head->next = head;
    length++;
  }
  else{
    bool moreToSearch = true;
    bool found = false;
    NodeType* newNode = new NodeType;
    newNode->data = item;
    NodeType* ptrNode = head->next;
    NodeType* pevNode = head;
    
    while(moreToSearch && !found){      // Searches for the item and sets pevNode and ptrNode
      if(item < ptrNode->data){
        moreToSearch = false;
      }
      else if(item == ptrNode->data){
        found = true;
      }
      else{
        pevNode = ptrNode;
        ptrNode = ptrNode->next;
        moreToSearch = (ptrNode != head->next);
      }
    }
    
    newNode->next = pevNode->next;     // General Case
    pevNode->next = newNode;
    
    if (head->data < item){            // Reassigns the head if the inserted node is the last one.
      head = newNode;  
    }
    length++;
  } 
} // insertItem

void CircularLinkedList::deleteItem(ItemType &item){
  if(length == 0 ){                     //  If the list is empty, cannot delete anything
    std::cout << "Cannot Delete, List is empty";
    return;
  }
  bool found = false;
  bool moreToSearch = true;
  NodeType* ptrNode = head->next;
  NodeType* pevNode = head;
  
  if(length == 1){                      // Handles deleting the only item in list
    head = NULL;
    length--;
  }
  else{   
     while(moreToSearch && !found){     // Searches for the item and sets pevNode and ptrNode
       if(item < ptrNode->data){
        moreToSearch = false;
      }
      else if(item == ptrNode->data){
        found = true;
      }
      else{
        pevNode = ptrNode;
        ptrNode = ptrNode->next;
        moreToSearch = (ptrNode != head->next);
      }
    }
    if(!found){                         // If the item is not in the list
      std::cout << "Item not in the list!" <<std::endl;
      return;
    }
    pevNode->next = ptrNode->next;
    
    if(ptrNode == head){                // Changes head if the last node needs to be deleted
      head = pevNode;
    }
    if(found){
      delete ptrNode;
      length--;
    }
  }
} // deleteItem

void CircularLinkedList::print(){
  int headValue;
  if(length > 0){                     // If the list is not empty, print items in list
  NodeType* ptrNode = head->next;                       
    if(length != 1){
      do{
        std::cout << ptrNode->data.getValue() << " ";
        ptrNode = ptrNode->next;
      } while(ptrNode != head);
    }
    headValue = head->data.getValue();
    std::cout << headValue << std::endl;
  }
  else
    std::cout << "\n";
} // print