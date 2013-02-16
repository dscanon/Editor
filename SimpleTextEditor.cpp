/*
* File: SimpleTextEditor.cpp
* --------------------------* This program implements a simple command-driven text editor, which is
* used to test the EditorBuffer class.
*/
#include <iostream>
#include <sstream>
#include <cctype>
#include "buffer.h"
using namespace std;
/* Function prototypes */
void executeCommand(EditorBuffer & buffer, string line);
/* Main program */
int main() {
	EditorBuffer buffer;
	while (true) {
		string cmd;
		cout << "*";
		getline(cin,cmd);
		if (cmd != "") executeCommand(buffer, cmd);
		buffer.showContents();
	}
	return 0;
}
/*
* Function: executeCommand
* Usage: executeCommand(buffer, line);
* ------------------------------------* Executes the command specified by line on the editor buffer.
*/
void executeCommand(EditorBuffer & buffer, string line) {
	switch (toupper(line[0])) {
case 'I': for (int i = 1; i < line.length(); i++) {
	buffer.insertCharacter(line[i]);
		  }
		  break;
case 'D': buffer.deleteCharacter(); break;
case 'F': buffer.moveCursorForward(); break;
case 'B': buffer.moveCursorBackward(); break;
case 'J': buffer.moveCursorToStart(); break;
case 'E': buffer.moveCursorToEnd(); break;
case 'Q': exit(0);
default: cout << "Illegal command" << endl; break;
	}
} 