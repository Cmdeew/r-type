#ifndef	_MAP_
#define _MAP_

class	Map
{
	public:
		Map();
		~Map();
		void	UpdateMap(unsigned char lastX, unsigned char lastY, unsigned char x, unsigned char y, unsigned char id);
		void	DisplayCase(unsigned char x, unsigned char y);
	private:
		int _map[100][100];
};


#endif