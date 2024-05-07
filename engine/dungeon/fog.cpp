#include "fog.h"

#include <algorithm>

#include "dungeon.h"
#include "fov.h"

Fog::Fog(double brightness_seen)
    :brightness_seen{brightness_seen}, position{} {}

void Fog::update_visibility(Dungeon& dungeon, const Vec& new_position) {
    for (const Vec& pos : visible_tiles) {
        dungeon.tiles(pos).visible = false;
    }

    update_visibility_no_update(dungeon, new_position);

    for (const Vec& pos : visible_tiles) {
        dungeon.tiles(pos).visible = true;
    }
}

void Fog::update_visibility_no_update(const Dungeon& dungeon, const Vec& new_position) {
    position = new_position;

    previously_seen_tiles.insert(std::begin(visible_tiles), std::end(visible_tiles));

    FieldOfView fov;
    visible_tiles = fov.compute(new_position, [&](const Vec& pos) {
        return dungeon.is_opaque(pos);
    });
}


double Fog::brightness(const Vec& location) const {
    if (visible_tiles.count(location)) {
        double dist = distance(position, location);
        double value = std::clamp(0.1*(dist-1), 0.0, brightness_seen);
        return value;
    }
    else if (previously_seen_tiles.count(location)) {
        return brightness_seen;
    }
    else {
        return 1;
    }
}

bool Fog::is_visible(const Vec& location) const {
    return visible_tiles.count(location);
}

bool Fog::is_seen(const Vec& location) const {
    return previously_seen_tiles.count(location);
}

Vec Fog::get_position() const {
    return position;
}
