#include "../include/advanced_array_function.h"
#include <stdlib.h>

/*1. Реализовать функцию int max_subarray_sum(int* nums, int size), которая принимает
целочисленный массив и его размер. И находит непрерывный подмассив (содержащий хотя бы
один элемент) в целочисленном массиве, который имеет наибольшую сумму. Если все числа
отрицательные, алгоритм все равно должен корректно работать (возвращая наименьшее по
модулю отрицательное число).*/

int max_subarray_sum(int* nums, int size) {
    if (size == 0){
        return 0;
    }
    int max_sum = nums[0];
    int right = 0;
    int sum = 0;
    
    int max_element = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > max_element) {
            max_element = nums[i];
        }
    }
    if (max_element < 0) {
        return max_element;
    }
    while (right < size) {
        sum += nums[right];
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (sum < 0) {
            right++;
            sum = 0;
        } else {
            right++;
        }
    }
    return max_sum;
}
/*2. Реализовать функцию int length_of_lis(int* nums, int numsSize), которая принимает
целочисленный массив и его размер. И находит длину самой длинной непрерывной строго
возрастающей подпоследовательности в данном массиве.
Пример: Для [10, 9, 2, 3, 7, 101, 18] LIS имеет длину 4 (например, [2, 3, 7, 101]).*/

int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int max_len = 1;
    int len = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) {
            len++;
        } else {
            if (len > max_len) {
                max_len = len;
            }
            len = 1;
        }
        if (len > max_len) {
            max_len = len;
        }
    }
    
    return max_len;
}
/*1. Реализовать функцию int* merge(int* intervals, int intervalsSize, int*
returnSize), которая принимает целочисленный массив и количество интервалов. Входной
массив сожержит интервалы чисел, например, {1,3,4,7} — интервалы [1; 3], [4; 7].
Объедините все перекрывающиеся интервалы и верните массив непересекающихся
интервалов, покрывающих все исходные интервалы в отсортированном виде. Через
returnSize верните размер результирующего массива.
Пример: Вход: [[1,3],[2,6],[8,10],[15,18]]. Выход: [[1,6],[8,10],[15,18]].*/

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    int* result = (int*)malloc(intervalsSize * 2 * sizeof(intervals[0]));
    int count = 0;
    result[0] = intervals[0];
    result[1] = intervals[1];
    count = 1;
    
    for (int i = 1; i < intervalsSize; i++) {
        int start = intervals[i * 2];
        int end = intervals[i * 2 + 1];
        int last_end = result[(count - 1) * 2 + 1];
        
        if (start <= last_end) {
            if (end > last_end) {
                result[(count - 1) * 2 + 1] = end;
            }
        } else {
            result[count * 2] = start;
            result[count * 2 + 1] = end;
            count++;
        }
    }
    *returnSize = count;
    return result;
}