#ifndef ENEMYSPAWNER_HPP
# define ENEMYSPAWNER_HPP

# include <string>
# include <cstdlib>
# include "Enemy.hpp"
# include "Window.hpp"

class EnemySpawner
{
	public:
		EnemySpawner( void );
		EnemySpawner(EnemySpawner const & src);
		~EnemySpawner( void );
		EnemySpawner &	operator=(EnemySpawner const & rhs);

		void			setWindow( Window const & win );

		Enemy const &	refresh(void);

	private:
		int					_winwdth;
		int					_winhgt;
		int					_speed;
		int					_maxspeed;
		std::string	const *	_pattern;
};

#endif /* ENEMYSPAWNER_HPP */
