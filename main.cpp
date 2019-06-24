/*!
\file main.cpp
\brief Contains the entry point for the application
*P17213769
*/

#include <Box2D/Box2D.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "rectangle.h"
#include "circle.h"

/*!< This is a bool function that is used for the interactions between sprites
*So that I can have them collide in a more satisfying way
*/
bool intersects(sf::Sprite& c1, sf::Sprite& rect2) 
{
	sf::FloatRect circle = c1.getGlobalBounds();
	sf::FloatRect Sprite = rect2.getGlobalBounds();
	return circle.intersects(Sprite);
}

int playerOneScore;
int playerTwoScore;

void main() /*!< Entry point for the application */
{
	sf::RenderWindow window(sf::VideoMode(1024, 800), "CW Starter"); /*!< Open main window */

	sf::Font p1Font;/*!< Naming the font that I am using p1Font */
	if (!p1Font.loadFromFile("//vfiler2.lec-admin.dmu.ac.uk/Home9/P17213769/Documents/My Pictures/fonts/ArialCE.ttf"))
	{
		std::cout << "Font not loaded" << std::endl;
	}
	sf::Event event;
	sf::Event eventTwo;
	sf::Texture pOneTex;/*!<Naming a texture pOneTex */
	sf::Texture pTwoTex;/*!<Naming a texture pTwoTex*/
	sf::Texture puckTex;/*!<Naming a texture puckTex*/
	sf::Texture boundry;/*!<Naming a texture boundry*/
	sf::Texture boundryDown;/*!<Naming a texture boundryDown*/
	sf::Texture goal;/*!<Naming a texture goal*/
	sf::Texture p1WinTex;/*!<Naming a texture p1WinTex*/
	sf::Texture p2WinTex;/*!<Naming a texture p2WinTex*/
	sf::Texture ring;/*!<Naming a texture ring*/

	sf::Vector2<float>moveSpeed(0.5, 0.5);/*!< Sets the move speed */
	sf::Vector2f velocity(sf::Vector2f(0, 0));;/*!< Sets the velocity */

	//if (!texture.loadFromFile("Pusher_1.png"))
	//These check whether a texture has loaded in and then output a message if they haven't
	if (!ring.loadFromFile("H:/Documents/My Pictures/AirHockeyRing.png"))
	{

		std::cout << "Ring texture problem" << std::endl;
	}
	if (!p1WinTex.loadFromFile("H:/Documents/My Pictures/playerOneWinner.png"))
	{

		std::cout << "Player one winner texture problem" << std::endl;
	}
	if (!p2WinTex.loadFromFile("H:/Documents/My Pictures/playerTwoWinner.png"))
	{

		std::cout << "Player two winner texture problem" << std::endl;
	}
	if (!pOneTex.loadFromFile("H:/Documents/My Pictures/Pusher3.png"))
	{
	
		std::cout << "Player one texture problem" << std::endl;
	}
	if (!pTwoTex.loadFromFile("H:/Documents/My Pictures/Pusher2.png"))
	{

		std::cout << "Player two texture problem" << std::endl;
	}
	if (!puckTex.loadFromFile("H:/Documents/My Pictures/Puck.png"))
	{

		std::cout << "Puck texture problem" << std::endl;
	}
	if (!boundry.loadFromFile("H:/Documents/My Pictures/airHockeyBoundry.png"))
	{
		std::cout << "Boudry texture problem" << std::endl;
	}
	if (!boundryDown.loadFromFile("H:/Documents/My Pictures/airHockeyBoundryDown.png"))
	{
		std::cout << "Boudry down texture problem" << std::endl;
	}
	if (!goal.loadFromFile("H:/Documents/My Pictures/airHockeyGoal.png"))
	{
		std::cout << "Goal texture problem" << std::endl;
	}
    //! Instaniate any classes here
    //! Creates an instance for each shape class and sets the the coordinates and the colours for them all 
	Rectangle background(sf::Vector2f(0, 0), sf::Vector2f(0, 1040), sf::Vector2f(1040, 1040), sf::Vector2f(1040, 0), sf::Color::White);
	;/*!< This creates the score object for player 1 
	 * It gives it a font:
	 *a colour
	 *a position
	 *and chooses the text being disaplyed
	 */
	sf::Text p1Score;;
	p1Score.setFont( p1Font );
	p1Score.setCharacterSize(20);
	p1Score.setFillColor(sf::Color::Green);
	p1Score.setPosition(31, 0);
	p1Score.setString("Player 1: 0");
	/*!< This creates the score object for player 2
	* It gives it a font:
	*a colour
	*a position
	*and chooses the text being disaplyed
	*/
	sf::Text p2Score;
	p2Score.setFont(p1Font);
	p2Score.setCharacterSize(20);
	p2Score.setFillColor(sf::Color::Green);
	p2Score.setPosition(900, 0);
	p2Score.setString("Player 2: 0");
	/*!< Creates the top rectangle
	*Gives it a texture and position
	*/
	sf::Sprite boundryTop;
	boundryTop.setTexture(boundry);
	boundryTop.setPosition(sf::Vector2f(0.f, 0.f));
	/*!< Creates the bottom rectangle
	*Gives it a texture and position
	*/
	sf::Sprite boundryBottom;
	boundryBottom.setTexture(boundry);
	boundryBottom.setPosition(sf::Vector2f(8.f, 780.f));
	/*!< Creates the player one win screen
	*Gives it a texture and position
	*/
	sf::Sprite playerOneWin;
	playerOneWin.setTexture(p1WinTex);
	playerOneWin.setPosition(-2000, 0);
	/*!< Creates the player two win screen
	*Gives it a texture and position
	*/
	sf::Sprite playerTwoWin;
	playerTwoWin.setTexture(p2WinTex);
	playerTwoWin.setPosition(-2000, 0);
	/*!< Creates the player one goal
	*Gives it a texture and position
	*/
	sf::Sprite player1Goal;
	player1Goal.setTexture(goal);
	player1Goal.setPosition(sf::Vector2f(-100.f, 0.f));
	/*!< Creates the player two goal
	*Gives it a texture and position
	*/
	sf::Sprite player2Goal;
	player2Goal.setTexture(goal);
	player2Goal.setPosition(sf::Vector2f(1030.f, 0.f));
	/*!< Creates the left rectangle at the top
	*Gives it a texture and position
	*/
	sf::Sprite boundryLeftUp;
	boundryLeftUp.setTexture(boundryDown);
	boundryLeftUp.setPosition(sf::Vector2f(0.f, 0.f));
	/*!< Creates the left rectangle at the bottom
	*Gives it a texture and position
	*/
	sf::Sprite boundryLeftDown;
	boundryLeftDown.setTexture(boundryDown);
	boundryLeftDown.setPosition(sf::Vector2f(0.f, 600.f));
	/*!< Creates the right rectangle at the top
	*Gives it a texture and position
	*/
	sf::Sprite boundryRightUp;
	boundryRightUp.setTexture(boundryDown);
	boundryRightUp.setPosition(sf::Vector2f(995.f, 8.f));
	/*!< Creates the right rectangle at the bottom
	*Gives it a texture and position
	*/
	sf::Sprite boundryRightDown;
	boundryRightDown.setTexture(boundryDown);
	boundryRightDown.setPosition(sf::Vector2f(995.f, 600.f));
	/*!< Creates the air hockey ring background
	*Gives it a texture and position
	*/
	sf::Sprite airHockeyRing;
	airHockeyRing.setTexture(ring);
	airHockeyRing.setPosition(0.f, 0.f);
	/*!< Creates player one
	*Gives it a texture and position
	*/
	sf::Sprite playerOne;
	playerOne.setTexture(pOneTex);
	playerOne.setPosition(sf::Vector2f(115.f, 350.f));
	/*!< Creates player two
	*Gives it a texture and position
	*/
	sf::Sprite playerTwo;
	playerTwo.setTexture(pTwoTex);
	playerTwo.setPosition(sf::Vector2f(810.f, 350.f));
	/*!< Creates the puck
	*Gives it a texture and position
	*/
	sf::Sprite puck;
	puck.setTexture(puckTex);
	puck.setPosition(sf::Vector2f(350.f, 350.f));

	float fFrameTime = 1.f / 60.f;
	int index = 0;
	/*!<  Start a clock to provide time for the physics */
	sf::Clock clock;

	/*!<  Run a game loop */
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{		
	    }	
		/*!< These are the if statements that allow the player to control either of the players */
		if (event.type == sf::Event::KeyReleased) /*!< It checks whether a key has been pressed then depending on the key the player will move in a particular direction */
		{
			if (event.key.code == sf::Keyboard::W)
			{
				playerOne.move(0,-0.5);
			}
			if (event.key.code == sf::Keyboard::S)
			{
				playerOne.move(0,0.5);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				playerOne.move(-0.5,0);
			}
			if (event.key.code == sf::Keyboard::D)
			{
				playerOne.move(0.5,0);
			}
			if (event.key.code == sf::Keyboard::Space)/*!< This stops the player */
			{
				playerOne.move(0, 0);
			}
			if (event.key.code == sf::Keyboard::Escape)/*!< This ends the game and closes the application */
			{
				window.close();
			}

			if (event.key.code == sf::Keyboard::Up)
			{
				playerTwo.move(0, -0.5);
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				playerTwo.move(0, 0.5);
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				playerTwo.move(-0.5, 0);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				playerTwo.move(0.5, 0);
			}
			if (event.key.code == sf::Keyboard::BackSpace)
			{
				playerTwo.move(0, 0);
			}
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
		/*!< When player one collides with player two they will move accordingly*/
		if (playerOne.getGlobalBounds().intersects(playerTwo.getGlobalBounds()))
		{
			std::cout << "Player 1 has collided with player 2" << std::endl;/*!< This message is displayed whenever this occurs */
			playerOne.move(-1, -1);
		}
		/*!< When player two collides with player one they will move accordingly*/
		if (playerTwo.getGlobalBounds().intersects(playerOne.getGlobalBounds()))
		{
			std::cout << "Player 2 has collided with player 1" << std::endl;/*!< This message is displayed whenever this occurs */
			playerTwo.move(0, 0);
		}
		/*!< Collision functions for player one */
		/*!< When player one collides with the top of the ring they will move accordingly*/
		if (playerOne.getGlobalBounds().intersects(boundryTop.getGlobalBounds()))
		{
			std::cout << "Player 1 has collided with the ceiling" << std::endl;/*!< This message is displayed whenever this occurs */
			playerOne.move(0, 1);
		}
		/*!< When player one collides with the bottom of the ring they will move accordingly*/
		if (playerOne.getGlobalBounds().intersects(boundryBottom.getGlobalBounds()))
		{
			std::cout << "Player 1 has collided with the floor" << std::endl;/*!< This message is displayed whenever this occurs */
			playerOne.move(0, -1);
		}
		/*!< When player one collides with the left side up of the ring they will move accordingly*/
		if (playerOne.getGlobalBounds().intersects(boundryLeftUp.getGlobalBounds()))
		{
			std::cout << "Player 1 has collided with the left side" << std::endl;/*!< This message is displayed whenever this occurs */
			playerOne.move(1, 0);
		}
		/*!< When player one collides with the left side down of the ring they will move accordingly*/
		if (playerOne.getGlobalBounds().intersects(boundryLeftDown.getGlobalBounds()))
		{
			std::cout << "Player 1 has collided with the left side" << std::endl;/*!< This message is displayed whenever this occurs */
			playerOne.move(1, 0);
		}
		/*!< When player one collides with the right side up of the ring they will move accordingly*/
		if (playerOne.getGlobalBounds().intersects(boundryRightUp.getGlobalBounds()))
		{
			std::cout << "Player 1 has collided with the right side" << std::endl;/*!< This message is displayed whenever this occurs */
			playerOne.move(-1, 0);
		}
		/*!< When player one Collides with the right side down of the ring they will move accordingly*/
		if (playerOne.getGlobalBounds().intersects(boundryRightDown.getGlobalBounds()))
		{
			std::cout << "Player 1 has collided with the right side" << std::endl;/*!< This message is displayed whenever this occurs */
			playerOne.move(-1, 0);
		}
		/*!< Collision functions for player two */
		/*!< When player two collides with the top of the ring they will move accordingly*/
		if (playerTwo.getGlobalBounds().intersects(boundryTop.getGlobalBounds()))
		{
			std::cout << "Player 2 has collided with the ceiling" << std::endl;/*!< This message is displayed whenever this occurs */
			playerTwo.move(0, 1);
		}
		/*!< When player two collides with the bottom of the ring they will move accordingly*/
		if (playerTwo.getGlobalBounds().intersects(boundryBottom.getGlobalBounds()))
		{
			std::cout << "Player 2 has collided with the floor" << std::endl;/*!< This message is displayed whenever this occurs */
			playerTwo.move(0, -1);
		}
		/*!< When player two collides with the left side up of the ring they will move accordingly*/
		if (playerTwo.getGlobalBounds().intersects(boundryLeftUp.getGlobalBounds()))
		{
			std::cout << "Player 2 has collided with the left side" << std::endl;/*!< This message is displayed whenever this occurs */
			playerTwo.move(1, 0);
		}
		/*!< When player two collides with the left down side of the ring they will move accordingly*/
		if (playerTwo.getGlobalBounds().intersects(boundryLeftDown.getGlobalBounds()))
		{
			std::cout << "Player 2 has collided with the left side" << std::endl;/*!< This message is displayed whenever this occurs */
			playerTwo.move(1, 0);
		}
		/*!< When player two collides with the right side up of the ring they will move accordingly*/
		if (playerTwo.getGlobalBounds().intersects(boundryRightUp.getGlobalBounds()))
		{
			std::cout << "Player 2 has collided with the right side" << std::endl;
			playerTwo.move(-1, 0);
		}
		/*!< When player two collides with the right side down of the ring they will move accordingly*/
		if (playerTwo.getGlobalBounds().intersects(boundryRightDown.getGlobalBounds()))
		{
			std::cout << "Player 2 has collided with the right side" << std::endl;/*!< This message is displayed whenever this occurs */
			playerTwo.move(-1, 0);
		}
		/*!<Collision for the puck*/
		/*!< The moveSpeed for the puck will change depending on the surface that it hits so that it bounces off it, including the players */
		if (intersects(puck, boundryTop) || (intersects(puck, boundryBottom))) {
			moveSpeed.y = -moveSpeed.y;
		}
		if (intersects(puck, boundryLeftUp) || (intersects(puck, boundryLeftDown))) {
			moveSpeed.x = -moveSpeed.x;
		}
		if (intersects(puck, boundryRightUp) || (intersects(puck, boundryRightDown))) {
			moveSpeed.x = -moveSpeed.x;
		}
		if (intersects(puck, playerOne) || (intersects(puck, playerTwo))) {
			moveSpeed.x = -moveSpeed.x;
		}
		/*!< When the puck hits the goal sprites it will add one to the opposite persons score of the goal sprite it collided with 
		*Then it sets the position of the puck to where it started as if it respawned
		*Then it displayes the updated score
		*/
		if (intersects(puck, player1Goal))
		{
			playerTwoScore++;
			puck.setPosition(350, 350);
			std::cout << "Player 2 : " << + playerTwoScore << std::endl;
		}
		/*!< This checks what the players scores are and then changes the text score displayed above each of them */
		if (playerOneScore == 1)
		{
			p1Score.setString("Player 1: 1");
		}
		if (playerOneScore == 2)
		{
			p1Score.setString("Player 1: 2");
		}
		if (playerOneScore == 3)
		{
			p1Score.setString("Player 1: 3");
		}
		if (intersects(puck, player2Goal))
		{
			playerOneScore++;
			puck.setPosition(350, 350);
			std::cout << "Player 1 : " << + playerOneScore << std::endl;
		}
		if (playerTwoScore == 1)
		{
			p2Score.setString("Player 2: 1");
		}
		if (playerTwoScore == 2)
		{
			p2Score.setString("Player 2: 2");
		}
		if (playerTwoScore == 3)
		{
			p2Score.setString("Player 2: 3");
		}
		/*!< When either of the player's scores equal three then a message displays
		*Then the position of the winner screen for the particular player is changed to cover the screen
		*/
		if (playerOneScore >= 3)
		{
			std::cout << "Player one is the winner" << std::endl;
			playerOneWin.setPosition(0, 0);
		}
		if (playerTwoScore >= 3)
		{
			std::cout << "Player two is the winner" << std::endl;
			playerTwoWin.setPosition(0, 0);
		}
		/*!< Gives movement to the puck from the beginning */
		puck.move(moveSpeed.x, moveSpeed.y);

		while (window.pollEvent(event))
		{
			// window closed button pressed
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {}

			if (event.type == sf::Event::MouseButtonPressed) {}
				
			if (event.type == sf::Event::MouseMoved) {}

			if (event.type == sf::Event::MouseWheelScrolled) {}

		}
		// Find out how much time has elapsed

		float m_fElapsedTime = clock.getElapsedTime().asSeconds();
		// If a frame has past the update the physics
		if (m_fElapsedTime > fFrameTime)
		{

			clock.restart();
		}
		window.clear(sf::Color(120,120,120));
		/*!< Drawing all of the sprites and SFML objects that are in the game
		*They are drawn in a particluar order so that they can be seen as intended
		*/
		window.draw(background);//The background

		window.draw(airHockeyRing);//The sprite used for the ring
		window.draw(boundryTop);//The rectangle at the top of the ring
		window.draw(boundryBottom);//The rectangle at the bottom of the ring
		window.draw(boundryLeftUp);//The top left side of the ring
		window.draw(boundryLeftDown);//The bottom left side of the ring
		window.draw(boundryRightUp);//The top right side of the ring
		window.draw(boundryRightDown);//The bottom right side of the ring
		
		window.draw(p1Score);//The score for player 1
		window.draw(p2Score);//The score for player 2

		window.draw(playerOne);//The sprite used for player one
		window.draw(playerTwo);//The sprite used for the second player

		window.draw(puck);//The puck
		
		window.draw(player1Goal);//Player one's goal
		window.draw(player2Goal);//Player two's goal

		window.draw(playerOneWin);//Drawing the player one win picture
		window.draw(playerTwoWin);//Drawing the player two win picture

		window.display();
	}
}