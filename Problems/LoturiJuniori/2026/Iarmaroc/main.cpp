#include <fstream>
#include <stack>

using namespace std;

ifstream cin("iarmaroc.in");
ofstream cout("iarmaroc.out");

const int NMAX = 200005;
const int LOG = 18;

int v[NMAX], nextGreater[NMAX], kthGreater[NMAX];
int bLiftGreater[LOG][NMAX];

void computeNextGreaters(int n) {
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && (v[stk.top()] < v[i])) {
            nextGreater[stk.top()] = i; 
            stk.pop();
        }
        stk.push(i);
    }

    while (!stk.empty()) {
        nextGreater[stk.top()] = n + 1;
        stk.pop();
    }
}

void buildBLiftGreater(int n) {
    for (int i = 1; i <= n; i++) {
        bLiftGreater[0][i] = nextGreater[i];
    }

    for (int exp2 = 1; (1 << exp2) <= n; exp2++) {
        for (int i = 1; i <= n; i++) {
            bLiftGreater[exp2][i] = bLiftGreater[exp2 - 1][bLiftGreater[exp2 - 1][i]];
        }
    }
}

int getKthGreater(int i, int k) {
    for (int exp2 = LOG; exp2 >= 0; exp2--) {
        if (k >= (1 << exp2)) {
            i = bLiftGreater[exp2][i];
            k -= (1 << exp2);
        }
    }

    return i;
}

void computeKthGreaters(int n, int k) {
    buildBLiftGreater(n);

    for (int i = 1; i <= n; i++) {
        kthGreater[i] = getKthGreater(i, k);
    }
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    computeNextGreaters(n);
    computeKthGreaters(n, k);

    return 0;
}