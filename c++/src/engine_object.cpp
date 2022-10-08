#include "engine_object.h"

using namespace engine;

Object () : spawn (Vector::Coord (0, 0)), size (Vector::Coord (0, 0)) {}

Object (Vector::Coord _loc) : spawn (_loc), size (Vector::Coord (0, 0)) {}

Object (Vector::Coord _loc, Vector::Coord _max) : spawn (_loc), size (_max) {}

virtual const bool draw () const {}

virtual const bool update () {
	bool flag = false;
	for (auto func : notify) {
		flag |= (*func) ();
	}
	return flag;
}

Solid (Vector::Coord (*_func) (Vector::Coord)) :
	spawn (Vector::Coord (0, 0)), size (Vector::Coord (0, 0)), center (Vector::Coord (0, 0)), closest (_func) {}

Solid (Vector::Coord (*_func) (Vector::Coord), Vector::Coord _loc) :
	spawn (_loc), size (Vector::Coord (0, 0)), center (Vector::Coord (0, 0), closest (_func) {}

Solid (Vector::Coord (*_func) (Vector::Coord), Vector::Coord _loc, Vector::Coord _max) :
	spawn (_loc), size (_max), closest (_func) {
	recenter ();
}

Solid (Vector::Coord (*_func) (Vector::Coord), Object _src) {
	*this = _src;
	closest = _func;
	recenter ();
}

const bool recenter () {
	center = spawn + size / 2;
}
