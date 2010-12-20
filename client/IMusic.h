#ifndef IMUSIC_H
#define IMUSIC_H

class	IMusic
{
  virtual void	LoadMusic() = 0;
  virtual void	PlayMusic() = 0;
  virtual void	StopMusic() = 0;
  virtual void	PauseMusic() = 0;
};

#endif //IMUSIC_H
