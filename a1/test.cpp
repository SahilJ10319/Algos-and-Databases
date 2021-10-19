#include "Sequence.h"

void basicTest()
{
	Sequence sq1;
	double numbers[] = { 1.1,2.2,3.3 };
	int n = 3;
 
	sq1.insert(3.14);
	sq1.insert(numbers, n);
 
	int pies = sq1.find(3.14);
	int sqSize = sq1.size();
	double sqSum = sq1.sum();
	double sqMean = sq1.mean();
	double sqMedian = sq1.median();
	double sqStddev = sq1.stddev();
 
	Sequence sq2(sq1);
	Sequence sq3 = sq2.concatenate(sq1);
 
	std::cout << "end basic test" << std::endl;
}

void test2() 
{
	Sequence sq1;
	double numbers[] = {1, 1, 1};
	int n = 3;

	sq1.insert(1);
	sq1.insert(numbers, n);

	int pies = sq1.find(1);
	int sqSize = sq1.size();
	double sqSum = sq1.sum();
	double sqMean = sq1.mean();
	double sqMedian = sq1.median();
	double sqStddev = sq1.stddev();

	Sequence sq2(sq1);
	Sequence sq3 = sq2.concatenate(sq1);

	std::cout << sqSum << std::endl;


}

int main()
{
	basicTest();
	test2();
}