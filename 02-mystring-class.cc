/**
 *   @file: 02-mystring-main.cc
 * @author: Nasseef Abukamail
 *   @date: May 19, 2021
 *  @brief: Add Description
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

class MyString {
   public:
    MyString(int size);       // Initializes with a size (default to 1000).
    MyString();               // initialize with 1000 size
    MyString(const char* s);  // initialize the string with the
                              // given string
    ~MyString();              // Returns all the dynamic memory
                              // used by the object to the heap.
    /**
     * MyString: Copy constructor
     * @param strObject - an initialize object
     *
     */
    MyString(const MyString& strObject);
    /**
     * operator =: overload the assignment operator
     * @param rightSide - an object that has been initialized
     */
    void operator = (const MyString &rightSide);

    void setString(const char* newString);
    char at(int index);  // retrun character at index or '\0'
    char* getString();
    int length() const;
    friend ostream& operator<<(ostream& outs, const MyString& theString);

   private:
    char* str;
    int maxLength;
};
/// Constants and function prototypes

void printString(MyString s);

int main(int argc, char const* argv[]) {
    MyString first;  // initialize to empty string
    first.setString("John");
    printString(first);

    MyString last("Smith");
    cout << first << " " << last << endl;  // prints Smith
    cout << "Last initial: " << last.at(0) << endl;
    {
        MyString copyLast(6);
        copyLast = last;
        // Let's exammin the pointer inside last and last2
        cout << "Copy of last: " << copyLast << endl;
    }
    cout << last << endl;
    return 0;
}  /// main

void printString(MyString s) { cout << s << endl; }

MyString::MyString(int size) {
    if (size > 0) {
        str = new char[size];
        maxLength = size;
    } else {
        str = new char[1000];
        maxLength = 1000;
    }
}

void MyString::operator = (const MyString &rightSide){
    int newLength = strlen(rightSide.str);
   //before deleting check to see if maxLength is enough if not checked then
   //the statement string1 = string1; will delete the memory allocated to the string.
   if (newLength > maxLength)
   {
       delete [] str;
       maxLength = newLength;
       str = strndup(rightSide.str, 1000);
   }
   else {
       strncpy(str, rightSide.str, 1000);
   }
}

MyString::MyString() {
    str = new char[1000];
    maxLength = 1000;
}
MyString::MyString(const char* newString) {
    str = strndup(newString, 1000);  // Allocate and copy up to 1000 characters
    maxLength = strlen(str);
}
MyString::~MyString() { delete[] str; }

// MyString copy constructor
MyString::MyString(const MyString& strObject) {
    maxLength = strObject.length();
    str = strndup(strObject.str, 1000);  // Allocate and copy up to 1000
                                        // characters
}

// used by the object to the heap.
void MyString::setString(const char* newString) {
    int length = strlen(newString);
    if (length > maxLength) {
        delete[] str;
        str = strndup(newString, 1000);  // Allocate and copy up to 1000
                                        // characters
        maxLength = length;
    } else {
        strcpy(str, newString);
    }
}
char* MyString::getString() {
    char* strCopy = strndup(str, 1000);  // never return a pointer to your data
    return strCopy;
}
char MyString::at(int index) {
    if (index >= 0 && index < strlen(str)) {
        return str[index];
    } else {
        return '\0';
    }

}  // retrun character at index or '\0'
int MyString::length() const { return strlen(str); }
ostream& operator<<(ostream& outs, const MyString& theString) {
    outs << theString.str;
    return outs;
}
