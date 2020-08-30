// 马拉车算法
/*
一种强化了记忆性的回文串搜索算法

所谓记忆强化，是因为其利用回文串两端字符相同的特点，减少了遍历过程中重复搜索的次数
    一个回文串的左半部分与右半部分相同，那么在搜索其右半部分的回文串时完全可以使用
    左半部分已经取得的关于字符串信息

除此之外，马拉车算法还在字符串各个字符中间插入了 #，将奇数回文串、偶数回文串的处理
流程统一起来，方便用一套代码处理
*/
#include <string>
#include <iostream>
#include <vector>

// 返回加了 ^#& 之后每个字符的回文半径
// 自己跟自己回文的半径定义为 0
std::vector<size_t> manacher(const std::string &s) {
    if(s.empty()) return {};

    // ^xxxxx$ 这种类型的字符串可以省略边界检查， 因为碰到边界时绝对不会遇到相同字符
    std::string str("^#");
    for(auto c : s) {
        str += c;
        str += '#';
    }
    str += '$';

    std::vector<size_t> radis(str.size());
    int maxIdx = 0;
    for(size_t i = 0; i < str.size(); i++) {
        // 如果之前查找过最长的回文串，其半径达到的最远范围仍不包含当前位置，那么就把当前位置的半径设置为 0
        if(maxIdx+radis[maxIdx] <= i) radis[i] = 0;
        // 如果当前位置恰好在最远范围之内，那么在最远范围之前的所有字符都不用再考虑，只要把其以 maxIdx 为中心的
        // 对称位置上的半径拿过来直接用就行，注意不要超过最远范围，在那之外的字符都是没检查过的
        else radis[i] = std::min(radis[2*maxIdx - i], maxIdx+radis[maxIdx] - i);

        // 中心扩散
        while(str[i+radis[i]] == str[i-radis[i]]) radis[i]++;
        radis[i]--;
        
        // 更新 maxIdx 保证其对应的回文串能触及 str 中最远的范围
        if(radis[maxIdx] + maxIdx < radis[i] + i) maxIdx = i;
    }

    return std::move(radis);
}

int main() {

    std::string s  = "aba";
    for(auto num : manacher(s))
        std::cout << num << " ";

    return 0;
}