#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string input;
    stack<char> s;
    cin >> input;
    int ans = 0;
    int temp = 1;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            s.push('(');
            temp *= 2;
        }
        else if (input[i] == '[') {
            s.push('[');
            temp *= 3;
        }
        else if (input[i] == ')') {
            if (s.empty() || s.top() != '(') {
                ans = 0;
                break;
            }
            if (input[i - 1] != ')' && input[i - 1] != ']') ans += temp;
            s.pop();
            temp /= 2;
        }
        else if (input[i] == ']') {
            if (s.empty() || s.top() != '[') {
                ans = 0;
                break;
            }
            if (input[i - 1] != ')' && input[i - 1] != ']') ans += temp;
            s.pop();
            temp /= 3;
        }
    }
    if (!s.empty()) ans = 0;
    cout << ans;

    return 0;
}