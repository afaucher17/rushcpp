
#include "Console.hpp"

WINDOW * Console::_debug = NULL;

Console::Console( void ) {}

Console::Console(WINDOW * debug)
{
	Console::_debug = debug;

	return ;
}

Console::Console(Console const & src)
{

	*this = src;
	return ;
}

Console::~Console( void )
{

}

Console &	Console::operator=(Console const & rhs)
{
	this->_debug = rhs._debug;
	return *this;
}

void           Console::log(std::string message, int color)
{
	int y, maxY, maxX;

	maxX = getmaxx(Console::_debug);
	maxY = getmaxy(Console::_debug);
	y = getcury(Console::_debug);
	if (y + 1 == maxY)
		y = 1;
	if (y == 0)
		y++;
	wattron(Console::_debug, COLOR_PAIR(color));
	mvwhline(Console::_debug, y, 1, ' ', maxX - 10);
	wmove(Console::_debug, y, 1);
	mvwprintw(Console::_debug, y, 1, message.c_str());
	wmove(Console::_debug, y + 1, 1);
	wattroff(Console::_debug, COLOR_PAIR(color));

}

