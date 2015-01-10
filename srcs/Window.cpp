/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:37:14 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/01/10 15:02:18 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Window.hpp"

Window::Window(int const x, int const y)
{
	std::cout << "class Window parameter constructor call." << std::endl;
	this->_x = x;
	this->_y = y;
}

Window::Window(Window const & src)
{
	std::cout << "class Window copy constructor call." << std::endl;
	*this = src;
}

Window::~Window( void )
{
	std::cout << "class Window destructor call." << std::endl;
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

Window::Window( void )
{
	std::cout << "class Window default constructor call." << std::endl;
}

