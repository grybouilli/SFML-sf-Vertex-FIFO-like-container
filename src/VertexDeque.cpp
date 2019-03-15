#include "hdr/VertexDeque.hpp"
#include <stdexcept>

VertexDeque::VertexDeque()
: mVertices{}
, mFirst {0}
, mSizeLimit { 0 }
, mFixedSize { true }
{
	mVertices.reserve(1000);
}

VertexDeque::VertexDeque(size_t size)
: mVertices {size}
, mFirst {0}
, mSizeLimit { size / 4 }
, mFixedSize { true }
{

}

sf::Vertex& VertexDeque::operator[](size_t i)
{
	//delays the whole work to std::vector
	return mVertices[mFirst + i];
}

const sf::Vertex& VertexDeque::operator[](size_t i) const
{
	//delays the whole work to std::vector
	return mVertices[mFirst + i];
}

size_t VertexDeque::size() const
{
	return mVertices.size() - mFirst;
}

void VertexDeque::push(const sf::Vertex& object)
{
	mVertices.push_back(object);

	if(size() > mSizeLimit)
	{
		flush();
	}
}

void VertexDeque::pop()
{
	if(mFirst >= mVertices.size())
		throw std::logic_error("Segmentation Fault (Core Dump) : popping unexisting element");

	mFirst++;
}

void VertexDeque::clear()
{
	mVertices.clear();
}

void VertexDeque::flush()
{
	if(mFirst == 0)
		return;

	auto begin = mVertices.begin();
	mVertices.erase(begin, begin + mFirst);

	mFirst = 0;
}
