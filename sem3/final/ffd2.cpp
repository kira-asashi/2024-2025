#include <iostream>
#include <chrono>
using namespace std;

void ffd(int weight[], int n, int c){
    int res = 0; //num of trucks currently used
    int truck_rem[5]; //remaining space for each truck
    for (int i = 0; i < n; i++){ 
        int j;
        for (j = 0; j < res; j++){
            if (truck_rem[j]>=weight[i]){  //if it fits
                truck_rem[j] = truck_rem[j] - weight[i]; //update weigh
                break;
            }
        }
        if (j == res){
            if (res < 5){ // create new truck only if less than 5
                truck_rem[res] = c - weight[i];
                res++;
            }
            else{
                cout << "Item with weight " << weight[i] 
                     << " cannot be loaded (max 5 trucks reached)." << endl;
            }
        }
    }        
    cout << endl;
    cout << "Remaining capacity of each truck:" << endl;
    for(int i = 0; i < res; i++){//displays remaining capacity for each truck
        cout << "truck " << i+1 << " Remaining: " << truck_rem[i] << endl;
    }
    cout << "Number of trucks required: " << res;
}


int main(){
    int weight[7] = {40000,35000,25000,30000,20000,15000,20000}; 

    cout << endl;
    cout << "List of Values: " << endl;
    cout << "Organic: " << weight[0] << endl;
    cout << "Plastic: " << weight[1] << endl;
    cout << "Glass: " << weight[2] << endl;
    cout << "Electronic: " << weight[3] << endl;
    cout << "Mixed: " << weight[4] << endl;
    cout << "Metal: " << weight[5] << endl;
    cout << "Paper: " << weight[6] << endl;
    cout << endl;


    int c = 40000;
    int n = sizeof(weight)/sizeof(weight[0]);

    
    auto start = chrono::high_resolution_clock::now(); //time starts 
    ffd(weight,n,c); //function calls FFD
    auto end = chrono::high_resolution_clock::now(); //time ends


    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << endl;
    cout << "Algo Time: " << duration.count() << " ns" << endl; 
    return 0;
}