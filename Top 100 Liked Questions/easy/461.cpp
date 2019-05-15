/* ԭ������
461. Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 �� x, y < 2^31.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ��   ��

The above arrows point to positions where the corresponding bits are different.

*/


// ��һ��ⷨ����
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
        z = (z >> 1);    // ��λ����������ȼ����ڵȺ�
    }

    return ans;
}

// ���ϺõĽⷨ
/* info:
*Runtime: 4 ms, faster than 97.20%
*Memory Usage: 8.4 MB, less than 57.28%
*/
//����Ժ�Ľ����1�ĸ�����Ϊ��Ӧλ��ͬ�ĸ���
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

// �����Ż�
/* info:
*Runtime: 4 ms, faster than 97.20%
*Memory Usage: 8.4 MB, less than 57.28%
*/
int hammingDistance(int x, int y) {
    return __builtin_popcount(x^y);
}
/* ˼��
1. �ⷨ˼·���棺

Hamming Distanceָ����x��y�Ķ������У�bit��ͬ����Ŀ������x��y����Ժ�Ľ����1�ĸ�����Ϊ��Ӧλ��ͬ�ĸ���

2. ���������棺

����ͨ��x&1�Ƿ����1�����ж�x�����һ��bit��0����1

__builtin_popcount()������GCC��һ���ڽ���������������x��1�ĸ���

λ�߼�������У�&(��)��^(���)��|(��)��~(ȡ��)

λ�߼�����������ȼ������߼�����������ڱȽ���������ҴӸߵ�������Ϊ&��^��|

��λ����������ȼ��ܵͣ�ʹ��ʱҪ������

*/




