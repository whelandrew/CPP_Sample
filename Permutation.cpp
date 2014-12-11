#include "stdafx.h"
#include "Permutation.h"
#include <stdio.h>


Permutation::Permutation()
{
}


Permutation::~Permutation()
{
	free(checkWord);
}

void Permutation::swap(char* first, char* second)
{
	char hold = *first;
	*first = *second;
	*second = hold;
}

void Permutation::BubbleSort(char* word)
{
	int i = 0, j = 0;
	int hold = 0; // to contain the found number being swapped
	bool swapped = true;
	int size = strlen(word);

	for (i = 0; i < size && swapped; i++)
	{
		swapped = false;
		for (j = 0; j < size; j++)
		{
			if (word[j + 1] > word[j])
			{
				hold = word[j]; //checking the element after the current
				word[j] = word[j + 1]; //swap the elements
				word[j + 1] = hold;
				swapped = true;
			}
		}
	}
}

void Permutation::CalculateWordPosition(char* word)
{
	checkWord = new char[strlen(word) + 1];
	strcpy(checkWord, word);

	InsertionSort(word);
	CalcRank(word, 0);
}


void Permutation::InsertionSort(char* word)
{
	int i = 0, j = 0;
	int key = 0;
	int size = strlen(word);

	for (j = 1; j < size; j++) // start with second element to begin comparison
	{
		key = word[j];

		for (i = j - 1; i >= 0 && word[i] < key; i--) // shift smaller values up
		{
			word[i + 1] = word[i];
		}

		word[i + 1] = key;
		printf(" %s\n", word);
	}

	printf("\nSORT COMPLETE\n");
	CalcRank(word, 0);
}

void Permutation::CalcRank(char* word, int j)
{
	int i = 0;
	int size = strlen(word);
	char dups[256] = "";

	if (!strcmp(word,checkWord) && !found)
	{
		printf("\n%s %d\n", word,total);
		found = true;
	}
	else
	{
		for (i = j; i < size; i++)
		{
			if (!dups[*(word + i)])
			{
				swap(&word[j], &word[i]);
				CalcRank(word, j + 1);
				swap(&word[j], &word[i]);
				dups[*(word + i)] = 1;
			}
		}
	}
}