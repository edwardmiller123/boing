#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

struct levelInitialiser
{
  std::string backgroundTexturePath, playerTexturePath,
      floorTexturePath, musicPath, courseTexturePath;
  std::vector<sf::IntRect> playerFrames;
  std::vector<std::vector<float>> spikePositions;
};

// A little clunky but we store all the level information here
// ready to be initialised.
std::vector<levelInitialiser> initLevels()
{
  std::vector<std::vector<float>> level1SpikePositions, level2SpikePositions, level3SpikePositions;

  levelInitialiser level1 = {"assets/level1_background.png",
                             "assets/boingo.png",
                             "assets/level1_floor.png",
                             "assets/level1.wav",
                             "assets/spike_no_background.png",
                             {{91, 150, 255, 243}, {479, 150, 255, 243}, {851, 150, 255, 243}, {1229, 150, 255, 243}},
                             {{185.702, 537.5}, {294.809, 537.5}, {406.316, 537.5} ,{445.518, 537.5}, 
                             {471.52, 537.5}, {483.521, 537.5}, {622.295, 537.5}, {678.382, 537.5}, {707.574, 537.5}, {818.047, 537.5},
                             {930.32, 537.5}, {971.81, 537.5}, {1036.89, 537.5}, {1074.08, 537.5}, {1116.77, 537.5}, {1127.67, 537.5},
                             {1147.47, 537.5}, {1185.06, 537.5}, {1255.84, 537.5}, {1296.53, 537.5}, {1333.42, 537.5}, {1350.92, 537.5},
                             {1364.21, 537.5}, {1412.3, 537.5}, {1476.39, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5},
                             {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}, {0, 537.5}}};

  // Initialise the other levels correctly when they arrive.
  levelInitialiser level2 = {"",
                             "",
                             "",
                             "",
                             "",
                             {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                             {{0, 0}}};
  levelInitialiser level3 = {"",
                             "",
                             "",
                             "",
                             "",
                             {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                             {{0, 0}}};
  std::vector<levelInitialiser> levels = {level1, level2, level3};
  return levels;
};

std::vector<float> readFile(std::string filePath) {
  std::vector<float> vec;
  return vec;
}

void initText(sf::Text &text, sf::Font &font, std::string fontPath,
              std::string textString, int textSize, sf::Color color, sf::Vector2f position)
{
  if (!font.loadFromFile(fontPath))
  {
    std::cout << "Error loading font";
  }
  text.setFont(font);
  text.setString(textString);
  text.setCharacterSize(textSize);
  text.setFillColor(color);
  text.setPosition(position);
}