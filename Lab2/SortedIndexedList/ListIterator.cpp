#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	//TODO - Implementation
    currentElement = list.head;
} // Theta(1)

void ListIterator::first(){
	//TODO - Implementation
    currentElement = list.head;
} // Theta(1)

void ListIterator::next(){
	//TODO - Implementation
    if ( currentElement == nullptr) throw exception();
    currentElement= currentElement->next;
} // Theta(1)

bool ListIterator::valid() const{
	//TODO - Implementation
	//return false;
    return currentElement != nullptr;
} // Theta(1)

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
    if ( currentElement == nullptr) throw exception();
    return currentElement->info;
	//return NULL_TCOMP;
} // Theta(1)

void ListIterator::jumpForward(int k) {
    if ( currentElement == nullptr || k<=0) throw exception();
    while(k!=0){
        currentElement=currentElement->next;
        k--;
        if(currentElement== nullptr){
            std::cout<<"Iterated given k number is too large! Could not iterate...\n";
            throw exception();
        }
    }
} // Theta(k)

//TComp ListIterator::getCurrentIndex() const{
//    //TODO - Implementation
//    if ( currentElement == nullptr) throw exception();
//    return currentElement->current_index;
//    //return NULL_TCOMP;
//}


