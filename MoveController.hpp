#ifndef MOVECONTROLLER_HPP
# define MOVECONTROLLER_HPP

# include <string>
# include <sstream>
# include <iostream>
# include "Position.hpp"
# include "Pattern.hpp"
# include "Console.hpp"

class MoveController
{
	public:
		MoveController(Position & position, Pattern & pattern);
		MoveController(MoveController const & src);
		~MoveController( void );
		MoveController &	operator=(MoveController const & rhs);
		std::string	toString() const;

		void				move();

		MoveController( void );

	private:
		Position *			_position;
		Pattern *			_pattern;
		void				moveLeft();
		void				moveRight();
		void				moveUp();
		void				moveDown();
		void				moveNothing();

};

typedef void 	(MoveController::*f)(void);
std::ostream &		operator<<(std::ostream & o, MoveController const & rhs);

#endif /* MOVECONTROLLER_HPP */
