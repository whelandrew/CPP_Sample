#pragma once
#include <string>

#include "KnuthMorrisPratt.h"
#include "PrintMatches.h"
#include "ReverseSentence.h"
#include "ArrayDuplicates.h"
#include "sorts.h"
#include "Permutation.h"
#include "MathFunctions.h"

using namespace std;

class GUI
{
private:
	void SortSelector();
	void MathProccess(int);
	void RunFunction(int);
	void Next();

	KnuthMorrisPratt* kmp;
	PrintMatches* match;
	ReverseSentence* sen;
	ArrayDuplicates* dup;
	Permutation* perm;
	MathFunctions* math;
public:
	GUI();
	~GUI();

	void MainMenu();
};

