#ifndef WINDOW_HPP
# define WINDOW_HPP

class Window
{
	public:
		Window(int const x, int const y);
		Window(Window const & src);
		~Window( void );

		Window &			operator=(Window const & rhs);

		void				initWindow(void);
		void				refreshWindow(void);

		int					getX(void) const;
		int					getY(void) const;

	private:
		Window( void );

		int					_clock;
		int					_x;
		int					_y;
};

#endif /* WINDOW_HPP */
