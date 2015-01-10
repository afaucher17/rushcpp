#ifndef SPRITE_HPP
# define SPRITE_HPP

class Sprite
{
	public:
		Sprite(std::string sprite[]);
		Sprite(Sprite const & src);
		~Sprite( void );
		Sprite &	operator=(Sprite const & rhs);

		std::string		*get() const;

	private:
		Sprite( void );
		std::string		sprite[];
};

#endif /* SPRITE_HPP */
