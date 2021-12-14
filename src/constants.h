#ifndef CONSTANTS_H
#define CONSTANTS_H

	#include <SFML/Graphics.hpp>

	namespace constant
	{
		//Window consts (you can change these)
		inline constexpr int windowWidth{ 800 };
		inline constexpr int windowHeight{ 1000 };
		inline constexpr sf::Uint32 windowStyle{ sf::Style::Default };
		inline const sf::Color fpsCounterColor{ sf::Color::Red };

		//Mathematical consts (don't touch these)
		inline constexpr double degToRad{ 0.0174532925 };
		inline constexpr double radToDeg{ 57.29578 };
	}

#endif
