// Copyright 2025

#include "train.h"

Train::Train() : head(nullptr), operations(0) {}

Train::~Train() {
    clear();
}

void Train::clear() {
    if (head == nullptr) {
        return;
    }

    Car* node = head->next;

    while (node != head) {
        Car* temp = node;
        node = node->next;

        delete temp;
    }

    delete head;

    head = nullptr;
}

void Train::addCar(bool state) {
    Car* node = new Car;

    node->lampState = state;

    if (head == nullptr) {
        head = node;

        node->next = node;
        node->prev = node;

        return;
    }

    Car* tail = head->prev;

    tail->next = node;
    node->prev = tail;

    node->next = head;
    head->prev = node;
}

int Train::getOpCount() {
    return operations;
}

int Train::getLength() {
    if (head == nullptr) {
        return 0;
    }

    operations = 0;

    Car* ptr = head;

    ptr->lampState = true;

    while (true) {
        int steps = 0;

        ptr = ptr->next;
        operations++;
        steps++;

        while (!ptr->lampState) {
            ptr = ptr->next;

            operations++;
            steps++;
        }

        ptr->lampState = false;

        int backSteps = steps;

        while (backSteps > 0) {
            ptr = ptr->prev;

            operations++;

            backSteps--;
        }

        if (!ptr->lampState) {
            return steps;
        }
    }
}
