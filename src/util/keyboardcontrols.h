#ifndef KEYBOARD_CONTROLS_H
#define KEYBOARD_CONTROLS_H

	#include <SFML/Graphics.hpp>

	class KeyboardControls
	{
		public:
			KeyboardControls()
				: moveUp{ sf::Keyboard::Unknown },
				  moveDown{ sf::Keyboard::Unknown },
				  moveRight{ sf::Keyboard::Unknown },
				  moveLeft{ sf::Keyboard::Unknown },
				  pause{ sf::Keyboard::Unknown }
			{

			}

			KeyboardControls(sf::Keyboard::Key up, sf::Keyboard::Key down,
											 sf::Keyboard::Key right, sf::Keyboard::Key left,
											 sf::Keyboard::Key pause)
				: moveUp{ up },
				  moveDown{ down },
				  moveRight{ right },
				  moveLeft{ left },
				  pause{ pause }
			{

			}

		sf::Keyboard::Key moveUp;
		sf::Keyboard::Key moveDown;
		sf::Keyboard::Key moveRight;
		sf::Keyboard::Key moveLeft;
		sf::Keyboard::Key pause;
	};

#endif
