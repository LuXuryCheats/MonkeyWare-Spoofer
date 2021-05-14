#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "xorstr.hpp"
#include <random>
#include "kdmapper/kdmapper.hpp"
#pragma comment(lib, "version.lib")
#include "driver.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <d3d9.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"

#define BLACK	7
#define BLUE	1
#define GREEN	2
#define CYAN	3
#define RED		12
#define PURPLE	5
#define AQUA    11 
#define WHITE	15
#define decrypt CTL_CODE(FILE_DEVICE_UNKNOWN, 0x1337, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define title "MonkeyWare"
#define WIDTH  300
#define HEIGHT 300

bool mainwindow = true;
HWND hWnd = nullptr;

LPDIRECT3DDEVICE9        pDevice;
D3DPRESENT_PARAMETERS    pD3Dpp;
LPDIRECT3D9              pD3D;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

bool CreateDeviceD3D(HWND hWnd)
{
    if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    ZeroMemory(&pD3Dpp, sizeof(pD3Dpp));
    pD3Dpp.Windowed = TRUE;
    pD3Dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    pD3Dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    pD3Dpp.EnableAutoDepthStencil = TRUE;
    pD3Dpp.AutoDepthStencilFormat = D3DFMT_D16;
    pD3Dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;     
    if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &pD3Dpp, &pDevice) < 0)
        return false;
    return true;
}

void CleanupDeviceD3D()
{
    if (pDevice) { pDevice->Release(); pDevice = NULL; }
    if (pD3D) { pD3D->Release(); pD3D = NULL; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = pDevice->Reset(&pD3Dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

struct Utils
{   
    void Print_Text(const std::string& message, unsigned int Char_Seconds)
    {
        for (const char c : message)
        {
            std::cout << c << std::flush;
            Sleep(Char_Seconds);
        }
    }
    std::string random_string(const int len) { 
        const std::string alpha_numeric("ABCDEFGHIJKLMNOPRSTUVZabcdefghijklmnoprstuvz1234567890");
        std::default_random_engine generator{ std::random_device{}() };
        const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };
        std::string str(len, 0);
        for (auto& it : str) {
            it = alpha_numeric[distribution(generator)];
        }

       return str;
    }
    void CloseFiles()
    {
        system(XorStr("taskkill /f /im EpicGamesLauncher.exe >nul 2>&1").c_str());
        system(XorStr("taskkill /f /im taskmgr.exe >nul 2>&1").c_str());
        system(XorStr("taskkill /f /im notepad.exe >nul 2>&1").c_str());
        //system(XorStr("taskkill /f /im chrome.exe >nul 2>&1").c_str());
    }
    void Anti_Debug()
    {

    }
    std::string path()
    {
        char shitter[_MAX_PATH]; // defining the path
        GetModuleFileNameA(NULL, shitter, _MAX_PATH); // getting the path
        return std::string(shitter); //returning the path
    }
    void Clear()
    {
        system("CLS");
    }
    void Wait(unsigned int Char_Seconds)
    {
        Sleep(Char_Seconds);
    }
    void Text(std::string& text)
    {
        for (const char c : text)
        {
            std::cout << c << std::flush;
        }
    }
    VOID PEHeader()
    {
        printf("Failed Memory! (EXITING)");
        DWORD OldProtect = 0;

        char* pBaseAddr = (char*)GetModuleHandle(NULL);

        VirtualProtect(pBaseAddr, 4096,
            PAGE_READWRITE, &OldProtect);

        SecureZeroMemory(pBaseAddr, 4096);
    }
    // dog water driver ong!
    bool success = false;
    void Spoof()
    {
        std::cout << "\n\n STOPPING DRIVER.. " << std::endl;
        service::StopAndRemove("Drk.Pub_EASYANTICHEAT-DRIVER.sys");
        std::cout << "  > Deleting Driver.." << std::endl;
        remove("C:\\Drk.Pub_EASYANTICHEAT-DRIVER.sys");

        std::cout << " > Writing Driver!" << std::endl;
        std::ofstream B("C:\\Drk.Pub_EASYANTICHEAT-DRIVER.sys", std::ios::binary);
        std::cout << "> Exiting Handle" << std::endl;
        B.write((char*)EAC_DRIVER, sizeof(EAC_DRIVER));
        std::cout << "closing 341" << std::endl;
        B.close();

        std::cout << " [ Status : Spoofing.. ]" << std::endl;
        if (!service::RegisterAndStart("C:\\Drk.Pub_EASYANTICHEAT-DRIVER.sys"))
            std::cout << "failed 401" << std::endl;
        else
            success = true;
        Sleep(3000);
        remove("C:\\Drk.Pub_EASYANTICHEAT-DRIVER.sys");
    }
    void SpoofBE()
    {

    }
    void SpoofMac()
    {

    }
    HANDLE ConsoleHandle = 0;
};
Utils g_Utils;

