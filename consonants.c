/*
 * File name: consonants.c
 * Project: Project on Consonants #2
 * CPSC 275 F 2020
 * Author: @Rakan AlZagha
 */

#include <stdio.h>
#include <math.h> //for the absolute value of golden ratio

#define MAXCHAR 25 //no word > 25
#define MAXWORD 1000 //no more than 1000 words
#define GRATIO 0.618 //golden ratio

void Sort(float A[], char wordOrder[][MAXCHAR], int n); //sort prototype
int Compare(float x, float y); //compare prototype

/*
 *   Function: main()
 *   ----------------------------
 *   Purpose: reading in an input file of words, store them into a 2D array
 *   and maintain a count of consonants, total words, and characters in a word
 *
 */

void main(void) {
  int i = 0, j = 0, row = 0, column = 0, countWords = 0;
  float percent[MAXWORD], countChar = 0, countCons = 0;
  char wordChar[MAXWORD][MAXCHAR], c;

  while((c = getchar()) != EOF) { //continue scanning in the input file until encounter EOF sign
    if (c == '\n' || c == '\0') { //each string gets its own row, go to next row and col = 0 if new word
      row++, column = 0;
      percent[i] = countCons/countChar; //calculate consonant/total characters
      countChar = 0, countCons = 0; //reset for next word
      countWords++, i++; //iterate amount of words and go to next pos for percent[i]
    }
    else { //if a regular character assign to respective row and iterate column
      wordChar[row][column] = c;
      column++, countChar++;
      if(c != 'a' && c!= 'e' && c != 'i' && c != 'o' && c != 'u') { //consonant count
        countCons++;
      }
    }
  }

  Sort(percent, wordChar, countWords); //calling sort function and pass in arrays and word count

  printf("A list of English words, sorted in increasing order of difficulty to pronounce: \n");
  printf("Words\tGolden Ratio\n");
  for(row = 0; row < countWords; row++) { //loop through 2D array rows
    for(column = 0; column < MAXCHAR; column++) { //go through each column
        printf("%c", wordChar[row][column]); //print each word
    }
    printf(":\t%.3f", percent[row]); //corresponding percentage
    printf("\n");
  }
}

/*
 *   Function: Sort()
 *   ----------------------------
 *   Purpose: sorting a float array holding goldenRatio percentage-ratios and
 *   to sort a 2D array holding the words passed in by STDIN
 *
 *   float A[]:
 *   char wordOrder[][]: Array holding the words passed in via STDIN
 *   int n: total amount of words (represent rows and count of values in array A)
 *
 */

void Sort(float A[], char wordOrder[][MAXCHAR], int n) {
  int k, j, i;
  float key, consPercent, goldenRatioCalc;
  char wordKey[MAXCHAR]; //key for parrallel array sorting (represents chars)

  //converting A[] contents into the goldenratio percent before sorting it
  for(i = 0; i < n; i++) { //loop through the array based on word count
    consPercent = A[i]; //consonant percentage pre-sort
    goldenRatioCalc = fabs(consPercent - GRATIO); //calculate the golden ratio and take absolute value
    A[i] = goldenRatioCalc; //reassign golden ratio to array pos (replace old percentage)
  }

  // sort algorithm implementation
  for(j = 1; j < n; j++) { //loop by the count of words (size of array A)
    key = A[j]; //key set to first position in array
    for (i = 0; i < MAXCHAR; i++) { //looping through columns of each row to get word
      wordKey[i] = wordOrder[j][i];//key set
    }
    k = j - 1; //previous position (0) first time
    while(k >= 0 && Compare(A[k], key)) { //comparison, if T continue, if false END
      A[k+1] = A[k]; //shifting array A
      i = 0;
      while(i < MAXCHAR) { // loop through the word array and shift accordingly
        wordOrder[k + 1][i] = wordOrder[k][i]; //re-set to correct pos
        i++; //iterate to next column
      }
      k = k - 1;
    }
    A[k + 1] = key; //re-set and continue sorting if needed
    for(i = 0; i < MAXCHAR; i++){ //re-set and continue sorting if needed
      wordOrder[k + 1][i] = wordKey[i];
    }
  }
}

/*
 *   Function: Compare()
 *   ----------------------------
 *   Returns TRUE if the value x, passed by Sort() is > than y, FALSE elsewise
 *
 *   x: one real value
 *   y: the other real value
 *
 */

int Compare(float x, float y) {
  if(x > y) { //comparing x and y
    return 1; //true
  }
  return 0; //else false
}
