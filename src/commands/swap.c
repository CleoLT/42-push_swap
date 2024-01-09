#include "../../include/push_swap.h"

void swap(t_stack **stack)
{
	t_stack **tmp;

	if (!*stack || !((*stack)->next))
		return ;
/*	tmp = *stack;
	printf("1\nA: %d        B: %d        C: %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
	printf("A->next: %d B->next: %d C->next: %d\n", (*stack)->next->value, (*stack)->next->next->value, (*stack)->next->next->next->value   );
	printf("tA: %d       tB: %d      tC: %d\n\n", tmp->value, tmp->next->value, tmp->next->next->value);


	*stack = (*stack)->next;
	printf("2\nA: %d       B: %d       C: %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
printf("A->next: %d B->next: %d C->next: %d\n", (*stack)->next->value, (*stack)->next->next->value, (*stack)->next->next->next->value   );
printf("tA: %d       tB: %d      tC: %d\n\n", tmp->value, tmp->next->value, tmp->next->next->value);


	tmp->next = (*stack)->next;
 printf("3\nA: %d       B: %d       C: %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
printf("A->next: %d B->next: %d C->next: %d\n", (*stack)->next->value, (*stack)->next->next->value, (*stack)->next->next->next->value   );
printf("tA: %d       tB: %d      tC: %d\n\n", tmp->value, tmp->next->value, tmp->next->next->value);


//    printf("tmp: %d tmp->next: %d\n\n", tmp->value, tmp->next->value);


	(*stack)->next = tmp;
 printf("2\nA: %d       B: %d       C: %d\n", (*stack)->value, (*stack)->next->value, (*stack)->next->next->value);
printf("A->next: %d B->next: %d C->next: %d\n", (*stack)->next->value, (*stack)->next->next->value, (*stack)->next->next->next->value   );
    printf("tmp: %d tmp->next: %d\n", tmp->value, tmp->next->value);

*/
tmp = stack;
stack =stack->next;
tmp->next= stack->next;
stack->next=tmp;


}

