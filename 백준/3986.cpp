#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    int n = 0;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {    
        stack<char> s;
        string word;
        cin >> word;
        for (int j = 0; j < word.length(); j++) {        
            if (s.empty()) s.push(word[j]);
            else if (s.top() == word[j]) s.pop();
            else if (s.top() != word[j]) s.push(word[j]);
        }
        if (s.empty()) ans++;
    }

    cout << ans;
}