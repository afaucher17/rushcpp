#ifndef ACHARACTER_HPP
# define ACHARACTER_HPP
# include "AGameEntity.hpp"

class ACharacter : public AGameEntity
{
	public:
		ACharacter(ACharacter const & src);
		virtual ~ACharacter( void );
		ACharacter &	operator=(ACharacter const & rhs);

		Missile	const	&fireMissile(void);
		int				getFireRate() const;
		int				getSpeed() const;

	protected:
		int				_frate;
		int				_maxfrate;
		int				_speed;
		int				_maxspeed;
	private:
		ACharacter( void );
};

#endif /* ACHARACTER_HPP */
