//
//  QuickSort.cpp
//  SortAlgorithm
//
//  Created by Tung Nguyen on 11/8/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#include "QuickSort.hpp"
QuickSort::QuickSort() {
    
}

void QuickSort::sort(void* base, int nElement, int nSize, int (*cmp)(const void*, const void*)) {
    this->quickSort(base, 0, nElement - 1, nSize, cmp);
}

void QuickSort::quickSort(void* base, int head, int tail, int nSize, int (*cmp)(const void*, const void*)) {
    if (head >= tail || base == NULL) return;
    
    int partionatedPos = this->partition(base, head, tail, nSize, cmp);
    quickSort(base, head, partionatedPos - 1, nSize, cmp);
    quickSort(base, partionatedPos + 1, tail, nSize, cmp);
}

int QuickSort::partition(void* base, int head, int tail, int nSize, int (*cmp)(const void*, const void*)) {
    int pivot = tail;
    int i = head, j = tail -1;
    
    while (true) {
        while (cmp((char*)base+ i*nSize, (char*)base + pivot* nSize) < 0) i++;
        while (cmp((char*)base+ j*nSize, (char*)base + pivot* nSize) > 0) j--;
        
        if (i < j) {
            this->swap((char*)base+ i*nSize, (char*)base + j*nSize, nSize);
            i++;
            j--;
        } else {
            this->swap((char*)base+ pivot*nSize, (char*)base + i*nSize, nSize);
            break;
        }
    }
    
    return i;
}
