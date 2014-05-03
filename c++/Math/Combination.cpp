/*!
* �ַ�����������⣬abc�������a,b,c,ab,bc,abc
* \author tonywang
* \date 2014/5/3 19:52
*/

/**
* �ݹ�ʵ��
* �ڳ���Ϊn���ַ�����ѡ��m���ַ�����ϣ������������
* 1.ѡ���һ���ַ�����ôҪ��ʣ�µĳ���Ϊn-1��ѡ��m-1����
* 2.��ѡ���һ���ַ�����ôҪ��ʣ�µĳ���Ϊn-1��ѡ��m����
* �ݹ�����������ǣ���m=0���������ַ�������ѡ���ַ�����ô��ʱ���Ѿ��ҵ�m���ַ������
*/
#include <stdio.h>
#include <string.h>
using namespace std;
#include <vector>

int count=0;

/**
* ��str�ַ�����ѡ��num���ַ�������result
*/
void combination(char *str, int num, vector<char> &result)
{
	if(!str) return;
	if(num==0)
	{
		printf("the %d combination: ",++count);
		vector<char>::iterator iter = result.begin();
		for( ;iter!=result.end();++iter)
			printf("%c",*iter);
		printf("\n");
		return;
	}
	if(*str == '\0')
		return;
	result.push_back(*str);
	combination(str+1,num-1,result);
	result.pop_back();
	combination(str+1,num,result);
}

void get_all_combination(char *str)
{
	if(!str) return;
	vector<char> result;
	int length = strlen(str);
	for(int i=1;i<=length;i++)
		combination(str, i, result);
}

int main()
{
	char str[256];
	printf("input a string:\n");
	scanf("%s",str);
	get_all_combination(str);
	return 0;
}
