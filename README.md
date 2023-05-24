## 编写和测试任意长的整数类ヾ(≧▽≦*)o

> ##### author: 吴荣榜_222200314_MEWWW
>
> ##### 福州大学软件工程大一下学期C++第三次大作业
>
> ##### 教师：王灿辉

### 问题描述

C/C++程序中的整数型变量能够表示的数字大小是有限制的，而现实中常常需要用到更大的整数，为此必须设计用户自定义的大整数类。要求用C++编程实现两个任意长的整数(
包括正数和负数)求和运算及其它运算。

### 功能

- 支持多种构造方式，包括字符串构造和长整型构造

- 支持任意长整数的加法、减法、乘法、除法、取模等运算
- 支持任意长整数的2-16进制的相互转换
- 支持两个超大整数之间的六个关系运算符的判断
- 支持绝对值功能
- 支持赋值运算和复合运算
- 支持实时显示本机时间

### 特性

- 采用万进制，提高了空间效率和时间效率
- 对各种四则运算的处理进行算法优化，大幅提高了运算速度
- 抛弃传统菜单模式，采用分页输出模式，用户按任意键即可进入下一页
- 程序界面采取多种颜色进行区分输出，更加美观清晰
- 轻量级应用，可在各种主流windows版本下轻松运行