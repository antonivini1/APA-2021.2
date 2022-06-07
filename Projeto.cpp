#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


int main(){
    string line;
    ifstream myfile ("input.txt");
    int n_line = 1;
    int n,m,p;
    vector<int> b;
    vector<vector<int>> t, c;
    int aux, i, j, printit;

    if(myfile.is_open()){
        while (myfile.good()){
            myfile >> n;
            myfile >> m;
            myfile >> p;
            
            for(i=0;i<m;i++){
                myfile >> aux;
                b.push_back(aux);
            }

            vector<int> tempVect;
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    myfile >> aux;
                    tempVect.push_back(aux);
                }
                t.push_back(tempVect);
                tempVect.clear();
            }

            tempVect.clear();
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    myfile >> aux;
                    tempVect.push_back(aux);
                }
                c.push_back(tempVect);
                tempVect.clear();
            }
        cout << n << " "  << m  << " "  << p  << endl;
        cout <<  "\n";
        for(auto& printit : b){
            cout <<  printit << " ";
        }
        cout <<  "\n\n";
        for(auto& printit : t){
            for(auto& elem : printit){
                cout << elem << " ";
            }
            cout << "\n";
        }
        cout <<  "\n";
        for(auto& printit : c){
            for(auto& elem : printit){
                cout << elem << " ";
            }
            cout << "\n";
        }
        myfile.close();
        }
    }
    else{
        cout << "Error";
    }

    return 0;
}