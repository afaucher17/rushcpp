#include <iostream>
#include <sstream>
#include "Sprite.hpp"

Sprite::Sprite(Sprite const & src)
{
	
	*this = src;
	return ;
}

Sprite::~Sprite( void )
{
	
	delete [] this->_sprite;
	return ;
}

Sprite &	Sprite::operator=(Sprite const & rhs)
{
	this->_sprite = rhs._sprite;
	this->_y = rhs._y;
	return *this;
}

std::string const *Sprite::get(void) const
{
	return this->_sprite;
}

int				Sprite::getY(void) const
{
	return this->_y;
}

void			Sprite::set(std::string const sprite[], int y)
{
	this->_sprite = sprite;
	this->_y = y;
	return ;
}

std::string		Sprite::toString(void) const {
	std::stringstream	buff;

	buff << "Sprite size: " <<this->_y <<"and it looks like: " << std::endl;
	for (int i = 0; i < this->_y; i++)
		buff << this->_sprite[i] <<std::endl;
	return buff.str();
}

Sprite::Sprite( void ) : _sprite(NULL), _y(0)
{
	
	return ;
}

std::ostream &	operator<<(std::ostream & o, Sprite const & rhs) {
	o << rhs.toString();
	return o;
}
