/*
* JR_Cursor.h (1.0)
* Console光标的操作
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-16
*/

#ifndef JR_CURSOR_H
#define JR_CURSOR_H

#define MAXCOL  79  //[0 - 79]


/* 将光标移到指定位置*/
void JR_SetCursor(int x, int y);

/* 将光标移到左上角 */
void JR_SetCursorStart();

/* 将光标向右移动N列 */
void JR_SetCursorRight(int n);

/* 将光标向左移动N列 */
void JR_SetCursorLeft(int n);

/* 将光标向上移动N行 */
void JR_SetCursorUp(int n);

/* 将光标向下移动N行 */
void JR_SetCursorDown(int n);

#endif
