#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#include <utility>

#define NULL_TELEM -111111;
#define MAXCAP 9999999
typedef int TElem;
class BagIterator;

//struct Node {
//    std::pair<int, int> info;  // Value, Frequency
//    Node* prev;
//    Node* next;
//};
class Bag {

private:
	//TODO - Representation

     TElem* elements;
    int* frequency;  // holds how many elements of this type exists

    int* next;
    int* prev;

    int head;
    int tail;

    int firstEmpty;
    int sizeElems;


	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};