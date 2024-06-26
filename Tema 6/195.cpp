#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comparator(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}

void solve() {
    string line;
    getline(cin, line);
    vector<char> chars;
    for (size_t i = 0; i < line.length(); i++)
    {
        chars.push_back(line[i]);
    }
    sort(chars.begin(), chars.end(), comparator);
    do {
        for (size_t i = 0; i < chars.size(); i++)
        {
            cout << chars[i];
        }
        cout << endl;
    } while (next_permutation(chars.begin(), chars.end(), comparator));
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;
    cin.ignore();

    while(casos--) {
        solve();
    }
  
    return 0;
}