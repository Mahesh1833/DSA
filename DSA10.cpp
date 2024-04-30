#include <iostream>
#include <string>

#define N 20
#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1

using namespace std;

struct Node {
    string data;
    int priority;
    Node* next;
};

Node* head = nullptr;

void enqueue(string data, int p) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->priority = p;
    newNode->next = nullptr;

    if (head == nullptr || p > head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr && temp->next->priority >= p) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Patient's Name - " << temp->data;
        switch (temp->priority) {
            case SERIOUS:
                cout << " Priority - 'Serious'" << endl;
                break;
            case NONSERIOUS:
                cout << " Priority - 'Non-serious'" << endl;
                break;
            case CHECKUP:
                cout << " Priority - 'General Check-up'" << endl;
                break;
            default:
                cout << " Priority - 'Unknown'" << endl;
                break;
        }
        temp = temp->next;
    }
}

void dequeue() {
    if (head == nullptr) {
        cout << "Queue is Empty" << endl;
    } else {
        Node* temp = head;
        cout << "Deleted Element = " << temp->data << endl;
        cout << "Its Priority = " << temp->priority << endl;
        head = head->next;
        delete temp;
    }
}

int main() {
    string data;
    int opt, n, p;

    cout << "Enter Your Choice:" << endl;
    do {
        cout << "1 for Insert Data in Queue" << endl
             << "2 for Show Data in Queue" << endl
             << "3 for Delete Data from Queue" << endl
             << "0 for Exit" << endl;
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "Enter the number of patients" << endl;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter the name of the patient: ";
                    cin >> data;
                    cout << "Enter the priority (0: Serious, 1: Non-serious, 2: General Check-up): ";
                    cin >> p;
                    switch (p) {
                        case 0:
                            enqueue(data, SERIOUS);
                            break;
                        case 1:
                            enqueue(data, NONSERIOUS);
                            break;
                        case 2:
                            enqueue(data, CHECKUP);
                            break;
                        default:
                            cout << "Invalid Priority" << endl;
                            break;
                    }
                }
                break;
            case 2:
                print();
                break;
            case 3:
                dequeue();
                break;
            case 0:
                cout << "Bye Bye!" << endl;
                break;
            default:
                cout << "Incorrect Choice" << endl;
        }
    } while (opt != 0);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
