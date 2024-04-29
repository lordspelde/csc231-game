#pragma once

#include <memory>
#include "entity.h"

namespace Monsters {
    void make_zombie(std::shared_ptr<Entity>& hero);
    void make_skeleton(std::shared_ptr<Entity>& monster);
    void make_golem(std::shared_ptr<Entity>& monster);

    std::unique_ptr<Action> default_behavior(Engine& engine, Entity&);
}
