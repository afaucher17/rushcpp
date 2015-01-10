#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player
{
	public:
		Player(Player const & src);
		~Player( void );
		Player &	operator=(Player const & rhs);

		virtual void	destroy(void);
		virtual void	refresh(void);

	private:
		InputController	_controller;
		Player(void);
};

#endif /* PLAYER_HPP */
