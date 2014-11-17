//
//  PrintMatches.h
//  
//
//  Created by Drew on 8/10/14.
//
//  Read a file with a grid and print out coordinates greater than 3
//

#include "stdafx.h"

class PrintMatches
{
public:
	PrintMatches(size_t,size_t);
	~PrintMatches();

	void printMatches(const char*);
	void writeToFile(const char*);

	size_t col;
	size_t row;
	int i, j, k;

private:
	int **_newArray;
};