#ifndef OBSTACLE_HPP
# define OBSTACLE_HPP

# include "AGameEntity.hpp"

class Obstacle : public AGameEntity
{
	public:
		Obstacle(int x, int y, int spe);
		Obstacle(Obstacle const & src);
		~Obstacle( void );
		Obstacle &			operator=(Obstacle const & rhs);

		virtual void		collidesWith(AGameEntity const & ge);

		virtual void		refresh(void);
		virtual void		destroy(void);

		std::string			toString(void) const;

	private:
		Obstacle( void );
};

#endif /* OBSTACLE_HPP */
