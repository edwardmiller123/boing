#include <SFML/Audio.hpp>

#include "player.hpp"

class Level
{
private:
  sf::View view;
  sf::Vector2f viewCenter;
  Player player;
  sf::Music music;

public:
  sf::Sprite background, floor, course;
  sf::Texture backgroundTexture, floorTexture, courseTexture;
  bool gameOver = false;

  int initLevel(std::string backgroundTexturePath, std::string playerTexturePath, std::string floorTexturePath, std::string musicPath, std::string courseTexturePath)
  {

    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
      std::cout << "Background texture didnt load";
      return 0;
    };
    background.setTexture(backgroundTexture);

    view.setSize(sf::Vector2f(750.f, 350.f));

    if (!floorTexture.loadFromFile(floorTexturePath))
    {
      std::cout << "Floor texture didnt load";
      return 0;
    };
    floor.setTexture(floorTexture);
    floor.setPosition(sf::Vector2f(0.f, 875.f));

    // TODO: Provide correct starting position once course
    // is drawn.
    if (!courseTexture.loadFromFile(courseTexturePath))
    {
      std::cout << "Course texture didnt load";
      return 0;
    };
    course.setTexture(courseTexture);
    course.setPosition(sf::Vector2f(900.f, 845.f));
    course.setScale(0.08, 0.08);

    if (!music.openFromFile(musicPath))
    {
      std::cout << "Level music didn't load correctly\n";
      return -1;
    }
    music.play();
    player.initPlayer({{91, 150, 255, 243}, {479, 150, 255, 243}, {851, 150, 255, 243}, {1229, 150, 255, 243}}, playerTexturePath);
  }

  // Handles whats displayed for the level.
  void renderLevel(sf::RenderWindow &window)
  {
    updateView(window);
    window.draw(background);
    window.draw(floor);
    window.draw(course);
    player.animate();
    window.draw(player.playerSprite);
  }

  // Handles game logic for the level.
  void updateLevel(sf::RenderWindow &window, std::string keyPressed)
  {
    player.handleInput(keyPressed);
    player.updatePosition(floor);
    player.updateState(course);
    if (player.dead)
    {
      gameOver = true;
    }
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