/*
 * Advent of code puzzle day 25 (1 Dec 2022)
 * Compile with
 * gcc -o day-1 day-1.c
 *
 * To get the top three:
 * ./day-1 | grep -v highest | cut -d ' ' -f 5 | sort -hr | head -3
 */

#include <stdio.h>
#include <stdlib.h>

#define READ_LENGTH 100

int main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    long highest_calories = 0;
    char line[READ_LENGTH];
    long total_calories = 0;
    long elfnr = 0;
    long highest_elf;
    FILE* fp;

    fp = fopen("day-1-input", "r");
    if (fp == NULL) {
        perror("Could not open input.");
        exit(1);
    }
    while(fgets(line, READ_LENGTH-1, fp)) {
        long calories;
        if (line[0] != '\n') {
            calories = atol(line);
            total_calories = total_calories + calories;
        } else {
            printf("Elf %ld is carrying %ld calories\n",
                   elfnr, total_calories);
            if (total_calories > highest_calories) {
                highest_calories = total_calories;
                highest_elf = elfnr;
            }
            total_calories = 0;
            elfnr++;
        }
    }
    printf("Elf %ld is carrying the highest amount and is carrying %ld calories\n",
           highest_elf, highest_calories);
    exit(0);
}
