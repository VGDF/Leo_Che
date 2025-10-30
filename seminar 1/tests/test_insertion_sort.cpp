#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "insertion_sort.h"
#include <vector>

TEST_CASE("Insertion Sort", "[insertion]") {
    SECTION("Positive case") {
        std::vector<int> arr = {5, 2, 4, 6, 1, 3};
        std::vector<int> sorted_arr = {1, 2, 3, 4, 5, 6};
        insertionSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Empty array") {
        std::vector<int> arr = {};
        insertionSort(arr);
        REQUIRE(arr.empty());
    }

    SECTION("Already sorted array") {
        std::vector<int> arr = {1, 2, 3, 4, 5, 6};
        std::vector<int> sorted_arr = {1, 2, 3, 4, 5, 6};
        insertionSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Reverse sorted array") {
        std::vector<double> arr = {6.1, 5.2, 4.3, 3.4, 2.5, 1.6};
        std::vector<double> sorted_arr = {1.6, 2.5, 3.4, 4.3, 5.2, 6.1};
        insertionSort(arr);
        REQUIRE(arr == sorted_arr);
    }
}