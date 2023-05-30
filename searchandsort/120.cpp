#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 257;  //The modular value
ll r = 256;    //radix
ll dr = 1;     //Highest power for row hashing
ll dc = 1;     //Highest power for col hashing

//func that return a power n under mod m in LogN
ll power(int a, int n, ll m) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return a % m;
  }
  ll pow = power(a, n / 2, m);
  if (n & 1) {
    return ((a % m) * (pow) % m * (pow) % m) % m;
  }
  else {
    return ((pow) % m * (pow) % m) % m;
  }
}
//Checks if all values of pattern matches with the text
bool check(vector<vector<char>> &txt, vector<vector<char>> &pat, ll r, ll c) {
  for (ll i = 0; i < pat.size(); i++) {
    for (ll j = 0; j < pat[0].size(); j++) {
      if (pat[i][j] != txt[i + r][j + c]) return false;
    }
  }
  return true;
}
//Finds the first hash of first n rows where n is no. of rows in pattern
vector<ll> findHash(vector<vector<char>> &mat, ll row) {
  vector<ll> hash;
  ll col = mat[0].size();
  for (ll i = 0; i < col; i++) {
    ll h = 0;
    for (ll j = 0; j < row; j++) {
      h = ((h * r) % mod + mat[j][i] % mod) % mod;
    }
    hash.push_back(h);
  }
  return hash;
}
//rolling hash function for columns
void colRollingHash(vector<vector<char>> &txt, vector<ll> &t_hash, ll row, ll p_row) {
  for (ll i = 0; i < t_hash.size(); i++) {
    t_hash[i] = (t_hash[i] % mod - ((txt[row][i]) % mod * (dr) % mod) % mod) % mod;
    t_hash[i] = ((t_hash[i] % mod) * (r % mod)) % mod;
    t_hash[i] = (t_hash[i] % mod + txt[row + p_row][i] % mod) % mod;
  }
}
void rabinKarp(vector<vector<char>> &txt, vector<vector<char>> &pat) {
  ll t_row = txt.size();
  ll t_col = txt[0].size();
  ll p_row = pat.size();
  ll p_col = pat[0].size();
  dr = power(r, p_row - 1, mod);
  dc = power(r, p_col - 1, mod);
  vector<ll> t_hash = findHash(txt, p_row); //column hash of p_row rows
  vector<ll> p_hash = findHash(pat, p_row); //column hash of p_row rows
  ll p_val = 0;  //hash of entire pattern matrix
  for (ll i = 0; i < p_col; i++) {
    p_val = (p_val * r + p_hash[i]) % mod;
  }
  for (ll i = 0; i <= (t_row - p_row); i++) {
    ll t_val = 0;
    for (ll i = 0; i < p_col; i++) {
      t_val = ((t_val * r) + t_hash[i]) % mod;
    }
    for (ll j = 0; j <= (t_col - p_col); j++) {
      if (p_val == t_val) {
        if (check(txt, pat, i, j)) {
          cout << i << " " << j << endl;
        }
      }
      //calculating t_val for next set of columns
      t_val = (t_val % mod - ((t_hash[j] % mod) * (dc % mod)) % mod + mod) % mod;
      t_val = (t_val % mod * r % mod) % mod;
      t_val = (t_val % mod + t_hash[j + p_col] % mod) % mod;
    }
    if (i < t_row - p_row) {
      //call this function for hashing form next row
      colRollingHash(txt, t_hash, i, p_row);
    }
  }
}
int main() {
  vector<vector<char>> txt{{'A', 'B', 'C', 'D', 'E'}, {'A', 'B', 'C', 'D', 'E'}, {'A', 'B', 'C', 'D', 'E'}, {'A', 'B', 'C', 'D', 'E'}, {'A', 'B', 'C', 'D', 'E'}};
  vector<vector<char>> pat{{'A', 'B', 'C', 'D', 'E'}, {'A', 'B', 'C', 'D', 'E'}, {'A', 'B', 'C', 'D', 'E'}, {'A', 'B', 'C', 'D', 'E'}};
  //function prints the indices of row and col where its a match in txt
  rabinKarp(txt, pat);
  return 0;
}