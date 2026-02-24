/*************************************************
 *  Linked List with Pointer-to-Pointer
 *  Concept: Inheritance & Polymorphism
 *************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;


/*********************** Struct ***********************/
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode* next;
};


/*********************** Class Prototype ***********************/
class LinkedList {
protected:
    studentNode* start;
    studentNode** now;

public:
    LinkedList();
    virtual ~LinkedList();

    void InsNode(char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    virtual void ShowNode() const;
};

class NewList : public LinkedList {
public:
    void InsertNode(char n[], int a, char s, float g);
    void GoFirst();
    void ShowNode() const override;
};


/*********************** Main ***********************/
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


/*********************** Implementation ***********************/

LinkedList::LinkedList()
    : start(nullptr), now(&start) {}


LinkedList::~LinkedList() {
    while (start != nullptr) {
        studentNode* temp = start;
        start = start->next;
        delete temp;
    }
    now = &start;
}


void LinkedList::InsNode(char n[], int a, char s, float g) {

    studentNode* newNode = new studentNode;

    strcpy(newNode->name, n);
    newNode->age  = a;
    newNode->sex  = s;
    newNode->gpa  = g;

    newNode->next = *now;
    *now = newNode;
}


void LinkedList::DelNode() {

    if (*now == nullptr)
        return;

    studentNode* temp = *now;
    *now = (*now)->next;
    delete temp;
}


void LinkedList::GoNext() {

    if (*now != nullptr && (*now)->next != nullptr) {
        now = &((*now)->next);
    }
}


void LinkedList::ShowNode() const {

    if (*now == nullptr)
        return;

    cout << (*now)->name << " "
         << (*now)->age  << " "
         << (*now)->sex  << " "
         << fixed << setprecision(2)
         << (*now)->gpa  << endl;
}


void NewList::InsertNode(char n[], int a, char s, float g) {
    InsNode(n, a, s, g);
}


void NewList::GoFirst() {
    now = &start;
}


void NewList::ShowNode() const {

    if (start == nullptr || *now == nullptr)
        return;

    cout << start->name << " "
         << (*now)->name << endl;
}
