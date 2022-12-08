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
    long contain_count = 0, overlap_count = 0;

    while (fgets(line, READ_LENGTH-1, stdin)) {
        int b1 = atoi(strtok(line, "-,"));
        int e1 = atoi(strtok(NULL, "-,"));
        int b2 = atoi(strtok(NULL, "-,"));
        int e2 = atoi(strtok(NULL, "-,"));

        if (b1 <= b2 && e1 >= e2) contain_count++;
        else if (b2 <= b1 && e2>= e1) contain_count++;
        else if ((b1 <= b2 && e1 >= b2) || (b1 <= e2 && e1 >= e2)) {
            printf("%d-%d and %d-%d overlap\n", b1, e1, b2, e2);
            overlap_count++;
        } else {
            printf("%d-%d and %d-%d DO NOT overlap\n", b1, e1, b2, e2);
        }
    }
    printf("Nr of assignment pairs where one contains the other: %ld\n", contain_count);
    printf("Nr of assignment overlapping pairs: %ld\n", overlap_count + contain_count);
    exit(0);
}
