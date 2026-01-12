
#include "catch.hpp"

#include "binary_insertion_sort.h"

TEST_CASE("Binary Insertion Sort", "[binary_insertion]") {

    SECTION("Variant 27 array") {
        int arr[] = { 4, 13, 10, 8, 1, 7, 10, 5 };
        int expected[] = { 1, 4, 5, 7, 8, 10, 10, 13 };

        binaryInsertionSort(arr, 8);

        for (int i = 0; i < 8; ++i)
            REQUIRE(arr[i] == expected[i]);
    }

    SECTION("Empty array") {
        int arr[1];
        binaryInsertionSort(arr, 0);
        REQUIRE(true);
    }

    SECTION("Single element") {
        int arr[] = { 42 };
        binaryInsertionSort(arr, 1);
        REQUIRE(arr[0] == 42);
    }

    SECTION("Already sorted") {
        int arr[] = { 1, 2, 3, 4 };
        int expected[] = { 1, 2, 3, 4 };

        binaryInsertionSort(arr, 4);

        for (int i = 0; i < 4; ++i)
            REQUIRE(arr[i] == expected[i]);
    }
}
