#pragma once
#include "Entity.h"

class EntityRingList
{
private:
    int mMaxSize;
    int mSize;
    int mIndex;

    Entity **mArray;

public:
    EntityRingList(int size);
    ~EntityRingList();

    void Push(Entity* newEntity);

    Entity* operator[](int index) const;
};

