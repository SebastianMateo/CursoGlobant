#include "EntityVector.h"
#include <algorithm>
#include <iterator>
#include <cassert>

EntityVector::EntityVector() : mReservedSize(defaultVectorSize), mSize(0)
{
    mArray = new Entity*[defaultVectorSize] {};
}

EntityVector::~EntityVector()
{
    delete[] mArray;
}

EntityVector::EntityVector(const EntityVector &other)
{
    mArray = new Entity*[other.mReservedSize];
    mSize = other.mSize;
    mReservedSize = other.mReservedSize;

    memcpy(mArray, other.mArray, sizeof(Entity*) * mSize);
}

//Inserts elements at the specified location in the vector.
//Causes reallocation if the new size is greater than the reserved size
void EntityVector::Insert(Entity* newEntity, int index)
{
    //Check if we have enough size
    if (mSize == mReservedSize)
    {
        Reserve(mSize + defaultVectorSize);
    }

    //Shit all elements 1 to the right
    mSize++;
    for (int i = mSize - 1; i > index; i--)
    {
        mArray[i] = mArray[i - 1];
    }
    mArray[index] = newEntity;
}

void EntityVector::PushBack(Entity* newEntity)
{
    //Check if we have enough size
    if (mSize == mReservedSize)
    {
        Reserve(mSize + defaultVectorSize);
    }

    //Add the element to the array
    mArray[mSize] = newEntity;
    mSize++;
}

//Returns and remove the last element from the collections
//Undefined if the collection is empty
Entity* EntityVector::PopBack()
{
    assert(mSize > 0);

    Entity* returnEntity = mArray[mSize - 1];
    mSize--;

    return returnEntity;
}

//Returns the first element from the collections
//Undefined if the collection is empty
Entity* EntityVector::Front()
{
    assert(mSize > 0);

    return mArray[0];
}

//Returns the first element from the collections
//Undefined if the collection is empty
Entity* EntityVector::Back()
{
    assert(mSize > 0);

    return mArray[mSize - 1];
}

//Undefined if the new size can't hold the current elements
void EntityVector::Reserve(int newSize)
{
    assert(newSize > mReservedSize);

    //Allocate a new array, copying the elements
    Entity **temp = new Entity*[newSize];
    std::copy(&mArray[0], &mArray[mSize], temp);
    delete[] mArray;
    mArray = temp;

    //We save the new reserved size
    mReservedSize = newSize;
}

void EntityVector::Clear()
{
    mSize = 0;
}

bool EntityVector::Empty() const
{
    return mSize == 0;
}

//Returns the index element from the collection
//Undefined if the collection is empty
Entity* EntityVector::operator[](int index) const
{
    assert(index < mSize);
    return mArray[index];
}