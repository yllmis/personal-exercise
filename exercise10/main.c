#include <stdio.h>
#include<stdlib.h>
#include"student.h"
<<<<<<< HEAD

=======
>>>>>>> aef5cb2a3a06b8ced6062dbcb1183d7437ef9df3
int main()
{
	int size=1;
	Class* class=createClass(size);  // �����༶
	while (1) {
		char a,c;
		Menu();  // ��ʾ�˵�
		printf("��ѡ���ܣ�\n");		
		switch (c=_getch())
		{
		//�ı�ѧ����Ϣ
		case '1': {
				system("cls");
				Menu1();  // ��ʾ�˵�1
				printf("��ѡ���ܣ�\n");
				a = _getch();
				switch (a)
				{
				case '1': {
					if (size > MAX) {
						printf("�༶�������޷������ѧ����\n");
						system("pause");
						system("cls");
						continue;
					}size++;
					addStudent(class); // ����ѧ����Ϣ
					system("pause");
					break;
				}
				case '2': {
					deleteStudent(class); // ɾ��ѧ����Ϣ
					system("pause");
					break;
				}
				case '3': {
					modifyStudent(class); // �޸�ѧ����Ϣ
					system("pause");
					break;
				}
				case '4': {
					searchStudent(class); // ��ѯѧ����Ϣ
					system("pause");
					break;
				}
				case '5': {
					system("cls");
					continue;
				}
				default: {
					printf("�������\n");
					system("pause");
					break;
				}
				}
			break;
			}
		//��ʾ�༶��Ϣ
		case '2': {
			printStudent(class); // ��ʾ�༶��Ϣ
			system("pause");
			break;
		}
		//����
		case '3': {
			system("cls");
			Menu2();  // ��ʾ�˵�2
			printf("��ѡ���ܣ�\n");
			a = _getch();
			switch (a)
			{
			case '1': {
				shengxu(class); //�ɸߵ�������
				system("pause");
				break;
			}
			case '2': {
				jiangxu(class); //�ɵ͵���
				system("pause");
				break;
			}
			case '3': {
				idsort(class); //��ѧ������
				system("pause");
				break;
			}
			case '4': {
				namesort(class); //����������
				system("pause");
				break;
			}
			case '5': {
				system("cls");
				continue;
			}
			default: {
				printf("�������\n");
				system("pause");
				break;
			}
			}break;
		}
		//ÿ�ſγ�
		case '4': {
			system("cls");
			Menu3();// ��ʾ�˵�3
			printf("��ѡ���ܣ� \n");
			a = _getch();
			switch (a)
			{
			case '1': {
				countScore(class); //����ÿ�ſγ��ֺܷ�ƽ����
				system("pause");
				break;
			}
			case '2': {
				accountScore(class); //���Ʒ�����
				system("pause");
				break;
			}
			case '3': {
				system("cls");
				continue;
			}
			default: {
				printf("�������\n");
				system("pause");
				break;
			}
			}break;
		}
		//�ļ�����
		case '5': {
			system("cls");
			Menu4(); // ��ʾ�˵�4
			printf("��ѡ���ܣ�\n");
			a = _getch();
			switch (a)
			{
			case '1': {
				writeFile(class);//��ѧ����Ϣд���ļ�
				system("pause");
				break;
			}
			case '2': {
				readFile(class);//���ļ��ж�ȡѧ����Ϣ
				system("pause");
				break;
			}
			case '3': {
				system("cls");
				continue;
			}
			default: {
				printf("�������\n");
				system("pause");
				break;
			}
			}
			break;
		}
		case '0': {		
			system("color FD");
			printf("�����˳���\n");
			system("pause");
			return 0;
		}
		default: {
			printf("�������\n");
			system("pause");
			break;
		}
		}system("cls");
	}
    return 0;
}