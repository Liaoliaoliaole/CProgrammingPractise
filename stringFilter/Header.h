#pragma once
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
int substring_count(char* str, char* substr);
void get_csnt_digraphs();
