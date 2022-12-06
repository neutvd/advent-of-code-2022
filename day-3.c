/*
 * Advent of code puzzle day 3 (3 Dec 2022)
 * Compile with
 * gcc -o day-3 day-3.c
 *
 * Run:
 * ./day-3 < day-3-input
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define READ_LENGTH 100

int main();

int main() {
    char line[READ_LENGTH];
    long upper_prio = 0, lower_prio = 0, line_nr = 0;
    while (fgets(line, READ_LENGTH-1, stdin)) {
        char* part1, *part2;
        int line_len, part1_idx, part2_idx;
        line_len = strlen(line);
        if (line[line_len-1] == '\n') {
            line[line_len-1] = '\0';
            printf("Stripping newline from line %ld [%s]\n", line_nr, line);
            line_len = strlen(line);
        }
        if (line_len % 2 != 0) {
            printf("Line %ld has odd number of items %d\n", line_nr, line_len);
            exit(1);
        }
        for (part1_idx = 0; part1_idx < line_len / 2; part1_idx++) {
            char *c = strchr(&line[line_len/2], line[part1_idx]);
            if (c != NULL) { /* found */
                if (isupper(*c)) {
                    int prio = *c + 27 - 65; /* Substract ascii value */
                    upper_prio += prio;
                    printf("Found %c UPPER prio raised by %d\n", *c, prio);
                    break;
                } else {
                    int prio = *c + 1 - 97; /* Substract ascii value */
                    lower_prio += prio;
                    printf("Found %c lower prio raised by %d\n", *c, prio);
                    break;
                }
            }
        }
        line_nr++;
    }
    printf("UPPER prio: %ld\nLower prio: %ld\nTotal: %ld\n",
           upper_prio, lower_prio, upper_prio+lower_prio);
}
