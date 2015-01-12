#ifndef MISSILE_HPP
# define MISSILE_HPP

# include "AGameEntity.hpp"
# include "Pattern.hpp"
# include "MoveController.hpp"

class Missile : public AGameEntity
{
	public:
								Missile(int x, int y, int speed, std::string pattern, e_type type);
								Missile(Position pos, int speed, std::string pattern, e_type type);
								Missile(Missile const & src);
		virtual					~Missile( void );
		Missile &				operator=(Missile const & rhs);

		virtual void			refresh(void);
		virtual void			destroy(void);

		void					_checkOutOfBound();
		Pattern	const &			getPattern( void ) const;

	protected:
		Pattern					_pattern;
		MoveController			_moveCtrl;

	private:
		Missile( void );
};

#endif /* MISSILE_HPP */
