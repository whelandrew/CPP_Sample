// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GUI.h"

GUI* g;

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{	
	g = new GUI();
	g->MainMenu();
	

	
	
	
	return 0;
}