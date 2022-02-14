#include <iostream>
using namespace std;

struct Node {
    string val;
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool isEmpty() {
        return first == nullptr;
    }

    Node* findElement (const int index) { // Поиск элемента
        if (isEmpty()) return nullptr;
        Node* p = first;
        for (int i = 1; i < index; i++) {
            if (!p) return nullptr;
            p = p->next;
        }
        return p;
    }

    void pushBack(string _val) {  // Добавление элемента в конец списка
        Node* p = new Node(_val);
        if (isEmpty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void addByPos(string _val, int index) {  // Добавление элемента на определённую позицию
        Node* new_element = new Node(_val);
        if (isEmpty()) {
            first = new_element;
            last = new_element;
            return;
        }
        else if (findElement(index) != nullptr) {
            if (index == 0) {
                Node* temp = first;
                first = new_element;
                first->next = temp;
            }
            else {
                Node* temp = findElement(index)->next;
                findElement(index)->next = new_element;
                new_element->next = temp;
            }
        }
        else {
            last->next = new_element;
            last = new_element;
        }
    }

    void removeByElement(string _val) {  // Удаление определённого элемента
        if (isEmpty()) return;
        if (first->val == _val) {
            if (isEmpty()) return;
            Node* p = first;
            first = p->next;
            delete p;
            return;
        }
        else if (last->val == _val) {
            if (isEmpty()) return;
            if (first == last) {
                Node* p = first;
                first = p->next;
                delete p;
                return;
            }
            Node* p = first;
            while (p->next != last) p = p->next;
            p->next = nullptr;
            delete last;
            last = p;
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    void print() { // Вывод списка
        if (isEmpty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    list l;
    cout << l.isEmpty() << endl;
    l.pushBack("3");
    l.pushBack("8");
    l.pushBack("123");
    l.pushBack("34");
    l.pushBack("25");
    cout << l.isEmpty() << endl;
    l.print();
    l.removeByElement("123");
    l.print();
    l.addByPos("123", 2);
    l.print();
    return 0;
}