#ifndef __competitive_definitions_h__
#define __competitive_definitions_h__

#include <cstdlib>
#include <iostream>
#include <bitset>
#include <vector>

#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << (x) << endl;
#else
#define dbg(x);
#endif

using namespace std;

using ii = int;
using vb = vector<bool>;

typedef long long ll;
typedef long double ld;
typedef pair<ii, ii> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ii> vi;
typedef vector<vi> vvi;

template <typename T, typename V> ostream &operator<<(ostream &out, pair<T, V> &p) {
	out << "(" << p.ff << ", " << p.ss << ")";

	return out;
}

template <typename T> ostream &operator<<(ostream &out, vector<T> &v) {
	out << "[";
	if (v.size() != 0) {
		for (size_t i = 0; i < v.size() - 1; i++)
			out << v[i] << ", ";
		out << v[v.size() - 1];
	}
	out << "]";

	return out;
}

#endif
