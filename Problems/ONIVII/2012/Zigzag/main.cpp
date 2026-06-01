#include <fstream>
const int NMAX = 50005;

using namespace std;

ifstream cin("zigzag.in");
ofstream cout("zigzag.out");

int main() {
    int c, n;
    cin >> c >> n;
    string s;
    cin.get();
    getline(cin, s);
    
    int step1 = 2 * (c - 1), step2 = 0;
    int startPos = 0;
    string sFinal(NMAX + 1, 0);
    for (int i = 1; i <= c; i++) {
        int timesSkipped = 0;
        for (int t = i - 1; t < n;) {
            sFinal[t] = s[startPos];
            startPos++;
            if (min(step1, step2) > 0) {
                if (timesSkipped % 2 == 0) {
                    t += step1;
                } else {
                    t += step2;
                }
            } else {
                t += max(step1, step2);
            }
            timesSkipped++;
        }
        step1 -= 2;
        step2 += 2;
    }
    sFinal.resize(n);
    cout << sFinal << '\n';
    return 0;
}