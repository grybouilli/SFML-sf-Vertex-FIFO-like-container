#include "hdr/VertexDeque.hpp"
#include <stdexcept>

const size_t MAX_SIZE = 1000;

VertexDeque::VertexDeque()
: mVertices{}
, mFirst {0}
, mSizeLimit { MAX_SIZE }
, mFixedSize { true }
{
	mVertices.reserve(1000);
}

VertexDeque::VertexDeque(size_t size)
: mVertices {size}
, mFirst {0}
, mSizeLimit { size > MAX_SIZE ? size : MAX_SIZE }
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

	if(size() > mSizeLimit && mFirst > 0)
	{
		flush();
	} else
	{
		if(mFixedSize)
		{
			//fixed size array will have some datas lost over time
			pop();
		} else
		{
			mSizeLimit = 1.2 * mSizeLimit ;
		}
	}
}

void VertexDeque::pop()
{
	mFirst++;

	if(size()  > mSizeLimit)
	{
		flush();
	}
}

void VertexDeque::clear()
{
	mVertices.clear();
}

void VertexDeque::reserve(size_t r)
{
	if(r < mVertices.size())
	{
		mVertices.shrink_to_fit();
		mSizeLimit = mVertices.size();
	} else
	{
		mVertices.reserve(r);
		mSizeLimit = r;
	}
}

void VertexDeque::setFixedSize(bool fxSz)
{
	mFixedSize = fxSz;
}

void VertexDeque::flush()
{
	if(mFirst == 0)
		return;

	auto begin = mVertices.begin();
	mVertices.erase(begin, begin + mFirst);

	mFirst = 0;
}
