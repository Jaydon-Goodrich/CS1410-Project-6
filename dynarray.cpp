// This is my own work Jaydon Goodrich
#include <iostream>
#include <stdexcept>
#include "dynarray.h"

int DEFAULT_CAP = 2;

DynArray::DynArray(){
   _capacity = DEFAULT_CAP;
   _size = 0;
   _data = new int [_capacity];
}
DynArray::~DynArray(){
   if(_data != nullptr){ 
      delete[] _data;
      _data = nullptr;
   }
}
int DynArray::size() const{
   return _size;
}
int DynArray::capacity() const{
   return _capacity;
}
void DynArray::clear(){
   if(_data != nullptr){ 
      delete[] _data;
      _data = nullptr;
   }
   _size = 0;
   _capacity = DEFAULT_CAP;
   _data = new int[_capacity];
}
void DynArray::push_back(int n){
   if(_size == _capacity){
      DynArray::grow();
   }
   _data[_size] = n;
   _size++;
}
void DynArray::pop_back(){
   if(_size>0){
      _size--;
   }
}
int DynArray::at(int n){
   if(n >= _size || n < 0){
      throw std::runtime_error("invalid index");
   }
   else{
      return _data[n];
   }
}
void DynArray::grow(){
   _capacity = _capacity + _capacity;
   int* newArray = new int[_capacity];
   for(int i = 0; i < _size; i++){
      newArray[i] = _data[i];
   }
   delete[] _data;
   _data = nullptr;
   _data = newArray;
}
