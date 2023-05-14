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
  sf::Sprite background, floor;
  sf::Texture backgroundTexture, floorTexture, spikeTexture;
  std::vector<sf::Sprite> spikes;
  int nextSpike;

public:
  bool gameOver;

  int initLevel(std::string backgroundTexturePath, std::string playerTexturePath, std::vector<sf::IntRect> playerFrames,
                std::string floorTexturePath, std::string musicPath, std::string spikeTexturePath,
                std::vector<std::vector<float>> spikePositions)
  {
    gameOver = false;

    if (!backgroundTexture.loadFromFile(backgroundTexturePath))
    {
      std::cout << "Background texture didnt load";
      return 0;
    };
    background.setTexture(backgroundTexture);

    // Scale factor of height to width is 2.143.
    // 64.29, 30.f
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
      spike.setScale(0.008, 0.008);
      spikes.push_back(spike);
    }
    nextSpike = 0;

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
    // This works for the moment but may not be viable with
    // alot of spikes.
    for (int n = 0; n < spikes.size(); n++)
    {
      window.draw(spikes[n]);
    }
    player.animate();
    window.draw(player.playerSprite);
  }

  // Handles game logic for the level.
  void updateLevel(sf::RenderWindow &window, std::string keyPressed)
  {
    handleInput(keyPressed);
    player.updatePosition(floor);
    player.updateState(spikes[nextSpike]);
    updateLevelState();
  }

  void handleInput(std::string keyPressed)
  {
    player.handleInput(keyPressed);
    // TODO: Replace with pause menu eventually.
    if (keyPressed == "escape")
    {
      std::cout << "escape\n";
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

  // Checks whether the level should continue.
  void updateLevelState()
  {
    if (player.dead)
    {
      exitLevel();
    }
    else if (player.currentPosition.x > spikes[nextSpike].getPosition().x)
    {
      // Stops us accessing an index that doesnt exist.
      if (nextSpike < spikes.size() - 1)
      {
        nextSpike++;
      }
    }
  }

  void exitLevel()
  {
    music.stop();
    gameOver = true;
  }
};