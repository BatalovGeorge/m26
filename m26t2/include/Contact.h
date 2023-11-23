#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <vector>

#define REGION_CODE "+7"

#define MSG_FLAG 0
#define CALL_FLAG 1
#define MSG_DATA 2

class Contact
{
private:
    std::string _name;
    std::string _number;
    std::vector<std::string> _messages;
public:
    Contact(std::string name):_name(name){};

    void show_contact() const;

    const std::string &number() const;
    void setNumber(const int &newNumber);

    const std::string &name() const;
    const std::vector<std::string> &messages() const;
    void setMessages(const std::string &newMessages);
};
#endif // CONTACT_H
