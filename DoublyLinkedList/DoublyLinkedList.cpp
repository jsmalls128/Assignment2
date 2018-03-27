#include "DoublyLinkedList.h"
 
DoublyLinkedList::DoublyLinkedList(){
  this->length = 0;
  this->head = NULL;
  this->current = NULL;
} // DoublyLinkedList

DoublyLinkedList::~DoublyLinkedList(){
  NodeType* tempPtr;
  current = head;
  while (current != NULL){
    tempPtr = current->next;
    delete current;
    current = tempPtr; 
  }
  this->length = 0;
  delete tempPtr;
} // ~DoublyLinkedList

int DoublyLinkedList::lengthIs() const{
  return this->length;
} // lengthIs

void DoublyLinkedList::insertItem(ItemType &item){
  if(length == 0){                          // case for handling inserting into an empty list
    NodeType* newNode = new NodeType;
    newNode->data = item;
    head = newNode;
    length++;
  }
  else{                                     
    bool moreToSearch = true;
    NodeType* newNode = new NodeType;
    newNode->data = item;
    current = head;
    NodeType* pevNode;
    
    while(moreToSearch){                    // sets current, previous node
      if(item < current->data){
        moreToSearch = false;
      }
      else{
        pevNode = current;
        current = current->next;
        moreToSearch = (current != NULL);
      }
    }
    if(current == NULL){                   // Inserting at the end
      newNode->back = pevNode;
      pevNode->next = newNode;
      length++;
    }
    else if(current->back == NULL){        // Inserting in the beginning
      newNode->next = current;
      current->back = newNode;
      head = newNode;
      length++;
    }
    else{                                  // Inserting in the middle
      newNode->back = current->back;
      newNode->next = current;
      pevNode->next = newNode;
      current->back = newNode;
      length++;
    }
  } 
} // insertItem

void DoublyLinkedList::deleteItem(ItemType &item){
  
  bool found = false;
  bool moreToSearch = true;
  current = head;
  NodeType* pevNode = NULL;
  
  if(length == 0 ){
    std::cout << "Cannot Delete, List is empty";
    return;
  }
 
  if(length == 1){ // Handles deleting the only item in list
    head = NULL;
    delete  current;
    length--;
  }
  else{   
  
    while(moreToSearch && !found){                    // sets current, previous node
      if(item < current->data){
        moreToSearch = false;
      }
      else if(item == current->data){
        found = true;
      }
      else{
        pevNode = current;
        current = current->next;
        moreToSearch = (current != NULL);
      }
    }
    
    if(found){                                       // If item is in list
      
      if(pevNode == NULL){                           // deletes first item
        head = current->next;
        delete current;
        length--;
      }
      else if(current->next == NULL){                // deletes last item
        current->back->next = NULL;
        delete current;
        length--;
      }
      else{                                          // general case
        pevNode->next = current->next;
        current->next->back = pevNode;
        delete current;
        length--;
      }
    }
    else{
      std::cout << "Item not in the list!" <<std::endl;
      return;
    }
  }
} // deleteItem

void DoublyLinkedList::print(){
  current = head;
  while(current != NULL){
      std::cout << current->data.getValue() << " ";
      current = current->next;
    }
    std::cout << std::endl;
} // print

void DoublyLinkedList::additivePairs(ItemType &item){
  // The list is sorted so we can do some simplification
  // You should only add up to the value of item (more efficient than while loop)
  // You need to keep the value of item
  // A nested for loop to compare the additions
  
  int number = item.getValue();
  int possibilities = 0;
  current = head;
  NodeType* secondPtr = head->next;
  std::cout << "Pairs: ";
  for(int i = current->data.getValue(); i < number; i = current->data.getValue()){
    for(int j = secondPtr->data.getValue(); j < number; j = secondPtr->data.getValue()){
      if((i+j) == number){
        possibilities++;
        std::cout << "("<<i <<"," <<j<<") ";
      }
      secondPtr = secondPtr->next;
      if(secondPtr == NULL)
        break;
    }
    current = current->next;
    secondPtr = current->next;
    if(current == NULL ||secondPtr == NULL)
      break;
  }
  std::cout << "\nPossibilities: "<< possibilities << std::endl;
} // additivePairs