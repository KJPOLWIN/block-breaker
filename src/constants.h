#ifndef CONSTANTS_H
#define CONSTANTS_H

	#include <SFML/Graphics.hpp>

	namespace constant
	{
		//Window consts (you can change these)
		inline constexpr int windowWidth{ 1920 };
		inline constexpr int windowHeight{ 1080 };
		inline constexpr sf::Style windowStyle{ sf::Style::Fullscreen };
		inline constexpr sf::Color fpsCounterColor{ stf::Color::Red };

		//Mathematical consts (don't touch these)
		inline constexpr double degToRad{ 0.0174532925 };
		inline constexpr double radToDeg{ 57.29578 };
	}

#endif
