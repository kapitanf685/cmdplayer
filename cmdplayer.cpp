#include <iostream>
#include <stdio.h>
<<<<<<< HEAD
#include <windows.h>
#include <dshow.h>
#include <strmif.h>
#include <control.h>
#include <winuser.h>

#pragma comment(lib, "ole32")
#pragma comment(lib, "strmiids")
#pragma comment(lib, "user32")

using namespace std;

=======

#include <control.h>

#include <dshow.h>
#include <strmif.h>
#include <evr.h>

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "strmiids.lib")

using namespace std;

#include "vpxdecoderidl.h"

>>>>>>> 171c81a (Uploding files)
wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
    wchar_t* wString=new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}

<<<<<<< HEAD
int main(int argc, char** argv)
{
    cout << "cmdplayer v0.3" << endl;
=======
RECT WindowRect(int xpos,int ypos,int width,int height)
{
    RECT rect;

    rect.left = xpos;
    rect.top = ypos;
    rect.right = width-xpos;
    rect.bottom = height-ypos;

    return rect;
}

int main(int argc, char** argv)
{    
    cout << "cmdplayer v0.0" << endl;
>>>>>>> 171c81a (Uploding files)
    
    int hr = CoInitialize(NULL);
    if (FAILED(hr)) 
    {
        cout << "Initialization of COM Object failed." << endl;
        goto endprogram;
    }

    IGraphBuilder *gbuilder;
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IFilterGraph, (void**)&gbuilder);
    if (FAILED(hr)) 
    {
        cout << "CreateInstance of GraphBuilder failed." << endl;
        goto endprogram;
    }    

<<<<<<< HEAD
    IMediaControl *control;
    IMediaEvent *event;
    hr = gbuilder->QueryInterface(IID_IMediaControl, (void**)&control);    
    if (FAILED(hr)) 
    {
        cout << "MediaControl of GraphBuilder failed." << endl;
        goto endprogram;
    }
    hr = gbuilder->QueryInterface(IID_IMediaEvent, (void**)&event);
    if (FAILED(hr))
    {
        cout << "MediaEvent of GraphBuilder failed." << endl;
        goto endprogram;
    }

   IBaseFilter* filter0;
   hr = CoCreateInstance(CLSID_VideoMixingRenderer, NULL, CLSCTX_INPROC_SERVER, IID_IBaseFilter, (void**)&filter0);
   if (FAILED(hr))
   {
       cout << "Create filter0 failed." << endl;
       goto endprogram;
   }
   hr = gbuilder->AddFilter(filter0, L"Decoder");
   if (FAILED(hr))
   {
       cout << "Addition filter0 to GraphBuilder failed." << endl;
       goto endprogram;
   }

   IVideoWindow* window0;
   hr = filter0->QueryInterface(IID_IVideoWindow, (void**)&window0);
   if (FAILED(hr))
    {
        cout << "VideoWindow of GraphBuilder failed." << endl;
        goto endprogram;
    }  
=======
    IMediaControl *control;    
    hr = gbuilder->QueryInterface(IID_IMediaControl, (void**)&control);    
    if (FAILED(hr)) 
    {
        cout << "MediaControl failed." << endl;
        goto endprogram;
    }
    
    IMediaEvent *event;
    hr = gbuilder->QueryInterface(IID_IMediaEvent, (void**)&event);
    if (FAILED(hr)) 
    {
        cout << "MediaEvent failed." << endl;
        goto endprogram;
    }
    /*IBasicVideo *video;
    hr = gbuilder->QueryInterface(IID_IBasicVideo,(void**)&video);
    if (FAILED(hr)) 
    {
        cout << "BasicVideo failed." << endl;
        goto endprogram;
    }*/
>>>>>>> 171c81a (Uploding files)

    //***************
    //CLSID_FileSource
    //***************
    if (argc<=1)
    {
        goto endprogram;
    }    
    LPCWSTR filename = convertCharArrayToLPCWSTR(argv[1]);
<<<<<<< HEAD
=======

>>>>>>> 171c81a (Uploding files)
    hr = gbuilder->RenderFile(filename,NULL);
    if (FAILED(hr)) 
    {
        cout << "RenderFile failed." << endl;
        goto endprogram;
<<<<<<< HEAD
    }    

    RECT window0_rect;
    GetWindowRect(GetDesktopWindow(), &window0_rect);
    window0->SetWindowPosition(0, 0, window0_rect.right - window0_rect.left, window0_rect.bottom - window0_rect.top);
    window0->put_WindowStyle(WS_EX_COMPOSITED);

    if (SUCCEEDED(hr))
    { 
        cout << "Press CTRL+C to exit playing..." << endl;
        hr = control->Run();
        if (SUCCEEDED(hr))
        {
                long EvCode;
                event->WaitForCompletion(-1, &EvCode);
        }      
    }

=======
    }

    IBaseFilter *filter0;        
    hr = CoCreateInstance(CLSID_VideoMixingRenderer, NULL, CLSCTX_INPROC, IID_IBaseFilter, (void**)&filter0);
    if (FAILED(hr)) 
    {
        cout << "Filter0 failed." << endl;
        goto endprogram;
    }

    hr = gbuilder->AddFilter(filter0, L"Video Mixing Renderer");
    if (FAILED(hr)) 
    {
        cout << "Filter0 addition failed." << endl;
        goto endprogram;
    }
    
    IVMRFilterConfig *config0;
    hr = filter0->QueryInterface(IID_IVMRFilterConfig,(void**)&config0);    
    if (FAILED(hr)) 
    {
        cout << "MFVideoRenderer Filter0 failed." << endl;
        goto endprogram;
    }

    config0->SetRenderingMode(VMRMode::VMRMode_Windowless);    
    IVMRWindowlessControl* wlc = NULL;
    hr = config0->QueryInterface(IID_IVMRWindowlessControl, (void**)&wlc);
    if (FAILED(hr)) 
    {
        cout << "WLC Filter0 failed." << endl;
        goto endprogram;
    }

    config0->SetNumberOfStreams(0);    

    //  wlc->SetVideoPosition(0,&WindowRect(0,0,1920,1080));
  

    hr = control->Run();
    if (FAILED(hr)) 
    {
        cout << "Running Control failed." << endl;
        goto endprogram;
    } 

    long pEvCode;
    hr = NULL;
    hr = event->WaitForCompletion(INFINITY, &pEvCode);
   
    system("pause");

>>>>>>> 171c81a (Uploding files)
    control->Stop();

    endprogram:
        control->Release();
        event->Release();
<<<<<<< HEAD
        gbuilder->Release();    
=======
        gbuilder->Release();            
>>>>>>> 171c81a (Uploding files)
}