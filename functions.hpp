#include <iostream>

#include <SFML/Graphics.hpp>

void initText(sf::Text &text, sf::Font &font, std::string fontPath,
              std::string textString, int textSize, sf::Color color, sf::Vector2f position)
{
  if (!font.loadFromFile(fontPath))
    {
      std::cout << "Error loading font";
    }
    text.setFont(font);
    text.setString(textString);
    text.setCharacterSize(textSize);
    text.setFillColor(color);
    text.setPosition(position);
}