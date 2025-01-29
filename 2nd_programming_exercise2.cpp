#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Υπολογισμός πίνακα ενέργειας
void computeEnergy(const vector<vector<int>>& A, vector<vector<int>>& energy, int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            energy[i][j] = 0;
            for (int x = i; x <= j; x++) {
                for (int y = x + 1; y <= j; y++) {
                    energy[i][j] += A[x][y];
                }
            }
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    // Ανάγνωση του πίνακα A
    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    // Προεπεξεργασία για τον υπολογισμό του πίνακα ενέργειας
    vector<vector<int>> energy(N + 1, vector<int>(N + 1, 0));
    computeEnergy(A, energy, N);

    // Πίνακας DP
    vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
    dp[0][0] = 0; // Δεν υπάρχει ενέργεια αν δεν έχουμε ουσίες

    for (int k = 1; k <= K; k++) {
        for (int n = 1; n <= N; n++) {
            for (int m = 0; m < n; m++) {
                if (dp[k - 1][m] != INT_MAX) { // Ελέγχουμε αν η προηγούμενη κατάσταση είναι έγκυρη
                    dp[k][n] = min(dp[k][n], dp[k - 1][m] + energy[m + 1][n]);
                }
            }
        }
    }

    // Αποτέλεσμα
    cout << dp[K][N] << endl;
    return 0;
}
