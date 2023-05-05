#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int S = 3; // number of states
const int A = 2; // number of actions

const double p[S][S][A] = {
    { {0.9, 0.1}, {0.5, 0.5}, {0.0, 1.0} },
    { {0.1, 0.9}, {0.8, 0.2}, {0.0, 1.0} },
    { {0.0, 1.0}, {0.0, 1.0}, {1.0, 0.0} }
};

const double r[S][A] = {
    {2.0, 3.0},
    {0.0, 4.0},
    {5.0, -1.0}
};

const double gamma = 0.9; // discount factor
const double tol = 1e-6; // convergence tolerance

vector<double> value_iteration() {
    vector<double> V(S, 0.0);
    while (true) {
        double delta = 0.0;
        for (int s = 0; s < S; ++s) {
            double v = V[s];
            double max_v = -INFINITY;
            for (int a = 0; a < A; ++a) {
                double q = r[s][a];
                for (int sp = 0; sp < S; ++sp) {
                    q += gamma * p[s][sp][a] * V[sp];
                }
                max_v = max(max_v, q);
            }
            V[s] = max_v;
            delta = max(delta, abs(v - V[s]));
        }
        if (delta < tol) break;
    }
    return V;
}

int main() {
    vector<double> V = value_iteration();
    for (int s = 0; s < S; ++s) {
        cout << "V(" << s << ") = " << V[s] << endl;
    }
    return 0;
}
