#ifndef PATTERN_HPP
# define PATTERN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include "Console.hpp"

enum	e_direction { NONE = 0, UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4};

class Pattern
{
	public:
		Pattern( void );
		Pattern(std::string const & pattern);
		Pattern(Pattern const & src);
		~Pattern( void );
		Pattern &	operator=(Pattern const & rhs);
		std::string	toString() const;

		void			set(std::string pattern);

		e_direction	next();
		std::string		getPattern( void ) const;

	private:
		std::string	_pattern;
		int			_current;
		int			_last;
};

std::ostream &			operator<<(std::ostream & o, Pattern const & rhs);

#endif /* PATTERN_HPP */
