//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>

int main()
{
	initscr();
	int x,y;
	getmaxyx(stdscr,y, x); // позволяет определить размер текущего терминала
	move(y/2, x/2);
	attron(A_REVERSE);
	printw("a");
	attroff(A_REVERSE);
	getch();
	endwin();
	return 0;
}