#include "catch.hpp"
#include "two_phase_merge_sort.h"
#include <cstdio>

TEST_CASE("Two Phase Merge Sort", "[two_phase]") {

    SECTION("General case") {
        const char* inputFile = "test_input.txt";
        const char* outputFile = "test_output.txt";

        FILE* input = fopen(inputFile, "w");
        fprintf(input, "9 5 7 3 8 1 6 2 4 ");
        fclose(input);

        twoPhaseMergeSort<double>(inputFile, outputFile);

        FILE* output = fopen(outputFile, "r");
        double val;
        double expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int i = 0;

        while (fscanf(output, "%lf", &val) == 1) {
            REQUIRE(val == expected[i]);
            i++;
        }
        fclose(output);

        remove(inputFile);
        remove(outputFile);
    }

    SECTION("Empty file") {
        const char* inputFile = "empty_input.txt";
        const char* outputFile = "empty_output.txt";

        FILE* input = fopen(inputFile, "w");
        fclose(input);

        twoPhaseMergeSort<double>(inputFile, outputFile);

        FILE* output = fopen(outputFile, "r");
        double val;
        REQUIRE(fscanf(output, "%lf", &val) != 1);
        fclose(output);

        remove(inputFile);
        remove(outputFile);
    }

    SECTION("Single element") {
        const char* inputFile = "single_input.txt";
        const char* outputFile = "single_output.txt";

        FILE* input = fopen(inputFile, "w");
        fprintf(input, "42 ");
        fclose(input);

        twoPhaseMergeSort<double>(inputFile, outputFile);

        FILE* output = fopen(outputFile, "r");
        double val;
        REQUIRE(fscanf(output, "%lf", &val) == 1);
        REQUIRE(val == 42.0);
        REQUIRE(fscanf(output, "%lf", &val) != 1);
        fclose(output);

        remove(inputFile);
        remove(outputFile);
    }
}