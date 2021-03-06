﻿#include "selectSort.h"

void SelectSort(std::vector<Account>& a, int* ind)
{
    int size = a.size();
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (a.at(ind[j]).username < a.at(ind[min]).username) {
                min = j;
            }
        }
        int temp = ind[i];
        ind[i] = ind[min];
        ind[min] = temp;
    }
}
