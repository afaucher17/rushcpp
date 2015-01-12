#include <iostream>
#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy(int x, int y, int frate, int speed, std::string pattern) : ACharacter(x, y, frate, speed, ENEMY)
{
	std::string *tsprite = new std::string[3];

	tsprite[0] = " ./H";
	tsprite[1] = "<HHH";
	tsprite[2] = " .\\H";
	this->_pattern.set(pattern);
	this->_moveCtrl = MoveController(this->_pos, this->_pattern);
	this->_hb.setWidth(3);
	this->_hb.setHeight(2);
	this->_sp.set(tsprite, 3);
	this->_mslOrigin.update(this->_hb.getWidth() - 5, this->_hb.getHeight() / 2 + 1);
	Enemy::enemyCount++;
	return;
}

Enemy::Enemy(Enemy const & src) : ACharacter(src)
{
	*this = src;
	Enemy::enemyCount++;
	return;
}

Enemy::~Enemy( void )
{

	Enemy::enemyCount--;
	return;
}

Enemy &	Enemy::operator=(Enemy const & rhs)
{
	this->ACharacter::operator=(rhs);
	this->_pattern = rhs._pattern;
	return *this;
}

void		Enemy::_checkOutOfBound()
{
	if (this->_pos.getX() <= -3)
		this->_dead = true;
}


void		Enemy::collidesWith(AGameEntity const & ge)
{
	this->AGameEntity::collidesWith(ge);
	if (this->_dead)
		Game::addScore(100);
}

void		Enemy::refresh(void)
{
	if (this->_speed == 0)
	{
		DisplaySprite::erase(this->_sp, this->_pos, AGameEntity::_window);
		this->_moveCtrl.move();
		this->_checkOutOfBound();
		this->_speed = this->_maxspeed;
		if (!this->_dead)
			DisplaySprite::display(this->_sp, this->_pos, 2,AGameEntity::_window);
	}
	else
		this->_speed--;
	this->fireMissile("3");
}

Missile *		Enemy::fireMissile(std::string pattern)
{
	Missile *	temp;

	temp = NULL;
	if (this->_frate <= 0)
	{
		temp = new Missile(this->_mslOrigin + this->_pos, 0, pattern, ENEMY);
		this->_frate = this->_maxfrate;
	}
	this->_frate = (this->_frate - 1) <= 0 ? 0 : this->_frate - 1;
	return (temp);
}

Enemy::Enemy(void)
{
	return;
}

int			Enemy::enemyCount = 0;
