#include "monsters.h"
#include "action.h"
#include "engine.h"

#include "randomness.h"

#include "rest.h"
#include "move.h"
#include "wander.h"

namespace Monsters {
    void make_monster(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("zombie");
        monster->set_max_health(4);
        monster->behavior = behavior;
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
        // pursue Hero if monster can see him (If Hero sees me, I see him)
        if (entity.is_visible() && engine.hero) {
            auto path = engine.dungeon.calculate_path(entity.get_position(),
                                                      engine.hero->get_position());

            if (path.size() > 1) {
                auto direction = path.at(1) - path.at(0);
                return std::make_unique<Move>(direction);
            }
        }

        if (probability(66)) {
            return std::make_unique<Wander>();
        }

        return std::make_unique<Rest>();
    }
}
