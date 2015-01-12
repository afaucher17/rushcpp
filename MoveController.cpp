
#include "MoveController.hpp"

MoveController::MoveController(Position & position, Pattern & pattern) : _position(&position), _pattern(&pattern)
{
	
	return ;
}

MoveController::MoveController(MoveController const & src)
{
	
	*this = src;
	return ;
}

MoveController::~MoveController( void )
{
	
}

MoveController &	MoveController::operator=(MoveController const & rhs)
{
	this->_position = rhs._position;
	this->_pattern = rhs._pattern;
	return *this;
}

std::string	MoveController::toString() const
{
	return "";
}

void				MoveController::moveLeft()
{
	this->_position->update(this->_position->getX() - 1, this->_position->getY());
	return ;
}

void				MoveController::moveRight()
{
	this->_position->update(this->_position->getX() + 1, this->_position->getY());
	return ;
}

void				MoveController::moveUp()
{
	this->_position->update(this->_position->getX(), this->_position->getY() - 1);
	return ;
}

void				MoveController::moveDown()
{
	this->_position->update(this->_position->getX(), this->_position->getY() + 1);
	return ;
}

void				MoveController::moveNothing()
{
	return ;
}


void				MoveController::move()
{
	e_direction d = this->_pattern->next();
	f a[5] =
	{
		&MoveController::moveNothing,
		&MoveController::moveUp,
		&MoveController::moveDown,
		&MoveController::moveLeft,
		&MoveController::moveRight,
	};
	(this->*a[static_cast<int>(d)])();
}

MoveController::MoveController( void ) : _position(NULL), _pattern(NULL)
{
	return ;
}

