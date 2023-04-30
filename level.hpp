#include "player.hpp"

class Level {
  private:
  std::string backgroundTexturePath, playerTexturePath;
  public:
  sf::Sprite background;
  sf::Texture backgroundTexture;
  Player player;

  int initLevel(std::string newBackgroundTexturePath, std::string newPlayerTexturePath) {
    backgroundTexturePath = newBackgroundTexturePath;
    playerTexturePath = newPlayerTexturePath;
    
    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
      std::cout << "Level texture didnt load";
      return 0;
    };
    background.setTexture(backgroundTexture);
    player.initPlayer({91, 150, 255, 243}, {479, 150, 255, 243}, {851, 150, 255, 243}, {1229, 150, 255, 243}, playerTexturePath);
  }
};