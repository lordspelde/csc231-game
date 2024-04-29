#include "spear.h"

#include "engine.h"
#include "hit.h"
#include "thrust.h"

Spear::Spear(int damage):Item {"spear"}, damage {damage} {}

void Spear::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}