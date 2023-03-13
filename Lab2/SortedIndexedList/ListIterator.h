#pragma once
#include "SortedIndexedList.h"
class SortedIndexedList;

//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIndexedList;
    //friend struct DLLNode;
private:
    const SortedIndexedList& list;
    ListIterator(const SortedIndexedList& list);

	//TODO - Representation
    SortedIndexedList::PNode currentElement;

public:
	void first();
	void next();
    void jumpForward(int k);
	bool valid() const;
    TComp getCurrent() const;


//    TComp getCurrentIndex() const; ///
};


