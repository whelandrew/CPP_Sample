//
//  PrintMatches.cpp
//  
//
//  Created by Krom on 8/10/14.
//
//

#include "stdafx.h"
#include "PrintMatches.h"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

PrintMatches::PrintMatches(size_t _col, size_t _row)
{
	col = _col;
	row = _row;
	i = 0;
	j = 0;
	k = 0;
}

PrintMatches::~PrintMatches(){}

void PrintMatches::printMatches(const char* filename)
{
	ifstream file(filename);
	vector<int> numbers;
	int num=0;
	int i, j, k = 0;

	if (file.is_open())
	{
		printf("\nFILE RECEIVED\n");
		string line, final;

		while (getline(file, final))
		{
			line += final;
			col++;
		}

		file.close();

		_newArray = new int *[row];

		for (i = 0; i < row; i++)
			_newArray[i] = new int[col];

		//sort _line in to a in 2d array
		for (j = 0; j<col; j++)
		{
			for (i = 0; i<row; i++)
			{
				char _newChar = line[k];
				_newArray[i][j] = atoi(&_newChar);
				printf("%d", _newArray[i][j]);
				k++;
			}
			printf("\n");
		}
	}
	else
		printf("FILE NOT FOUND\n");
}

void PrintMatches::writeToFile(const char* filename)
{
	printf("\nFILE CREATED:\n%s", filename);
	//write to file
	freopen(filename, "w+",stdout);

	//output results
	for (k = 3; k<6; k++)
	{
		for (j = 0; j<col; j++)
		{
			for (int i = 0; i<row; i++)
			{
				if (_newArray[i][j] == k)
					printf("(%d, %d) ", i, j);
			}
		}
		printf("(%d)\n", k);
	}
	fclose(stdout);
}