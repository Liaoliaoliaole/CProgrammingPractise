/***********************************************
1. which character has most occurrence？
2. starting with which letter has most words?
3. which consonant has most occurrence？
4. how many palindromes in the dictionary?
5. which consonant digraphs has most occrrence？
*************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>


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
            case 'd':get_csnt_digraphs();
                    break;
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





