#include "stdafx.h"
#include "ArrayDuplicates.h"


ArrayDuplicates::ArrayDuplicates()
{
}


ArrayDuplicates::~ArrayDuplicates()
{
}

void ArrayDuplicates::FindDuplicateNumbers(int* nums, int size)
{
	printf("\nREMOVING DUPLICATES FROM ARRAY\n");
	int i, j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (nums[i] == nums[j])
			{
				printf("%d\n", nums[j]);
				nums[i] = 0;
				nums[j] = 0;
			}
		}
	}
	printf("\nNEW ARRAY\n");

	for (i = 0; i < size; i++)
		if (nums[i] != 0)
			printf("%d ", nums[i]);
	printf("\n");
}