#ifndef _ENGINE_LISTENER
#define _ENGINE_LISTENER

#include "datahandler.h"
#include "engine_object.h"

namespace engine {

	class Listener {
		bool triggered;
		const int eventId;
		Linked::List<Object> * parent;
		Listener ();
	public:
		Listener (const int);
		Listener (Linked::List<Object>);
		Listener (Linked::List<Object> *);
		bool check ();
	};
}

#endif
