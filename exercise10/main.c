#include <stdio.h>
#include<stdlib.h>
#include"student.h"
<<<<<<< HEAD

=======
>>>>>>> aef5cb2a3a06b8ced6062dbcb1183d7437ef9df3
int main()
{
	int size=1;
	Class* class=createClass(size);  // 创建班级
	while (1) {
		char a,c;
		Menu();  // 显示菜单
		printf("请选择功能：\n");		
		switch (c=_getch())
		{
		//改变学生信息
		case '1': {
				system("cls");
				Menu1();  // 显示菜单1
				printf("请选择功能：\n");
				a = _getch();
				switch (a)
				{
				case '1': {
					if (size > MAX) {
						printf("班级已满，无法再添加学生！\n");
						system("pause");
						system("cls");
						continue;
					}size++;
					addStudent(class); // 创建学生信息
					system("pause");
					break;
				}
				case '2': {
					deleteStudent(class); // 删除学生信息
					system("pause");
					break;
				}
				case '3': {
					modifyStudent(class); // 修改学生信息
					system("pause");
					break;
				}
				case '4': {
					searchStudent(class); // 查询学生信息
					system("pause");
					break;
				}
				case '5': {
					system("cls");
					continue;
				}
				default: {
					printf("输入错误！\n");
					system("pause");
					break;
				}
				}
			break;
			}
		//显示班级信息
		case '2': {
			printStudent(class); // 显示班级信息
			system("pause");
			break;
		}
		//排序
		case '3': {
			system("cls");
			Menu2();  // 显示菜单2
			printf("请选择功能：\n");
			a = _getch();
			switch (a)
			{
			case '1': {
				shengxu(class); //由高到低排序
				system("pause");
				break;
			}
			case '2': {
				jiangxu(class); //由低到高
				system("pause");
				break;
			}
			case '3': {
				idsort(class); //按学号排序
				system("pause");
				break;
			}
			case '4': {
				namesort(class); //按姓名排序
				system("pause");
				break;
			}
			case '5': {
				system("cls");
				continue;
			}
			default: {
				printf("输入错误！\n");
				system("pause");
				break;
			}
			}break;
		}
		//每门课程
		case '4': {
			system("cls");
			Menu3();// 显示菜单3
			printf("请选择功能： \n");
			a = _getch();
			switch (a)
			{
			case '1': {
				countScore(class); //计算每门课程总分和平均分
				system("pause");
				break;
			}
			case '2': {
				accountScore(class); //各科分数段
				system("pause");
				break;
			}
			case '3': {
				system("cls");
				continue;
			}
			default: {
				printf("输入错误！\n");
				system("pause");
				break;
			}
			}break;
		}
		//文件操作
		case '5': {
			system("cls");
			Menu4(); // 显示菜单4
			printf("请选择功能：\n");
			a = _getch();
			switch (a)
			{
			case '1': {
				writeFile(class);//将学生信息写入文件
				system("pause");
				break;
			}
			case '2': {
				readFile(class);//从文件中读取学生信息
				system("pause");
				break;
			}
			case '3': {
				system("cls");
				continue;
			}
			default: {
				printf("输入错误！\n");
				system("pause");
				break;
			}
			}
			break;
		}
		case '0': {		
			system("color FD");
			printf("程序退出！\n");
			system("pause");
			return 0;
		}
		default: {
			printf("输入错误！\n");
			system("pause");
			break;
		}
		}system("cls");
	}
    return 0;
}