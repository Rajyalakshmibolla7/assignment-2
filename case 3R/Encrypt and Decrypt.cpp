/*
filename:Encrypt and Decrypt.cpp
details: program shows encrypt and decrypt of the file when pass related parameters
author:B.Rajyalakshmi
date:12/05/2020
*/
#include"cryptography.h"
using namespace std;

void cryptography::encript(char* infile,string key)
{
    ifstream reading(infile,ios::in);
    stack<char>text;
    ofstream outfile("enc.txt",ios::out);
    outfile<<key<<endl;
     while(getline(reading,cwords))
    {
    	cout<<cwords<<endl;
    	int length=cwords.length();
    // Traverse given string and push all characters 
    // to stack until we see a space. 
    for (int istart=0;istart<length;++istart) 
	{ 
        if(cwords[istart]!= ' ') 
            text.push(cwords[istart]); 
        // When we see a space, we print contents 
        // of stack. 
        else 
		{
            while(text.empty()==false)
			{ 
                outfile<<text.top();
                text.pop();
            } 
                outfile<<'*';
        }
    }
     while(text.empty()==false)
	 { 
        outfile<<text.top(); 
        text.pop();
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
void cryptography::decript(char* infile,string key) 
{ 
	ifstream reading(infile,ios::in);
	getline(reading,csentance);
	// comparing the security keyword while entering into the decript
	if(csentance==key)
	{
    stack<char>Text; 
    ofstream outfile("decript.txt",ios::out);
    // Traverse given string and push all characters 
    // to stack until we see a star.
    while(getline(reading,csentance))
   {
   for (int istart=0;istart< csentance.length();++istart) 
   { 
        if (csentance[istart] != '*') 
            Text.push(csentance[istart]); 
        // When we see a star, we print contents 
        // of stack. 
        else 
		{ 
            while(Text.empty()==false) 
			{ 
                cout<<Text.top(); 
                outfile<<Text.top();
                Text.pop(); 
            } 
            cout <<" ";
			outfile<<" "; 
        } 
    } 
    // Since there may not be space after 
    // last word. 
    while(Text.empty()==false) 
	{ 
        cout<<Text.top(); 
        outfile<<Text.top();
        Text.pop(); 
    }
	outfile<<endl;
    cout<<endl;
    }
    outfile.close();
    reading.close();
    }
	else
    {
		cout<<"key doesn't match"<<endl;
	}
};
// main 
int main(int argc,char* argv[])
{
 	cryptography c;
 	//created a help command
    if((argc==2)&&strcmp(argv[1],"-h")==0)    
    {
        cout<<"-d||-e -f note.txt key"<<endl;
    }
    //encript calling
    else if((argc>1)&&strcmp(argv[1],"-e")==0)    
    {
   	   c.encript(argv[3],argv[5]);
    }
    //decript calling
     else if((argc>1)&&strcmp(argv[1],"-d")==0)    
    {

	c.decript(argv[3],argv[5]);
    }
    return 0; 
}
