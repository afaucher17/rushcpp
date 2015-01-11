#ifndef AGAMEENTITY_HPP
# define AGAMEENTITY_HPP

class AGameEntity
{
	public:
		AGameEntity(int x, int y, int wdt, int hei, Sprite const & sprite);
		AGameEntity(AGameEntity const & src);
		virtual ~AGameEntity( void );

		AGameEntity &			operator=(AGameEntity const & rhs);

		Position &				getPosition(void) const;
		Hitbox &				getHitbox(void) const;
		Sprite &				getSprite(void) const;
		int						getSpeed() const;

		virtual void			refresh() = 0;
		virtual void			destroy(void) = 0;

		std::string				toString(void) const;

	protected:
		Position				_pos;
		Hitbox					_hb;
		Sprite					_sp;
		int						_dead;
		int						_speed;
		int						_maxspeed;

	private:
		AGameEntity( void );
};

std::ostream &					operator<<(std::ostream & o, AGameEntity const & rhs);

#endif /* AGAMEENTITY_HPP */
