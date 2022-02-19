#include "ballgenerator.h"
#include "ball.h"
#include "guitext.h"
#include "resourcemanager.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cmath>

    #include <iostream>

BallGenerator::BallGenerator(sf::Vector2f position, double maxCooldown)
  : position{ position },
    cooldown{ 0.0 },
    maxCooldown{ maxCooldown }
{
  ballsNumberText.setPosition(position + sf::Vector2f(-5, -50));
}

void BallGenerator::update(double elapsedTime, sf::Vector2i mousePosition, bool clicked)
{
  if(phase == Phase::Aiming)
  {
    nextLevelSignal = false;
    arrow.update(position, mousePosition);

    if(clicked)
    {
      double distance{ sqrt(pow(mousePosition.x - position.x, 2)
                          + pow(mousePosition.y - position.y, 2)) };
      rotation = sf::Vector2f((mousePosition.x - position.x) / distance,
                              (mousePosition.y - position.y) / distance);

      phase = Phase::Firing;
    }
  }
  else
  {
    shotBall(elapsedTime);

    for( auto& ball : balls )
  	{
  		ball.update(elapsedTime);
  	}

    if(ballsNumber == 0 && balls.size() == 0)
    {
      ballsNumber = maxBallsNumber;
      phase = Phase::Aiming;
      nextLevelSignal = true;
    }
  }

  ballsNumberText.update(std::to_string(ballsNumber));
  
  for(std::size_t iii{ 0 }; iii < balls.size(); ++iii)
  {
    //Ball shouldn't escape screen from the bottom, because ball deletor is there
    if(balls.at(iii).getPosition().x < 0 || balls.at(iii).getPosition().x > constant::windowHeight
    || balls.at(iii).getPosition().y < 0)
    {
      balls.erase(balls.begin() + iii);
    }
  }
}

void BallGenerator::draw(sf::RenderWindow& window)
{
  arrow.draw(window);

  for( auto& ball : balls )
	{
		ball.draw(window);
	}

  ballsNumberText.draw(&window);
}

void BallGenerator::shotBall(double elapsedTime)
{
  if(cooldown < 0.0 && ballsNumber > 0)
  {
    balls.push_back(Ball(position, constant::ballSpeed, rotation));
    cooldown = maxCooldown;
    --ballsNumber;
  }

  cooldown -= elapsedTime;
}

std::vector<Ball>& BallGenerator::getBalls()
{
  return balls;
}

int BallGenerator::getBallsNumber()
{
  return ballsNumber;
}

int BallGenerator::getMaxBallsNumber()
{
  return maxBallsNumber;
}

void BallGenerator::addBall()
{
  ++maxBallsNumber;
}

void BallGenerator::setPosition(sf::Vector2f newPosition)
{
  position = newPosition;
  ballsNumberText.setPosition(position + sf::Vector2f(-5, -50));
}

void BallGenerator::setPosition(double newPositionX)
{
  position = sf::Vector2f(newPositionX, position.y);
  ballsNumberText.setPosition(position + sf::Vector2f(-5, -50));
}

sf::Vector2f BallGenerator::getPosition()
{
  return position;
}

Phase BallGenerator::getPhase()
{
  return phase;
}

bool BallGenerator::getNextLevelSignal()
{
  return nextLevelSignal;
}

void BallGenerator::reset()
{
  balls.clear();
  ballsNumber = 1;
  maxBallsNumber = 1;
}
