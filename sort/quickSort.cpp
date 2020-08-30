#include <vector>
#include <iostream>
#include <algorithm>

int split(std::vector<int>& v, int low, int high) {
    if(low > high) return low;
    auto target = low;
    while(low < high) {
        while(low < high && v[high] >= v[target]) high--;
        while(low < high && v[low] <= v[target]) low++;
        if(low < high) std::swap(v[low], v[high]);
        else std::swap(v[target], v[low]); //结束时 low 位置放的应该是比 target 目标小的关键字，直接交换就行了
    }
    return low;
}

void sort(std::vector<int>& list, int low, int high) {
    if(low < high) {
        int mid = split(list, low, high);

        for(auto num : list) {
            std::cout << num << " ";
        }
        std:: cout << std::endl;

        sort(list, low, mid-1);
        sort(list, mid+1, high);
    }
}

int main() {
    std::vector<int> v{25, 84, 21, 47, 15, 27, 68, 35, 20};
    sort(v, 0, v.size()-1);

    return 0;
}