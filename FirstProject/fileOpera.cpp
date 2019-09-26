/*
 * @Description: 
 * @Author: TheNightIsYoung
 * @E-Mail: guojie0213_iit@163.com
 * @Date: 2019-09-25 15:43:41
 * @LastEditors: TheNightIsYoung
 * @LastEditTime: 2019-09-25 16:02:49
 */
#include <stdarg.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int CreatDir(char *pDir)
{
	int i = 0;
	int iRet;
	int iLen;
	char* pszDir;

	if(NULL == pDir)
	{
		return 0;
	}
	
	pszDir = strdup(pDir);
	iLen = strlen(pszDir);

	// 创建中间目录
	for (i = 0;i < iLen;i ++)
	{
		if (pszDir[i] == '\\' || pszDir[i] == '/')
		{ 
			pszDir[i] = '\0';

			// 如果不存在，创建
			iRet = access(pszDir,0);
			if (iRet != 0)
			{
				iRet = mkdir(pszDir,0755);
				if (iRet != 0)
				{
					return -1;
				} 
			}
			// 支持 linux，将所有 "\" 换成 "/"
			pszDir[i] = '/';
		} 
	}

	iRet = mkdir(pszDir,0755);
	free(pszDir);
	return iRet;
}

int main(int argc, char const *argv[])
{
    char VisualizationDir[] = "./TEST";
    CreatDir(VisualizationDir);
    
    return 0;
}
