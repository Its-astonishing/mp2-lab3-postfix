#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

const int MaxMemSize = 10;
template <class uni>
class TStack
{
    uni *pMem;
    int size;
    int topIndex;
public:
    TStack(int _size = MaxStackSize) :
        size(_size)
    {
        if (_size<1 || _size >MaxStackSize)
            throw "incorrect size";
        pMem = new uni[size];
        topIndex = -1;
    }
    ~TStack()
    {
        delete[] pMem;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool isFull()
    {
        return topIndex == (size - 1); // 4 elems, top index = 3... 3==(4-1)
    }

    void push_back(uni bf)
    {
        if (!isFull())
        {
            topIndex++;
            pMem[topIndex] = bf;
        }
    }
    uni pop()
    {
        int tmp = topIndex;
        topIndex--;
        return pMem[tmp];
    }
    uni top()
    {
        return pMem[topIndex];
    }
    int GetSize()
    {
        return topIndex + 1;
    }

};

#endif
