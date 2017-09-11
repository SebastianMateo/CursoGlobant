#pragma once
#include "Entity.h"

class EntityVector {

private:
    int mReservedSize;
    int mSize;

    Entity **mArray;

    const int defaultVectorSize = 2;

public:
    EntityVector();
    ~EntityVector();
    EntityVector::EntityVector(const EntityVector &other);

    void Insert(Entity* newEntity, int index);
    void PushBack(Entity* newEntity);
    Entity* PopBack();

    Entity* Front();
    Entity* Back();

    void Reserve(int newSize);
    void Clear();

    bool Empty() const;

    Entity* operator[](int index) const;

    //
    inline int Size() const { return mSize; };
    inline void Replace(Entity* newEntity, int index) { mArray[index] = newEntity; }
};