#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)

#define LOAD_FACTOR 0.75
#define INITIAL_SIZE 16
//define a DELELTED_TELEM to mark deleted elements with
#define DELETED_TELEM pair<int,int>(NULL_TVALUE -1, NULL_TVALUE -1)

class MultiMapIterator;

class MultiMap
{
	friend class MultiMapIterator;

private:
	//TODO - Representation
    TElem* elements;
    int capacity;
    int actualSize;


    // computes the loadFactor of the hashTable
    double loadFactor();

    // first hash function
    int normalHash(TKey key) const;

    // Quadratic probing calc function
    int quadraticProbingfunction(int i) const;


    // the final hashing function
    int hashingFunction(TKey key, int i) const;

public:

    vector <TValue> valueBag() const;
    //resizes the hash table, rehashing all its elements
    void resize();

	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//descturctor
	~MultiMap();


};

