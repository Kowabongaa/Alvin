#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void findFirstNegativeInteger(vector<int>& arr, int k) 
{
    int n = arr.size();
    queue<int> negatives; 
    vector<int> result;  

    for (int i = 0; i < k; i++) 
    {
        if (arr[i] < 0) {
            negatives.push(i); 
        }
    }

    for (int i = k; i <= n; i++) 
    {
        if (!negatives.empty()) 
        {
            result.push_back(arr[negatives.front()]);  
        } else 
        {
            result.push_back(0); 
        }

        if (!negatives.empty() && negatives.front() <= i - k) {
            negatives.pop();
        }

        if (i < n && arr[i] < 0) {
            negatives.push(i);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter the window size k: ";
    cin >> k;
    cout << "First negative integer for each window of size " << k << ":" << endl;
    findFirstNegativeInteger(arr, k);

    return 0;
}
