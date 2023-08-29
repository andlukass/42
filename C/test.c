#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// esse caso nao é valido, assim que essa funcao acabar
// o espaço da stack dela será excluido, sendo assim
// os valores de ptr serão perdidos
// int *testee(int *kkk)
// {
// 	int ptr[3] = {1, 2 ,98};
// 	write(1, &kkk[2], 4);
// 	return (ptr);
// }

void testee(int *kkk)
{
	write(1, &kkk[2], 4);
}

int main()
{
	//NULL = (void*)0
	// int ptr[3] = {1, 2 ,97};
	// testee(ptr);
	// int array[3];
	// int *ptr;
	// int *nullptr;
	// nullptr = NULL;
	// printf("array: %p\nponteiro: %p\nnull: %p\n", array, ptr, nullptr);
	// printf("\n\nnull: %p\nvoid0: %p\nvoid1: %p\n", NULL, (void*)0, (void*)1);

	// if(0 == NULL)
	// 	write(1, "cu\n", 3);
}