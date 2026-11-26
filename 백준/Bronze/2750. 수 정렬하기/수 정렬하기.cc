#include <iostream>

void mySort(int arr[], int n){
    while(--n){
        for(int* it=arr; it<arr+n; it++){
            if(*it > *(it+1)){
                *it ^= *(it+1);
                *(it+1) ^= *it;
                *it ^= *(it+1);
            }
        }
    }
}

void printArray(int arr[],int size){
    for(int* it=arr; it<arr+size; it++){
        std::cout << *it << "\n";
    }
}

int arr[1003];
int main(){
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
    int N;std::cin>>N;
    for(int i=0;i<N;i++)std::cin>>arr[i];
    mySort(arr, N);
    printArray(arr, N);
    return 0;
}
