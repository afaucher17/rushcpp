
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
		Console::log("You left. How disappointing...", 2);
		this->_status = 2;
	}
}

void				Game::_isOver()
{
	if (this->_player.isDead())
	{
		Console::log("I'd just like to point out that you were given every opportunity to succeed. There was even going to be a party for you. A big party that all your friends were invited to. [...] All your other friends couldn't come either because you don't have any other friends. Because of how unlikable you are. It says so here in your personnel file: Unlikable. Liked by no one. A bitter, unlikable loner whose passing shall not be mourned. Shall not be mourned. That's exactly what it says. Very formal. Very official. It also says you were adopted. So that's funny, too.", 7);
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
