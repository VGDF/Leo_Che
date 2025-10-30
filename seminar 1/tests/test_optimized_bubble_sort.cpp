#include "catch.hpp"
#include "optimized_bubble_sort.h"
#include <vector>

TEST_CASE("Optimized Bubble Sort", "[optimized_bubble]") {

    SECTION("General case with integers") {
        std::vector<int> arr = {5, 1, 4, 2, 8};
        std::vector<int> sorted_arr = {1, 2, 4, 5, 8};
        optimizedBubbleSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Empty array") {
        std::vector<int> arr = {};
        optimizedBubbleSort(arr);
        REQUIRE(arr.empty());
    }

    SECTION("Single element array") {
        std::vector<int> arr = {100};
        optimizedBubbleSort(arr);
        REQUIRE(arr.size() == 1);
        REQUIRE(arr[0] == 100);
    }

    SECTION("Already sorted array (tests optimization)") {
        std::vector<int> arr = {10, 20, 30, 40};
        std::vector<int> sorted_arr = {10, 20, 30, 40};
        optimizedBubbleSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Reverse sorted array") {
        std::vector<int> arr = {5, 4, 3, 2, 1};
        std::vector<int> sorted_arr = {1, 2, 3, 4, 5};
        optimizedBubbleSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Array with duplicate elements") {
        std::vector<int> arr = {7, 3, 7, 1, 3};
        std::vector<int> sorted_arr = {1, 3, 3, 7, 7};
        optimizedBubbleSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Array with floating point numbers") {
        std::vector<double> arr = {0.5, 0.1, 0.4, 0.2, 0.8};
        std::vector<double> sorted_arr = {0.1, 0.2, 0.4, 0.5, 0.8};
        optimizedBubbleSort(arr);
        REQUIRE(arr == sorted_arr);
    }
}