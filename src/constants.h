#ifndef CONSTANTS_H
#define CONSTANTS_H

	#include <SFML/Graphics.hpp>

	namespace constant
	{
    //Color consts
    inline const sf::Color blockColor{ 26, 63, 229 };
    inline const sf::Color ballColor{ 229, 192, 26 };
    inline const sf::Color textColor{ 234, 205, 72 };
    inline const sf::Color wallColor{ 43, 12, 108 };
    inline const sf::Color arrowColor{ 229, 210, 125 };
    inline const sf::Color backgroundColor{ 3, 7, 25 };

		//Game consts
		inline constexpr float ballRadius{ 15.0f };

		inline constexpr double ballSpeed{ 2000.0 };

		inline constexpr int wallThickness{ 20 };
		inline constexpr int blocksInRow{ 7 };
		inline constexpr int blocksInColumn{ 8 };  	//Number of blocks + 1 block-size gap on the top
		inline constexpr double blockSize{ 100.0 };
		inline constexpr double gapSize{ 5.0 };

		//Window consts
		inline constexpr double windowWidth{ 2 * wallThickness
																			+ (blocksInRow + 1) * gapSize
																			+ blocksInRow * blockSize };
		inline constexpr double windowHeight{ wallThickness
		 																	  + (blocksInColumn + 3) * gapSize
																			  + (blocksInColumn + 1) * blockSize };
		inline constexpr sf::Uint32 windowStyle{ sf::Style::Default };

		//Mathematical consts
		inline constexpr double degToRad{ 0.0174532925 };
		inline constexpr double radToDeg{ 57.29578 };
	}

#endif
