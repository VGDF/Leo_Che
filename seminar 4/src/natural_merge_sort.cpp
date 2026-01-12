#include "natural_merge_sort.h"
#include <cstdio>
#include <cstdlib>

#define SIZEOF(arr) (sizeof(arr)/sizeof(arr[0]))

template <typename T>
int readRun(FILE* file, T* buffer, int maxSize) {
    int count = 0;
    T current, next;

    if (fscanf(file, "%lf", &current) != 1) {
        return 0;
    }

    buffer[count++] = current;

    while (count < maxSize) {
        int pos = ftell(file);
        if (fscanf(file, "%lf", &next) != 1) {
            break;
        }

        if (next < current) {
            fseek(file, pos, SEEK_SET);
            break;
        }

        buffer[count++] = next;
        current = next;
    }

    return count;
}

template <typename T>
void mergeRuns(T* run1, int size1, T* run2, int size2, FILE* out) {
    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (run1[i] <= run2[j]) {
            fprintf(out, "%f ", run1[i++]);
        }
        else {
            fprintf(out, "%f ", run2[j++]);
        }
    }

    while (i < size1) {
        fprintf(out, "%f ", run1[i++]);
    }

    while (j < size2) {
        fprintf(out, "%f ", run2[j++]);
    }
}

template <typename T>
void naturalMergeSort(const char* inputFile, const char* outputFile) {
    const int MAX_RUN_SIZE = 100;
    T run1[MAX_RUN_SIZE];
    T run2[MAX_RUN_SIZE];

    FILE* input = fopen(inputFile, "r");
    if (!input) return;

    int tempCount = 0;
    while (!feof(input)) {
        int size1 = readRun<T>(input, run1, MAX_RUN_SIZE);
        if (size1 == 0) break;

        int size2 = readRun<T>(input, run2, MAX_RUN_SIZE);

        char tempName[50];
        sprintf(tempName, "temp_nat_%d.txt", tempCount++);
        FILE* temp = fopen(tempName, "w");

        if (size2 > 0) {
            mergeRuns(run1, size1, run2, size2, temp);
        }
        else {
            for (int i = 0; i < size1; ++i) {
                fprintf(temp, "%f ", run1[i]);
            }
        }

        fclose(temp);
    }
    fclose(input);

    while (tempCount > 1) {
        int newTempCount = 0;

        for (int i = 0; i < tempCount; i += 2) {
            char in1Name[50], in2Name[50], outName[50];
            sprintf(in1Name, "temp_nat_%d.txt", i);
            FILE* in1 = fopen(in1Name, "r");

            if (i + 1 < tempCount) {
                sprintf(in2Name, "temp_nat_%d.txt", i + 1);
                FILE* in2 = fopen(in2Name, "r");

                int size1 = 0;
                T val;
                while (fscanf(in1, "%lf", &val) == 1 && size1 < MAX_RUN_SIZE) {
                    run1[size1++] = val;
                }

                int size2 = 0;
                while (fscanf(in2, "%lf", &val) == 1 && size2 < MAX_RUN_SIZE) {
                    run2[size2++] = val;
                }

                sprintf(outName, "temp_nat_new%d.txt", newTempCount++);
                FILE* out = fopen(outName, "w");

                mergeRuns(run1, size1, run2, size2, out);

                fclose(in2);
                fclose(out);
                remove(in2Name);
            }
            else {
                sprintf(outName, "temp_nat_new%d.txt", newTempCount++);
                FILE* out = fopen(outName, "w");

                T val;
                while (fscanf(in1, "%lf", &val) == 1) {
                    fprintf(out, "%f ", val);
                }

                fclose(out);
            }

            fclose(in1);
            remove(in1Name);
        }

        for (int i = 0; i < newTempCount; ++i) {
            char oldName[50], newName[50];
            sprintf(oldName, "temp_nat_new%d.txt", i);
            sprintf(newName, "temp_nat_%d.txt", i);
            rename(oldName, newName);
        }

        tempCount = newTempCount;
    }

    if (tempCount == 1) {
        rename("temp_nat_0.txt", outputFile);
    }
}

template void naturalMergeSort<double>(const char*, const char*);