#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"

namespace LeTurfu::Api {

class EntityApi: public sf::Transformable
{
protected:
	Entity* entity;
public:


};

}
