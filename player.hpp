#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
  sf::Texture playerTexture;
  sf::Rect<int> frame1, frame2, frame3, frame4;
  std::string texturePath;

public:
  sf::Sprite playerSprite;

  int initPlayer(sf::Rect<int> newFrame1, sf::Rect<int> newFrame2, sf::Rect<int> newFrame3, sf::Rect<int> newFrame4, std::string newTexturePath)
  {
    frame1 = newFrame1;
    frame2 = newFrame2;
    frame3 = newFrame3;
    frame4 = newFrame4;
    texturePath = newTexturePath;
    if (!playerTexture.loadFromFile(texturePath))
    {
      std::cout << "Player texture didn't load";
      return 0;
    };
    playerSprite.setTexture(playerTexture);
    // Sets starting frame
    playerSprite.setTextureRect(frame1);
    playerSprite.setScale(sf::Vector2f(0.125f, 0.125f));
    playerSprite.setPosition(sf::Vector2f(320.f, 700.f));
  }

  void animate()
  {
  }

  void jump()
  {
  }
};