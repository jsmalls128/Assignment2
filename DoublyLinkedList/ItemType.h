#include <iostream>

class ItemType{
 
 private:
 
 int value;
 
 public:
   // constructor for ItemType object
   ItemType(); 
   // value instance variable is printed to standard-out
   void print(); 
   // sets value equal to number
   void initialize(int number);
   // returns the value instance variable
   int getValue() const; 
   
   // Overloaded operators
  bool operator <( ItemType & t); 
  bool operator >( ItemType & t); 
  bool operator == ( ItemType & t);
};
  