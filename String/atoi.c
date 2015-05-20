/*************************************************************************
	> File Name: atoi.c
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-05-14. 00:31:25
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

static int str_to_int(const char* const str);


int main(void)
{
	const char* str = "   + 2 5 6   8";
	int result;
	result = str_to_int(str);
	if(result)
	{
        printf("The number corresponding to %s is %d\n", str, result);
	}
	return 0 ;
}

static int str_to_int(const char* const str)
{
	int result = 0;
	int sign = 1;


	int len = strlen(str);
	char* trim_str = (char*)malloc(len * sizeof(char));
	size_t i, j;
	i = j = 0;
	char temp;
	int onesign = 1;
	while(i < len)
	{
		temp = *(str + i);
		if(temp <= '9' && temp >= '0')
		{
			*(trim_str + j) = temp;
			i++;
			j++;

		}else if(temp == ' ')
        {
            i++;
		}else if((temp == '-' || temp == '+') && onesign)
		{
            *(trim_str + j) = temp;
            i++;
			j++;
			onesign = 0;
		}
		else
		{
            printf("The format of the inputing number is invalid\n");
            return 0;
		}
	}
	*(trim_str + j) = '\0';


	if(*trim_str == '-' || *trim_str == '+')
	{
		sign = (*trim_str == '-' ? -1 : 1);
        trim_str++;
	}

	while(*trim_str && *trim_str > '0' && *trim_str < '9')
	{
		if(result > INT_MAX / 10 || ( result  == INT_MAX / 10 && *trim_str > INT_MAX % 10))
		{
			result = (sign == -1 ? INT_MIN : INT_MAX);
			return result;
		}
		result = result * 10 + *trim_str - '0';
		trim_str++;
	}
	return result * sign;
}

