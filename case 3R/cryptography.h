#include<string.h>
#include<stack>
#include<iostream>
#include<fstream>
using namespace std; 
class cryptography
{
	private:
	string cwords;
	string csentance;
	public:
		cryptography()
		void encript(char* infile,string key);
		void decript(char* infile,string key);
		~cryptography()
}
