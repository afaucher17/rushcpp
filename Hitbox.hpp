#ifndef HITBOX_HPP
# define HITBOX_HPP
# include <iostream>

class Hitbox
{
	public:
		Hitbox( void );
		Hitbox(int wth, int hei);
		Hitbox(Hitbox const & src);
		~Hitbox( void );
		Hitbox &	operator=(Hitbox const & rhs);

		int			getWidth() const;
		void		setWidth(int w);
		int			getHeight() const;
		void		setHeight(int h);
		std::string	toString(void) const;

	private:
		int			_wth;
		int			_hei;
};

std::ostream &	operator<<(std::ostream & o, Hitbox const & rhs);

#endif /* HITBOX_HPP */
