#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int a = 0; //инициализация глобальной статической переменной, доступной из каждого треда
//функция, выполняющаяся в рамках второго треда
void *mythread(void *dummy)
{
	pthread_t mythid; //идентификатор треда - для каждого имеет свое значение
	mythid = pthread_self();
	a = a+1;
	printf("Thread %ld, Результат вычисления a = %d\n", mythid, a); //печать идентификатора текущего треда и результата и значения глобальной переменной 
	return NULL;
}
int main()
{
	pthread_t thid, mythid;
	int result;
	result = pthread_create(&thid, (pthread_attr_t *)NULL, mythread, NULL); //создание нового треда
	if(result != 0)
	{
		printf("Ошибка при создании нового thread, возвращаемое значение = %d\n", result);
		exit(-1);
	}
	printf("Thread создан, thid = %ld\n", thid);
	mythid = pthread_self(); //сохраняем в данной переменной идентификатор главного треда
	a = a+1;
	printf("Thread %ld, Результат вычисления a = %d\n", mythid, a);
	pthread_join(thid, (void **)NULL); //ожидание завершения порожденного треда
	return 0;
}
