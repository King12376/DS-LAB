#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    Node() {
        data = 0;
        next = NULL;
    }
    int data;
    struct Node* next;
};

class Set {
public:
    Set() {
        element = NULL;
    }

    // Add an element to the set, return true on success and false if it's a duplicate.
    bool addElement(int e) {
        Node* newNode = new Node();
        newNode->data = e;

        if (element == NULL) {
            element = newNode;
            return true;
        }

        Node* cur = element;
        Node* prev = nullptr;

        while (cur != nullptr) {
            if (cur->data == e) {
                delete newNode;
                return false; // Element already exists in the set
            }

            prev = cur;
            cur = cur->next;
        }

        prev->next = newNode;
        return true;
    }

    // Union two sets and return the result.
    Set* unions(Set* b) {
        Set* result = new Set();

        Node* curA = element;
        Node* curB = b->element;

        while (curA != nullptr) {
            result->addElement(curA->data);
            curA = curA->next;
        }

        while (curB != nullptr) {
            result->addElement(curB->data);
            curB = curB->next;
        }

        return result;
    }

    // Intersect two sets and return the result.
    Set* intersections(Set* b) {
        Set* result = new Set();
        Node* curA = element;

        while (curA != nullptr) {
            if (b->contains(curA->data)) {
                result->addElement(curA->data);
            }
            curA = curA->next;
        }

        return result;
    }

    // Check if two sets are equivalent.
    bool equivalent(Set* b) {
        return (this->intersections(b)->isEmpty() && b->intersections(this)->isEmpty());
    }

    // Check if the set contains a specific element.
    bool contains(int e) {
        Node* cur = element;
        while (cur != nullptr) {
            if (cur->data == e) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    // Check if the set is empty.
    bool isEmpty() {
        return (element == nullptr);
    }

    void listAll() {
        Node* cur = element;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    Node* element;
};

int main() {
    Set* a = new Set();
    Set* b = new Set();
    Set* c;

    a->addElement(1);
    a->addElement(2);
    a->addElement(3);
    b->addElement(3);
    b->addElement(4);
    b->addElement(5);
    b->addElement(5);

    c = a->unions(b);
    cout << "Union: ";
    c->listAll();

    c = a->intersections(b);
    cout << "Intersection: ";
    c->listAll();

    if (a->equivalent(b)) {
        cout << "Equivalent!\n";
    } else {
        cout << "Not equivalent.\n";
    }
}
