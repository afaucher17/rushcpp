#ifndef OBSTACLE_HPP
# define OBSTACLE_HPP

# include "AGameEntity.hpp"

class Obstacle : public AGameEntity
{
	public:
		Obstacle(Obstacle const & src);
		~Obstacle( void );
		Obstacle &	operator=(Obstacle const & rhs);

		virtual void		refresh(void);
		virtual void		destroy(void);

	private:
		Obstacle( void );
};

#endif /* OBSTACLE_HPP */
