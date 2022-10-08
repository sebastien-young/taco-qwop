//load,check,update,show
#ifndef _ENGINE_GAME
#define _ENGINE_GAME

#include "datahandler.h"
#include "engine_view.h"
#include "engine_object.h"
#include "engine_listener.h"

namespace engine {

	class Game : public View {
		bool running;
		View & screen;
		Linked::List<Object> * elements;
		Linked::List<Listener> * active;
		Game ();
	public:
		Game (Linked::List<Object> *);
		Game (Object **);
		Game (View &);
		operator bool () const;
		operator std::string () const;
		operator engine::Object ** () const;
		operator engine::Listener ** () const;
		View & add (View &);
		Linked::List<Object> * add (Object &);
		Linked::List<Listener> * add (Listener &);
	};
}


#endif
