//
//  HeapSort.cpp
//  SortAlgorithm
//
//  Created by Tung Nguyen on 11/10/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#include "HeapSort.hpp"

HeapSort::HeapSort() {
    
}

void HeapSort::sort(void *base, int nElement, int nSize, int (*cmp)(const void *, const void *)) {
    this->buildHeap(base, nElement, nSize, cmp);
    for (int i = nElement - 1; i > 0; i --) {
        this->swap((char*)base, (char*)base + i*nSize, nSize);
        heapify(base, 0, i, nSize, cmp);
    }
}

void HeapSort::buildHeap(void *base, int nElement, int nSize, int (*cmp)(const void *, const void *)) {
    for (int i = nElement/2; i >= 0; i --) {
        heapify(base, i, nElement, nSize, cmp);
    }
}

void HeapSort::heapify(void *base, int rootIndex, int nElement, int nSize, int (*cmp)(const void *, const void *)) {
    int tempRootIdx = rootIndex;
    int leftNodeIdx = rootIndex * 2 + 1;
    int rightNodeIdx = rootIndex * 2 + 2;
    
    if (leftNodeIdx < nElement &&
        cmp((char*)base + tempRootIdx * nSize, (char*)base + leftNodeIdx * nSize) < 0)
            tempRootIdx = leftNodeIdx;
    
    if (rightNodeIdx < nElement &&
        cmp((char*)base + tempRootIdx * nSize, (char*)base + rightNodeIdx * nSize) < 0)
            tempRootIdx = rightNodeIdx;
    
    if (tempRootIdx != rootIndex) {
        this->swap((char*)base+ rootIndex*nSize, (char*)base + tempRootIdx* nSize, nSize);
        heapify(base, tempRootIdx, nElement, nSize, cmp);
    }
}
