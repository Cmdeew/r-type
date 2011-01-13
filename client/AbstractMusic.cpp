#include "AbstractMusic.h"

AbstractMusic::AbstractMusic()
{
  _idSongPlayed = 0;
  LoadMusic();
}

void	AbstractMusic::LoadMusic()
{
  std::ifstream	file;
  std::string	buf;
  sf::Music	*Music;

  file.open(CONF_SONG);
  if (file)
    {
      while (getline(file, buf))
	{
	  Music = new sf::Music;
	  buf = "./music/" + buf;
	  if (!Music->OpenFromFile(buf.c_str()))
	    {
	      std::cerr << "Error: " << buf << " no such file or directory ..." << std::endl;
	    }
	  else
	    _lMusic.push_back(Music);
	}
      file.close();
    }
}

void	AbstractMusic::PlayMusic()
{
  std::list<sf::Music *>::iterator	it;
  int					count;
  sf::Music				*Music;
 

  count = 0;
  it = _lMusic.begin();
  if (!_lMusic.empty())
    {
      if (_idSongPlayed == 0)
	{
	  Music = *it;
	  Music->Play();
	  _idSongPlayed = 1;
	}
      else
	{
	  while (count != _idSongPlayed - 1 && it != _lMusic.end())
	    {
	      count++;
	      it++;
	    }
	  Music = *it;
	  if (Music->GetStatus() != sf::Music::Playing)
	    {
	      it++;
	      if (it == _lMusic.end())
		{
		  it = _lMusic.begin();
		  _idSongPlayed = 1;
		}
	      else
		_idSongPlayed = count + 2;
	      Music = *it;
	      Music->Play();
	    }
	}
    }
}

void	AbstractMusic::StopMusic()
{

  std::list<sf::Music *>::iterator	it;
  sf::Music				*Music;
  int	flag = 1;

  while (flag == 1)
    {
      flag = 0;
      for(it = _lMusic.begin();it != _lMusic.end();it++)
	{
	  Music = *it;
	  Music->Stop();
	  _lMusic.erase(it);
	  delete(Music);
	  flag = 1;
	  break;
	}
    }
}

void	AbstractMusic::PauseMusic()
{

}

