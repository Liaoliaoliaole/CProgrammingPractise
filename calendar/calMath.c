//zeller agrithom reference:https://zhuanlan.zhihu.com/p/79290515
#include"cldr.h"
#include<stdio.h>

int get_weekD_firstD(int m, int y) {
	int d = 1;//to get the first day of the week in given month.
	int zm, zy, zeller;
	if (m < 3) {
		zm = m + 12;
		zy = y - 1;
	}
	else {
		zm = m;
		zy = y;
	}
	zeller = d + 13 * (zm + 1) / 5 + (zy % 100) + (zy % 100) / 4 +
		(zy / 100) / 4 + 5 * (zy / 100);
	zeller = zeller % 7;
	return zeller;
}
