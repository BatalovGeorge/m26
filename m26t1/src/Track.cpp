#include <Track.h>

Track::Track(std::string name,double &duration)
{

    this->_track_name=name;
    this->_duration=duration;
//    this->_start_play=*std::localtime(&t);
}

void Track::show_track_fields()
{
    std::cout<<"Track: "<<_track_name<<"; Duration: "<<(int)_duration/60<<":"<<((int)_duration)%60;
}

double Track::get_duration(){return _duration;}
std::string Track::get_name(){return _track_name;}

