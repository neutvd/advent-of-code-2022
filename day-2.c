/*
 * Advent of code puzzle day 2 (2 Dec 2022)
 * Compile with
 * gcc -o day-2 day-2.c
 */

#include <stdio.h>
#include <stdlib.h>

#define READ_LENGTH 100

int main(int argc, char* argv[]);
int opponent_score(char play);
int my_score(char play);

enum round_score {lost, draw=3, won=6};

int main(int argc, char* argv[]) {
    FILE *fp;
    char line[READ_LENGTH];
    long oppo_score = 0;
    long score = 0;
    
    fp = fopen("day-2-input", "r");
    if (fp == NULL) {
        perror("Could not open input.");
        exit(1);
    }
    while(fgets(line, READ_LENGTH-1, fp)) {
        char opponent = line[0];
        char me = line[2];
        oppo_score += opponent_score(opponent);
        score += my_score(me);
        
        if ((me == 'X' && opponent == 'A') ||
            (me == 'Y' && opponent == 'B') ||
            (me == 'Z' && opponent == 'C')) {
            oppo_score += 3;
            score += 3;
        } else if ((me == 'X' && opponent == 'C') ||
                   (me == 'Z' && opponent == 'B') ||
                   (me == 'Y' && opponent == 'A')) {
            score += 6;
        } else {
            oppo_score += 6;
        }
    }
    printf("My score: %ld\nOpponent's score: %ld\n", score, oppo_score);
}

int opponent_score(char play) {
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

int my_score(char play) {
    int score;
    switch(play) {
    case 'X':
        score = 1;
        break;
    case 'Y':
        score = 2;
        break;
    case 'Z':
        score = 3;
        break;
    }
    return score;
}
