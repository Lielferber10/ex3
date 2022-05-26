#include "Queue.h"
#include <stdlib.h>

//copy constractur
Queue::Queue(const Queue& queue):
m_firstNode(queue.m_firstNode),
m_lastNode(queue.m_lastNode),
m_size(queue.m_size), 
{
    for(int i = 0; i < queue.m_size; i++)
    {
        
    }
}

Queue::pushBack(T value) 
{
    if(last==first)
    {
        if()
        first.value = value;
        Node newNode = new Node(Null,first,0);
        last.next = newNode;
    }

}

}