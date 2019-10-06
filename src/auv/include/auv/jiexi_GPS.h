#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class GPS
{
private:
	char ss[500]; //#和×之间的字符串
				  //	double ss1;
public:
	GPS();
	~GPS(){};
	char get_ss(char s[]);
	int str(int num);
	char *gps(char ss1[], int num, int l, int flag);
};

GPS::GPS()
{
	strcpy(ss, "hello0000");
	//  ss1 = 0;
}

char GPS::get_ss(char s[]) //s为单次接收的所有数据
{
	char *p1;
	char *p2;
	char *p = s;
	int k;
	p1 = strchr(s, '#');
	p2 = strchr(s, '*');
	for (k = 0; k < p2 - p1; k++)
	{
		ss[k] = *(p1 + k);
	}
}

//根据， 寻找维度所在的子字符串
int GPS::str(int num)
{
	int i, j = 0;
	for (i = 0; i < strlen(ss); i++)
	{
		if (ss[i] == ',')
		{
			j++;
		}
		if (j == num)
			return i + 1;
	}
}
char *GPS::gps(char ss1[], int num, int l, int flag) // 子字符串 逗号个数 子字符串长度
{
	int k, i;
	char s_[50];
	i = str(num);
	char *q = &ss[i];
	for (k = 0; k < 50; k++)
	{
		s_[k] = *(q + k); //获得维度字符串
	}
	// cout << s_ <<endl;
	char *p2 = strchr(s_, '.');
	char *p1 = s_;
	// cout << p2 -p1<<endl;
	// cout << s_[0]<<endl;
	//维度，北向速度，东向速度，天向速度小数点之前有三位字符
	if (flag == 3)
	{
		if ((p2 - p1) == 3)
		{
			for (i = 0; i < l; i++)
			{
				ss1[i] = s_[i];
			}
		}
		if ((p2 - p1) == 2)
		{
			if (s_[0] == '-')
			{
				ss1[0] = '-';
				ss1[1] = '0';
				for (i = 2; i < l; i++)
				{
					ss1[i] = s_[i - 1];
				}
			}
			else
			{
				ss1[0] = '0';
				for (i = 1; i < l; i++)
				{
					ss1[i] = s_[i - 1];
				}
			}
		}
		if ((p2 - p1) == 1)
		{
			ss1[0] = ss1[1] = '0';
			for (i = 2; i < l; i++)
			{
				ss1[i] = s_[i - 2];
			}
		}
	}
	//经度，roll，俯仰角，航向 小数点前要求有四位字符
	if (flag == 4)
	{
		if ((p2 - p1) == 4)
		{
			for (i = 0; i < l; i++)
			{
				ss1[i] = s_[i];
			}
		}
		if ((p2 - p1) == 3)
		{
			if (s_[0] == '-')
			{
				ss1[0] = '-';
				ss1[1] = '0';
				for (i = 2; i < l; i++)
				{
					ss1[i] = s_[i - 1];
				}
			}
			else
			{
				ss1[0] = '0';
				for (i = 1; i < l; i++)
				{
					ss1[i] = s_[i - 1];
				}
			}
		}
		if ((p2 - p1) == 2)
		{
			if (s_[0] == '-')
			{
				ss1[0] = '-';
				ss1[1] = ss1[2] = '0';
				for (i = 3; i < l; i++)
				{
					ss1[i] = s_[i - 2];
				}
			}
			else
			{
				ss1[0] = ss1[1] = '0';
				for (i = 2; i < l; i++)
				{
					ss1[i] = s_[i - 2];
				}
			}
		}
		if ((p2 - p1) == 1)
		{
			ss1[0] = ss1[1] = ss1[2] = 0;
			for (i = 3; i < l; i++)
			{
				ss1[i] = s_[i - 3];
			}
		}
	}
	//高程，起伏 小数点前有五个字符
	if (flag == 5)
	{
		if ((p2 - p1) == 5)
		{
			for (i = 0; i < l; i++)
			{
				ss1[i] = s_[i];
			}
		}
		if ((p2 - p1) == 4)
		{
			if (s_[0] = '-')
			{
				ss1[0] = '-';
				ss1[1] = '0';
				for (i = 2; i < l; i++)
				{
					ss1[i] = s_[i - 1];
				}
			}
			else
			{
				ss1[0] = '0';
				for (i = 1; i < l; i++)
				{
					ss1[i] = s_[i - 1];
				}
			}
		}
		if ((p2 - p1) == 3)
		{
			if (s_[0] == '-')
			{
				ss1[0] = '-';
				ss1[1] = ss1[2] = '0';
				for (i = 3; i < l; i++)
				{
					ss1[i] = s_[i - 2];
				}
			}
			else
			{
				ss1[0] = ss1[1] = '0';
				for (i = 2; i < l; i++)
				{
					ss1[i] = s_[i - 2];
					;
				}
			}
			//cout << ss1 << endl;
		}
		if ((p2 - p1) == 2)
		{
			if (s_[0] == '-')
			{
				ss1[0] = '-';
				ss1[1] = ss1[2] = ss1[3] = '0';
				for (i = 4; i < l; i++)
				{
					ss1[i] = s_[i - 3];
				}
			}
			else
			{
				ss1[0] = ss1[1] = ss1[2] = '0';
				for (i = 3; i < l; i++)
				{
					ss1[i] = s_[i - 3];
				}
			}
		}
		if ((p2 - p1) == 1)
		{
			ss1[0] = ss1[1] = ss1[2] = ss1[3] = '0';
			for (i = 4; i < l; i++)
			{
				ss1[i] = s_[i - 4];
			}
		}
	}

	return ss1;
}

//ss1 = atof(s1); //转为double型