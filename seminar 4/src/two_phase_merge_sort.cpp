#include "two_phase_merge_sort.h"
#include <cstdio>
#include <cstdlib>
#include <climits>

#define SIZEOF(arr) (sizeof(arr)/sizeof(arr[0]))

template <typename T>
int compare(const void* a, const void* b) {
    T x = *(const T*)a;
    T y = *(const T*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

template <typename T>
void mergeTwoFiles(FILE* in1, FILE* in2, FILE* out) {
    T val1, val2;
    int read1 = fscanf(in1, "%lf", &val1);
    int read2 = fscanf(in2, "%lf", &val2);

    while (read1 == 1 && read2 == 1) {
        if (val1 <= val2) {
            fprintf(out, "%f ", val1);
            read1 = fscanf(in1, "%lf", &val1);
        }
        else {
            fprintf(out, "%f ", val2);
            read2 = fscanf(in2, "%lf", &val2);
        }
    }

    while (read1 == 1) {
        fprintf(out, "%f ", val1);
        read1 = fscanf(in1, "%lf", &val1);
    }

    while (read2 == 1) {
        fprintf(out, "%f ", val2);
        read2 = fscanf(in2, "%lf", &val2);
    }
}

template <typename T>
void twoPhaseMergeSort(const char* inputFile, const char* outputFile) {
    const int BUFFER_SIZE = 100;
    T buffer[BUFFER_SIZE];
    int count = 0;
    int fileCount = 0;

    FILE* input = fopen(inputFile, "r");
    if (!input) return;

    while (fscanf(input, "%lf", &buffer[count]) == 1) {
        count++;
        if (count == BUFFER_SIZE) {
            qsort(buffer, count, sizeof(T), compare<T>);

            char tempName[50];
            sprintf(tempName, "temp%d.txt", fileCount++);
            FILE* temp = fopen(tempName, "w");
            for (int i = 0; i < count; ++i) {
                fprintf(temp, "%f ", buffer[i]);
            }
            fclose(temp);
            count = 0;
        }
    }

    if (count > 0) {
        qsort(buffer, count, sizeof(T), compare<T>);
        char tempName[50];
        sprintf(tempName, "temp%d.txt", fileCount++);
        FILE* temp = fopen(tempName, "w");
        for (int i = 0; i < count; ++i) {
            fprintf(temp, "%f ", buffer[i]);
        }
        fclose(temp);
    }
    fclose(input);

    while (fileCount > 1) {
        int newFileCount = 0;
        for (int i = 0; i < fileCount; i += 2) {
            char in1Name[50], in2Name[50], outName[50];
            sprintf(in1Name, "temp%d.txt", i);
            FILE* in1 = fopen(in1Name, "r");

            if (i + 1 < fileCount) {
                sprintf(in2Name, "temp%d.txt", i + 1);
                FILE* in2 = fopen(in2Name, "r");
                sprintf(outName, "temp_new%d.txt", newFileCount++);
                FILE* out = fopen(outName, "w");

                mergeTwoFiles<T>(in1, in2, out);

                fclose(in2);
                fclose(out);
                remove(in2Name);
            }
            else {
                sprintf(outName, "temp_new%d.txt", newFileCount++);
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

        for (int i = 0; i < newFileCount; ++i) {
            char oldName[50], newName[50];
            sprintf(oldName, "temp_new%d.txt", i);
            sprintf(newName, "temp%d.txt", i);
            rename(oldName, newName);
        }
        fileCount = newFileCount;
    }

    if (fileCount == 1) {
        rename("temp0.txt", outputFile);
    }
}

template void twoPhaseMergeSort<double>(const char*, const char*);