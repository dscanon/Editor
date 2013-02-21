/*
* File: buffer.h
* --------------* This file defines the interface for the EditorBuffer class.
*/
#ifndef _buffer_h
#define _buffer_h
#include <string>
/*
* Class: EditorBuffer
* -------------------* This class represents an editor buffer, which maintains an ordered
* sequence of characters along with an insertion point called the cursor.
*/
class EditorBuffer {
public:
/*
* Constructor: EditorBuffer
* Usage: EditorBuffer buffer;
* ---------------------------* Creates an empty editor buffer.
*/
EditorBuffer();
/*
* Destructor: ~EditorBuffer
* Usage: (usually implicit)
* -------------------------* Frees any heap storage associated with this buffer.
*/
~EditorBuffer();
/*
* Methods: moveCursorForward, moveCursorBackward
* Usage: buffer.moveCursorForward();
* buffer.moveCursorBackward();
* -----------------------------------* These functions move the cursor forward or backward one character,
* respectively. If the command would shift the cursor beyond either
* end of the buffer, this method has no effect.
*/
void moveCursorForward();
void moveCursorBackward();
/*
* Methods: moveCursorToStart, moveCursorToEnd
* Usage: buffer.moveCursorToStart();
* buffer.moveCursorToEnd();
* --------------------------------* These functions move the cursor to the start or the end of this buffer.
*/
void moveCursorToStart();
void moveCursorToEnd(); 
/*
* Method: insertCharacter
* Usage: buffer.insertCharacter(ch);
* ----------------------------------* Inserts the single character ch into this buffer at the cursor
* position. The cursor is then advanced to follow the inserted
* character, thereby allowing for consecutive insertions.
*/
void insertCharacter(char ch);
/*
* Method: deleteCharacter
* Usage: buffer.deleteCharacter();
* --------------------------------* Deletes the character immediately after the cursor. If the cursor is
* at the end of the buffer, the method has no effect.
*/
void deleteCharacter();
/*
* Method: showContents
* Usage: buffer.showContents();
* -----------------------------* Displays the buffer contents on the console stream and notes the
* position of the cursor.
*/
void showContents();

//return string in the buffer.
std::string str();

#include "bufferpriv.h"
};
#endif
