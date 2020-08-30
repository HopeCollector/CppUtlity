#include <string>
#include <vector>

using namespace std;

// 只能算正整数乘法，负数需要加一层判断
// 小数需要额外计算在哪里添加小数点
// 输入字符串不能为空
string multiply(string num1, string num2) {
    vector<int> buf(num1.size() + num2.size(), 0);

    for(int i = num1.size()-1; i >= 0; i--) {
        for(int j = num2.size()-1; j >= 0; j--) {
            int tmp = (num1[i]-'0') * (num2[j]-'0');
            buf[i+j+1] += tmp;
        }
    }

    for(auto i = buf.rbegin(); i+1 != buf.rend(); i++) {
        if(*i > 9) {
            *(i+1) += *i / 10;
            *i %= 10;
        }
    }

    string ret;
    auto i = buf.begin();

    while(i != buf.end() && *i == 0) i++;
    for(; i != buf.end(); i++) {
        ret += static_cast<char>(*i+'0');
    }
    
    return ret.empty() ? "0" : ret;
}