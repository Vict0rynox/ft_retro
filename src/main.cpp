//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include "core/Application.hpp"

int main()
{
	/*initscr();

	bool isExit = false;
	int x,y;
	int ch;

	noecho();
	//raw();
	//erase()
	while (!isExit)
	{
		getmaxyx(stdscr,y, x); // позволяет определить размер текущего терминала
		ch = getch();
		mvprintw(y/2, x/2, "%c[%d]", ch, ch);
		if(ch == 27) {
			isExit = true;
		}
		refresh();
	}
	endwin();*/
	Core::Application app;
	app.loop();
	return 0;
}