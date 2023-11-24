/*Реализуйте симуляцию работы окна в визуальном интерфейсе пользователя.

Окно располагается на виртуальном экране монитора, размером 80 × 50 точек.
У окна есть несколько параметров, которые также задаются в пикселях: двумерные
координаты левого верхнего угла и размеры, ширина и высота.
Ширина и высота при этом не могут быть отрицательными, а координаты не могут выходить
за область экрана.

Пользователь взаимодействует с программой с помощью команд:

    Команда move принимает вектор, на который надо сместить окно на экране.
Сообщение с новыми координатами окна появляется на экране.

    Команда resize запрашивает из стандартного ввода новый размер окна.
После изменения размера сообщение с новым размером выводится на экране.

    Команда display выводит текущее изображение монитора в консоль.
0 — это пиксель вне области окна, 1 — с окном.
    Команда close закрывает окно, выход из программы.*/

#include "Main_Window.h"


int main()
{
    Main_Window* u_window= new Main_Window;
    while(true)
    {
        std::string input_cmd;
        std::cout<<"input cmd (move,resize,display,close): ";
        std::cin>>input_cmd;
        std::cin.sync();
        unsigned int coord_h,coord_w;
        if(input_cmd=="move")
        {

            std::string msg_output = "input height and width up left corner pos to move window: (20 20)";
            u_window->input_data(u_window,msg_output)>>coord_h>>coord_w;
            u_window->usr.set_newCoordinate(coord_h,coord_w);
        }
        else if(input_cmd=="resize")
        {
            std::string msg_output = "input height and width of the window: (20 20)";
            u_window->input_data(u_window,msg_output)>>coord_h>>coord_w;
            u_window->usr.set_newParams(coord_h,coord_w);
        }
        else if(input_cmd=="display")
        {
            u_window->display(u_window->usr);
        }

        else if(input_cmd=="close")
        {
            exit(0);
        }

        else{std::cout<<"unexpected input:\n";}
    }

    return 0;
}
