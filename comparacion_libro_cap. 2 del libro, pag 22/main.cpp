#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<chrono>
#define MAX 5000
using namespace std;
void allocate2d(int* A[MAX]){
    for (int i = 0; i < MAX; i++)
    {
        A[i] = new int[MAX];
    }
}
void fill_values(int* A[MAX]){
    for(int i= 0; i< MAX; i++){
        for(int j= 0; j< MAX; j++){
            A[i][j] = i*j;
        }
    }
}

int main(){
int* matris[MAX];
int vectorX[MAX];
int vectorY[MAX];
allocate2d(matris); fill_values(matris);
//fill_n(vectorX,MAX,50);  // fill a vector with a specific value
//for (int i=0;i<500;i++) cout<<vectorX[i]<< " ";
//cout<<vectorY<<endl;

auto start_time = chrono::high_resolution_clock::now();
for(int i= 0; i< MAX; i++){
    for(int j= 0; j< MAX; j++){
        vectorY[i]+=matris[i][j]*vectorX[j];
    }
}
auto end_time = chrono::high_resolution_clock::now();
auto time = end_time - start_time;
cout<<time/chrono::milliseconds(1)<< " ms"<<endl;

start_time = chrono::high_resolution_clock::now();

for(int i= 0; i< MAX; i++){
    for(int j= 0; j< MAX; j++){
       vectorY[j]+=matris[j][i]*vectorX[i];
    }
}

end_time = chrono::high_resolution_clock::now();
time = end_time - start_time;
cout<<time/chrono::milliseconds(1)<< " ms"<<endl;

}
