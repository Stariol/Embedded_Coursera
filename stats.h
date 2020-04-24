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
 * @file stats.h
 * @brief Statistic function headers
 *
 * Definition of statistic functions to find maximum, minimum, median or mean
 * values and print the results.
 *
 * @author David Marcos
 * @date 24/04/2020
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

void print_statistics(uint8_t min, uint8_t max, float mean, float median);

/**
 * @brief Print statistic data
 *
 * Print the minimum, maximum, mean and median values.
 *
 * @param min		: Minimum value
 * @param max		: Maximum value
 * @param mean		: Mean value
 * @param median	: Median value
 *
 * @return NULL
 */

void print_array(uint8_t* array, uint8_t len);

/**
 * @brief Print 1D the array
 *
 * Print N elements of one-dimensional array
 *
 * @param array		: Pointer of the array with the data
 * @param len		: Length of the array or N elements to be printed
 *
 * @return NULL
 */

float find_median(uint8_t* array, uint8_t len);

/**
 * @brief Find median value
 *
 * Find median value of the input array.
 *
 * @param array		: Pointer of the array with the data
 * @param len		: Length of the array
 *
 * @return Median	: Median value (float type)
 */

float find_mean(uint8_t* array, uint8_t len);

/**
 * @brief Find mean value
 *
 * Find mean value of the input array.
 *
 * @param array		: Pointer of the array with the data
 * @param len		: Length of the array
 *
 * @return Median	: Mean value (float type)
 */

uint8_t find_maximum(uint8_t* array, uint8_t len);

/**
 * @brief Find maximum value
 *
 * It returns the maximum value of the input array.
 *
 * @param array		: Pointer of the array with the data
 * @param len		: Length of the array
 *
 * @return Median	: Maximum value (unsigned 8 bit type)
 */

uint8_t find_minimum(uint8_t* array, uint8_t len);

/**
 * @brief Find minimum value
 *
 * It returns the minimum value of the input array.
 *
 * @param array		: Pointer of the array with the data
 * @param len		: Length of the array
 *
 * @return Median	: Minimum value (unsigned 8 bit type)
 */

void sort_array(uint8_t* array, uint8_t len);

/**
 * @brief Sort array decreasing order
 *
 * Sort the array in decreasing order using the Bubble Sort algorithm. The
 * array to be sorted is passed as a pointer.
 *
 * @param array		: Pointer of the array to be sorted
 * @param len		: Length of the array
 *
 * @return NULL
 */

#endif /* __STATS_H__ */