#include "entity.h"
#include "tile.h"
#include "engine.h"
#include "move.h"

Move::Move(Vec direction):direction {direction} {}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);
    Vec goto_dir = entity->get_position() + direction;

    if (engine.dungeon.get_tile(goto_dir).walkable) {
        entity->move_to(goto_dir);
        return success();
    }

    return failure();
}
