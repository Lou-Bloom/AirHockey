/* file shapes.h
*This file creates a class called Arc which inherits from the sf::drawable class
*Contains a class and a draw function
*/
#pragma once
#include "SFML/Graphics.hpp"
using namespace std;
class Shapes :public sf::Drawable //! Creating the Shapes class, which inherits from the sf::Drawable class
{
protected:
	sf::VertexArray m_vertexarray;
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0; //! Draw funtion
};
