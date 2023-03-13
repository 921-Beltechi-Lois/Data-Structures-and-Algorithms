#pragma once
//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -111111

class Stack
{
private:
    //TODO - Representation
    TElem* elems;
    int capacity, size;

    void resize();
    /// checks if the stack is full
    bool isFull() const;
	
public:

	//constructor
	Stack(int capacity =1);

    // copy constructor
    Stack(const Stack& v);

    //assignment operator
    Stack& operator=(const Stack&);
	
	//pushes an element to the top of the Stack
	void push(TElem e);
	
	//returns the element from the top of the Stack
	//throws exception if the stack is empty
	TElem top() const;
	   
	//removes and returns the element from the top of the Stack
	//throws exception if the stack is empty
	TElem pop();
	   
	//checks if the stack is empty
	bool isEmpty() const;
    void printStack(Stack & s);

	//destructor
	~Stack();
};

