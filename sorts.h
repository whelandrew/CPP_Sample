#pragma once
class sorts
{
public:
	sorts(int*, int);
	~sorts();

	void BubbleSort();
	void ExchangeSort();
	void SelectionSort();
	void InsertionSort();
private:
	int* nums;
	int size;

	void PrintArray();
};

