#include "AGameEntity.hpp"

AGameEntity::AGameEntity(int x, int y, int speed, e_type type) : _speed(0), _maxspeed(speed), _dead(false), _index(AGameEntity::_nb_inst++), _type(type)
{
	this->_pos.update(x, y);
	
	AGameEntity::pushFront(this);
	return ;
}

AGameEntity::AGameEntity(void) : _speed(0), _maxspeed(0), _dead(true)
{
	std::cout << "[CONSTRUCT] Game Entity" << std::endl;
	return ;
}

AGameEntity::AGameEntity(AGameEntity const & src) : _index(AGameEntity::_nb_inst++)
{
	
	*this = src;
	AGameEntity::pushFront(this);
	return ;
}

AGameEntity::~AGameEntity( void )
{
	
	deleteNode();
	return ;
}

AGameEntity &			AGameEntity::operator=(AGameEntity const & rhs)
{
	this->_dead = rhs._dead;
	this->_speed = rhs._speed;
	this->_maxspeed = rhs._maxspeed;
	return *this;
}

Position const &		AGameEntity::getPosition(void) const
{
	return this->_pos;
}

Hitbox const &			AGameEntity::getHitbox(void) const
{
	return this->_hb;
}

Sprite const &			AGameEntity::getSprite(void) const
{
	return this->_sp;
}

int						AGameEntity::getSpeed() const
{
	return this->_speed;
}

e_type					AGameEntity::getType() const
{
	return this->_type;
}

void					AGameEntity::collidesWith(AGameEntity const & ge)
{
	(void)ge;
	if (this->_type != ge._type)
	{
		this->_dead = true;
		DisplaySprite::erase(this->_sp, this->_pos, this->_window);
	}
}

AGameEntity *			AGameEntity::getNext() const
{
	return this->_next;
}

int						AGameEntity::getWinY()
{
	return AGameEntity::_winY;
}

int						AGameEntity::getWinX()
{
	return AGameEntity::_winX;
}

AGameEntity *			AGameEntity::getPrevious() const
{
	return this->_previous;
}

AGameEntity *			AGameEntity::getHead()
{
	return AGameEntity::_head;
}

int						AGameEntity::isDead() const
{
	return this->_dead;
}

void				AGameEntity::pushFront(AGameEntity *alist)
{
	AGameEntity *save = AGameEntity::_head;
	AGameEntity::_head = alist;
	alist->_next = save;
	if (save != NULL)
		save->_previous = alist;
}

void				AGameEntity::setWindow(Window const & window)
{
	AGameEntity::_winX = window.getW();
	AGameEntity::_winY = window.getH();
}

void				AGameEntity::setWindow(WINDOW *window)
{
	AGameEntity::_window = window;
}

void				AGameEntity::deleteNode()
{
	if (this == AGameEntity::_head)
	{
		AGameEntity::_head = this->_next;
		if (this->_next)
			this->_next->_previous = NULL;
	}
	else
	{
		if (this->_previous)
			this->_previous->_next = this->_next;
		if (this->_next)
			this->_next->_previous = this->_previous;
	}
}

std::string				AGameEntity::toString(void) const
{
	std::stringstream	ostr;

	ostr << "Game Entity (" << this->_index << ") has position : " << this->_pos
		<< ", hitbox : " << this->_hb << ", sprite : " << this->_sp
		<< ", dead : " << this->_dead << ", speed : " << this->_speed
		<< ", speedmax " << this->_maxspeed << "." << std::endl;
	return ostr.str();
}

std::ostream &			operator<<(std::ostream & o, AGameEntity const & rhs)
{
	o << rhs.toString();
	return o;
}

int				AGameEntity::_winX = 0;
int				AGameEntity::_winY = 0;
unsigned int	AGameEntity::_nb_inst = 0;
AGameEntity		*AGameEntity::_head = NULL;
WINDOW			*AGameEntity::_window = NULL;
