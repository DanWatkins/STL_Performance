#ifndef _TEST_H
#define _TEST_H

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <chrono>
#include <ctime>

class Test
{
private:
	const unsigned mValueCount	= 100000000;
	const unsigned mValueLow	= 0;
	const unsigned mValueHigh	= 5000;

	virtual void init(int *start, unsigned length) = 0;
	virtual void sort() = 0;

public:
	void start()
	{
		std::cout << "Starting test for " << typeid(*this).name() << std::endl;


		int *data = new int[mValueCount];
		std::srand(std::time(NULL));

		for (unsigned n=0; n<mValueCount; ++n)
			data[n] = std::rand() % (mValueHigh+1);

		clock_t initStart = std::clock();
		init(data, mValueCount);
		std::cout << "  -Initialization with " << mValueCount << " values [" << (std::clock()-initStart) / 1000.0 << " seconds]" << std::endl;

		clock_t sortStart = std::clock();
		sort();
		clock_t end = std::clock();
		std::cout << "  -Sorting [" << (end-sortStart) / 1000.0 << " seconds]" << std::endl;

		std::cout << "  -Process complete [" << (end-initStart) / 1000.0 << " seconds total]" << std::endl;
	}
};


#endif

