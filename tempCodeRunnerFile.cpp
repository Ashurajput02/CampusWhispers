#include <iostream>
#include <vector>
using namespace std;

// Function to count the frequency of elements in the array
vector<int> counting(const vector<int>& ash, int n) {
    vector<int> freq(21, 0);
    for (int i = 0; i < n; i++) {
        freq[ash[i]]++;
    }
    return freq;
}

// Function to check if element k is "full ok" by comparing its frequency with others
int compute1(int k, const vector<int>& freq) {
    for (int i = 1; i <= 20; i++) {
        if (i == k) continue;
        if (freq[k] < freq[i]) return 0;
        else
        {
            continue;
        }
    }
    return 1;
}

// Function to check if ash prefix can make the array "full ok"
int prefix(int n, int k, const vector<int>& ash) {
    vector<int> prefreq(21, 0);  // Prefix frequency array
    for (int i = 0; i < n - 1; i++) {
        prefreq[ash[i]]+=1;
        if (prefreq[k] == 0) continue;
        if (compute1(k, prefreq)==1) return 1;
    }
    return 0;
}

// Function to check if ash suffix can make the array "full ok"
int suffix(int n, int k, const vector<int>& ash) {
    vector<int> suffreq(21, 0);  // Suffix frequency array
    for (int i = n - 1; i > 0; i--) {
        suffreq[ash[i]]++;
        if (suffreq[k] == 0) continue;
        if (compute1(k, suffreq)) return 1;
    }
    return 0;
}

// Function to check if one operation is possible (either prefix or suffix)
bool compute2(int n, int k, const vector<int>& ash) {
    int k1=prefix(n, k, ash);
    int k2=suffix(n, k, ash);
    if((k1||k2))
    return true;

    return false;
}

// Function to handle ash single test case
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ash(n);
    for (int i = 0; i < n; i++) {
        cin >> ash[i];
    }

    vector<int> freq = counting(ash, n);

    if (compute1(k, freq)) {
        cout << 0 << endl;
    } else if (compute2(n, k, ash)) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
