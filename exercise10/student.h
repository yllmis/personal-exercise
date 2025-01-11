#ifndef STUDENT_H
#define STUDENT_H
#define MAX 100
<<<<<<< HEAD

=======
>>>>>>> aef5cb2a3a06b8ced6062dbcb1183d7437ef9df3
typedef struct Student{
    char name[20];
    int id;
    int score;
    int course[5];
    double aver;
} Student;
typedef struct Class {
    Student stu[MAX];
    int size;
} Class;
Class* createClass(int size);
void Menu();
void Menu1();
void Menu2();
void Menu3();
void Menu4();
void addStudent(Class* class);
void deleteStudent(Class* class);
void modifyStudent(Class* class);
void searchStudent(Class* class);
void countScore(Class* class);
void printStudent(Class* class);
void shengxu(Class* class);
void jiangxu(Class* class);
void idsort(Class* class);
void namesort(Class* class);
void accountScore(Class* class);
void writeFile(Class* class);
void readFile(Class* class);
#endif