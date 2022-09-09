#include <iostream>
#include <regex>
using namespace std;

string reverse(string str){
    if(str.length() <= 1) return str;
    return reverse(str.substr(1)) + str[0];
}

bool isPalindrome(string str){
    if(str.length() <= 1) return true;
    if(str[0] != str[str.length() - 1]) return false;
    return isPalindrome(str.substr(1, str.length() - 2));
}

string modify(string str, int n){
    regex r("\\s+");
    str = regex_replace(str, r, "");
    for(int i = 0; i < n; i++) str[i] = tolower(str[i]);
    return str;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    getline(cin, str);
    int n = str.length();
    string edit = modify(str, n);
    cout << reverse(str) << endl;
    if(isPalindrome(edit)) cout << "true";
    else cout << "false";    
    return 0;
}