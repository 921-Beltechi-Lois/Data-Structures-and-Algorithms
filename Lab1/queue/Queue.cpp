#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;


Queue::Queue(int capacity): capacity{capacity}, size{0}, front{-1}, rear{-1}{
	//TODO - Implementation
    this->elems= new TElem[this->capacity];
}

// copy constructor
Queue::Queue(const Queue& v){
    this->capacity = v.capacity;
    this->size = v.size;
    this->front = v.front;
    this->rear = v.rear;
    this->elems = new TElem[this->capacity];
    for(int i=0; i<this->size; i++){
        this->elems[i] = v.elems[i];
    }
}

/// v1=v2=v3 assignment operator
Queue& Queue::operator=(const Queue& v){
    if(this==&v){
        return *this;
    }
    this->capacity = v.capacity;
    this->size = v.size;
    this->front = v.front;
    this->rear = v.rear;
    delete[] this->elems;   /// ?
    this->elems = new TElem[this->capacity];
    for (int i = 0; i < v.size; i++)
        this->elems[i] = v.elems[i];

    return *this;
}

void Queue::push(TElem elem) {
	//TODO - Implementation
    if(isFull())
        resize();

    if(isEmpty())
        rear=front=0;

    //this->elems[this->size]=elem;
    //this->size++;
    else{
        rear=(rear+1)%this->capacity; //todo capacity?
    }
    //this->rear++;
    this->elems[rear] = elem;
} // Complexity: Theta(1)


TElem Queue::top() const {
	//TODO - Implementation
    TElem front_element = NULL_TELEM;
    if(isEmpty()){
        throw exception();
    }
    // front
    //front_element = this->elems[0];
    front_element = this->elems[front];
    return front_element;
} // // Complexity: Theta(1)

TElem Queue::pop() {
	//TODO - Implementation
    TElem removed_element = NULL_TELEM;
    if(isEmpty()){
        throw exception();
    }
    //removed_element = this->elems[0];
    //for(int i=1;i<this->size;i++){
      //  this->elems[i-1] = this->elems[i];
    //}
    //this->size--;
    if(front==rear){
        removed_element = this->elems[front];
        front=rear=-1; // resize?
    }
    else{

        removed_element = this->elems[front];
        front=(front+1)%this->capacity;
        //halfQueueCapacity();

    }
    return removed_element;
} // Complexity: Theta(1)

bool Queue::isEmpty() const {
	//TODO - Implementation
	//return this->size == 0;
    if(this->front == -1 && this->rear == -1)
        return 1;
    return 0;
} // Complexity: Theta(1)
bool Queue::isFull() const {
    //TODO - Implementation
    //return this->size == this->capacity;
    if((this->rear+1)%(this->capacity)==this->front)
        return 1;
    return 0;
} // Complexity: Theta(1)


Queue::~Queue() {
	//TODO - Implementation
    delete [] this->elems;
}

void Queue::resize()
{   int len = queueSize(), i;

    //this->capacity= this->capacity*2;
    TElem* aux_array = new TElem[this->capacity*2];  // sizeof(telem)*this->capacity
    int index = this->front;
//    aux_array[0]=this->elems[3];///???
//    aux_array[0]=this->elems[0];
//    aux_array[0]=this->elems[1];
//    aux_array[0]=this->elems[2];
//    aux_array[0]=this->elems[3];
//    aux_array[0]=this->elems[4];
    //aux_array[0]=this->elems[5];
    for (i = 0; len--; i++) {
        aux_array[i] = this->elems[index];
        index = (index+1)%(this->capacity);
    }
    delete[] this->elems;

    this->capacity=this->capacity*2;
    this->elems = aux_array;
    this->front = 0;
    this->rear = i-1;
} // Complexity: Theta(n)

int Queue::queueSize() const{
    if(this->front ==-1 && this->rear == -1){
        return 0;
    }
    else{
        if(isFull())
            return this->capacity;

        return (((this->capacity)-(this->front)+(this->rear)+1)%(this->capacity));
    }
} // Complexity: Theta(1)



//void Queue::halfQueueCapacity() {
//    int len = queueSize(), i;
//    if (this->capacity > this->size && len == (this->capacity) / 2) {
//        this->capacity = this->capacity / 2;
//        TElem *aux_array = new TElem[this->capacity];
//        int index = this->front;
//        for (i = 0; i < len; i++) {
//            aux_array[i] = this->elems[index];
//            index = (index + 1) % (this->capacity);
//        }
//
//        delete[] this->elems;
//        //Q->capacity=(Q->capacity)/2;
//        this->elems = aux_array;
//        this->front = 0;
//        this->rear = i - 1;
//    }
//}

