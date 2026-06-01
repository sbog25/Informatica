#include <fstream>
const int NMAX = 2005;

using namespace std;

ifstream cin("bile.in");
ofstream cout("bile.out");

int line[2][NMAX];
bool obstacol[NMAX][NMAX];

int main() {
    int m, n, p;
    cin >> m >> n >> p;
    for (int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        obstacol[x][y] = true;
    }
    for (int i = 1; i <= n; i++) {
        int bile;
        cin >> bile;
        line[0][i] = bile;
    }

    /*for (int y = 1; y <= n; y++) {
            cout << line[0][y] << ' ';
    }
    cout << '\n';*/

    int turn = 0;
    for (int x = 1; x < m; x++) {
        for (int y = 1; y <= n; y++) {
            if (obstacol[x + 1][y] == true) {
                line[1 - turn][y - 1] += line[turn][y] / 2 + (line[turn][y] % 2 == 1);
                line[1 - turn][y + 1] += line[turn][y] / 2;
                line[1 - turn][y] = 0;
            } else {
                line[1 - turn][y] += line[turn][y];
            }
        }

        for (int y = 1; y <= n; y++) {
            line[turn][y] = 0;
        }

        turn = 1 - turn;
        /*for (int y = 1; y <= n; y++) {
            cout << line[turn][y] << ' ';
        }
        cout << '\n';*/
    }
    for (int y = 1; y <= n; y++) {
        cout << line[turn][y] << '\n';
    }
    return 0;
}