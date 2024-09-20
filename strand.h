//
// Created by MacBook Pro on 4/6/24.
//

#ifndef UNTITLED7_STRAND_H
#define UNTITLED7_STRAND_H

#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

// REQUIRED STRUCT - DO NOT REMOVE STRUCT MEMBERS
//March 28 task, which strand elements do we know?
//1) char** words; 2) char** letters; 3) int rows, cols;  4)int wordLen;
//5) I donk know the numWords, I'll asume a number for now

typedef struct strand
{
    //doublke pointer means it's a 2D array, one is word, the other is the char
    char** words;
    char** letters;
    int rows, cols;
  //  int numWords;
  //int wordLen;

  int numWords;
      char** matrix;
    int numFoundWords;
  int wordLen;
    char** Wordsfound;


} strand_t;


// REQUIRED FUNCTIONS
strand_t * create_strand(FILE * dataFP, FILE * dictFP);
bool recursive(strand_t *strand, int x, int y, char*word ,int count);
void populate_valid_words(strand_t *strand, FILE *dictFP);
bool find_valid_words(strand_t *strand, char* word);
bool is_word_in_strand(strand_t * strand, char * word);
void print_strand_matrix(strand_t * strand);
void free_strand(strand_t * strand);









#endif //UNTITLED7_STRAND_H
