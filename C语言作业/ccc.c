#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
	int id;
	char name[50];
	float score;
};
void addStudent();
void displayStudents();
int main() {
	int choice;
	printf("=== 简单学生成绩管理系统 ===\n\n");

	do {
		printf("\n请选择操作:\n");
		printf("1. 添加学生\n");
		printf("2. 显示所有学生\n");
		printf("0. 退出\n");
		printf("请输入选择: ");
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			addStudent();
			break;
		case 2:
			displayStudents();
			break;
		case 0:
			printf("程序结束，再见!\n");
			break;
		default:
			printf("无效选择，请重新输入!\n");
		}
	} while(choice != 0);
	return 0;
}
void addStudent() {
	FILE *file = fopen("students.dat", "ab");
	if(file == NULL) {
		printf("无法打开文件!\n");
		return;
	}
	struct Student student;
	printf("请输入学号: ");
	scanf("%d", &student.id);
	printf("请输入姓名: ");
	scanf("%s", student.name);
	printf("请输入成绩: ");
	scanf("%f", &student.score);
	fwrite(&student, sizeof(struct Student), 1, file);
	fclose(file);
	printf("学生信息添加成功!\n");
}
void displayStudents() {
	FILE *file = fopen("students.dat", "rb");
	if(file == NULL) {
		printf("没有找到学生数据文件!\n");
		return;
	}
	struct Student student;
	printf("\n学号\t姓名\t成绩\n");
	printf("----------------------------\n");
	while(fread(&student, sizeof(struct Student), 1, file)) {
		printf("%d\t%s\t%.2f\n", student.id, student.name, student.score);
	}
	fclose(file);
}

