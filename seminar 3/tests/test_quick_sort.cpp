#include "catch.hpp"

#include "quick_sort.h"

TEST_CASE("Quick Sort", "[quick]") {

    SECTION("General case") {
        int arr[] = { 10, 7, 8, 9, 1, 5 };
        int expected[] = { 1, 5, 7, 8, 9, 10 };

        quickSort(arr, 6);

        for (int i = 0; i < 6; ++i)
            REQUIRE(arr[i] == expected[i]);
    }

    SECTION("Empty array") {
        int arr[1];
        quickSort(arr, 0);
        REQUIRE(true);
    }

    SECTION("Single element array") {
        int arr[] = { 99 };
        quickSort(arr, 1);
        REQUIRE(arr[0] == 99);
    }

    SECTION("Reverse sorted array") {
        int arr[] = { 5, 4, 3, 2, 1 };
        int expected[] = { 1, 2, 3, 4, 5 };

        quickSort(arr, 5);

        for (int i = 0; i < 5; ++i)
            REQUIRE(arr[i] == expected[i]);
    }
}
