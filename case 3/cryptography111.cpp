/*
filename: cryptography111.cpp
details: program shows encrypt and decrypt of the file when pass related parameters
author:B.Rajyalakshmi
date:12/05/2020
*/
#include<string.h>
#include<stack>
#include<iostream>
#include<fstream>
using namespace std;   
/*Function Name :encrypt
  Parameters    :char*
  Return Type   :no return type
  Usage         :to reverse data of input file */
void encript(char* infile,string key) 
{ 	
	ifstream reading(infile,ios::in);
	string words;
    stack<char>rev;
    ofstream outfile("enc.txt",ios::out);
    outfile<<key<<endl;
     while(getline(reading,words))
    {
    	cout<<words<<endl;
    	int length=words.length();
    // Traverse given string and push all characters 
    // to stack until we see a space. 
    for (int istart=0;istart<length;++istart) 
	{ 
        if(words[istart]!= ' ') 
            rev.push(words[istart]); 
        // When we see a space, we print contents 
        // of stack. 
        else {
            while(rev.empty()==false)
			{ 
                outfile<<rev.top();
                rev.pop();
            } 
                outfile<<'*';
        }
    }
     while(rev.empty()==false)
	 { 
        outfile<<rev.top(); 
        rev.pop();
	}
	outfile<<endl;
	}
    outfile.close();
    reading.close();
} 
/*Function Name :decrypt
  Parameters    :char*
  Return Type   :no return type
  Usage         :to reverse data of  encripted file */
void decript(char* infile,string key) 
{ 
	string sentance;
	ifstream reading(infile,ios::in);
	getline(reading,sentance);
	// comparing the security keyword while entering into the decript
	if(sentance==key)
	{
    stack<char>Rev; 
    ofstream outfile("decript.txt",ios::out);
    // Traverse given string and push all characters 
    // to stack until we see a star.
    while(getline(reading,sentance))
   {
   for (int istart=0;istart< sentance.length();++istart) 
   { 
        if (sentance[istart] != '*') 
            Rev.push(sentance[istart]); 
        // When we see a star, we print contents 
        // of stack. 
        else { 
            while(Rev.empty()==false) 
			{ 
                cout<<Rev.top(); 
                outfile<<Rev.top();
                Rev.pop(); 
            } 
            cout <<" ";
			outfile<<" "; 
        } 
    } 
    // Since there may not be space after 
    // last word. 
    while(Rev.empty()==false) 
	{ 
        cout<<Rev.top(); 
        outfile<<Rev.top();
        Rev.pop(); 
    }
	outfile<<endl;
    cout<<endl;
}
outfile.close();
reading.close();
}
else
	cout<<"key doesn't match"<<endl;
}
 
 int main(int argc,char* argv[])
 {
 	//created a help command
    if((argc==2)&&strcmp(argv[1],"-h")==0)    
    {
        cout<<"-d||-e -f note.txt key"<<endl;
    }
    //encript calling
    else if((argc>1)&&strcmp(argv[1],"-e")==0)    
    {
   	   encript(argv[3],argv[5]);
    }
    //decript calling
     else if((argc>1)&&strcmp(argv[1],"-d")==0)    
    {

	decript(argv[3],argv[5]);
}
    return 0; 
}
