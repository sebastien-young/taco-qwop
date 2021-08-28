//load,check,update,show
#ifndef _ENGINE
#define _ENGINE

#include "engine_game.h"
#include "engine_view.h"
#include "engine_object.h"
#include "engine_listener.h"

namespace engine {

	Game & load (Object *);
	Game & load (View &);
	const bool check (Listener *);
	const bool update (View &);
	const std::string & log (Game &);

}

#endif
