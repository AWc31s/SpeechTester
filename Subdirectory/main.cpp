#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <sstream>

#include <windows.h>
#include <tchar.h>

using namespace std;

int main(int argc, char* argv[])
{ 
    string language;

    cout << "Language: ";
    cin >> language;
    cout << "\n";
    
    string lang = language.substr(0,2);

    fstream fin;
    fin.open("..\\"+language+".ini", ios::in);
    
    getc(stdin);

    string line;
    string filename;

    while(getline(fin, line)){
        int breakpoint = line.find_first_of("=");
        string floornum = line.substr(0,breakpoint);
        string files = line.substr(breakpoint+1);

        stringstream unsplit(files);
        string segment;
        
        cout << "Floor: " << floornum << "\n";
        while(getline(unsplit, segment, ','))
        {
            filename = "..\\"+lang+"_"+segment+".wav";

            cout << "Currently Playing: "<< segment;
            PlaySoundA(filename.c_str(), NULL, SND_FILENAME | SND_ASYNC);
            
            getc(stdin);
        }
        cout << "\n";

    }
    fin.close();

    return 0;
}
