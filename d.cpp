#include <bits/stdc++.h>
using namespace std;

// Function to calculate the total surface area
double surfaceArea(double b, double h) {
    return b * b + 2 * b * sqrt(h * h + (b * b) / 4.0);
}

// Function to calculate the volume of the pyramid
double volume(double b, double h) {
    return (1.0 / 3.0) * b * b * h;
}

// Function to maximize the volume given the total surface area
double maximizeVolume(double S) {
    double low = 0.0, high = S; // Possible range for the base side length b
    double bestVolume = 0.0;

    // Use binary search to find the maximum volume
    for (int i = 0; i < 100; i++) { // 100 iterations for precision
        double b = (low + high) / 2.0;
        double h = sqrt((S - b * b) / (2 * b)); // Derive h from the surface area formula
        double currentVolume = volume(b, h);

        if (surfaceArea(b, h) <= S) {
            bestVolume = max(bestVolume, currentVolume);
            low = b;
        } else {
            high = b;
        }
    }
    return bestVolume;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    double S;
    while(cin >> S){
        if ( S < 0 ) break; 
        double maxVol = maximizeVolume(S);
        cout << fixed << setprecision(10) << maxVol << endl;
    }
    return 0;
}
