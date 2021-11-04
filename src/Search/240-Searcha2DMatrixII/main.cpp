#include <iostream>
#include <vector>

using namespace std;

class Solution240
{
private:
    bool inMatrix(int x, int y, int n, int m)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // 从左下角开始，遇到比 target 大的则往上走一格；比它小的则往右走一格
        int n = matrix.size(), m = matrix[0].size();
        int currX = 0, currY = n - 1; // 从左下角开始

        while (inMatrix(currX, currY, n, m))
        {
            int currVal = matrix[currY][currX];
            if (currVal == target)
                return true;

            else if (currVal > target)
                currY--;
            else
                currX++;
        }

        return false;
    }
};

int main()
{

    return 0;
}