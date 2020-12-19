#include "base_algs.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>


TEST(bin_srch, test) {
    int data[7] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 7; i++)
       ASSERT_EQ(BinarySearch(data, 7, i + 1), i);

    int data_2[10] = {100, 200, 300, 500, 800, 1300, 2100, 3400, 5500, 8900};
    ASSERT_EQ(BinarySearch(data_2, 10, 100), 0);
    ASSERT_EQ(BinarySearch(data_2, 10, 8900), 9);

    ASSERT_EQ(BinarySearch(data_2, 10, 101), -404);
    ASSERT_EQ(BinarySearch(data_2, 10, 1010), -404);    // non-exist elems

}

TEST(insertion_sort, sort) {
    int data[7] = {7, 6, 5, 4, 3, 2, 1};

    InsertionSort(data, 7);
    for (int i = 0; i < 7; i++)
        ASSERT_EQ(data[i], i + 1);

    int data_2[10] = {10, 2, 3, 0, 1, 6, 7, 8, 5, 0};
    InsertionSort(data_2, 10);
    ASSERT_EQ(data_2[0], 0);
    ASSERT_EQ(data_2[1], 0);
    ASSERT_EQ(data_2[9], 10);
    ASSERT_EQ(data_2[8], 8);

    int* data_3 = new int[100];
    for (int i = 0; i < 100; i++) {
        data_3[i] = 100 - i;
    }
    InsertionSort(data_3, 100);
    for (int i = 0; i < 100; i++) {
        ASSERT_EQ(data_3[i], i + 1);
    }
    delete[] data_3;
}

TEST(bogo_sort, sort) {
    int data[7] = {7, 6, 5, 4, 3, 2, 1};

    BogoSort(data, 7);
    for (int i = 0; i < 7; i++)
        ASSERT_EQ(data[i], i + 1);

    int data_2[10] = {10, 2, 3, 0, 1, 6, 7, 8, 5, 0};
    BogoSort(data_2, 10);
    ASSERT_EQ(data_2[0], 0);
    ASSERT_EQ(data_2[1], 0);
    ASSERT_EQ(data_2[9], 10);
    ASSERT_EQ(data_2[8], 8);

    int* data_3 = new int[100];
    for (int i = 0; i < 100; i++) {
        data_3[i] = 100 - i;
    }
    BogoSort(data_3, 100);
    for (int i = 0; i < 100; i++) {
        ASSERT_EQ(data_3[i], i + 1);
    }
    delete[] data_3;
}

TEST(quick_sort, sort) {
    int data[7] = {7, 6, 5, 4, 3, 2, 1};

    QuickSort(data, 0, 6);
    for (int i = 0; i < 7; i++)
        ASSERT_EQ(data[i], i + 1);

    int data_2[10] = {10, 2, 3, 0, 1, 6, 7, 8, 5, 0};
    QuickSort(data_2, 0, 9);
    ASSERT_EQ(data_2[0], 0);
    ASSERT_EQ(data_2[1], 0);
    ASSERT_EQ(data_2[9], 10);
    ASSERT_EQ(data_2[8], 8);

    int* data_3 = new int[100];
    for (int i = 0; i < 100; i++) {
        data_3[i] = 100 - i;
    }
    QuickSort(data_3, 0, 99);
    for (int i = 0; i < 100; i++) {
        ASSERT_EQ(data_3[i], i + 1);
    }
    delete[] data_3;
}

TEST(counting_sort, sort) {
    char data[7] = {7, 6, 5, 4, 3, 2, 1};

    CountingSort(data, char(7));
    for (int i = 0; i < 7; i++)
        ASSERT_EQ(data[i], (char)i + 1);

    char data_2[10] = {10, 2, 3, 0, 1, 6, 7, 8, 5, 0};
    CountingSort(data_2, 10);
    ASSERT_EQ(data_2[0], (char)0);
    ASSERT_EQ(data_2[1], char(0));
    ASSERT_EQ(data_2[9], char(10));
    ASSERT_EQ(data_2[8], char(8));

    char* data_3 = new char[100];
    for (int i = 0; i < 100; i++) {
        data_3[i] = 100 - i;
    }
    CountingSort(data_3, 100);
    for (int i = 0; i < 100; i++) {
        ASSERT_EQ(data_3[i], (char)(i + 1));
    }
    delete[] data_3;
}


TEST(throws, test) {
    int data1[3] = {1, 2, 3};

    ASSERT_THROW(BinarySearch(data1, -1, 3), std::range_error);

    ASSERT_THROW(InsertionSort(data1, -1), std::range_error);
    ASSERT_THROW(QuickSort(data1, -1, -1), std::range_error);
    ASSERT_THROW(BogoSort(data1, -1), std::range_error);

    char data2[3] = {1, 2, 3};
    ASSERT_THROW(CountingSort(data2, char(-1)), std::range_error);
}