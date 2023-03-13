#include "SortedBagIterator.h"
#include <exception>
#include <stack> 
#include <fstream>

#define emptyVal INT_MIN

// Thetha(n)
SortedBagIterator::SortedBagIterator(const SortedBag & c) : c{ c }
{
	this->current = this->c.root;
	this->currentAmount = 0;
	if (current != -1)
	{
		while (current != -1)
		{
			this->inorderParse.push(current);
			this->current = this->c.elements[current].left;
		}
		this->current = this->inorderParse.top();
		this->inorderParse.pop();

	}
}

// Thetha(n)
void SortedBagIterator::first()
{
	this->current = this->c.root;
	this->currentAmount = 0;
	if (current != -1)
	{
		while (current != -1)
		{
			this->inorderParse.push(current);
			this->current = this->c.elements[current].left;
		}
		this->current = this->inorderParse.top();
		this->inorderParse.pop();
	}

}
// Thetha(1)
void SortedBagIterator::next()
{
	if (this->valid())
	{
		if (this->currentAmount < this->c.elements[this->current].info.second-1)
		{
			this->currentAmount++;
		}
		else
		{
			this->current = this->c.elements[this->current].right;
			this->currentAmount = 0;
			while (current != -1)
			{
				this->inorderParse.push(current);
				this->current = this->c.elements[current].left;
			}
			if (!inorderParse.empty())
			{
				this->current = this->inorderParse.top();
				this->inorderParse.pop();
			}
		}

	}
	else
		throw std::exception();
}
// thetha(1)
bool SortedBagIterator::valid() const
{
	return current != -1;
}
// Thetha(1)
TComp SortedBagIterator::getCurrent() const
{
	if (this->valid())
	{
		return this->c.elements[current].info.first;
	}
	else
		throw std::exception();
}
