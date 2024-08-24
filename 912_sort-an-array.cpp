#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void merge(std::vector<int>& array, int const left, int const mid, int const right) {
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;

        std::vector<int> leftArray(subArrayOne), rightArray(subArrayTwo);

        for (int i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (int j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];

        int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    void mergeSort(std::vector<int>& array, int const begin, int const end) {
        if (begin >= end)
            return;

        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {34, 7, 23, 32, 5, 62};

    std::vector<int> sortedNums = solution.sortArray(nums);

    std::cout << "Sorted array: ";
    for (int num : sortedNums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
