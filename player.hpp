#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
  sf::Texture playerTexture;
  std::vector<sf::Rect<int>> frames;
  std::string texturePath;

public:
  sf::Sprite playerSprite;
  sf::Vector2f currentPosition;
  int currentFrame;

  int initPlayer(std::vector<sf::Rect<int>> newFrames, std::string newTexturePath)
  {
    frames = newFrames;
    texturePath = newTexturePath;
    if (!playerTexture.loadFromFile(texturePath))
    {
      std::cout << "Player texture didn't load";
      return 0;
    };
    playerSprite.setTexture(playerTexture);

    // Sets starting frame
    playerSprite.setTextureRect(frames[0]);
    playerSprite.setScale(sf::Vector2f(0.125f, 0.125f));
    playerSprite.setPosition(sf::Vector2f(320.f, 700.f));
  }

  void updatePosition(sf::RenderWindow &window) {
    currentPosition = playerSprite.getPosition();
  }

  void animate()
  {
  }

  void jump()
  {
  }
};