/****************************** Module Header ******************************\
Module Name:  openCV_DLL_00.h
Project:      OpenCV CppDynamicLinkLibrary
Copyright (c) Chowarat I.

\***************************************************************************/


#pragma once

#ifdef CAMLIBRARY_EXPORTS
#define CAMLIBRARY_API __declspec(dllexport)
#else
#define CAMLIBRARY_API __declspec(dllimport)
#endif



namespace CAMLIBRARY
{
	
	class CamFuncs
	{
	public:
		static CAMLIBRARY_API int InitializeCameraAsync(int CamID, double CamExpo);
		//int CleanupCameraAsync();
		static CAMLIBRARY_API int StartPreviewAsync(int CamID);
		//int SetPreviewRotationAsync();
		static CAMLIBRARY_API bool StopPreviewAsync(void);
		//int TakePhotoAsync();
		//int StartRecordingAsync();
		//int StopRecordingAsync();

	private:
	

	};

}









