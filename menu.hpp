#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

class Menu {
  private:
    
    std::vector<std::vector<std::string>> levels;
  public:
    bool menuOpen = true;

    void initMenu() {
      levels[0] = {"assets/backgroundL1.png", "assets/boingo.png", "assets/floorL1.png", "assets/home.wav", "assets/spike_no_background.png"};
      levels[1] = {"", "", "", "", ""};
      levels[2] = {"", "", "", "", ""};
    }

    void updateMenu(sf::RenderWindow &window, std::string keyPressed) {
      handleInput();
    }

    void renderMenu() {

    }

    void handleInput() {

    }

};