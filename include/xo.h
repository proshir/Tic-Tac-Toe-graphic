#ifndef XO_H
#define XO_H

#include <SFML/Graphics.hpp>
#include "helper.h"
#include "setting.h"

class XO
{
public:
    XO(Id _id);
    sf::Sprite sprite;
    Id id;
    void load_texture();
};

#endif