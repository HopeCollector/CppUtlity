#include <string>
#include <iostream>
#include <vector>

std::vector<int> genPMT(std::string& s) {
    if(s.size() < 2) return std::vector<int>(s.size());
    std::vector<int> pmt(s.size());

    for(size_t i = 1, j = 0; i < s.size(); i++) {
        while(j && s[j] != s[i]) j = pmt[j-1];
        if(s[j] == s[i]) j++;
        pmt[i] = j;
    }

    return std::move(pmt);
}

int KMP(std::string& target, std::string str) {
    if(target.empty()) return 0;
    if(str.empty()) return -1;

    std::vector<int> pmt = genPMT(target);
    
    for (size_t i = 0, j = 0; i < str.size(); i++) {
        while (j && str[i] != target[j]) 
            j = pmt[j-1];

        if(target[j] == str[i]) j++;
        if(j == target.size())
            return i-j+1;
    }
    
    return -1;
}

int main() {

    std::string target = "aabaaac";
    std::string str = "aabaaabaaac";

    std::cout << KMP(target, str) << std::endl;

    return 0;
}