/* 
-----------------------------------------------------------
Lab 1
Module: Message
Filename: Message.h
-----------------------------------------------------------
Author: Fardad
Subject: OOP345NAA
-----------------------------------------------------------
Description:
Declares the Message class and Priority scoped enumeration.
Students must complete the Rule of Five declarations.
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
1.0     2026/09/24 Initial release
-----------------------------------------------------------
*/
 
#ifndef SENECA_MESSAGE_H
#define SENECA_MESSAGE_H
 
#include <iostream>
 
namespace seneca {
 
    enum class Priority {
        low,
        normal,
        high
    };
 
    class Message {
        char* m_text{};
        Priority m_priority{ Priority::normal };
 
    public:
        Message();
        Message(const char* text,
            Priority priority = Priority::normal);
 
        // TODO:
        // Declare the five special member functions
        // required by the Rule of Five.
 
        ~Message();

        Message(const Message& other);

        Message& operator=(const Message& other);

        Message(Message&& other) noexcept;

        Message& operator=(Message&& other) noexcept;

        const char* text() const;
        Priority priority() const;
        bool empty() const;
        void display() const;
    };
 
}
 
#endif