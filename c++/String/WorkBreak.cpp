/*!
* word break����
* ����һ�����ַ�������һ�����ʴʵ䣬�����ַ������ֳɵ�����ɵľ���
* \author tonywang
* \date 2014/5/4
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

/**
* �����ʵ�dict���ж��ַ���s�ܷ���е��ʻ���
* ��̬�滮�������ռ�H[n]�ݴ�����״̬��H[i]��ʾ�ַ���ǰi���ַ���ɵ��ִ��ܹ����е��ʻ��֣�
* ��1���ַ���ʼ�жϣ�ÿ���ж�ǰi���ַ��ܷ񻮷֣��ܻ�������H[i]Ϊ1��
* �ж�iʱ����j=0��ʼ��j<i����H[j]=1,˵��ǰj���ɻ��֣����ж�s[j..i-j]�Ƿ���һ�����ʣ���������H[i]=1��
* �����H[n]=1�����������ַ����ܻ��֡�
*/
bool is_word_break(string s, set<string> dict, int H[])
{
	int n = s.size();
	if(n==0)  return false;
	//int H[n+1];
	memset(H,0,(n+1)*sizeof(int));
	H[0] = 1;
	for(int i=1;i<=n;i++)  //�ж��ַ���ǰi���ַ���ɵĴ��ܷ���е��ʻ���
	{
		for(int j=0;j<i;j++)  //�ж�0..i-1��i���ַ���ɵĴ�
		{
			//��ǰj(0<=j<i)���ַ��ܻ��֣���s[j..i-j]���ֵ������ҵ�����˵��ǰi���ܻ���
			if(H[j]==1 && dict.find(s.substr(j,i-j))!=dict.end())
			{
				H[i] = 1;
				break;
			}
		}
	}
	return (H[n] == 1);
}


/**
* ����H[]����ָ��ַ������ݹ�ʵ��
* s ���ָ��ַ���
* now ��ǰ�ѷָ�ɹ����ַ���
* idx ÿ�εݹ�ָ�ʱ����ʼ�жϵ�λ�ã��ݹ�ʱ��ֵΪ��һ���ҵ��ĵ���β+1
* H �ָ�������
* n �ַ�������
* dict �ֵ�
* re �ָ�Ľ���������в�ͬ��������������vector
*/
void backtrack(string s, string now, int idx, int H[], int n, set<string> dict, vector<string> &re)  
{
	if(idx == n)  
	{
		re.push_back(now);  
            	return;  
        }  
	for(int i=idx;i<n;i++)  
      	{
		//��һ��������֤������Ƕ�׵��ʵ����������cats��cat��cats���ǵ��ʵ����
         	if(H[i+1] == 1 && dict.find(s.substr(idx, i-idx+1)) != dict.end())  
            	{  
                	string new_now;  
                	if(now == "")  
                    		new_now = s.substr(idx, i-idx+1);  
                	else  
                		new_now = now + " " + s.substr(idx, i-idx+1);  
                	backtrack(s, new_now, i+1, H, n, dict, re);  
            	}
       	}  
} 


int main()
{
	set<string> dict;
	//dict.insert("leet");
	//dict.insert("code");
	//string str = "leetcode";
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("sand");
	dict.insert("and");
	dict.insert("dog");
	string str = "catsanddog";
	int n = str.size();
	int H[n+1];
	if(is_word_break(str,dict,H))
	{
		printf("yes\n");
		vector<string> result;
		backtrack(str,"",0,H,n,dict,result);
		printf("split result:\n");
		int count=0;	
		for(vector<string>::iterator iter = result.begin();iter!=result.end();++iter)
			cout<<++count<<") "<<*iter<<endl;
			//printf("%s\n",*iter);
	}
	else
		printf("no\n");
	
	return 0;
}
