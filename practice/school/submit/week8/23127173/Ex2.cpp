#include<iostream>
#include<fstream>
#include<vector>
#include<string> 
#include<cstring>

using namespace std;

struct Phone{
    string monster_name;
    long long number;      
};

vector<Phone> HASHTABLE;
int CURRENT_MAX_SIZE = 10;
const int MAXSIZEHASH = 400;

long long hashCode(string number){
    long long res = 0;
    int n = number.length();
    for(int i = 0; i < n; i++){
        res = res * 10 + number[i];
    }
    return res;
}

void h(string line, int &cnt){
    Phone newPhone;

    int spaceIndex = line.rfind(" ");
    // cout << "space index: " << spaceIndex << "\n";

    string tmp;

    newPhone.monster_name = line.substr(0, spaceIndex);
    tmp = line.substr(spaceIndex + 1, line.length() - spaceIndex - 1);
    newPhone.number = hashCode(tmp);

    HASHTABLE.push_back(newPhone);

    cnt++;

    if(cnt == CURRENT_MAX_SIZE){
        cout << "START TO CREATE A NEW HASH TABLE \n";
        vector<Phone> newHashTable (cnt);
        for(int i = 0; i < CURRENT_MAX_SIZE; i++)
            newHashTable[i] = HASHTABLE[i];
        HASHTABLE.clear();
        HASHTABLE = newHashTable;
        CURRENT_MAX_SIZE++;
    }
}

void readFile(){
    fstream fin;
    fin.open("phonebook.txt", ios::in);

    int cnt = 0;

    while(!fin.eof()){
        string line;
        getline(fin, line);
        // cout << "line " << cnt << ": " << line << "\n";

        h(line, cnt);
    }

    fin.close();
}

void printHash(){
    for(auto i : HASHTABLE){
        cout << i.monster_name << " " << i.number << endl; 
    }
    cout << endl;
}

void ADD(string monster_name, int p){
    // cout << "START TO CREATE A NEW HASH TABLE \n";
    // vector<Phone> newHashTable (CURRENT_MAX_SIZE + 1);
    // for(int i = 0; i < CURRENT_MAX_SIZE; i++)
    //     newHashTable[i] = HASHTABLE[i];
    // HASHTABLE.clear();
    // HASHTABLE = newHashTable;

    // HASHTABLE[CURRENT_MAX_SIZE + 1] = {monster_name, p};

    // CURRENT_MAX_SIZE++;
    HASHTABLE.push_back({monster_name, p});
}

void DELETE(string monster_name){
    // do not need to reduce the size 

    for(int i = 0; i < HASHTABLE.size(); i++){
        if(HASHTABLE[i].monster_name == monster_name){
            HASHTABLE[i].monster_name = "DELETED";
            HASHTABLE[i].number = 0;
        }
    }
}

void UPDATES(string monster_name, int p){
    for(int i = 0; i < HASHTABLE.size(); i++){
        if(HASHTABLE[i].monster_name == monster_name){
            HASHTABLE[i].monster_name = monster_name;
            HASHTABLE[i].number = p;
        }
    }
}

long long FIND(string monster_name){
    for(int i = 0; i < HASHTABLE.size(); i++){
        if(HASHTABLE[i].monster_name == monster_name){
            return HASHTABLE[i].number;
        }
    }

    return -1;
}

int main(){

    readFile();
    // printHash();

    ADD("100", 100);
    ADD("200", 200);
    DELETE("Clyde Thornton");
    UPDATES("100", 101);
    long long res = FIND("200"); cout << res << endl;

    printHash();

    return 0;
}