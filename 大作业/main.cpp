/*which 0:������ 1:�Ѷ�ѡ����� 2:������Ա 3:�˳���Ϸ
chose 0:�Ѷ�ѡ����� 1:�������� 2:������� 3:��ս����
chose1 0:����������� 1:�ӷ����� 2:�������� 3:�˷����� 4:��������
chose2 0:���а� 1����սģʽ
page/tapge ���а�ǰҳ��/��ҳ��
amount ���а�������
user ����û���Ϣ
que �����Ŀ��Ϣ
right ������������ right2 ����������� right1 ��ս���д���� 
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
clock_t start, end;//��ʱ
char mainMenu[][20] = { "��ʼ��Ϸ","������Ա","�淨����","�˳���Ϸ" };
char diffculty[][20] = { "��������","�������","��ս����"};
char single[][20] = { "�ӷ�����","��������","�˷�����","��������" };
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
//��ȡ�������
void mouseEvent() {
	if (peekmessage(&msg, EX_MOUSE)) {
		mx = msg.x;
		my = msg.y;
	}
}
//�ж�����Ƿ��ڰ�ť����
bool contain(int x, int y,int mouse_x, int mouse_y) {
	if (x <= mouse_x && mouse_x <= x + 123 && y <= mouse_y && mouse_y <= y + 35) {
		return true;
	}
	return false;
}
//ɾ���û�
void deleteUser() {
	if (amount == 0) {
		MessageBox(GetHWnd(), _T("�����û�"), _T("��ʾ"), MB_OK); // �������������������������Ϣ��
		return;
	}
	char name[20];
	InputBox(name, 20, "�������û�����", "ɾ��");
	for (int i = 0; i < amount; i++) {
		if (strcmp(user[i].name, name) == 0) {
			for (int j = i; j < amount - 1; j++) {
				user[j] = user[j + 1];// ��ǰ�ƶ�
			}MessageBox(GetHWnd(), _T("ɾ���ɹ�\n����������ս����Ϊ����ɾ��\n��������"), _T("��ʾ"), MB_OK); // �������������������ʾ��Ϣ��
			amount--;
			return;
		}
	}MessageBox(GetHWnd(), _T("ɾ��ʧ��"), _T("û�������"), MB_OK); // �������������������������Ϣ��
}
//��ѯ�û�
void searchUser() {
	if (amount == 0) {
		MessageBox(GetHWnd(), _T("�����û�"), _T("��ʾ"), MB_OK); // �������������������������Ϣ��
		return;
	}
	char name[20];
	InputBox(name, 20, "�������û�����", "��ѯ");
	for (int i = 0; i < amount; i++) {
		if (strcmp(user[i].name, name) == 0) {
			MessageBox(GetHWnd(), _T("��ѯ�ɹ�"), _T("��ʾ"), MB_OK); // �������������������ʾ��Ϣ��
			char str[100000];
			sprintf(str, "������%d\n�û�����%s\n������%d\n��ʱ��%.2lf��",i+1,user[i].name, user[i].score, user[i].time);
			MessageBox(GetHWnd(), str, _T("�û���Ϣ"), MB_OK); // �����û���Ϣ
			return;
		}
	}MessageBox(GetHWnd(), _T("��ѯʧ��"), _T("û�������"), MB_OK); // �������������������������Ϣ��
}
//������¼�
void mouseClick(ExMessage* msg) {
	int ty = 250;
	mouseEvent();
	if (msg->message == WM_LBUTTONDOWN) {
		//��������
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
		//�Ѷ�ѡ�������
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
		//�������������
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
		//������������
		else if (chose== 2) {
			if (contain(330, 400, mx, my)) {
				chose = 0;
				right = 0;
				mx = 0;
				my = 0;
			}
		}
		//���а������
		else if (chose==3) {
			if (contain(430, 250, mx, my)) {
				deleteUser();
			}
			if (contain(430, 350, mx, my)) {
				searchUser();
			}
			if (contain(65, 550, mx, my)) {
				if (chose2 == 0) {
					chose = 0;//�����ѶȽ���
					namecase = 0;
				}
				else if (chose2 == 1&&ques>=10) {
					chose2 = 0;//�������а�
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
		//Creator������,�淨����
		else if (which == 2||which == 3) {
			if (contain(100, 550, mx, my)) {
				which = 0;
			}
		}
	}
}
//�����ı���
void drawText(char* input) {
		fillrectangle(90, 180, 400, 300);
		outtextxy(120, 200, "������𰸣�");
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // �س�
			input[index] = 13;
			Sleep(200);
		}
		else if (GetAsyncKeyState(VK_BACK) & 0x8000) { // �˸�
			if (index > 0) {
				index--;
				input[index] = '\0';
				Sleep(200);
			}
		}
		else {
			for (int i = '0'; i <= '9'; i++) {
				if (GetAsyncKeyState(i) & 0x8000) { // ����
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
//��Ϸ����
void back1() {
	setbkcolor(WHITE);
	char str1[100000];
	sprintf(str1, "%d", right);
	settextstyle(22, 0, "����");
	outtextxy(380, 20, "��ȷ������");
	outtextxy(380, 40, str1);
	settextstyle(32, 0, "����");
	loadimage(&res.back[1], _T("���㱳��.jpg"), 380, 500);
	putimage(60, 120, &res.back[1]);
}
void back2() {
	setbkcolor(WHITE);
	char str1[100000];
	sprintf(str1, "%d", right2);
	settextstyle(22, 0, "����");
	outtextxy(380, 20, "��ȷ������");
	outtextxy(380, 40, str1);
	settextstyle(32, 0, "����");
	loadimage(&res.back[1], _T("���㱳��.jpg"), 380, 500);
	putimage(60, 120, &res.back[1]);
}
//�淨���ܽ���
void Introduction() {
	loadimage(&res.intro, _T("�淨����.png"), 400, 400);
	putimage(50, 150, &res.intro);
	mouseEvent();
	if (contain(100, 550, mx, my)) {
		setbkmode(OPAQUE);
		setbkcolor(LIGHTGRAY);
		settextcolor(RED);
		outtextxy(100, 550, "����");
		setbkmode(TRANSPARENT);
	}outtextxy(100, 550, "����");
}
//�ӷ�
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
		outtextxy(330, 400, "����");
		mouseClick(&msg);
	}
}
//����
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
		outtextxy(330, 400, "����");
		mouseClick(&msg);
	}
}
//�˷�
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
		outtextxy(330, 400, "����");
		mouseClick(&msg);
	}
}
//����
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
		outtextxy(330, 400, "����");
		mouseClick(&msg);
	}
}
//����
void background() {
	loadimage(&res.back[0], _T("����.jpg"), getwidth(), getheight());
	putimage(0, 0, &res.back[0]);
	setbkmode(TRANSPARENT);//���ñ���͸��
	settextcolor(BLACK);
	settextstyle(45, 0, "��������");
	outtextxy(175, 50, "������Ϸ");
	setbkmode(OPAQUE);
}
//�˵�����
void menu(){
	int ty = 250;
	setbkcolor(WHITE);
	settextcolor(BLACK);
	settextstyle(32, 0, "��������");
	for (int i = 0; i < 4; i++) {
		mouseEvent();
		if (contain(190,ty+i*80,mx,my)) {
			setbkcolor(RED); //��ͣ��ɫ
			settextcolor(WHITE); //��ͣ������ɫ
			outtextxy(190, ty + i * 80, mainMenu[i]);
			setbkcolor(WHITE); //��ͣ��ɫ�ָ�
			settextcolor(BLACK); //��ͣ������ɫ�ָ�
			continue;
		}
		outtextxy(190, ty + i * 80, mainMenu[i]);
	}
}
//������Ա����
void Creator() {
	setbkmode(TRANSPARENT);
	outtextxy(100, 100, "������Ա��");
	loadimage(&res.sonimg[1], _T("����.png"), 300, 400);
	putimage(100, 150, &res.sonimg[1]);
	mouseEvent();
	if (contain(100, 550, mx, my)) {
		setbkmode(OPAQUE);
		setbkcolor(LIGHTGRAY);
		settextcolor(RED);
		outtextxy(100, 550, "����");
		setbkmode(TRANSPARENT);
	}outtextxy(100, 550, "����");
}
//�Ѷ�ѡ�����
void Chose() {
	int ty = 250;
	settextstyle(30, 0, "����");
	settextcolor(LIGHTRED);
	setbkmode(TRANSPARENT);
	outtextxy(75, 150, "ѡ���Ѷȣ�");
	settextstyle(32, 0, "��������");
	for (int i = 0; i < 3; i++) {
		mouseEvent();
		if (contain(190, ty + i * 80, mx, my)) {
			setbkmode(OPAQUE);
			setbkcolor(BLACK);
			settextcolor(RED);
			outtextxy(190, ty + i * 80, diffculty[i]);
			if (i == 2&&condition<10) {
				outtextxy(120, ty + 220, "���ڻ�������д��10��");
				char str[100000];
				sprintf(str, "%d", condition);
				outtextxy(120, ty + 260, str);
				outtextxy(150, ty + 260, "/10");
			}
			setbkcolor(LIGHTGRAY); //��ͣ��ɫ�ָ�
			settextcolor(WHITE); //��ͣ������ɫ�ָ�
			continue;
		}setbkcolor(LIGHTGRAY); 
		settextcolor(WHITE);
		setbkmode(OPAQUE);
		outtextxy(190, ty + i*80, diffculty[i]);
	}
	if (contain(400, 550, mx, my)) {
		setbkcolor(RED);
		settextcolor(BLACK);
		outtextxy(400, 550, "����");
	}outtextxy(400, 550, "����");
}
//��������
void Single(){
	int ty = 250;
	settextstyle(30, 0, "����");
	settextcolor(LIGHTRED);
	setbkmode(TRANSPARENT);
	outtextxy(75, 150, "ѡ���Ѷȣ�");
	settextstyle(32, 0, "��������");
	for (int i = 0; i < 4; i++) {
		mouseEvent();
		if (contain(190, ty + i * 80, mx, my)) {
			setbkmode(OPAQUE);
			setbkcolor(BLACK);
			settextcolor(RED);
			outtextxy(190, ty + i * 80, single[i]);
			setbkcolor(LIGHTGRAY); //��ͣ��ɫ�ָ�
			settextcolor(WHITE); //��ͣ������ɫ�ָ�
			continue;
		}setbkcolor(LIGHTGRAY);
		settextcolor(WHITE);
		setbkmode(OPAQUE);
		outtextxy(190, ty + i * 80, single[i]);
	}
	if (contain(400, 550, mx, my)) {
		setbkcolor(RED);
		settextcolor(BLACK);
		outtextxy(400, 550, "����");
	}outtextxy(400, 550, "����");

}
//�������
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
		outtextxy(330, 400, "����");
		mouseClick(&msg);
	}
}
//���а�
void drawTable() {
	if (amount <= 0) {
		FILE* fp = fopen("rank.txt", "r");
		if (fp == NULL) {
			outtextxy(200, 200, "�������а�");
			return;
		}
		char buffer[1000];
		while (fgets(buffer, 1000, fp) != NULL) {
			amount++;
		}rewind(fp);	
		for (int i = 0; i < amount; i++) {
			if (fscanf_s(fp, "%99s %d %lf", &user[i].name, (unsigned)_countof(user[i].name), &user[i].score, &user[i].time) != 3) {
				// ��ȡʧ�ܣ����Դ������
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
	//ð������
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
	settextstyle(26, 0, "����");
	outtextxy(40, 150, "����		����    ����   ��ʱ");
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
//��ս��
void Race() {
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "����");
	settextcolor(LIGHTRED);
	outtextxy(10, 100, "��ս��");
	char str1[100000];
	sprintf(str1, "%d/10", ques+1);
	settextstyle(22, 0, "����");
	outtextxy(320, 20, "������");
	outtextxy(400, 20, str1);
	FILE* fp1 = fopen("���а���.txt", "r");
	if (fp1 == NULL) {
		outtextxy(200, 200, "������Ŀ");
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (fscanf_s(fp1, "%d %d %d %d %d", &que[i].a,&que[i].b,&que[i].d,&que[i].e,&que[i].c) != 5) {
			// ��ȡʧ�ܣ����Դ������
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
			settextstyle(32, 0, "��������");
			outtextxy(150, 300, "��ս����");
			outtextxy(150, 350, "�÷֣�");
			outtextxy(150, 400, "��ʱ��");
			char str2[100000];
			sprintf(str2, "%d", right1);
			outtextxy(240, 350, str2);
			sprintf(str2, "%.2f", time1);
			outtextxy(240, 400, str2);
			FILE* fp = fopen("rank.txt", "w");
			if (fp == NULL) {
				outtextxy(200, 200, "���а�д��ʧ��");
				return;
			}
			for (int i = 0; i < amount; i++) {
				fprintf_s(fp, "%s %d %.2f\n", user[i].name, user[i].score, user[i].time);
			}fclose(fp);
		settextstyle(32, 0, "��������");
		outtextxy(100, 550, "����");
		}
}
//��ս����
void Chanllenge() {
	switch (chose2) {
	case 0: {
		drawTable();
		char page1[1000];
		sprintf(page1, "%d", page);
		outtextxy(400, 520, page1);
		sprintf(page1, "/%d", tpage);
		outtextxy(450, 520, page1);
		outtextxy(100, 550, "����");
		outtextxy(350, 550, "��һҳ");
		outtextxy(190, 550, "��ս");
		outtextxy(430, 250, "ɾ��");
		outtextxy(430, 350, "��ѯ");
		if (page != 1) {
			outtextxy(250, 550, "��һҳ");
		}break;
	}
	case 1: {
		if (namecase != 0) {
			char name[20];
			InputBox(name, 20, "��ע��������","ע��");
			for (int i = 0; i < amount; i++) {
				if (strcmp(user[i].name, name) == 0) {
					MessageBox(GetHWnd(), _T("�������������ɾ��"), _T("�û��Ѵ���"), MB_OK); // �������������������������Ϣ��
					chose2 = 0;
					namecase = 0;
					return;
				}
				else if (name[0] == '\0') {
					MessageBox(GetHWnd(), _T("��������Ϊ��"), _T("����"), MB_OK); // �������������������������Ϣ��
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
					outtextxy(150, 400, "�ش���ȷ��");
					ques++; right1++;
					index = 0;
					memset(input, '\0', sizeof(input));
				}
				else if (ans != num.c) {
					outtextxy(150, 400, "�ش����");
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
//������
int main() {
	int count = 0;
	//��ʼ������
	initgraph(500, 650);
	//˫�����ͼ
	BeginBatchDraw();
	while (count == 0) {
		//����
		cleardevice();
		background();
		mouseClick(&msg);
		if (which == 0) {
			menu();
		}
		//�Ѷ�ѡ�����
		else if (which == 1) {
			switch (chose) {
			case 0:
				Chose();
				break;
			//��������
			case 1: {
				if (chose1 == 0) {
					Single();
					j = 0;
					numb = 0;
					right = 0;
				}
				switch (chose1) {
				//�ӷ�����
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
							outtextxy(150, 400, "�ش���ȷ��");
							numb++;
							right++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
						else if (ans != num.c) {
							outtextxy(150, 400, "�ش����");
							numb++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
					}
					drawText(input);
					break;
				}
				//��������	
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
							outtextxy(150, 400, "�ش���ȷ��");
							numb++;
							right++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
						else if (ans != num.c) {
							outtextxy(150, 400, "�ش����");
							numb++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
					}
					drawText(input);
					break;
				}
				//�˷�����
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
							outtextxy(150, 400, "�ش���ȷ��");
							numb++;
							right++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
						else if (ans != num.c) {
							outtextxy(150, 400, "�ش����");
							numb++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
					}
					drawText(input);
					break;
				}
				//��������
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
							outtextxy(150, 400, "�ش���ȷ��");
							numb++;
							right++;
							index = 0;
							memset(input, '\0', sizeof(input));
						}
						else if (ans != num.c) {
							outtextxy(150, 400, "�ش����");
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
			//�������
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
						outtextxy(150, 400, "�ش���ȷ��");
						numb++;
						right2++;
						condition++;condition1++;
						index = 0;
						memset(input, '\0', sizeof(input));
					}
					else if (ans != num.c) {
						outtextxy(150, 400, "�ش����");
						numb++;
						condition1++;
						index = 0;
						memset(input, '\0', sizeof(input));
					}
				}
				drawText(input);
				break;
			}
			 //��ս����
			case 3:
				Chanllenge();
				break;
			}
		}
		//������Ա����
		else if (which == 2) {
			Creator();
		}
		//�淨����
		else if (which == 3) {
			Introduction();
		}
		else if (which == 4) {
			loadimage(&res.sonimg[2], _T("��л.png"), getwidth(), getheight());
			putimage(0, 0, &res.sonimg[2]);
			count = 1;
		}
		//����ˢ��
		FlushBatchDraw();
	}
	Sleep(3000);
	exit(0);
	return 0;
}