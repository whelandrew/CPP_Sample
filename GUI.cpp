#include <iostream>
#include "stdafx.h"

#include "GUI.h"

extern int MATHARRAY[] = { 1, 6, 3, 3, 4, 8, 5, 2, 7, 5 };
extern string STRINGLIST = "NOISTEUQ";
extern char* PERMWORD = "something";
extern char* FILELOCATION = "Text.txt";
extern char* FILENAME = "coordinates.txt";


GUI::GUI()
{
	kmp = new KnuthMorrisPratt();
	dup = new ArrayDuplicates();
	match = new PrintMatches(0,11);
	sen = new ReverseSentence("Turn around, bright eyes");
	match = new PrintMatches(0, 11);
	perm = new Permutation();
	math = new MathFunctions(MATHARRAY, 10);

	MATHARRAY[0] = 1;
	MATHARRAY[1] = 6;
	MATHARRAY[2] = 3;
	MATHARRAY[3] = 3;
	MATHARRAY[4] = 8;
	MATHARRAY[5] = 4;
	MATHARRAY[6] = 5;
	MATHARRAY[7] = 2;
	MATHARRAY[8] = 7;
	MATHARRAY[9] = 5;
}


GUI::~GUI()
{
	delete kmp;
	delete match;
	delete dup;
	delete sen;
	delete perm;
	delete math;
}

void GUI::MathProccess(int selection)
{
	printf("\nSelect a Math Function\n");
	printf(" 1 - Print Odd Numers\n");
	printf(" 2 - Calculate Average\n");
	printf(" 3 - Fibonacci Sequence\n");

	printf("Enter number: ");
	cin >> selection;
	getchar();

	switch (selection)
	{
	case 1:
		math->PrintOddNumbers();
		Next();
		break;
	case 2:
		math->CalculateAverage();
		Next();
		break;
	case 3:
		math->Fibonacci();
		Next();
		break;
	}
}

void GUI::Next()
{
	printf("\nPress Enter to Continue");
	getchar();
	MainMenu();
}

void GUI::RunFunction(int selection)
{
	string word = "";
	switch (selection)
	{
	case 0:
		break;
	case 1:
		printf("\nENTER A STRING TO SEARCH FOR IN \"%s\" : ", STRINGLIST.c_str());
		cin >> word;
		getchar();
		printf("\n");
		kmp->KMP(STRINGLIST, word);
		Next();
		break;
	case 2:
		SortSelector();
		break;
	case 3:
		MathProccess(selection);
		break;
	case 4:
		dup->FindDuplicateNumbers(MATHARRAY, 10);
		Next();
		break;
	case 5:
		sen->reverseWords();
		Next();
		break;
	case 6:
		match->printMatches(FILELOCATION);
		match->writeToFile(FILENAME);
		Next();
		break;
	case 7:
		perm->CalculateWordPosition(PERMWORD);
		Next();
		break;
	case 8:
		sen->iToA(123);
		Next();
		break;
	default:
		printf("You did not enter a valid selection\n");
		MainMenu();
		break;
	}
}

void GUI::SortSelector()
{
	int sortNums[20] = { 1, 5, 7, 8, 19, 33, 4, 90, 100, 84, 23, 2, 4, 6, 0, 1, 5, 18, 9, 432 };
	sorts* sort = new sorts(sortNums, 20);
	int selection = 0;
	printf("\nSelect a Sorting Algorithm\n");
	printf(" 1 - Bubble Sort\n");
	printf(" 2 - Exchance Sort\n");
	printf(" 3 - Selection Sort\n");
	printf(" 4 - Insertion Sort\n");

	printf("Enter number: ");
	cin >> selection;
	getchar();

	switch (selection)
	{
	case 1:
		sort->BubbleSort();
		getchar();
		break;
	case 2:
		sort->ExchangeSort();
		getchar();
		break;
	case 3:
		sort->SelectionSort();
		getchar();
		break;
	case 4:
		sort->InsertionSort();
		getchar();
		break;
	default:
		printf("You did not enter a valid selection\n");
		getchar();
		SortSelector();
		break;
	}
	MainMenu();
}

void GUI::MainMenu()
{
	printf("\nSELECT A FUNCTION");
	printf("\n 1 - Knuth Morris Pratt Algorithm");
	printf("\n 2 - Sorting Algorithms");
	printf("\n 3 - Math Functions");
	printf("\n 4 - Array Duplicates");
	printf("\n 5 - Reverse Sentence");
	printf("\n 6 - Print Matches");
	printf("\n 7 - Permutation");
	printf("\n 8 - iToA");

	printf("\n 0 - Exit");

	int selection = 0;
	printf("\nEnter number: ");
	cin >> selection;
	getchar();
	RunFunction(selection);
}