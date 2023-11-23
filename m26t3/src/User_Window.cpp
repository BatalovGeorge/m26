#include "User_Window.h"

User_Window::User_Window()
{
    _scale.push_back(0);
    _scale.push_back(0);

    _upL_pos.push_back(0);
    _upL_pos.push_back(0);
}

const std::vector<unsigned> &User_Window::scale() const
{
    return _scale;
}

const std::vector<unsigned> &User_Window::upL_pos() const
{
    return _upL_pos;
}


void User_Window::set_newParams(unsigned& w_h,unsigned& w_w)
{
    _scale.at(0) = w_h;//0 elem HEIGHT
    _scale.at(1) = w_w;//1 elem WIDTH
}

void User_Window::set_newCoordinate(unsigned &upL_h,unsigned &upL_w)
{
    _upL_pos.at(0) = upL_h;//0 elem HEIGHT
    _upL_pos.at(1) = upL_w;//1 elem WIDTH
}


