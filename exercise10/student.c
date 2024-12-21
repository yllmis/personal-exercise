#include <stdio.h>
#include <stdlib.h>
#include"student.h"
//创建菜单
void Menu() {
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
	printf("*\t\t请选择功能\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.管理学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.排序学生信息\t\t\t*\n");
	printf("*\t\t4.每门课程信息\t\t\t*\n");
	printf("*\t\t5.文件操作  \t\t\t*\n");
	printf("*\t\t0.退出系统  \t\t\t*\n");
	printf("*************************************************\n");
}
//创建菜单1
void Menu1() {
	printf("------------------------------------\n");
	printf("****1.添加学生信息   ****\n");
	printf("****2.删除学生信息   ****\n");
	printf("****3.修改学生信息   ****\n");
	printf("****4.查询学生信息   ****\n");
	printf("****5.返回上一级     ****\n");
	printf("----------\n");
}
//创建菜单2
void Menu2() {
	printf("----------\n");
	printf("****1.从大到小排序****\n");
	printf("****2.从小到大排序****\n");
	printf("****3.按学号排序  ****\n");
	printf("****4.按姓名排序  ****\n");
	printf("****5.返回上一级  ****\n");
	printf("----------\n");
}
//创建菜单3
void Menu3() {
	printf("----------\n");
	printf("****1.计算每门课程的总成绩和平均成绩****\n");
	printf("****2.划分分数段                  ****\n");
	printf("****3.返回上一级                  ****\n");
	printf("----------\n");
}
//创建菜单4
void Menu4() {
	printf("----------\n");
	printf("****1.录入文件      ****\n");
	printf("****2.读取文件      ****\n");
	printf("****3.返回上一级     ****\n");
	printf("----------\n");
}
//创建班级
Class *createClass(int size) {
	Class *class = (Class*)malloc(sizeof(Class));
	if(class == NULL){
		printf("内存分配失败！\n");
		return NULL;
	}
	class->size = size-1;
	return class;
}
//添加学生信息
void addStudent(Class* class) {//添加学生信息
	int n=class->size;
		printf("请输入学生姓名：");
		char tempName[100]; // 临时存储姓名的缓冲区
		scanf_s("%99s", tempName, (unsigned)_countof(tempName)); // 读取姓名，限制长度，并且指定缓冲区大小
		strcpy(class->stu[n].name, tempName);
		getchar();
		printf("请输入学生学号：");
		scanf_s("%d", &class->stu[n].id, n+ 1);
		for (int i = 0; i<class->size; i++) {
			if (class->stu[n].id == class->stu[i].id) {
				printf("学号重复，请重新输入！\n");
				return;
			}
		}
		class->stu[n].score = 0;
		for (int i = 0; i < 5; i++) {
			printf("请输入第%d门课的成绩：", i+1);
			scanf_s("%d", &class->stu[n].course[i], n+ 1);
			class->stu[n].score += class->stu[n].course[i];
			class->stu[n].aver = (double)class->stu[n].score / 5.0;
		}
		class->size++;
		
}
//删除学生信息
void deleteStudent(Class* class) {//删除学生信息
	if(class->size==0){
		printf("没有学生信息！\n");
		return;
	}
	char tempName[100]; // 临时存储姓名的缓冲区
	printf("请输入要删除的学生姓名：");
	scanf_s("%99s", tempName, (unsigned)_countof(tempName)); // 读取姓名，限制长度，并且指定缓冲区大小
	for (int i = 0; i<class->size; i++) {
		if (strcmp(class->stu[i].name, tempName) == 0) {
			for (int j = i; j<class->size-1; j++) {
				class->stu[j] = class->stu[j + 1];
			}
			class->size--;
			printf("删除成功！\n");
			return;
		}
	}
	printf("没有该学生信息！\n");
}
//修改学生信息
void modifyStudent(Class* class) {//修改学生信息
	if(class->size==0){
		printf("没有学生信息！\n");
		return;
	}
	char tempName[100]; // 临时存储姓名的缓冲区
	printf("请输入要修改的学生姓名：");
	scanf_s("%99s", tempName, (unsigned)_countof(tempName)); // 读取姓名，限制长度，并且指定缓冲区大小
	for (int i = 0; i<class->size; i++) {
		if (strcmp(class->stu[i].name, tempName) == 0) {
			int id;
			printf("请输入学生学号：");
			scanf_s("%d", &id);
			for (int n = 0; i<class->size; i++) {
				if (class->stu[n].id == id) {
					printf("学号重复，请重新输入！\n");
					return;
				}
				else {
					class->stu[i].id = id;
					break;
				}
			}
			for (int j = 0; j < 5; j++) {
				printf("请输入第%d门课的成绩：", j+1);
				scanf_s("%d", &class->stu[i].course[j], i+ 1);
				class->stu[i].score = 0;
				for (int k = 0; k < 5; k++) {
					class->stu[i].score += class->stu[i].course[k];
				}
				class->stu[i].aver = (double)class->stu[i].score / 5.0;
			}
			printf("修改成功！\n");
			return;
		}
	}
}
//查询学生信息
void searchStudent(Class* class) {//查询学生信息
	if(class->size==0){
		printf("没有学生信息！\n");
		return;
	}
	char tempName[100]; // 临时存储姓名的缓冲区
	printf("请输入要查询的学生姓名：");
	scanf_s("%99s", tempName, (unsigned)_countof(tempName)); // 读取姓名，限制长度，并且指定缓冲区大小
	for (int i = 0; i<class->size; i++) {
		if (strcmp(class->stu[i].name, tempName) == 0) {
			printf("姓名：%s\n", class->stu[i].name);
			printf("学号：%d\n", class->stu[i].id);
			printf("总成绩：%d\n", class->stu[i].score);
			printf("平均成绩：%.2lf\n", class->stu[i].aver);
			for (int j = 0; j < 5; j++) {
				printf("第%d门课的成绩：%d\n", j+1, class->stu[i].course[j]);
			}
			return;
		}
	}printf("没有该学生信息！\n");
}
//打印学生信息
void printStudent(Class* class) {//打印学生信息
	printf("------------------------------------\n");
	printf("------------------------------------\n");
	printf("****姓名\t学号\t总成绩\t平均成绩****\n");
	for (int i = 0; i<class->size; i++) {
		printf("****%s  \t", class->stu[i].name);
		printf("%d\t", class->stu[i].id);
		printf("%d\t", class->stu[i].score);
		printf("%.2lf\t****", class->stu[i].aver);
		printf("\n");
		
	}printf("------------------------------------\n");
	printf("------------------------------------\n");
}
//由大到小
void shengxu(Class* class) {//升序排名
	if(class->size==0){
		printf("没有学生信息！\n");
		return;
	}
	for(int i=1;i<=class->size-1;i++){
		for(int j=0;j<class->size-i;j++){
			if(class->stu[j].score<class->stu[j+1].score){
				Student temp = class->stu[j];
				class->stu[j] = class->stu[j + 1];
				class->stu[j + 1] = temp;
			}
		}
	}printf("按总成绩由大到小排序后的成绩表：\n");
		printf("----------\n");
		printf("排名\t姓名\t总成绩\n");
	for (int i = 0; i<class->size; i++) {
		printf("%d\t%s\t%d\n", i + 1, class->stu[i].name, class->stu[i].score);
	}
}
//由小到大
void jiangxu(Class* class) {
	if(class->size==0){
		printf("没有学生信息！\n");
		return;
	}
	for(int i=1;i<=class->size-1;i++){
		for(int j=0;j<class->size-i;j++){
			if(class->stu[j].score>class->stu[j+1].score){
				Student temp = class->stu[j];
				class->stu[j] = class->stu[j + 1];
				class->stu[j + 1] = temp;
			}
		}
	}printf("按总成绩由小到大排序后的成绩表：\n");
		printf("----------\n");
		printf("排名\t姓名\t总成绩\n");
	for (int i = 0; i<class->size; i++) {
		printf("%d\t%s\t%d\n", i+1,class->stu[i].name, class->stu[i].score);
	}
}
//统计各门课程的总成绩和平均成绩
void countScore(Class* class) {
	for (int i = 0; i<5; i++) {
		int sum = 0;
		double average = 0;
		for (int j = 0; j < class->size; j++) {
			sum += class->stu[j].course[i];
		}printf("第%d门课的总成绩为：%d\n", i+1, sum);
		printf("第%d门课的平均成绩为：%.2lf\n", i + 1, (double)sum / class->size);
	}
}
//按学号排序
void idsort(Class* class) {
	for (int i = 1; i<=class->size - 1; i++) {
		for (int j = 0; j<class->size - i; j++) {
			if (class->stu[j].id > class->stu[j + 1].id) {
				Student temp = class->stu[j];
				class->stu[j] = class->stu[j + 1];
				class->stu[j + 1] = temp;
			}
		}
	}printf("按学号排序后的成绩表：\n");
		printf("----------\n");
		printf("姓名\t学号\t总成绩\t平均成绩\n");
		for (int i = 0; i<class->size; i++) {
			printf("%s\t%d\t%d\t%.2lf\n", class->stu[i].name, class->stu[i].id, class->stu[i].score, class->stu[i].aver);
		}
		printf("----------\n");
}
//按姓名字母顺序排序
void namesort(Class* class) {
	for (int i = 1; i<=class->size - 1; i++) {
		for (int j = 0; j<class->size - i; j++) {
			if (strcmp(class->stu[j].name, class->stu[j + 1].name) > 0) {
				Student temp = class->stu[j];
				class->stu[j] = class->stu[j + 1];
				class->stu[j + 1] = temp;
			}
		}
	}printf("按姓名字母顺序排序后的成绩表：\n");
		printf("----------\n");
		printf("姓名\t学号\t总成绩\t平均成绩\n");
		for (int i = 0; i<class->size; i++) {
			printf("%s\t%d\t%d\t%.2lf\n", class->stu[i].name, class->stu[i].id, class->stu[i].score, class->stu[i].aver);
		}
		printf("----------\n");
}
//分数段划分
void accountScore(Class* class) {
	int account[5] = { 0 };
	for(int i=0;i<5;i++){
		for (int j = 0; j<class->size; j++) {
			if (class->stu[j].course[i] >= 90) {
				account[0]++;
			}
			else if (class->stu[j].course[i] >= 80) {
				account[1]++;
			}
			else if (class->stu[j].course[i] >= 70) {
				account[2]++;
			}
			else if (class->stu[j].course[i] >= 60) {
				account[3]++;
			}
			else {
				account[4]++;
			}
		}printf("第%d门课的分数段及占比为：\n", i + 1);
		printf("优秀(90-100)\t%.2lf%%\n", (double)account[0] / class->size * 100);
		printf("良好(80-89)\t%.2lf%%\n", (double)account[1] / class->size * 100);
		printf("中等(70-79)\t%.2lf%%\n", (double)account[2] / class->size * 100);
		printf("及格(60-69)\t%.2lf%%\n", (double)account[3] / class->size * 100);
		printf("不及格(0-59)\t%.2lf%%\n", (double)account[4] / class->size * 100);
		account[0] = account[1] = account[2] = account[3] = account[4] = 0;
	}
}
//写入文件
void writeFile(Class* class) {
	FILE* fp = fopen("student.txt", "w");
	if (fp == NULL) {
		printf("文件打开失败！\n");
		return;
	}
	for (int i = 0; i<class->size; i++) {
		fprintf(fp, "%s %d %d %d %d %d %d %d %.2lf\n", class->stu[i].name, class->stu[i].id, class->stu[i].course[0], class->stu[i].course[1], class->stu[i].course[2], class->stu[i].course[3], class->stu[i].course[4], class->stu[i].score, class->stu[i].aver);
	}
	fclose(fp);
	printf("文件写入成功！\n");
}
//读取文件
void readFile(Class* class) {
	class->size = 0;
	FILE* fp = fopen("student.txt", "r");
	char buffer[1000];
	if (fp == NULL) {
		printf("文件打开失败！\n");
		return;
	}
	while (fgets(buffer, 1000, fp) != NULL) {
		class->size++;
	}rewind(fp);
	for (int i = 0; i<class->size; i++) {
		if (fscanf_s(fp, "%99s %d %d %d %d %d %d %d %lf", class->stu[i].name, (unsigned)_countof(class->stu[i].name), &class->stu[i].id, &class->stu[i].course[0], &class->stu[i].course[1], &class->stu[i].course[2], &class->stu[i].course[3], &class->stu[i].course[4], &class->stu[i].score, &class->stu[i].aver) != 9) {
			// 读取失败，可以处理错误
			break;
		}
		printf("%s %d %d %d %d %d %d %d %.2lf\n", class->stu[i].name, class->stu[i].id,class->stu[i].course[0], class->stu[i].course[1], class->stu[i].course[2], class->stu[i].course[3], class->stu[i].course[4], class->stu[i].score, class->stu[i].aver);
	}
	fclose(fp);
	printf("文件读取成功！\n");
}