#ifndef __HI__SYS__
#define __HI_SYS__

#include "cross_platform.h"

#ifdef __cplusplus
extern "C"{
#endif

typedef struct _video_block_param_s{
	int32_t m_i32Width;			//ͼ����
	int32_t m_i32Height;		//ͼ��߶�
	int32_t m_i32BlockCnt;		//�ڴ����-�������������Ӧ��С��Ƶ�����ĸ���
	char m_strMmzName[32];		//�ڴ�������
}video_block_param_t;

typedef struct _hi_sys_param_s{
	int32_t m_i32StrideAlignWidth;//ϵͳʹ��ͼ���stride�ֽڶ�����
	video_block_param_t *m_stVideoBlockParamPtr;//��Ƶ�������������׵�ַ
	int32_t m_i32VideoBlockParamCnt;//��Ƶ�������������С
}hi_sys_param_t;

int32_t HI_SYS_Init(hi_sys_param_t *pstSysParam);
int32_t HI_SYS_UnInit();
int32_t HI_SYS_GetvVersion(char *pstrOutBuf, int32_t i32BufSize);

#ifdef __cplusplus
};
#endif

#endif