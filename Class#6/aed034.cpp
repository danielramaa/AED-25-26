#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct Opening {
    char type;
    int position;
};

struct Match {
    char opening;
    char closing;
    int openPos;
    int closePos;
};

bool isOpening(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isClosing(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool matches(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main() {
    string expression;
    getline(cin, expression);
    
    stack<Opening> st;
    vector<Match> matches_list;
    bool badly_matched = false;
    bool has_brackets = false;
    
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        if (isOpening(c)) {
            has_brackets = true;
            st.push({c, i});
        } else if (isClosing(c)) {
            has_brackets = true;
            
            if (st.empty()) {
                badly_matched = true;
                break;
            }
            
            Opening top = st.top();
            st.pop();
            
            if (!matches(top.type, c)) {
                badly_matched = true;
                break;
            }
            
            matches_list.push_back({top.type, c, top.position, i});
        }
    }
    
    if (!st.empty()) {
        badly_matched = true;
    }
    
    if (!has_brackets) {
        cout << "no brides and grooms to marry" << endl;
    } else if (badly_matched) {
        cout << "badly matched pairs" << endl;
    } else {
        for (const auto& match : matches_list) {
            cout << match.opening << match.closing << " " 
                 << match.openPos << " " << match.closePos << endl;
        }
    }
    
    return 0;
}