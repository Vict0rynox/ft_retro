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
			mvprintw(object->getPosition().getY() + simbol.getPosition().getY(),
				object->getPosition().getX() + simbol.getPosition().getX(),
					 "%s", simbol.getUsim().c_str());
			points->prev();
		}
		points->reset();
	}
}

View::ObjectViewer::~ObjectViewer()
{
	//TODO: delete list;
}

View::ObjectViewer::ObjectViewer() : objectsList(nullptr)
{

}

View::ObjectViewer::ObjectViewer(const View::ObjectViewer &rhs) : objectsList(rhs.objectsList)
{

}

View::ObjectViewer &View::ObjectViewer::operator=(const View::ObjectViewer &rhs)
{
	objectsList = rhs.objectsList;
	return *this;
}

View::ObjectViewer::ObjectViewer(Utils::List<Model::Object *> *objectsList) : objectsList(objectsList)
{

}

void View::ObjectViewer::render()
{
	Model::Object *object;

	while (!objectsList->isEnd()) {
		object = objectsList->curr();
		view(object);
		objectsList->next();
	}
	objectsList->reset();
}
