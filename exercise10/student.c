#include <stdio.h>
#include <stdlib.h>
#include"student.h"
//�����˵�
void Menu() {
	printf("*************************************************\n");
	printf("*\t��ӭʹ�ø�Уѧ���ɼ�����ϵͳV1.0\t*\n");
	printf("*\t\t��ѡ����\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.��ӡѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.����ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.ÿ�ſγ���Ϣ\t\t\t*\n");
	printf("*\t\t5.�ļ�����  \t\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ  \t\t\t*\n");
	printf("*************************************************\n");
}
//�����˵�1
void Menu1() {
	printf("------------------------------------\n");
	printf("****1.���ѧ����Ϣ   ****\n");
	printf("****2.ɾ��ѧ����Ϣ   ****\n");
	printf("****3.�޸�ѧ����Ϣ   ****\n");
	printf("****4.��ѯѧ����Ϣ   ****\n");
	printf("****5.������һ��     ****\n");
	printf("----------\n");
}
//�����˵�2
void Menu2() {
	printf("----------\n");
	printf("****1.�Ӵ�С����****\n");
	printf("****2.��С��������****\n");
	printf("****3.��ѧ������  ****\n");
	printf("****4.����������  ****\n");
	printf("****5.������һ��  ****\n");
	printf("----------\n");
}
//�����˵�3
void Menu3() {
	printf("----------\n");
	printf("****1.����ÿ�ſγ̵��ܳɼ���ƽ���ɼ�****\n");
	printf("****2.���ַ�����                  ****\n");
	printf("****3.������һ��                  ****\n");
	printf("----------\n");
}
//�����˵�4
void Menu4() {
	printf("----------\n");
	printf("****1.¼���ļ�      ****\n");
	printf("****2.��ȡ�ļ�      ****\n");
	printf("****3.������һ��     ****\n");
	printf("----------\n");
}
//�����༶
Class *createClass(int size) {
	Class *class = (Class*)malloc(sizeof(Class));
	if(class == NULL){
		printf("�ڴ����ʧ�ܣ�\n");
		return NULL;
	}
	class->size = size-1;
	return class;
}
//���ѧ����Ϣ
void addStudent(Class* class) {//���ѧ����Ϣ
	int n=class->size;
		printf("������ѧ��������");
		char tempName[100]; // ��ʱ�洢�����Ļ�����
		scanf_s("%99s", tempName, (unsigned)_countof(tempName)); // ��ȡ���������Ƴ��ȣ�����ָ����������С
		strcpy(class->stu[n].name, tempName);
		getchar();
		printf("������ѧ��ѧ�ţ�");
		scanf_s("%d", &class->stu[n].id, n+ 1);
		for (int i = 0; i<class->size; i++) {
			if (class->stu[n].id == class->stu[i].id) {
				printf("ѧ���ظ������������룡\n");
				return;
			}
		}
		class->stu[n].score = 0;
		for (int i = 0; i < 5; i++) {
			printf("�������%d�ſεĳɼ���", i+1);
			scanf_s("%d", &class->stu[n].course[i], n+ 1);
			class->stu[n].score += class->stu[n].course[i];
			class->stu[n].aver = (double)class->stu[n].score / 5.0;
		}
		class->size++;
		
}
//ɾ��ѧ����Ϣ
void deleteStudent(Class* class) {//ɾ��ѧ����Ϣ
	if(class->size==0){
		printf("û��ѧ����Ϣ��\n");
		return;
	}
	char tempName[100]; // ��ʱ�洢�����Ļ�����
	printf("������Ҫɾ����ѧ��������");
	scanf_s("%99s", tempName, (unsigned)_countof(tempName)); // ��ȡ���������Ƴ��ȣ�����ָ����������С
	for (int i = 0; i<class->size; i++) {
		if (strcmp(class->stu[i].name, tempName) == 0) {
			for (int j = i; j<class->size-1; j++) {
				class->stu[j] = class->stu[j + 1];
			}
			class->size--;
			printf("ɾ���ɹ���\n");
			return;
		}
	}
	printf("û�и�ѧ����Ϣ��\n");
}
//�޸�ѧ����Ϣ
void modifyStudent(Class* class) {//�޸�ѧ����Ϣ
	if(class->size==0){
		printf("û��ѧ����Ϣ��\n");
		return;
	}
	char tempName[100]; // ��ʱ�洢�����Ļ�����
	printf("������Ҫ�޸ĵ�ѧ��������");
	scanf_s("%99s", tempName, (unsigned)_countof(tempName)); // ��ȡ���������Ƴ��ȣ�����ָ����������С
	for (int i = 0; i<class->size; i++) {
		if (strcmp(class->stu[i].name, tempName) == 0) {
			int id;
			printf("������ѧ��ѧ�ţ�");
			scanf_s("%d", &id);
			for (int n = 0; i<class->size; i++) {
				if (class->stu[n].id == id) {
					printf("ѧ���ظ������������룡\n");
					return;
				}
				else {
					class->stu[i].id = id;
					break;
				}
			}
			for (int j = 0; j < 5; j++) {
				printf("�������%d�ſεĳɼ���", j+1);
				scanf_s("%d", &class->stu[i].course[j], i+ 1);
				class->stu[i].score = 0;
				for (int k = 0; k < 5; k++) {
					class->stu[i].score += class->stu[i].course[k];
				}
				class->stu[i].aver = (double)class->stu[i].score / 5.0;
			}
			printf("�޸ĳɹ���\n");
			return;
		}
	}
}
//��ѯѧ����Ϣ
void searchStudent(Class* class) {//��ѯѧ����Ϣ
	if(class->size==0){
		printf("û��ѧ����Ϣ��\n");
		return;
	}
	char tempName[100]; // ��ʱ�洢�����Ļ�����
	printf("������Ҫ��ѯ��ѧ��������");
	scanf_s("%99s", tempName, (unsigned)_countof(tempName)); // ��ȡ���������Ƴ��ȣ�����ָ����������С
	for (int i = 0; i<class->size; i++) {
		if (strcmp(class->stu[i].name, tempName) == 0) {
			printf("������%s\n", class->stu[i].name);
			printf("ѧ�ţ�%d\n", class->stu[i].id);
			printf("�ܳɼ���%d\n", class->stu[i].score);
			printf("ƽ���ɼ���%.2lf\n", class->stu[i].aver);
			for (int j = 0; j < 5; j++) {
				printf("��%d�ſεĳɼ���%d\n", j+1, class->stu[i].course[j]);
			}
			return;
		}
	}printf("û�и�ѧ����Ϣ��\n");
}
//��ӡѧ����Ϣ
void printStudent(Class* class) {//��ӡѧ����Ϣ
	printf("------------------------------------\n");
	printf("------------------------------------\n");
	printf("****����\tѧ��\t�ܳɼ�\tƽ���ɼ�****\n");
	for (int i = 0; i<class->size; i++) {
		printf("****%s  \t", class->stu[i].name);
		printf("%d\t", class->stu[i].id);
		printf("%d\t", class->stu[i].score);
		printf("%.2lf\t****", class->stu[i].aver);
		printf("\n");
		
	}printf("------------------------------------\n");
	printf("------------------------------------\n");
}
//�ɴ�С
void shengxu(Class* class) {//��������
	if(class->size==0){
		printf("û��ѧ����Ϣ��\n");
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
	}printf("���ܳɼ��ɴ�С�����ĳɼ���\n");
		printf("----------\n");
		printf("����\t����\t�ܳɼ�\n");
	for (int i = 0; i<class->size; i++) {
		printf("%d\t%s\t%d\n", i + 1, class->stu[i].name, class->stu[i].score);
	}
}
//��С����
void jiangxu(Class* class) {
	if(class->size==0){
		printf("û��ѧ����Ϣ��\n");
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
	}printf("���ܳɼ���С���������ĳɼ���\n");
		printf("----------\n");
		printf("����\t����\t�ܳɼ�\n");
	for (int i = 0; i<class->size; i++) {
		printf("%d\t%s\t%d\n", i+1,class->stu[i].name, class->stu[i].score);
	}
}
//ͳ�Ƹ��ſγ̵��ܳɼ���ƽ���ɼ�
void countScore(Class* class) {
	for (int i = 0; i<5; i++) {
		int sum = 0;
		double average = 0;
		for (int j = 0; j < class->size; j++) {
			sum += class->stu[j].course[i];
		}printf("��%d�ſε��ܳɼ�Ϊ��%d\n", i+1, sum);
		printf("��%d�ſε�ƽ���ɼ�Ϊ��%.2lf\n", i + 1, (double)sum / class->size);
	}
}
//��ѧ������
void idsort(Class* class) {
	for (int i = 1; i<=class->size - 1; i++) {
		for (int j = 0; j<class->size - i; j++) {
			if (class->stu[j].id > class->stu[j + 1].id) {
				Student temp = class->stu[j];
				class->stu[j] = class->stu[j + 1];
				class->stu[j + 1] = temp;
			}
		}
	}printf("��ѧ�������ĳɼ���\n");
		printf("----------\n");
		printf("����\tѧ��\t�ܳɼ�\tƽ���ɼ�\n");
		for (int i = 0; i<class->size; i++) {
			printf("%s\t%d\t%d\t%.2lf\n", class->stu[i].name, class->stu[i].id, class->stu[i].score, class->stu[i].aver);
		}
		printf("----------\n");
}
//��������ĸ˳������
void namesort(Class* class) {
	for (int i = 1; i<=class->size - 1; i++) {
		for (int j = 0; j<class->size - i; j++) {
			if (strcmp(class->stu[j].name, class->stu[j + 1].name) > 0) {
				Student temp = class->stu[j];
				class->stu[j] = class->stu[j + 1];
				class->stu[j + 1] = temp;
			}
		}
	}printf("��������ĸ˳�������ĳɼ���\n");
		printf("----------\n");
		printf("����\tѧ��\t�ܳɼ�\tƽ���ɼ�\n");
		for (int i = 0; i<class->size; i++) {
			printf("%s\t%d\t%d\t%.2lf\n", class->stu[i].name, class->stu[i].id, class->stu[i].score, class->stu[i].aver);
		}
		printf("----------\n");
}
//�����λ���
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
		}printf("��%d�ſεķ����μ�ռ��Ϊ��\n", i + 1);
		printf("����(90-100)\t%.2lf%%\n", (double)account[0] / class->size * 100);
		printf("����(80-89)\t%.2lf%%\n", (double)account[1] / class->size * 100);
		printf("�е�(70-79)\t%.2lf%%\n", (double)account[2] / class->size * 100);
		printf("����(60-69)\t%.2lf%%\n", (double)account[3] / class->size * 100);
		printf("������(0-59)\t%.2lf%%\n", (double)account[4] / class->size * 100);
		account[0] = account[1] = account[2] = account[3] = account[4] = 0;
	}
}
//д���ļ�
void writeFile(Class* class) {
	FILE* fp = fopen("student.txt", "w");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
	for (int i = 0; i<class->size; i++) {
		fprintf(fp, "%s %d %d %d %d %d %d %d %.2lf\n", class->stu[i].name, class->stu[i].id, class->stu[i].course[0], class->stu[i].course[1], class->stu[i].course[2], class->stu[i].course[3], class->stu[i].course[4], class->stu[i].score, class->stu[i].aver);
	}
	fclose(fp);
	printf("�ļ�д��ɹ���\n");
}
//��ȡ�ļ�
void readFile(Class* class) {
	class->size = 0;
	FILE* fp = fopen("student.txt", "r");
	char buffer[1000];
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
	while (fgets(buffer, 1000, fp) != NULL) {
		class->size++;
	}rewind(fp);
	for (int i = 0; i<class->size; i++) {
		if (fscanf_s(fp, "%99s %d %d %d %d %d %d %d %lf", class->stu[i].name, (unsigned)_countof(class->stu[i].name), &class->stu[i].id, &class->stu[i].course[0], &class->stu[i].course[1], &class->stu[i].course[2], &class->stu[i].course[3], &class->stu[i].course[4], &class->stu[i].score, &class->stu[i].aver) != 9) {
			// ��ȡʧ�ܣ����Դ������
			break;
		}
		printf("%s %d %d %d %d %d %d %d %.2lf\n", class->stu[i].name, class->stu[i].id,class->stu[i].course[0], class->stu[i].course[1], class->stu[i].course[2], class->stu[i].course[3], class->stu[i].course[4], class->stu[i].score, class->stu[i].aver);
	}
	fclose(fp);
	printf("�ļ���ȡ�ɹ���\n");
}