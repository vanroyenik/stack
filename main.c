#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DEFAULT_SIZE    4

struct stack{ // объ€влена структура
    int mas_size;  //размер массива
    char *massive; //символьный массив
    int quantity; //число элементов в массиве
};

bool push(struct stack *stc, char new_elem); //прототипы функций
char pop(struct stack *stc);
char top(struct stack *stc);

int main()
{
    struct stack my_stack;  //создана переменна€ типа структура
                            //доступ к пол€м структуры через точку
    my_stack.mas_size = DEFAULT_SIZE; //размеру массива присвоено значение макроса
    my_stack.massive = (char*)malloc(sizeof(char)*my_stack.mas_size);   //выделили область пам€ти
                                                                        //размером: размер 1 символа[б] х длина массива [штук] = [б]
    my_stack.quantity = 0; //массив пока пуст

    if (my_stack.massive == NULL) return 1; //если пам€ть не выделилась это нехорошо, код ошибки 1
    while(true){ //бесконечный цикл
        char tmp[16]; //буфер ввода
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

bool push(struct stack *stc, char new_elem){//доступ к переменной из структуры структура ->пеерменна€
    if (stc->quantity == stc->mas_size){//массив полон?
        stc->massive = (char*)realloc(stc->massive, stc->mas_size);//область пам€ти massive увеличить на mas_size
        stc->mas_size*=2;
        if (stc->massive == NULL) return false;
    }
    stc->massive[stc->quantity] = new_elem; //quantity-ый элемент массива massive становитс€ new_elem
    ++stc->quantity;//инкремент дл€ будущего элемента
    return true;
};

char pop(struct stack *stc){
    if (stc->quantity == 0) return NULL;//массив  пуст?
    stc->quantity--;//в массиве индекс начинаетс€ в нул€, сейчас их еще и на 1 меньше
    return stc->massive[stc->quantity];//
};

char top(struct stack *stc){
    if (stc->quantity == 0) return NULL;
    return stc->massive[stc->quantity - 1];//в массиве индекс начинаетс€ в нул€
}
