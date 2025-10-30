#include "catch.hpp"
#include "selection_sort.h"
#include <vector>

TEST_CASE("Selection Sort", "[selection]") {

    SECTION("General case with integers") {
        std::vector<int> arr = {64, 25, 12, 22, 11};
        std::vector<int> sorted_arr = {11, 12, 22, 25, 64};
        selectionSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Empty array") {
        std::vector<int> arr = {};
        selectionSort(arr);
        REQUIRE(arr.empty());
    }

    SECTION("Single element array") {
        std::vector<int> arr = {42};
        selectionSort(arr);
        REQUIRE(arr.size() == 1);
        REQUIRE(arr[0] == 42);
    }

    SECTION("Already sorted array") {
        std::vector<int> arr = {10, 20, 30, 40, 50};
        std::vector<int> sorted_arr = {10, 20, 30, 40, 50};
        selectionSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Reverse sorted array") {
        std::vector<int> arr = {5, 4, 3, 2, 1};
        std::vector<int> sorted_arr = {1, 2, 3, 4, 5};
        selectionSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Array with duplicate elements") {
        std::vector<int> arr = {5, 2, 8, 2, 5, 1};
        std::vector<int> sorted_arr = {1, 2, 2, 5, 5, 8};
        selectionSort(arr);
        REQUIRE(arr == sorted_arr);
    }
    
    SECTION("Array with floating point numbers") {
        std::vector<double> arr = {3.3, 1.1, -4.4, 2.2, -4.4};
        std::vector<double> sorted_arr = {-4.4, -4.4, 1.1, 2.2, 3.3};
        selectionSort(arr);
        REQUIRE(arr == sorted_arr);
    }
}