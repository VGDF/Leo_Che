#include "catch.hpp"
#include "natural_merge_sort.h"
#include <cstdio>

TEST_CASE("Natural Merge Sort", "[natural]") {

    SECTION("General case") {
        const char* inputFile = "test_input_nat.txt";
        const char* outputFile = "test_output_nat.txt";

        FILE* input = fopen(inputFile, "w");
        fprintf(input, "25 10 30 15 5 20 35 ");
        fclose(input);

        naturalMergeSort<double>(inputFile, outputFile);

        FILE* output = fopen(outputFile, "r");
        double val;
        double expected[] = { 5, 10, 15, 20, 25, 30, 35 };
        int i = 0;

        while (fscanf(output, "%lf", &val) == 1) {
            REQUIRE(val == expected[i]);
            i++;
        }
        fclose(output);

        remove(inputFile);
        remove(outputFile);
    }

    SECTION("Partially sorted") {
        const char* inputFile = "partial_input.txt";
        const char* outputFile = "partial_output.txt";

        FILE* input = fopen(inputFile, "w");
        fprintf(input, "1 3 5 2 4 6 8 7 9 ");
        fclose(input);

        naturalMergeSort<double>(inputFile, outputFile);

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

    SECTION("With duplicates") {
        const char* inputFile = "duplicates_input.txt";
        const char* outputFile = "duplicates_output.txt";

        FILE* input = fopen(inputFile, "w");
        fprintf(input, "5 2 5 2 3 5 3 2 ");
        fclose(input);

        naturalMergeSort<double>(inputFile, outputFile);

        FILE* output = fopen(outputFile, "r");
        double val;
        double expected[] = { 2, 2, 2, 3, 3, 5, 5, 5 };
        int i = 0;

        while (fscanf(output, "%lf", &val) == 1) {
            REQUIRE(val == expected[i]);
            i++;
        }
        fclose(output);

        remove(inputFile);
        remove(outputFile);
    }
}