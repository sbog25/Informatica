#include <fstream>
const int NMAX = 1000005;

using namespace std;

ifstream cin("proiecte.in");
ofstream cout("proiecte.out");

char frecv[NMAX];

int main() {
    int n, m;
    int maxiProiecte=0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int nrEtape, elementMaj = 0, cntMaj = 0;
        cin >> nrEtape;

        for (int t = 1; t <= nrEtape; t++) {
            int firma;
            cin >> firma;

            if (elementMaj == 0) {
                elementMaj = firma;
                cntMaj++;
            } else if (elementMaj == firma) {
                cntMaj++;
            } else {
                cntMaj--;
            }
            if(cntMaj == 0) {
                cntMaj++;
                elementMaj = firma;
            }
        }

        frecv[elementMaj]++;
        maxiProiecte = max(maxiProiecte, (int)frecv[elementMaj]);
    }

    for (int i = 1; i <= n; i++) {
        if (frecv[i] == maxiProiecte) {
            cout << i << ' ';
        }
    }
    return 0;
}