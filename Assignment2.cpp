#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
using namespace std;




void readfile(ifstream & infile, map<string, string> & smap);


int main(){
	 /* For example #Load wiboon.txt
	 *  command ex. #Load #Set #Save
	 *  data is argument after command
	 */
	string str, command, data, date;
	
	ifstream infile;
	
	//key = date, value = messages which are matched with date.
	map <string, string> smap;
	
	getline(cin, str);	
	data = str.substr(str.find(' ')+1);
	command = str.substr(0,str.find(' '));
	cout << command << endl;
	cout << data << endl;
	while(true){
		if(smap.empty()){
			if(command == "#Load"){
				smap.clear();
				infile.open(data.c_str());
				if(infile.fail()){ cout << "fail" << endl;break;}
				else readfile(infile, smap);
			}
			else{
				cout << "no file in the buffer" << endl;
			}
		} else {
			if(command == "#Load"){
				smap.clear();
				infile.open(data.c_str());
				if(infile.fail()) cout << "fail" << endl;
				else readfile(infile, smap);
			}
			else if(command == "Set"){
				date == data;
			}
			else if(command == "#Show"){
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
