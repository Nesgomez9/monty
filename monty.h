#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct v_global{
        int status;
        char *n;
        stack_t *stack;
        unsigned int line_number;
} va_global;
extern va_global vglobal;
void _push(stack_t **stack, unsigned int line_number);
void free_buffer(char *buffer);
void str_concat(char *s1, char s2);
char *cpy(char *src, char *dest, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_list(stack_t *head);
void _pall(stack_t **stack, unsigned int line_number);
#endif
