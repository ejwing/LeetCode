//
// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/
//
#pragma once

using namespace std;

//
namespace PROBLEM29
{
	class Solution {
	public:
		int divide(int dividend, int divisor) {
			return method2(dividend, divisor);
		}

		int method1(int dividend, int divisor) {
			unsigned int c = 0;
			int ret = 0;
			bool p1 = dividend > 0, p2 = divisor > 0;
			unsigned int d1, d2;
			d1 = p1 ? dividend : (unsigned int)~dividend + 1;
			d2 = p2 ? divisor : (unsigned int)~divisor + 1;
			while (d1 >= d2)
			{
				for (int i = 0; i < 32 && d1 >= d2; i++)
				{
					unsigned int _d = d2 << i;
					if (_d > d1)
					{
						d1 -= d2 << (i - 1);
						c += 1 << (i - 1);
						break;
					}
					else if (_d == d1)
					{
						d1 -= d2 << i;
						c += 1 << i;
						break;
					}
				}
			}
			//
			if (p1 ^ p2)
				ret = c * -1;
			else
				ret = c > INT_MAX ? INT_MAX : c;

			return ret;
		}

		int method2(int dividend, int divisor) {
			if (dividend == INT_MIN && divisor == -1)
				return INT_MAX;
			bool p1 = dividend > 0, p2 = divisor > 0;
			unsigned int d1, d2;
			d1 = p1 ? dividend : (unsigned int)~dividend + 1;
			d2 = p2 ? divisor : (unsigned int)~divisor + 1;
			double d3 = exp(log(d1) - log(d2));
			if (p1 ^ p2)
				d3 *= -1;
			return (int)d3;
		}
	};
}

using namespace PROBLEM29;
