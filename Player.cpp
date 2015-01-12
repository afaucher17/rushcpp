
#include "ACharacter.hpp"
#include "Player.hpp"

Player::Player() : ACharacter(5, 20, 0, 3, ALLY), _quit(false), _life(3)
{
	std::string *tsprite = new std::string[5];

	tsprite[0] = "/---\\";
	tsprite[1] = "  |  ";
	tsprite[2] = " (o) ";
	tsprite[3] = "  |  ";
	tsprite[4] = "\\---/";
	this->_hb.setWidth(2);
	this->_hb.setHeight(4);
	this->_sp.set(tsprite, 5);
	this->_mslOrigin.update(this->_hb.getWidth() + 1, this->_hb.getHeight() / 2);
}

Player::Player(Player const & src) : ACharacter(src)
{
	*this = src;
	return ;
}

Player::~Player( void )
{
}

Player &		Player::operator=(Player const & rhs)
{
	AGameEntity::operator=(rhs);
	this->_controller = rhs._controller;
	return *this;
}

void			Player::collidesWith(AGameEntity const & ge)
{
	if (this->_type != ge.getType())
		this->_life--;
	if (this->_life <= 0)
		this->_dead = true;
}

bool			Player::_getInput(void)
{
	int			ch = getch();

	if (ch == KEY_UP)
		return this->_applyInput(0, -1);
	else if (ch == KEY_DOWN)
		return this->_applyInput(0, 1);
	else if (ch == KEY_RIGHT)
		return this->_applyInput(1, 0);
	else if (ch == KEY_LEFT)
		return this->_applyInput(-1, 0);
	else if (ch == 27)
		this->_quit = true;
	else if (ch == ' ')
	{
		this->fireMissile("4");
		return true;
	}
	return false;
}

int				Player::getLife() const
{
	return this->_life;
}

void			Player::refresh(void)
{
	DisplaySprite::display(this->_sp, this->_pos, 4,AGameEntity::_window);
	if (this->_getInput() && this->_speed == 0)
	{
		this->_speed = this->_maxspeed;
	}
	else
		this->_speed = (this->_speed - 1) <= 0 ? 0 : this->_speed - 1;
	this->_frate = (this->_frate - 1) <= 0 ? 0 : this->_frate - 1;
}

bool				Player::isQuit(void) const
{
	return this->_quit;
}

Missile *			Player::fireMissile(std::string pattern)
{
	Missile *	temp;

	temp = NULL;
	if (this->_frate <= 0)
	{
		temp = new Missile(this->_mslOrigin + this->_pos, 0, pattern, ALLY);
		this->_frate = this->_maxfrate;
	}
	return (temp);
}

int					Player::_applyInput(int x, int y)
{
	DisplaySprite::erase(this->_sp, this->_pos, AGameEntity::_window);
	if (!(this->_pos.getY() + y <= 0
			|| this->_pos.getY() + y + this->_hb.getHeight() + 1 >= AGameEntity::_winY
			|| this->_pos.getX() + x <= 0
			|| this->_pos.getX() + x + this->_hb.getWidth() + 1 >= AGameEntity::_winX))
		this->_pos.update(this->_pos.getX() + x, this->_pos.getY() + y);
	DisplaySprite::display(this->_sp, this->_pos, 4,AGameEntity::_window);
	return true;
}
