#include "stdio.h"
#include "iostream"
#include "iterator"
using namespace std;

class Algo{
    private:
        int **allocated_ptr;
        int **maximum_ptr;
        int *available_ptr;
        int **needs_ptr;
    public:
        Algo(int n_process, int n_rescources, int *a[]){
                allocated_ptr = &a[0];
                maximum_ptr = &a[1];
                available_ptr = a[2];
                needs_ptr = &a[3];

        }
                
        void empty(){
            int *s;
            s = sum(available_ptr,1);      
            
        }

        int* sum(int to_sum[],int axis){
            int *aa[1];
            
            cout<<sizeof(allocated_ptr);
            return *aa;
        }








};


int main(){
    int n_process = 4;
    int n_rescources = 3;
    int allocated[4][3] = {{0,1,0},{2,0,0},{4,0,1},{2,1,1}};
    int maximum[4][3] = {{7,5,3},{3,2,2},{9,0,4},{2,2,2}};
    int available[3] = {3,3,2};
    int needs[4][3];
    
    for(int i=0;i<n_process;i++){
        for(int j=0;j<n_rescources;j++){
            needs[i][j] = maximum[i][j]-allocated[i][j];
        }
    }
   
    int *arr[4];
    arr[0] = *allocated;
    arr[1] = *maximum;
    arr[2] = available;
    arr[3] = *needs;
    Algo obj(n_process,n_rescources,arr);
    obj.empty();
    return 0;


}