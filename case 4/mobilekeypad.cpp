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
//recursion to print all possible
public :void  Recursion(string cNum,int icurrent_length,string cOutput)
{
    int istart;
    if(icurrent_length == cNum.length())
    {
        cout<<cOutput<<",";
        return;
    }
    int iDigit=cNum[icurrent_length]-'0';
    //loop for all charcters according to given digits
    for(istart=0;istart<cDataArray[iDigit].length();istart++)
    {
        cOutput+=cDataArray[iDigit][istart];
        Recursion(cNum,icurrent_length+1,cOutput);
       // output.clear
       cOutput.pop_back();
    }
}
//call recurstion in this function
public:void PrintStrings(string cNum)
{
    string cOutput;
    Recursion(cNum,0,cOutput);
}
};
int main(int argc,char* argv[])
 {
 	
 	//created a help command
    if((argc==2)&&strcmp(argv[1],"-h")==0)    
    {
        cout<<"program shows number of possible ways of mobile key borad from 2 to 9"<<endl;
    }
    else
    {
     keypad k;
     cout<<"enter  mobile keys"<<endl;
     string cNumber;
     cin>>cNumber;
    //int string_length = si
    sizeof(string)/sizeof(string[0]);
    k.PrintStrings(cNumber);
    return 0;
}}
