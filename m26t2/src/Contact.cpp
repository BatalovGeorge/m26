#include "Contact.h"
//double const means const return CONST func,
//where we can not change value of the contact through func
//& means we got reference to private field class

const std::string &Contact::number() const
{
    return _number;
}

void Contact::setNumber(const int &newNumber)
{
        std::string num = std::to_string(newNumber);
        num.insert(0,REGION_CODE);
        _number = num;
}

const std::string &Contact::name() const
{
    return _name;
}

const std::vector<std::string> &Contact::messages() const
{
    return _messages;
}

void Contact::setMessages(const std::string &newMessages)
{
    _messages.push_back(newMessages);
}

void Contact::show_contact() const
{
    std::cout<<_name<<"; "<<_number<<";\n";
}
