#ifndef TRACK_H
#define TRACK_H
/*класс Track.
 * Полями этого класса должны быть: название, дата создания
 * (здесь вы можете использовать тип std::tm) и продолжительность записи в секундах.*/
#include <iostream>
#include <ctime>

class Track
{
private:
    std::string _track_name;
    double _duration;
    std::time_t _start_play;

public:
    Track(std::string name,double &duration);
    double get_duration();
    std::string get_name();
    void show_track_fields();
};

#endif // TRACK_H
