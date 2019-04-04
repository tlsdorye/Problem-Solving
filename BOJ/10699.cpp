#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	struct tm *datetime;
	time_t timer;
	timer = time(NULL);
	datetime = localtime(&timer);
	printf("%d-%02d-%02d", datetime->tm_year + 1900, datetime->tm_mon + 1, datetime->tm_mday);
}
