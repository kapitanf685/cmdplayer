#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <dshow.h>
#include <strmif.h>
#include <control.h>
#include <winuser.h>

#pragma comment(lib, "ole32")
#pragma comment(lib, "strmiids")
#pragma comment(lib, "user32")

using namespace std;

wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
    wchar_t* wString=new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}

int main(int argc, char** argv)
{

    cout << "cmdplayer v0.3" << endl;
    
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

    //***************
    //CLSID_FileSource
    //***************
    if (argc<=1)
    {
        goto endprogram;
    }    
    LPCWSTR filename = convertCharArrayToLPCWSTR(argv[1]);
    hr = gbuilder->RenderFile(filename,NULL);
    if (FAILED(hr)) 
    {
        cout << "RenderFile failed." << endl;
        goto endprogram;
    }    

    RECT desktoprect;
    GetWindowRect(GetDesktopWindow(), &desktoprect);    
    window0->SetWindowPosition(0, 0, desktoprect.right - desktoprect.left, desktoprect.bottom - desktoprect.top);
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

    control->Stop();

    endprogram:
        control->Release();
        event->Release();
        gbuilder->Release();    
}