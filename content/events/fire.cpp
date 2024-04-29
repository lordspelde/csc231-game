#include "fire.h"

#include "engine.h"

Fire::Fire(Vec position): position {position} {}

void Fire::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_animated_sprite("fire", 1);
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(position, sprite.get_sprite());
    sprite.update();
}