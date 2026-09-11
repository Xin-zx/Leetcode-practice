class Solution {
public:
    bool isHappy(int n) {
        unordered_set <int> s;//哈希记录重复数字
        while (true){
            int sum = 0;
            while (n > 0){
                int mod = n % 10;
                sum += mod * mod;
                n /= 10;
            }
                n = sum;
                if (sum == 1) return true;
                if (s.count(n)){ 
                //不断求每一位平方和；有限集合内迭代，要么收敛到 1，要么进入循环。
                return false;
            }
            s.insert(n);
        }
    }
};