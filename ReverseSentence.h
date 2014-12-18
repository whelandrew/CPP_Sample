//
//  ReverseSentence.h
//  
//
//  Created by Drew on 8/8/14.
//
//  Receiving an array of chars as a sentence, reverse the the order of the words.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

class ReverseSentence
{
public:
	ReverseSentence(char*);
	~ReverseSentence();

	void reverseWords();
	void iToA(int);

	char* newSentence;
private:
};
