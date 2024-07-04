#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

typedef long long ll;

struct Song{
    string track;
    string artist;
    ll spotify_streams;
    int explicit_track;
};

void readFile(Song songs[], int &nSong){
    fstream fin;
    fin.open("MostStreamedSpotifySongs2024.txt", ios::in);

    if(!fin){
        cerr << "Error opening file" << endl;
        exit(1);
    }

    //read first line
    string line = "";
    getline(fin, line);
    cin.ignore();

    nSong = 0;
    while(!fin.eof()){

        char quote;
        fin >> quote;

        getline(fin, songs[nSong].track, '"');

        char comma;
        fin >> comma;
        fin >> quote;

        getline(fin, songs[nSong].artist, '"');
        fin >> comma;

        fin >> songs[nSong].spotify_streams;

        fin >> comma;

        fin >> songs[nSong].explicit_track;

        nSong++;
    }

    fin.close();
}

void writeFile(Song songs[], int nSong){
    fstream fout;
    fout.open("out.txt", ios::out);

    if(!fout){
        cerr << "Error opening file" << endl;
        exit(1);
    }

    for(int i = 0; i < nSong; i++){
        if(songs[i].explicit_track == 0){
            fout << songs[i].track << " " << songs[i].artist << " " << songs[i].spotify_streams << endl;
        }
    }

    fout.close();
}

void quickSortSong(Song songs[], int left, int right){
    int i = left, j = right;
    Song pivot = songs[(left + right) / 2];

    while(i <= j){
        while(songs[i].spotify_streams > pivot.spotify_streams) i++;
        while(songs[j].spotify_streams < pivot.spotify_streams) j--;

        if(i <= j){
            swap(songs[i], songs[j]);
            i++;
            j--;
        }
    }

    if(left < j) quickSortSong(songs, left, j);
    if(i < right) quickSortSong(songs, i, right);
}

void top5songbystreams(Song songs[], int nSong){
    for(int i = 0; i < 5; i++){
        cout << songs[i].track << " " << songs[i].artist << " " << songs[i].spotify_streams << endl;
    }
}

int main(){
    Song songs[1000];
    int nSong;
    readFile(songs, nSong);
    writeFile(songs, nSong);

    quickSortSong(songs, 0, nSong - 1);
    top5songbystreams(songs, nSong);

    map<string, int> mp;
    for(int i = 0; i < nSong; i++){
        mp[songs[i].artist]++;
    }

    //find pair max int in mp
    pair <string, int> max = {"", 0};
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second > max.second){
            max = *it;
        }
    }

    cout << max.first << " " << max.second << endl;

    return 0;
}