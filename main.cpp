#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

const unsigned int n = 60;

void rnd(int *arr){
    srand((time(0)));
    for (int i=0; i<n; i++) {
        arr[i]=0+rand()%10000;
        cout << 'a' << '['<<i<<']'<<'='<<arr[i]<<endl;
    }
    cout << endl;
}

void chetn (int *arr, int *arr1){
    for (int i=0; i<n/2; i++){
        arr1[i]=arr[2*i+1];
        cout << 'a' << '['<<i<<']'<<'='<<arr1[i]<<endl;
    }
    cout << endl;

}

void check (int *arr1) {
for (int i=0; i<n/2; i++){
    if ( (((arr1[i])&88) == 88) && (((arr1[i])&6) == 0) ){
        cout << 'a' << '['<<i<<']'<<'='<<arr1[i]<<" true "<<endl;
}
    else cout << 'a' << '['<<i<<']'<<'='<<arr1[i]<<" false "<<endl;
}
    cout <<endl;
}


void div (int *arr1){
    for(int i = 0; i<n/2; i++){
        int k=0;
        int a = arr1[i];
        while(a){
        a/=10;
        k++;
    }
        cout << 'a' << '['<<i<<']'<<'='<<arr1[i]<< " razryadov "<< k <<endl;
    }
    cout <<endl;
}
int div1 (int a){
    int k=0;
    while(a){
        a/=10;
        k++;
    }
    return k;
}

void twodimarr (int *arr1, int **p){
    for (int i=0; i<n/2; i++) {
        double d = div1(*(arr1+i));
        for (int j=0,jj=pow(10,d); j<d; j++, jj/=10 ) {
            p[i][j]= (((arr1[i])%jj)/(jj/10));
            cout << p[i][j]<< " ";
        }
        cout<< endl;
    }
    cout << endl;
}
void twodimarr1 (int *arr1, int **p){
    for (int i=0; i<n/2; i++) {
        double d = div1(*(arr1+i));
        for (int j=0; j<d; j++ ) {


            if (p[i][j]==0) {
                p[i][j] = 9;
            }
            else p[i][j]-=1;
            cout << p[i][j]<< " ";
        }
        cout<< endl;
    }
    cout << endl;
}

    void onedimarr (int *arr1, int **p, int *arr2){
        for (int i=0; i<n/2; i++) {
            double d = div1(*(arr1+i));
            int sum=0;
            for (int j=0,jj=pow(10,d-1); j<d; j++, jj/=10 ) {
                sum+=p[i][j]*jj;
            }
            arr2[i]=sum;
            cout<< sum << " ";
        }
        cout << endl;
}

int main() {
    int *arr = new int[n];
    int *arr1 = new int [n/2];
    int *arr2 = new int [n/2];

    rnd(arr);
    chetn (arr, arr1);
    check (arr1);
    div(arr1);

    int **p = new int *[n/2];
    for (int i=0; i<n/2; i++) {
        int d = div1(*(arr1+i));
        p[i] = new int[d];
    }

    twodimarr(arr1, p);
    twodimarr1(arr1, p);
    onedimarr(arr1, p, arr2);

    delete []arr;
    delete []arr1;
    delete []arr2;
    for (int i=0; i<5; i++)
        delete []p[i];
    delete[]p;

    return 0;
}