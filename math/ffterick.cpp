#include<bits/stdc++.h>
 
#define N 999983
#define int long long
 
using namespace std;
 
bitset<N + 5> ehcomp;
vector<int> primo;
 
//typedef complex<double> base;
struct base { // faster than complex<double>
	double x, y;
	base() : x(0), y(0) {}
	base(double a, double b=0) : x(a), y(b) {}
	base operator/=(double k) { x/=k; y/=k; return (*this); }
	base operator*(base a) const { return base(x*a.x - y*a.y, x*a.y + y*a.x); }
	base operator*=(base a) {
		double tx = x*a.x - y*a.y;
		double ty = x*a.y + y*a.x;
		x = tx; y = ty;
		return (*this);
	}
	base operator=(double a) { x=a; y=0; return (*this); }
	base operator+(base a) const { return base(x+a.x, y+a.y); }
	base operator+=(base a) { x+=a.x; y+=a.y; return (*this); }
	base operator-(base a) const { return base(x-a.x, y-a.y); }
	base operator-=(base a) { x-=a.x; y-=a.y; return (*this); }
	double& real() { return x; }
	double& imag() { return y; }
};
 
void fft(vector<base> &a, bool invert) {
	int n = (int)a.size();
	for(int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for(; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for(int len = 2; len <= n; len <<= 1) {
		double ang = 2*acos(-1.0)/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for(int i = 0; i < n; i += len) {
			base w(1);
			for(int j = 0; j < len/2; j++) {
				base u = a[i+j], v = a[i+j+len/2] * w;
				a[i + j] = u + v;
				a[i + j + len/2] = u - v;
				w *= wlen;
			}
		}
	}
	for (int i = 0; invert && i < n; i++) a[i] /= n;
}
 
void convolution(vector<base> a, vector<base> b, vector<base> &res) {
	int n = 1;
	while(n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	a.resize(n), b.resize(n);
 
 
	fft(a, false); fft(b, false);
	res.resize(n);
	for(int i=0; i<n; ++i) res[i] = a[i]*b[i];
	fft(res, true);
}
 
void crivo(int n){
	ehcomp.reset();
	primo.push_back(2);
 
	for(int i = 3; i*i <= n; i += 2){
		if(!ehcomp[i]){
			primo.push_back(i);
			for(int j = i * i; j <= n; j += i)
				ehcomp[j] = 1;
		}
	}
 
	for(int i = primo[primo.size()-1] + 2; i <= n; i += 2) if(!ehcomp[i]) primo.push_back(i);
}
 
signed main() {
	//cout << (999983 * 2) << endl; // 1999966
	crivo(N); // 999983
 
	int last = primo.back();
	vector<base> p(last + 1, 0), res;
 
	for(int i = 0; i < primo.size(); ++i) {
		p[primo[i]] = 1;
	}
 
	int n, x;
	scanf("%lld", &n);
	//cin >> n;
	while(n--){
		scanf("%lld", &x);
		//cin >> x;
		p[x] = 0;
	}
	convolution(p, p, res);
 
 	scanf("%lld", &n);
	//cin >> n;
	while(n--){
		scanf("%lld", &x);
		//cin >> x;
		int ans = (int)((res[x].real() + 0.5)), half = x/2;
		if(x == 4 && ans == 1) ans = 2;
		if(half & 1 && !ehcomp[half]) {
			ans = ((ans + 1)/2) ;
		}
		else ans >>=1;
		printf("%lld\n", ans);
		//cout << ans << endl;
	}
 
	return 0;
}

