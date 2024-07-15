#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<cmath>

#define vi vector<int> 

using namespace std;

bool checkValidPairs(string input){
    int n = input.length();
    
    stack<char> st; 
    
    bool check = true;
    
    for(int i = 0; i < n; i++){
        if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
            st.push(input[i]);
        }
        else if(input[i] == ')'){
            if(st.empty() || st.top() != '('){
                check = false;
                break;
            }
            st.pop();
        } 
        else if(input[i] == ']'){
            if(st.empty() || st.top() != '['){
                check = false;
                break;
            }
            st.pop();
        }
        else if(input[i] == '}'){
            if(st.empty() || st.top() != '{'){
                check = false;
                break;
            }
            st.pop();
        }
    }
    
    if(!st.empty()) check = false;
    
    return check;
}

int precedence(char c){
    if(c == '(') return 0;
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return -1;
}

queue<char> PrefixToPostfix(string input){
    
    stack<char> st;
    queue<char> qu;
    
    int n = input.length();
    
    for(int i = 0; i < n; i++){
        if(input[i] == '('){
            st.push(input[i]);
        }
        else if(input[i] >= '0' && input[i] <= '9'){
        // else if(input[i] >= 'a' && input[i] <= 'z'){
            qu.push(input[i]);
        }
        else if(input[i] == '+' || input[i] == '-' 
            || input[i] == '*' || input[i] == '/'
            || input[i] == '^'){
            while(!st.empty() && precedence(input[i]) <= precedence(st.top())){
                qu.push(st.top());
                st.pop();
            }
            st.push(input[i]); 
        }
        else if(input[i] == ')'){
            while(!st.empty() && st.top() != '('){
                qu.push(st.top());
                st.pop();
            }
            st.pop();
        }
    }
    
    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }
    
    return qu;
}

int calculate(queue<char> qu){
    int res = 0;
    
    stack<int> st;
    
    while(!qu.empty()){
        if(qu.front() >= '0' && qu.front() <= '9'){
            st.push(qu.front() - '0');
        }
        else{
            if(qu.front() == '+'){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int cal = b + a;
                st.push(cal);
            }
            else if(qu.front() == '-'){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int cal = b - a;
                st.push(cal);
            }
            else if(qu.front() == '*'){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int cal = b * a;
                st.push(cal);
            }
            else if(qu.front() == '/'){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int cal = b / a;
                st.push(cal);
            }
            else if(qu.front() == '^'){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int cal = pow(b, a);
                st.push(cal);
            }
        }
        qu.pop();
    }
    
    res = st.top();
    st.pop();
    
    return res;
}

int main(){
    
    string input; 
    cin >> input;
        
    queue<char> postfix = PrefixToPostfix(input);
    int cal = calculate(postfix);
    
    cout << cal << endl;
    
    
    return 0;
}