#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
    this->capacity = INITIAL_SIZE;
    this->actualSize = 0;

    //allocate space for the array
    this->elements = new TElem[this->capacity];

    //initialize array with NULL_TELEM
    for(int i = 0; i < this->capacity; i++)
        this->elements[i] = NULL_TELEM;
}


// complexity: best case: tetha(1) - the hashing algorithm finds space on the first position checked
//             worst case: depends on the load factor we choose and the distribution of the hashed positions. Tetha(n)
//              average complexity: O(n)
void MultiMap::add(TKey c, TValue v) {
    // if the load factor reaches a given value, we resize and rehash
    if(this->loadFactor() >= LOAD_FACTOR)
        this->resize();
    int i, position;
    // with i we will generate positions for the element (i - probe number)
    i = 0;
    position = this->hashingFunction(c, i);
    // we find first available position - deleted element or null element
    // our hashing function returns a permutation of the indexes of the array, so it is sure it'll find an empty
    // position.                                       // == null when empty space is found
    while(i < this->capacity && this->elements[position] > NULL_TELEM) {
        i++;
        position = this->hashingFunction(c, i);
    }
    this->elements[position] = TElem(c,v);
    this->actualSize++;
}


bool MultiMap::remove(TKey c, TValue v) {
    int i, position;
    i = 0;
    position = this->hashingFunction(c, i);
    // we hash the key until we find a NULL_TELEM. If we find it, means that the hasing didn't get that far, so
    // we don't need to check further.
    while(i < this->capacity && this->elements[position] != NULL_TELEM) {
        if(this->elements[position] == TElem(c, v))
        {
            // mark the element as deleted
            this->elements[position] = DELETED_TELEM;
            this->actualSize--;
            return true;
        }
        i++;
        position = this->hashingFunction(c, i);
    }
    return  false;
}


vector<TValue> MultiMap::search(TKey c) const {
    vector<TValue> elementsMatchingKey {};
    int i, position;
    i = 0;
    position = this->hashingFunction(c, i);
    // if we get to NULL_TELEM, means hashing didn't get that far, so we don't have to look further
    while(i < this->capacity && this->elements[position] != NULL_TELEM) {
        if(this->elements[position].first == c)
            elementsMatchingKey.push_back(this->elements[position].second);
        i++;
        position = this->hashingFunction(c, i);
    }
    return elementsMatchingKey;
}


// complexity: tetha(1)
int MultiMap::size() const {
    return this->actualSize;
}

// complexity: tetha(1)
bool MultiMap::isEmpty() const {
    return this->actualSize == 0;
}

// complexity: O(capacity)
MultiMapIterator MultiMap::iterator() const{
	return MultiMapIterator(*this);
}

// complexity: tetha(1)
MultiMap::~MultiMap() {
    delete [] this->elements;
}

// complexity: tetha(1)
int MultiMap::normalHash(TKey key) const{
    return abs(key) % this->capacity; //  H(k) = key/m  n
}

//Quadratic Probing, c1,c2=0.5=1/2
int MultiMap::quadraticProbingfunction(int i) const {
    return (i+i*i)/2;
}

// complexity: tetha(1)
int MultiMap::hashingFunction(TKey key, int i) const{
    long long result = ((long long) this->normalHash(key) + (long long) this->quadraticProbingfunction(i)) % (long long) this->capacity;
    return (int) result;
}

// resizes the hash table to one of at least double the size, whose capacity is a prime number
// time complexity: O(newCapacity + oldCapacity * addComplexity)
// space complexity: the dimension of the array at least doubles.
void MultiMap::resize() {
    /// Double capacity, always one of power 2
    // compute the new capacity - double the old one
    int newCapacity = this->capacity * 2;
    // save the old array
    TElem* oldArray = this->elements;
    // create a new array
    this->elements = new TElem[newCapacity];

    // set null telem on every position in the new array
    for(int i=0; i< newCapacity; i++)
        this->elements[i] = NULL_TELEM;

    int oldCapacity = this->capacity;
    this->capacity = newCapacity;
    // set the old size to 0, because we will rehash
    this->actualSize = 0;
    // add back the old elements
    for(int i=0; i< oldCapacity; i++)
        if(oldArray[i] > NULL_TELEM)
            this->add(oldArray[i].first, oldArray[i].second);
    delete [] oldArray;
}

// computes the load factor of the hash table:
// complexity: tetha(1)
double MultiMap::loadFactor() {
    // n   /  m
    return (double) this->actualSize / (double) this->capacity;
}

vector<TValue> MultiMap::valueBag() const {
    vector<TValue> allElements {};
    int i, position=0;
    i = 0;
    //position = this->hashingFunction(c, i);
    int c=0;
    int totalLen=this->actualSize;
    // if we get to NULL_TELEM, means hashing didn't get that far, so we don't have to look further
    while(i < this->actualSize && this->elements[i] != NULL_TELEM) {
        allElements.push_back(this->elements[i].second);
        i++;
        //position = this->hashingFunction(c, i);
    }
    return allElements;
}


