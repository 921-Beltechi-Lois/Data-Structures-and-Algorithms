#include "Stack.h"
#include <exception>
#include <iostream>

using namespace std;

// default constructor
Stack::Stack(int capacity): capacity{capacity},size{0}{
	//TODO - Implementation
    this->elems=new TElem[this->capacity];
}
// copy constructor
Stack::Stack(const Stack& v){
    this->capacity = v.capacity;
    this->size = v.size;
    this->elems = new TElem[this->capacity];
    for(int i=0; i<this->size; i++){
        this->elems[i] = v.elems[i];
    }
}

/// v1=v2=v3 assignment operator
Stack& Stack::operator=(const Stack& v){
    if(this==&v){
        return *this;
    }
    this->capacity = v.capacity;
    this->size = v.size;
    delete[] this->elems;   /// ?
    this->elems = new TElem[this->capacity];
    for (int i = 0; i < v.size; i++)
        this->elems[i] = v.elems[i];

    return *this;
}
void Stack::printStack(Stack & s){
    for(int i=0;i<s.size;i++)
        std::cout<<this->elems[i]<<" ";
}
// Complexity Thetha(1)


//add
void Stack::push(TElem e) {
	//TODO - Implementation
    if(isFull())
        resize();
    this->elems[this->size] = e;
    this->size++;
}

TElem Stack::top() const {
	//TODO - Implementation

    TElem return_top_element = NULL_TELEM;
    if(isEmpty())
        throw exception();

    return_top_element = this->elems[this->size-1];
    return return_top_element;
} // Complexity: Theta(1)
//delete
TElem Stack::pop() {
	//TODO - Implementation

    TElem return_top_element = NULL_TELEM;
    if(isEmpty()){
        throw exception();
    }
    this->size--;
    return_top_element=this->elems[this->size];
    return return_top_element;
} // Complexity: Theta(1)

bool Stack::isEmpty() const {
	//TODO - Implementation
    return this->size == 0 ;
} // Complexity: Theta(1)

bool Stack::isFull() const {
    ///TODO - Implementation
    return this->size == this->capacity;
} // Complexity: Theta(1)

Stack::~Stack() {
	//TODO - Implementation
    delete [] this->elems;
}

void Stack::resize()
{

    this->capacity *= 2;
    TElem* aux_array = new TElem[this->capacity];  // sizeof(telem)*this->capacity
    for (int i = 0; i < this->size; i++) {
        aux_array[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = aux_array;

} // Complexity: Theta(n)

