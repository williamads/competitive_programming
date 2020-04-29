#include<bits/stdc++.h>
#define eps 1e-9

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    const double pi = acos(-1);
    double x, y;
    while(cin >> x >> y) {
        cout << fixed << setprecision(10);
        double rad = atan2(y, x);
        if(rad < -eps) rad = 2.0 * pi + rad;
        cout << "rad: " << rad << '\n';
        double grau = rad / pi * 180.0;
        cout << "grau: " << grau << '\n';
    }
    return 0;
}
