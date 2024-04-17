#include "closedoor.h"
#include "entity.h"
#include "updatefov.h"

Result CloseDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    bool closed = false;

    for (Vec neighbor : neighbors) {
        Tile& tile = engine.dungeon.get_tile(neighbor);

        if (tile.has_door() && tile.door->is_open()) {
            closed = true;

            tile.door->close();
        }
    }

    if (closed) {
        engine.events.create_event<UpdateFOV>();

        return success();
    } else {
        return failure();
    }
}
