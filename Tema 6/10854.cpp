#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string line;
int countif;

int process_block();

int process_if() {
    countif++;
    //cout << "IF" << countif << endl;
    int count = 1;
    getline(cin, line);
    while (line != "END_IF" && line != "ELSE") {
        count *= process_block();
        getline(cin, line);
        //cout << "IF" << countif << " LOOP: " << line << endl;
    }
    //cout << "IF" << countif << " " << count << endl;
    if (line == "ELSE") {
        //cout << "IN ELSE" << countif << endl;
        int count_else = 1;
        getline(cin, line);
        while (line != "END_IF") {
            count_else *= process_block();
            getline(cin, line);
        }
        count += count_else;
        
        
    }
    //cout << "IF RETURN: " << count << endl;
    countif--;
    return count;

}

int process_block() {
    //cout << "PB: "<< line << endl;
    if (line == "S" || line == "END_IF") return 1;

    int count = 1;
    if (line == "IF") {
        count *= process_if();
    }

    return count;

}

void solve() {
    countif = 0;
    int count = 1;
    
    getline(cin, line);
    while (line != "ENDPROGRAM") {
        //cout << "PROGRAM LOOP" << endl;
        count *= process_block();
        getline(cin, line);
    }
    

    cout << count << endl;
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