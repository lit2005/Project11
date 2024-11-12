#include <iostream>  
#include <stdexcept>  
using namespace std;
template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};


template<typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() :top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }


    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }


    void pop() {
        if (isEmpty()) {
            throw out_of_range("���� ����! ���������� ��������� �������� pop.");
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }


    T peek() const {
        if (isEmpty()) {
            throw out_of_range("���� ����! ���������� ��������� �������� peek.");
        }
        return top->data;
    }

    // ����� ��� ��������, �������� �� ���� ������  
    bool isEmpty() const {
        return top == nullptr;
    }
};

// ������ ������������� �����  
int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "������� �������: " << stack.peek() << endl;

    while (!stack.isEmpty()) {
        cout << "���������: " << stack.peek() << endl;
        stack.pop();
    }

    return 0;
}