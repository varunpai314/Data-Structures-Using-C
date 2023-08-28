# Data-Structures-Using-C
 
# C Data Structures Repository

Welcome to my C Data Structures repository! This repository contains various implementations of data structures in the C programming language.

## Table of Contents

- [Array](#array)
- [Linked List](#linked-list)
- [Stack](#stack)
- [Queue](#queue)

## Array

An array is a collection of elements, each identified by an index or a key.

```c
#include <stdio.h>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    
    return 0;
}
