// Copyright 2025

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "train.h"

enum TrainMode {
    ALL_DISABLED,
    ALL_ENABLED,
    RANDOM_LIGHTS
};

void generateTrain(Train& train, int size, TrainMode mode) {
    for (int i = 0; i < size; ++i) {
        bool state = false;

        switch (mode) {
            case ALL_ENABLED:
                state = true;
                break;

            case RANDOM_LIGHTS:
                state = std::rand() % 2;
                break;

            default:
                state = false;
                break;
        }

        train.addCar(state);
    }
}

int runExperiment(int size, TrainMode mode) {
    Train train;

    generateTrain(train, size, mode);

    train.getLength();

    return train.getOpCount();
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const int MIN_SIZE = 2;
    const int MAX_SIZE = 100;

    std::ofstream file("results.csv");

    file << "n,all_off,all_on,random\n";

    for (int n = MIN_SIZE; n <= MAX_SIZE; ++n) {
        int offResult = runExperiment(n, ALL_DISABLED);

        int onResult = runExperiment(n, ALL_ENABLED);

        int randomResult = runExperiment(n, RANDOM_LIGHTS);

        file << n << ","
             << offResult << ","
             << onResult << ","
             << randomResult << "\n";

        std::cout << "Processed train size: "
                  << n << std::endl;
    }

    file.close();

    return 0;
}
