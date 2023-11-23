/*//Задание 2. Реализация программы симуляции мобильного телефона
//Что нужно сделать

//Реализуйте программу простой симуляции работы мобильного телефона.

//По мобильному телефону можно звонить и отправлять СМС. Также мобильный телефон содержит адресную книгу. Телефон и отдельные записи адресной книги должны быть реализованы с помощью классов. Все номера телефонов задаются в формате +7 <10 цифр>.

//Пользователь взаимодействует с программой с помощью команд:

//    Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта. Оба эти параметра команда получает от пользователя через стандартный ввод.
//    Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить. Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.
//    Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который требуется послать сообщение. Само сообщение также вводится через стандартный ввод.
//    Команда exit — выход из программы.

//Советы и рекомендации

//Сам по себе тип номера телефона вы тоже можете реализовать с помощью отдельного класса.
//Что оценивается

//Корректность работы программы.
//Как отправить работу на проверку

//Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.*/

#include "Contact.h"
#include "Mobile_Telephone.h"

#include <algorithm>
#include <sstream>

int main()
{
    Mobile_Telephone *m1 = new Mobile_Telephone();
    while(true)
    {
        std::string user_input;
        std::cout<<"input command (ADD, CALL, SMS, EXIT)"<< std::endl;

        getline(std::cin,user_input);
        std::transform(user_input.begin(), user_input.end(), user_input.begin(),
            [](unsigned char c){ return std::tolower(c); });

        if(user_input=="call" && !m1->contacts_book().empty())
        {
            m1->show();
            std::cin.sync();
            std::cout<<"input name or phone num:";
            std::string search_input;
            getline(std::cin,search_input);
            m1->communication(CALL_FLAG,search_input);
        }
        else if(user_input=="add")
        {
            m1->add();
        }
        else if(user_input=="sms" && !m1->contacts_book().empty())
        {
            std::cin.sync();
            m1->show();
            std::cout<<"input name or phone num:";
            std::string search_input;
            getline(std::cin,search_input);
            m1->communication(MSG_FLAG,search_input);
        }
        else if(user_input=="exit")
        {
            std::cout<<"\texit\n";
            delete m1;
    //        break;
            exit(0);
        }else if(user_input=="data" && !m1->contacts_book().empty())
        {
            m1->show();
            std::cout<<"input name or phone num:";
            std::string search_input;
            getline(std::cin,search_input);
            m1->communication(MSG_FLAG,search_input);
        }else{std::cout<<"unknown cmd or adress book is empty, add contact;\n";}
    }

    return 0;
}
