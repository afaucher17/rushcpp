
#include "Game.hpp"

Game::Game( void )
{

	return ;
}

Game::Game( Window const & win ) : _status(0)
{
	this->_spawner.setWindow(win);
	AGameEntity::setWindow(win);

	return ;
}

Game::Game(Game const & src)
{

	*this = src;
	return ;
}

Game::~Game( void )
{

}

Game &	Game::operator=(Game const & rhs)
{
	(void)rhs;
	return *this;
}

void				Game::addScore(int i)
{
	Game::_score += i;
}

std::string			Game::getScore()
{
	std::stringstream ostr;

	ostr << "Score : " << Game::_score;
	return ostr.str();
}

std::string			Game::getLife() const
{
	std::stringstream ostr;

	ostr << "Life : " << this->_player.getLife();
	return ostr.str();
}

void				Game::_refreshGameEntity()
{
	AGameEntity		*current;

	current = AGameEntity::getHead();
	(void)current;
	while (current)
	{
		current->refresh();
		current = current->getNext();
	}
}

void				Game::_deathCheck()
{
	AGameEntity		*current;
	AGameEntity		*save;

	current = AGameEntity::getHead();
	while (current)
	{
		save = current->getNext();
		if (current->isDead())
			delete current;
		current = save;
	}
}

void				Game::_isQuit()
{
	if (this->_player.isQuit())
	{
		Console::log("YA QUIT YA BASTARD !", 2);
		this->_status = 2;
	}
}

void				Game::_isOver()
{
	if (this->_player.isDead())
	{
		Console::log("YA LASE, NAAB !", 7);
		this->_status = 1;
	}
}

char				Game::getStatus() const
{
	return this->_status;
}

void				Game::refresh()
{
	this->_spawner.refresh();
	this->_refreshGameEntity();
	CollisionChecker::checkCollision(*AGameEntity::getHead());
	this->_isQuit();
	this->_isOver();
	if (!this->_status)
		this->_deathCheck();
	return ;
}

int			Game::_score = 0;
