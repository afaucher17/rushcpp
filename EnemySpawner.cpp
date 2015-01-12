
#include "EnemySpawner.hpp"

EnemySpawner::EnemySpawner( void ) : _speed(0), _maxspeed(10), _pattern(NULL)
{
	std::string		*tpattern = new std::string[1];
	std::srand(time(0));

	tpattern[0] = "3";
	this->_pattern = tpattern;

	return ;
}

EnemySpawner::EnemySpawner(EnemySpawner const & src)
{
	*this = src;
	return ;
}

EnemySpawner::~EnemySpawner( void )
{
	delete [] this->_pattern;
}

void			EnemySpawner::setWindow( Window const & win)
{
	this->_winwdth = win.getW();
	this->_winhgt = win.getH();
	return ;
}

EnemySpawner &	EnemySpawner::operator=(EnemySpawner const & rhs)
{
	this->_winwdth = rhs._winwdth;
	this->_winhgt = rhs._winhgt;
	this->_speed = rhs._speed;
	this->_maxspeed = rhs._maxspeed;
	return *this;
}

Enemy const &		EnemySpawner::refresh(void)
{
	Enemy *	tmp = NULL;

	if (this->_speed == 0)
	{
		this->_speed = this->_maxspeed;
		if (Enemy::enemyCount < 20)
		{
			tmp = new Enemy(this->_winwdth - 5, (std::rand() %
			(this->_winhgt - 9)) + 5, 300, std::rand() % 2 + 1, "33313331333133313332333233323332");
		}
	}
	else
		this->_speed--;
	return *tmp;
}
