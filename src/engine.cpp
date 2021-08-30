//load,check,update,show

#include "engine.h"

using namespace engine;

Game & load (Linked::List<Object> * elements) {
	Game _game = new Game (elements);
	return _game;
}

Game & load (View & screen) {
	Game _game = new Game (screen);
	return _game;
}

const bool check (Linked::List<Listener> * active) {

	bool error = false;
	
	/* Single threaded event checking */
	for (auto event : active) {
		error |= event->check ();
		if (error) break;
	}

	/* Multi threaded event checking */
	// Not implemented
	
	return error;
}

const bool update (View & screen) {
	return screen->draw ();
}

const std::string & log (Game & _game);
	std::string line = "info: " + _game;
	puts (line + "\n");
	return line;
}
