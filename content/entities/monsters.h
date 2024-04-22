#pragma once

#include <memory>
#include "entity.h"

namespace Monsters {
    void make_monster(std::shared_ptr<Entity>& hero);

    std::unique_ptr<Action> behavior(Engine& engine, Entity&);
}
