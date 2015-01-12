#ifndef ACHARACTER_HPP
# define ACHARACTER_HPP

# include "AGameEntity.hpp"
# include "Missile.hpp"
# include "Position.hpp"
# include "Console.hpp"

class ACharacter : public AGameEntity
{
	public:
		ACharacter(int x, int y, int frate, int speed, e_type type);
		ACharacter(ACharacter const & src);
		virtual ~ACharacter( void );
		ACharacter &	operator=(ACharacter const & rhs);

		virtual Missile *	fireMissile(std::string pattern) = 0;
		int					getFireRate(void) const;
		int					getMaxFireRate(void) const;
		int					getSpeed(void) const;
		int					getMaxSpeed(void) const;

	protected:
		ACharacter( void );
		int					_frate;
		int					_maxfrate;
		Position			_mslOrigin;
};

#endif /* ACHARACTER_HPP */
