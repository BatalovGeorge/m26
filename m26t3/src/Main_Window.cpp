#include "Main_Window.h"

bool Main_Window::is_digits(std::string& str)
{
    for (int ch_pos=0;ch_pos<str.size();ch_pos++)
    {
        if(str[ch_pos]==' '){ch_pos++;}
        if (!isdigit(str[ch_pos]))
        {
              std::cout<<str<< " is not a digit" << std::endl;
            return false;
        }
    }
    return true;
}

void Main_Window::invoke_newParams(void (*set_newParams)(unsigned, unsigned), std::string &msg_output)
{
//msg_output = "input height and width of the window: (20 20)";                set_newParams()
//msg_output = "input height and width up left corner pos to move window: (20 20)"; set_newCoord()

    std::string input_coordinates;
    unsigned coord_h, coord_w;
    std::cout<<msg_output;
    getline(std::cin,input_coordinates);
    if(is_digits(input_coordinates))
    {
        std::stringstream ss(input_coordinates);
        ss>>coord_h>>coord_w;
        set_newParams(coord_h,coord_w);
    }else{std::cout<<"unexpected input:"<<input_coordinates<<std::endl;}
}

void Main_Window::display(User_Window& window)
{
    int buff;
    for(int column=0;column<window_width;column++)
    {
        for(int line=0;line<window_height;line++)
        {
                   std::cout<<"0";
                   if(line==window.upL_pos().at)
                   if(line==window_height-1){std::cout<<std::endl;}
        }
    }
}
