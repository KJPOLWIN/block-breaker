#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

	#include <SFML/Graphics.hpp>

	enum class AnimationStatus
	{
		endless,
		in_progress,
		finished
	};

	class AnimatedSprite
	{
		public:
			//Constructor;
			AnimatedSprite(sf::Texture &texture, 	//Animation sheet,
						   sf::Vector2f size,						//Size of sprite
						   int frameNumber, 						//Number of frames in one animation
						   double frameDuration)				//How many seconds will one frame last
				: sprite{ sf::Sprite(texture) },
				  spriteSize{ size },
				  currentAnimationFrame{ sf::Vector2i(0, 0) },
				  frameCount{ frameNumber },
				  currentTime{ 0.0 },
				  switchTime{ frameDuration },
				  status{ AnimationStatus::in_progress }
			{
				//Setting sprite's texture and origin point
				AnimatedSprite::sprite.setOrigin(spriteSize.x / 2, spriteSize.y / 2);

				//Switching animation to endless 0
				AnimatedSprite::setAnimation(0, true);
			}

			//Default constructor; it was declared to avoid compiler errors
			AnimatedSprite()
				: sprite{ sf::Sprite() },
				  spriteSize{ sf::Vector2f(0, 0) },
				  currentAnimationFrame{ sf::Vector2i(0, 0) },
				  frameCount{ 0 },
				  currentTime{ 0.0 },
				  switchTime{ 0.0 },
				  status{ AnimationStatus::in_progress }
			{
				//Switching animation to endless 0
				AnimatedSprite::setAnimation(0, true);
			}

			//Setting animation;
			void setAnimation(int animationNumber, 	//Position of animation (top-left is 0)
							  				bool isItEndless);		//After endless animation will run again

			//Updating animation; elapsedTime in seconds
			void update(double elapsedTime);

			//Drawing on window specified in argument
			void draw(sf::RenderWindow *currentWindow);

			//Setters/getters to control position and rotation
			void setPosition(sf::Vector2f position);
			sf::Vector2f getPosition();

			void setRotation(double rotation);
			double getRotation();

			sf::Vector2f getSize();

			bool isInProgress(int animationId)
			{
				return currentAnimationFrame.y == animationId;
			}

		private:
			//Actual sprite which will be drawed on window by SFML function
			sf::Sprite sprite;

			//Size of the sprite; used to calculate sprite's animation frame size
			sf::Vector2f spriteSize;
			//Part of texture which is drawed on screen;
			//it's moving is y axis to change animation and in x axis to change animation's frame
			sf::Vector2i currentAnimationFrame;
			//How many frames there are in animation
			int frameCount;
			//Timer; when current time is greater than switch time, animation frame is changed
			double currentTime;
			double switchTime;

			//If animation is finished or not
			AnimationStatus status;
	};

#endif
