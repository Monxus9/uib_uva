#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    unsigned int size;
    cin >> size;
    if (size == 0)
        return false;
    else {
        // Code solve
        stack<int> stack;
        unsigned int num;
        unsigned int rails;
        bool valid;
        while (true) {
            rails = 1;
            valid = true;
            for (size_t i = 0; i < size; i++)
            {
                cin >> num;
                if (num == 0) break;
                if (valid) {
                    if (num >= rails) {
                        while (num > rails) {
                            stack.push(rails++);
                        }
                        rails++;
                    } else if (!stack.empty() && stack.top() == num) {
                        stack.pop();
                    } else {
                        valid = false;
                    }
                }
            }
            if (num == 0) {
                cout << endl;
                break;
            } else {
                if (valid) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }

    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()) {
    }
  
    return 0;
}