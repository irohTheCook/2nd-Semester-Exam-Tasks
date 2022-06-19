#ifndef STUDENTS_EXAM_LINKEDLIST_H
#define STUDENTS_EXAM_LINKEDLIST_H
#include <stdexcept>

template<typename data_type>
struct LinkedList {

private:
    struct Node {
        data_type data;
        Node* next;
        explicit Node(data_type d, Node* n = nullptr) {
            data = d;
            next = n;
        }
    };

    Node* head = nullptr;

public:
    int counter = 0;
    LinkedList() = default;

    ~LinkedList();

    void push(data_type val);

    data_type pop();
};

template<typename data_type>
LinkedList<data_type>::~LinkedList() {
    while ( head != nullptr ) {
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
    }

    counter = 0;
}

// ascending order
template<typename data_type>
void LinkedList<data_type>::push(data_type val) {
    Node* new_node = new Node(val);

    if ( head == nullptr || head->data >= val) {
        new_node->next = head;
        head = new_node;
    }
    else {
        Node* pre_curr = nullptr;
        Node* curr = head;

        while ( curr != nullptr && curr->data < val) {
            pre_curr = curr;
            curr = curr->next;
        }
        pre_curr->next = new_node;
        new_node->next = curr;
    }

    ++counter;
}

template<typename data_type>
data_type LinkedList<data_type>::pop() {
    if ( head == nullptr ) {
        throw std::runtime_error("List is empty");
    }
    else {
        Node* to_pop = head;
        data_type result = to_pop->data;
        head = head->next;
        delete to_pop;
        --counter;

        return result;
    }
}


#endif
