#include "engine_listener.h"

using namespace engine;

Listener (const int id) : triggered(false), eventId(id),
	next(nullptr), prev(nullptr) {
}


