#include<stdio.h>
#include<stdlib.h>
#define NUMBER_OF_STUDENT 250

struct student{
	int number;
	char name;
	int status;
	//status���� 0�� ���� 1�� ����
	int score;
};

void register_student(struct student*);
void input_score(struct student*);
void student_status(struct student*);
void search_student(struct student*);
void remove_student(struct student*);

int main(void){
	int n;
	struct student* student = (struct student*) malloc(NUMBER_OF_STUDENT * sizeof(struct student));
	printf("�л��� ����Ϸ��� 1�� �Է��ϼ���\n���� �Է��� �Ϸ��� 2�� �Է��ϼ���\n���� / ���� ��û�� �Ϸ��� 3�� �Է��ϼ���\n�л��� �˻��Ϸ��� 4�� �Է��ϼ���\n��ϵ� �л��� �����Ϸ��� 5�� �Է��ϼ���\n");
	scanf_s("%d", &n);
	if (n == 1){
		//�л��� ���
		register_student(student);
	}
	if (n == 2){
		//�л��� ���� �Է�
		input_score(student);
	}
	if (n == 3){
		//�л��� ���� / ���� ��û
		status(student);
	}
	if (n == 4){
		//�л��� �˻�
		search_student(student);
	}
	if (n == 5){
		//��ϵ� �л��� ����
		remove_student(student);
	}


	free(student);
}

void register_student(struct student* student){
	printf("�й��� �Է��ϼ���\n");
	scanf_s("%d", &(student->number));
	printf("�̸��� �Է��ϼ���\n");
	scanf_s("%s", &(student->name));
	(student->status) = 0;
	(student->score) = 0;
}

void input_score(struct student* student){
	/*
	A: 91 ~ 100
	B: 81 ~ 90
	C: 71 ~ 80
	D: 61 ~ 70
	F: ~ 60
	��, ���� ���� ������ �л��� ������ �Է��� �� �����ϴ�.*/
	printf("������ �Է��ϼ��� ( 0 ~ 100 )");
	scanf_s("%d",&(student->score));


}

int status(struct student* student){
	int status_status;
	int n;
	printf("�й��� �Է��ϼ���\n");
	scanf_s("%d", &(status_status));
	if (status_status == (student->number)){
		if ((student->status) == 0){
			printf("���� ��û�� �Ϸ��� 1�� �Է����ּ���\n�ƴϸ� �ƹ� Ű�� �Է����ּ���\n");
			scanf_s("%d", &n);
			if (n == 1){
				(student->number) = 1;
				printf("���� ��û �Ǿ����ϴ�\n");
			}
			else printf("��ҵǾ����ϴ�\n");
		}
		if ((student->status) == 1){
			printf("���� ��û�� �Ϸ��� 1�� �Է����ּ���\n�ƴϸ� �ƹ� Ű�� �Է����ּ���\n");
			scanf_s("%d", &n);
			if (n == 1){
				(student->number) = 0;
				printf("���� ��û �Ǿ����ϴ�\n");
			}
			else printf("��ҵǾ����ϴ�\n");
		}
	}
	else printf("��ġ�ϴ� �й��� �����ϴ�\n");
}

void search_student(struct student* student){
	// �й�1 �̸�2 ����3 ����/����4
	int n, m;
	printf("�й����� �˻��Ͻ÷��� 1\n�̸����� �˻��Ͻ÷��� 2\n�������� �˻��Ͻ÷��� 3\n����/�������� �˻��Ͻ÷��� 4�� �Է��ϼ���\n");
	scanf_s("%d", &n);
	if (n == 1){
		//�й��˻�
		printf("�й��� �Է��ϼ���\n");
		scanf_s("%d", &m);
		if (m == (student->number)){
			printf("");
		}
	}
	if (n == 2){
		//�̸��˻�
		printf("�̸��� �Է��ϼ���\n");
		scanf_s("%s", &m);
	}
	if (n == 3){
		//�����˻�
		printf("������ �Է��ϼ���\n");
		scanf_s("%d", &m);
		if (m == (student->score)){
			printf("");
		}

	}
	if (n == 4){
		//����/���а˻�
		printf("���� �����̸� 0�� �Է��ϼ���\n���� �����̸� 1�� �Է��ϼ���\n");
		scanf_s("%d", &m);
	}
	else printf("1~4�� ���ڸ� �Է��ϼ���\n");
}

void remove_student(struct student* student){
	//��ϵ� �л��� ������ �������� ���Ű� �����ϸ� �й��� �Է��Ͽ� ������ �� �ֽ��ϴ�.
	int status_status;
	int n;
	printf("�й��� �Է��ϼ���\n");
	scanf_s("%d", &status_status);
	if (status_status == (student->number)){
		printf("�Էµ� �й��� �л��� �����Ͻ÷��� 1���� �Է��ϼ���\n�ƴϸ� �ƹ� Ű�� �Է����ּ���\n");
		scanf_s("%d", &n);
		if (n == 1){
			student->number = 0;
			student->name = 0;
			student->status = 0;
			student->score = 0;
			printf("���ŵǾ����ϴ�\n");
		}
		else printf("��ҵǾ����ϴ�\n");
	}
	else printf("��ġ�ϴ� �й��� �����ϴ�\n");
}