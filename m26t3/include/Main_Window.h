#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <sstream>

#include "User_Window.h"

static const int window_height  = 80;
static const int window_width   = 50;

class Main_Window
{
public:
    User_Window usr;
    bool is_digits(std::string& str);
    void display(User_Window& window);
    void invoke_newParams( void (*func)(unsigned,unsigned),std::string &msg_output);
};
#endif // MAIN_WINDOW_H
