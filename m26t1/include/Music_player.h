#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H
/*
 * Сам плеер тоже реализуйте с помощью класса.
 * Внутри он должен содержать список доступных записей и нужные для логики
 * работы плеера поля.
Команда play запрашивает у пользователя название записи для воспроизведения и начинает её
воспроизведение. Воспроизведение симулируется с помощью вывода в консоль всей информации о записи.
Если произведение какой-то записи уже начато, ничего не происходит.

Команда pause. Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль.
Если запись уже на паузе или не воспроизводится вовсе, ничего не происходит.

Команда next переходит к следующей записи для воспроизведения. Запись при этом выбирается случайно,
 как будто плеер работает в режиме shuffle.

Команда stop прекращает воспроизведение текущей записи, если таковая имеется.
Об этом выводится сообщение в консоль. Два раза остановить воспроизведение невозможно,
так что команда должна срабатывать только в первом случае.

Команда exit — выход из программы.
*/
#include <map>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>

#include "Track.h"

class Music_player
{
    std::multimap<std::string,Track> playlist;
    bool is_playing;
    std::time_t start_playing;
    std::multimap<std::string,Track>::iterator playlist_iter;
   public:
    Music_player();
    void play();
    void pause();
    void next();
    void stop();
    bool getIs_playing() const;
    void setIs_playing(bool newIs_playing);
};
#endif // MUSIC_PLAYER_H
