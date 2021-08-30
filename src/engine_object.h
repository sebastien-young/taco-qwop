#ifndef _ENGINE_OBJECT
#define _ENGINE_OBJECT

#include "datahandler.h"

namespace engine {
	class Object {
		Linked::List<void *> * notify;
	public:
		Object ();
		virtual const bool draw () const;
		virtual const bool update ()
	};
}

#endif
