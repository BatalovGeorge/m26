#include "Music_player.h"
#include <vector>

bool Music_player::getIs_playing() const
{
    return is_playing;
}

void Music_player::setIs_playing(bool newIs_playing)
{
    is_playing = newIs_playing;
}

Music_player::Music_player()
{
    double max_duration=20;
    srand(std::time(nullptr));
    start_playing = std::time(nullptr);

    //here TODO: put some logic for dl music list from some data
    std::string track="track";
    for(int rand_songs=1;rand_songs<3;rand_songs++)
    {
        double random_song = rand()%((int)max_duration+1);
        auto rand_name=track+std::to_string(rand_songs);
        Track *m1 = new Track(rand_name,random_song);
        std::pair<std::string,Track> track_queue(m1->get_name(),*m1);
        playlist.insert(track_queue);
        delete m1;
    }


    Track *m2 = new Track("m2",max_duration);
    std::pair<std::string,Track> track_queue2(m2->get_name(),*m2);
    playlist.insert(track_queue2);

    Track *m3 = new Track("m3",max_duration);
    std::pair<std::string,Track> track_queue3(m3->get_name(),*m3);
    playlist.insert(track_queue3);

    delete m2;
    delete m3;
}

void Music_player::play()
{

        std::time_t localTime_queue = std::time(nullptr);
        localTime_queue<=start_playing?setIs_playing(true):setIs_playing(false);

        if(!getIs_playing())
        {
        std::cout<<"input name of the song:";
        std::cout<<"Current playlist:";

        for (auto& song : playlist)
        {
            std::cout<<"\t"<<std::endl;
            song.second.show_track_fields();
        }
        std::cout<<std::endl;
        playlist_iter=playlist.begin();

        std::string input_song;
        std::cin>>input_song;
        std::cin.sync();

        if(playlist.find(input_song)!=playlist.end())
        {
         std::cout<<"\tplaying: "<<playlist_iter->first<<std::endl;
         std::time(&start_playing);
         start_playing+=(std::time_t)playlist_iter->second.get_duration();

         }else{
            std::cout<<"\tthere's no available track with this name"<<std::endl;
            }
        }
}

void Music_player::pause()
{
    std::time_t now = std::time(nullptr);
    now<=start_playing?setIs_playing(true):setIs_playing(false);
    if(getIs_playing())
    {
        int playing_time = start_playing - now - (int) playlist_iter->second.get_duration();
        std::cout<<"PAUSE track:"<<playlist_iter->first<<"; time duration: ";
        std::cout<<std::abs(playing_time)/60<<":"<<std::abs(playing_time)%60<<std::endl;
    }else{std::cout<<"no more track to set pause"<<std::endl;}
}

void Music_player::next()
{
  int playlist_sz = playlist.size()-1;

  std::srand(std::time(nullptr));
  int random_song = rand()%(playlist_sz+1);
  std::cout<<random_song<< " = random num "<<std::endl;
  std::vector<std::string> buff_list;
  for(auto &it:playlist)
  {
    buff_list.push_back(it.first);
  }
  playlist_iter = playlist.begin();
  playlist_iter = playlist.find(buff_list.at(random_song));

  std::time(&start_playing);
  start_playing+=(std::time_t)playlist_iter->second.get_duration();
  std::cout<<"\tplaying: "<<playlist_iter->first<<std::endl;
}

void Music_player::stop()
{
    std::time_t now = std::time(nullptr);
    now<=start_playing?setIs_playing(true):setIs_playing(false);
    if(getIs_playing())
    {
        std::time(&start_playing);
        int playing_time = start_playing - now - (int) playlist_iter->second.get_duration();
        std::cout<<"STOP track:"<<playlist_iter->first<<"; time duration: ";
        std::cout<<std::abs(playing_time)/60<<":"<<std::abs(playing_time)%60<<std::endl;
    }else{std::cout<<"no more track to stop"<<std::endl;}
}
