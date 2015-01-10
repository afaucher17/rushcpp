/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fps.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:14:01 by afaucher          #+#    #+#             */
/*   Updated: 2015/01/10 17:29:11 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fps.hpp"

Fps::Fps( void ) : _m_fps(0), _m_fpscount(0)
{
	std::cout << "[CONSTRUCTED] FPS" << std::endl;
	return ;
}

Fps::Fps(Fps const & src)
{
	std::cout << "[CONSTRUCTED] FPS" << std::endl;
	*this = src;
	return ;
}

Fps::~Fps( void )
{
	std::cout << "[DESTRUCTED] FPS" << std::endl;
	return ;
}

Fps &	Fps::operator=(Fps const & rhs)
{
	this->_m_fps = rhs._m_fps;
	this->_m_fpscount = rhs._m_fpscount;
	this->_m_fpsinterval = rhs._m_fpsinterval;
	return *this;
}

std::string	Fps::toString() const
{
	std::ostringstream ostr;
	ostr << "FPS : fps :" << this->_m_fps << " fps count " << this->_m_fpscount
		<< " fps interval " << this->_m_fpsinterval << std::endl;
	return ostr.str();
}

void			Fps::update()
{
	this->_m_fpscount++;

	if (this->_m_fpsinterval.value() > CLOCKS_PER_SEC)
	{
		this->_m_fps = this->_m_fpscount;
		this->_m_fpscount = 0;
		this->_m_fpsinterval.refresh();
	}
	return ;
}

unsigned int	Fps::get() const
{
	return this->_m_fps;
}

std::ostream &	operator<<(std::ostream & o, Fps const & rhs)
{
	o << rhs.toString();
	return o;
}
