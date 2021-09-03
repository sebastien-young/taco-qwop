#ifndef _ENGINE_OBJECT
#define _ENGINE_OBJECT

#include "datahandler.h"

namespace engine {
	class Object {
		Linked::List<bool (*) (void)> * notify;
		Linked::List<Linked::List> * subscriptions;
		Vector::Coord spawn;
		Vector::Coord size;
	public:
		Object ();
		Object (Vector::Coord);
		Object (Vector::Coord, Vector::Coord);
		virtual const bool draw () const;
		virtual const bool update ();
		virtual Linked::List & subscribe (bool (*) (void));
		virtual const bool unsubscribe (Linked::List *);
	};

	class Solid : public Object {
		Vector::Coord (*closest) (Vector::Coord);
		Vector::Coord center;
		Solid ();
	public:
		Solid (Vector::Coord (*) (Vector::Coord));
		Solid (Vector::Coord (*) (Vector::Coord), Vector::Coord);
		Solid (Vector::Coord (*) (Vector::Coord), Vector::Coord, Vector::Coord);
		Solid (Vector::Coord (*) (Vector::Coord), Object);
		const bool recenter ();
		const bool collides (const Solid *) const;
	};

	class Motile : public Solid {
		bool floating;
		Vector::Coord velocity;
		Vector::Coord force;
		Motile ();
	public:
		const bool move ();
		const bool fall ();
		const bool above (Solid *) const;
	};

	class Rotile : public Solid {
		float rotation;
		float speed;
		bool clockwise;
		Rotor ();
	public:
		const bool rotate ();
		const bool roll (float);
	};
}

#endif
