/* file circle.cpp
*This file creates a class called Circle which inherits from the Shapes class
*Contains a constructor, a float, a class and a draw function
*/
#include "circle.h"
//! Including the header file for circle, to inherit the class
Circle::Circle(sf::Vector2f origin, float fRadius, sf::Color colour) //! Using the constructor with the class
{
	m_vertexarray.setPrimitiveType(sf::TriangleFan);
	m_vertexarray.resize(32);//! Set the number of points, that being 32 as it's creating several triangle fans to make it look like a circle
							 //! Setting the position of the position of the center of the circle as the vector origin
	m_vertexarray[0].position = origin;
	//! Setting the colour of the circle as the variable colour
	m_vertexarray[0].color = colour;
	//! For loop that creates 32 triangle fans that create a circle when together
	for (int i = 1; i < 32; i++)
	{
		m_vertexarray[i].position = sf::Vector2f(origin.x + cos(fAngle) * fRadius, origin.y + sin(fAngle) * fRadius);
		fAngle = i * 6.28318531 / 30;
		m_vertexarray[i].color = colour;
	}
}
void Circle::draw(sf::RenderTarget& target, sf::RenderStates states)const//! Draw function
{
	target.draw(m_vertexarray);
}