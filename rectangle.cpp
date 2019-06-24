/* file rectangle.cpp
*This file creates a class called Rectangle which inherits from the Shapes class
*Contains a constructor, a class and a draw function
*/
#include "rectangle.h"
//! Including the header file for rectangle, to inherit the class
Rectangle::Rectangle(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4, sf::Color colour)//! Using the constructor with the class
{
	m_vertexarray.setPrimitiveType(sf::Quads);
	m_vertexarray.resize(4);//! Setting the amount of points to four as it's a rectangle
							//!Set the position of the points of the rectangle as the vectors declared in 'Rectangle'
	m_vertexarray[0].position = point1;
	m_vertexarray[1].position = point2;
	m_vertexarray[2].position = point3;
	m_vertexarray[3].position = point4;
	//! Setting the colour for the rectangle as the variable colour
	m_vertexarray[0].color = colour;
	m_vertexarray[1].color = colour;
	m_vertexarray[2].color = colour;
	m_vertexarray[3].color = colour;
}
void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states)const//! Used for drawing the shape 'rectangle'
{
	target.draw(m_vertexarray);
}
