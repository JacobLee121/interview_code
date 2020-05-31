//
//  stringLastWord.cpp
//  string_stuf
//
//  Created by 李鑫强 on 2020/5/31星期日.
//  Copyright © 2020年 lixinqiang. All rights reserved.
//

#include "stringLastWord.hpp"
#include <string>
#include <sstream>
using namespace std;

class LengthOfLastWord {
public:
    int lengthOfLastWord(string s) {
        string ret;
        printf("s.size is%d\n", s.size());
        while(s.back() == ' ') {
            s.pop_back();
        }
        if(s.size() == 0) {
            return 0;
        }
        if(s.find(" ") == string::npos) {
            return static_cast<int>(s.size()) ;
        }
        auto it = s.rfind(" ");
        string sub = s.substr(it+1);
        return static_cast<int>(sub.size());
    }
    int lenthOfLastwordStream(string s)
    {
        int ret;
        stringstream ss(s);
        string tmp;
        while (ss>>tmp) {
            printf("tmp is %s\n",tmp.c_str());
        }
        ret = tmp.size();
        return ret;
    }
        
};

int main()
{
    LengthOfLastWord lw;
    int ret = lw.lengthOfLastWord("  ");
    ret = lw.lenthOfLastwordStream("hello world   ,, ");
    printf("ret :%d\n",ret);
    return 0;
}
