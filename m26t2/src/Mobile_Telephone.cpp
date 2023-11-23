#include "Mobile_Telephone.h"

const std::map<int, Contact> &Mobile_Telephone::contacts_book() const
{
    return _contacts_book;
}

void Mobile_Telephone::add()
{

    int num_contact;
    std::string name_buff,num_buff,user_input;

    std::cout<<"\nInput name and telephone num (without prefix +7):";
    getline(std::cin,user_input);
    std::stringstream ss(user_input);

    ss>>name_buff>>num_buff;

    if(num_buff.size()!=10){std::cout<<"number must contain 10 digits"<<std::endl;}

    for(int i=0;i<num_buff.size();i++)
    {
        if(!isdigit(num_buff[i]))
        {
            std::cout<<"number contains non-digit character, number is not added to contact!"<<std::endl;
            num_buff.clear();
            break;
        }
    }

    if(num_buff.empty())
    {
        std::cout<<"empty field: number\n";
        std::cin.sync();
        //not smart idea, but who cares, 'll do it l8r
        add();
    }else{
        s_num++;
        std::stringstream ss_to_int(num_buff);
        ss_to_int>>num_contact;

        Contact *person = new Contact(name_buff);
        person->setNumber(num_contact);

        _contacts_book.emplace(s_num,*person);
        delete person;
    }
}

void Mobile_Telephone::communication(int communication_flag, std::string user_input)
{
    std::string request,msg_input;
    if(_contacts_book.empty()){std::cout<<"\tadress book is empty\n";}

    for(auto& book_iter:_contacts_book)
    {
        if(book_iter.second.name().find(user_input)||book_iter.second.number().find(user_input))
        {
            switch(communication_flag)
            {
            case CALL_FLAG:
                request="\tcalling \n";
                std::cout<<request;
                book_iter.second.show_contact();
                break;

            case MSG_FLAG:
                request="\tsending msg \n";
                std::cout<<request<<"type your message: ";
                getline(std::cin,msg_input);
                book_iter.second.setMessages(msg_input);
                std::cout<<"\tmessage has sended\n ";
                break;

            case MSG_DATA:
                request="\tcheck messages for this contact \n";
                std::cout<<request;
                for(auto&msg:book_iter.second.messages())
                {
                    std::cout<<msg<<std::endl;
                }
                break;

            default:
                std::cout<<"\tuncnown cmd\n";
                break;
            }
        }else{std::cout<<"no such contact in adress book\n";}
    }

}

void Mobile_Telephone::show()
{
    for(auto person_itr=_contacts_book.begin();person_itr!=_contacts_book.end();person_itr++)
    {
        std::cout<<person_itr->first<<" ";
        person_itr->second.show_contact();
    }

}
