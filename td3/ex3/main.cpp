#include <iostream>
#include <queue>
#include <stack>
#include <cctype> 
using namespace std;
bool isPalindrome(const string& input) {
    queue<char> q;
    stack<char> s;
    for (char c : input) {
        if (isalnum(c)) { 
            char lowercaseChar = tolower(c); 
            q.push(lowercaseChar);
            s.push(lowercaseChar);
        }
    }
    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false; 
        }
        q.pop();
        s.pop();
    }
    return true; 
}

int main() {
    cout << boolalpha; 
    cout << "Is 'racecar' a palindrome? " << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? " << isPalindrome("hello") << endl;
    cout << "Is 'A man, a plan, a canal, Panama' a palindrome? " << isPalindrome("A man, a plan, a canal, Panama") << endl;
    return 0;
}

