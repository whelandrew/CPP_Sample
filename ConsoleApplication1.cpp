// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrintMatches.h"
#include "ReverseSentence.h"
#include <cstdio>

PrintMatches* match;
ReverseSentence* sen;

char* fileLocation = "Text.txt";
char* newFileName = "coordinates.txt";

int _tmain(int argc, _TCHAR* argv[])
{	
	sen = new ReverseSentence("Turn around, bright eyes");
	sen->reverseWords();

	match = new PrintMatches(0, 11);
	match->printMatches(fileLocation);
	match->writeToFile(newFileName);

	getchar();
	return 0;
}

