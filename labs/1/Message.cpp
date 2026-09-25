/* 
-----------------------------------------------------------
Lab 1
Module: Message
Filename: Message.cpp
-----------------------------------------------------------
Author: Fardad
Subject: OOP345NAA
-----------------------------------------------------------
Description:
Implements the Message class.
Students must complete the Rule of Five implementations.
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
1.0     2026/09/24 Initial release
-----------------------------------------------------------
*/
 
#include <iostream>
#include <cstring>
#include "Message.h"
 
using namespace std;
 
namespace seneca {
 
    Message::Message() {
    }
 
    Message::Message(const char* text, Priority priority) {
        m_priority = priority;
 
        if (text && text[0]) {
            m_text = new char[strlen(text) + 1];
            strcpy(m_text, text);
        }
    }
 
    // TODO:
    // Implement the destructor.
 
    Message::~Message(){
        delete[] m_text;
    }

    // TODO:
    // Implement the copy constructor.
 
    Message::Message(const Message& other) {
        *this = other;
    }
 
    // TODO:
    // Implement the copy assignment operator.
 
    Message& Message::operator=(const Message& other) {
        if(this != &other) {
            delete[] m_text;
            m_text = nullptr;
            if (other.empty()) {
                m_text = new char[strlen(other.text()) + 1];
                strcpy(m_text, other.text());
            }
            m_priority = other.priority();
        }
        return *this;
    }

    // TODO:
    // Implement the move constructor.
 
    Message::Message(Message&& other) noexcept {
        *this = move(other);
    }
 
    // TODO:
    // Implement the move assignment operator.

    Message& Message::operator=(Message&& other) noexcept { 
        if (this != &other) {
            m_text = other.m_text;
            m_priority = other.priority();
            other.m_text = nullptr;
        }
        return *this;
    }

    const char* Message::text() const {
        return m_text ? m_text : "";
    }
 
    Priority Message::priority() const {
        return m_priority;
    }
 
    bool Message::empty() const {
        return m_text == nullptr || m_text[0] == '\0';
    }
 
    void Message::display() const {
        if (!empty()) {
            cout << text() << " [";
 
            switch (m_priority) {
            case Priority::low:
                cout << "Low";
                break;
            case Priority::normal:
                cout << "Normal";
                break;
            case Priority::high:
                cout << "High";
                break;
            }
 
            cout << "]" << endl;
        }
        else {
            cout << "Empty Message" << endl;
        }
    }
 
}
