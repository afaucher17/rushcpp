#ifndef ENEMY_HPP
# define ENEMY_HPP
# include "Character.hpp"

class Enemy : public ACharacter
{
	public:
		Enemy(int x, int y, std::string pattern);
		Enemy(Enemy const & src);
		virtual ~Enemy( void );
		Enemy &	operator=(Enemy const & rhs);

		virtual void		destroy(void);
		virtual void		refresh(void);

	protected:
		Pattern		_pattern;
	private:
		Enemy(void);
};

#endif /* ENEMY_HPP */
