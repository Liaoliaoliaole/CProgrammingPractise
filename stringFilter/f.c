#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "Header.h"
#define ASCIILENGTH 256
#define MAXWORDSLENGTH 50

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
    while (fscanf(fp, "%49s", word) == 1) {
        for (int i = 0; i < 26; i++) {
            if ((word[0] == alphabet[i]) || (word[0] == toupper(alphabet[i]))) {
                wcount[i]++;
            }
        }
    }
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
    int wpcount = 0;
    int flag = 0;

    while (fscanf(fp, "%49s", word) == 1) {
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        int left = 0;
        int len = strlen(word);
        int right = len - 1;
        if (len % 2 == 0) {
            for (int i = 0; i < len / 2; i++) {
                if (word[left++] != word[right--]) {
                    break;
                }
                else {
                    continue;
                }
                flag += 1;
            }
            if (flag == len / 2) {
                wpcount++;
            }
        }
        if (len % 2 == 1) {
            for (int i = 0; i < (len - 1) / 2; i++) {
                if (word[left++] != word[right--]) {
                    break;
                }
                else {
                    continue;
                }
                flag += 1;
            }
            if (flag == (len - 1) / 2) {
                wpcount++;
            }
        }
    }
    fclose(fp);
    printf("Palindromes appear %d times intotal.\n", wpcount);
}

void get_csnt_digraphs() {
    FILE* fp = fopen("words.txt", "r");
    char word[MAXWORDSLENGTH];
    char cnst_d[11][3] = { {"ch"},{"ck"},{"gh"},{"kn"},{"mb"},{"ng"},{"ph"},{"sh"},{"th"},{"wh"},{"wr"} };
    int sum_count = 0;

    while (fscanf(fp, "%49s", word) == 1) {
        for (int i = 0; i < 11; i++) {
            sum_count += substring_count(word, cnst_d[i]);
        }
    }
    fclose(fp);
    printf("Consonant digraph occur %d times.\n", sum_count);

}

int substring_count(char* str, char* substr) {
    int i, j;
    int c_count = 0, count = 0;
    for (i = 0; i < strlen(str);) {
        j = 0;
        c_count = 0;
        while (str[i] == substr[j]) {
            c_count++;
            i++;
            j++;
        }
        if (c_count == 2) {//if need more than 2 charactor substring filter,here could change into the string length of substr
            count++;
            c_count = 0;
        }
        else {
            i++;
        }
    }
    return count;
}