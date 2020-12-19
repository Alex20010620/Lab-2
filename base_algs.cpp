#include <iostream>

#include "base_algs.h"

using namespace std;

int BinarySearch(int data[], int size, int value) {
    if (size < 0)
        throw range_error("The size of the array in BinarySearch is lesser than zero.");

    int m, l = 0, r = size;

    while (l != r) {
        m = (l + r) / 2;

        if (data[m] == value)
            return m;

        if (data[m] < value)
            l = m + 1;
        else if (data[m] > value)
            r = m - 1;
    }

    if (data[l] == value)
        return l;

    return -404;    // The code of non-existent value
}

void InsertionSort(int data[], int size) {
    if (size < 0)
        throw std::range_error("The size of the array in InsertionSort is lesser than zero.");

    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && data[j-1] > data[j]; j--) {
            int temp = data[j - 1];
            data[j - 1] = data[j];
            data[j] = temp;
        }
    }
}

bool is_sorted(int data[], int size) {
    for (int i = 1; i < size; i++) {
        if (data[i] < data[i - 1])
            return false;
    }

    return true;
}

void BogoSort(int data[], int size) {
    if (size < 0)
        throw range_error("The size of the array in BogoSearch is lesser than zero.");

    srand((unsigned)time(NULL));

    do {
        for (int i = 0; i < size; i++) {
            int random = rand() % size;
            int temp = data[random];
            data[random] = data[i];
            data[i] = temp;
        }
    } while(!is_sorted(data,size));
}

void QuickSort(int data[], int old_l, int old_r) {
    if (old_r - old_l < 0 || old_l < 0)
        throw range_error("Left and right corners are wrong in QuickSort func().");

    int l = old_l, r = old_r, medium = (l + r) / 2;
    int piv = data[medium];

    while (l <= r) {
        while (data[l] < piv)
            l++;
        while (data[r] > piv)
            r--;

        if (l <= r) {
            int temp = data[l];
            data[l] = data[r];
            data[r] = temp;
            l++; r--;
        }
    }
    if (old_l < r)
        QuickSort(data, old_l, r);
    if (old_r > l)
        QuickSort(data, l, old_r);
}


void CountingSort(char data[], char size) {
    if (size < 0) 
        throw range_error("The size of the array in CountingSort is lesser than zero");

    char max = -1;
    for (char i = 0; i < size; i++)
        if (data[i] > max) 
            max = data[i];

    char* data_2 = new char[max + 1];
    int pos = 0;

    for (char i = 0; i < max + 1; i++)
        data_2[i] = 0;

    for (char i = 0; i < size; i++)
        data_2[data[i]]++;

    for (char number = 0; number < max + 1; number++) {
        for (char j = 0; j < data_2[number]; j++)
            data[pos++] = number;
    }

    delete[] data_2;
}

