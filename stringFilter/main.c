/***********************************************
1. which character has most occurrence？
2. starting with which letter has most words?
3. which consonant has most occurrence？
4. how many palindromes in the dictionary?
5. which consonant digraphs has most occrrence？
*************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ASCIILENGTH 256
#define MAXWORDSLENGTH 50


void operation_options();
int get_letters();
void get_most_character();
void get_most_letter(int* arr, int l, int* maxc, char* mch);
void get_most_consonant(int* arr, int l, int* maxc, char* mch);
int* count_words();
void get_most_words();
void get_palindromes();

int main(void) {
    FILE* fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("File is unable to open.");
        return 1;
    }
    else {
        operation_options();
        int x = 1;
        while (x) {
            printf("\n");
            printf("******Dictionary Analysis******\n");
            switch (getchar())
            {
            case 'c':get_most_character();
                break;
            case 'w':get_most_words();
                break;
            case 'p':get_palindromes();
                    break;
            /*case 'd':get_csnt_digraphs();
                    break;*/
            case 'q': exit(0);
                break;
            defalut:
                printf("¤¤¤¤¤¤¤¤¤¤Please enter again: ");
                operation_options();
            }
        }
    }   
    fclose(fp);
    return 0;
}

void operation_options() {
    printf("Options\n");
    printf("****** Press c for which charactor and consonant have most occurrence？\n");
    printf("****** Press w for starting with which letter has most words?\n");
    printf("****** Press p for how many palindromes in the dictionary?\n");
    printf("****** Press d for which consonant digraphs is most common in the dictionary?\n");
    printf("****** Press q for quit the program.\n");
    printf("Press Enter after your choice.\n");
}

int get_letters() {
    FILE* fp = fopen("words.txt", "r");
    //get each character's occurrence count
    //index is the decimal of ASCIII table
    int charCount[ASCIILENGTH] = { 0 };
    int c;
    while ((c = fgetc(fp))) {
if (c == EOF) break;
charCount[c] = charCount[c] + 1;
    }
    //form a new array:26 elements correspond with 26 letters
     //value of elements are the occurrence of each letter
    int i = 0, x = 0;
    int letter[26] = { 0 };
    while (i < ASCIILENGTH) {
        if (i >= 'A' && i <= 'Z') {
            x = i - 'A';
            letter[x] = charCount[i];
        }
        if (i >= 'a' && i <= 'z') {
            x = i - 'a';
            letter[x] = letter[x] + charCount[i];
        }
        i++;
    }
    fclose(fp);
    return letter;
}

void get_most_character() {
    get_letters();
    int maxcount;
    char maxchar;
    get_most_letter(get_letters(), 26, &maxcount, &maxchar);
    printf("%c the maximum count is %d\n", maxchar, maxcount);
    printf("\n");
    get_most_consonant(get_letters(), 26, &maxcount, &maxchar);
    printf("%c the maximum count is %d\n", maxchar, maxcount);
    printf("\n");
}

void get_most_letter(int* arr, int l, int* maxc, char* mch) {
    int max = arr[0];
    int most_char = 0;
    for (int i = 0; i < l; i++) {
        if (arr[i] > max) {
            max = arr[i];
            most_char = (i + 65);
        }
    }
    *mch = most_char;
    *maxc = max;
}

void get_most_consonant(int* arr, int l, int* maxc, char* mch) {
    int max = 0;
    int most_csnt = 0;
    for (int i = 0; i < l; i++) {
        if ((arr[i] > max) && (i != 'A' - 65) && (i != 'E' - 65) && (i != 'I' - 65) && (i != 'O' - 65) && (i != 'U' - 65)) {
            max = arr[i];
            most_csnt = (i + 65);
        }
    }
    *mch = most_csnt;
    *maxc = max;
}

int* count_words() {
    char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    FILE* fp = fopen("words.txt", "r");
    char word[MAXWORDSLENGTH];
    int wcount[26] = { 0 };
    while (fscanf(fp, "%s", word) == 1) {
        for (int i = 0; i < 26; i++) {
            if ((word[0] == alphabet[i]) || (word[0] == toupper(alphabet[i]))) {
                wcount[i]++;
            }
        }
    }
    /*for (int x = 0; x < 26; x++) {
    printf("Start with '%c' words appear %d times.\n", alphabet[x], wcount[x]);
    }*/
    fclose(fp);
    return wcount;
}

void get_most_words() {
    int* arr = count_words();
    int max = arr[0];
    int most_word = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] > max) {
            max = arr[i];
            most_word = (i + 65);
        }
    }
    printf("Starting with '%c' words has the maximum count %d\n", most_word, max);
    printf("\n");
}

void get_palindromes() {
    FILE* fp = fopen("words.txt", "r");
    char word[MAXWORDSLENGTH];
    int wcount = 0;
    
    while (fscanf(fp, "%s", word) == 1) {
        int left = 0;
        int right = strlen(word) - 1;
        while (right > left) {
            if (word[left++] == word[right--]) {
                wcount++;
            }
        }   
    }
    fclose(fp);
    printf("Palindromes appear %d times intotal.\n", wcount);
}





