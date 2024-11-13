#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void floyd2(int n, const vector<vector<double>> &W, vector<vector<double>> &D, vector<vector<int>> &P)
{
    D = W;
    P = vector<vector<int>>(n, vector<int>(n, 0));

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k + 1;
                }
            }
        }
    }
}

void path(int q, int r, const vector<vector<int>> &P, vector<int> &pathVec)
{
    if (P[q][r] != 0)
    {
        path(q, P[q][r] - 1, P, pathVec);
        pathVec.push_back(P[q][r]);
        path(P[q][r] - 1, r, P, pathVec);
    }
}

int main()
{
    int n;
    cout << "정점의 개수를 입력하세요: ";
    cin >> n;

    vector<vector<double>> W(n, vector<double>(n));
    cout << "정점의 가중치를 입력해주세요 (무한대는 '9999'로 입력):" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double input;
            cin >> input;
            if (input == 9999)
            {
                W[i][j] = numeric_limits<double>::infinity();
            }
            else
            {
                W[i][j] = input;
            }
        }
    }

    vector<vector<double>> D;
    vector<vector<int>> P;
    floyd2(n, W, D, P);

    cout << "Distance matrix D:" << endl;
    for (const auto &row : D)
    {
        for (double val : row)
        {
            if (val == numeric_limits<double>::infinity())
            {
                cout << "inf ";
            }
            else
            {
                cout << val << " ";
            }
        }
        cout << endl;
    }

    cout << "\nPath matrix P:" << endl;
    for (const auto &row : P)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    int q, r;
    cout << "\n출발 정점을 입력하세요 (1부터 시작): ";
    cin >> q;
    cout << "도착 정점을 입력하세요 (1부터 시작): ";
    cin >> r;
    cout << "\nPath from v" << q << " to v" << r << ": ";

    vector<int> pathVec;
    path(q - 1, r - 1, P, pathVec);

    for (int v : pathVec)
    {
        cout << "v" << v << " ";
    }
    cout << endl;

    return 0;
}