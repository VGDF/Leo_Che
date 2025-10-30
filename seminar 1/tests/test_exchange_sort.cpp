#include "catch.hpp"
#include "exchange_sort.h"
#include <vector>

TEST_CASE("Exchange Sort", "[exchange]") {
    SECTION("General case with integers") {
        std::vector<int> arr = {5, 1, 4, 2, 8};
        std::vector<int> sorted_arr = {1, 2, 4, 5, 8};
        exchangeSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Empty array") {
        std::vector<int> arr = {};
        exchangeSort(arr);
        REQUIRE(arr.empty());
    }

    SECTION("Single element array") {
        std::vector<int> arr = {1};
        exchangeSort(arr);
        REQUIRE(arr.size() == 1);
        REQUIRE(arr[0] == 1);
    }

    SECTION("Already sorted array") {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        std::vector<int> sorted_arr = {1, 2, 3, 4, 5};
        exchangeSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Reverse sorted array") {
        std::vector<int> arr = {9, 7, 5, 3, 1};
        std::vector<int> sorted_arr = {1, 3, 5, 7, 9};
        exchangeSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Array with negative numbers") {
        std::vector<int> arr = {-5, 0, 5, -10, 10};
        std::vector<int> sorted_arr = {-10, -5, 0, 5, 10};
        exchangeSort(arr);
        REQUIRE(arr == sorted_arr);
    }

    SECTION("Array with floating point numbers") {
        std::vector<double> arr = {9.9, 1.1, 5.5};
        std::vector<double> sorted_arr = {1.1, 5.5, 9.9};
        exchangeSort(arr);
        REQUIRE(arr == sorted_arr);
    }
}