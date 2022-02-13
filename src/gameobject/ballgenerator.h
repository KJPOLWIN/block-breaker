#ifndef BALLGENERATOR_H
#define BALLGENERATOR_H

  #include "ball.h"
  #include "guitext.h"
  #include "resourcemanager.h"
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
    int getBallsNumber();
    int getMaxBallsNumber();
    void addBall();

    void setPosition(sf::Vector2f newPosition);
    void setPosition(double newPositionX);   //only x cood
    sf::Vector2f getPosition();

    Phase getPhase();

    bool getNextLevelSignal();

    void reset();

  private:
    std::vector<Ball> balls{  };
    sf::Vector2f position{ 0, 0 };
    sf::Vector2f rotation{ 0, -1 };

    double cooldown{ 0.0 };
    double maxCooldown{ 0.0 };

    int maxBallsNumber{ 1 };
    int ballsNumber{ 1 };

    std::vector<sf::Vertex> aimingLine{  };
    Phase phase{ Phase::Aiming };

    bool nextLevelSignal{ false };

    guiText ballsNumberText{
                             ResourceManager::arial,
                             "",
                             sf::Color::Red,
                             30,
                             sf::Vector2f()
                           };
  };

#endif
