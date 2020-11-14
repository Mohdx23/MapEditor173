#pragma once

#include "app.h"
#include <vector>

#define LINE_THICKNESS 3

#define GRID_OFFSET_X 0
#define GRID_OFFSET_Y 0

#define CELL_WIDTH 192
#define CELL_HEIGHT 64

#define TOTAL_CELLS_X 7 + 1
#define TOTAL_CELLS_Y 9 + 1

#define TILES_ARRAZY_SIZE (TOTAL_CELLS_X - 1) * (TOTAL_CELLS_Y - 1)

class Example : public App
{
public:
	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();

	bool orangeisActive;
	bool pinkisActive;
	

	
	sf::Texture* OrangeTilee;
	sf::Texture* PurpleTile;
	


	sf::Sprite tiles[TILES_ARRAZY_SIZE];

	sf::Sprite *m_backgroundSprite;

	sf::RectangleShape vLine[TOTAL_CELLS_X];
	sf::RectangleShape hLine[TOTAL_CELLS_Y];
};
