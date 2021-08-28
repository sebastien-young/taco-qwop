//load,check,update,show
#include "engine_game.h"

using namespace engine;

Game (const Linked::List<Object> * _elements) : 
	running(true), elements(_elements), middle(_elements), active(_elements) {
	for (auto & element : *elements) {
		if (element) {
			add (Listener (element));
		}
	} 
}

Game (const View & _screen) :
	running(true), elements(_screen), active(_screen) {
}

Game::operator bool () const {
	return running;
}

Game::operator std::string () const {
	return running ? "running" : "stopped";
}

Game::operator Linked::List<Object> * () const {
	return elements;
}

Game::operator Linked::List<Listener> * () const {
	return active;
}

Game::View & add (View & _screen) {
	delete screen;
	return screen = _screen;
}

engine::Game::Object * add (Object & element) {
	if (elements != nullptr) elements->add (element);
	else elements = &element;
	return elements;
}

engine::Game::Listener ** add (Listener & event) {
	if (active == nullptr or active[-1]) {
		active mem
			add (event);
	return active;
}
