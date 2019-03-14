#ifndef GUARD_VERTEXDEQUE_HPP
#define GUARD_VERTEXDEQUE_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class VertexDeque
{
public:
    VertexDeque();
    VertexDeque(size_t size);

    sf::Vertex& operator[](size_t i);
    const sf::Vertex& operator[](size_t i) const;

    size_t size() const;

    void push(const sf::Vertex& object);
    void pop();
    void clear();
    void reserve(size_t r);

    void setFixedSize(bool fxSz);

private:
    void flush();

private:
    std::vector<sf::Vertex> mVertices;
    size_t                  mFirst;
    size_t                  mSizeLimit;
    bool                    mFixedSize;
};


#endif