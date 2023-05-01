#include "player.hpp"

class Level
{
private:
  sf::View view;
  sf::Vector2f viewCenter;
  Player player;

public:
  sf::Sprite background, floor, course;
  sf::Texture backgroundTexture, floorTexture, courseTexture;

  int initLevel(std::string backgroundTexturePath, std::string playerTexturePath, std::string floorTexturePath)
  {

    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
      std::cout << "Background texture didnt load";
      return 0;
    };
    background.setTexture(backgroundTexture);

    if (!floorTexture.loadFromFile(floorTexturePath))
    {
      std::cout << "Floor texture didnt load";
      return 0;
    };
    floor.setTexture(floorTexture);
    floor.setPosition(sf::Vector2f(0.f, 875.f));

    player.initPlayer({{91, 150, 255, 243}, {479, 150, 255, 243}, {851, 150, 255, 243}, {1229, 150, 255, 243}}, playerTexturePath);
    view.setSize(sf::Vector2f(750.f, 350.f));
  }

  // Handles whats displayed for the level.
  void renderLevel(sf::RenderWindow &window)
  {
    updateView(window);
    window.draw(background);
    window.draw(floor);
    player.animate();
    window.draw(player.playerSprite);
  }

  // Handles game logic for the level.
  void updateLevel(sf::RenderWindow &window, std::string keyPressed)
  {
    player.handleInput(keyPressed);
    player.updatePosition(floor);
  }

  // Sets whats visible in the window.
  sf::Vector2f updateView(sf::RenderWindow &window)
  {
    window.setView(view);

    // Slightly offsets the player from the screen center.
    viewCenter = sf::Vector2f(player.currentPosition.x + 200, 847 - 50);
    view.setCenter(viewCenter);
  }
};