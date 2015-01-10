#ifndef HITBOX_HPP
# define HITBOX_HPP

class Hitbox
{
	public:
		Hitbox(int wth, int hei);
		Hitbox(Hitbox const & src);
		~Hitbox( void );
		Hitbox &	operator=(Hitbox const & rhs);

		int			getWidth() const;
		int			getHeight() const;

	private:
		int			_wth;
		int			_hei;
		Hitbox( void );
};

#endif /* HITBOX_HPP */
