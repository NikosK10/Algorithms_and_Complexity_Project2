#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    // Δυναμικός πίνακας για αποθήκευση του μέγιστου αθροίσματος ευθυμίας
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int maxHappiness = 0;
        for (int j = 1; j <= K && i - j >= 0; j++) {
            maxHappiness = max(maxHappiness, h[i - j]);
            dp[i] = max(dp[i], dp[i - j] + j * maxHappiness);
        }
    }

    cout << dp[N] << endl;
    return 0;
}
