#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "shell_sort.h"

TEST_CASE("Shell Sort", "[shell]") {

    SECTION("General case") {
        int arr[] = { 9, 8, 3, 7, 5, 6, 4, 1 };
        int expected[] = { 1, 3, 4, 5, 6, 7, 8, 9 };

        shellSort(arr, 8);

        for (int i = 0; i < 8; ++i)
            REQUIRE(arr[i] == expected[i]);
    }

    SECTION("Empty array") {
        int arr[1];
        shellSort(arr, 0);
        REQUIRE(true);
    }

    SECTION("Single element array") {
        int arr[] = { 42 };
        shellSort(arr, 1);
        REQUIRE(arr[0] == 42);
    }

    SECTION("Already sorted array") {
        int arr[] = { 1, 2, 3, 4 };
        int expected[] = { 1, 2, 3, 4 };

        shellSort(arr, 4);

        for (int i = 0; i < 4; ++i)
            REQUIRE(arr[i] == expected[i]);
    }
}
