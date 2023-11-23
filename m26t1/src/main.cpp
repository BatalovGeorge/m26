#include <iostream>
#include "Track.h"
#include "Music_player.h"

int main()
{
    Music_player *player = new Music_player();

    while(true)
    {
        std::cout<<"Enter cmd: play pause next stop:";
        std::string user_cmd;
        std::cin>>user_cmd;

        if(user_cmd=="play"){               player->play();}
        else if(user_cmd=="pause"){         player->pause();}
        else if(user_cmd=="next"){          player->next();}
        else if(user_cmd=="stop"){          player->stop();}
        else if(user_cmd=="exit")
        {
            std::cout<<"EXIT";
            delete player;
            exit(0);
        }else{std::cout<<"unknown cmd: "<<user_cmd<<std::endl;}
    }





    return 0;
}
