// Михайлов А.А 9302 Вариант 1

#include <iostream>
#include <gtest/gtest.h>
#include "base_algs.h"

using namespace std;

void AlgorithmResearch() {
    srand((unsigned)time(NULL));
    for (int tries = 10; tries < 1'000'000; tries *= 10) {

        double time = 0.0;
        int *data_1 = new int[tries];
        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < tries; i++) {
                int num = rand() % 100'000;
                data_1[i] = num;
            }

            clock_t start = clock();
            QuickSort(data_1, 0, tries - 1);
            clock_t end = clock();
            time += double(end - start) / double(CLOCKS_PER_SEC);
        }

        cout << "TIme for QuickSort: " << time / 10 << endl;
        time = 0.0;

        int* data_2 = new int[tries];
        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < tries; i++) {
                int num = rand() % 100'000;
                data_2[i] = num;
            }

            clock_t start = clock();
            InsertionSort(data_2, tries);
            clock_t end = clock();
            time += double(end - start) / double(CLOCKS_PER_SEC);
        }

        cout << "TIme for InsertionSort: " << time / 10 << endl;

        delete [] data_1;
        delete [] data_2;
    }
}

int main() {
    AlgorithmResearch();
    return 0;
}
