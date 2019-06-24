/* file circle.h
*This file creates a class called Circle which inherits from the Shapes class
*Contains a constructor,a float, a class and a draw function
*/
#pragma once
#include "shapes.h"
//! Inlcuding the header file of 'shapes' so that this header file can inherit from it

class Circle :public Shapes//! Creates a class called Circle which inherits from Shapes
{
private:
	float fAngle = 0.0;//! Creating the variable fAngle and setting it's value

public:
	Circle(sf::Vector2f point1, float fRadius, sf::Color colour);//! Constructor
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;//! Draw function
};
