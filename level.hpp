#include <vector>

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
  bool gameOver;

  int initLevel(std::string backgroundTexturePath, std::string playerTexturePath, std::vector<sf::IntRect> playerFrames, std::string floorTexturePath, std::string musicPath, std::string courseTexturePath)
  {
    gameOver = false;

    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
      std::cout << "Background texture didnt load";
      return 0;
    };
    background.setTexture(backgroundTexture);

    // Note: 750, 350 is the correct size for the game.
    // Scale factor of height to width is 2.143
    view.setSize(sf::Vector2f(64.29, 30.f));

    if (!floorTexture.loadFromFile(floorTexturePath))
    {
      std::cout << "Floor texture didnt load";
      return 0;
    };
    floor.setTexture(floorTexture);
    floor.setPosition(sf::Vector2f(0.f, 540.f));

    // TODO: Provide correct starting position once course
    // is drawn.
    if (!courseTexture.loadFromFile(courseTexturePath))
    {
      std::cout << "Course texture didnt load";
      return 0;
    };
    course.setTexture(courseTexture);
    course.setPosition(sf::Vector2f(200.f, 536.f));
    course.setScale(0.03, 0.03);

    if (!music.openFromFile(musicPath))
    {
      std::cout << "Level music didn't load correctly\n";
      return -1;
    }
    music.play();
    
    player.initPlayer(playerFrames, playerTexturePath);
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
      exitLevel();
    }
  }

  // Sets whats visible in the window.
  sf::Vector2f updateView(sf::RenderWindow &window)
  {
    window.setView(view);

    // Slightly offsets the player from the screen center.
    // Note: 700 is a good y value.
    viewCenter = sf::Vector2f(player.currentPosition.x + 20, 530);
    view.setCenter(viewCenter);
  }

  void exitLevel() {
    music.stop();
    gameOver = true;
  }
};