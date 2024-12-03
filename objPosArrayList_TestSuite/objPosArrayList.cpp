#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];

    //additional constructor
}


objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}


//copy assignment operator
objPosArrayList& objPosArrayList::operator=(const objPosArrayList& copy)
{
    int i;

    // check for self assignement
    if (this == &copy) 
    {
        return *this;
    }

    // clean up existing resources
    delete[] aList;

    // allocate memory
    listSize = copy.listSize;

    arrayCapacity = copy.arrayCapacity;

    aList = new objPos[arrayCapacity];

    // copy elements from other object
    for (i = 0; i < listSize; ++i) 
    {
        aList[i] = copy.aList[i];
    }

    return *this;
}


void objPosArrayList::insertHead(objPos thisPos)
{   listSize++;
    if(listSize >= ARRAY_MAX_CAP) return;
    for(int i = listSize-1; i > 0; i--)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    
}


void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize < ARRAY_MAX_CAP){
    aList[listSize] = thisPos;
    listSize++;
    }
}

void objPosArrayList::removeHead()
{
    if(listSize == 0) return;

    for(int i = 1; i < listSize; i++)
    {
        aList[i-1] = aList[i];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{

    if(listSize >= 1){
        listSize--;
        }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    if(index < 0)
    {
        index = 0;
    } 
    
    else if(index >= listSize && listSize != 0)
    {
        index = listSize - 1;
    }

    return aList[index];
}