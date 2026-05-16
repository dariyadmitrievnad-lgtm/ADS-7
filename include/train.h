// Copyright 2025

#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
    struct Car {
        Car* next;
        Car* prev;

        bool lampState;

        Car() : next(nullptr), prev(nullptr), lampState(false) {}
    };

    Car* head;

    int operations;

    void clear();

 public:
    Train();

    ~Train();

    void addCar(bool state);

    int getLength();

    int getOpCount();
};

#endif  // INCLUDE_TRAIN_H_
