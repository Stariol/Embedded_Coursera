/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Statistic functions
 *
 * Definition of statistic functions to find maximum, minimum, median or mean
 * values and print the results.
 *
 * @author David Marcos
 * @date 24/04/2020
 *
 */

#include <stdio.h>
#include <stdint.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

	uint8_t test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

	/* Other Variable Declarations Go Here */
	
	uint8_t *test_ptr;
	uint8_t test_sorted[SIZE];
	uint8_t *test_sorted_ptr;
	uint8_t maximum_value = 0;
	uint8_t minimum_value = 0;
	uint8_t i = 0;
	float mean_value = 0;
	float median_value = 0;
	
	/* Statistics and Printing Functions Go Here */
	
	for(i = 0; i < SIZE; i++){
		test_sorted[i] = test[i];	
	}
	
	test_ptr = &test[0];
	test_sorted_ptr = &test_sorted[0];
	
	sort_array(test_sorted_ptr, SIZE);
	
	minimum_value = find_minimum(test_ptr, SIZE);
	maximum_value = find_maximum(test_ptr, SIZE);
	median_value = find_median(test_ptr, SIZE);
	mean_value = find_mean(test_ptr, SIZE);
	
	printf("\nTest array:");
	print_array(test_ptr, SIZE);
	printf("\nSorted test array:");
	print_array(test_sorted_ptr, SIZE);
	print_statistics(minimum_value, maximum_value, mean_value, median_value);
	printf("\nEnd of program\n\n");
}

/* Add other Implementation File Code Here */

void print_statistics(uint8_t min, uint8_t max, float mean, float median) {
	printf("\nminimum = %u", min);
	printf("\nmaximum = %u", max);
	printf("\nmean = %.3f", mean);
	printf("\nmedian = %.3f\n", median);
}

void print_array(uint8_t* array, uint8_t len) {
	uint8_t i = 0;
	printf("\n[%u", array[0]);
	for(i = 1; i < len; i++){
		printf(", %u",array[i]);
	}
	printf("]\n");
}

float find_median(uint8_t* array, uint8_t len) {
	uint8_t sorted_array[len];
	float median;
	uint8_t i;
	if(len < 1) {
		return 0;
	}
	for(i = 0; i < len; i++) {
		sorted_array[i] = array[i];
	}
	sort_array(sorted_array, len);
	if(len%2>0){
		median = (float)sorted_array[(len+1)/2-1];
	} else {
		median = ((float)sorted_array[len/2-1]+(float)sorted_array[len/2])/2;
	}
	return median;
}

float find_mean(uint8_t* array, uint8_t len) {
	uint8_t sorted_array[len];
	float mean = 0;
	uint8_t i = 0;
	if(len < 1) {
		return 0;
	}
	for(i = 0; i < len; i++) {
		mean += (float)array[i];
	}
	mean = mean/((float)len);
	return mean;
}

uint8_t find_maximum(uint8_t* array, uint8_t len) {
	uint8_t max;
	uint8_t i = 0;
	if(len < 1) {
		return 0;
	}
	max = array[0];
	for(i = 0; i < len; i++) {
		if(max < array[i]){
			max = array[i];
		}
	}
	return max;
}

uint8_t find_minimum(uint8_t* array, uint8_t len) {
	uint8_t min;
	uint8_t i = 0;
	if(len < 1) {
		return 0;
	}
	min = array[0];
	for(i = 0; i < len; i++) {
		if(min > array[i]){
			min = array[i];
		}
	}
	return min;
}

void sort_array(uint8_t* array, uint8_t len) {
	uint8_t temp = 0;
	uint8_t i = 0;
	uint8_t j = 0;
	for(i = 0; i < len; i++){
		for(j = (len-1); j > i; j--){
			if(array[j-1] < array[j]){
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
			}
		}
	}
}