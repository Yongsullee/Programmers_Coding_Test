#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    // answer의 사이즈 = arr1의 행 x arr2의 열
    int arr1_row = (int)arr1.size();
    int arr1_col = (int)arr1[0].size();

    int arr2_col = (int)arr2[0].size();

    answer.resize(arr1_row, vector<int>(arr2_col));

    for (int i = 0; i < arr1_row; ++i)
    {
        for (int j = 0; j < arr2_col; ++j)
        {
            for (int k = 0; k < arr1_col; ++k)
                answer[i][j] += arr1[i][k] * arr2[k][j];
        }
    }
    `

        return answer;
}