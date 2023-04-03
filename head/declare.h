#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


#define N 10000

void quickSort(int* a, int head, int tail);
void countSort(int* a);
void radixSort(int* a);
void InsertionSort(int* a, int n);  

void mergeSort(int* a, int start, int end);
void merge(int* a, int start, int mid, int end);

void colorSort(int * a,int n);
void findData(int* arr, int count, int loc);