#ifndef BALLGENERATOR_H
#define BALLGENERATOR_H

  #include "ball.h"
  #include <SFML/Graphics.hpp>
  #include <vector>

  class BallGenerator
  {
  public:
    BallGenerator(sf::Vector2f position, double maxCooldown);

    void shotBall(double elapsedTime);

    std::vector<Ball>& getBalls();

  private:
    std::vector<Ball> balls;
    sf::Vector2f position;

    double cooldown{ 0.0 };
    double maxCooldown{ 0.0 };
  };

#endif
