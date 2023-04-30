#include "player.hpp"

class Level
{
private:
  std::string backgroundTexturePath, playerTexturePath;
  sf::View view;
  sf::Vector2f viewCenter;

public:
  sf::Sprite background;
  sf::Texture backgroundTexture;
  Player player;

  int initLevel(std::string newBackgroundTexturePath, std::string newPlayerTexturePath)
  {
    backgroundTexturePath = newBackgroundTexturePath;
    playerTexturePath = newPlayerTexturePath;

    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
      std::cout << "Level texture didnt load";
      return 0;
    };
    background.setTexture(backgroundTexture);
    player.initPlayer({{91, 150, 255, 243}, {479, 150, 255, 243}, {851, 150, 255, 243}, {1229, 150, 255, 243}}, playerTexturePath);
    view.setSize(sf::Vector2f(1076.f, 600.f));
  }

  // Handles whats displayed for the level.
  void renderLevel(sf::RenderWindow &window)
  {
    updateView(window);
    window.draw(background);
    player.animate();
    window.draw(player.playerSprite);
  }

  // Handles game logic for the level.
  void updateLevel(sf::RenderWindow &window)
  {
    player.updatePosition(window);
  }

  // Sets whats visible in the window.
  sf::Vector2f updateView(sf::RenderWindow &window)
  {
    window.setView(view);
    // Slightly offsets the player from the screen center.
    viewCenter = sf::Vector2f(player.currentPosition.x + 250, player.currentPosition.y);
    view.setCenter(viewCenter);
  }
};