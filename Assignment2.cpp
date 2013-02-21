#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
#include "buffer.h"
using namespace std;

void readfile(ifstream & infile, map<string, string> & smap);
bool showContent(map<string, string> & smap, string date);
void executeCommand(EditorBuffer & buffer, string line, int &count);

int main(){
	 /* For example #Load wiboon.txt
	 *  command ex. #Load #Set #Save
	 *  data is argument after command
	 */
	string str, command, data, date, month, numMonth  ;
	int count;
	ifstream infile;
	EditorBuffer buffer;
	
	//key = date, value = messages which are matched with date.
	map <string, string> smap;
	

	while(getline(cin, str)){
	data = str.substr(str.find(' ')+1);
	command = str.substr(0,str.find(' '));
		if(smap.empty()){
			if(command == "#Load"){
				smap.clear();
				infile.open(data.c_str());
				if(infile.fail()){ cout << "fail" << endl;break;}
				else readfile(infile, smap);
			}
			else{
				cout <<  "Incorect Command" << endl;
			}
		} else {
			if(command == "#Load"){
				smap.clear();
				infile.close();
				infile.open(data.c_str());
				infile.seekg(ios::beg); // move cursor to begin of file.
				if(infile.fail()) cout << "fail2" << endl;
				else readfile(infile, smap);
			}
			else if(command == "#Set"){
				date = data;
				cout << "date1" <<date<<endl;
				month = date.substr(date.find(' ')+1,date.rfind(' ')-date.find(' ')-1);
				numMonth = month;
				cout << month  << endl;
				cout << "date2" << date << endl;
						 if(month=="01")	{month = "January";}
					else if(month=="02")	{month = "February";}
					else if(month=="03")	{month = "March";}
					else if(month=="04")	{month = "April";}
					else if(month=="05")	{month = "May";}
					else if(month=="06")	{month = "June";}
					else if(month=="07")	{month = "July";}
					else if(month=="08")	{month = "August";}
					else if(month=="09")	{month = "September";}
					else if(month=="10")	{month = "October";}
					else if(month=="11")	{month = "November";}
					else if(month=="12")	{month = "December";}
					cout << month << endl;
					cout << "date3" << date << endl;
					numMonth = date.replace(date.find(' '),date.rfind(' ')-date.find(' ')+1,numMonth);
					cout << numMonth << "---numMonth" << endl;
					cout << date <<endl;
			}
			else if(command == "#Show"){
				if(showContent(smap,numMonth)){cout << smap[numMonth] << endl;}
				else {cout << "No date in file.";}
			}
			else if(command == "#Edit"){
				count = 1;
				if(showContent(smap,numMonth)){cout << smap[numMonth] << endl;}
				else {cout << "No date in file.";}
				for (unsigned i = 0; i < smap[numMonth].length(); i++) {
				buffer.insertCharacter(smap[numMonth][i]);
				}
						while (true) {
						string cmd;
						cout << "*";
						getline(cin,cmd);
						if (cmd != "") executeCommand(buffer, cmd, count);
						buffer.showContents();
						if(count==0)break;
						}
			}
			else if(command == "#Save"){
				buffer.showContents();
			}
			else{
				cout << "Incorect Command" << endl;
			}
		}
	}
	return 0;
}

void readfile(ifstream &infile, map<string, string> & smap){
	string str;
	while(!infile.eof()){
		getline(infile,str);
		smap[str.substr(0,8)] = str.substr(9,91); 
		cout << smap[str.substr(0,8)] << endl;
	}
}


bool showContent(map<string, string> & smap, string numDate){
for(map<string, string>::iterator it=smap.begin();it!=smap.end();it++){
					if((*it).first == numDate ){
						return 1;
	}
}
	return 0;
}


void executeCommand(EditorBuffer & buffer, string line ,int &count) {
	switch (toupper(line[0])) {
case 'I': for (unsigned i = 1; i < line.length(); i++) {
	buffer.insertCharacter(line[i]);
		  }
		  break;
case 'D': buffer.deleteCharacter(); break;
case 'F': buffer.moveCursorForward(); break;
case 'B': buffer.moveCursorBackward(); break;
case 'J': buffer.moveCursorToStart(); break;
case 'E': buffer.moveCursorToEnd(); break;
case 'Q': count = 0; break;
default: cout << "Illegal command" << endl; break;
	}
} 
