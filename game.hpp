#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "player.hpp"

class Game
{
private:
  sf::RenderWindow window;
  sf::Event event;
  sf::View view;

public:
  bool gameRunning;
  sf::Sprite level;
  sf::Texture levelTexture;
  Player player;

  // Initialisation
  int initGame()
  {
    gameRunning = true;
    window.create(sf::VideoMode(1600, 800), "Boing!");
    initLevel();
  }

  int initLevel() {
    if (!levelTexture.loadFromFile("assets/level.png"))
    {
      std::cout << "Level texture didnt load";
      return 0;
    };
    level.setTexture(levelTexture);
    player.initPlayer({91, 150, 255, 243}, {479, 150, 255, 243}, {851, 150, 255, 243}, {1229, 150, 255, 243}, "assets/boingo.png");
    view.setSize(sf::Vector2f(800.f, 800.f));
    window.setView(view);

  }

  // Game logic
  void run()
  {
    update();
    render();
  }
  // Handles game logic.
  void update()
  {
    view.setCenter(player.playerSprite.getPosition());
    pollEvents();
  }
  // Handles whats shown on screen.
  void render()
  {
    window.clear();
    window.draw(level);
    window.draw(player.playerSprite);
    window.display();
  }

  void pollEvents()
  {
    while (window.pollEvent(event))
    {
      switch (event.type)
      {

      case sf::Event::Closed:
        window.close();
        gameRunning = false;
        break;
      default:
        break;
      }
    }
  }
};