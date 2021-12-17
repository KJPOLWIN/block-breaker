#include "ballgenerator.h"
#include "ball.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <vector>

BallGenerator::BallGenerator(sf::Vector2f position, double maxCooldown)
  : position{ position },
    cooldown{ maxCooldown },
    maxCooldown{ maxCooldown }
{

}

void BallGenerator::shotBall(double elapsedTime)
{
  if(cooldown < 0.0)
  {
    balls.push_back(Ball(position, constant::ballSpeed, sf::Vector2f(0.0f, -1.0f)));
    cooldown = maxCooldown;
  }

  cooldown -= elapsedTime;
}

std::vector<Ball>& BallGenerator::getBalls()
{
  return balls;
}
