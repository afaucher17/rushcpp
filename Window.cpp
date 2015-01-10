/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:37:14 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/01/10 17:37:57 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <ncurses.h>
#include "Window.hpp"

Window::Window(int const x, int const y) : _clock(0), _x(x), _y(y)
{
	std::cout << "[CONSTRUCT] Window "
		<< this->getX() << " " << this->getY() << std::endl;
}

Window::Window(Window const & src) : _clock(0)
{
	*this = src;
	std::cout << "[CONSTRUCT] Window"
		<< this->getX() << " " << this->getY() << std::endl;
}

Window::~Window( void )
{
	std::cout << "[DESTRUCTOR] Window" << std::endl;
	endwin();
}

Window &			Window::operator=(Window const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return *this;
}

void				initColor()
{
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
}

void				Window::initWindow(void)
{
	initscr();
	initColor();
	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
}

void				Window::refreshWindow(void)
{
	refresh();
}

int					Window::getX(void) const
{
	return this->_x;
}

int					Window::getY(void) const
{
	return this->_y;
}

Window::Window( void ) : _clock(0)
{
	std::cout << "[CONSTRUCT] Window" << std::endl;
}

