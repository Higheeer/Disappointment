//
// Created by Eryk on 22.10.2020.
//

#ifndef SIMPLERPG_SRC_CAMERA_H_
#define SIMPLERPG_SRC_CAMERA_H_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

#include "Constants.h"

namespace Terrain
{
	class ChunkManager;
}

class Player;

class Chunk;

class Camera : public sf::Drawable
{
public:
	explicit Camera(Player& player);

	void zoomIn();

	void zoomOut();

	void update(Terrain::ChunkManager const& terrain, sf::RenderWindow& window);

private:
	void checkVisibleChunks(Terrain::ChunkManager const& terrain);

	void addVisibleChunk(Chunk const& chunk);

	void clampViewSize();

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;

private:
	std::vector<Chunk> visibleChunks;
	int viewDistance;
	sf::View view;

	Player* player;
	sf::Vector2f playerOrigin;
};

#endif //SIMPLERPG_SRC_CAMERA_H_
