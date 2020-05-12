/*
filename: cryptography.cpp
details: program shows encrypt and decrypt of the file when pass related parameters
author:B.Rajyalakshmi
date:12/05/2020
*/

#include <string.h>
#include<stack>
#include<iostream>
#include<fstream>
using namespace std; 
// reverses individual words of a string 
void encript(string str) 
{ 
   // cout<<str;
    stack<char>st;
    int length=str.length();
    ofstream outfile("enc.txt",ios::out);
    // Traverse given string and push all characters 
    // to stack until we see a space. 
    for (int i=0;i<length;++i) 
	{ 
        if(str[i]!= ' ') 
            st.push(str[i]); 
        // When we see a space, we print contents 
        // of stack. 
        else {
            while(st.empty()==false)
			{ 
                outfile<<st.top();
                st.pop();
            } 
                outfile<<'*';
        }
    }
     while(st.empty()==false)
	 { 
        outfile<<st.top(); 
        st.pop();
	}
    outfile.close();
} 
void decript(string strl) 
{ 
   // cout<<str;
    stack<char>st;
    int length=strl.length();
    ofstream outfile("decript.txt",ios::out);
    // Traverse given string and push all characters 
    // to stack until we see a star. 
    for (int i=0;i<length;++i) 
	{ 
        if(strl[i]!= '*') 
            st.push(strl[i]); 
        // When we see a star, we print contents 
        // of stack. 
        else {
            while(st.empty()==false)
			{ 
                outfile<<st.top();
                st.pop();
            } 
                outfile<<' ';
        }
    }
     while(st.empty()==false)
	 { 
        outfile<<st.top(); 
        st.pop();
	}
    outfile.close();
} 
// Driver program to test function 
int main(int argc,char* argv[])
 {
    if((argc==2)&&strcmp(argv[1],"-h")==0)    //created a help command
    {
        cout<<"-d||-e give in parameters"<<endl;
    }
    else if((argc>1)&&strcmp(argv[1],"-e")==0)    //encript calling
    {
    string str;
    ifstream reading("note.txt",ios::in);
    getline(reading,str);
    reading.close();
    encript(str);
   }
    else if((argc>1)&&strcmp(argv[1],"-d")==0)    //decript calling
    {
	string strl;
    ifstream readings("enc.txt",ios::in);
    getline(readings,strl);
    readings.close();
    decript(strl);
    return 0; 
}}
