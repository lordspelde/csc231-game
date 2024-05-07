#pragma once

#include "vec.h"
#include <set>

class Dungeon;

class Fog {
public:
    explicit Fog(double brightness_seen=0.8);
    void update_visibility(Dungeon& dungeon, const Vec& position);
    void update_visibility_no_update(const Dungeon& dungeon, const Vec& position);

    [[nodiscard]] double brightness(const Vec& location) const;

    [[nodiscard]] bool is_visible(const Vec& location) const;
    [[nodiscard]] bool is_seen(const Vec& location) const;

    Vec get_position() const;
    
private:
    double brightness_seen;
    Vec position;
    std::set<Vec> visible_tiles, previously_seen_tiles;
};
