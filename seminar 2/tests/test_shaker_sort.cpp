#include "catch.hpp"

#include "shaker_sort.h"

TEST_CASE("Shaker Sort", "[shaker]") {

    SECTION("Variant 27 array") {
        int arr[] = { 4, 13, 10, 8, 1, 7, 10, 5 };
        int expected[] = { 1, 4, 5, 7, 8, 10, 10, 13 };

        shakerSort(arr, 8);

        for (int i = 0; i < 8; ++i)
            REQUIRE(arr[i] == expected[i]);
    }

    SECTION("Empty array") {
        int arr[1];
        shakerSort(arr, 0);
        REQUIRE(true);
    }

    SECTION("Single element") {
        int arr[] = { 7 };
        shakerSort(arr, 1);
        REQUIRE(arr[0] == 7);
    }

    SECTION("Reverse sorted") {
        int arr[] = { 5, 4, 3, 2, 1 };
        int expected[] = { 1, 2, 3, 4, 5 };

        shakerSort(arr, 5);

        for (int i = 0; i < 5; ++i)
            REQUIRE(arr[i] == expected[i]);
    }
}
