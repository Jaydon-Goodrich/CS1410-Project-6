// This is my own work Jaydon Goodrich
/* Using the concept of pointers in c++ this project creates a Dynamic Array very similar to the vector class. */
#include <iostream>
using namespace std;

class DynArray{
// public class members
   public:
   DynArray();
   DynArray(int n);
   ~DynArray();
   int size() const;
   int capacity() const;
   void clear();
   void push_back(int n);
   void pop_back();
   int at(int n);
   void grow();
   
//private class members
   private:
   int _capacity;
   int _size;
   int* _data = nullptr;
};
