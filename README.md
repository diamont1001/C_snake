# C语言写的字符界面贪吃蛇 - 不闪屏

![](https://raw.githubusercontent.com/diamont1001/C_snake/0892ea08817bb7ba7b99fca1ce5fd26c24a76408/docs/Kapture%202021-08-02%20at%2014.37.11.gif)

之前在网上下载了几位网友的贪吃蛇，看了下，觉得屏幕好闪，因为他们很多人都是用 `system("cls")` 来刷新屏幕的，所以难免会闪。在下一时兴致大发，也写了个，用 WIN—API 函数来控制光标输出，去除了闪屏的问题。有需要的童鞋欢迎下载交流。^_^


1. 该小游戏并没有引用到任何第三方库，完全是调用标准C的库函数和WIN-API函数的。
2. 该小游戏引用到之前封装好的几个函数：定时器、随机数、键盘响应、光标移动，所以也可以作为以上几个函数的一个例子。
3. 字符界面：屏幕根据“按需刷新”原则，每次只是刷新有变化的区域。总体上个人感觉还不错啦，哈哈！
4. 代码设计：状态加定时器驱动，个人感觉可以满足大多数单线程小游戏的开发。

环境：`code::blocks + MinGW`

PS:有的朋友用VS或者VC打开，发现编译不过，是因为编译器不同，VS要求比较严格，声明和定义一定要放到前面，解决方法：在 `JR_timer.c`里面，把以下这句放到函数或者文件的前面就行了： `extern void mainTimer();`

## 附

 - [游戏试玩](http://download.csdn.net/download/diamont1001/3033102)
 - [原 CSDN 资源下载地址](http://download.csdn.net/download/diamont1001/3032070)
 
