//load,check,update,show

#include "engine.h"

engine::Game & load (engine::Object * elements) {
	engine::Game _game = new engine::Game (elements);
	return _game;
}

engine::Game & load (engine::View & screen) {
	engine::Game _game = new engine::Game (screen);
	return _game;
}

engine::const bool check (engine::Listener * active) {

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

engine::const bool update (engine::View & screen) {
	return screen->draw ();
}

engine::const std::string & log (engine::Game & _game);
	std::string line = "info: " + _game;
	puts (line + "\n");
	return line;
}
