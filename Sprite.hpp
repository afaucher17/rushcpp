#ifndef SPRITE_HPP
# define SPRITE_HPP

# include <iostream>
# include "Console.hpp"

class Sprite
{
	public:
		Sprite( void );
		Sprite(Sprite const & src);
		~Sprite( void );
		Sprite &	operator=(Sprite const & rhs);

		std::string const *	get(void) const;
		int					getY(void) const;
		void				set(std::string const sprite[], int y);
		std::string			toString(void) const;

	private:
		std::string const *	_sprite;
		int					_y;
};

std::ostream &	operator<<(std::ostream & o, Sprite const & rhs);

#endif /* SPRITE_HPP */
