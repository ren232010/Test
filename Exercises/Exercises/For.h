#pragma once
#include <iostream>


class For
{
public:
	For();
	~For();
};

/*求1-100之间所有偶数的和？ */

void Sum();

/*找出100 - 999 之间的水仙花数。
例如：153 = 1*1*1+5*5*5+3*3*3*/


void NarcissisticNumber();   //水仙花数


//If Else If-------------------------------------
//从3个数中找出最大的数，不考虑相等。
float Max(float,float,float);

/*提示用户输入密码，如果密码是“88888”则提示正确，否则要求再输入一次，
如果密码是“88888”则提示正确，否则提示错误，程序结束。*/



void PassWord();
/*提示用户输入用户名，然后再提示输入密码，如果用户名是“admin”，并且
密码是“88888”，则提示正确，否则，如果用户名不是admin还提示用户用户名
不存在，如果用户名是admin则提示密码错误*/
void PassName();

/*提示用户输入密码，如果输入的密码是“888888”，则在控制台打印“登陆成功”，否则
打印“密码错误”。*/

bool PassWord(std::string);

/*输入一个整数，如果这个数是偶数，则打印“Your input is even”，否则打印“Your
 input is odd”*/

void Judge(int);

/*输入年龄，如果年龄在10-18或者25-30范围内，
输出“可以访问”，否则，输出“拒绝访问”*/

void visitByAge();

/*编写一个程序接受用户输入的字符。如果输入的字符是0-9数字中的一个，
则显示“您输入了一个数字”，否则显示这不是一个数字”*/

void JudgeNum();




