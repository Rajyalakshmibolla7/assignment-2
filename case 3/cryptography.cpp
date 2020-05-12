/*
filename: cryptography.cpp
details: program shows encrypt and decrypt of the file when pass related parameters
author:B.Rajyalakshmi
date:12/05/2020
*/
#include<string.h>
#include<stack>
#include<iostream>
#include<fstream>
using namespace std;   
// reverses individual words of a string 
void encript(string str,string key) 
{ 
   // cout<<str;
    stack<char>st;
    int length=str.length();
    ofstream outfile("enc.txt",ios::out);
    outfile<<key<<endl;
    
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
    stack<char>stl; 
    int length=strl.length();
    ofstream outfile("decript.txt",ios::out);
    // Traverse given string and push all characters 
    // to stack until we see a star.
    for (int i = 0; i < strl.length(); ++i) { 
        if (strl[i] != '*') 
            stl.push(strl[i]); 
        // When we see a star, we print contents 
        // of stack. 
        else { 
            while(stl.empty()==false) 
			{ 
                cout<<stl.top(); 
                outfile<<stl.top();
                stl.pop(); 
            } 
            cout <<" ";
			outfile<<" "; 
        } 
    } 
    // Since there may not be space after 
    // last word. 
    while(stl.empty()==false) 
	{ 
        cout<<stl.top(); 
        outfile<<stl.top();
        stl.pop(); 
    } 
outfile.close();
}
 
// Driver program to test function 
 int main(int argc,char* argv[])
 {
    if((argc==2)&&strcmp(argv[1],"-h")==0)    //created a help command
    {
        cout<<"-d||-e -f note.txt -k key"<<endl;
    }
    else if((argc>1)&&strcmp(argv[1],"-e")==0)    //encript calling
    {
    string str;
    ifstream reading(argv[3], ios::in);
    getline(reading,str);
    reading.close();
    encript(str,argv[5]);
    }
     else if((argc>1)&&strcmp(argv[1],"-d")==0)    //decript calling
    {
	string strl;
	ifstream readings(argv[3],ios::in);
	getline(readings,strl);
	//string strls;
   //getline(readings,strls); 
   // cout<<strl<<"\n";
	readings.close();
	decript(strl);
    return 0; 
}}
