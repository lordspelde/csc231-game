#include "monsters.h"
#include "action.h"
#include "engine.h"

#include "randomness.h"

#include "rest.h"
#include "move.h"
#include "wander.h"

#include "sword.h"
#include "bite.h"

namespace Monsters {
    // Basic enemies
    void make_zombie(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("zombie");
        monster->set_max_health(5);
        monster->add_to_inventory(std::make_shared<Bite>(Bite {1}));
        monster->behavior = default_behavior;
    }

    void make_skeleton(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("skeleton");
        monster->set_max_health(3);
        monster->add_to_inventory(std::make_shared<Sword>(Sword {2}));
        monster->behavior = default_behavior;
    }

    // Unique Enemies
    void make_golem(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("zombie_big");
        monster->set_max_health(10);
        monster->add_to_inventory(std::make_shared<Bite>(Bite {3}));
        monster->behavior = default_behavior;
    }



    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity) {
        // pursue Hero if monster can see him (If Hero sees me, I see him)
        if (entity.is_visible() && engine.hero) {
            auto path = engine.dungeon.calculate_path(entity.get_position(),
                                                      engine.hero->get_position());

            if (path.size() > 1) {
                auto direction = path.at(1) - path.at(0);
                Tile goto_tile = engine.dungeon.get_tile(path.at(1));

                return std::make_unique<Move>(direction);
            }
        }

        if (probability(66)) {
            return std::make_unique<Wander>();
        }

        return std::make_unique<Rest>();
    }
}
