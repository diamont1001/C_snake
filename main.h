/*
* main.h (1.0)
* 贪吃蛇游戏资源、数据结构的声明与定义
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011年2月
*/

#ifndef MAIN_H
#define MAIN_H

#include "JR_timer.h"
#include "JR_Random.h"
#include "JR_Cursor.h"
#include "JR_KeyBoard.h"
#include "snake.h"


/* 界面规格 */
#define ROW 20
#define COL 20

/* 游戏状态 */
typedef enum _STATUS{
    WELCOME, GAMING, DIE, PAUSE, STOP
}STATUS;

/* 方向 */
typedef enum _DIRECTION{
    UP, DOWN, LEFT, RIGHT
}DIRECTION;

#endif
