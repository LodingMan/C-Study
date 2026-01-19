#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
// p = 탐색을 원하는 string
// m = p의 사이즈 
// pi 결과값
// i = 현재 탐색 기준
// j = 탐색 포인트  *어차피 0번인덱스는 0이니까 패스하는건가?
// i기준에서 j랑 다르면 pi를 뒤로 되돌림
// ABABABABC 기준 a와 b를 비교 후 다르니 패스ABABABABBABABABABCAB j15 i 17
//  i = 2 j = 0 
// 또 값이 다름 (a와 c)
// 넘어감
// i = 3 j = 0 
// 값이 같음 a와 a
// j상승 후 pi[i]에 저장 pi[3] = 1
// i = 4 j = 1  b와 b
// 값이 같고 j가 0이 아님
// 두 값이 같으니 j 상승 후 pi[i]에 j저장 pi[4] = 2

vector<int> getPi(string p) {
    int m = (int)p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
// ans는 결과값
// pi 실패검사 결과리스트
// n = s의 사이즈 s = 전체 string
// m = p의 사이즈 p = 탐색을 원하는 string
// i = 전체 string의 현재 탐색 기준 
// j = 탐색 포인트 (0부터)
vector<int> kmp(string s, string 
    p) {
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ans;
}
int main() {
    string s, p;
    //getline(cin, s);
    //getline(cin, p);
    s.assign("ABABABABBBABABABCAB");
    p.assign("A");

    auto matched = kmp(s, p);
    printf("%d\n", (int)matched.size());
    for (auto i : matched)
        printf("%d ", i + 1);
    return 0;
}