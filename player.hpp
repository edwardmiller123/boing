#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
  sf::Texture playerTexture;
  std::vector<sf::Rect<int>> frames;
  std::string texturePath;
  sf::Clock animationClock;

public:
  sf::Sprite playerSprite;
  sf::Vector2f currentPosition;
  int currentFrame;
  bool framesAscending;

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
    currentFrame = 0;
    framesAscending = true;
    playerSprite.setScale(sf::Vector2f(0.125f, 0.125f));
    playerSprite.setPosition(sf::Vector2f(320.f, 845.f));
  }

  void updatePosition(sf::RenderWindow &window)
  {
    currentPosition = playerSprite.getPosition();
  }

  void animate()
  {
    if (animationClock.getElapsedTime() > sf::milliseconds(62.5))
    {
      animationClock.restart();
      switch (framesAscending)
      {
      case true:
        currentFrame++;
        if (currentFrame == 3)
        {
          framesAscending = false;
        }
        break;
      case false:
        currentFrame--;
        if (currentFrame == 0)
        {
          framesAscending = true;
        }
        break;
      }
      playerSprite.setTextureRect(frames[currentFrame]);
    }
  }

  void jump()
  {
  }
};