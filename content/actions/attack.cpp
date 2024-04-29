#include "attack.h"

#include "entity.h"
#include "item.h"

Attack::Attack(Entity& defender):defender {defender} {}

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker) {
    std::shared_ptr<Item> tool = attacker->get_current_item();
    tool->use(engine, *attacker, defender);

    return success();
}