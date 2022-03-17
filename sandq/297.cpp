// implement queue from scratch

#include <bits/stdc++.h>
using namespace std;

struct queues *f = NULL;
struct queues *r = NULL;

struct queues
{
    int data;
    struct queues *next;
};

void enqueue(int value)
{
    struct queues *ptr = (struct queues *)malloc(sizeof(struct queues));
    ptr->data = value;
    ptr->next = NULL;
    if (f == NULL)
    {
        f = ptr;
        r = ptr;
    }
    else
    {
        r->next = ptr;
        r = ptr;
    }
}

void dequeue()
{
    struct queues *ptr = f;
    f = f->next;
    cout << ptr->data << " removed" << endl;
    free(ptr);
}

void display(struct queues *f)
{
    struct queues *ptr = f;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(30);
    enqueue(30);
    enqueue(30);
    enqueue(30);
    display(f);
    dequeue();
    dequeue();
    display(f);
    return 0;
}