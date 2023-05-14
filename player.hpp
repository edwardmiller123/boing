#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
  sf::Texture playerTexture;
  std::vector<sf::Rect<int>> frames;
  std::string texturePath;
  sf::Clock animationClock;
  float velocityY;
  float velocityX;
  float gravity;
  sf::FloatRect hitBox; 

public:
  sf::Sprite playerSprite;
  sf::Vector2f currentPosition;
  int currentFrame = 0;
  bool framesAscending = true;
  bool dead;

  int initPlayer(std::vector<sf::Rect<int>> newFrames, std::string newTexturePath)
  {
    frames = newFrames;
    texturePath = newTexturePath;
    dead = false;
    velocityY = 0;
    gravity = 0.005;

    // Player is moving forwards by default.
    // 0.2478 is almost the right speed however may ditch this.
    velocityX = 0.1;

    if (!playerTexture.loadFromFile(texturePath))
    {
      std::cout << "Player texture didn't load";
      return 0;
    };
    playerSprite.setTexture(playerTexture);

    // Sets starting frame 
    playerSprite.setTextureRect(frames[0]);
    playerSprite.setScale(sf::Vector2f(0.01f, 0.01f));
    playerSprite.setPosition(sf::Vector2f(50.f, 535.f));
    
    // Add a collsion detection box that is smaller than the player to make
    // the game seem less unfair.
    hitBox = {playerSprite.getPosition().x, playerSprite.getPosition().y, 0.05, 0.05};
  }

  void updatePosition(sf::Sprite &floor)
  {
    currentPosition = playerSprite.getPosition();
    // Adds gravity if player is not touching the floor.
    if (!playerSprite.getGlobalBounds().intersects(floor.getGlobalBounds()))
    {
      velocityY += gravity;
    }
    else if (velocityY > 0)
    {
      // Stops player continuing to move through the floor.
      velocityY = 0;
    }
    currentPosition.x += velocityX;
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
      velocityY = -0.25;
    }
  }

  void updateState(sf::Sprite spike)
  {
    std::cout << currentPosition.x << "\n";
    hitBox.left = currentPosition.x;
    hitBox.top = currentPosition.y;
    if (hitBox.intersects(spike.getGlobalBounds()))
    {
      velocityX = 0;
      dead = true;
    }
  }
};