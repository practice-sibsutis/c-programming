#include "../include/advanced_array_function.h"

int max_subarray_sum(int* nums, int size) {
    if (size == 0){
        return 0;
    }
    //---------------------------------------
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
    //---------------------------------------
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
    }
    
    return max_len;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {

    for (int i = 0; i < intervalsSize - 1; i++) {
        for (int j = 0; j < intervalsSize - i - 1; j++) {
            if (intervals[j * 2] > intervals[(j + 1) * 2]) {
                int temp_start = intervals[j * 2];
                int temp_end = intervals[j * 2 + 1];
                intervals[j * 2] = intervals[(j + 1) * 2];
                intervals[j * 2 + 1] = intervals[(j + 1) * 2 + 1];
                intervals[(j + 1) * 2] = temp_start;
                intervals[(j + 1) * 2 + 1] = temp_end;
            }
        }
    }
    int* result = (int*)malloc(intervalsSize * 2 * sizeof(int));
    int count = 0;
    result[0] = intervals[0];
    result[1] = intervals[1];
    count = 1;
    
    for (int i = 1; i < intervalsSize; i++) {
        int start = intervals[i * 2];
        int end = intervals[i * 2 + 1];
        int last_end = result[count * 2 - 1];
        
        if (start <= last_end) {
            if (end > last_end) {
                result[count * 2 - 1] = end;
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