#include "ballgenerator.h"
#include "ball.h"
#include "guitext.h"
#include "resourcemanager.h"
#include "constants.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cmath>

BallGenerator::BallGenerator(sf::Vector2f position, double maxCooldown)
  : position{ position },
    cooldown{ 0.0 },
    maxCooldown{ maxCooldown }
{
  aimingLine.push_back(sf::Vertex(position, sf::Color::Red));
  aimingLine.push_back(sf::Vertex(position, sf::Color::Red));

  ballsNumberText.setPosition(position + sf::Vector2f(-5, -50));
}

void BallGenerator::update(double elapsedTime, sf::Vector2i mousePosition, bool clicked)
{

  if(phase == Phase::Aiming)
  {
    nextLevelSignal = false;
    aimingLine.at(0).position = position;
    //SFML won't let assing Vector2f to Vector2i
    aimingLine.at(1).position.x = mousePosition.x;
    aimingLine.at(1).position.y = mousePosition.y;

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
}

void BallGenerator::draw(sf::RenderWindow& window)
{
  window.draw(&aimingLine.at(0), aimingLine.size(), sf::Lines);

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
