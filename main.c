/*
* main.c (1.0)
* 贪吃蛇游戏主要逻辑与界面的实现
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011年2月
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/* 游戏资源 */
const char *BG = "■";
const char *BODY = "○";//"□";//"●";//"█";
const char *BODY_HEAD = "㊣";
const char *BODY_FOOD = "☆";//"◆";

static STATUS sys_gs;       //游戏状态
static DIRECTION sys_dir;   //当前方向
static int sys_speed = 100;       //速度

//纹理缓存
static SHOWNODE showBuff[ROW*COL*2];
static int BuffIndex = 0;

//游戏分数
static int TotalScore = 0;


/* SHOW WELCOME */
void showWelcome(void){
    printf("\t\t******************************************\n");
    printf("\t\t*       Welcome to Snake Gameing.        *\n");
    printf("\t\t*        By Eric-JR Chen 2011-2          *\n");
    printf("\t\t*          diamont1001@163.com           *\n");
    printf("\t\t*        【1~9】Start in Level 1~9       *\n");
    printf("\t\t*        【Enter】 Start in default      *\n");
    printf("\t\t*        【Esc】  Esc                    *\n");
    printf("\t\t******************************************\n");
    JR_SetCursor(0,8);
}

/* 将一个 NODE放到纹理缓冲区 */
void showInBuff(SHOWNODE buffer){
    showBuff[BuffIndex].x = buffer.x;
    showBuff[BuffIndex].y = buffer.y;
    strcpy(showBuff[BuffIndex].text, buffer.text);
    BuffIndex ++;
}

/* 将snake尾部清空 */
void blackTail(){
    strcpy(pSnakeHead->node.text, BG);
    showInBuff(pSnakeHead->node);
    DelSNode();
}

/* 显示背景 */
void showBG(void){
    int i = 0, j = 0;
    char backshow[10];
    strcpy(backshow, BG);
    JR_SetCursorStart();
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            printf("%s", backshow);
        }
        printf("\t\t\t\n");
    }
    JR_SetCursor(COL*2+1, 0);
    printf("Score : %d", TotalScore);
    JR_SetCursor(COL*2+1, 1);
    printf("Speed : %d", sys_speed);
    JR_SetCursor(COL*2+1, 3);
    printf("UP   :【↑】【W】【w】");
    JR_SetCursor(COL*2+1, 4);
    printf("LEFT :【←】【A】【a】");
    JR_SetCursor(COL*2+1, 5);
    printf("DOWN :【↓】【S】【s】");
    JR_SetCursor(COL*2+1, 6);
    printf("RIGHT:【→】【D】【d】");
    JR_SetCursor(COL*2+1, 8);
    printf("PAUSE :【ENTER】");
    JR_SetCursor(COL*2+1, 9);
    printf("RESUME:【ENTER】");
    JR_SetCursor(COL*2+1, 10);
    printf("ESC   :【ESC】");
}

/* 游戏显示 */
void show(void){
    if(sys_gs == GAMING){
        int i = 0;
        if(BuffIndex == 0) return ;
        for(i=0; i<BuffIndex; i++){
            JR_SetCursor(showBuff[i].x, showBuff[i].y);
            printf("%s", showBuff[i].text);
        }
        BuffIndex = 0;
        JR_SetCursor(0, COL+1);
    }
}

/* 开始新游戏 */
void startGame(void){
    SNAKE ps;
    showBG();
    InitSnake(4);
    BuffIndex = 0;
    TotalScore = 0;
    ps = pSnakeHead;
    while(ps){
        showInBuff(ps->node);
        ps = ps->next;
    }
    GetFood();
    showInBuff(FOOD);
    JR_SetCursor(0, ROW+2);
    printf("Food : %d, %d, %s\t", FOOD.x, FOOD.y, FOOD.text);
    sys_dir = RIGHT;
    setTimer(sys_speed);
    startTimer();
}

/* Game over */
void gameOver(){
    DeleteSnake();
}

/* 游戏初始化 */
void initGame(void){
    setTimer(33);
    startTimer();
    sys_gs = WELCOME;
    showWelcome();
}

/* 按键检测 */
void updateKey(void){
    if(!JR_AnyKeys()) return ;

    if(JR_IsKeyDown(JR_KEY_ESC)){   //ESC
        sys_gs = STOP;
        exit(0);
    }

    switch(sys_gs){
    case WELCOME :
    case DIE:
        //START GAME
        if(JR_IsKeyDown(JR_KEY_ENTER)){
            stopTimer();
            sys_gs = GAMING;
            JR_SetCursor(COL*2+9, 1);
            printf("%d", sys_speed);
            startGame();
        }
        else if(JR_GetKeyNum() >= '1' && JR_GetKeyNum() <= '9'){
            sys_speed = 200 - (JR_GetKeyNum()-'0') * 18;
            stopTimer();
            sys_gs = GAMING;
            showBG();
            JR_SetCursor(COL*2+9, 1);
            printf("%d", sys_speed);
            startGame();
        }
        break;
    case GAMING :
        if(JR_IsKeyDown(JR_KEY_ENTER)){   //PAUSE
            sys_gs = PAUSE;
            printf("Pause! 【Enter】to continue!【Esc】to esc!\t");
            JR_SetCursor(0, ROW+1);
        }else if(JR_IsKeyDown(JR_KEY_UP) || JR_IsKeyDown('w') || JR_IsKeyDown('W')){
            if(sys_dir == LEFT || sys_dir == RIGHT){
                sys_dir = UP;
            }
        }else if(JR_IsKeyDown(JR_KEY_DOWN) || JR_IsKeyDown('s') || JR_IsKeyDown('S')){
            if(sys_dir == LEFT || sys_dir == RIGHT){
                sys_dir = DOWN;
            }
        }else if(JR_IsKeyDown(JR_KEY_LEFT) || JR_IsKeyDown('a') || JR_IsKeyDown('A')){
            if(sys_dir == UP || sys_dir == DOWN){
                sys_dir = LEFT;
            }
        }else if(JR_IsKeyDown(JR_KEY_RIGHT) || JR_IsKeyDown('d') || JR_IsKeyDown('D')){
            if(sys_dir == UP || sys_dir == DOWN){
                sys_dir = RIGHT;
            }
        }
        break;
    case PAUSE :
        if(JR_IsKeyDown(JR_KEY_ENTER)){ //resume
            sys_gs = GAMING;
            printf("Continue!\t\t\t\t\t\t");
            JR_SetCursor(0, ROW+1);
        }
        break;
    case STOP:
        break;
    }
}

/* 更新snake */
void updateSnake(void){
    SNAKE ps = NULL;
    if(sys_gs != GAMING) return ;

    //还原BODY
    strcpy(pSnakeTail->node.text, BODY);
    showInBuff(pSnakeTail->node);

    ps = malloc(sizeof(SNAKENODE));
    switch(sys_dir){
    case UP:
        ps->node.x = pSnakeTail->node.x;
        ps->node.y = pSnakeTail->node.y - 1;
        break;
    case DOWN:
        ps->node.x = pSnakeTail->node.x;
        ps->node.y = pSnakeTail->node.y + 1;
        break;
    case LEFT:
        ps->node.x = pSnakeTail->node.x - 2;
        ps->node.y = pSnakeTail->node.y;
        break;
    case RIGHT:
        ps->node.x = pSnakeTail->node.x + 2;
        ps->node.y = pSnakeTail->node.y;
        break;
    }
    strcpy(ps->node.text, BODY);
    AddSNode(ps);
    showInBuff(ps->node);
    if(pSnakeTail->node.x != FOOD.x || pSnakeTail->node.y != FOOD.y){
        blackTail();
    }else{
        TotalScore ++;
        JR_SetCursor(COL*2+9, 0);
        printf("%d", TotalScore);
        GetFood();
        showInBuff(FOOD);
        JR_SetCursor(0, ROW+2);
        printf("Food : %d, %d, %s\t", FOOD.x, FOOD.y, FOOD.text);
    }

    if(!checkSnake()){
        sys_gs = DIE;
        gameOver();
        printf("Game Over! 【1~9】or【Enter】 to continue!【Esc】to esc!\t");
        JR_SetCursor(0, ROW+1);
    }
}

/* 定时器中的功能实现，在ontimer()中自动定时调用 */
void mainTimer(void){
    updateKey();
    updateSnake();
    show();
}

int main()
{
    initGame();
    while(1){
        ontimer();  //定时器处理函数，功能实现在mainTimer()
    }
    gameOver();
    return 0;
}
