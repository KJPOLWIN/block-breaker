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
  aimingLine.push_back(sf::Vertex(position, sf::Color::Red));
  aimingLine.push_back(sf::Vertex(position, sf::Color::Red));

  ballsNumberText.setPosition(position + sf::Vector2f(-5, -50));
}

void BallGenerator::update(double elapsedTime, sf::Vector2i mousePosition, bool clicked)
{

  if(phase == Phase::Aiming)
  {
    std::cout << "updating line position...";
    nextLevelSignal = false;
    aimingLine.at(0).position = position;
    //SFML won't let to assign Vector2f to Vector2i
    aimingLine.at(1).position.x = mousePosition.x;
    aimingLine.at(1).position.y = mousePosition.y;
    std::cout << " done\n";

    std::cout << "checking if clicked...";
    if(clicked)
    {
      std::cout << " done\n";
      std::cout << "changing state to Firing...";
      double distance{ sqrt(pow(mousePosition.x - position.x, 2)
                          + pow(mousePosition.y - position.y, 2)) };
      rotation = sf::Vector2f((mousePosition.x - position.x) / distance,
                              (mousePosition.y - position.y) / distance);

      phase = Phase::Firing;
      std::cout << " done\n";
    }
  }
  else
  {
    std::cout << "shooting ball...";
    shotBall(elapsedTime);
    std::cout << " done\n";

    std::cout << "updating balls...";
    for( auto& ball : balls )
  	{
  		ball.update(elapsedTime);
  	}
    std::cout << " done\n";

    std::cout << "checking state change to Aiming...";
    if(ballsNumber == 0 && balls.size() == 0)
    {
      std::cout << " done\n";
      std::cout << "changing state to Aiming...";
      ballsNumber = maxBallsNumber;
      phase = Phase::Aiming;
      nextLevelSignal = true;
      std::cout << " done\n";
    }
    else
    {
      std::cout << " done\n";
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
