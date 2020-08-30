#include <iostream>
#include <vector>

// T (totalTestNum)
//  (testDatas[0])
//    N
//    0, 1, 2...
//  (testDatas[1])
//    N
//    0, 1, 2...
//    ...
//  (testDatas[T-1])
//    ...
std::vector<std::vector<int>> getInput() {
    int totalTestNum = 0;
    std::cin >> totalTestNum;
    std::vector<std::vector<int>> testDatas(totalTestNum);

    for(int i = 0; i < totalTestNum; i++) {
        int objectNum, tmp;
        std::cin >> objectNum;
        for(int j = 0; j < objectNum; j++) {
            std::cin >> tmp;
            testDatas[i].push_back(tmp);
        }
    }

    return std::move(testDatas);
}