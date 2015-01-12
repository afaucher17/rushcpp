/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:37:14 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/01/12 00:06:16 by frale-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <ncurses.h>
#include "Window.hpp"

Window::Window(int const x, int const y, int const h, int const w) : _clock(0), _x(x), _y(y), _h(h), _w(w)
{
	WINDOW	*win;

	win = newwin(this->_h, this->_w, this->_y, this->_x);

	wattron(win, COLOR_PAIR(5));
	wborder(win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	wrefresh(win);
	wattroff(win, COLOR_PAIR(5));

	this->_window = win;
}

Window::Window(Window const & src) : _clock(0)
{
	*this = src;
	std::cout << "[CONSTRUCT] Window"
		<< this->getX() << " " << this->getY() << std::endl;
}

Window::~Window( void )
{
	
	delwin(this->_window);
	endwin();
}

Window &			Window::operator=(Window const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_h = rhs.getH();
	this->_w = rhs.getW();
	return *this;
}


void				Window::refreshWindow(void)
{
	wrefresh(this->_window);
}

int					Window::getX(void) const
{
	return this->_x;
}

int					Window::getY(void) const
{
	return this->_y;
}

int					Window::getH(void) const {
	return this->_h;
}

int					Window::getW(void) const {
	return this->_w;
}

WINDOW 				*Window::getWindow(void) const {
	return this->_window;
}

Window::Window( void ) : _clock(0)
{
	
}

