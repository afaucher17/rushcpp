#ifndef FPS_HPP
# define FPS_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Interval.hpp"
# include "Console.hpp"

class Fps
{
	public:
		Fps( void );
		Fps(Fps const & src);
		~Fps( void );
		Fps &	operator=(Fps const & rhs);
		std::string	toString() const;

		void			update();
		unsigned int	get() const;

	protected:
		unsigned int	_m_fps;
		unsigned int	_m_fpscount;
		Interval		_m_fpsinterval;

};

std::ostream &		operator<<(std::ostream & o, Fps const & rhs);

#endif /* FPS_HPP */
