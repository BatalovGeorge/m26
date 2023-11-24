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
    std::stringstream input_data(Main_Window *main_win, std::string &msg_output);
    bool check_outOfBounds(User_Window& window);
};
#endif // MAIN_WINDOW_H
