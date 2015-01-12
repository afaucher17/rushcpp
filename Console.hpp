#ifndef CONSOLE_HPP
# define CONSOLE_HPP
#include <iostream>
#include <ncurses.h>
#include <cstdlib>


class Console
{
	public:
		Console( void );
		Console(WINDOW * debug);
		Console(Console const & src);
		~Console( void );
		Console &	operator=(Console const & rhs);

		static void		log(std::string, int color);
	private:
		static WINDOW *	_debug;
};

#endif /* CONSOLE_HPP */
