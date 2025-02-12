// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <bits/stdc++.h>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N1, N2, N3, N4;
        cin >> N1 >> N2 >> N3 >> N4;

        int M;
        cin >> M;

        string F1;
        cin >> F1;

        string F2;
        cin >> F2;

        string F3;
        cin >> F3;

        string F4;
        cin >> F4;

        int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
        // devo controllare che ci la posizione di una parola contenuta in tutte le stringhe F1, F2, F3, F4 che sia di lunghezza M e che sia presente in tutte le stringhe
        for (int i = 0; i < N1 - M + 1; ++i) {
            for (int j = 0; j < N2 - M + 1; ++j) {
                for (int k = 0; k < N3 - M + 1; ++k) {
                    for (int l = 0; l < N4 - M + 1; ++l) {
                        if (F1.substr(i, M) == F2.substr(j, M) && F1.substr(i, M) == F3.substr(k, M) && F1.substr(i, M) == F4.substr(l, M)) {
                            p1 = i;
                            p2 = j;
                            p3 = k;
                            p4 = l;
                            break;
                        }
                    }
                }
            }
        }

        cout << "Case #" << test << ": ";
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    }

    return 0;
}
