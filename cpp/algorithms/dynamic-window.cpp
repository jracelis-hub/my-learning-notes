#include <iostream>
#include <vector>

int minSize(std::vector<int>& n_array, int sum) {
    int first = 0;
    int end = 0;

    int min_length = 0;

    int current_sum = 0;
    for (end; end < n_array.size(); end++) {
        current_sum += n_array[end];
        while (current_sum >= sum) {
            current_sum -= n_array[first++];
        }
        min_length = end - first + 1;
    }
    return min_length;
}

int main()
{
    std::vector<int> values = {1, 7, 4, 1, 2};

    int min_size = minSize(values, 7);
    std::cout << min_size << std::endl;

    return 0;
}