#include <iostream>

using namespace std;

class MyDynamicArray {
    private:
        int size, capacity, error;
        int *a;
    public:
        MyDynamicArray() {
            capacity = 2;
            size = 0;
            error = 0;
            a = new int[capacity];            
        }
        MyDynamicArray(int s) {
            capacity = s;
            size = s;
            error = 0;
            a = new int[capacity];            
        }
        int& operator[](int i){
            if(i >= size){
               cout << "Out of bounds reference: " << i << endl;
               return error;
            }
            else{
               return a[i];
               }
        }
        void add(int v) {
           if(size == capacity){
              capacity *= 2;
              cout << "Doubling to : " << capacity << endl;} 
            int *b = a;
            a = new int[capacity];
            a = b;
            a[size] = v;
            size++;
        }
        void del() {           
           if(size<=capacity/4){
              capacity /= 2;
              cout << "Reducing to : " << capacity << endl;}
            size--;
        }
        int length() {
            return size;
        }
        void clear() {
            delete[] a;
            capacity = 2;
            size = 0;
            a = new int[capacity];
        }
};
