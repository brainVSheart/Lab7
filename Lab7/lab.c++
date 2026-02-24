/**************** Include ****************/
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

/**************** Struct ****************/
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode* next;
};

/**************** Class Prototype ****************/
class LinkedList {
protected:
    studentNode* start;
    studentNode** now;

public:
    LinkedList();
    virtual ~LinkedList();

    void InsNode(const char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    virtual void ShowNode();
};

class NewList : public LinkedList {
public:
    void InsertNode(const char n[], int a, char s, float g);
    void GoFirst();
    void ShowNode() override;
};

/**************** Main ****************/
int main() {

    LinkedList listA;
    NewList listB;
    LinkedList* listC = nullptr;

    listA.InsNode("one", 1, 'A', 1.1f);
    listA.InsNode("two", 2, 'B', 2.2f);
    listA.InsNode("three", 3, 'C', 3.3f);

    listA.GoNext();
    listA.ShowNode();

    listB.InsertNode("four", 4, 'D', 4.4f);
    listB.InsertNode("five", 5, 'E', 5.5f);
    listB.InsertNode("six", 6, 'F', 6.6f);

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

/**************** Implementation ****************/

LinkedList::LinkedList() : start(nullptr) {
    now = &start;
}

LinkedList::~LinkedList() {
    while (start != nullptr) {
        studentNode* temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkedList::InsNode(const char n[], int a, char s, float g) {

    studentNode* newNode = new studentNode;

    strncpy(newNode->name, n, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';

    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = *now;
    *now = newNode;
}

void LinkedList::DelNode() {

    if (now != nullptr && *now != nullptr) {
        studentNode* temp = *now;
        *now = (*now)->next;
        delete temp;
    }
}

void LinkedList::GoNext() {

    if (now != nullptr && *now != nullptr && (*now)->next != nullptr) {
        now = &((*now)->next);
    }
}

void LinkedList::ShowNode() {

    if (now != nullptr && *now != nullptr) {
        cout << (*now)->name << " "
             << (*now)->age << " "
             << (*now)->sex << " "
             << fixed << setprecision(2)
             << (*now)->gpa << endl;
    }
}

void NewList::InsertNode(const char n[], int a, char s, float g) {
    InsNode(n, a, s, g);
}

void NewList::GoFirst() {
    now = &start;
}

void NewList::ShowNode() {

    if (start != nullptr && now != nullptr && *now != nullptr) {
        cout << start->name << " "
             << (*now)->name << endl;
    }
}
