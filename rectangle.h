/* file rectangle.h
*This file creates a class called Rectangle which inherits from the Shapes class
*Contains a constructor, a class and a draw function
*/
#pragma once
#include "shapes.h"
//! Inlcuding the header file of 'shapes' so that this header file can inherit from it

class Rectangle :public Shapes//! Creating the class Rectangle and using Shapes class
{
private:

public:
	Rectangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4, sf::Color colour);//! Constructor
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;//! Draw function
};
