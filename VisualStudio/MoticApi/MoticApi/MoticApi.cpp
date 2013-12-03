// MoticApi.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MoticApi.h"

MOTICAPI MUCam_Handle Motic_FindCamera()
{
	return MUCam_findCamera();
}

MOTICAPI MUCam_Type Motic_GetType(MUCam_Handle camera)
{
	return MUCam_getType(camera);
}

MOTICAPI void Motic_ReleaseCamera(MUCam_Handle camera)
{
	return MUCam_releaseCamera(camera);
}

MOTICAPI bool Motic_OpenCamera(MUCam_Handle camera)
{
	return MUCam_openCamera(camera);
}

MOTICAPI void Motic_CloseCamera(MUCam_Handle camera)
{
	return MUCam_closeCamera(camera);
}

MOTICAPI MUCam_Format Motic_GetFrameFormat(MUCam_Handle camera)
{
	return MUCam_getFrameFormat(camera);
}

MOTICAPI bool Motic_GetFrame(MUCam_Handle camera, unsigned char *buf, unsigned long *ts)
{
	return MUCam_getFrame(camera, buf, ts);
}

MOTICAPI bool Motic_SetBitCount(MUCam_Handle camera, int bit)
{
	return MUCam_setBitCount(camera, bit);
}

MOTICAPI int Motic_GetBinningCount(MUCam_Handle camera)
{
	return MUCam_getBinningCount(camera);
}

MOTICAPI bool Motic_GetBinningList(MUCam_Handle camera, int *w, int *h)
{
	return MUCam_getBinningList(camera, w, h);
}

MOTICAPI bool Motic_GetBinningType(MUCam_Handle camera, MUCam_Binning_Type *tl)
{
	return MUCam_getBinningType(camera, tl);
}

MOTICAPI bool Motic_SetBinningIndex(MUCam_Handle camera, int idx)
{
	return MUCam_setBinningIndex(camera, idx);
}

MOTICAPI bool Motic_SetROI(MUCam_Handle camera, int *top, int *left, int *bottom, int *right)
{
	return MUCam_setROI(camera, top, left, bottom, right);
}

MOTICAPI bool Motic_SetFlip(MUCam_Handle camera, bool b)
{
	return MUCam_setFlip(camera, b);
}

MOTICAPI bool Motic_SetMirror(MUCam_Handle camera, bool b)
{
	return MUCam_setMirror(camera, b);
}

MOTICAPI int Motic_GetGainCount(MUCam_Handle camera)
{
	return MUCam_getGainCount(camera);
}

MOTICAPI bool Motic_GetGainList(MUCam_Handle camera, float *g)
{
	return MUCam_getGainList(camera, g);
}

MOTICAPI bool Motic_SetRGBGainIndex(MUCam_Handle camera, int r, int g, int b)
{
	return MUCam_setRGBGainIndex(camera, r, g, b);
}

MOTICAPI bool Motic_SetRGBGainValue(MUCam_Handle camera, float r, float g, float b, int *ri, int *gi, int *bi)
{
	return MUCam_setRGBGainValue(camera, r, g, b, ri, gi, bi);
}


MOTICAPI bool Motic_GetOffsetRange(MUCam_Handle camera, int *min, int *max)
{
	return MUCam_getOffsetRange(camera, min, max);
}

MOTICAPI bool Motic_SetRGBOffset(MUCam_Handle camera, int r, int g, int b)
{
	return MUCam_setRGBOffset(camera, r, g, b);
}

MOTICAPI bool Motic_GetExposureRange(MUCam_Handle camera, float *min, float *max)
{
	return MUCam_getExposureRange(camera, min, max);
}

MOTICAPI bool Motic_SetExposure(MUCam_Handle camera, float t)
{
	return MUCam_setExposure(camera, t);
}

MOTICAPI bool Motic_IsConnected(MUCam_Handle camera)
{
	return MUCam_isConnected(camera);
}

MOTICAPI bool Motic_IsCoolerAvailable(MUCam_Handle camera)
{
	return MUCam_isCoolerAvailable(camera);
}

MOTICAPI bool Motic_ActivateCooler(MUCam_Handle camera, bool act)
{
	return MUCam_activateCooler(camera, act);
}

MOTICAPI int Motic_GetFrequencyCount(MUCam_Handle camera)
{
	return MUCam_getFrequencyCount(camera);
}

MOTICAPI bool Motic_SetFrequencyIndex(MUCam_Handle camera, int level)
{
	return MUCam_setFrequencyIndex(camera, level);
}

MOTICAPI int Motic_GetFrequencyIndex(MUCam_Handle camera)
{
	return MUCam_getFrequencyIndex(camera);
}

MOTICAPI bool Motic_SetTriggerType(MUCam_Handle camera, MUCam_Trigger_Type type)
{
	return MUCam_setTriggerType(camera, type);
}

MOTICAPI bool Motic_GetTemperature(MUCam_Handle camera, float* st, float*at, float*rh)
{
	return MUCam_getTemperature(camera, st, at, rh);
}