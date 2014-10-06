#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int searchTargetDiffs(int *arr, int n, int target)
	{
		if(n < 2)	return 0;
		sort(arr, arr + n);
		int start = 0, end = 1, pairs = 0;
		while(end < n)
		{
			if(arr[end] - arr[start] == target) {
				++start; ++end; ++pairs;
			}
			else if(arr[end] - arr[start] > target) {
				++start;
				//if(start == end) ++end;
			}
			else
				++end;
		}
		return pairs;
	}
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 1;
    Solution so;
    
    cout << "Count of pairs with target diff is : "<< so.searchTargetDiffs(arr, size, n) <<endl;
    return 0;
}