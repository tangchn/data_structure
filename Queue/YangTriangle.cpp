/*************************************************************************
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> File Name: YangTriangle.cpp
	> Description: ...
	> Created  Time: 2015-05-16. 23:21:10
	> Modified Time: 2015-05-16. 23:21:10
 ************************************************************************/
#include<queue>
#include<iostream>

using namespace std;

static void YangTriangle(const int n);
static void YangHuiTriangle(const int n);
int main(void)
{
	YangTriangle(10);
	YangHuiTriangle(10);
	return 0;
}

static void YangTriangle(const int n)
{
	queue<int> q;
	q.push(1);
	for(int i = 0; i <= n; i++)
	{
		int s = 0;
		q.push(s);
		for(int j = 0; j < i + 2; j++)
		{
			int t;
			int temp;
			t = q.front();
			q.pop();
			temp = s + t;
			q.push(temp);
			s = t;
			if(j != i+1)
			{
				cout<<s<<" ";
			}
		}
		cout<<endl;
	}
}

/*This one is easy to understand.
 * Here I use '0' to seperate every line, the key is:
 * step1: Pop the head and store the vaule as temp;
 * step2: Get the value(front) of the queue header but not dequeue it;
 * step2: Store front + temp and print it out;
 * */
static void YangHuiTriangle(const int n)
{
	queue<int> q;
	q.push(1);
	q.push(0);
	int i, temp, front;
	for(i = 0; i <= n; i++)
	{
		do
		{
			//step1
			temp = q.front();
			q.pop();
			//step2
			front = q.front();
			//step3
			temp += front;
			cout<<temp<<" ";
			q.push(temp);
		}while(front != 0);
		//After printed the whole line, we should insert '0'
		q.push(0);
		cout<<endl;
	}
}
