/*
* JR_timer.h (1.0)
* 单线程中的定时器
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-11
*/

#ifndef JR_TIMER_H
#define JR_TIMER_H


/* 获取CPU时间ms */
unsigned long JR_GetTicks(void);

/* 启动计时器 */
void startTimer(void);

/* 停止计时器 */
void stopTimer(void);

/* 设定定时器间隔 */
void setTimer(int ms);

/* 每个Interval触发一次 */
void ontimer(void);

#endif
