#pragma once
#include <string>
class Permutation
{
public:
	Permutation();
	~Permutation();

	void CalculateWordPosition(char*);
private:
	void swap(char*, char*);
	void InsertionSort(char*); 
	void BubbleSort(char*);
	void CalcRank(char*,int);

	char* checkWord;
	bool found;
	int total;
};

