#include <iostream>
using namespace std;

class Node{
public:
    int data = 0;
    Node* next = nullptr;
};

class LinkedList{

public:

    Node* head;

    LinkedList(){
        head = nullptr;
    }

    void addToEnd(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr){
            head = temp;
        }
        else {
            Node *p;
            p = head;

            while (p->next != nullptr){
                p = p->next;
            }
            p->next = temp;
        }
    }

    void addToStart(int value){
        Node* temp = new Node;
        temp->data = value;

        if (head == nullptr){
            head = temp;
            temp->next = nullptr;
        } else{
            temp->next = head;
            head = temp;
        }
        temp = nullptr;
        delete temp;

    }

    void reverseList(){
        if (head == nullptr){
            cout << "Linked List is empty";
            return;
        }
        int count = 0;
        Node* temp = head;
        Node* temp2;
        Node* tempHead;

        while (temp->next != nullptr){
            temp = temp->next;
            count++;
        }
        tempHead = temp;

        for (int i = 0; i < count; ++i) {
            temp = head;
            temp2 = head;

            while (temp->next != nullptr){
                temp = temp->next;
            }

            while (temp2->next != temp){
                temp2 = temp2->next;
            }
            temp->next = temp2;
            temp2->next = nullptr;
        }
        head = tempHead;

    }

    void deleteNodeByValue(int value){
        if (head->data == value){
            head = head->next;
            return;
        }
        Node* itr = head;
        Node* itr2 = head;
        while (itr->data != value){
            itr2 = itr;
            itr = itr->next;
        }
        itr = itr->next;
        itr2->next = itr;
    }

    void deleteNodeByPosition(int x){
        if (head == nullptr){
            cout << "Linked Linked List is empty";
            return;
        }
        int count = 1;
        if (x==1){
            head = head->next;
            return;
        }
        Node* itr = head;
        while (itr){
            if(count == x-1){
                Node* tempDel = itr->next;
                itr->next = itr->next->next;
                delete tempDel;
                return;
            }
            itr = itr->next;
            count++;
        }
//        delete itr;
    }

    int search(int number){
        if (head == nullptr){
            cout << "Linked Linked List is empty";
            return 0;
        }
        Node* p = head;
        int nodeCounter = 0;

        while (p != nullptr){
            nodeCounter++;
            if (p->data == number){
                break;
            }
            else
                p = p->next;
        }
        return nodeCounter;

    }

    void print(){
        if (head == nullptr){
            cout << "Linked Linked List is empty";
            return;
        }
        Node* tempHead;

        for (tempHead = head; tempHead != nullptr; tempHead = tempHead->next){
            cout << tempHead->data << " ";
        }

//        while (tempHead != nullptr){
//            cout << tempHead->data;
//            tempHead = tempHead->next;
//        }
        delete tempHead;
        cout << endl;
    }

    void deleteFromStart(){
        if (head == nullptr){
            cout << "Linked List is empty";
            return;
        }
        Node* temp = head;
        head = head->next;

        delete temp;
    }

    void deleteFromEnd(){
        if (head == nullptr){
            cout << "Linked List is empty";
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr){
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void splitIntoEvenOdd(){
        Node* temp = head;

        LinkedList evenList;
        LinkedList oddList;

        while (temp != nullptr){
            if (temp->data % 2 == 0){
                evenList.addToEnd(temp->data);
            } else{
                oddList.addToEnd(temp->data);
            }
            temp = temp->next;
        }

        cout << "Even List" << endl;
        evenList.print();

        cout << "Odd List" << endl;
        oddList.print();

    }

    void printReverseRecursive(Node* temp){

        if (temp  == nullptr) // Base case
            return;

        printReverseRecursive(temp->next); // Recursive Case
        cout << temp->data << endl;

    }

    void printReverseRecursive(){
        printReverseRecursive(head);
    }

//    void rev(Node* temp){
//        if (temp == nullptr)
//            return;
//
//        rev(temp->next);
//        Node* temp2 = head;
//        while (temp2->next != temp)
//            temp2 = temp2->next;
//        temp->next = temp2;
//        temp2->next = nullptr;
//
//    }



};


int main() {

    LinkedList l;

    l.addToEnd(1);
    l.addToEnd(2);
    l.addToEnd(3);
    l.addToEnd(4);
    l.addToEnd(5);
    l.addToEnd(6);



//    l.print();

//    l.printReverseRecursive();


//    l.rev(l.head);

    l.print();

//    l.printReverseRecursive();






//    cout << "Value found at " << l.search(2) << endl;

//    l.deleteNodeByPosition(2);

//
//    LinkedList l2;
//    l2.addToStart(1);
//    l2.print();

}


