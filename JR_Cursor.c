/*
* JR_Cursor.c (1.0)
* Console光标的操作
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-16
*/

#include "JR_Cursor.h"
#include <windows.h>


/* 将光标移到指定位置 */
void JR_SetCursor(int x, int y){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hOut, pos);
}

/* 将光标移到左上角 */
void JR_SetCursorStart(){
    JR_SetCursor(0, 0);
}

/* 将光标向右移动N列 */
void JR_SetCursorRight(int n){
    COORD pos= {0, 0};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO cinfo = malloc(sizeof(PCONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(hOut, cinfo);
    pos.X = cinfo->dwCursorPosition.X + n;
    pos.Y = cinfo->dwCursorPosition.Y;
    SetConsoleCursorPosition(hOut, pos);
    free(cinfo);
}

/* 将光标向左移动N列 */
void JR_SetCursorLeft(int n){
    COORD pos= {0, 0};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO cinfo = malloc(sizeof(PCONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(hOut, cinfo);
    pos.X = cinfo->dwCursorPosition.X - n;
    pos.Y = cinfo->dwCursorPosition.Y;
    SetConsoleCursorPosition(hOut, pos);
    free(cinfo);
}

/* 将光标向上移动N行 */
void JR_SetCursorUp(int n){
    COORD pos= {0, 0};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO cinfo = malloc(sizeof(PCONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(hOut, cinfo);
    pos.X = cinfo->dwCursorPosition.X;
    pos.Y = cinfo->dwCursorPosition.Y - n;
    SetConsoleCursorPosition(hOut, pos);
    free(cinfo);
}

/* 将光标向下移动N行 */
void JR_SetCursorDown(int n){
    COORD pos= {0, 0};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO cinfo = malloc(sizeof(PCONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(hOut, cinfo);
    pos.X = cinfo->dwCursorPosition.X;
    pos.Y = cinfo->dwCursorPosition.Y + n;
    SetConsoleCursorPosition(hOut, pos);
    free(cinfo);
}
