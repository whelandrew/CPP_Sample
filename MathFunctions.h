#pragma once
class MathFunctions
{
public:
	MathFunctions(int*, int);
	~MathFunctions();

	void CalculateAverage();
	void PrintOddNumbers();
	void Fibonacci();

private:
	int* numArray;
	int arraySize;
};

