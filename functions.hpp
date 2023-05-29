#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>

struct levelInitialiser
{
  std::string backgroundTexturePath, playerTexturePath,
      floorTexturePath, musicPath, courseTexturePath;
  std::vector<sf::IntRect> playerFrames;
  std::vector<std::vector<float>> spikePositions;
  std::string levelNumber;
};

std::vector<std::vector<float>> readSpikePositions(std::string filePath)
{
  std::vector<std::vector<float>> vec;
  std::fstream file;
  int lineCounter;
  float lineFloat;
  file.open(filePath, std::ios::in); 
  if (file.is_open())
  {
    std::string line;
    while (getline(file, line))
    {
      // For the moment set the heights to be the same but may change this in future by
      // adding the heights to the file.
      lineFloat = (float)atof(line.c_str());
      // 537.5 is a good height
      vec.push_back({lineFloat, 545});
    }
    file.close();
    return vec;
  }
}

// A little clunky but we store all the level information here
// ready to be initialised.
std::vector<levelInitialiser> initLevels()
{
  std::vector<std::vector<float>> level1SpikePositions, level2SpikePositions, level3SpikePositions;
  level1SpikePositions = readSpikePositions("assets/level1_spike_positions.txt");

  levelInitialiser level1 = {"assets/level1_background.png",
                             "assets/boingo.png",
                             "assets/level1_floor.png",
                             "assets/level1.wav",
                             "assets/spike_no_background.png",
                             {{91, 150, 255, 243}, {479, 150, 255, 243}, {851, 150, 255, 243}, {1229, 150, 255, 243}},
                             level1SpikePositions, "1"};

  // Initialise the other levels correctly when they arrive.
  levelInitialiser level2 = {"",
                             "",
                             "",
                             "",
                             "",
                             {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                             level2SpikePositions, "2"};
  levelInitialiser level3 = {"",
                             "",
                             "",
                             "",
                             "",
                             {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                              level3SpikePositions, "3"};
  std::vector<levelInitialiser> levels = {level1, level2, level3};
  return levels;
};

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