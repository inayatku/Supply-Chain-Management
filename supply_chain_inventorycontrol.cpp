#include <iostream>
#include <cmath>

using namespace std;

double calculateEOQ(double demand, double ordering_cost, double holding_cost) {
    return sqrt((2 * demand * ordering_cost) / holding_cost);
}

int main() {
    double annual_demand, ordering_cost, holding_cost;

    cout << "Enter annual demand: ";
    cin >> annual_demand;

    cout << "Enter ordering cost per order: ";
    cin >> ordering_cost;

    cout << "Enter holding cost per unit per year: ";
    cin >> holding_cost;

    double eoq = calculateEOQ(annual_demand, ordering_cost, holding_cost);

    cout << "Economic Order Quantity: " << eoq << endl;

    return 0;
}
