/*
 * Advent of code puzzle day 4 (4 Dec 2022)
 * Compile with
 * gcc -o day-4 day-4.c
 *
 * Run:
 * ./day-4 < day-4-input
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define READ_LENGTH 100

int main();

int main() {
    char line[READ_LENGTH];
    long count;

    while (fgets(line, READ_LENGTH-1, stdin)) {
        int b1 = atoi(strtok(line, "-,"));
        int e1 = atoi(strtok(NULL, "-,"));
        int b2 = atoi(strtok(NULL, "-,"));
        int e2 = atoi(strtok(NULL, "-,"));

        if (b1 <= b2 && e1 >= e2) count++;
        else if (b2 <= b1 && e2>= e1) count++;
    }
    printf("Nr of assignment pairs where one contains the other: %ld\n", count);
    exit(0);
}
