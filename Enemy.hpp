#ifndef ENEMY_HPP
# define ENEMY_HPP
# include "ACharacter.hpp"
# include "MoveController.hpp"

class Enemy : public virtual ACharacter
{
	public:
		Enemy(int x, int y, int frate, int speed, std::string pattern);
		Enemy(Enemy const & src);
		virtual ~Enemy( void );
		Enemy &					operator=(Enemy const & rhs);

		Pattern &				getPattern(void) const;

		virtual void			refresh(void);
		virtual Missile *		fireMissile(std::string pattern);
		virtual	void			collidesWith(AGameEntity const & ge);

		static int				enemyCount;

	protected:
		Pattern					_pattern;
		Position				_mslOrigin;
		MoveController			_moveCtrl;

	private:
		void			_checkOutOfBound();
		Enemy(void);
};

#endif /* ENEMY_HPP */
