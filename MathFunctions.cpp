#include "stdafx.h"
#include "MathFunctions.h"

MathFunctions::MathFunctions(int* nums, int size)
{
	numArray = nums;
	arraySize = size;
}


MathFunctions::~MathFunctions()
{
	delete [] numArray;
	arraySize = NULL;
}

void MathFunctions::CalculateAverage()
{
	int i = 0;
	int total = 0;
	int average = 0;

	for (i = 0; i < arraySize; i++)
	{
		total +=numArray[i];
		average = total / arraySize;
	}

	printf("\nThe average of the array is %d\n", average);
}

void MathFunctions::PrintOddNumbers()
{
	printf("\nPrinting the Odd Numbers\n");
	int i = 0;

	for (i = 0; i < arraySize; i++)
	{
		if (numArray[i] % 2 == 1)
			printf("%d ", numArray[i]);
	}
	printf("\n");
}

void MathFunctions::Fibonacci()
{
	printf("\nFibonnaci Sequence\n");

	int next = 0;
	int first = 0;
	int second = 1;
	int i = 0;

	for (i = 0; i < arraySize; i++)
	{
		if (numArray[i] <= 1)
		{
			next = numArray[i];
		}
		else
		{
			next = first + second;
			first = second;
			second = next;
		}

		printf("%d ", next);
	}
	printf("\n");
}