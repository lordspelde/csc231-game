#include "heroes.h"
#include "action.h"
#include "engine.h"

#include "rest.h"
#include "move.h"
#include "closedoor.h"

#include "sword.h"

namespace Heroes {
    void make_wizard(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("wizard");
        hero->set_max_health(10);
        hero->add_to_inventory(std::make_shared<Sword>(2));
        hero->behavior = behavior;
    }

    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
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
        } else if (!key.empty() && std::isdigit(key.at(0))){
            int item_num = std::stoi(key) - 1; // "1" -> index 0
            entity.select_item(item_num);
        }

        return nullptr;
    }
}