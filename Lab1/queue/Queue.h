#pragma once
#include <vector>
using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

class Queue
{
private:
	//TODO - Representation
    TElem* elems;
    int capacity, size, front, rear;

    void resize();
    /// checks if the queue is full
    bool isFull() const;
    int queueSize() const;
    //void halfQueueCapacity();

public:
    //constructor
	Queue(int capacity=1);

    // copy constructor
    Queue(const Queue& v);

    //assignment operator
    Queue& operator=(const Queue&);

	//pushes an element to the end of the queue
	void push(TElem e);

	//returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem top() const;

	//removes and returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem pop();

	//checks if the queue is empty
	bool isEmpty() const;

	// destructor
	~Queue();
};
