#include "game.h"
#include "strand.h"
#include <stdbool.h>
#include <string.h>

// REQUIRED
//argc is the number of arguments it will receive within argv
//argv is the command line arguments

//this fucntion Opens the data file for the strand game.
//If a filename is provided as a command line argument, it opens that file.
//FILE*: Pointer to the opened file stream.
//If no filename is provided, it prompts the user to enter the filename.
//The file is opened in read mode.
FILE * open_data_file(int argc, char** argv) {
    char name[101];
    FILE* fp;

    if (argc >=2) {
        //open argv and equal it to fp
        fp = fopen(argv[1], "r");
    }else{
        printf("Provide strand data filename:");
        //%s is for strings
        scanf("%s",name);
        fp = fopen(name, "r");
    }
    return fp;
    //    fclose(fp);
}

// REQUIRED

//Opens the dictionary file for the strand game.
//If a filename is provided as a command line argument, it opens that file.
//If no filename is provided, it opens the default dictionary file defined in game.h.
//The file is opened in read mode.
FILE * open_dict_file(int argc, char** argv) {
    // char dict_name[100];
    FILE* dict_fp;
    //char name[100];
    if (argc >=3) {
        //we assume that a strand file name is provided in argv[1] from prev function
        dict_fp = fopen(argv[2], "r");

    }else {
      
        //DICT_PATH is defined in game.h with the name of the file (the path name)
        dict_fp = fopen(DICT_PATH, "r");
    }

    return dict_fp;
    // fclose(dict_fp);
}




//this functions  Stores and checks a word in the array of found words.
//Checks if the word is already in the array of found words.
//If the word is not found, it is stored in the array and the number of found words is incremented.
bool store_and_check_word(strand_t*strand,char *word, char Wordsfound[][100],int *numFoundWords) {
  int i;//initialize the variables that will be used
    strand->numFoundWords=*numFoundWords;


    //iterate in all the words found if its the same as words
    for (i=0; i< *numFoundWords ;i++) {
      if (strcmp(word,Wordsfound[i]) == 0) {//if 0, so the same, we return true
	 
	  return true;
        }
    }
   
   strcpy(Wordsfound[*numFoundWords],word);
   (*numFoundWords)++;//we add one to numFoundWords, its a pointer so the number is passed by reference
    
    return false;
}


//instruction sof the game were given
void print_instructions(strand_t * strand) {
    printf("\n  +-- Welcome to Strands! --+\n");
    printf("\nInstructions:\n");
    printf("\tFind all %d %d-letter words\n",strand->numWords, strand->wordLen);
    printf("\tEach word's letters must touch\n");
    printf("\tA letter can be repeated in a word\n");
    printf("\tType a word then press 'Enter'\n");
    printf("\tType 'quit' when done\n");
}

// REQUIRED
//void play_game(strand_t * strand, FILE* dictFP,char **valid_words) {
void play_game(strand_t * strand) {


    //  printf("%d in find valid words in playgame \n",words_in_dict);
    //here we put all the printing syntax

    char guess[100];
    //bool continue_playing = true;
    //int guess_correct;
    //bool first_run = true;
    //int words_found = 0;
    //int already_guess;
    int numFoundWords = 0;
    bool finding = false;
    //bool correct = false;
    //int words_repeated = 0;
   
    bool finish = false;
    char Wordsfound[strand->numWords][100];


    while (!finding) {

        if (strand->words == NULL) {
            printf("Memory allocation failed for valid_words\n");
            return;  // Or handle the error accordingly
        }

        while ((getchar()) != '\n'); // Clear input buffer
        printf("Guess a word or 'quit': \n");
        scanf("%s", guess);//continue_playing =true; defaulted

        if (strcmp(guess, "quit") == 0) {//first we check if input is wuit to see if continue prompting
	  printf("You found %d out of %d %d-letter words.\n", strand->numFoundWords, strand->numWords, strand->wordLen);
            printf("Thanks for playing!");
            finding = true; //we exit this function, all memory should be erased from the strand
            finish = true;
        }


        if (!finish) {
            if (is_word_in_strand(strand, guess)) {
	      if (!store_and_check_word(strand,guess, Wordsfound, &numFoundWords)) {
                    strand->numFoundWords++;
                    printf("%s is a valid word in the strand!\n", guess);
                    //printf("You have found %d of %d %d-letter words in the strand so far.\n", words_found,
                    if (strand->numFoundWords == strand->numWords) {
                        printf("You found all %d %d-letter words!\n Great job! Thanks for playing!\n",
                               strand->numFoundWords, strand->wordLen);
                        finding = true;
                    } else {
                        printf("You have found %d of %d %d-letter words in the strand so far.\n", strand->numFoundWords,
                               strand->numWords, strand->wordLen);
                    }

                } else {
                    //printf("number that words repeat is %d",guess);
                    printf(" You have already guessed %s!\n", guess);
                    printf("You have found %d of %d %d-letter words in the strand so far.\n", strand->numFoundWords,
                           strand->numWords, strand->wordLen);
                }
            } else {
                printf("%s is not a valid word in the strand.\n", guess);
                printf("You have found %d of %d %d-letter words in the strand so far.\n", strand->numFoundWords,
                       strand->numWords, strand->wordLen);
                printf("\n");
            }


        }
    }
}





















