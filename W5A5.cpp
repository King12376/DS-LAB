#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 100

using namespace std;

class Node
{
public:
    Node()
    {
        next = NULL;
        pre = NULL;
    }
    Node(int n)
    {
        data = n;
        next = NULL;
        pre = NULL;
    }
    int getData() { return data; }
    Node *getNext() { return next; }
    Node *getPre() { return pre; }
    void setData(int d) { data = d; }
    void setNext(Node *n) { next = n; }
    void setPre(Node *p) { pre = p; }
private:
    int data;
    Node *next, *pre;
};

class List
{
public:
    List() { list = NULL; }
    List(int n) { generate(n); }

    void generate(int n)
    {
        int j;
        list = NULL;
        for (j = 0; j < n; j++)
            generate();
    }

    void generate()
    {
        Node *buf = new Node(rand());
        buf->setNext(list);
        if (list != NULL)
            list->setPre(buf);
        list = buf;
    }

    // Bubble Sort
    void bubbleSort()
    {
        if (list == NULL || list->getNext() == NULL)
            return; // Nothing to sort

        bool swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do
        {
            swapped = false;
            ptr1 = list;

            while (ptr1->getNext() != lptr)
            {
                if (ptr1->getData() > ptr1->getNext()->getData())
                {
                    // Swap the data
                    int temp = ptr1->getData();
                    ptr1->setData(ptr1->getNext()->getData());
                    ptr1->getNext()->setData(temp);
                    swapped = true;
                }
                ptr1 = ptr1->getNext();
            }
            lptr = ptr1;
        } while (swapped);
    }

    // Selection Sort
    void selectionSort()
    {
        if (list == NULL || list->getNext() == NULL)
            return; // Nothing to sort

        Node* cur = list;
        while (cur)
        {
            Node* min = cur;
            Node* temp = cur->getNext();
            while (temp)
            {
                if (temp->getData() < min->getData())
                    min = temp;
                temp = temp->getNext();
            }

            // Swap data
            int temp_data = cur->getData();
            cur->setData(min->getData());
            min->setData(temp_data);
            cur = cur->getNext();
        }
    }

    // Insertion Sort
    void insertionSort()
    {
        if (list == NULL || list->getNext() == NULL)
            return; // Nothing to sort

        Node* sorted = NULL;
        Node* cur = list;
        while (cur)
        {
            Node* next = cur->getNext();
            if (sorted == NULL || cur->getData() <= sorted->getData())
            {
                cur->setNext(sorted);
                cur->setPre(NULL);
                sorted = cur;
            }
            else
            {
                Node* search = sorted;
                while (search->getNext() != NULL && search->getNext()->getData() < cur->getData())
                    search = search->getNext();

                cur->setNext(search->getNext());
                cur->setPre(search);
                if (search->getNext() != NULL)
                    search->getNext()->setPre(cur);
                search->setNext(cur);
            }
            cur = next;
        }
        list = sorted;
    }

    void print()
    {
        Node *cur = list;
        while (cur != NULL)
        {
            cout << cur->getData() << " ";
            cur = cur->getNext();
        }
        cout << endl;
    }
private:
    Node *list;
};

int main()
{
    srand(time(NULL));
    List *l = new List(10);
    l->print();
    l->bubbleSort();
    l->print();

    l = new List(10);
    l->print();
    l->insertionSort();
    l->print();

    l = new List(10);
    l->print();
    l->selectionSort();
    l->print();
}
