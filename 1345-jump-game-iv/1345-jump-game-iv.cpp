class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        queue<pair<int, int>> q;
        map<int, vector<int>> m;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]].push_back(i);
        }

        q.push({0, 0});
        for (auto it : m[arr[0]])
        {
            if (it != 0)
                q.push({it, 1});
        }
        m.erase(arr[0]);
        while (!q.empty())
        {

            for (int i = 0; i < q.size(); i++)
            {
                pair<int, int> x = q.front();
                q.pop();
                if (x.first == arr.size() - 1)
                {
                    return x.second;
                }
                if (x.first - 1 >= 0 && m.find(arr[x.first - 1]) != m.end())
                {
                    q.push({x.first - 1, x.second + 1});
                }
                if (x.first + 1 < arr.size() && m.find(arr[x.first + 1]) != m.end())
                {
                    if (x.first + 1)
                        q.push({x.first + 1, x.second + 1});
                }
                if (m.find(arr[x.first]) != m.end())
                {
                    for (auto it : m[arr[x.first]])
                    {
                        if (it != x.first)
                            q.push({it, x.second + 1});
                    }
                }
                m.erase(arr[x.first]);
            }
        }
        return 0;
    }
};