#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int size;
    cin >> size;
    if (size == 0)
        return false;
    else {
        vector<int> nums;

        for (size_t i = 0; i < size; i++)
        {
            int num;
            cin >> num;
            if (num > 0) {
                nums.push_back(num);
            }
        }

        if (nums.size() == 0) {
            cout << 0 << endl;
        } else {
            for (size_t i = 0; i < nums.size() - 1; i++)
            {
                cout << nums[i] << " ";
            }
            cout << nums[nums.size() - 1] << endl;
            
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