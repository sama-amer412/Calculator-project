#include"../HALL/LCD/LCD_interface.h"
#include"../HALL/LCD/LCD_private.h"
#include"../HALL/LCD/LCD_cofig.h"
#include"../HALL/Kpad/Kpad_interface.h"
#include"../HALL/Kpad/Kpad_config.h"



#include"../Lib/STD_TYPES.h"
#include"../Lib/Bit_math.h"

#include <util/delay.h>
#include"../MCAL/DIO/DIO_interface.h"
#include <string.h>
#include <stdlib.h>


int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}


void infix_to_postfix(char* infix, char* postfix) {
    char stack[20];
    int top = -1, i = 0, j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if (token >= '0' && token <= '9') {
            postfix[j++] = token;
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            postfix[j++] = ' ';
            while (top >= 0 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = token;
        }

        i++;
    }

    while (top >= 0) {
        postfix[j++] = ' ';
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}


int eval_postfix(char* postfix) {
    int stack[20];
    int top = -1;
    int i = 0;

    while (postfix[i] != '\0') {
        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        if (postfix[i] >= '0' && postfix[i] <= '9') {
            int num = 0;
            while (postfix[i] >= '0' && postfix[i] <= '9') {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            stack[++top] = num;
        }
        else {
            int b = stack[top--];
            int a = stack[top--];
            switch (postfix[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
            i++;
        }
    }

    return stack[top];
}


int main(void){
LCD_init();
Kpad_init();
// u8 arr1[10]={'W','e','l','c','o','m','e',' ', 't','o' };
u8  arr2[10]={'C','a','l','c','u','l','a','t','o','r'};
// LCD_curserPosition(line1, 2);
// LCD_print_string(arr1);
LCD_curserPosition(line1, 2);
LCD_print_string(arr2);
_delay_ms(1000);
LCD_ClearDisplay();

    

    char infix_expr[30] = {0};
    char postfix_expr[30] = {0};
    u8 key, i = 0;

    while (1)
    {
        key = Kpad_return_pressed_key();

        if (key != 0xFF)
        {
            if (key == 'c')
            {
                i = 0;
                LCD_ClearDisplay();
                memset(infix_expr, 0, sizeof(infix_expr));
            }
            else if (key == '=')
            {
                infix_expr[i] = '\0';
                infix_to_postfix(infix_expr, postfix_expr);
                int result = eval_postfix(postfix_expr);

                LCD_ClearDisplay();
                LCD_print_string("Result: ");
                LCD_print_number(result);

                i = 0;
                memset(infix_expr, 0, sizeof(infix_expr));
                memset(postfix_expr, 0, sizeof(postfix_expr));
            }
            else
            {
                if (i < 29)
                {
                    infix_expr[i++] = key;
                    LCD_SendCharData(key);
                }
            }

            _delay_ms(250);
        }
    }

    return 0;
}