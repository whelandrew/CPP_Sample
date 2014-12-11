#include "stdafx.h"
#include "sorts.h"


sorts::sorts(int* _nums, int _size)
{
	nums = _nums;
	size = _size;
}

sorts::~sorts()
{
	delete[] nums;
}

void sorts::PrintArray()
{
	for (int i = 0; i < size; i++)
		printf(" %d", nums[i]);
}

//	Splits an array into two sub-arrays. 
//	The first sub-array (such as the cards in your hand) is sorted and increases in size as 
//	the sort continues. 
//	The second sub-array (such as the cards to be picked up) is unsorted, 
//	contains all the elements to yet be inserted into the first sub-array, and decreases in 
//	size as the sort continues.
void sorts::InsertionSort()
{
	int i = 0, j = 0;
	int key = 0;

	printf("\nINSERT SORT\nOriginal\n");
	PrintArray();

	for (j = 1; j < size; j++) // start with second element to begin comparison
	{
		key = nums[j];

		printf("\nValues in Sub-Array, Pass #%d\n",j);
		
		for (i = j-1; i >= 0 && nums[i] < key; i--) // shift smaller values up
		{ 
			nums[i + 1] = nums[i];
			printf(" %d", nums[i]);
		}

		nums[i + 1] = key;
	}
	printf("\nFinal Sort\n");
	PrintArray();
}

//Unsorted element with the smallest (or largest) value is moved to its proper position in the array
void sorts::SelectionSort()
{
	int i = 0, j = 0;
	int next = 0;
	int curr = 0; // current element being checked

	printf("\nSELECTION SORT\nOriginal\n");
	PrintArray();

	for (i = size; i > 0; i--)
	{
		printf("\nResults of Pass #%d\n", (size-i)+1);
		curr = 0;
		for (j = 1; j <= i; j++) // locate smallest between positions 1 and i
		{
			if (nums[j] < nums[curr])
				curr = j;
			//printf(" %d", nums[j]);		
		}

		next = nums[curr];
		nums[curr] = nums[i];
		nums[i] = next;
		PrintArray();
		printf("\n");
	}
}

//Compares the first element with each following element of the array
void sorts::ExchangeSort()
{
	int i = 0, j = 0;
	int hold = 0; // to contain the found number being swapped

	printf("\nEXCHANGE SORT\nOriginal\n");
	PrintArray();

	for (i = 0; i < size; i++)
	{
		printf("\nResults of Pass #%d\n", i + 1);
		for (j = 0; j < size; j++)
		{
			if (nums[i] < nums[j])
			{
				hold = nums[i];
				nums[i] = nums[j];
				nums[j] = hold;
			}
			printf(" %d", nums[j]);
		}
		printf("\n");
	}

	printf("\nEXCHANGE SORT FINISHED\n");
}

//Repeatedly compares adjacent elements of an array
void sorts::BubbleSort()
{
	int i = 0, j = 0;
	int hold = 0; // to contain the found number being swapped
	bool swapped = true;

	printf("\nBUBBLE SORT\nOriginal\n");
	PrintArray();

	for (i = 0; i < size && swapped; i++)
	{
		printf("\nResults of Pass #%d\n", i+1);
		swapped = false;
		for (j = 0; j < size; j++)
		{
			if (nums[j + 1] > nums[j])
			{
				hold = nums[j]; //checking the element after the current
				nums[j] = nums[j + 1]; //swap the elements
				nums[j + 1] = hold;
				swapped = true;
			}
			printf(" %d", nums[j]);
		}
		printf("\n");
	}

	printf("\nBUBBLE SORT FINISHED\n");
}