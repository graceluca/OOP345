/* 
-----------------------------------------------------------
Lab 1
Module: Main
Filename: main.cpp
-----------------------------------------------------------
Author: Fardad
Subject: OOP345NAA
-----------------------------------------------------------
Description:
Tests the Message class Rule of Five implementation.
This file must not be modified by the student.
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
1.0     2026/09/24 Initial release
-----------------------------------------------------------
*/
 
#include <iostream>
#include <utility>
#include "Message.h"
 
using namespace std;
using namespace seneca;
 
int main() {
 
    cout << "1. Construction" << endl;
    cout << "--------------" << endl;
 
    Message msg1("Rule of Five", Priority::high);
    msg1.display();
 
    cout << endl;
 
    cout << "2. Copy Constructor" << endl;
    cout << "-------------------" << endl;
 
    Message msg2(msg1);
 
    cout << "Original: ";
    msg1.display();
 
    cout << "Copy    : ";
    msg2.display();
 
    cout << endl;
 
    cout << "3. Copy Assignment" << endl;
    cout << "------------------" << endl;
 
    Message msg3("Old Message", Priority::low);
 
    cout << "Before assignment: ";
    msg3.display();
 
    msg3 = msg1;
 
    cout << "After assignment : ";
    msg3.display();
 
    cout << endl;
 
    cout << "4. Self Assignment" << endl;
    cout << "------------------" << endl;
 
    msg3 = msg3;
 
    cout << "After self assignment: ";
    msg3.display();
 
    cout << endl;
 
    cout << "5. Move Constructor" << endl;
    cout << "-------------------" << endl;
 
    Message msg4(std::move(msg1));
 
    cout << "Moved object : ";
    msg4.display();
 
    cout << "Source object: ";
    msg1.display();
 
    cout << endl;
 
    cout << "6. Move Assignment" << endl;
    cout << "------------------" << endl;
 
    Message msg5("Temporary", Priority::low);
 
    cout << "Destination before move: ";
    msg5.display();
 
    msg5 = std::move(msg2);
 
    cout << "Destination after move : ";
    msg5.display();
 
    cout << "Source after move      : ";
    msg2.display();
 
    cout << endl;
 
    cout << "7. Empty Object" << endl;
    cout << "---------------" << endl;
 
    Message empty;
 
    cout << "empty(): "
         << (empty.empty() ? "true" : "false")
         << endl;
 
    empty.display();
 
    return 0;
}