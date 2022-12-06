/*
 * Advent of code puzzle day 3 part 2 (3 Dec 2022)
 * Compile with
 * gcc -o day-3_2 day-3_2.c
 *
 * Run:
 * ./day-3_2 < day-3-input
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define READ_LENGTH 100

int main();

int main() {
    char members[3][READ_LENGTH];
    char line[READ_LENGTH];
    char member = 0;
    long upper_prio = 0, lower_prio = 0;
    int groupnr = 0;
    while (fgets(line, READ_LENGTH-1, stdin)) {
        if (member < 3) {
            int line_len = strlen(line);
            if (line[line_len-1] == '\n') line[line_len-1] = '\0';
            strcpy(members[member], line);
            member++;
            if (member != 3) continue;
        }
        printf("Read group %d:\n%s\n%s\n%s\n", groupnr, members[0], members[1], members[2]);
        for (int i = 0 ; i < strlen(members[0]) ; i++) {
            char *m1 = strchr(members[1], members[0][i]);
            char *m2 = strchr(members[2], members[0][i]);
            if (m1 != NULL && m2 != NULL) {
                if (isupper(members[0][i])) {
                    int prio = members[0][i] + 27 - 65; /* Substract ascii value */
                    upper_prio += prio;
                    printf("Found %c UPPER prio raised by %d\n", members[0][i], prio);
                    break;
                } else {
                    int prio = members[0][i] + 1 - 97; /* Substract ascii value */
                    lower_prio += prio;
                    printf("Found %c lower prio raised by %d\n", members[0][i], prio);
                    break;
                }
            }
        }
        member = 0;
        groupnr ++;
    }
    printf("UPPER prio: %ld\nLower prio: %ld\nTotal: %ld\n",
           upper_prio, lower_prio, upper_prio+lower_prio);
}
