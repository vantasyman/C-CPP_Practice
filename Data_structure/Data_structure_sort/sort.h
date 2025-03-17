#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void insertsort(int* a, int n);
void ShellSort(int* a, int n);
void selectsort(int* a, int n);
void my_qsort(int* arr, int begin, int end);
void my_qsort2(int* arr, int begin, int end);
void bubblesort(int* p, int sz);
void my_qsort3(int* arr, int begin, int end);
void _MergeSort(int* a, int left, int right, int* tmp);
void MergeSort(int* arr, int n);
void FileSort(FILE* p, int n);