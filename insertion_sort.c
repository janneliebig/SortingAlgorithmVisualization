// Insertion Sort
// 04. Februar 2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

int size = 100;
int min_value = 0;
int max_value = 100;

int insertion_sort(size_t, int*);
int print_array(size_t, int*);
int* random_array(size_t, int, int);
int* descending_array(size_t, int, int);
void print_array_special(size_t, int*);
void set_position(int,int);

int main(int argc, char** argv) {
	
	int descending = 0;
	int* to_sort;
	
	if(argc < 5) {
		printf("ver<x> [min_value] [max_value] [list_size] [(r|u)]\n");
		return 0;
	}
	
	if(argc == 5) {
		min_value = atoi(*(argv + 1));
		max_value = atoi(*(argv + 2));
		size = atoi(*(argv + 3));
		if( strcmp(*(argv + 4), "r") == 0) {
			descending = 0;
		} else {
			descending = 1;
		}
	}	

	system("clear");
	
	if(max_value < min_value) return 0;
	
	if(descending == 1) {
		to_sort = descending_array(size, min_value, max_value);
	}
	else {
		to_sort = random_array(size, min_value, max_value);
	}
	insertion_sort(size, to_sort);
}

int insertion_sort(size_t length, int* array) {
	
	int s = 0;
	
	for(size_t i = 1; i < length; i++) {
		if(*(array + i - 1) > *(array + i)) {
			s = *(array + i);
			
			size_t k = i;
			for(; k > 0 && *(array + k -1) > s; k--) {
				*(array + k) = *(array + k - 1);
				print_array_special(length, array);
			}
			*(array + k) = s;
			print_array_special(length, array);
		}
	}
	return 0;
}

int* random_array(size_t length, int min, int max) {
	int* array = (int*)malloc(sizeof(int) * length);
	if(array == NULL) {
		fprintf(stderr, "Memory error");
		return NULL;
	}
	
	srand(time(NULL));
	
	for(size_t i = 0; i < length; i++) {
		*(array + i) = rand() % (max-min) + min + 1; 
	}
	
	return array;	
}

int* descending_array(size_t length, int min, int max) {
	int* array = (int*)malloc(sizeof(int) * length);
	if(array == NULL) {
		fprintf(stderr, "Memory error");
		return NULL;
	}
	
	for(size_t i = 0; i < length; i++) {
		*(array + i) = length - i; 
	}
	return array;
}

int print_array(size_t length, int* array) {
	printf("[");
	for(size_t i = 0; i < length - 1; i++) {
		printf("%d, ", *(array + i));
	}
	printf("%d]\n", *(array + length - 1));
	return 0;
}

void print_array_special(size_t length, int* array) {
	set_position(0,0);
	for(size_t i = 0; i < length; i++) {
		printf("%4d : ", *(array+i));
		for(size_t j = 0; j < *(array + i); j++) {
			printf("▓");
		}
		for(size_t j = 0; j < max_value - *(array + i); j++) {
			printf(".");
		}
		printf("\n");
	}
	printf("...\n");
	
}

void set_position(int x, int y)
{
	HANDLE screen;
	screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position={x, y};

	SetConsoleCursorPosition(screen, position);
}
