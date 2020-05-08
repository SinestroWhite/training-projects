#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;
    vector<int> sizes;

    if (1 > N || N > 1000) {
        cout << "Invalid N value" << endl;
        return 1;
    }

    if (1 > K || K > 1000) {
        cout << "Invalid K value" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (1 > temp || temp > 100000) {
            cout << "Invalid weight value" << endl;
            return 1;
        }
        sizes.push_back(temp);
    }

    sort(sizes.begin(),sizes.end(), greater<>());

    int maxElement = sizes[0];
    int capacity = maxElement;
    int moves = 0;

    while (moves != K) {
        moves=0;
        int sumSize=0;

        vector<int> tempArray = sizes;

        maxElement = tempArray[0];

        while (maxElement != 0) {
            if (sumSize + maxElement > capacity) {
                sumSize = 0;
                moves++;
            }

            sumSize += maxElement;

            for (int i = 0; i < N; i++) {
                if (tempArray[i] == maxElement) {
                    tempArray[i] = 0;
                    break;
                }
            }

            sort(tempArray.begin(), tempArray.end(), greater<>());

            maxElement = tempArray[0];

            if (maxElement + sumSize > capacity && maxElement != 0) {
                for (int i = 1; i < N; i++) {
                    if (tempArray[i] + sumSize <= capacity && tempArray[i] != 0) {
                        maxElement = tempArray[i];
                        break;
                    }
                }
            }
        }
        moves++;

        if (!tempArray.empty() && moves == K) {
            cout << "Capacity is: " << capacity << endl;
            return 0;
        }

        capacity++;
    }

    return 0;
}
