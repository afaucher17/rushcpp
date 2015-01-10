#ifndef MISSILE_HPP
# define MISSILE_HPP

# include "AGameEntity.hpp"
class Missile : public AGameEntity
{
	public:
		Missile(int x, int y, std::string pattern, ACharacter const & owner)
		Missile(Missile const & src);
		~Missile( void );
		Missile &	operator=(Missile const & rhs);

		virtual void		refresh(void);
		virtual void		destroy(void);

	protected:
		Pattern		_pattern;
		ACharacter&	_owner;

	private:
		Missile( void );
};

#endif /* MISSILE_HPP */
