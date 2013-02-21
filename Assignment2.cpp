#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <sstream>
#include "buffer.h"
using namespace std;




void readfile(ifstream & infile, map<string, string> & smap);
bool showContent(map<string, string> & smap, string date);
int editMode(EditorBuffer & buffer, map<string, string> & smap, string & date);
void sorting(map<string,string> &,vector<string> &, vector<string> &);
int stringToInt(string);
//void executeCommand(EditorBuffer & editor, string line);

int main(){
	 /* For example #Load wiboon.txt
	 *  command ex. #Load #Set #Save
	 *  data is argument after command
	 */
	EditorBuffer buffer;
	string str,command, data, date, month, filename;
	ifstream infile;
	ofstream outfile;
	vector<string> first;
	vector<string> second;
	//key = date, value = messages which are matched with date.
	map <string, string> smap;
	while(getline(cin, str)){
	data = str.substr(str.find(' ')+1);
	command = str.substr(0,str.find(' '));
		if(smap.empty()){
			if(command == "#Load"){
				smap.clear();
				infile.open(data.c_str());
				if(infile.fail()) {cout << "fail" << endl;break;}
				else {
					readfile(infile, smap);
					filename = data;
				}
			}else{
				cout << "no file in the buffer" << endl;
			}
		} else {
			if(command == "#Load"){
				smap.clear();
				infile.close();
				infile.open(data.c_str());
				infile.seekg(ios::beg); // move cursor to begin of file.
				if(infile.fail()) cout << "fail2" << endl;
				else {
					readfile(infile, smap);
					filename = data;
				}

			}
			else if(command == "#Set"){
				
				date = data;
				month = date.substr(date.find(' ')+1,date.rfind(' ')-date.find(' ')-1);
					if(month=="01")		{month = "January";}
					else if(month=="02")	{month = "February";}
					else if(month=="03")		{month = "March";}
					else if(month=="04")		{month = "April";}
					else if(month=="05")		{month = "May";}
					else if(month=="06")		{month = "June";}
					else if(month=="07")		{month = "July";}
					else if(month=="08")	{month = "August";}
					else if(month=="09")	{month = "September";}
					else if(month=="10")	{month = "October";}
					else if(month=="11")	{month = "November";}
					else if(month=="12")	{month = "December";}
						date.erase(2, 1);
						date.erase(4, 1);
						buffer.moveCursorToStart();
						while((buffer.str()).length()!=0){
							buffer.deleteCharacter();
						}
						for(int i = 0 ; i < smap[date].length() ; i++){
							buffer.insertCharacter(smap[date][i]);
						}
			}
			else if(command == "#Show"){
				cout << date.substr(0,2) << " "<< month << " "<< date.substr(4,4) << endl;
				/*buffer.moveCursorToStart();
						while((buffer.str()).length()!=0){
							buffer.deleteCharacter();
						}
						for(unsigned i = 0 ; i < smap[date].length() ; i++){
							buffer.insertCharacter(smap[date][i]);
						}*/
				if(showContent(smap,date)){
					buffer.showContents();
				}
				else {
					cout << "No date in file.";
				}
			}
			else if(command == "#Edit"){
				cout << date.substr(0,2) << " "<< month << " " << date.substr(4,4) << endl;
				buffer.showContents();
				editMode(buffer, smap, date);
			}
			else if(command == "#Save"){
				cout << date.substr(0,2) << " "<< month << " " << date.substr(4,4) << endl;
				cout << smap[date] << endl;
				sorting(smap, first, second);
				outfile.open(filename.c_str());
					for(unsigned i=0 ; i < first.size() ; i++){
					outfile << first[i] << " " << smap[first[i]];
					if(i!=first.size()-1){outfile << endl;}
				}
				outfile.close();
			
			}else if(command == "#Quit"){
				return 0;
			}
			else {
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
	}
	infile.close();
}

bool showContent(map<string, string> & smap, string date){
	for(map<string, string>::iterator it=smap.begin();it!=smap.end();it++){
		if((*it).first == date ){
			return true;
		}
	}
	return false;
}

int editMode(EditorBuffer & buffer, map<string, string> & smap, string & date){
	while (true) {
		string a;
		string cmd;
		cout << "*";
		getline(cin,cmd);
		if (cmd != "") {
			switch (toupper(cmd[0])) {
				case 'I': for (unsigned i = 1; i < cmd.length(); i++) {
					buffer.insertCharacter(cmd[i]);
				}
				break;
				case 'D': buffer.deleteCharacter(); break;
				case 'F': buffer.moveCursorForward(); break;
				case 'B': buffer.moveCursorBackward(); break;
				case 'J': buffer.moveCursorToStart(); break;
				case 'E': buffer.moveCursorToEnd(); break;
				case 'Q': a = buffer.str();
						  smap[date] = a;
						  return 0;;
				default: cout << "Illegal command" << endl; break;
			}
		}
		buffer.showContents();
	}
}

void sorting(map<string, string> & smap , vector<string> & first, vector<string> & second){
	int i=0;
	for(map<string, string>::iterator it = smap.begin() ; it!=smap.end() ; it++){
		first.push_back(it->first);
		i++;	
	}
	int firstIndex = 0;
	int smallestIndex;
	int index;
	while(firstIndex!=first.size()-1){
		index = first.size()-1;
		smallestIndex = index;
		while(index!=firstIndex){
			index--;
			if(stringToInt(first[index].substr(4,4)) < stringToInt(first[smallestIndex].substr(4,4))){
				smallestIndex = index;
			} else if(stringToInt(first[index].substr(4,4)) == stringToInt(first[smallestIndex].substr(4,4))){
				if(stringToInt(first[index].substr(2,2)) < stringToInt(first[smallestIndex].substr(2,2))){
					smallestIndex = index;
				}else if(stringToInt(first[index].substr(2,2)) == stringToInt(first[smallestIndex].substr(2,2))){
					if(stringToInt(first[index].substr(0,2)) < stringToInt(first[smallestIndex].substr(0,2)))smallestIndex = index;
				}
			}
		}
		string temp = first[smallestIndex];
		first[smallestIndex] = first[firstIndex];
		first[firstIndex] = temp;
		firstIndex++;
	}
}

int stringToInt(string str){
	istringstream ss(str);
	int i;
	ss >> i;
	return i;
}
