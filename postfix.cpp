#include<iostream>
#include<string>
#include<stack>
#include<queue> 
#include<cmath>

using namespace std;

int precedence(char x){
    if(x == '(') return 0;
    else if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
    else if(x == '^') return 3;
    else return 4;
}

bool checkValidBrackets(string w){
    stack<char> s;

    for(int i = 0; i < w.length(); i++){
        if(w[i] == '('){
            s.push(w[i]);
        }
        else if(w[i] == ')'){
            if(s.empty()){
                return false;
            }
            s.pop();
        }
    }

    bool check;
    s.empty() ? check = true : check = false;

    return check;
}

// bool checkValidExpression(string w){
//     stack<char> s;
//     for(int i = 0; i < w.length(); i++){
//         if(w[i] >= '1' && w[i] <= '9'){
//             s.push(w[i]);
//         }
//         else if(w[i] == '+' || w[i] == '-' || w[i] == '*' || w[i] == '/' || w[i] == '^'){
//             if(s.empty()){
//                 return false;
//             }
//             s.pop();
//         }
//     }

//     bool check;
//     s.empty() ? check = true : check = false;

//     return check;
// }

string infixToPostfix(string w){
    stack<char> s;
    queue<char> q; 

    for(int i = 0; i < w.length(); i++){
        if(w[i] == '('){
            s.push(w[i]);
        }
        else if(w[i] >= '1' && w[i] <= '9'){
            q.push(w[i]);
        }
        else if(w[i] == '+' || w[i] == '-' || w[i] == '*' || w[i] == '/' || w[i] == '^'){
            while(!s.empty() && precedence(s.top()) >= precedence(w[i])){
                q.push(s.top());
                s.pop();
            }
            s.push(w[i]);
        }
        else if(w[i] == ')'){
            while(!s.empty() && s.top() != '('){
                q.push(s.top());
                s.pop();
            }
            s.pop();
        }
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    string save = "";

    while(!q.empty()){
        save += q.front();
        q.pop();
    }

    return save;
}

int calculate(string postfix){
    stack<int> s;

    for(int i = 0; i < postfix.length(); i++){
        if(postfix[i] >= '1' && postfix[i] <= '9'){
            s.push(postfix[i] - '0');
        }
        else if(postfix[i] == '+'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a + b);
        }
        else if(postfix[i] == '-'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b - a);
        }
        else if(postfix[i] == '*'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a * b);
        }
        else if(postfix[i] == '/'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b / a);
        }
        else if(postfix[i] == '^'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(pow(b, a));
        }
    }

    int res = s.top();
    s.pop();
    return res;
}

int main(){

    string w; cin >> w;
    
    if(!checkValidBrackets(w)){
        cout << "Invalid Bracket";
        return 0;
    }

    // if(!checkValidExpression(w)){
    //     cout << "Invalid Expression";
    //     return 0;
    // }

    string postfix = infixToPostfix(w);
    
    cout << calculate(postfix);

    return 0;
}