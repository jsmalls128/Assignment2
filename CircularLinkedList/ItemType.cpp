#include "ItemType.h"

ItemType::ItemType(){
  
}
void ItemType::print(){
  std::cout << this->value;
}
void ItemType::initialize(int number){
  this->value = number;
}
int ItemType::getValue() const{
  return this->value;
}
bool ItemType::operator <( ItemType & t){
  return (this->value < t.getValue());
}
bool ItemType::operator >(ItemType & t) {
  return (this->value > t.getValue());
}
bool ItemType::operator ==(ItemType & t) {
  return (this->value == t.getValue());
}