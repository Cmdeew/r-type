#ifndef _OBJECT_H_
# define _OBJECT_H_

class	Object
{
private:
	char	m_id;
	char	m_x;
	char	m_y;
	char	m_type;
public:
	Object(char id, char x, char y, char type);
	~Object();
	void	move();
	char	getId();
	char	getX();
	char	getY();
	char	getType();
};

#endif // _OBJECT_H_