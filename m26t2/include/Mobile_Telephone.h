#ifndef MOBILE_TELEPHONE_H
#define MOBILE_TELEPHONE_H

//this is telephone, not smartphone or phone, hehe

#include <map>
#include <sstream>
#include <ctype.h>
#include "Contact.h"

class Mobile_Telephone
{
private:
    std::map<int,Contact> _contacts_book;
    std::string _phone_model;
    int s_num=0;
public:
    void add();
    void communication(int,std::string);
    void show();

    const std::map<int, Contact> &contacts_book() const;
};
#endif // MOBILE_TELEPHONE_H
