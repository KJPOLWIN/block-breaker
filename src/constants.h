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

		//Game consts (same as above)
		inline constexpr float ballRadius{ 20.0f };
		inline const sf::Color ballColor{ sf::Color::White };
		//inline constexpr double ballSpeed{ 10.0 };
		inline const sf::Color wallColor{ 24, 45, 42 };
		inline int wallThickness{ 20 };

		//Mathematical consts (don't touch these)
		inline constexpr double degToRad{ 0.0174532925 };
		inline constexpr double radToDeg{ 57.29578 };
	}

#endif
