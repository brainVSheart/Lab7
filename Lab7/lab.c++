#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};
class LinkedList {
protected:
    struct studentNode *start, **now;
public:
    LinkedList() {
        start = NULL;
        now = &start;
    }
    ~LinkedList() {
        struct studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }
    }
    void InsNode(char n[], int a, char s, float g) {
        struct studentNode *newNode = new studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = *now;
        *now = newNode;
    }
    void DelNode() {
        if (*now != NULL) {
            struct studentNode *temp = *now;
            *now = (*now)->next;
            delete temp;
        }
    }
    void GoNext() {
        if (*now != NULL && (*now)->next != NULL) {
            now = &((*now)->next);
        }
    }
    virtual void ShowNode() {
        if (*now != NULL) {
            cout << (*now)->name << " " << (*now)->age << " " 
                 << (*now)->sex << " " << fixed << setprecision(2) << (*now)->gpa << endl;
        }
    }
};
class NewList : public LinkedList {
public:
    void InsertNode(char n[], int a, char s, float g) {
        InsNode(n, a, s, g);
    }
    void GoFirst() {
        now = &start;
    }
    virtual void ShowNode() {
        if (start != NULL && *now != NULL) {
            cout << start->name << " " << (*now)->name << endl;
        }
    }
};
int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;
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