#include <iostream>
#include <sstream>
#include "Hitbox.hpp"

Hitbox::Hitbox( void ) : _wth(0), _hei(0)
{}

Hitbox::Hitbox(int w, int h ) : _wth(w), _hei(h) {
}

Hitbox::Hitbox(Hitbox const & src) : _wth(src.getWidth()), _hei(src.getHeight())
{
	return ;
}

Hitbox &	Hitbox::operator=(Hitbox const & src) {
	this->_wth = src.getWidth();
	this->_hei = src.getHeight();
	return *this;
}

int				Hitbox::getWidth() const
{
	return this->_wth;
}

void			Hitbox::setWidth(int w)
{
	this->_wth = w;
	return ;
}

int				Hitbox::getHeight() const
{
	return this->_hei;
}

void			Hitbox::setHeight(int h)
{
	this->_hei = h;
	return ;
}

std::string		Hitbox::toString(void) const {
	std::stringstream	buff;

	buff << "HB:: width = " <<this->_wth <<"; height = "<< this->_hei <<std::endl;
	return buff.str();
}

Hitbox::~Hitbox( void )
{
}

std::ostream &	operator<<(std::ostream & o, Hitbox const & rhs) {
	o << rhs.toString();
	return o;
}
