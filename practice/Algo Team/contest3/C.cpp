#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    // int time; cin >> time;
    // while(time--){
        int n;
        cin >> n;
        map<string, int> m;

        for(int i = 0; i < n; i++){
            string name;
            cin >> name;

            if(m.find(name) == m.end()){
                m[name] = 1;
                cout << "OK" << endl;
            } else {
                int count = m[name];
                string newName = name + to_string(count);
                
                while(m.find(newName) != m.end()){
                    newName = name + to_string(count);
                    count++;
                }
                
                m[name] = count;
                m[newName] = 1;
                cout << newName << endl;
            }
        }
        
    // }
    return 0;
}
