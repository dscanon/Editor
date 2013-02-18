#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
using namespace std;

void readfile(ifstream & infile, map<string, string> & smap);
bool showContent(map<string, string> & smap, string date);

int main(){
	 /* For example #Load wiboon.txt
	 *  command ex. #Load #Set #Save
	 *  data is argument after command
	 */
	string str, command, data, date, month ;

	ifstream infile;
	
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
				month = date.substr(date.find(' ')+1,date.rfind(' ')-date.find(' ')-1);
				cout << month  << endl;
					if(month=="January")		{month = "01";}
					else if(month=="February")	{month = "02";}
					else if(month=="March")		{month = "03";}
					else if(month=="April")		{month = "04";}
					else if(month=="May")		{month = "05";}
					else if(month=="June")		{month = "06";}
					else if(month=="July")		{month = "07";}
					else if(month=="August")	{month = "08";}
					else if(month=="September")	{month = "09";}
					else if(month=="October")	{month = "10";}
					else if(month=="November")	{month = "11";}
					else if(month=="December")	{month = "12";}
						cout << month << endl;
						date = date.replace(date.find(' '),date.rfind(' ')-date.find(' ')+1,month);
						cout << date <<endl;
			}
			else if(command == "#Show"){
				if(showContent(smap,date)){
					cout << smap[date] << endl;
				}
				else {
					cout << "No date in file.";
				}
			}
			else if(command == "#Edit"){
			}
			else if(command == "#Save"){
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


bool showContent(map<string, string> & smap, string date){
	for(map<string, string>::iterator it=smap.begin();it!=smap.end();it++){
		if((*it).first == date ){
			return 1;
		}
	}
return 0;
}
