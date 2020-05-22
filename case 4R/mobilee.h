/*
filename : mobilekeypad.cpp
details  : number of possible ways to form words in the moblile key pad from 2 to 9 numbers 
author   :B.Rajyalakshmi
date     :15/05/2020
*/
#include <bits/stdc++.h>
using namespace std;
string cDataArray[10] = {"", "", "ABC", "DEF", "GHI", "JKL","MNO", "PQRS", "TUV", "WXYZ"};
class keypad
{
	public:
		keypad()
		void  Recursion(string cNum,int icurrent_length,string cOutput);
		void PrintStrings(string cNum);
		~keypad()
}
