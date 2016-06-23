// openCV_DLL_00.cpp : Defines the exported functions for the DLL application.
//

#include <stdafx.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "openCV_DLL_00.h"
#include "opencv2/highgui/highgui.hpp"




#pragma region function

using namespace cv;
using namespace std;

enum {
	CAP_PROP_POS_MSEC = 0,
	CAP_PROP_POS_FRAMES = 1,
	CAP_PROP_POS_AVI_RATIO = 2,
	CAP_PROP_FRAME_WIDTH = 3,
	CAP_PROP_FRAME_HEIGHT = 4,
	CAP_PROP_FPS = 5,
	CAP_PROP_FOURCC = 6,
	CAP_PROP_FRAME_COUNT = 7,
	CAP_PROP_FORMAT = 8,
	CAP_PROP_MODE = 9,
	CAP_PROP_BRIGHTNESS = 10,
	CAP_PROP_CONTRAST = 11,
	CAP_PROP_SATURATION = 12,
	CAP_PROP_HUE = 13,
	CAP_PROP_GAIN = 14,
	CAP_PROP_EXPOSURE = 15,
	CAP_PROP_CONVERT_RGB = 16,
	CAP_PROP_WHITE_BALANCE_BLUE_U = 17,
	CAP_PROP_RECTIFICATION = 18,
	CAP_PROP_MONOCHROME = 19,
	CAP_PROP_SHARPNESS = 20,
	CAP_PROP_AUTO_EXPOSURE = 21,
	CAP_PROP_GAMMA = 22,
	CAP_PROP_TEMPERATURE = 23,
	CAP_PROP_TRIGGER = 24,
	CAP_PROP_TRIGGER_DELAY = 25,
	CAP_PROP_WHITE_BALANCE_RED_V = 26,
	CAP_PROP_ZOOM = 27,
	CAP_PROP_FOCUS = 28,
	CAP_PROP_GUID = 29,
	CAP_PROP_ISO_SPEED = 30,
	CAP_PROP_BACKLIGHT = 32,
	CAP_PROP_PAN = 33,
	CAP_PROP_TILT = 34,
	CAP_PROP_ROLL = 35,
	CAP_PROP_IRIS = 36,
	CAP_PROP_SETTINGS = 37,
	CAP_PROP_BUFFERSIZE = 38,
	CAP_PROP_AUTOFOCUS = 39
}

namespace CAMLIBRARY
{
	int CamFuncs::InitializeCameraAsync(int CamID,double CamMSEC, double CamFRAME, double CamExpo, double CamFocus)//,int Msec,int FPS,int CamExp,int CamFocus)
	{
			
		VideoCapture cap(CamID); // open the video camera no. 0
		cap.set(CAP_PROP_POS_MSEC, CamMSEC);
		cap.set(CAP_PROP_POS_FRAMES, CamFRAME);
		cap.set(CAP_PROP_EXPOSURE, CamExpo);
		cap.get(CAP_PROP_FOCUS, CamFocus);
				
		if (!cap.isOpened())  // if not success, exit program
		{
			return -1;
		}

		return 0;
	}
	
	bool CamFuncs::StopPreviewAsync(void)
	{
		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			return true;
		}
		return false;
	}

	int CamFuncs::StartPreviewAsync(int CamID)
	{
		VideoCapture cap(CamID); // open the video camera no. 0
		double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
		double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
		namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
		/*while()	*/
		
	
		while (1)
		{
			Mat frame;

			bool bSuccess = cap.read(frame); // read a new frame from video
			if (!bSuccess) //if not success, break loop
			{
			
				break;
			}
			
			imshow("test", frame); //show the frame in "MyVideo" window
									  
			if (waitKey(30) == 27)
			{
				break;
			}
		}

		return 0;

	}






}
#pragma endregion










