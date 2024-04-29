#include "entity.h"
#include "tile.h"
#include "engine.h"
#include "move.h"
#include "opendoor.h"
#include "attack.h"
#include "rest.h"

Move::Move(Vec direction):direction {direction} {}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);
    Vec new_pos = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(new_pos);

    if (tile.is_wall())
        return failure();

    if (tile.has_entity()) {
        if (entity->get_team() != tile.entity->get_team()) {
            return alternative(Attack{*tile.entity});
        } else {
            return alternative(Rest {});
        }
    }

    if (tile.has_door() && !tile.door->is_open())
        return alternative(OpenDoor{*tile.door});

    entity->move_to(new_pos);
    return success();
}
