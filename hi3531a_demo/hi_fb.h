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

typedef void* hi_fb_handle;

typedef struct _hi_fb_point_s{
	int32_t m_s32XPos;         /**<  horizontal position */
	int32_t m_s32YPos;         /**<  vertical position */
}hi_fb_point_t;

typedef struct _hi_fb_rect_s{
	int32_t m_s32XPos;         /**<  horizontal position */
	int32_t m_s32YPos;         /**<  vertical position */
	uint32_t m_u32Width;	   /**<  horizontal width */
	uint32_t m_u32Height;	   /**<  vertical height */
}hi_fb_rect_t;

//��������
typedef struct _hi_fb_canvas_s{
	uint32_t  m_u32PhyAddr;     /**<  start physical address */
	uint32_t  m_u32Width;       /**<  width pixels */
	uint32_t  m_u32Height;      /**<  height pixels */   
	uint32_t  m_u32Pitch;       /**<  line pixels */         
	char m_strColorFmt[16];		/**<  color format */ 
}hi_fb_canvas_t;

typedef struct _hi_fb_alpha_param_s{
	uint8_t m_bAlphaOverlay;	//����ʹ��
	uint8_t m_bAlphaChn;		//ͨ��ʹ��
	uint8_t m_u8OverlayValue0;	//RGB1555���λΪ1ʱ���ӵ�alphaֵ
	uint8_t m_u8OverlayValue1;	//RGB1555���λΪ0ʱ���ӵ�alphaֵ
	uint8_t m_u8ChnValue;		//ͨ��alphaֵ
}hi_fb_alpha_param_t;

typedef struct _hi_fb_colorkey_param_s{
	uint8_t m_bEnable;				//ʹ��colorkey����
	uint32_t m_u32ColorKeyValue;	//colorkeyֵ
}hi_fb_colorkey_param_t;

//��׼��ʾ����
typedef struct _hi_fb_pan_display_param_s{
	uint32_t m_u32PosX;				//��ʾ����ʼλ��X����posx + ʵ�ʷֱ��� ���ܴ����������ֱ���
	uint32_t m_u32PosY;				//��ʾ����ʼλ��Y����posx + ʵ�ʷֱ��� ���ܴ����������ֱ���
}hi_fb_pan_display_param_t;

//��չ��ʾ����
typedef struct _hi_fb_refresh_param_s{
	hi_fb_canvas_t m_stCanvas;				//��������
	hi_fb_rect_t m_stRefreshRect;			//ˢ������
}hi_fb_refresh_param_t;

typedef struct _hi_fb_screen_info_s{
	uint32_t m_u32DisResWidth;				//�豸��ʾ�ֱ��ʿ�
	uint32_t m_u32DisResHeight;				//�豸��ʾ�ֱ��ʸ�
	uint32_t m_u32MaxVirtualResWidth;		//�������ֱ��ʿ�
	uint32_t m_u32MaxVirtualResHeight;		//�������ֱ��ʸ�
	uint32_t m_u32BitsPerPixel;				//λ�� 8bit - 16bit - 32bit
	uint32_t m_u32ScreenStride;				//��Ļ���
	uint32_t m_u32PhyAddr;					//��Ļ�����ַ
	void *m_pVirAddr;						//��Ļ�����ַ
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
* �� �� ����	HI_FB_GetScreeInfo
* ��    �ܣ���ȡ��Ļ��Ϣ
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--pstScreenInfo���洢��Ļ��Ϣ
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_GetScreeInfo(hi_fb_handle fb_handle, hi_fb_screen_info_t *pstScreenInfo);
/********************************************************************************************
* �� �� ����	HI_FB_SetScreeInfo
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
/********************************************************************************************
* �� �� ����	HI_FB_GetAlpha
* ��    �ܣ���ȡalpha����
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--pstAplphaParam���洢alpha������ַ
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_GetAlpha(hi_fb_handle fb_handle,hi_fb_alpha_param_t *pstAplphaParam);
/********************************************************************************************
* �� �� ����	HI_FB_SetAlpha
* ��    �ܣ�����alpha����
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--stAplphaParam: alpha����
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_SetAlpha(hi_fb_handle fb_handle,hi_fb_alpha_param_t stAplphaParam);

/********************************************************************************************
* �� �� ����	HI_FB_GetColorkey
* ��    �ܣ���ȡcolorkey����
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--pstColorkeyParam���洢colorkey������ַ
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_GetColorkey(hi_fb_handle fb_handle,hi_fb_colorkey_param_t *pstColorkeyParam);
/********************************************************************************************
* �� �� ����	HI_FB_SetColorkey
* ��    �ܣ�����colorkey����
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--stColorkeyParam: colorkey����
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_SetColorkey(hi_fb_handle fb_handle,hi_fb_colorkey_param_t stColorkeyParam);
/********************************************************************************************
* �� �� ����	HI_FB_PanDisplay
* ��    �ܣ���ȡ��Ļ���Դ滺������ʾ��λ��
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--stPanDisplayParam: ƽ����ʾ��λ�ò�����ַ
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_GetPanDisplay(hi_fb_handle fb_handle, hi_fb_pan_display_param_t *pstPanDisplayParam);
/********************************************************************************************
* �� �� ����	HI_FB_PanDisplay
* ��    �ܣ�ƽ����ʾ�����Դ���������
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--stColorkeyParam: colorkey����
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_SetPanDisplay(hi_fb_handle fb_handle, hi_fb_pan_display_param_t stPanDisplayParam);
/********************************************************************************************
* �� �� ����	HI_FB_RefreshRect
* ��    �ܣ�ˢ��ָ�����������
* ������
		|--fb_handle	���洢ͼ����Դ�ľ��
		|--stColorkeyParam: colorkey����
* ����ֵ��	0-�ɹ�������ֵ-ʧ��
********************************************************************************************/
int32_t HI_FB_RefreshRect(hi_fb_handle fb_handle, hi_fb_refresh_param_t stRefreshRectParam);

#ifdef __cplusplus
#if __cplusplus
};
#endif
#endif

#endif