/*
* JR_Random.h (1.1)
* 随机数
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-11
*/

#ifndef JR_RANDOM_H
#define JR_RANDOM_H


/* 取随机数 */
int JR_random(void);
/* 取0到max的随机数 [0, max] */
int JR_randomIn(int max);
/* 取指定范围随机数 [min, max] */
int JR_randomRange(int min, int max);

#endif
