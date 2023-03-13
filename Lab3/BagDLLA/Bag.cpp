#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	//TODO - Implementation
    this->head=-1;
    this->tail=-1;    ///
    this->firstEmpty=0;
    this->sizeElems=0;
    this->elements= new TElem[MAXCAP];
    this->frequency = new TElem [MAXCAP];
    this->next=new TElem[MAXCAP];
    this->prev=new TElem[MAXCAP]; ///
}


void Bag::add(TElem elem) {
	//TODO - Implementation
    if(this->isEmpty()){
        this->head=firstEmpty;     // Add head... empty list
        this->tail=firstEmpty;

        this->elements[0]=elem;
        this->frequency[0] =1;
        this->next[0]=-1;
        this->prev[0]=-1;
        this->sizeElems++;
        this->firstEmpty++;

    }
    else{
        int current = this->head;
        while (current != -1)                   /// Add to already existing
        {
            if (elements[current] == elem)
            {
                frequency[current]++;
                this->sizeElems++;
                return;
            }
            current = next[current];
        }

        int current_node = this->head;
        while(this->next[current_node]!= -1){  // tail ADD TO END
            current_node=this->next[current_node];
        }
        int prev_node = current_node; // there is another one coming to the end

        this->firstEmpty = prev_node+1; // position in which to add  // first empty

        this->next[firstEmpty-1]= firstEmpty; // Last elem points to the new one's first empty pos

        this->elements[firstEmpty] = elem;
        this->frequency[firstEmpty]=1;
        this->next[firstEmpty] = -1;
        this->prev[firstEmpty] = prev_node;

        this->tail = firstEmpty;
        this->sizeElems++;
        this->firstEmpty++;
    }

}



bool Bag::remove(TElem elem) {
	//TODO - Implementation
	bool deleted=false;
    int current = this->head;

    while (current != -1 && elements[current] != elem)
    {
        current = next[current];
    }
    if(current!=-1){
        deleted=true;
        this->sizeElems--;
        this->frequency[current]--;

        if(this->frequency[current]==0){
            if(current==this->head){
                if(this->next[current]!=-1) { // Delete head, there are more than 1 elems in the array
                    //int prev_elem = current;
                    current=this->next[current]; // Next index will be the new head
                    this->head=current;
                    this->prev[current] = -1; // second element is the new head, so prev of the new head =-1
                    ///this->elements[current] = this->elements[sizeElems-1];
                }
                else{
                    this->head=-1;
                    this->tail=-1;
                }
            }
            else if(current==this->tail){    // Delete last Elem
                int prev_tail_elem=this->prev[current];  // Previous of Tail
                this->tail=prev_tail_elem;
                this->next[prev_tail_elem] = -1;
                //this->next[current] = -1; // asta nu e necesar.... E nextu tailului
                this->prev[current] = -1;
            }
            else{                                   // Delete in middle!!!!!
                int prev_elem= this->prev[current];
                int next_elem = this->next[current];
                this->next[prev_elem] = next_elem;
                this->prev[next_elem] = prev_elem;
                this->next[current] = -1; // ?/
                this->prev[current] = -1; // ???
                ///this->elements[current] = this->elements[this->sizeElems-1];
            }
            this->firstEmpty--;
        }
    }
    return deleted;
}


bool Bag::search(TElem elem) const {
	//TODO - Implementation
    int current=this->head;
    while(current!=-1){
        if(elem==this->elements[current])
            return true;
        current=this->next[current];
    }
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	int current=this->head;
    while(current!=-1){
        if(elem==this->elements[current])
            return this->frequency[current];
        current=this->next[current];
    }
    return 0;
}


int Bag::size() const {
	return this->sizeElems;

//    int sum = 0, current = this->head;
//    while (current != -1)
//    {
//        sum+=this->frequency[current];
//        current = this->next[current];
//    }
//    return sum;
}


bool Bag::isEmpty() const {
	return this->head==-1;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
    delete[] this->elements;
    delete[] this->frequency;
    delete[] this->next;
    delete[] this->prev;
}

