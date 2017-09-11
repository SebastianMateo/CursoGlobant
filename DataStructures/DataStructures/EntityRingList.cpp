#include "EntityRingList.h"

EntityRingList::EntityRingList(int size) : mMaxSize(size), mSize(0), mIndex(0)
{
    mArray = new Entity*[size] {};
}

EntityRingList::~EntityRingList()
{
    delete[] mArray;
}

void EntityRingList::Push(Entity* newEntity)
{
    mArray[mIndex] = newEntity;

    //We need to increment the size up to the moment we fill the array
    if (mSize < mMaxSize)
    {
        mSize++;
    }

    //We need to cycle the index, start again after pushing the last element
    mIndex++;
    if (mIndex == mMaxSize)
    {
        mIndex = 0;
    }
}

Entity* EntityRingList::operator[](int index) const
{
    int realIndex = index % mSize;

    return mArray[realIndex];
}
