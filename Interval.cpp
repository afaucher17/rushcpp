/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interval.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:38:32 by afaucher          #+#    #+#             */
/*   Updated: 2015/01/10 15:38:51 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interval.hpp"
#include <ctime>

Interval::Interval( void ) : _initial(std::clock())
{
	std::cout << "[CONSTRUCT] Interval" << std::endl;
	return ;
}

Interval::Interval(Interval const & src)
{
	std::cout << "[CONSTRUCT] Interval" << std::endl;
	*this = src;
	return ;
}

Interval::~Interval( void )
{
	std::cout << "[DESTRUCT] Interval" << std::endl;
	return ;
}

Interval &	Interval::operator=(Interval const & rhs)
{
	this->_initial = rhs._initial;
	return *this;
}

std::string	Interval::toString() const
{
	std::ostringstream ostr;

	ostr << "Interval : Initial Value " << this->_initial << " Current Value " <<
		this->value() << std::endl;
	return ostr.str();
}

void			Interval::refresh()
{
	this->_initial = std::clock();
}

unsigned int	Interval::value() const
{
	return std::clock() - this->_initial;
}

std::ostream &	operator<<(std::ostream & o, Interval const & rhs)
{
	o << rhs.toString();
	return o;
}

