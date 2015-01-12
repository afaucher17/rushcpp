#ifndef INTERVAL_HPP
# define INTERVAL_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Console.hpp"

class Interval
{
	public:
		Interval( void );
		Interval(Interval const & src);
		virtual ~Interval( void );
		Interval &	operator=(Interval const & rhs);
		std::string	toString() const;

		void			refresh();
		unsigned int	value() const;

	private:
		unsigned int	_initial;

};

std::ostream &		operator<<(std::ostream & o, Interval const & rhs);

#endif /* INTERVAL_HPP */
