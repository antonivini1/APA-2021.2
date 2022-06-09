#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

string verify(string input);
int index(vector<int> vec, int server);

int main(){
    // string input;
    // cout << "Arquivo: ";
    // cin >> input;
    // input = verify(input);

    ifstream myfile ("input.txt");
    int n,m,p;
    vector<int> b, tempVect;
    vector<vector<int>> t, c;
    int temp, i, j;

    if(myfile.is_open()){
        while (myfile.good()){
            myfile >> n;
            myfile >> m;
            myfile >> p;
            
            for(i=0;i<m;i++){
                myfile >> temp;
                b.push_back(temp);
            }

            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    myfile >> temp;
                    tempVect.push_back(temp);
                }
                t.push_back(tempVect);
                tempVect.clear();
            }

            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    myfile >> temp;
                    tempVect.push_back(temp);
                }
                c.push_back(tempVect);
                tempVect.clear();
            }
        myfile.close();
        }
    }
    else{
        cout << "Error" << endl;
    }


    vector<vector<int>> jobs_list_server(m, vector<int>(n,0));
    vector<int> capacidade_atual(m,0);
    i = 0, j = 0;
    int min_c;

    while(j < n){
        for(int s=0;s<c.size();s++){
            tempVect.push_back(c[s][j]);
        }

        min_c = *min_element(tempVect.begin(), tempVect.end());
        i = index(tempVect, min_c);

        if(capacidade_atual[i] + t[i][j] <= b[i]){
            capacidade_atual[i] += t[i][j];
            jobs_list_server[i][j] = 1;
        }
        j++;
        tempVect.clear();
    }

    int custo_total = 0;
    for(j=0;j<n;j++){
        for(i=0;i<m;i++){
            if(jobs_list_server[i][j] == 1){
                custo_total += c[i][j];
                break;
            }
            if(i == m-1){
                custo_total += p;
            }
        }
    }
    cout << "Custo total: " << custo_total << endl;

    return 0;
}


string verify(string input){
    string end = ".txt";
    
    if((input.length() >= end.length()) && (input.compare(input.length()-end.length(), end.length(), end)))
        return input+end;
    else
        return input;
}
int index(vector<int> vec, int server){
    auto it = find(vec.begin(), vec.end(), server);
    return (it - vec.begin());
}