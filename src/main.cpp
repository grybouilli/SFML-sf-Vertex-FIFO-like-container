#include <vector>
#include <SFML/Graphics.hpp>
#include "hdr/VertexDeque.hpp"

int main()
{
	sf::Time elapsed = sf::Time::Zero;

	auto toPush = 10000;
	auto limitSz = 500;
	std::vector<sf::Vertex> vertices_1 {};
	sf::Vertex v(sf::Vector2f(100,100), sf::Color::White);

	VertexDeque vertices_2 {};
	vertices_2.reserve(limitSz);
	//
	sf::Clock clock;
	for(auto i = 0; i != toPush; ++i)
	{
		vertices_1.push_back(v);
		if(vertices_1.size() > limitSz)
		{
			vertices_1.erase(vertices_1.begin());
		}
	}
	elapsed = clock.restart();
	std::cout << elapsed.asSeconds() << " sec elapsed for std::vector<sf:Vertex> operations" << std::endl;

	for(auto i = 0; i != toPush; ++i)
	{
		vertices_2.push(v);
	}
	elapsed = clock.restart();
	std::cout << elapsed.asSeconds() << " sec elapsed for VertexDeque operations" << std::endl;

}