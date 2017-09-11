#include <iostream>
#include <cassert>
#include<cmath>

#include "EntityVector.h"
#include "EntityRingList.h"
#include "Entity.h"

void print(const Entity &entity)
{
    std::cout << entity.m_x << "," << entity.m_y;
}

void testVector()
{
    //Create 10 test entities
    Entity entities[10];
    for (int i = 0; i < 10; i++)
    {
        entities[i] = Entity{ i,i };
    }

    //Push and Pop test
    EntityVector entityVector;
    assert(entityVector.Empty() == true);
    entityVector.PushBack(&entities[0]);
    assert(entityVector.Empty() == false);
    entityVector.PushBack(&entities[1]);
    entityVector.PushBack(&entities[2]);
    entityVector.PushBack(&entities[3]);
    assert(entityVector.Empty() == false);

    assert(entityVector.PopBack()->m_x == 3);
    assert(entityVector.Empty() == false);
    assert(entityVector.PopBack()->m_x == 2);
    assert(entityVector.PopBack()->m_x == 1);
    assert(entityVector.PopBack()->m_x == 0);
    assert(entityVector.Empty() == true);

    //Front and back test
    entityVector.PushBack(&entities[0]);
    assert(entityVector.Back()->m_x == 0);
    assert(entityVector.Front()->m_x == 0);

    entityVector.PushBack(&entities[1]);
    assert(entityVector.Back()->m_x == 1);
    assert(entityVector.Front()->m_x == 0);

    //Clear tests
    assert(entityVector.Empty() == false);
    entityVector.Clear();
    assert(entityVector.Empty() == true);

    //Insertion test
    entityVector.Insert(&entities[0], 0);
    assert(entityVector[0]->m_x == 0);

    entityVector.Insert(&entities[1], 0);
    assert(entityVector[0]->m_x == 1); //new
    assert(entityVector[1]->m_x == 0);

    entityVector.Insert(&entities[2], 0);
    assert(entityVector[0]->m_x == 2); //new
    assert(entityVector[1]->m_x == 1);
    assert(entityVector[2]->m_x == 0);

    entityVector.Insert(&entities[3], 1);
    assert(entityVector[0]->m_x == 2);
    assert(entityVector[1]->m_x == 3); //new
    assert(entityVector[2]->m_x == 1);
    assert(entityVector[3]->m_x == 0);

    entityVector.Insert(&entities[4], 4);
    assert(entityVector[0]->m_x == 2);
    assert(entityVector[1]->m_x == 3);
    assert(entityVector[2]->m_x == 1);
    assert(entityVector[3]->m_x == 0);
    assert(entityVector[4]->m_x == 4); //new

    entityVector.Insert(&entities[6], 3);
    assert(entityVector[0]->m_x == 2);
    assert(entityVector[1]->m_x == 3);
    assert(entityVector[2]->m_x == 1);
    assert(entityVector[3]->m_x == 6); //new
    assert(entityVector[4]->m_x == 0);
    assert(entityVector[5]->m_x == 4); //new
}

void ringListTest()
{
    //Create 10 test entities
    Entity entities[10];
    for (int i = 0; i < 10; i++)
    {
        entities[i] = Entity{ i,i };
    }

    //A 1 element list
    EntityRingList ringList1(1);
    ringList1.Push(&entities[0]);
    assert(ringList1[0]->m_x == 0);

    ringList1.Push(&entities[1]);
    assert(ringList1[0]->m_x == 1);

    //A 3 element list
    EntityRingList ringList3(3);
    ringList3.Push(&entities[0]);
    assert(ringList3[0]->m_x == 0);

    ringList3.Push(&entities[1]);
    assert(ringList3[0]->m_x == 0);
    assert(ringList3[1]->m_x == 1);//new

    ringList3.Push(&entities[2]);
    assert(ringList3[0]->m_x == 0);
    assert(ringList3[1]->m_x == 1);
    assert(ringList3[2]->m_x == 2);//new

    ringList3.Push(&entities[3]);
    assert(ringList3[0]->m_x == 3);//new
    assert(ringList3[1]->m_x == 1);
    assert(ringList3[2]->m_x == 2);

    ringList3.Push(&entities[4]);
    assert(ringList3[0]->m_x == 3);
    assert(ringList3[1]->m_x == 4);//new
    assert(ringList3[2]->m_x == 2);

    ringList3.Push(&entities[5]);
    assert(ringList3[0]->m_x == 3);
    assert(ringList3[1]->m_x == 4);
    assert(ringList3[2]->m_x == 5);//new

    ringList3.Push(&entities[6]);
    assert(ringList3[0]->m_x == 6);//new
    assert(ringList3[1]->m_x == 4);
    assert(ringList3[2]->m_x == 5);
}

void sort(EntityVector& vector, int centerPosX, int centerPosY)
{
    //Compare function
    auto  compare = [centerPosX, centerPosY](Entity* a, Entity* b)
    {
        auto sqrLengthA = pow(centerPosX - a->m_x, 2) + pow(centerPosY - a->m_y, 2);
        auto sqrLengthB = pow(centerPosX - b->m_x, 2) + pow(centerPosY - b->m_y, 2);

        return sqrLengthA > sqrLengthB;
    };

    //Bubblesort!
    const int vectorSize = vector.Size();
    for (int i = 0; i < (vectorSize - 1); i++)
    {
        for (int j = 0; j < vectorSize - i - 1; j++)
        {
            if (compare(vector[j], vector[j + 1]))
            {
                //Swap elements
                auto swap = vector[j];
                vector.Replace(vector[j + 1], j);
                vector.Replace(swap, j + 1);
            }
        }
    }
}

void testSort()
{
    Entity e1{ 0, 0 };
    Entity e2{ 1, 1 };
    Entity e3{ 1, 2 };
    Entity e4{ 1, 3 };
    Entity e5{ 3, 1 };
    Entity e6{ 0, 1 };
    Entity e7{ 1, 0 };
    Entity e8{ 2, 2 };

    EntityVector vector;
    vector.PushBack(&e1);
    vector.PushBack(&e2);
    vector.PushBack(&e3);
    vector.PushBack(&e4);
    vector.PushBack(&e5);
    vector.PushBack(&e6);
    vector.PushBack(&e7);
    vector.PushBack(&e8);

    //Original array
    for (int i = 0; i < vector.Size(); i++)
    {
        print(*vector[i]);
        std::cout << "; ";
    }
    std::cout << std::endl;

    sort(vector, 1, 1);
    for (int i = 0; i < vector.Size(); i++)
    {
        print(*vector[i]);
        std::cout << "; ";
    }

    EntityVector vec2 = vector;
}

int main()
{
    testVector();

    ringListTest();

    testSort();

    return 0;
}

