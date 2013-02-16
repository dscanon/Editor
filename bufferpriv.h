/*
* File: bufferpriv.h
* ------------------* This file contains the private section of the EditorBuffer
* class for the list-based editor.
*/
/*
* Implementation notes: Buffer data structure
* -------------------------------------------* In the linked-list implementation of the buffer, the characters
* in the buffer are stored in a list of Cell structures, each of
* which contains a character and a pointer to the next cell in the
* chain. To simplify the code used to maintain the cursor, this
* implementation adds an extra "dummy" cell at the beginning of the
* list. The character in this cell is not used, but having it in
* the data structure provides a cell for the cursor to point to
* when the cursor is at the beginning of the buffer.
*
* The following diagram shows the structure of the list-based buffer
* containing "ABC" with the cursor at the beginning:
*
* +-----+ +-----+ +-----+ +-----+ +-----+
* start | o--+---==>| | -->| A | -->| B | -->| C |
* +-----+ / +-----+ / +-----+ / +-----+ / +-----+
* cursor | o--+-- | o--+-- | o--+-- | o--+-- | / |
* +-----+ +-----+ +-----+ +-----+ +-----+
*/
private:
/*
* Type: Cell
* ----------* This structure type is used locally within the implementation to
* store each cell in the linked-list representation. Each cell
* contains one character and a pointer to the next cell in the chain.
*/
struct Cell {
char ch;
Cell *link;
};
/* Instance variables */
Cell *start; /* Pointer to the dummy cell */
Cell *cursor; /* Pointer to cell before cursor */
/* Make it illegal to copy editor buffers */
EditorBuffer(const EditorBuffer & value) { }
const EditorBuffer & operator=(const EditorBuffer & rhs) { return *this; }