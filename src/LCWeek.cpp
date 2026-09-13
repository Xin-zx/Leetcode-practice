class Solution {
public:
    // 函数定义：
    // n：方阵大小 n*n
    // grid：原始二维矩阵（输入）
    // rowShift：rowShift[i]代表第i行左移多少位
    // colShift：colShift[j]代表第j列上移多少位
    // 返回移位完成之后的新矩阵
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        // 创建一个 n行n列 的二维数组res，用来存放最终答案，初始全部是0
        vector<vector<int>> res(n, vector<int>(n));

        // 外层循环：遍历每一行，i是行下标
        for(int i = 0; i < n; i++){
            // 内层循环：遍历当前行里面的每一列，j是列下标
            for(int j = 0; j < n; j++){

                // =========第一步：处理【行左循环移位】=========
                // 取出第i行要左移的位数
                int k_row = rowShift[i];
                // 题目公式：原位置(i,j)，行移位后，新的列下标 j1 = (j - k_row + n) % n
                // +n是为了防止减法算出负数；%n保证下标在0~n-1之间
                int j1 = (j - k_row + n) % n;

                // =========第二步：处理【列向上循环移位】=========
                // 行移位完成之后，元素现在在(i, j1)这个位置
                // 取出 j1 这一列，要向上移位的位数
                int k_col = colShift[j1];
                // 题目公式：原位置(i,j1)，列移位后，新的行下标 i2 = (i - k_col + n) % n
                int i2 = (i - k_col + n) % n;

                // =========把原始grid[i][j]放到最终的位置 res[i2][j1] =========
                res[i2][j1] = grid[i][j];
            }
        }
        // 返回结果矩阵
        return res;
    }
};
