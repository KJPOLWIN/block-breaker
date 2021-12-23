#ifndef CONSTANTS_H
#define CONSTANTS_H

	#include <SFML/Graphics.hpp>

	namespace constant
	{
		//Game consts (you can change these)
		inline constexpr float ballRadius{ 15.0f };
		inline const sf::Color ballColor{ sf::Color::White };
		inline constexpr double ballSpeed{ 2000.0 };
		inline const sf::Color wallColor{ 24, 45, 42 };
		inline constexpr int wallThickness{ 20 };
		inline constexpr int blocksInRow{ 5 };
		inline constexpr int blocksInColumn{ 8 };  	//Number of blocks + 1 block-size gap on the top
		inline constexpr double blockSize{ 100.0 };
		inline constexpr double gapSize{ 5.0 };

		//Window consts (same as above)
		inline constexpr double windowWidth{ 2 * wallThickness
																			+ (blocksInRow + 1) * gapSize
																			+ blocksInRow * blockSize };
		inline constexpr double windowHeight{ wallThickness
		 																	  + (blocksInColumn + 3) * gapSize
																			  + (blocksInColumn + 1) * blockSize };
		inline constexpr sf::Uint32 windowStyle{ sf::Style::Default };
		inline const sf::Color fpsCounterColor{ sf::Color::Red };

		//Mathematical consts (don't touch these)
		inline constexpr double degToRad{ 0.0174532925 };
		inline constexpr double radToDeg{ 57.29578 };
	}

#endif
