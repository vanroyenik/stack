#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DEFAULT_SIZE    4

struct stack{ // ��������� ���������
    int mas_size;  //������ �������
    char *massive; //���������� ������
    int quantity; //����� ��������� � �������
};

bool push(struct stack *stc, char new_elem); //��������� �������
char pop(struct stack *stc);
char top(struct stack *stc);

int main()
{
    struct stack my_stack;  //������� ���������� ���� ���������
                            //������ � ����� ��������� ����� �����
    my_stack.mas_size = DEFAULT_SIZE; //������� ������� ��������� �������� �������
    my_stack.massive = (char*)malloc(sizeof(char)*my_stack.mas_size);   //�������� ������� ������
                                                                        //��������: ������ 1 �������[�] � ����� ������� [����] = [�]
    my_stack.quantity = 0; //������ ���� ����

    if (my_stack.massive == NULL) return 1; //���� ������ �� ���������� ��� ��������, ��� ������ 1
    while(true){ //����������� ����
        char tmp[16]; //����� �����
        scanf("%s", tmp);
        char tmp_var = NULL;
        if (sscanf(tmp, "push:%c", &tmp_var )== 1){
            if (push(&my_stack, tmp_var))printf("OK\n");
        }
        if (strcmp(tmp, "pop") == 0){
            char elem = pop(&my_stack);
            if (elem) printf("%c\n", elem);
        }
        if (strcmp(tmp, "top") == 0){
            char elem = top(&my_stack);
            if (elem) printf("%c\n", elem);
        }
    }
    return 0;
};

bool push(struct stack *stc, char new_elem){//������ � ���������� �� ��������� ��������� ->����������
    if (stc->quantity == stc->mas_size){//������ �����?
        stc->massive = (char*)realloc(stc->massive, stc->mas_size);//������� ������ massive ��������� �� mas_size
        stc->mas_size*=2;
        if (stc->massive == NULL) return false;
    }
    stc->massive[stc->quantity] = new_elem; //quantity-�� ������� ������� massive ���������� new_elem
    ++stc->quantity;//��������� ��� �������� ��������
    return true;
};

char pop(struct stack *stc){
    if (stc->quantity == 0) return NULL;//������  ����?
    stc->quantity--;//� ������� ������ ���������� � ����, ������ �� ��� � �� 1 ������
    return stc->massive[stc->quantity];//
};

char top(struct stack *stc){
    if (stc->quantity == 0) return NULL;
    return stc->massive[stc->quantity - 1];//� ������� ������ ���������� � ����
}
