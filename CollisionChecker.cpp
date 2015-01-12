
#include "CollisionChecker.hpp"

void			CollisionChecker::checkCollision(AGameEntity & alist1, AGameEntity & alist2)
{
	if (alist1.getPosition() == alist2.getPosition())
	{
		alist1.collidesWith(alist2);
		alist2.collidesWith(alist1);
	}
	int x1 = alist1.getPosition().getX();
	int y1 = alist1.getPosition().getY();
	int x2 = alist2.getPosition().getX();
	int y2 = alist2.getPosition().getY();

	int w1 = alist1.getHitbox().getWidth();
	int w2 = alist2.getHitbox().getWidth();
	int h1 = alist1.getHitbox().getHeight();
	int h2 = alist2.getHitbox().getHeight();

	if ((((x1 <= x2 && x2 <= x1 + w1)
				|| (x1 <= x2 + w2 && x2 + w2 <= x1 + w1))
			|| ((x2 <= x1 && x1 <= x2 + w2)
				|| (x2 <= x1 + w1 && x1 + w1 <= x2 + w2)))
		&& (((y1 <= y2 && y2 <= y1 + h1)
				|| (y1 <= y2 + h2 && y2 + h2 <= y1 + h1))
			|| ((y2 <= y1 && y1 <= y2 + h2)
				|| (y2 <= y1 + h1 && y1 + h1 <= y2 + h2))))
	{
		alist1.collidesWith(alist2);
		alist2.collidesWith(alist1);
	}
	return ;
}

void			CollisionChecker::checkCollision(AGameEntity & alist)
{
	AGameEntity *current = &alist;
	if (!current || current->getNext() == NULL)
		return ;
	while ((current = current->getNext()))
	{
		CollisionChecker::checkCollision(alist, *current);
	}
	CollisionChecker::checkCollision(*(alist.getNext()));
}


CollisionChecker::CollisionChecker( void )
{
	return ;
}

CollisionChecker::CollisionChecker(CollisionChecker const & src)
{
	*this = src;
	return ;
}

CollisionChecker &	CollisionChecker::operator=(CollisionChecker const & rhs)
{
	(void)rhs;
	return *this;
}

CollisionChecker::~CollisionChecker( void )
{
	return ;
}

