#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> v;
long long cap, glb;
/*
long long powerLL(long long x, long long n)
{
    long long result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x;
        n = n / 2;
        x = x * x;
    }
    return result;
}
*/
string DtoB(int num)
{
    string str;
    while (num)
    {
        if (num & 1)
            str += '1';
        else
            str += '0';
        num >>= 1;
    }
    return str;
}

void split(long long x)
{
    long long sum = 0, y = v.size();
    vector<long long> w;
    w.push_back(v[x][0] + (1<<v[x][1]));
    v[x][1]++;
    w.push_back(v[x][1]);
    v.push_back(w);
    w.clear();
    for(long long i = 0; i < v[x].size(); i++)
    {
        w.push_back(v[x][i]);
    }
    v[x].clear();
    v[x].push_back(w[0]);
    v[x].push_back(w[1]);
    for (long long i = 2; i < w.size(); i++)
    {
        sum = 0;
        /*
        for (long long j = 0; j < w[1]; j++)
        {
            sum = sum + (w[i] & (1<<j));
        }
        */
        sum = w[i] & ((1<<w[1])-1);
        if (sum == w[0])
        {
            v[x].push_back(w[i]);
            continue;
        }
        v[y].push_back(w[i]);
    }
    w.clear();
    if (v[x].size() > cap + 2)
    {
        split(x);
    }
    if (v[y].size() > cap + 2)
    {
        split(y);
    }
    return;
}

void display()
{
    long long sum = glb;
    for(long long i = 0; i < v.size(); i++)
    {
        sum = max(sum, v[i][1]);
    }
    cout << sum << endl
         << v.size() << endl;
    for(long long i = 0; i < v.size(); i++)
    {
        cout << v[i].size() - 2 << " " << v[i][1] << "\n";
    }
    cout << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long x, y, sum;
    cin >> glb >> cap;
    vector<long long> w;
    for (long long i = 0; i < (1<<glb); i++)
    {
        w.push_back(i);
        w.push_back(glb);
        v.push_back(w);
        w.clear();
    }
    while (1)
    {
        cin >> x;
        if (x == 6)
            break;

        if (x == 5)
            display();

        if (x == 4)
        {
            bool flag = false;
            cin >> y;
            for(long long i = 0; i < v.size(); i++)
            {
                auto it = v[i].begin();
                ++it;
                ++it;
                while (it != v[i].end())
                {
                    if (*it == y)
                    {
                        v[i].erase(it);
                        flag = true;
                        break;
                    }
                    ++it;
                }
                if (flag)
                {
                    break;
                }
            }
        }
        if (x == 3)
        {
            cin >> y;
            bool flag = false;
            for(long long i = 0; i < v.size(); i++)
            {
                for(long long j = 2; j < v[i].size(); j++)
                {
                    if (v[i][j] == y)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
        }
        if (x == 2)
        {
            cin >> y;
            for(long long i=0;i<v.size();i++)
            {
                sum=0;
                for(long long j=0;j<v[i][1];j++)
                {
                    sum=sum+(y&(1<<j));
                }
                if(sum==v[i][0])
                {
                    v[i].push_back(y);
                    if(v[i].size()>cap+2)
                    {
                        split(i);
                    }
                    break;
                }
            }
        }
    }
    
}