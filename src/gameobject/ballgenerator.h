#ifndef BALLGENERATOR_H
#define BALLGENERATOR_H

  #include "ball.h"
  #include <SFML/Graphics.hpp>
  #include <vector>

  enum class Phase
  {
    Aiming,
    Firing
  };

  class BallGenerator
  {
  public:
    BallGenerator(sf::Vector2f position, double maxCooldown);

    void update(double elapsedTime, sf::Vector2i mousePosition, bool clicked);
    void draw(sf::RenderWindow& window);

    void shotBall(double elapsedTime);

    std::vector<Ball>& getBalls();
    void returnBall();

  private:
    std::vector<Ball> balls{  };
    sf::Vector2f position{ 0, 0 };
    sf::Vector2f rotation{ 0, -1 };

    double cooldown{ 0.0 };
    double maxCooldown{ 0.0 };

    int maxBallsNumber{ 3 };
    int ballsNumber{ 3 };

    std::vector<sf::Vertex> aimingLine{  };
    Phase phase{ Phase::Aiming };
  };

#endif
