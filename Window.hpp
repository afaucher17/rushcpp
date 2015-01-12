#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <ncurses.h>
# include "Console.hpp"

class Window
{
	public:
		Window(int const x, int const y, int const h, int const w);
		Window(Window const & src);
		~Window( void );

		Window &			operator=(Window const & rhs);

		void				initWindow(void);
		void				refreshWindow(void);

		int					getX(void) const;
		int					getY(void) const;
		int					getH(void) const;
		int					getW(void) const;
		WINDOW 				*getWindow(void) const;
	private:
		Window( void );

		int					_clock;
		int					_x;
		int					_y;
		int					_h;
		int					_w;
		WINDOW				*_window;
};

#endif /* WINDOW_HPP */
