#include <iostream>
#include <stack>
#include <string>
using namespace std;
string add_num(string first, string second) {
    if (second.length() > first.length()) {
        string temp;
        temp = second;
        second = first;
        first = temp;
    }
    stack<int> stack1;
    stack<int> stack2;
    stack<int> ans_stack;
    for (int i = 0; i < first.length(); i++) stack1.push(first[i] - 48);
    for (int i = 0; i < second.length(); i++) stack2.push(second[i] - 48);
    
    while (!stack2.empty()) {
        if (stack1.top() + stack2.top() >= 10) {
            ans_stack.push((stack1.top() + stack2.top() - 10));
            stack1.pop();
            stack2.pop();
            if (!stack1.empty()) {
                int temp = stack1.top();
                temp++;
                stack1.pop();
                stack1.push(temp);
            }
            else {
                int temp = 1;
                stack1.push(temp);
            }
        }
        else {
            ans_stack.push((stack1.top() + stack2.top()));
            stack1.pop();
            stack2.pop();
        }
    }
    while (!stack1.empty()) {
        ans_stack.push(stack1.top());
        stack1.pop();
    }
    string answer;
    while(!ans_stack.empty()) {
        answer.push_back(ans_stack.top() + 48);
        ans_stack.pop();
    }
    return answer;
}
int main() {
    string first_num;
    string second_num;
    string dp[10001];
    dp[0] = '0';
    dp[1] = '1';
    dp[2] = '1';
    int n = 0;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        dp[i] = add_num(dp[i - 1], dp[i - 2]);
    }
    cout << dp[n];
    return 0;
}