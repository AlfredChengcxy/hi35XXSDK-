#ifndef __HI_FB_H__
#define __HI_FB_H__

#include "cross_platform.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

#define GRAPHICS_LAYER_G0  0
#define GRAPHICS_LAYER_G1  4
#define GRAPHICS_LAYER_SD0 2
#define GRAPHICS_LAYER_HC0 2
#define GRAPHICS_LAYER_HC1 3

typedef hi_fb_handle void*;

typedef struct _hi_fb_point_s{
	int32_t m_s32XPos;         /**<  horizontal position */
	int32_t m_s32YPos;         /**<  vertical position */
}hi_fb_point_t;

typedef struct _hi_fb_screen_info_s{
	uint32_t m_u32DisResWidth;				//�豸��ʾ�ֱ��ʿ�
	uint32_t m_u32DisResHeight;				//�豸��ʾ�ֱ��ʸ�
	uint32_t m_u32MaxVirtualResWidth;		//�������ֱ��ʿ�
	uint32_t m_u32MaxVirtualResHeight;		//�������ֱ��ʸ�
	uint32_t m_u32BitsPerPixel;				//λ�� 8bit - 16bit - 32bit
}hi_fb_screen_info_t;

typedef struct __hi_fb_graphics_layer_param_s{
	int32_t m_i32GraphicsLayerID;			//ͼ�β�ID
	uint32_t m_u32DevDisResWidth;			//�豸��ʾ�ֱ��ʿ�
	uint32_t m_u32DevDisResHeight;			//�豸��ʾ�ֱ��ʸ�
	uint32_t m_u32MaxVirtualResWidth;		//�������ֱ��ʿ�
	uint32_t m_u32MaxVirtualResHeight;		//�������ֱ��ʸ�
	uint32_t m_u32BitsPerPixel;				//λ�� 8bit - 16bit - 32bit
}hi_fb_graphics_layer_param_t;

/********************************************************************************************
* �� �� ����	HI_FB_Init
* ��    �ܣ�	��ʼ��hifbģ��
* ��������
* ����ֵ��0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_Init();
/********************************************************************************************
* �� �� ����	HI_FB_UnInit
* ��    �ܣ�	����ʼ��hifbģ��
* ��������
* ����ֵ��0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_UnInit();

/********************************************************************************************
* �� �� ����	HI_FB_StartGraphicsLayer
* ��    �ܣ�	����ͼ�β�
* ������
		|--fb_handle���洢ͼ����Դ����Ļ�����ָ��
		|--pstGraphicsLayerParam��ͼ�����
* ����ֵ��0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_StartGraphicsLayer(hi_fb_handle *fb_handle, hi_fb_graphics_layer_param_t *pstGraphicsLayerParam);
/********************************************************************************************
* �� �� ����	HI_FB_StopGraphicsLayer
* ��    �ܣ�����ͼ�β�
* ������
		|--fb_handle���洢ͼ����Դ�ľ��
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_StopGraphicsLayer(hi_fb_handle fb_handle);
/********************************************************************************************
* �� �� ����	HI_FB_SetScreenOrigin
* ��    �ܣ�������Ļ��ʾλ��
* ������
		|--fb_handle���洢ͼ����Դ�ľ��
		|--stPoint	��λ������
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_SetScreenOrigin(hi_fb_handle fb_handle, hi_fb_point_t stPoint);
/********************************************************************************************
* �� �� ����	HI_FB_ShowScreen
* ��    �ܣ���ʾ/������Ļ
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--i8ShowFlag	��0-���� 1-��ʾ
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_ShowScreen(hi_fb_handle fb_handle, uint8_t i8ShowFlag);
/********************************************************************************************
* �� �� ����	HI_FB_ShowScreen
* ��    �ܣ���ʾ/������Ļ
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--pstScreenInfo���洢��Ļ��Ϣ
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_GetScreeInfo(hi_fb_handle fb_handle, hi_fb_screen_info_t *pstScreenInfo);
/********************************************************************************************
* �� �� ����	HI_FB_ClearScreen
* ��    �ܣ���ʱ��Ч
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--stScreenInfo	����Ļ��Ϣ
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_SetScreeInfo(hi_fb_handle fb_handle, hi_fb_screen_info_t stScreenInfo);
/********************************************************************************************
* �� �� ����	HI_FB_ShowScreen
* ��    �ܣ�����
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_ClearScreen(hi_fb_handle fb_handle);

#ifdef __cplusplus
#if __cplusplus
};
#endif
#endif

#endif