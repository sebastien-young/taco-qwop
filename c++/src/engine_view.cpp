#include "engine_view.h"

using namespace engine;

View () : front (nullptr), middle (nullptr), back (nullptr) {
	//initialize the screen...
}

View::const bool draw () const {
	bool status = true;
	return status;
}
