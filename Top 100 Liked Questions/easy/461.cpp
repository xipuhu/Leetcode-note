/* 原题内容
461. Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 2^31.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

*/


// 第一遍解法代码
/* info:
*Runtime: 4 ms, faster than 97.20%
*Memory Usage: 8.4 MB, less than 57.28%
*/
int hammingDistance(int x, int y) {

    int z = (x^y);
    int ans = 0;

    while (z != 0){
        if ((z & 1) == 1)
            ++ans;
        z = (z >> 1);    // 移位运算符的优先级低于等号
    }

    return ans;
}

// 网上好的解法
/* info:
*Runtime: 4 ms, faster than 97.20%
*Memory Usage: 8.4 MB, less than 57.28%
*/
//异或以后的结果中1的个数即为对应位不同的个数
int hammingDistance(int x, int y) {
    int tmp = x ^ y;
    return numof1(tmp);
}
int numof1(int x){
    int count = 0;
    while (x){
        ++count;
        x = (x - 1)&x;
    }
    return count;
}

// 精简优化
/* info:
*Runtime: 4 ms, faster than 97.20%
*Memory Usage: 8.4 MB, less than 57.28%
*/
int hammingDistance(int x, int y) {
    return __builtin_popcount(x^y);
}
/* 思考
1. 解法思路方面：

Hamming Distance指的是x和y的二进制中，bit不同的数目，即，x和y异或以后的结果中1的个数即为对应位不同的个数

2. 代码解决方面：

可以通过x&1是否等于1，来判断x的最后一个bit是0还是1

__builtin_popcount()函数是GCC的一个内建函数，用来计算x中1的个数

位逻辑运算符有：&(与)、^(异或)、|(或)、~(取反)

位逻辑运算符的优先级高于逻辑运算符，低于比较运算符，且从高到低依次为&、^、|

移位运算符的优先级很低，使用时要加括号

*/




