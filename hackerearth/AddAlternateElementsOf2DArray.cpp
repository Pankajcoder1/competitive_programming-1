#include <iostream>

using namespace std;

int main() {
    int arr[3][3];

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >> arr[i][j];
        }
    }

    int sum1 = arr[0][0] + arr[0][2] + arr[1][1] + arr[2][0] + arr[2][2];
    int sum2 = arr[0][1] + arr[1][0] + arr[1][2] + arr[2][1];

    cout << sum1 << endl;
    cout << sum2 << endl;
    
    return 0;
}