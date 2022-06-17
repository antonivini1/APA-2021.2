#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> t, c;
vector<int> b;
int n,m,p;


string verify(string input);
void Busca_Local_VND(vector<vector<int>> &sol_m, vector<int> &sol, vector<int> &capacidade, int custo_total, int r);
void Best_Fit(vector<vector<int>> &sol_m, vector<int> &sol, vector<int> &capacidade_atual);


int main(){
    string input;
    cout << "Arquivo: ";
    cin >> input;
    input = verify(input);

    ifstream myfile (input);
    vector<int> tempVect;
    int temp, i, j;

    /* --------------------------------------------------------- */
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

    /* --------------------------------------------------------- */
    vector<vector<int>> sol_m(m, vector<int>(n,0));
    vector<int> capacidade_atual(m,0), sol;
    i = 0, j = 0;

    while(j < n){
        for(int s=0;s<c.size();s++){
            tempVect.push_back(c[s][j]);
        }

        i = min_element(tempVect.begin(), tempVect.end()) - tempVect.begin();

        if(capacidade_atual[i] + t[i][j] <= b[i]){
            capacidade_atual[i] += t[i][j];
            sol_m[i][j] = 1;
            sol.push_back(i);
        }
        else{
            sol.push_back(-1);
        }
        j++;
        tempVect.clear();
    }
    /* --------------------------------------------------------- */

    /* --------------------------------------------------------- */
    int custo_total = 0;
    for(j=0;j<n;j++){
        i = sol[j];
        if(i != -1){
            custo_total += c[i][j];
        }
        else{
            custo_total += p;
        }
        
    }
    cout << "Custo total: " << custo_total << endl;

    for(auto& i : sol_m){
        cout << "| ";
        for(auto& j : i)
            cout << j << " | ";
        cout << endl;
    }
    cout << endl;

    return 0;
}


string verify(string input){
    string end = ".txt";
    
    if((input.length() >= end.length()) && (input.compare(input.length()-end.length(), end.length(), end)))
        return input+end;
    else
        return input;
}