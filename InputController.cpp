#include <ncurses.h>
#include "InputController.hpp"
#include <iostream>

InputController::InputController(InputController const & src)
{
	*this = src;
}

InputController::~InputController( void )
{
}

InputController &	InputController::operator=(InputController const & rhs)
{
	(void)rhs;
	return *this;
}


int					InputController::getInput(void)
{
	return -1;
}

InputController::InputController( void )
{
}

