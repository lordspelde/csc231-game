#include "sword.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Sword::Sword(int damage):Item {"sword"}, damage {damage} {}

void Sword::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Swing>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}
