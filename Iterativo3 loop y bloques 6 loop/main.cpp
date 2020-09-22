#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<chrono>
#define MAX 1000
using namespace std;

void fill_values(int* A[MAX]){
    for(int i= 0; i< MAX; i++){
        for(int j= 0; j< MAX; j++){
            A[i][j] = i*j +1;
        }
    }
}
void printM(int* A[MAX]){
    for(int i= 0; i< MAX; i++){
        for(int j= 0; j< MAX; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<'\n';
    }
}
void allocate2d(int* A[MAX]){
    for (int i = 0; i < MAX; i++)
    {
        A[i] = new int[MAX];
    }
}

int main(){

int* A[MAX];
int* B[MAX];
int* C[MAX];
int* D[MAX];
allocate2d(A); allocate2d(B);allocate2d(C);allocate2d(D);
fill_values(A); fill_values(B);

auto start_time = chrono::high_resolution_clock::now();

for(int i= 0; i<MAX; i++){
    for(int j= 0; j<MAX; j++){
        for(int k=0; k<MAX;k++){
            //if (i==2 && j==2){ cout<<A[i][k]*B[k][j]<<" ";}
            C[i][j]+=A[i][k]*B[k][j];
        }
    }
}

//printM(A);printM(B);printM(C);
auto end_time = chrono::high_resolution_clock::now();
auto time = end_time - start_time;
cout<<"Alg1: "<<time/chrono::milliseconds(1)<< " ms"<<endl;

int s =4; int temp=0; int a[5][5];int b[5][5];
start_time = chrono::high_resolution_clock::now();

for(int subi=0;subi<MAX;subi+= s){
    for(int subj=0;subj<MAX;subj+= s){
        for(int subk=0;subk<MAX;subk+=s){

            for(int i = subi; i<( (subi+s)>MAX ?MAX:(subi+s) ); i++){
                temp = 0;
                for(int j = subj; j<( (subj+s)>MAX ?MAX:(subj+s)); j++){
                    for(int k = subk; k<( (subk+s)>MAX ?MAX:(subk+s) ); k++){
                        //temp += a[i][k]*b[k][j];
                        //if (i==2 && j==2){ cout<<A[i][k]*B[k][j]<<" ";}
                        D[i][j] += A[i][k]*B[k][j] ;
                        }
                }
 
            }
        }
    }
}


end_time = chrono::high_resolution_clock::now();
time = end_time - start_time;
cout<<"Alg2: "<<time/chrono::milliseconds(1)<< " ms"<<endl;
//printM(A);printM(B);printM(D);
}
