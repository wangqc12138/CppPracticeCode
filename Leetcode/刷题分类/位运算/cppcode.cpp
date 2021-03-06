#include "head.h"
/*
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回
338
*/
/*
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
191
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
		int res=0;
		for(int i=0;i<31;i++){
			if((n>>i)&&1){
				res++;
			}
		}
		return res;
    }
};