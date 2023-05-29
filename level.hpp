#include <vector>

#include <SFML/Audio.hpp>
#include "functions.hpp"
#include "player.hpp"

class Level
{
private:
  sf::View view;
  sf::Vector2f viewCenter;
  Player player;
  sf::Music music;
  sf::Sprite background, floor, finishFlag;
  sf::Texture backgroundTexture, floorTexture, spikeTexture, finishFlagTexture;
  std::vector<sf::Sprite> spikes;
  int nextSpike;
  sf::Text victoryText;
  sf::Font victoryFont;
  sf::Clock victoryScreenClock;
  std::string levelNumber;

public:
  bool gameOver, levelComplete;

  int initLevel(std::string backgroundTexturePath, std::string playerTexturePath, std::vector<sf::IntRect> playerFrames,
                std::string floorTexturePath, std::string musicPath, std::string spikeTexturePath,
                std::vector<std::vector<float>> spikePositions, std::string newLevelNumber)
  {
    gameOver = false;
    levelComplete = false;
    levelNumber = newLevelNumber;

    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
      std::cout << "Background texture didnt load";
      return 0;
    };
    background.setTexture(backgroundTexture);

    // Scale factor of height to width is 2.143.
    view.setSize(sf::Vector2f(64.29, 30.f));

    if (!floorTexture.loadFromFile(floorTexturePath))
    {
      std::cout << "Floor texture didnt load";
      return 0;
    };
    floor.setTexture(floorTexture);
    floor.setPosition(sf::Vector2f(0.f, 540.f));

    // We initialise all the spikes for the level.
    if (!spikeTexture.loadFromFile(spikeTexturePath))
    {
      std::cout << "Spike texture didnt load";
      return 0;
    };

    sf::Sprite spike;
    for (int j = 0; j < spikePositions.size(); j++)
    {
      spike.setTexture(spikeTexture);
      spike.setPosition(sf::Vector2f(spikePositions[j][0], spikePositions[j][1]));
      spike.setScale(0.006, 0.006);
      spikes.push_back(spike);
    }
    nextSpike = 0;

    // Can reuse flag for all levels so we hard code the texture path.
    if (!finishFlagTexture.loadFromFile("assets/finish_flag.png"))
    {
      std::cout << "Finish Flag texture didnt load";
      return 0;
    };
    finishFlag.setTexture(finishFlagTexture);
    finishFlag.setPosition(sf::Vector2f(6000.f, 531.5));
    finishFlag.setScale(0.025, 0.025);

    initText(victoryText, victoryFont, "assets/Aadhunik.ttf", "Level " + levelNumber + " Complete!", 80, sf::Color::White,
             sf::Vector2f(520.f, 360.f));

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
    if (levelComplete)
    {
      window.draw(victoryText);
    }
    else
    {
      window.draw(background);
      window.draw(floor);
      window.draw(finishFlag);
      drawSpikes(window);
      player.animate();
      window.draw(player.playerSprite);
    }
  }

  // Handles game logic for the level.
  void updateLevel(sf::RenderWindow &window, std::string keyPressed)
  {
    handleInput(keyPressed);
    player.updatePosition(floor);
    player.updateState(spikes[nextSpike], keyPressed);
    updateLevelState();
  }

  void handleInput(std::string keyPressed)
  {
    player.handleInput(keyPressed);
    // TODO: Replace with pause menu eventually.
    if (keyPressed == "escape")
    {
      exitLevel();
    }
  }

  // Sets whats visible in the window.
  sf::Vector2f updateView(sf::RenderWindow &window)
  {
    if (levelComplete)
    {
      window.setView(window.getDefaultView());
    }
    else
    {
      window.setView(view);

      // Slightly offsets the player from the screen center.
      viewCenter = sf::Vector2f(player.currentPosition.x + 20, 530);
      view.setCenter(viewCenter);
    }
  }

  // Checks whether the level should continue.
  void updateLevelState()
  {
    if (player.dead)
    {
      exitLevel();
    }
    // We +3 here to stop the previous spike being marked as safe once we have passed
    // it's centre.
    else if (player.currentPosition.x > (spikes[nextSpike].getPosition().x + 3))
    {
      // Stops us accessing an index that doesnt exist.
      if (nextSpike < spikes.size() - 1)
      {
        nextSpike++;
      }
    }
    if (player.playerSprite.getGlobalBounds().intersects(finishFlag.getGlobalBounds()))
    {
      levelComplete = true;
      player.hasWon = true;
      // (I'm sure there is a better way to do this) we check the elapsed time twice so we can reset it before showing
      // the victory screen since the clock has been running for the whole game.
      if (victoryScreenClock.getElapsedTime() > sf::seconds(30))
      {
        victoryScreenClock.restart();
      }
      if (victoryScreenClock.getElapsedTime() > sf::seconds(3) && victoryScreenClock.getElapsedTime() < sf::seconds(4))
      {
        exitLevel();
      }
    }
  }

  // Only draw the spikes in the vicinity of the player to improve perfomance.
  void drawSpikes(sf::RenderWindow &window)
  {
    if (spikes.size() > 0)
    {
      int j = 0;
      int k = nextSpike + 6;
      if (nextSpike > 4)
      {
        j = nextSpike - 3;
      }
      for (int n = j; n < k; n++)
      {
        window.draw(spikes[n]);
      }
    }
  }

  void exitLevel()
  {
    music.stop();
    gameOver = true;
  }
};