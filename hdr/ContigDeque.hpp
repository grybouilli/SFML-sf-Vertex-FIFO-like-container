#ifndef GUARD_CONTIGDEQUE_HPP
#define GUARD_CONTIGDEQUE_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class VertexDeque
{
public:
    ContigDeque();
    ContigDeque(size_t size);

    sf::Vertex& operator[](size_t i);
    const sf::Vertex& operator[](size_t i) const;

    size_t size() const;

    void push(const sf::Vertex& object);
    void pop();
    void clear();

private:
    std::vector<sf::Vertex> mVertices;
    size_t                  mFirst;
    size_t                  mSizeLimit;
};

#include "ContigDeque.inl"

#endif