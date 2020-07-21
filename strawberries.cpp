#include <iostream>

using namespace std;

typedef unsigned int uint;

const uint MAX = 1000;
const uint MIN = 0;

void age(uint arr[][MAX], const uint& x, const uint& y, const int days) {
    if (days <= 0) {
        return;
    }

    if (x > MIN) {
        arr[x-1][y] = 1;
        age(arr, x-1, y, days - 1);
    }

    if (x < MAX-1) {
        arr[x+1][y] = 1;
        age(arr, x+1, y, days - 1);
    }

    if (y > MIN) {
        arr[x][y-1] = 1;
        age(arr, x, y-1, days - 1);
    }

    if (y < MAX-1) {
        arr[x][y+1] = 1;
        age(arr, x, y+1, days - 1);
    }
}

uint count(uint arr[][MAX], const int& K, const int& L) {
    uint count = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < L; j++) {
            if (arr[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

void print(uint arr[][MAX], const int& K, const int& L) {
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < L; j++) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

int main() {



    uint K, L, R;
    uint arr[MAX][MAX] = {};

    cin >> K >> L >> R;
    if (MIN > K || K >= L || L >= MAX || MIN > R || R >= MAX) {
        cout << "Invalid data." << endl;
        exit(1);
    }

    uint x1, y1;
    cin >> x1 >> y1;
    x1--; y1--;
    arr[x1][y1] = 1;

    int x2 = -1, y2 = -1;
    cout << "Do you want to enter the location of another strawberry? (y/n)" << endl;
    char answer = 0;
    cin >> answer;

    if (answer == 'y') {
        cin >> x2 >> y2;
        x2--; y2--;
        arr[x2][y2] = 1;
    }

    age(arr, x1, y1, R);
    if (x2 != -1) {
        age(arr, x2, y2, R);
    }

    print(arr, K, L);

    cout << "count: " << count(arr, K, L) << endl;

    return 0;
}
