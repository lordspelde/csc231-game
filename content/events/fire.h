#pragma once

#include "event.h"
#include "vec.h"
#include "animatedsprite.h"

class Fire : public Event {
public:
    explicit Fire(Vec position);

    void execute(Engine& engine) override;

private:
    Vec position;
    AnimatedSprite sprite;

};