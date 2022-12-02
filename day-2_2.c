/*
 * Advent of code puzzle day 2, part 2 (2 Dec 2022)
 * Compile with
 * gcc -o day-2_2 day-2_2.c
 */

#include <stdio.h>
#include <stdlib.h>

#define READ_LENGTH 100

int main(int argc, char* argv[]);
int score(char play);
char win(char play);
char lose(char play);
char draw(char play);

int main(int argc, char* argv[]) {
    FILE *fp;
    char line[READ_LENGTH];
    long oppo_score = 0;
    long my_score = 0;
    
    fp = fopen("day-2-input", "r");
    if (fp == NULL) {
        perror("Could not open input.");
        exit(1);
    }
    while(fgets(line, READ_LENGTH-1, fp)) {
        char opponent = line[0];
        char result = line[2];
        char me;
        
        if (result == 'X') {
            /* I have to lose */
            oppo_score += 6;
            me = lose(opponent);            
        } else if (result == 'Y') {
            my_score += 3;
            oppo_score += 3;
            me = draw(opponent);
        } else {
            my_score += 6;
            me = win(opponent);
        }
        my_score += score(me);
        oppo_score += score(opponent);
    }
    printf("My score: %ld\nOpponent's score: %ld\n", my_score, oppo_score);
}

char lose(char play) {
    switch(play) {
    case 'A':
        return 'C';
    case 'B':
        return 'A';
    case 'C':
        return 'B';
    }
}

char win(char play) {
    switch(play) {
    case 'A':
        return 'B';
    case 'B':
        return 'C';
    case 'C':
        return 'A';
    }
}

char draw(char play) {
    switch(play) {
    case 'A':
        return 'A';
    case 'B':
        return 'B';
    case 'C':
        return 'C';
    }
}

int score(char play) {
    int score;
    switch(play) {
    case 'A':
        score = 1;
        break;
    case 'B':
        score = 2;
        break;
    case 'C':
        score = 3;
        break;
    }
    return score;
}
