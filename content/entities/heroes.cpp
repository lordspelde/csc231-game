#include "heroes.h"
#include "action.h"
#include "engine.h"

#include "rest.h"
#include "move.h"
#include "closedoor.h"

namespace Heroes {
    void make_wizard(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("wizard");
        hero->set_max_health(10);
        hero->behavior = behavior;
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity&) {
        std::string key = engine.input.get_last_keypress();

        if (key == "R") {
            return std::make_unique<Rest>();
        } else if (key == "C") {
            return std::make_unique<CloseDoor>();
        } else if (key == "W") { // fwd
            return std::make_unique<Move>(Vec {0, 1});
        } else if (key == "A") { // left
            return std::make_unique<Move>(Vec {-1, 0});
        } else if (key == "S") { // back
            return std::make_unique<Move>(Vec {0, -1});
        } else if (key == "D") { // right
            return std::make_unique<Move>(Vec {1, 0});
        }

        return nullptr;
    }
}