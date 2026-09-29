#ifndef COURSE_SORTS_H
#define COURSE_SORTS_H
#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

namespace course {
    using namespace std;

    // Bubble sort: move the largest remaining value to the end on each pass.
    inline void bubbleSort(vector<int>& data) {
        for (size_t limit = data.size(); limit > 1; --limit) {
            bool changed = false;
            for (size_t i = 1; i < limit; ++i) {
                if (data[i - 1] > data[i]) {
                    swap(data[i - 1], data[i]);
                    changed = true;
                }
            }
            if (!changed) {
                break;
            }
        }
    }
    // Selection sort: put the smallest remaining value in the next position.
    inline void selectionSort(vector<int>& data) {
        for (size_t i = 0; i < data.size(); ++i) {
            size_t smallest = i;
            for (size_t j = i + 1; j < data.size(); ++j) {
                if (data[j] < data[smallest]) {
                    smallest = j;
                }
            }
            swap(data[i], data[smallest]);
        }
    }
    // Insertion sort: shift larger values to make room for the current card.
    inline void insertionSort(vector<int>& data) {
        for (size_t i = 1; i < data.size(); ++i) {
            int current = data[i];
            size_t j = i;
            while (j > 0 && data[j - 1] > current) {
                data[j] = data[j - 1];
                --j;
            }
            data[j] = current;
        }
    }

    // Merge sort: all ranges are [startIndex, endIndex), excluding endIndex.
    inline void mergeRange(vector<int>& data, vector<int>& buffer, size_t startIndex,
                           size_t endIndex) {
        if (endIndex - startIndex < 2) {
            return;
        }
        size_t middle = startIndex + (endIndex - startIndex) / 2;
        mergeRange(data, buffer, startIndex, middle);
        mergeRange(data, buffer, middle, endIndex);
        size_t leftIndex = startIndex, rightIndex = middle, destination = startIndex;
        while (leftIndex < middle && rightIndex < endIndex) {
            if (data[leftIndex] <= data[rightIndex]) {
                buffer[destination++] = data[leftIndex++];
            } else {
                buffer[destination++] = data[rightIndex++];
            }
        }
        while (leftIndex < middle) {
            buffer[destination++] = data[leftIndex++];
        }
        while (rightIndex < endIndex) {
            buffer[destination++] = data[rightIndex++];
        }
        for (size_t i = startIndex; i < endIndex; ++i) {
            data[i] = buffer[i];
        }
    }
    inline void mergeSort(vector<int>& data) {
        vector<int> buffer(data.size());
        mergeRange(data, buffer, 0, data.size());
    }

    // Quick sort: separate values smaller than the pivot from the rest.
    inline void partitionRange(vector<int>& data, size_t startIndex, size_t endIndex) {
        if (endIndex - startIndex < 2) {
            return;
        }
        int pivot = data[endIndex - 1];
        size_t split = startIndex;
        for (size_t i = startIndex; i < endIndex - 1; ++i) {
            if (data[i] < pivot) {
                swap(data[i], data[split]);
                ++split;
            }
        }
        swap(data[split], data[endIndex - 1]);
        partitionRange(data, startIndex, split);
        partitionRange(data, split + 1, endIndex);
    }
    inline void quickSort(vector<int>& data) {
        // ponytail: last-element pivot, O(n^2) worst case; use sort in applications.
        partitionRange(data, 0, data.size());
    }
} // namespace course

#endif
