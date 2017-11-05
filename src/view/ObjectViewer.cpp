//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include "ObjectViewer.hpp"

void View::ObjectViewer::view(Model::Object *object)
{
	Model::INcursesView *view = nullptr;

	if(dynamic_cast<Model::INcursesView *>(object) != nullptr) {

		view = dynamic_cast<Model::INcursesView *>(object);
		Utils::List<Model::Simbol> *points = view->getView();
		Model::Simbol simbol;
		while (!points->isEnd())
		{
			simbol = points->curr();
			mvwprintw(window, object->getPosition().getY() + simbol.getPosition().getY(),
				object->getPosition().getX() + simbol.getPosition().getX(),
					 "%s", simbol.getUsim().c_str());
			points->prev();
		}
		points->reset();
	}
}

View::ObjectViewer::~ObjectViewer()
{
	delwin(window);
}

View::ObjectViewer::ObjectViewer() : objectsList(nullptr)
{
	int w, h;
	getmaxyx(stdscr, h, w);
	window = newwin(h - 5, w, 5, 0);
}

View::ObjectViewer::ObjectViewer(const View::ObjectViewer &rhs) : objectsList(rhs.objectsList), window(rhs.window)
{

}

View::ObjectViewer &View::ObjectViewer::operator=(const View::ObjectViewer &rhs)
{
	objectsList = rhs.objectsList;
	window = rhs.window;
	return *this;
}

View::ObjectViewer::ObjectViewer(Utils::List<Model::Object *> *objectsList) : objectsList(objectsList)
{
	int w, h;
	getmaxyx(stdscr, h, w);
	window = newwin(h - 5, w, 5, 0);
}

void View::ObjectViewer::render()
{
	Model::Object *object;

	werase(window);
	box(window, 0, 0);
	while (!objectsList->isEnd()) {
		object = objectsList->curr();
		view(object);
		objectsList->prev();
	}
	objectsList->reset();
	wrefresh(window);
}
