#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
void showMatrix(const bool T[][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << T[i][j] << " ";
        }
    cout << "\n";
    }
}  
void inputMatrix(double R[][N]){
for(int i = 0; i < N; i++){
        cout << "Row " << i+1 << ": ";
        for(int j = 0; j < N; j++){
            cin >> R[i][j];
        } 
        
    }
}  
void findLocalMax(const double S[][N], bool U[][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            U[i][j] = false; 
        }
    }

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            
            double current = S[i][j];
            double top    = S[i-1][j];
            double bottom = S[i+1][j];
            double left   = S[i][j-1];
            double right  = S[i][j+1];

            if (current >= top && current >= bottom && 
                current >= left && current >= right) {
                U[i][j] = true;
            } else {
                U[i][j] = false;
            }
        }
    }
}