#include "catch.hpp"
#include "one_phase_merge_sort.h"
#include <cstdio>

TEST_CASE("One Phase Merge Sort", "[one_phase]") {

    SECTION("General case") {
        const char* inputFile = "test_input_one.txt";
        const char* outputFile = "test_output_one.txt";

        FILE* input = fopen(inputFile, "w");
        fprintf(input, "15 3 12 8 20 1 17 9 ");
        fclose(input);

        onePhaseMergeSort<double>(inputFile, outputFile);

        FILE* output = fopen(outputFile, "r");
        double val;
        double expected[] = { 1, 3, 8, 9, 12, 15, 17, 20 };
        int i = 0;

        while (fscanf(output, "%lf", &val) == 1) {
            REQUIRE(val == expected[i]);
            i++;
        }
        fclose(output);

        remove(inputFile);
        remove(outputFile);
    }

    SECTION("Already sorted") {
        const char* inputFile = "sorted_input.txt";
        const char* outputFile = "sorted_output.txt";

        FILE* input = fopen(inputFile, "w");
        fprintf(input, "1 2 3 4 5 6 7 ");
        fclose(input);

        onePhaseMergeSort<double>(inputFile, outputFile);

        FILE* output = fopen(outputFile, "r");
        double val;
        double expected[] = { 1, 2, 3, 4, 5, 6, 7 };
        int i = 0;

        while (fscanf(output, "%lf", &val) == 1) {
            REQUIRE(val == expected[i]);
            i++;
        }
        fclose(output);

        remove(inputFile);
        remove(outputFile);
    }

    SECTION("Reverse sorted") {
        const char* inputFile = "reverse_input.txt";
        const char* outputFile = "reverse_output.txt";

        FILE* input = fopen(inputFile, "w");
        fprintf(input, "10 8 6 4 2 ");
        fclose(input);

        onePhaseMergeSort<double>(inputFile, outputFile);

        FILE* output = fopen(outputFile, "r");
        double val;
        double expected[] = { 2, 4, 6, 8, 10 };
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