#ifndef _OBJECT_H_
# define _OBJECT_H_

class Session;

class	Object
{
private:
	char	m_id;
	char	m_x;
	char	m_y;
	char	m_type;
	int	m_lim; /*limite de deplcement*/
public:
	Object();
	Object(char id, char x, char y, char type);
	~Object();
	void	move(Session *s);
	char	getId();
	char	getX();
	char	getY();
	char	getType();
};

#endif // _OBJECT_H_
