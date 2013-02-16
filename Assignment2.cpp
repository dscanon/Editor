#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
void readFile(ifstream infile,string data);
void setDateInFile(string data);
void setDateOnShow(string data);
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
	if(command == "#Load"){readFile(infile,data);} 
	//readFile will load file name(data) and get data in <map>.
	else if(command == "#Set"){setDateInFile(data);setDateOnShow(data);}
	/*setDateInFile is method will set date same as date in file.
	 ex.  #Set12 01 2013	has set		string dateInFile 12012013
	 setDateOnShow is method will set date on show content.
	 ex. #Set12 01 2013	has set		string dateOnshow 12 December 2013*/	 
	else if(command == "#Show"){}
	else if(command == "#Edit"){}
	else if(command == "#Save"){}
	else if(command == "#Quit")
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
