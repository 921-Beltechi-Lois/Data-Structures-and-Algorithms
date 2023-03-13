#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	//TODO - Implementation
    this->currentIndex=this->bag.head;
    this->currentFreq = 0;
}

void BagIterator::first() {
	this->currentIndex=this->bag.head;
    this->currentFreq=0;
}


void BagIterator::next() {
	//TODO - Implementation
    if (!this->valid()) throw exception();

    this->currentFreq++;
    if (this->currentFreq == this->bag.frequency[this->currentIndex])
    {
        this->currentIndex = this->bag.next[this->currentIndex];
        this->currentFreq = 0;
    }
}


bool BagIterator::valid() const {
	//TODO - Implementation
    if (this->currentIndex == -1) return false;
    return true;
}



TElem BagIterator::getCurrent() const
{
	//TODO - Implementation
    if (!this->valid()) throw exception();
    return this->bag.elements[this->currentIndex];
}
