#include "arrow.h"
#include "constants.h"
#include "animatedsprite.h"
#include "resourcemanager.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Arrow::Arrow()
{
  arrowBody.setFillColor(constant::arrowColor);
}

void Arrow::update(sf::Vector2f start, sf::Vector2i end)
{
  double length{ sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2)) };
  sf::Vector2f rotationVector{ (end.x - start.x) / length, (end.y - start.y) / length };
  double rotation{ atan2(rotationVector.y, rotationVector.x) * constant::radToDeg };

  if(length > 68)
  {
    arrowHead.setPosition(sf::Vector2f(start.x + rotationVector.x * (length - 13.0),
                                       start.y + rotationVector.y * (length - 13.0)));
    arrowHead.setRotation(rotation);

    arrowBody.setSize(sf::Vector2f((length - 63), arrowBody.getSize().y));
    arrowBody.setOrigin(sf::Vector2f(arrowBody.getSize().x * 0.5, arrowBody.getSize().y * 0.5));
    // arrowBody.setPosition(sf::Vector2f(start.x + rotationVector.x * (length - 13.0 - arrowBody.getSize().x),
    //                                    start.y + rotationVector.y * (length - 13.0 - arrowBody.getSize().x)));
    arrowBody.setPosition(sf::Vector2f(start.x + rotationVector.x * (length - 18.0 - arrowBody.getSize().x * 0.5),
                                       start.y + rotationVector.y * (length - 18.0 - arrowBody.getSize().x * 0.5)));
    arrowBody.setRotation(rotation);

    arrowBase.setPosition(sf::Vector2f(start.x + rotationVector.x * 25,
                                       start.y + rotationVector.y * 25));
    arrowBase.setRotation(rotation);
  }
  else
  {
    arrowHead.setPosition(sf::Vector2f(start.x + rotationVector.x * 55,
                                       start.y + rotationVector.y * 55));
    arrowHead.setRotation(rotation);

    arrowBody.setSize(sf::Vector2f(0.0, arrowBody.getSize().y));

    arrowBase.setPosition(sf::Vector2f(start.x + rotationVector.x * 25,
                                       start.y + rotationVector.y * 25));
    arrowBase.setRotation(rotation);
  }
}

void Arrow::draw(sf::RenderWindow& targetWindow)
{
  arrowHead.draw(&targetWindow);
  targetWindow.draw(arrowBody);
  arrowBase.draw(&targetWindow);
}
