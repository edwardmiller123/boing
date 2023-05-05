#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
  sf::Texture playerTexture;
  std::vector<sf::Rect<int>> frames;
  std::string texturePath;
  sf::Clock animationClock;
  float velocityY = 0;
  float gravity = 0.2;

public:
  sf::Sprite playerSprite;
  sf::Vector2f currentPosition;
  int currentFrame = 0;
  bool framesAscending = true;

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
    playerSprite.setPosition(sf::Vector2f(320.f, 847.f));
  }

  void updatePosition(sf::Sprite &floor)
  {
    currentPosition = playerSprite.getPosition();
    // Adds gravity if player is not touching the floor
    if (!playerSprite.getGlobalBounds().intersects(floor.getGlobalBounds()))
    {
      velocityY += gravity;
    }
    else if (velocityY > 0)
    {
      // Stops player continuing to move through the floor.
      velocityY = 0;
    }
    currentPosition.y += velocityY;
    playerSprite.setPosition(sf::Vector2f(currentPosition.x, currentPosition.y));
  }

  void handleInput(std::string keyPressed)
  {
    if (keyPressed == "space")
    {
      jump();
    }
  }

  // Controls player animations.
  void animate()
  {
    // TODO: need to make this in time
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
    // Prevents double jumping.
    if (velocityY == 0)
    {
      velocityY = -6;
    }
  }
};