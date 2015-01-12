#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "ACharacter.hpp"
#include "InputController.hpp"

class Player : public ACharacter
{
	public:
		Player(void);
		Player(Player const & src);
		~Player( void );
		Player &					operator=(Player const & rhs);

		virtual void				refresh(void);
		bool						isQuit() const;
		int							getLife() const;
		virtual Missile *			fireMissile(std::string pattern);
		void						collidesWith(AGameEntity const & ge);

	private:
		InputController				_controller;
		bool						_quit;
		int							_life;
		bool						_getInput();
		int							_applyInput(int x, int y);
};

#endif /* PLAYER_HPP */
