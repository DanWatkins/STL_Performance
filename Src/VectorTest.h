#ifndef _VECTOR_TEST_H
#define _VECTOR_TEST_H

#include "Test.h"
#include <vector>

class VectorTest : public Test
{
private:
	std::vector<int> mData;

	void init(int *start, unsigned length)
	{
		mData.assign(start, start+length);
	}


	void sort()
	{
		std::sort(mData.begin(), mData.end());
	}
};

#endif

