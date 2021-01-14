//-----------------------------------------------------------------------------
//   swmm5.h
//
//   Project: EPA SWMM5
//   Version: 5.1
//   Date:    03/24/14  (Build 5.1.001)
//            08/01/16  (Build 5.1.011)
//   Author:  L. Rossman
//
//   Prototypes for SWMM5 functions exported to swmm5.dll.
//
//-----------------------------------------------------------------------------

#ifndef SWMM5_H
#define SWMM5_H

// --- define WINDOWS

#undef WINDOWS
#ifdef _WIN32
  #define WINDOWS
#endif
#ifdef __WIN32__
  #define WINDOWS
#endif

// --- define DLLEXPORT

//#ifndef DLLEXPORT
#ifdef WINDOWS
	#ifdef __MINGW32__
		// Seems to be more wrapper friendly
		#define DLLEXPORT __declspec(dllexport) __cdecl
	#else
		#define DLLEXPORT __declspec(dllexport) __stdcall
	#endif
#else
	#define DLLEXPORT
#endif
//#endif


//-----------------------------------------------------------------------------
//  Shared variables
//-----------------------------------------------------------------------------
static int IsOpenFlag;           // TRUE if a project has been opened
static int IsStartedFlag;        // TRUE if a simulation has been started
static int SaveResultsFlag;      // TRUE if output to be saved to binary file

int swmm_IsOpenFlag(void);
int swmm_IsStartedFlag(void);


// --- use "C" linkage for C++ programs

#ifdef __cplusplus
extern "C" { 
#endif 

int  DLLEXPORT   swmm_run(char* f1, char* f2, char* f3);
int  DLLEXPORT   swmm_open(char* f1, char* f2, char* f3);
int  DLLEXPORT   swmm_start(int saveFlag);
int  DLLEXPORT   swmm_step(double* elapsedTime);
int  DLLEXPORT   swmm_end(void);
int  DLLEXPORT   swmm_report(void);
int  DLLEXPORT   swmm_getMassBalErr(float* runoffErr, float* flowErr,
                 float* qualErr);
int  DLLEXPORT   swmm_close(void);
int  DLLEXPORT   swmm_getVersion(void);
int  DLLEXPORT   swmm_getError(char* errMsg, int msgLen);
int  DLLEXPORT   swmm_getWarnings(void);

#ifdef __cplusplus 
}   // matches the linkage specification from above */ 
#endif

#endif
