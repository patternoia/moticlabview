#ifndef __MOTIC_UCAM_H__
#define __MOTIC_UCAM_H__

/**
 * @file
 *
 *
 * Motic Universal Camera API declaration file.
 */

/**
 * @mainpage Motic Universal Camera API
 *
 *
 * Motic Universal Camera API (MUCam) is a programming interface for various Motic USB 2.0 cameras. MUCam is "universal"
 * as it covers different camera features and can be used on Windows and MacOS X. On Windows it's a C dll (including 32-bit
 * and 64-bit version). On MacOS X it's a static library.
 *
 * On Windows the MUCam SDK includes MoticUCam.h, MUCam32.dll/lib, MUCam64.dll/lib files.
 * 
 */

/**
 * The camera object handle type. The handle is the "void *" type, never convert it to "int" or "long",
 * especially in 64-bit operating system.
 */
typedef void * MUCam_Handle;

/**
 * The camera identifier, used to determine camera name in an application.
 */
typedef enum
{
  /**
   * Unknown camera type.
   */
  MUCAM_TYPE_UNKNOWN,

  /**
   * MC1001 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 15(1280*1024) or 40(640*512).
   */
  MUCAM_TYPE_MC1001,

  /**
   * MC2001 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 10(1600*1200) or 30(800*600).
   */
  MUCAM_TYPE_MC2001,

  /**
   * MC3001 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 6(2048*1536) or 21(1024*768).
   */
  MUCAM_TYPE_MC3001,

  /**
   * MC2001B camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 10(1280*1024) or 30(640*512).
   */
  MUCAM_TYPE_MC2001B,

  /**
   * MC1002 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 14(1280*1024) or 52(640*512).
   */
  MUCAM_TYPE_MC1002,

  /**
   * MC2002 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 5(1600*1200) or 20(800*600).
   */
  MUCAM_TYPE_MC2002,

  /**
   * MA205 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 10(1360*1024).
   */
  MUCAM_TYPE_MA205,

  /**
   * MA285 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 15(1360*1024).
   */
  MUCAM_TYPE_MA285,

  /**
   * MA252 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 11(2048*1536).
   */
  MUCAM_TYPE_MA252,

  /**
   * Swift MC1002 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 14(1280*1024) or 52(640*512).
   */
  MUCAM_TYPE_SWIFT_MC1002,

  /**
   *
   * Undocumented.
   *
   * @deprecated Since MA252 added.
   */
  MUCAM_TYPE_MD3300,

  /**
   * MC5001 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 7(2592*1944) or 20(1296*972).
   */
  MUCAM_TYPE_MC5001,

  /**
   * MC3111 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images
   * the normal FPS is 13(1280*1024) or 40(640*480)
   */
  MUCAM_TYPE_MC3111,

  /**
   * MC3222 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images
   * the normal FPS is 10(1600*1200) or 30(800*600)
   */
  MUCAM_TYPE_MC3222,

  /**
   * MC3022 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images
   * the normal FPS is 7(1600*1200) or 20(800*600) 
   */
  MUCAM_TYPE_MC3022,

  /** 
   * Swift MC3001 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 6(2048*1536) or 21(1024*768).
   */
  MUCAM_TYPE_SWIFT_MC3001,

  /**
  * Swift MC3222 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images
  * the normal FPS is 10(1600*1200) or 30(800*600)
  */
  MUCAM_TYPE_SWIFT_MC3222,

  /**
  * Swift MC3111 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images
  * the normal FPS is 13(1280*1024) or 40(640*480)
  */
  MUCAM_TYPE_SWIFT_MC3111,
 
  /**
  * MA282 camera type. On Windows it exports BGR format images. On MacOS X it exports RGB format images.
  * The normal FPS is 6(2560*1920).
  */
  MUCAM_TYPE_MA282,

  /**
   * @brief MC352+ Camrea
   *  
   * Undocumented. Not available at present.
   */
  MUCAM_TYPE_MC352PLUS,

  /**
   * @brief MC3521
   *
   * Undocumented. Not available at present.   
   */
  MUCAM_TYPE_MC3521,

  /**   
   * MC10M camera type. On Windows/Linux it exports BGR format images. On MacOS X it exports RGB format images.
   * The normal FPS is 2.2(3664*2748) or 8.5(1832*1374) or 30(916*686).
   */
  MUCAM_TYPE_MC10M

} MUCam_Type;

/**
 * The camera exported image format definition.
 */
typedef enum
{
  /**
   * The bayer image format in GRBG pattern.
   */
  MUCAM_FORMAT_BAYER_GR_BG,
  /**
   * The bayer image format in BGGR pattern.
   */
  MUCAM_FORMAT_BAYER_BG_GR,
  /**
   * The bayer image format in GBRG pattern.
   */
  MUCAM_FORMAT_BAYER_GB_RG,
  /**
   * The bayer image format in RGGB pattern.
   */
  MUCAM_FORMAT_BAYER_RG_GB,
  /**
   * The RGB color image format.
   */
  MUCAM_FORMAT_COLOR_RGB,
  /**
   * The BGR color image format.
   */
  MUCAM_FORMAT_COLOR_BGR,
  /**
   * The monochrome image format.
   */
  MUCAM_FORMAT_MONOCHROME
} MUCam_Format;

/**
 * The camera binning type.
 */
typedef enum
{
  /**
   * Normal binning type.
   */
  MUCAM_BINNING_NORMAL,
  /**
   * The sampling type completed by software.
   */
  MUCAM_BINNING_SAMPLING,
  /**
   * The fast display type for high-resolution camera.
   */
  MUCAM_BINNING_FAST_DISPLAY
} MUCam_Binning_Type;

/**
 * The camera grab frame type.
 */
typedef enum
{
  /**
   * The trigger free mode. The SDk will automatically grab frames as soon as possible. It's the default mode when a camera opened.
   */
  MUCAM_TRIGGER_FREE,
  /**
   * The software trigger mode. Every time invoking MUCam_getFrame function will cause camera to exposure and transfer a frame data.
   */
  MUCAM_TRIGGER_SOFTWARE,
  /**
   * The external hardware trigger signal on TTL rise side.
   */
  MUCAM_TRIGGER_HARDWARE_RISE,
  /**
  * The external hardware trigger signal on TTL fall side.
  */
  MUCAM_TRIGGER_HARDWARE_FALL
} MUCam_Trigger_Type;

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
MUCam_Handle MUCam_findCamera();

/**
 * To release a camera object. It is unnecessary to close the camera before releasing it.
 *
 * @param camera   The camera handle, not valid after return.
 *
 * @see MUCam_findCamera
 */
void MUCam_releaseCamera(MUCam_Handle camera);

/**
 * To get the camera identifier. The function can be invoked without opening the camera.
 *
 * @param camera  The camera handle.
 *
 * @return  The camera identifier.
 *
 * @see MUCam_Type
 */
MUCam_Type MUCam_getType(MUCam_Handle camera);

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
bool MUCam_openCamera(MUCam_Handle camera);

/** 
 * To close the opened camera. The closed camera can be re-opened. The MUCam_releaseCamera function should
 * be invoked to release all resources associated with a camera.
 *
 * @param camera  The camera handle.
 *
 * @see MUCam_releaseCamera
 */
void MUCam_closeCamera(MUCam_Handle camera);

/**
 * To get the image format exported by the camera.
 *
 * @param camera  The camera handle.
 *
 * @return  The image format.
 */
MUCam_Format MUCam_getFrameFormat(MUCam_Handle camera);

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
bool MUCam_getFrame(MUCam_Handle camera, unsigned char *buf, unsigned long *ts);

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
bool MUCam_setBitCount(MUCam_Handle camera, int bit);

/**
 * To get the count of binning supported by the camera.
 *
 * @param camera  The camera handle.
 *
 * @return  The count of binning.
 */
int MUCam_getBinningCount(MUCam_Handle camera);

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
bool MUCam_getBinningList(MUCam_Handle camera, int *w, int *h);

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
bool MUCam_getBinningType(MUCam_Handle camera, MUCam_Binning_Type *tl);

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
bool MUCam_setBinningIndex(MUCam_Handle camera, int idx);

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
bool MUCam_setROI(MUCam_Handle camera, int *top, int *left, int *bottom, int *right);

/**
  * To flip the camera image.
 *
 * @param camera  The camera handle.
 * @param b       The flip setting.
 *
 * @return        True if successful; False if failed.
 */
bool MUCam_setFlip(MUCam_Handle camera, bool b);

/** 
 * To mirror the camera image.
 *
 * @param camera  The camera handle.
 * @param b       The mirror setting.
 *
 * @return        True if successful; False if failed.
 */
bool MUCam_setMirror(MUCam_Handle camera, bool b);

/**
 * To get the count of the gain supported by camera. The camera gain is a series of discrete values, the application only can select one of them.
 *
 * @param camera  The camera handle.
 *
 * @return        The count of the gain supported by camera.
 */
int MUCam_getGainCount(MUCam_Handle camera);

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
bool MUCam_getGainList(MUCam_Handle camera, float *g);

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
bool MUCam_setRGBGainIndex(MUCam_Handle camera, int r, int g, int b);

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
bool MUCam_setRGBGainValue(MUCam_Handle camera, float r, float g, float b, int *ri, int *gi, int *bi);

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
bool MUCam_getOffsetRange(MUCam_Handle camera, int *min, int *max);

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
bool MUCam_setRGBOffset(MUCam_Handle camera, int r, int g, int b);

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
bool MUCam_getExposureRange(MUCam_Handle camera, float *min, float *max);

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
bool MUCam_setExposure(MUCam_Handle camera, float t);

/** 
 * To check whether the camera is still connected. Invoke this function to check whether the camera has been un-plugged
 * if failed to get image from camera many times.
 *
 * @param camera  The camera handle.
 *
 * @return        True if camera is connected; False if camera has been removed.
 */
bool MUCam_isConnected(MUCam_Handle camera);

/** 
 * To check whether the cooler is available in the camera.
 *
 * @param camera  The camera handle.
 *
 * @return        True if the camera has a cooler; False if not.
 */
bool MUCam_isCoolerAvailable(MUCam_Handle camera);

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
bool MUCam_activateCooler(MUCam_Handle camera, bool act);

/**
 *
 * To get the working frequency count supported by the camera.
 *
 * @param camera  The camera handle.
 *
 * @return        The count of working frequency. The available working frequency is from 0 to n-1, 0 means the fastest.
 */
int MUCam_getFrequencyCount(MUCam_Handle camera);

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
bool MUCam_setFrequencyIndex(MUCam_Handle camera, int level);

/**
 *
 * To get current working frequency index of the camera.
 *
 * @param camera  The camera handle.
 *
 * @return        Current working frequency index.
 */
int MUCam_getFrequencyIndex(MUCam_Handle camera);

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
bool MUCam_setTriggerType(MUCam_Handle camera, MUCam_Trigger_Type type);

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
bool MUCam_getTemperature(MUCam_Handle camera, float* st, float*at, float*rh);
#endif // __MOTIC_UCAM_H__