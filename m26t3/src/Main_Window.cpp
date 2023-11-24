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


std::stringstream Main_Window::input_data(Main_Window *main_win, std::string &msg_output)
{
    std::string input_coordinates;
    unsigned coord_h, coord_w;
    std::cout<<msg_output;
    getline(std::cin,input_coordinates);
    if(is_digits(input_coordinates))
    {
        std::stringstream ss(input_coordinates);
        return ss;
    }else{std::cout<<"unexpected input:"<<input_coordinates<<std::endl;}
}

bool Main_Window::check_outOfBounds(User_Window& window)
{
    if(window.upL_pos().at(1)+window.scale().at(1) >window_width
            || window.upL_pos().at(0)+window.scale().at(0) >window_height
            || window.upL_pos().at(0) > window_height
            || window.upL_pos().at(1) > window_width
            || window_height - window.upL_pos().at(0)< window.scale().at(0)
            || window_width - window.upL_pos().at(1)< window.scale().at(1))
    {
      std::cout<<"out of bounds\n";return false;
    }else
    { std::cout<<"in bounds\n"; return true;}
}

void Main_Window::display(User_Window& window)
{
    if(check_outOfBounds(window))
    {
        int pos_h=window.upL_pos().at(0);
        int pos_w=window.upL_pos().at(1);

        for(int column=1;column<=window_height;column++)
        {
            for(int line=1;line<=window_height;line++)
            {
                if(column==pos_h && line==pos_w
                        &&window.upL_pos().at(1)+window.scale().at(1)!=pos_w
                        &&window.upL_pos().at(0)+window.scale().at(0)!=pos_h)
                {
                        std::cout<<"1";
                        pos_w++;

                }else{std::cout<<"0";}

                if(line==window_height){
                    std::cout<<std::endl;
                }

                if(window.upL_pos().at(1)+window.scale().at(1)==pos_w)
                {
                    pos_h++;
                    pos_w=window.upL_pos().at(1);
                }
            }
        }
    }


}
