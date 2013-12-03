// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MOTICAPI_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MOTICAPI_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MOTICAPI_EXPORTS
#define MOTICAPI __declspec(dllexport)
#else
#define MOTICAPI __declspec(dllimport)
#endif

#include "MoticUCam.h"

/**
* To find a camera supported by MUCam. This function will search for an unused camera. If find a camera then
* return its handle, otherwise return 0. The returned camera object is uninitialized. It should be released
* by MUCam_releaseCamera function after use. The search order is not fixed. Continuously invoke this function
* until it returns 0 to find all connected cameras.
*
* @return  The camera handle if successful, 0 if failed.
*
* @see MUCam_openCamera, MUCam_releaseCamera
*/
MOTICAPI MUCam_Handle Motic_FindCamera();

/**
* To release a camera object. It is unnecessary to close the camera before releasing it.
*
* @param camera   The camera handle, not valid after return.
*
* @see MUCam_findCamera
*/
MOTICAPI void Motic_ReleaseCamera(MUCam_Handle camera);

/**
* To get the camera identifier. The function can be invoked without opening the camera.
*
* @param camera  The camera handle.
*
* @return  The camera identifier.
*
* @see MUCam_Type
*/
MOTICAPI MUCam_Type Motic_GetType(MUCam_Handle camera);

/**
* To open the camera. The camera should be opened before use it. The camera status after opening is
* uncertain, the application should set all the camera status parameters before capturing an image.
* The function will return "true" when it is invoked to open an opened camera.
*
* @param camera  The camera handle.
*
* @return  True if successful; False if failed.
*
* @see MUCam_closeCamera
*/
MOTICAPI bool Motic_OpenCamera(MUCam_Handle camera);

/**
* To close the opened camera. The closed camera can be re-opened. The MUCam_releaseCamera function should
* be invoked to release all resources associated with a camera.
*
* @param camera  The camera handle.
*
* @see MUCam_releaseCamera
*/
MOTICAPI void Motic_CloseCamera(MUCam_Handle camera);

/**
* To get the image format exported by the camera.
*
* @param camera  The camera handle.
*
* @return  The image format.
*/
MOTICAPI MUCam_Format Motic_GetFrameFormat(MUCam_Handle camera);

/**
* To grab a frame
*
* @param camera  The camera handle.
* @param buf     The frame buffer, must be large enough to hold the image data.
* @param ts      The pointer to the buffer that will receive time stamp(ms) of the frame. Might be 0 when it is not used.
*
* @return  True if successful; False if failed.
*
* @see MUCam_getFrameFormat
*/
MOTICAPI bool Motic_GetFrame(MUCam_Handle camera, unsigned char *buf, unsigned long *ts);

/**
* Set bit depth of image data.
*
* After setting bit depth, the captured images will be stored according to the bit depth.
* The processing of data byte order is fulfilled by MUCam automatically.
* The image data acquired by the application will be within the range defined by bit depth.
*
* @param camera  The camera handle
* @param bit     Bit count, e.g.
*	              @li @c 8 means 8 bits per channel, stored in 1 byte.
*	              @li @c 10 means 10 bits per channel, stored in 2 bytes.
*                @li @c 16 means 16 bits per channel, stored in 2 bytes.
*
* @return  True if successful; False if failed.
*
* @attention  All MUCam cameras support 8-bit depth format; only some support other bit depth format.
*
*/
MOTICAPI bool Motic_SetBitCount(MUCam_Handle camera, int bit);

/**
* To get the count of binning supported by the camera.
*
* @param camera  The camera handle.
*
* @return  The count of binning.
*/
MOTICAPI int Motic_GetBinningCount(MUCam_Handle camera);

/**
* To get the image size of each binning. The image sizes are in descending order, the full resolution size is w[0] and h[0].
*
* @param camera  The camera handle.
* @param w       The integer array that will receive the image width(pixel) of each binning. Must be large enough to hold all the data.
* @param h       The integer array that will receive the image height(pixel) of each binning. Must be large enough to hold all the data.
*
* @return       True if successful; False if failed.
*
* @see MUCam_getBinningCount
*/
MOTICAPI bool Motic_GetBinningList(MUCam_Handle camera, int *w, int *h);

/**
* To get the type of each binning.
*
* @param camera  The camera handle.
* @param tl      The MUCam_Binning_Type array that will receive the type of each binning. Must be large enough to hold all the data.
*
* @return        True if successful; False if failed.
*
* @see MUCam_getBinningCount MUCam_Binning_Type
*/
MOTICAPI bool Motic_GetBinningType(MUCam_Handle camera, MUCam_Binning_Type *tl);

/**
* To set the index of the selected binning.
*
* @param camera  The camera handle.
* @param idx     The 0-based index of binning.
*
* @return        True if successful; False if failed.
*
* @see MUCam_getBinningCount
*/
MOTICAPI bool Motic_SetBinningIndex(MUCam_Handle camera, int idx);

/**
* To set the ROI(region of interest) of the camera. The input coordinates are based on the size of currently
* exported image, without consideration of the current binning, ROI, flip and mirror settings. The top-left
* corner of currently exported image is (0,0), the bottom-right is (W-1, H-1). If the function returns successfully,
* the input coordinate parameters will be transformed to be based on camera sensor matrix, and its value might be adjusted.
*
* The ROI image width will be adjusted to align on 4-byte boundary for rendering optimization on Windows.
*
* @param camera  The camera handle.
* @param top     The 0-based top coordinate(pixel). After successful return, it will be the coordinate on sensor matrix.
* @param left    The 0-based left coordinate(pixel). After successful return, it will be the coordinate on sensor matrix.
* @param bottom  The 0-based bottom coordinate(pixel). After successful return, it will be the coordinate on sensor matrix.
*                The bottom-top+1 equals the width(pixel) of ROI.
* @param right   The 0-based right coordinate(pixel). After successful return, it will be the coordinate on sensor matrix.
*                The right-left+1 equals the height(pixel) of ROI.
*
* @return        True if successful; False if failed.
*
* @see MUCam_getFrame
*/
MOTICAPI bool Motic_SetROI(MUCam_Handle camera, int *top, int *left, int *bottom, int *right);

/**
* To flip the camera image.
*
* @param camera  The camera handle.
* @param b       The flip setting.
*
* @return        True if successful; False if failed.
*/
MOTICAPI bool Motic_SetFlip(MUCam_Handle camera, bool b);

/**
* To mirror the camera image.
*
* @param camera  The camera handle.
* @param b       The mirror setting.
*
* @return        True if successful; False if failed.
*/
MOTICAPI bool Motic_SetMirror(MUCam_Handle camera, bool b);

/**
* To get the count of the gain supported by camera. The camera gain is a series of discrete values, the application only can select one of them.
*
* @param camera  The camera handle.
*
* @return        The count of the gain supported by camera.
*/
MOTICAPI int Motic_GetGainCount(MUCam_Handle camera);

/**
*
* To get the gain value list.
*
* @param camera  The camera setting.
* @param g       The float array, must be big enough to contain data.
*
* @return        True if successful; False if failed.
*
* @see MUCam_getGainCount
*/
MOTICAPI bool Motic_GetGainList(MUCam_Handle camera, float *g);

/**
* To set the gain index of RGB channel.
*
* @param camera  The camera handle.
* @param r       The 0-based gain index of red channel.
* @param g       The 0-based gain index of green channel.
* @param b       The 0-based gain index of blue channel.
*
* @return        True if successful; False if failed.
*
* @attention  Some camears don't support different gain values in RGB channels. The function will return true only when the parameters r,g,b are the same.
*
* @see MUCam_getGainCount
*/
MOTICAPI bool Motic_SetRGBGainIndex(MUCam_Handle camera, int r, int g, int b);

/**
* @code
*
* void doWhiteBalance()
* {
*   ROI = getROI();
*   for (1 to 3)
*   {
*     Image = grabImage();
*     CalculateWhiteBalance(Image, ROI, &redGain, &greenGain, &blueGain);
*     if (redGain != 1 && greenGain != 1 && blueGain != 1)
*     {
*       redGain   *= gainValue[currentRedGainIndex];
*       greenGain *= gainValue[currentGreenGainIndex];
*       blueGain  *= gainValue[currentBlueGainIndex];
*
*       MUCam_setRGBGainValue(camera, redGain, greenGain, blueGain, &currentRedGainIndex, &currentGreenGainIndex, &currentBlueGainIndex);
*     }
*     else
*     {
*       break;
*     }
*   }
* }
*
* @endcode
*
*
* To set the gain value of RGB channel. When the application calculated the expected gain value(eg. do white-balance processing)
* it could invoke the function to set the gain value directly. The function will find the closest gain value in gain value list, and
* return the index actual set. Because the camera hardware gain is not an exact multiply calculation, the application could invoke the
* function several times to get better result. The above-mentioned sample code shows the precedure.
*
* The white-balance of image is influenced by the light source. The application should re-calculate white-balance gain value after changing
* the light source. But, the exposure time does not affect the white-balance status. It is suggested that the application adjusts exposure
* time instead of changing the light source.
*
* @param camera  The camera handle.
* @param r       The expected gain value of red channel.
* @param g       The expected gain value of green channel.
* @param b       The expected gain value of blue channel.
* @param ri      The pointer to the buffer that will receive the gain index of red channel. Might be 0 when it is not used.
* @param gi      The pointer to the buffer that will receive the gain index of green channel. Might be 0 when it is not used.
* @param bi      The pointer to the buffer that will receive the gain index of blue channel. Might be 0 when it is not used.
*
* @return        True if successful; False if failed.
*
* @attention     Some camears don't support different gain values in RGB channels. The function will return true only when the parameters r,g,b are the same.
*
* @see MUCam_getGainCount, MUCam_setRGBGainIndex
*/
MOTICAPI bool Motic_SetRGBGainValue(MUCam_Handle camera, float r, float g, float b, int *ri, int *gi, int *bi);

/**
*
* To get the offset range of the camera.
*
* @param camera  The camera handle.
* @param min     The pointer to the buffer that will receive the minimum offset value.
* @param max     The pointer to the buffer that will receive the maximum offset value.
*
* @return        True if successful; False if failed.
*
* @attention   The offset value is not based on gray level. It just means the offset effect that can be achieved by the camera.
*/
MOTICAPI bool Motic_GetOffsetRange(MUCam_Handle camera, int *min, int *max);

/**
*
* To set the offset value of RGB channel.
*
* @attention   The offset value is not based on gray level, eg. the offset 100 does not mean the actual pixel gray level can be increased 100.
*
* @param camera  The camera handle.
* @param r       The offset value of red channel.
* @param g       The offset value of green channel.
* @param b       The offset value of blue channel.
*
* @return        True if successful; False if failed.
*
* @attention  Some camears don't support different offset values in RGB channels. The function will return true only when the parameters r, g, b are the same.
*
* @see MUCam_getOffsetRange
*/
MOTICAPI bool Motic_SetRGBOffset(MUCam_Handle camera, int r, int g, int b);

/**
*
* To get the current exposure time range of the camera. The setting of binning and ROI will change the exposure time range, the application
* should have a check after finishing these settings.
*
* @param camera  The camera handle.
* @param min     The pointer to the buffer that will receive the minimum exposure value. For MC1002/2002, it's a value without unit; for other
*                camera, it's based on millisecond.
* @param max     The pointer to the buffer that will receive the maximum exposure value. For MC1002/2002, it's a value without unit; for other
*                camera, it's based on millisecond.
*
* @return        True if successful; False if failed.
*
* @see MUCam_setBinningIndex, MUCam_setROI
*/
MOTICAPI bool Motic_GetExposureRange(MUCam_Handle camera, float *min, float *max);

/**
* To set the exposure time of the camera.
*
* @attention  The exposure time should be set after setting binning or ROI.
*
* @param camera  The camera handle.
* @param t       The exposure time.
*
* @return        True if successful; False if failed.
*
* @see MUCam_getExposureRange, MUCam_setBinningIndex, MUCam_setROI
*/
MOTICAPI bool Motic_SetExposure(MUCam_Handle camera, float t);

/**
* To check whether the camera is still connected. Invoke this function to check whether the camera has been un-plugged
* if failed to get image from camera many times.
*
* @param camera  The camera handle.
*
* @return        True if camera is connected; False if camera has been removed.
*/
MOTICAPI bool Motic_IsConnected(MUCam_Handle camera);

/**
* To check whether the cooler is available in the camera.
*
* @param camera  The camera handle.
*
* @return        True if the camera has a cooler; False if not.
*/
MOTICAPI bool Motic_IsCoolerAvailable(MUCam_Handle camera);

/**
* To activate or inactivate the cooler in the camera.
*
* @param camera  The camera handle.
* @param act     True for activating the cooler, false for inactivating.
*
* @return        Returns true if successful; false if failed.
*
* @see MUCam_isCoolerAvailable
*/
MOTICAPI bool Motic_ActivateCooler(MUCam_Handle camera, bool act);

/**
*
* To get the working frequency count supported by the camera.
*
* @param camera  The camera handle.
*
* @return        The count of working frequency. The available working frequency is from 0 to n-1, 0 means the fastest.
*/
MOTICAPI int Motic_GetFrequencyCount(MUCam_Handle camera);

/**
* To set the working frequency index of the camera.
*
* @param camera  The camera handle.
* @param level   The index of working frequency.
*
* @return        True if successful; False if failed.
*
* @see MUCam_getFrequencyCount
*/
MOTICAPI bool Motic_SetFrequencyIndex(MUCam_Handle camera, int level);

/**
*
* To get current working frequency index of the camera.
*
* @param camera  The camera handle.
*
* @return        Current working frequency index.
*/
MOTICAPI int Motic_GetFrequencyIndex(MUCam_Handle camera);

/**
* To set the trigger mode of the camera.
*
* @param camera  The camera handle.
* @param type    The type of trigger mode.
*
* @return   True if successful; False if failed.
*
* @see MUCam_Trigger_Type
*/
MOTICAPI bool Motic_SetTriggerType(MUCam_Handle camera, MUCam_Trigger_Type type);

/**
* To get Temperature and humidity values.Only part of cameras support the function.
*
* @param camrea  The camera handle
* @param st      Sensor surface temperature (degrees Celsius)
* @param at      Ambient temperature (degrees Celsius)
* @param rh      Relative humidity
*
* @return   True if successful; False if failed.
*/
MOTICAPI bool Motic_GetTemperature(MUCam_Handle camera, float* st, float*at, float*rh);