#ifndef _ENGINE_VIEW
#define _ENGINE_VIEW

#include "datahandler.h"
#include "engine_object.h"

namespace engine {
	class View {
		Linked::List<Object> * front;
		Linked::List<Object> * middle;
		Linked::List<Object> * back;
	public:
		View ();
		const bool draw () const;
		const bool operator + (Object &);
	};
}

#endif
