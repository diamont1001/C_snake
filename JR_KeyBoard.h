/*
* JR_KeyBoard.h (1.0)
* 键盘按键检测
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-14
*/

#ifndef JR_KEYBOARD_H
#define JR_KEYBOARD_H

/******** 键值定义 ********/
//复合键值前置部分
#define JR_KEY_PRE_F        0
#define JR_KEY_PRE_DIR      224

//方向键
#define JR_KEY_UP           224072
#define JR_KEY_LEFT         224075
#define JR_KEY_RIGHT        224077
#define JR_KEY_DOWN         224080

//控制键
#define JR_KEY_ENTER        13
#define JR_KEY_SPACE        32
#define JR_KEY_ESC          27
#define JR_KEY_TAB          09
#define JR_KEY_BACKSPACE    08

//F键【F1，F12】 F8除外)
#define JR_KEY_F1           -59
#define JR_KEY_F2           -60
#define JR_KEY_F3           -61
#define JR_KEY_F4           -62
#define JR_KEY_F5           -63
#define JR_KEY_F6           -64
#define JR_KEY_F7           -65
//#define JR_KEY_F8           -59
#define JR_KEY_F9           -67
#define JR_KEY_F10          -68

#define JR_KEY_F11          2240133     //pre键值为224
#define JR_KEY_F12          2240134     //pre键值为224

/* 检测当前是否有键盘输入，并更新键值JR_KeyValue */
int JR_AnyKeys(void);

/* 返回键值ASCII码 或 对应自定义键值 */
int JR_GetKeyNum(void);

/* 检测指定键是否有按下 */
int JR_IsKeyDown(const int key);


#endif
