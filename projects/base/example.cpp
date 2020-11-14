#include "example.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	pinkisActive = false;
	orangeisActive = false;

	m_backgroundSprite = kage::TextureManager::getSprite("data/Spacey.jpg");

	OrangeTilee = kage::TextureManager::getTexture("data/OrangeTilee.png");
	PurpleTile = kage::TextureManager::getTexture("data/PurpleTile.png");
	//To load the textures that i've saved in the data folder

	
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	for (size_t i = 0; i < TOTAL_CELLS_X; i++)
	{
		vLine[i] = sf::RectangleShape(sf::Vector2f(LINE_THICKNESS, CELL_HEIGHT * TOTAL_CELLS_Y));
		vLine[i].setFillColor(sf::Color::Cyan);
		vLine[i].setPosition(sf::Vector2f(GRID_OFFSET_X + CELL_WIDTH * i, GRID_OFFSET_Y));
	}
	
	for (size_t i = 0; i < TOTAL_CELLS_Y; i++)
	{
		hLine[i] = sf::RectangleShape(sf::Vector2f(CELL_WIDTH * TOTAL_CELLS_X, LINE_THICKNESS));
		hLine[i].setFillColor(sf::Color::Cyan);
		hLine[i].setPosition(sf::Vector2f(GRID_OFFSET_X, GRID_OFFSET_Y + CELL_HEIGHT * i));
	}

	return true;

}

void Example::update(float deltaT)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

	//std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
	//if statement for if the boolian pinkisActive or orangeisActive

	if (orangeisActive == true &&sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		int x = mousePosition.x / CELL_WIDTH;
		int y = mousePosition.y / CELL_HEIGHT;


		if (x >= 0 && y >= 0 && x < (TOTAL_CELLS_X - 1) && y < (TOTAL_CELLS_Y - 1))
		{
			int i = x + y * (TOTAL_CELLS_X - 1);

			std::cout << x << " " << y << std::endl;

			sf::Sprite Orange;
			Orange.setTexture(*OrangeTilee);
			Orange.setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));

			tiles[i] = Orange;
		
	   }	
	} 
	if (pinkisActive == true &&sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		int x = mousePosition.x / CELL_WIDTH;
		int y = mousePosition.y / CELL_HEIGHT;


		if (x >= 0 && y >= 0 && x < (TOTAL_CELLS_X - 1) && y < (TOTAL_CELLS_Y - 1))
		{
			int i = x + y * (TOTAL_CELLS_X - 1);

			std::cout << x << " " << y << std::endl;

			sf::Sprite Purple;
			Purple.setTexture(*PurpleTile);
			Purple.setPosition(sf::Vector2f(x * CELL_WIDTH, y * CELL_HEIGHT));
			

			tiles[i] = Purple;

		}
	}
	

	static const char* options[]{ "Orange Tile","Pink Tile"};
	static int currentTile = 0;

	ImGui::Begin("Map Editor");
	ImGui::ListBox("Tiles", &currentTile, options, IM_ARRAYSIZE(options));

	if (currentTile == 0)
	{
		orangeisActive = true;
		pinkisActive = false;
	}

	if (currentTile == 1)
	{
		orangeisActive = false;
		pinkisActive = true;
	}
	
	ImGui::End();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}



	//ImGui::Begin("Kage2D");
	//if (ImGui::Button("PinkTile"))
	//{
		//orangeisActive = false;
		//pinkisActive = true;

	//}
	//ImGui::End();



	
	ImGui::Begin("Kage2D");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	ImGui::End();

}


void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < TOTAL_CELLS_X; i++)
	{
		m_window.draw(vLine[i]);
	}

	for (size_t i = 0; i < TOTAL_CELLS_Y; i++)
	{
		m_window.draw(hLine[i]);
	}

	for (size_t i = 0; i < TILES_ARRAZY_SIZE; i++)
	{
		m_window.draw(tiles[i]);
	}

	
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

