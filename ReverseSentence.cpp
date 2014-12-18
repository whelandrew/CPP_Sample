//  ReverseSentence.cpp
//  
//
//  Created by Krom on 8/8/14.
//
//

#include "stdafx.h"
#include "ReverseSentence.h"
#include <vector>

ReverseSentence::ReverseSentence(char* _sentence = "Turn around bright eyes")
{
	newSentence = _sentence;
}

ReverseSentence::~ReverseSentence()
{
	newSentence = 0;
}

void ReverseSentence::iToA(int num)
{
	std::string numChar="";
	while (num > 0)
	{
		numChar += (char)(num % 10);
		num /= 10;
	} 

	printf("Printing Int as String\n%s\n", numChar.c_str());
}

void ReverseSentence::reverseWords()
{
	printf("ORIGINAL SENTENCE:\n%s\n\nSENTENCE REVERSED:\n", newSentence);
	int index = strlen(newSentence) - 1;
	int hold = 0;
	int last = '\0';

	while (index >= 0)
	{
		while (index >= 0 && newSentence[index] != ' ')
		{
			index--;
		}

		hold = index - 1;
		index++;

		while (newSentence[index] != last)
		{
			printf("%c", newSentence[index]);
			index++;
		}
		last = ' ';
		index = hold;

		if (index > 0)
			printf(" ");
	}
	printf("\n");
}