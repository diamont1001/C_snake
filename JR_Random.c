/*
* JR_Random.c (1.0)
* 随机数
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-11
*/

#include <time.h>
#include "JR_Random.h"

#define JR_RANDOM_NUM   100

static int RandomPool[JR_RANDOM_NUM];
static int JR_index = JR_RANDOM_NUM;

static void JR_InitRandom(){
    int i = 0;
    if(JR_index != JR_RANDOM_NUM) return ;

    JR_index = 0;
    memset(RandomPool, 0, sizeof(RandomPool));
    srand(time(0) + rand());
    for(i=0; i<JR_RANDOM_NUM; i++)
        RandomPool[i] = rand();
}

/* 取随机数 */
int JR_random(void){
    JR_InitRandom();
    return (RandomPool[JR_index++]);
}
/* 取0到max的随机数 [0, max] */
int JR_randomIn(int max){
    JR_InitRandom();
    return (RandomPool[JR_index++] % (max+1));
}
/* 取指定范围随机数 [min, max] */
int JR_randomRange(int min, int max){
    JR_InitRandom();
    return ( min + (RandomPool[JR_index++] % (max-min+1)) );
}
