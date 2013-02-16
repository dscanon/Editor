#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
void readFile(ifstream infile,string data);
int main(){
	string str,command, data;
getline(cin,str);
ifstream infile;
		/* For example #Load wiboon.txt
		command ex. #Load #Set #Save
		data is argument after command*/
	command	= str.substr(0,str.find(' '));
	data	= str.substr(str.find(' ')+1);
	cout << command << endl;
	cout << data << endl;
	switch(command)
	{
	case "#Load": readFile(infile,data);break;
	case "#Set"	: break;
	case "#Show": break;
	case "#Edit": break;
	case "#Save": break;
	case "#Quit": break;
	default : cout <<"Incorrect command"; break;
	}
return 0;
}

void readFile(ifstream infile,string data)
{	
	string str;
	map<string,string> smap;
	infile.open(data);
		while(infile!=EOF)
		{
			infile.getline(str,200)
		}
}