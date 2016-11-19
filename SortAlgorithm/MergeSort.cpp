//
//  MergeSort.cpp
//  SortAlgorithm
//
//  Created by Tung Nguyen on 11/8/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#include "MergeSort.hpp"
#include <iostream>
MergeSort::MergeSort() {
    
}

void MergeSort::sort(void* base, int nElement, int nSize, int (*cmp)(const void*, const void*)) {
    this->mergeSort(base, 0, nElement-1, nSize, cmp);
}

void MergeSort::mergeSort(void* base, int head, int tail, int nSize, int (*cmp)(const void*, const void*)) {
    if (base == NULL || head >= tail) {
        return;
    }
    
    int pivot = (head + tail) / 2;
    this->mergeSort(base, head, pivot, nSize, cmp);
    this->mergeSort(base, pivot + 1, tail, nSize, cmp);
    
    this->merge(base, head, pivot, tail, nSize, cmp);
}

void MergeSort::merge(void* base, int head, int pivot, int tail, int nSize, int (*cmp)(const void*, const void*)) {
    int i = head, j = pivot + 1;
    int k = 0;
    
    int sortingItemNum = tail - head + 1;
    
    void* temp = ::operator new(sortingItemNum * nSize);
    
    while ((i <= pivot) && (j <= tail)) {
        if (cmp((char*)base+ i*nSize, (char*)base+(j*nSize)) > 0) {
            memcpy((char*)temp+ k*nSize, (char*)base+ j*nSize, nSize);
            j++;
        } else {
            memcpy((char*)temp+ k*nSize, (char*)base+ i*nSize, nSize);
            i++;
        }
        k++;
    }
    
    if (i > pivot) {
        for (;j <= tail; j ++) {
            memcpy((char*)temp+ k*nSize, (char*)base+ j*nSize, nSize);
            k++;
        }
    }
    
    if (j > tail) {
        for (; i <= pivot; i++) {
            memcpy((char*)temp+ k*nSize, (char*)base+ i*nSize, nSize);
            k++;
        }
    }
    
    int p = 0;
    
    for (int q= head; q <= tail; q++) {
        memcpy(((char*)base)+ q*nSize, ((char*)temp)+ p*nSize, nSize);
        p++;
    }
    
    ::operator delete(temp);
}
