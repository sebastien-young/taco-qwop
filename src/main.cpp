#include "engine.h"
#include "qwop.h"

int main () {
	auto game = engine::load (qwop::initial);
	do {
		if (engine::check (game)) break;
		if (engine::update (game)) break;
		engine::log (game);
	} while (game);
	return 0;
}
