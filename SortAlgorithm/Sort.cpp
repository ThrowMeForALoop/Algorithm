//
//  Sort.cpp
//  SortAlgorithm
//
//  Created by Tung Nguyen on 11/8/16.
//  Copyright © 2016 Tung Nguyen. All rights reserved.
//

#include "Sort.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sort::swap(void *a, void *b, int nSize) {
    void* temp = ::operator new (nSize);
    memcpy(temp, a, nSize);
    memcpy(a, b, nSize);
    memcpy(b, temp, nSize);
    
    ::operator delete(temp);
}
