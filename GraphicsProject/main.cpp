#include "Engine.h"
#include "Dragonorld.h"

int main() {
	Engine* engine = new Engine(1280, 720, "Dragonorld");

	Dragonorld* world = new Dragonorld();

	engine->setActiveWorld(world);

	int exitCode = engine->run();

	delete world;
	delete engine;

	return exitCode;
}