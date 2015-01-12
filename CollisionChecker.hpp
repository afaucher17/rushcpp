#ifndef COLLISIONCHECKER_HPP
# define COLLISIONCHECKER_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "AGameEntity.hpp"

class CollisionChecker
{
	public:
		static void		checkCollision(AGameEntity & alist);
		static void		checkCollision(AGameEntity & alist1, AGameEntity & alist2);

	private:
		CollisionChecker( void );
		CollisionChecker(CollisionChecker const & src);
		CollisionChecker &	operator=(CollisionChecker const & rhs);
		virtual ~CollisionChecker( void );
};

#endif /* COLLISIONCHECKER_HPP */
