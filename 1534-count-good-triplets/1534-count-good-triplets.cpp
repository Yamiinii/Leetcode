class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (abs(arr[i] - arr[j]) <= a)
                {
                    for (int k = j + 1; k < arr.size(); k++)
                    {
                        int B = abs(arr[j] - arr[k]);
                        int C = abs(arr[k] - arr[i]);
                        if (B <= b and C <= c)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};