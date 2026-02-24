#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************** Struct ****************/
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode* next;
};

/**************** Class ****************/
class LinkedList {
protected:
    struct studentNode* start;
    struct studentNode** now;

public:
    LinkedList();
    ~LinkedList();

    void InsNode(const char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    virtual void ShowNode();
};

class NewList : public LinkedList {
public:
    void InsertNode(const char n[], int a, char s, float g);
    void GoFirst();
    void ShowNode();
};

/**************** Implementation ****************/

LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    struct studentNode* temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkedList::InsNode(const char n[], int a, char s, float g) {

    struct studentNode* newNode =
        (struct studentNode*)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = *now;
    *now = newNode;
}

void LinkedList::DelNode() {

    if (*now != NULL) {
        struct studentNode* temp = *now;
        *now = (*now)->next;
        free(temp);
    }
}

void LinkedList::GoNext() {

    if (*now != NULL && (*now)->next != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::ShowNode() {

    if (*now != NULL) {
        printf("%s %d %c %.2f\n",
               (*now)->name,
               (*now)->age,
               (*now)->sex,
               (*now)->gpa);
    }
}

void NewList::InsertNode(const char n[], int a, char s, float g) {
    InsNode(n, a, s, g);
}

void NewList::GoFirst() {
    now = &start;
}

void NewList::ShowNode() {

    if (start != NULL && *now != NULL) {
        printf("%s %s\n", start->name, (*now)->name);
    }
}

/**************** Main ****************/

int main() {

    LinkedList listA;
    NewList listB;
    LinkedList* listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);

    listA.GoNext();
    listA.ShowNode();

    listB.InsertNode("four", 4, 'D', 4.4);
    listB.InsertNode("five", 5, 'E', 5.5);
    listB.InsertNode("six", 6, 'F', 6.6);

    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}
