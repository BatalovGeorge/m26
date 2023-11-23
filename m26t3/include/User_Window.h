#ifndef USER_WINDOW_H
#define USER_WINDOW_H

#include <iostream>
#include <vector>

class User_Window
{
private:
    std::vector<unsigned> _scale;
    std::vector<unsigned> _upL_pos;

public:
    User_Window();
    void set_newParams(unsigned& w_h,unsigned& w_w); //resize
    void set_newCoordinate(unsigned& upL_h,unsigned& upL_w); //move

    const std::vector<unsigned> &scale() const;
    const std::vector<unsigned> &upL_pos() const;
};
#endif // USER_WINDOW_H
