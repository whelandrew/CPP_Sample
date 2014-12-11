#include "stdafx.h"
#include "KnuthMorrisPratt.h"

#include <iostream>
#include <vector>
using namespace std;

KnuthMorrisPratt::KnuthMorrisPratt()
{
}


KnuthMorrisPratt::~KnuthMorrisPratt()
{
}

void KnuthMorrisPratt::KMP(string list, string word)
{	
	int wSize = word.size();
	int lSize = list.size();
	for (int i = 0; i < wSize; i++)
		word[i] = toupper(word[i]);
		
	vector<int> t(wSize + 1, -1);
	vector<int> matches;

	printf("\nFINDING \"%s\" LOCATED AT ", word.c_str());

	for (int i = 1; i <= wSize; i++)
	{
		int pos = t[i - 1];
		while (pos != -1 && word[pos] != word[i - 1])
			pos = t[pos];
		
		t[i] = pos + 1;
	}

	int lPos = 0, wPos = 0;
	while (lPos < lSize)
	{
		while (wPos != -1 && (wPos == wSize || word[wPos] != list[lPos]))
			wPos = t[wPos];

		lPos++;
		wPos++;

		if (wPos == wSize)
			matches.push_back(lPos - wSize);
	}

	printf("%d\n", matches);
}