#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include "Window.hpp"
#include "Interval.hpp"
#include "Fps.hpp"
#include "Position.hpp"
#include "DisplaySprite.hpp"
#include "AGameEntity.hpp"
#include "Game.hpp"

// enables to save the terminal current color and restore them later (using the boolean save)
void    switchDefaultColors(bool save) {
	static short black[3];
	static short red[3];
	static short green[3];
	static short yellow[3];
	static short blue[3];
	static short magenta[3];
	static short cyan[3];
	static short white[3];

	if (save) {
		color_content(COLOR_BLACK, &black[0], &black[1], &black[2]);
		color_content(COLOR_RED, &red[0], &red[1], &red[2]);
		color_content(COLOR_GREEN, &green[0], &green[1], &green[2]);
		color_content(COLOR_YELLOW, &yellow[0], &yellow[1], &yellow[2]);
		color_content(COLOR_BLUE, &blue[0], &blue[1], &blue[2]);
		color_content(COLOR_MAGENTA, &magenta[0], &magenta[1], &magenta[2]);
		color_content(COLOR_CYAN, &cyan[0], &cyan[1], &cyan[2]);
		color_content(COLOR_WHITE, &white[0], &white[1], &white[2]);
	}
	else {
		init_color(COLOR_BLACK, black[0], black[1], black[2]);
		init_color(COLOR_RED, red[0], red[1], red[2]);
		init_color(COLOR_GREEN, green[0], green[1], green[2]);
		init_color(COLOR_YELLOW, yellow[0], yellow[1], yellow[2]);
		init_color(COLOR_BLUE, blue[0], blue[1], blue[2]);
		init_color(COLOR_MAGENTA, magenta[0], magenta[1], magenta[2]);
		init_color(COLOR_CYAN, cyan[0], cyan[1], cyan[2]);
		init_color(COLOR_WHITE, white[0], white[1], white[2]);
	}
}

void    initColors() {
	// init default color - TODO: later create different games color profiles
	init_color(COLOR_BLACK, 20, 50, 150);
	init_color(COLOR_RED, 700, 0, 0);
	init_color(COLOR_GREEN, 0, 700, 0);
	init_color(COLOR_YELLOW, 700, 700, 0);
	init_color(COLOR_BLUE, 0, 0, 700);
	init_color(COLOR_MAGENTA, 700, 0, 700);
	init_color(COLOR_CYAN, 0, 400, 700);
	init_color(COLOR_WHITE, 700, 700, 700);
}

void    setColors(void) {
	// color support is required for this game
	if (!can_change_color()) {
		printw("ERROR: Your terminal can't change colors");
		getch();
		endwin(); // care, we are exiting the program. Is everything restored ?
		exit(1);
	}
	if (has_colors() == FALSE) {
		printw("ERROR: Your terminal does not support color\n");
		getch();
		endwin();
		exit(1);
	}

	start_color();
	switchDefaultColors(true);
	initColors();

	// init pairs : Here define our color pairs.
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_CYAN);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_GREEN);

}

void				init(void)
{
	initscr();
	setColors();
	cbreak(); // or raw() of we want to catch all inputs including ctr-c, etc.
	noecho();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(0);
	refresh();
}

int					main(void)
{
	// Primary variables
	int					i, row, col;
	std::stringstream	buff;

	// Screen init
	init();
	getmaxyx(stdscr, col, row);

	// Windows variables
	Window 				gamew(0, 0, col / 5 * 4, row);
	Window				debug(0, col / 5 * 4, col / 5, row);
	Game				game(gamew);
	DisplaySprite::display("game", Position(1, 0), 3, gamew.getWindow());
	DisplaySprite::display("Debug", Position(1, 0), 3, debug.getWindow());

	AGameEntity::setWindow(gamew.getWindow());

	Console console(debug.getWindow());

	// Secondary variables
	Fps					fps;
	Interval			itv;

	i = 0;
	gamew.refreshWindow();
	while (!game.getStatus())
	{
		buff.str(std::string());
		buff.clear();
		while (itv.value() < CLOCKS_PER_SEC / 120);
		buff << "FPS: " << fps.get();
		DisplaySprite::display(buff.str(), Position(13, 0), 2, debug.getWindow());
		DisplaySprite::display(game.getLife(), Position(25, 0), 2, debug.getWindow());
		DisplaySprite::display(Game::getScore(), Position(38, 0), 2, debug.getWindow());
		i++;
		game.refresh();
		gamew.refreshWindow();
		debug.refreshWindow();
		fps.update();
		itv.refresh();
	}
	timeout(-1);
	do
		i = getch();
	while (i != 10);

	switchDefaultColors(false); // TODO: Before exiting, launch this function to restore Terminal default colors
}
