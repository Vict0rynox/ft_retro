//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include <zconf.h>
#include <cmath>
#include "Application.hpp"
#include "../model/INcursesView.hpp"

void Core::Application::loop() {
    while (!isExit) { //loop
        tickRate.calcFps();
        //if (tickRate.getFps() <= maxFPS) {
        garbregCollection();
        control();
        intersections();
        update();
        eventHandle();
        redrow();
        //}
    }
    endwin();
}

void Core::Application::control() {
    sim = getch(); //get button
    int x, y;
    getmaxyx(stdscr, y, x);
    winSize.setHeight(static_cast<unsigned int>(y));
    winSize.setWidth(static_cast<unsigned int>(x));
}

void Core::Application::update() {
    Control::IController *controller;
    while (!controllerList.isEnd()) {
        controller = controllerList.curr();
        if (controller->isHandle(sim)) {
            controller->handle(sim);
            changed();
        }
        controllerList.prev();
    }
    controllerList.reset();
}

void Core::Application::redrow() {

    View::IViewer *viewer;
    while (!viewerList.isEnd()) {

        viewer = viewerList.curr();
        viewer->render();
        viewerList.prev();
    }
    viewerList.reset();
    refresh();
}

void Core::Application::eventHandle() {
    Event::IEvent *event;
    while (!eventsList.isEnd()) {

        event = eventsList.curr();
        event->handle();
        eventsList.prev();
        if (event->isEnd()) {
            eventsList.remove(event);
            delete event;
        }
    }
    eventsList.reset();
}


Core::Application::Application(const Core::Application &rhs)
        :  sim(),   isExit(rhs.isExit),
          isChange(rhs.isChange), minFPS(rhs.minFPS), maxFPS(rhs.maxFPS) {
    _init();
}

Core::Application &Core::Application::operator=(const Core::Application &rhs) {
    isExit = rhs.isExit;
    isChange = rhs.isChange;
    return *this;
}

Core::Application::Application() :   sim(),   isExit(false),
                                   isChange(false),minFPS(29), maxFPS(200) {
    _init();
}

Core::Application::~Application() {
    endwin();
}

void Core::Application::_init() {
    initscr();
    curs_set(0);
    raw();
    noecho();
    keypad(stdscr, true);
    halfdelay(1);
    control();
}

void Core::Application::addController(Control::IController *controller) {
    controllerList.pushNode(controller);
}

void Core::Application::exit() {
    isExit = true;
}

void Core::Application::changed() {
    isChange = true;
}

void Core::Application::addObject(Model::Object *object) {
    objectsList.pushNode(object);
}

void Core::Application::addViewer(View::IViewer *viewer) {
    viewerList.pushNode(viewer);
}

Utils::List<Model::Object *> *Core::Application::getObjectsListPtr() {
    return &objectsList;
}

int *Core::Application::getSimPtr() {
    return &sim;
}

Core::TickRate *Core::Application::getTickRatePtr() {
    return &tickRate;
}

void Core::Application::addEvent(Event::IEvent *event) {
    eventsList.pushNode(event);
}

Utils::List<Event::IEvent *> *Core::Application::getEventsListPtr() {
    return &eventsList;
}

void Core::Application::garbregCollection() {
    Model::Object *object;
    Utils::ListIterator<Model::Object *> objectIterator =
            Utils::ListIterator<Model::Object *>(objectsList);
    while (!objectIterator.isEnd()) {
        object = objectIterator.curr();
        if (object->isDestroy()) {
            mvprintw(4, 0, "remove object %s", object->getName().c_str());
            objectsList.remove(object);
        } else if (
                object->getPosition().getY() > getmaxy(stdscr) ||
                object->getPosition().getY() < 0 ||
                object->getPosition().getX() > getmaxx(stdscr) ||
                object->getPosition().getX() < 0) {
            object->destroy();
        }
        objectIterator.prev();
    }
}

void Core::Application::intersections() {
    Model::Object *object;
    Utils::ListIterator<Model::Object *> objectIterator =
            Utils::ListIterator<Model::Object *>(objectsList);
    mvprintw(5, 0, "in intersections");
    while (!objectIterator.isEnd()) {
        object = objectIterator.curr();
        if (!object->isIsNotIntersection()) {
            Utils::ListIterator<Model::Object *> objectIntersectIterator =
                    Utils::ListIterator<Model::Object *>(objectsList);
            while (!objectIntersectIterator.isEnd()) {
                Model::Object *intersectObject = objectIntersectIterator.curr();
                if (object != intersectObject && !intersectObject->isIsNotIntersection()) {
                    mvprintw(5, 0, "%s check %s", object->getName().c_str(), intersectObject->getName().c_str());
                    if (object->isIntersect(*intersectObject)) {
                        intersectObject->destroy();
                        object->destroy();
                        break;
                    }
                }
                objectIntersectIterator.prev();
            }
        }
        objectIterator.prev();
    }
}
















