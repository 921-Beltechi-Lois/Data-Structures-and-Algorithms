#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
    this->first();
}

// complexity: tetha(1)
// if the iterator is not valid, throws an exception
TElem MultiMapIterator::getCurrent() const{
    if(!this->valid())
        throw std::exception();
    return this->col.elements[this->index];
}

// complexity: tetha(1)
bool MultiMapIterator::valid() const {
    return this->index < this->col.capacity;
}


//complexity: O(capacity)
//if the iterator is not valid, throws an exception
void MultiMapIterator::next() {
    if(!this->valid())
        throw std::exception();
    this->index++;
    while(this->valid() && this->getCurrent() <= NULL_TELEM)
        this->index++;
}


// sets the iterator to point to the first non-empty element in the hash table
// if the hash table is empty, the iterator becomes invalid
//best case: tetha(1)
//worst case: tetha(capacity)
// avg case: O(capacity)
void MultiMapIterator::first() {
    this->index = 0;                            // < deleted elems are < null_telem
    while(this->valid() && this->getCurrent() <= NULL_TELEM)
        this->index++;
}
