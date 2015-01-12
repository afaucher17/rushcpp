#include <iostream>
#include "Obstacle.hpp"

Obstacle::Obstacle(int x, int y, int spe) : AGameEntity(x, y, spe, NEUTRAL)
{
	std::string tsprite[] = { "#" };
	this->_hb.setWidth(0);
	this->_hb.setHeight(0);
	this->_sp.set(tsprite, 1);
}

Obstacle::Obstacle(Obstacle const & src) : AGameEntity(src)
{
	
	*this = src;
}

Obstacle::~Obstacle( void )
{
	
}

Obstacle &		Obstacle::operator=(Obstacle const & rhs)
{
	AGameEntity::operator=(rhs);
	return *this;
}

void			Obstacle::collidesWith(AGameEntity const & ge)
{
	(void)ge;
	return ;
}

void			Obstacle::refresh(void)
{
	int			thisx;
	int			thisy;

	if (this->_speed == 0)
	{
		DisplaySprite::erase(this->_sp, this->_pos, AGameEntity::_window);
		thisx = this->_pos.getX();
		thisy = this->_pos.getY();
		this->_speed = this->_maxspeed;
		this->_pos.update(--thisx, thisy);
		DisplaySprite::display(this->_sp, this->_pos, 5,AGameEntity::_window);
	}
	else
		this->_speed--;
}

void			Obstacle::destroy(void)
{
	this->_dead = 1;
}

Obstacle::Obstacle( void )
{
	
}

