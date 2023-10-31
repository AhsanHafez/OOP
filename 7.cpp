#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<class T>
class list {
public:
    struct node {
        T value;
        node* next;
    };
    node* head;
    node* last;
    list(T val) {
        head = last = new node;  // Initialize head and last with a new node
        head->value = val;
        head->next = nullptr;
    }

    void push(T val) {
        node* temp = new node;
        temp->value = val;
        temp->next = nullptr;
        last->next = temp;
        last = last->next;
    }

    void print_list() {  // Removed the parameter, as it uses the class member head
        node* current = head;
        cout << '[';
        for (; current != nullptr;) {
            cout << current->value;
            current = current->next;
            if (current != nullptr) {
                cout << ',';
            }
        }
        cout << ']';
    }
};

template <class T>
T _max(T a, T b) {
    T result;
    if (a > b) {
        result = a;
    }
    else {
        result = b;
    }
    return result;
}

int main() {
    cout << _max<string>("usman", "ullah") << endl;
    list<string> l("AHSAN");
    l.push("HASNAIN");
    l.print_list();
}
