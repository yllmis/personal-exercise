/*which 0:主界面 1:难度选择界面 2:制作人员 3:退出游戏
chose 0:难度选择界面 1:单则运算 2:混合运算 3:挑战排行
chose1 0:单则运算界面 1:加法运算 2:减法运算 3:乘法运算 4:除法运算
chose2 0:排行榜 1：挑战模式
page/tapge 排行榜当前页数/总页数
amount 排行榜总人数
user 存放用户信息
que 存放题目信息
right 单则运算答对数 right2 混合运算答对数 right1 挑战排行答对数 
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<easyx.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#define MAX_INPUT 10000000
ExMessage msg;
int mx, my;
int j = 0,numb = 0,right=0,right1=0,right2=0;
int condition = 0,namecase=0;
char input[MAX_INPUT] = { 0 };int index = 0;
int which = 0, chose = 0, chose1 = 0,chose2=0;
int page = 1, tpage = 1, amount = 0,ques=0;
double time1 = 0;
clock_t start, end;//计时
char mainMenu[][20] = { "开始游戏","制作人员","玩法介绍","退出游戏" };
char diffculty[][20] = { "单则运算","混合运算","挑战排行"};
char single[][20] = { "加法运算","减法运算","乘法运算","除法运算" };
struct Resource {
	IMAGE back[2];
	IMAGE sonimg[3];
	IMAGE intro;
}res;
struct Number {
	int a;
	int b;
	int c;
	int d;
	int e;
}num;
struct User {
	char name[20];
	int score;
	double time;
}user[50];
struct Question {
	int a;
	int b;
	int c;
	int d;
	int e;
}que[20];
void Random() {
	srand((unsigned)time(NULL));
	num.a=rand()%100;
	num.b=rand()%100;
}
void Random1() {
	srand((unsigned)time(NULL));
	num.a = rand() % 50+1;
	num.b = rand() % 10+1;
}
void Random2() {
	srand((unsigned)time(NULL));
	num.a = rand() % 11;
	num.b = rand() % 11;
	num.d = rand() % 11;
	num.e = rand() % 11;
}
//获取鼠标坐标
void mouseEvent() {
	if (peekmessage(&msg, EX_MOUSE)) {
		mx = msg.x;
		my = msg.y;
	}
}
//判断鼠标是否在按钮区域
bool contain(int x, int y,int mouse_x, int mouse_y) {
	if (x <= mouse_x && mouse_x <= x + 123 && y <= mouse_y && mouse_y <= y + 35) {
		return true;
	}
	return false;
}
//删除用户
void deleteUser() {
	if (amount == 0) {
		MessageBox(GetHWnd(), _T("暂无用户"), _T("提示"), MB_OK); // 如果不满足条件，弹出错误消息框
		return;
	}
	char name[20];
	InputBox(name, 20, "请输入用户名：", "删除");
	for (int i = 0; i < amount; i++) {
		if (strcmp(user[i].name, name) == 0) {
			for (int j = i; j < amount - 1; j++) {
				user[j] = user[j + 1];// 向前移动
			}MessageBox(GetHWnd(), _T("删除成功\n若不进行挑战，认为恶意删除\n将不存入"), _T("提示"), MB_OK); // 如果满足条件，弹出提示消息框
			amount--;
			return;
		}
	}MessageBox(GetHWnd(), _T("删除失败"), _T("没有这个人"), MB_OK); // 如果不满足条件，弹出错误消息框
}
//查询用户
void searchUser() {
	if (amount == 0) {
		MessageBox(GetHWnd(), _T("暂无用户"), _T("提示"), MB_OK); // 如果不满足条件，弹出错误消息框
		return;
	}
	char name[20];
	InputBox(name, 20, "请输入用户名：", "查询");
	for (int i = 0; i < amount; i++) {
		if (strcmp(user[i].name, name) == 0) {
			MessageBox(GetHWnd(), _T("查询成功"), _T("提示"), MB_OK); // 如果满足条件，弹出提示消息框
			char str[100000];
			sprintf(str, "排名：%d\n用户名：%s\n分数：%d\n用时：%.2lf秒",i+1,user[i].name, user[i].score, user[i].time);
			MessageBox(GetHWnd(), str, _T("用户信息"), MB_OK); // 弹出用户信息
			return;
		}
	}MessageBox(GetHWnd(), _T("查询失败"), _T("没有这个人"), MB_OK); // 如果不满足条件，弹出错误消息框
}
//鼠标点击事件
void mouseClick(ExMessage* msg) {
	int ty = 250;
	mouseEvent();
	if (msg->message == WM_LBUTTONDOWN) {
		//主界面点击
		if (which == 0) {
			if (contain(190, ty, mx, my) && which == 0) {
				which = 1;
				mx = 0;
				my = 0;
			}
			else if (contain(190, ty + 80, mx, my) && which == 0) {
				which = 2;
				mx = 0;
				my = 0;
			}
			else if (contain(190, ty + 160, mx, my) && which == 0) {
				which = 3;
			}
			else if (contain(190, ty + 240, mx, my) && which == 0) {
				which = 4;
			}
		}
		//难度选择界面点击
		else if(which==1&&chose==0){
			if (contain(400, 550, mx, my)) {
				which = 0;
			}
			else if (contain(190, ty, mx, my)) {
				chose = 1;
				mx = 0;
				my = 0;
			}
			else if (contain(190, ty + 80, mx, my)) {
				chose = 2;
				mx = 0;
				my = 0;
			}
			else if (contain(190, ty + 160, mx, my)&&right2>=10) {
				chose = 3;
				mx = 0;
				my = 0;
			}
		}
		//单则运算界面点击
		else if (which == 1 && chose == 1&&chose1==0) {
			if (contain(400, 550, mx, my)) {
				which = 1;
				chose = 0;
				mx = 0;
				my = 0;
			}
			else if (contain(190, ty, mx, my)) {
				chose1 = 1;
			}
			else if (contain(190, ty + 80, mx, my)) {
				chose1 = 2;
			}
			else if (contain(190, ty + 160, mx, my)) {
				chose1 = 3;
			}
			else if (contain(190, ty + 240, mx, my)) {
				chose1 = 4;
			}
		}
		else if (chose1 != 0) {
			if (contain(330, 400, mx, my)) {
				chose1 = 0;
				mx = 0;
				my = 0;
			}
		}
		//混合运算界面点击
		else if (chose== 2) {
			if (contain(330, 400, mx, my)) {
				chose = 0;
				right = 0;
				mx = 0;
				my = 0;
			}
		}
		//排行榜界面点击
		else if (chose==3) {
			if (contain(430, 250, mx, my)) {
				deleteUser();
			}
			if (contain(430, 350, mx, my)) {
				searchUser();
			}
			if (contain(65, 550, mx, my)) {
				if (chose2 == 0) {
					chose = 0;//返回难度界面
					namecase = 0;
				}
				else if (chose2 == 1&&ques>=10) {
					chose2 = 0;//返回排行榜
					namecase = 0;
					mx = 0;
					my = 0;
				}
			}
			else if (contain(350, 550, mx, my)&&page<tpage) {
				page++;
				mx = 0;
				my = 0;
			}
			else if (contain(240, 550, mx, my)&&page>1) {
				page--;
				mx = 0;
				my = 0;
			}
			else if (contain(170, 550, mx, my)) {
				chose2 = 1;
				namecase = 1;
				mx = 0;
				my = 0;
			}
		}
		//Creator界面点击,玩法介绍
		else if (which == 2||which == 3) {
			if (contain(100, 550, mx, my)) {
				which = 0;
			}
		}
	}
}
//绘制文本框
void drawText(char* input) {
		fillrectangle(90, 180, 400, 300);
		outtextxy(120, 200, "请输入答案：");
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // 回车
			input[index] = 13;
			Sleep(200);
		}
		else if (GetAsyncKeyState(VK_BACK) & 0x8000) { // 退格
			if (index > 0) {
				index--;
				input[index] = '\0';
				Sleep(200);
			}
		}
		else {
			for (int i = '0'; i <= '9'; i++) {
				if (GetAsyncKeyState(i) & 0x8000) { // 数字
					if (index < MAX_INPUT - 1) {
						input[index] = i;
						index++;
						Sleep(200);
					}
				}
			}
		}
		settextcolor(BLACK);
		outtextxy(120, 240, input);
}
//游戏背景
void back1() {
	setbkcolor(WHITE);
	char str1[100000];
	sprintf(str1, "%d", right);
	settextstyle(22, 0, "黑体");
	outtextxy(380, 20, "正确个数：");
	outtextxy(380, 40, str1);
	settextstyle(32, 0, "黑体");
	loadimage(&res.back[1], _T("口算背景.jpg"), 380, 500);
	putimage(60, 120, &res.back[1]);
}
void back2() {
	setbkcolor(WHITE);
	char str1[100000];
	sprintf(str1, "%d", right2);
	settextstyle(22, 0, "黑体");
	outtextxy(380, 20, "正确个数：");
	outtextxy(380, 40, str1);
	settextstyle(32, 0, "黑体");
	loadimage(&res.back[1], _T("口算背景.jpg"), 380, 500);
	putimage(60, 120, &res.back[1]);
}
//玩法介绍界面
void Introduction() {
	loadimage(&res.intro, _T("玩法介绍.png"), 400, 400);
	putimage(50, 150, &res.intro);
	mouseEvent();
	if (contain(100, 550, mx, my)) {
		setbkmode(OPAQUE);
		setbkcolor(LIGHTGRAY);
		settextcolor(RED);
		outtextxy(100, 550, "返回");
		setbkmode(TRANSPARENT);
	}outtextxy(100, 550, "返回");
}
//加法
void increase() {
	num.c = num.a + num.b;
	back1();
	char str[100000];
	sprintf(str, "%d", num.a);
	outtextxy(80, 140, str);
	outtextxy(160, 140, "+");
	sprintf(str, "%d", num.b);
	outtextxy(190, 140, str);
	outtextxy(260, 140, "=");
	if (right >= 5) {
		mouseEvent();
		outtextxy(330, 400, "返回");
		mouseClick(&msg);
	}
}
//减法
void decrease() {
	num.c = num.a - num.b;
	back1();
	char str[100000];
	sprintf(str, "%d", num.a);
	outtextxy(80, 140, str);
	outtextxy(160, 140, "-");
	sprintf(str, "%d", num.b);
	outtextxy(190, 140, str);
	outtextxy(260, 140, "=");
	if (right >= 5) {
		mouseEvent();
		outtextxy(330, 400, "返回");
		mouseClick(&msg);
	}
}
//乘法
void multiply() {
	num.c = num.a * num.b;
	back1();
	char str[100000];
	sprintf(str, "%d", num.a);
	outtextxy(80, 140, str);
	outtextxy(160, 140, "X");
	sprintf(str, "%d", num.b);
	outtextxy(190, 140, str);
	outtextxy(260, 140, "=");
	if (right >= 5) {
		mouseEvent();
		outtextxy(330, 400, "返回");
		mouseClick(&msg);
	}
}
//除法
void divide() {
	num.c = num.a / num.b;
	back1();
	char str[100000];
	sprintf(str, "%d", num.a);
	outtextxy(80, 140, str);
	outtextxy(160, 140, "/");
	sprintf(str, "%d", num.b);
	outtextxy(190, 140, str);
	outtextxy(260, 140, "=");
	if (right >= 5) {
		mouseEvent();
		outtextxy(330, 400, "返回");
		mouseClick(&msg);
	}
}
//背景
void background() {
	loadimage(&res.back[0], _T("口算.jpg"), getwidth(), getheight());
	putimage(0, 0, &res.back[0]);
	setbkmode(TRANSPARENT);//设置背景透明
	settextcolor(BLACK);
	settextstyle(45, 0, "华文琥珀");
	outtextxy(175, 50, "口算游戏");
	setbkmode(OPAQUE);
}
//菜单界面
void menu(){
	int ty = 250;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	settextstyle(32, 0, "华文琥珀");
	for (int i = 0; i < 4; i++) {
		mouseEvent();
		if (contain(190,ty+i*80,mx,my)) {
			setbkcolor(RED); //悬停颜色
			settextcolor(WHITE); //悬停字体颜色
			outtextxy(190, ty + i * 80, mainMenu[i]);
			setbkcolor(WHITE); //悬停颜色恢复
			settextcolor(BLACK); //悬停字体颜色恢复
			continue;
		}
		outtextxy(190, ty + i * 80, mainMenu[i]);
	}
}
//制作人员界面
void Creator() {
	setbkmode(TRANSPARENT);
	outtextxy(100, 100, "制作人员：");
	loadimage(&res.sonimg[1], _T("介绍.png"), 300, 400);
	putimage(100, 150, &res.sonimg[1]);
	mouseEvent();
	if (contain(100, 550, mx, my)) {
		setbkmode(OPAQUE);
		setbkcolor(LIGHTGRAY);
		settextcolor(RED);
		outtextxy(100, 550, "返回");
		setbkmode(TRANSPARENT);
	}outtextxy(100, 550, "返回");
}
//难度选择界面
void Chose() {
	int ty = 250;
	settextstyle(30, 0, "黑体");
	settextcolor(LIGHTRED);
	setbkmode(TRANSPARENT);
	outtextxy(75, 150, "选择难度：");
	settextstyle(32, 0, "华文琥珀");
	for (int i = 0; i < 3; i++) {
		mouseEvent();
		if (contain(190, ty + i * 80, mx, my)) {
			setbkmode(OPAQUE);
			setbkcolor(BLACK);
			settextcolor(RED);
			outtextxy(190, ty + i * 80, diffculty[i]);
			if (i == 2&&condition<10) {
				outtextxy(120, ty + 220, "需在混合运算中答对10题");
				char str[100000];
				sprintf(str, "%d", condition);
				outtextxy(120, ty + 260, str);
				outtextxy(150, ty + 260, "/10");
			}
			setbkcolor(LIGHTGRAY); //悬停颜色恢复
			settextcolor(WHITE); //悬停字体颜色恢复
			continue;
		}setbkcolor(LIGHTGRAY); 
		settextcolor(WHITE);
		setbkmode(OPAQUE);
		outtextxy(190, ty + i*80, diffculty[i]);
	}
	if (contain(400, 550, mx, my)) {
		setbkcolor(RED);
		settextcolor(BLACK);
		outtextxy(400, 550, "返回");
	}outtextxy(400, 550, "返回");
}
//单则运算
void Single(){
	int ty = 250;
	settextstyle(30, 0, "黑体");
	settextcolor(LIGHTRED);
	setbkmode(TRANSPARENT);
	outtextxy(75, 150, "选择难度：");
	settextstyle(32, 0, "华文琥珀");
	for (int i = 0; i < 4; i++) {
		mouseEvent();
		if (contain(190, ty + i * 80, mx, my)) {
			setbkmode(OPAQUE);
			setbkcolor(BLACK);
			settextcolor(RED);
			outtextxy(190, ty + i * 80, single[i]);
			setbkcolor(LIGHTGRAY); //悬停颜色恢复
			settextcolor(WHITE); //悬停字体颜色恢复
			continue;
		}setbkcolor(LIGHTGRAY);
		settextcolor(WHITE);
		setbkmode(OPAQUE);
		outtextxy(190, ty + i * 80, single[i]);
	}
	if (contain(400, 550, mx, my)) {
		setbkcolor(RED);
		settextcolor(BLACK);
		outtextxy(400, 550, "返回");
	}outtextxy(400, 550, "返回");

}
//混合运算
int condition1=0;
void Mix(){
	back2();
	if (condition1 < 3) {
		num.c=num.a+num.b*num.d+num.e;
		char str[100000];
		sprintf(str, "%d", num.a);
		outtextxy(80, 140, str);
		outtextxy(120, 140, "+");
		sprintf(str, "%d", num.b);
		outtextxy(160, 140, str);
		outtextxy(200, 140, "X");
		sprintf(str, "%d", num.d);
		outtextxy(220, 140, str);
		outtextxy(280, 140, "+");
		sprintf(str, "%d", num.e);
		outtextxy(320, 140, str);
		outtextxy(360, 140, "=");
	}
	else if (condition1 < 6 && condition1 >= 3) {
		num.c = num.a*(num.b+num.d) + num.e;
		char str[100000];
		sprintf(str, "%d", num.a);
		outtextxy(80, 140, str);
		outtextxy(120, 140, "X");
		outtextxy(140, 140, "(");
		sprintf(str, "%d", num.b);
		outtextxy(160, 140, str);
		outtextxy(200, 140, "+");
		sprintf(str, "%d", num.d);
		outtextxy(220, 140, str);
		outtextxy(260, 140, ")");
		outtextxy(280, 140, "+");
		sprintf(str, "%d", num.e);
		outtextxy(320, 140, str);
		outtextxy(360, 140, "=");
	}
	else if(condition1 >= 6&&condition1 < 10){
		num.c = num.a * (num.b - num.d) + num.e;
		char str[100000];
		sprintf(str, "%d", num.a);
		outtextxy(80, 140, str);
		outtextxy(120, 140, "X");
		outtextxy(140, 140, "(");
		sprintf(str, "%d", num.b);
		outtextxy(160, 140, str);
		outtextxy(200, 140, "-");
		sprintf(str, "%d", num.d);
		outtextxy(220, 140, str);
		outtextxy(260, 140, ")");
		outtextxy(280, 140, "+");
		sprintf(str, "%d", num.e);
		outtextxy(320, 140, str);
		outtextxy(360, 140, "=");
		if (condition1 == 9) condition1 = 0;
	}
	if (condition>=1) {
		mouseEvent();
		outtextxy(330, 400, "返回");
		mouseClick(&msg);
	}
}
//排行榜
void drawTable() {
	if (amount <= 0) {
		FILE* fp = fopen("rank.txt", "r");
		if (fp == NULL) {
			outtextxy(200, 200, "暂无排行榜");
			return;
		}
		char buffer[1000];
		while (fgets(buffer, 1000, fp) != NULL) {
			amount++;
		}rewind(fp);	
		for (int i = 0; i < amount; i++) {
			if (fscanf_s(fp, "%99s %d %lf", &user[i].name, (unsigned)_countof(user[i].name), &user[i].score, &user[i].time) != 3) {
				// 读取失败，可以处理错误
				break;
			}
		}fclose(fp);
	}if (amount > 7) {
		if (amount % 7 != 0) {
			tpage = amount / 7 + 1;
		}
		else {
			tpage = amount / 7;
		}
	}
	//冒泡排序
	for (int i = 1; i <= amount - 1; i++) {
		for (int j = 0; j < amount - i; j++) {
			if (user[j].score < user[j + 1].score) {
				User temp = user[j];
				user[j] = user[j + 1];
				user[j + 1] = temp;
			}
			else if (user[j].score == user[j + 1].score) {
				if (user[j].time > user[j + 1].time) {
					User temp = user[j];
					user[j] = user[j + 1];
					user[j + 1] = temp;
				}
			}
		}
	}
	setbkmode(TRANSPARENT);
	settextstyle(26, 0, "黑体");
	outtextxy(40, 150, "排名		姓名    题数   用时");
	for (int i = 0; i < 7; i++) {
		for (int k = 0; k < 3; k++) {
			setlinecolor(BLACK);
			int left = 100 + k * 90;
			int top = 200 + i * 40;
			int right = left + 90;
			int bottom = top + 40;
			rectangle(left, top, right, bottom);
		}
	}
	for (int i = page; i <= page; i++) {
		if (amount <7) {
			char str[100000];
			for (int k = 0; k < amount; k++) {
				outtextxy(110, 210 + k * 40, user[k].name);
				sprintf(str, "%d", k+1);
				outtextxy(40, 210 + k * 40,str);
				sprintf(str, "%d", user[k].score);
				outtextxy(200, 210 + k* 40, str);
				sprintf(str, "%.2f", user[k].time);
				outtextxy(300, 210 + k * 40, str);
			}
		}
		else {
			if (page != tpage) {
				for (int k = (i-1)*7; k < (i-1)*7+7; k++) {
					outtextxy(110, 210 + (k-7*(page-1)) * 40, user[k].name);
					char str[100000];
					sprintf(str, "%d", k+1);
					outtextxy(40, 210 + (k-7*(page-1)) * 40,str);
					sprintf(str, "%d", user[k].score);
					outtextxy(200, 210 + (k-7*(page-1)) * 40, str);
					sprintf(str, "%.2f", user[k].time);
					outtextxy(300, 210 + (k-7*(page-1)) * 40, str);
				}
			}
			else {
				for (int k = (tpage-1)*7; k < amount; k++) {
					outtextxy(110, 210 + (k-7*(page-1)) * 40, user[k].name);
					char str[100000];
					sprintf(str, "%d", k+1);
					outtextxy(40, 210 + (k-7*(page-1)) * 40,str);
					sprintf(str, "%d", user[k].score);
					outtextxy(200, 210 + (k-7*(page-1)) * 40, str);
					sprintf(str, "%.2f", user[k].time);
					outtextxy(300, 210 + (k-7*(page-1)) * 40, str);
				}
			}
		}
	}
}
//挑战赛
void Race() {
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "黑体");
	settextcolor(LIGHTRED);
	outtextxy(10, 100, "挑战赛");
	char str1[100000];
	sprintf(str1, "%d/10", ques+1);
	settextstyle(22, 0, "黑体");
	outtextxy(320, 20, "已做：");
	outtextxy(400, 20, str1);
	FILE* fp1 = fopen("排行榜题.txt", "r");
	if (fp1 == NULL) {
		outtextxy(200, 200, "暂无题目");
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (fscanf_s(fp1, "%d %d %d %d %d", &que[i].a,&que[i].b,&que[i].d,&que[i].e,&que[i].c) != 5) {
			// 读取失败，可以处理错误
			break;
		}
	}fclose(fp1);
	if (ques == 0) {
		start = clock();
	}
		char str[100];
		if (ques < 3) {
			sprintf(str, "%d", que[ques].a);
			outtextxy(80, 140, str);
			outtextxy(120, 140, "X");
			sprintf(str, "%d", que[ques].b);
			outtextxy(160, 140, str);
			outtextxy(200, 140, "+");
			sprintf(str, "%d", que[ques].d);
			outtextxy(220, 140, str);
			outtextxy(280, 140, "-");
			sprintf(str, "%d", que[ques].e);
			outtextxy(320, 140, str);
			outtextxy(360, 140, "=");
		}
		else if (ques < 5) {
			sprintf(str, "%d", que[ques].a);
			outtextxy(80, 140, str);
			outtextxy(120, 140, "-");
			sprintf(str, "%d", que[ques].b);
			outtextxy(160, 140, str);
			outtextxy(200, 140, "X");
			sprintf(str, "%d", que[ques].d);
			outtextxy(220, 140, str);
			outtextxy(280, 140, "+");
			sprintf(str, "%d", que[ques].e);
			outtextxy(320, 140, str);
			outtextxy(360, 140, "=");
		}
		else if (ques < 9) {
			sprintf(str, "%d", que[ques].a);
			outtextxy(80, 140, str);
			outtextxy(120, 140, "/");
			sprintf(str, "%d", que[ques].b);
			outtextxy(160, 140, str);
			outtextxy(200, 140, "+");
			sprintf(str, "%d", que[ques].d);
			outtextxy(220, 140, str);
			outtextxy(280, 140, "-");
			sprintf(str, "%d", que[ques].e);
			outtextxy(320, 140, str);
			outtextxy(360, 140, "=");
		}
		else if(ques<10){
			sprintf(str, "%d", que[ques].a);
			outtextxy(80, 140, str);
			outtextxy(120, 140, "-");
			sprintf(str, "%d", que[ques].b);
			outtextxy(160, 140, str);
			outtextxy(200, 140, "/");
			sprintf(str, "%d", que[ques].d);
			outtextxy(220, 140, str);
			outtextxy(280, 140, "+");
			sprintf(str, "%d", que[ques].e);
			outtextxy(320, 140, str);
			outtextxy(360, 140, "=");
		}
		else {
			if (end == 0) {
				end = clock();
				time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
			}
			user[amount-1].score = right1;
			user[amount-1].time = time1;
			settextstyle(32, 0, "华文琥珀");
			outtextxy(150, 300, "挑战结束");
			outtextxy(150, 350, "得分：");
			outtextxy(150, 400, "用时：");
			char str2[100000];
			sprintf(str2, "%d", right1);
			outtextxy(240, 350, str2);
			sprintf(str2, "%.2f", time1);
			outtextxy(240, 400, str2);
			FILE* fp = fopen("rank.txt", "w");
			if (fp == NULL) {
				outtextxy(200, 200, "排行榜写入失败");
				return;
			}
			for (int i = 0; i < amount; i++) {
				fprintf_s(fp, "%s %d %.2f\n", user[i].name, user[i].score, user[i].time);
			}fclose(fp);
		settextstyle(32, 0, "华文琥珀");
		outtextxy(100, 550, "返回");
		}
}
//挑战排行
void Chanllenge() {
	switch (chose2) {
	case 0: {
		drawTable();
		char page1[1000];
		sprintf(page1, "%d", page);
		outtextxy(400, 520, page1);
		sprintf(page1, "/%d", tpage);
		outtextxy(450, 520, page1);
		outtextxy(100, 550, "返回");
		outtextxy(350, 550, "下一页");
		outtextxy(190, 550, "挑战");
		outtextxy(430, 250, "删除");
		outtextxy(430, 350, "查询");
		if (page != 1) {
			outtextxy(250, 550, "上一页");
		}break;
	}
	case 1: {
		if (namecase != 0) {
			char name[20];
			InputBox(name, 20, "请注册姓名：","注册");
			for (int i = 0; i < amount; i++) {
				if (strcmp(user[i].name, name) == 0) {
					MessageBox(GetHWnd(), _T("若想继续，请先删除"), _T("用户已存在"), MB_OK); // 如果不满足条件，弹出错误消息框
					chose2 = 0;
					namecase = 0;
					return;
				}
				else if (name[0] == '\0') {
					MessageBox(GetHWnd(), _T("姓名不能为空"), _T("错误"), MB_OK); // 如果不满足条件，弹出错误消息框
					chose2 = 0;
					namecase = 0;
					return;
				}
			}if (namecase == 1) {
				strcpy(user[amount].name, name);
				amount++;
				namecase = 0;
			}
		}
		Race();
		if (ques <10) {
			if (input[index] == 13) {
				input[index] = '\0';
				int ans = atoi(input);
				if (ans == que[ques].c) {
					outtextxy(150, 400, "回答正确！");
					ques++; right1++;
					index = 0;
					memset(input, '\0', sizeof(input));
				}
				else if (ans != num.c) {
					outtextxy(150, 400, "回答错误！");
					ques++;
					index = 0;
					memset(input, '\0', sizeof(input));
				}
			}drawText(input);
		}
		break;
	}
	}
		
}
//主函数
int main() {
	int count = 0;
	//初始化界面
	initgraph(500, 650);
	//双缓冲绘图
	BeginBatchDraw();
	while (count == 0) {
		//清屏
		cleardevice();
		background();
		mouseClick(&msg);
		if (which == 0) {
			menu();
		}
		//难度选择界面
		else if (which == 1) {
			switch (chose) {
			case 0:
				Chose();
				break;
			//单则运算
			case 1: {
				if (chose1 == 0) {
					Single();
					j = 0;
					numb = 0;
					right = 0;
				}
				switch (chose1) {
				//加法运算
				case 1: {				
					for (j; j <= numb;) {
						Random();
						j++;
					}
					increase();
					if (input[index] == 13) {
						input[index] = '\0';
						int ans = atoi(input);
						if (ans == num.c) {
							outtextxy(150, 400, "回答正确！");
							numb++;
							right++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
						else if (ans != num.c) {
							outtextxy(150, 400, "回答错误！");
							numb++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
					}
					drawText(input);
					break;
				}
				//减法运算	
				case 2: {
					for (j; j <= numb;) {
						Random();
						while (num.a < num.b) {
							Random();
						}
						j++;
					}
					decrease();
					if (input[index] == 13) {
						input[index] = '\0';
						int ans = atoi(input);
						if (ans == num.c) {
							outtextxy(150, 400, "回答正确！");
							numb++;
							right++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
						else if (ans != num.c) {
							outtextxy(150, 400, "回答错误！");
							numb++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
					}
					drawText(input);
					break;
				}
				//乘法运算
				case 3: {
					
					for (j; j <= numb;) {
						Random1();
						j++;
					}
					multiply();
					if (input[index] == 13) {
						input[index] = '\0';
						int ans = atoi(input);
						if (ans == num.c) {
							outtextxy(150, 400, "回答正确！");
							numb++;
							right++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
						else if (ans != num.c) {
							outtextxy(150, 400, "回答错误！");
							numb++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
					}
					drawText(input);
					break;
				}
				//除法运算
				case 4: {
					for (j; j <= numb;) {
						Random1();
						while (num.b == 0 || num.a % num.b != 0) {
							Random1();
						}
						j++;
					}
					divide();
					if (input[index] == 13) {
						input[index] = '\0';
						int ans = atoi(input);
						if (ans == num.c) {
							outtextxy(150, 400, "回答正确！");
							numb++;
							right++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
						else if (ans != num.c) {
							outtextxy(150, 400, "回答错误！");
							numb++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
					}
				}
					drawText(input);
					break;
				}
				break;
			}
			//混合运算
			case 2: {
				for (j; j <= numb;) {
					Random2();
					while (condition1>=6&&num.b < num.d) {
						Random2();
					}
					j++;
				}
				Mix();
				if (input[index] == 13) {
					input[index] = '\0';
					int ans = atoi(input);
					if (ans == num.c) {
						outtextxy(150, 400, "回答正确！");
						numb++;
						right2++;
						condition++;condition1++;
						index = 0;
						memset(input, '\0', sizeof(input));
					}
					else if (ans != num.c) {
						outtextxy(150, 400, "回答错误！");
						numb++;
						condition1++;
						index = 0;
						memset(input, '\0', sizeof(input));
					}
				}
				drawText(input);
				break;
			}
			 //挑战排行
			case 3:
				Chanllenge();
				break;
			}
		}
		//制作人员界面
		else if (which == 2) {
			Creator();
		}
		//玩法介绍
		else if (which == 3) {
			Introduction();
		}
		else if (which == 4) {
			loadimage(&res.sonimg[2], _T("感谢.png"), getwidth(), getheight());
			putimage(0, 0, &res.sonimg[2]);
			count = 1;
		}
		//界面刷新
		FlushBatchDraw();
	}
	Sleep(3000);
	exit(0);
	return 0;
}