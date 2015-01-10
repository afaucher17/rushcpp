#ifndef PATTERN_HPP
# define PATTERN_HPP

enum	e_direction = { NONE = 1, UP, DOWN, LEFT, RIGHT }
class Pattern
{
	public:
		Pattern(std::string pattern);
		Pattern(Pattern const & src);
		~Pattern( void );
		Pattern &	operator=(Pattern const & rhs);

		e_direction	next();

	private:
		std::string	_pattern;
		int			_current;
		Pattern( void );
};

#endif /* PATTERN_HPP */
