#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
using namespace std;

// The unsigned integral type which is used to store the number of
// characters in a string is nested within the string class, so it
// is accessed using "string::size_type".
// The range of string::size_type is guaranteed to be large enough to store the maximum
// *size* of any string that can be held by the string class as well as any index into
// the string.

enum class Direction {HOME, FORWARD, BACK, UP, DOWN, END};

class Screen {
public:
	// Screen's constructor
	Screen(string::size_type height, string::size_type width, char bkground = '#');

	// get the Screen's height
	string::size_type height() const { return height_; }
	// get the Screen's width
	string::size_type width() const { return width_; }

	// place the cursor at the top-left corner of the screen
	void home() { cursor_ = 0;  return; }
	// place the cursor at the bottom-right corner of the screen
	void end() { cursor_ = width_ * height_ - 1; return; }
	// move the cursor one position to the right
	void forward();
	// move the cursor one position to the left
	void back();
	// move the cursor up one row
	void up();
	// move the cursor down one row
	void down();
	// move the cursor to the specified row and column
	void move(string::size_type row, string::size_type col);
	void move (Direction dir); // overload move function

	// get the character at the cursor's current position
	char get() const { return _screen[cursor_]; }
	// get the character at the specified row and column
	char get(string::size_type row, string::size_type col);

	// write a character on the screen at the current cursor position
	void set( char ch );
	// write a string of characters on the screen starting at the current cursor position
	void set( const string& s );
	// overwrite the entire screen with the specified character
	void clear( char bkground = '#');

	// resize the screen
	void reSize( string::size_type height, string::size_type width, char bkground = '#');
	// display the screen
	void display() const;
	// check whether the specified co-ordinates lie within the screen
	bool checkRange(string::size_type row, string::size_type col) const;

private:
	// constants
	// 0 represents the top-left screen element
	const string::size_type TOP_LEFT = 0;

	// private member functions
	string::size_type remainingSpace() const;
	string::size_type row() const;

	// private data members
	// (using a trailing underscore is a naming convention for private data - not a requirement)

	// number of Screen rows
	string::size_type height_;
	// number of Screen columns
	string::size_type width_;
	// default position of the Screen's cursor, use in-class initilisation
	string::size_type cursor_ = TOP_LEFT;
	// the Screen's data is stored as a string
	string _screen;
};


#endif

//Explanations of 3 situations which const is used.
//1. string::size_type height() const { return height_; }
// const use in the above means that height () function cannot modify anything in the class.

//2. void set( const string& s );
// const use in the above means the function cannot modify the passed in parameter.

//3. const string::size_type TOP_LEFT = 0;
// const use in the above means that the variable is set to a fixed value an cannot be
// anywhere in the class.

//Meaning of string class's at member function:
// void reSize( string::size_type height, string::size_type width, char bkground = '#');
// string::size_type is of an unsigned integer type.
// This means that parameters height and width are of type int(unsigned).
// This is good for information hiding in the class.

