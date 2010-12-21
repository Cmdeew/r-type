#ifndef ABSTRACTMUSIC_H
#define ABSTRACTMUSIC_H

#define CONF_SONG "./music/music.list"
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <list>
#include "IMusic.h"

class	AbstractMusic : public IMusic
{
 private:
  std::list<sf::Music *>	_lMusic;
  int			_idSongPlayed;
  public:
  AbstractMusic();
  void	LoadMusic();
  void	PlayMusic();
  void	StopMusic();
  void	PauseMusic();
};


#endif //!ABSTRACTMUSIC_H
