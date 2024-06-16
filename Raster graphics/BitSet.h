#pragma once
#include <iostream>

class BitSet
{
private:
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N = 0;
	const unsigned elementsInBucket = sizeof(uint8_t) * 8;

	void free();
	void copyFrom(const BitSet& other);

	unsigned getBucketIndex(unsigned num) const;

public:
	BitSet(unsigned n); 

	BitSet(const BitSet& other);
	BitSet& operator=(const BitSet& other);
	~BitSet();

	void add(unsigned num);
	void remove(unsigned num);
	bool contains(unsigned num) const;
	void print() const;
	friend BitSet UnionOfSets(const BitSet& lhs, const BitSet& rhs);
	friend BitSet IntersectionOfSets(const BitSet& lhs, const BitSet& rhs);

};

