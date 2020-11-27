//
// Created by Eryk on 21.10.2020.
//

#ifndef SIMPLERPG_CHUNK_H
#define SIMPLERPG_CHUNK_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "Constants.h"

namespace Terrain
{
	class Chunk : public sf::Drawable
	{
	public:
		explicit Chunk(sf::Vector2f const& position);

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::Vector2f position;
		sf::VertexArray blocks;
	};
}
#endif //SIMPLERPG_CHUNK_H
