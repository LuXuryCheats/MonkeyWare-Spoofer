#include "util.h"
#include <thread>

bool SpoofEAC = false;
bool SpoofBE = false;
bool CleanPC = false;
bool SpoofMAC = false;
bool DoAll = false;
int Exit = false;
#include "Config.h"

ImVec2 p;

void me()
{

}

float color_red = 1.;
float color_green = 0;
float color_blue = 0;
float color_random = 0.0;
float color_speed = -3.0;

void ColorChange()
{
    static float Color[3];
    static DWORD Tickcount = 0;
    static DWORD Tickcheck = 0;
    ImGui::ColorConvertRGBtoHSV(color_red, color_green, color_blue, Color[0], Color[1], Color[2]);
    if (GetTickCount() - Tickcount >= 1)
    {
        if (Tickcheck != Tickcount)
        {
            Color[0] += 0.001f * color_speed;
            Tickcheck = Tickcount;
        }
        Tickcount = GetTickCount();
    }
    if (Color[0] < 0.0f) Color[0] += 1.0f;
    ImGui::ColorConvertHSVtoRGB(Color[0], Color[1], Color[2], color_red, color_green, color_blue);
}

int APIENTRY main(HINSTANCE, HINSTANCE, LPSTR, int)
{
    HWND hwnd = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
    EnableMenuItem(hmenu, SC_MAXIMIZE, MF_GRAYED);
    DWORD styles = GetWindowLong(hwnd, GWL_STYLE);
    styles &= ~WS_MAXIMIZEBOX;
    SetWindowLong(hwnd, GWL_STYLE, styles);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
    SetWindowLong(hwnd, GWL_STYLE,
        GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
    ::SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
    ::ShowWindow(hwnd, SW_NORMAL);
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);// show console
    SetConsoleTitleA(g_Utils.random_string(100).c_str());
    g_Utils.ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(g_Utils.ConsoleHandle, AQUA);
    printf("\n\n  Initializing");
    std::string Print1 = ("\n\n  Closing Files...");
    g_Utils.CloseFiles();
    g_Utils.Print_Text(Print1, 40);
    Sleep(1000);
    // renames file once closed
    std::string name = g_Utils.random_string(30) + ".exe";
    std::rename(g_Utils.path().c_str(), name.c_str());
    SetConsoleTextAttribute(g_Utils.ConsoleHandle, RED);
    std::string Print2 = ("\n\n  Info : Version : 1.1");
    g_Utils.Print_Text(Print2, 40);
    g_Utils.Wait(700);
    g_Utils.Clear();
    g_Utils.Wait(700);
    SetConsoleTextAttribute(g_Utils.ConsoleHandle, AQUA);
    printf("\n\n  > Initializing..");
    Sleep(2000);
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);// hide console

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, (L"Mapi101"), NULL};
    RegisterClassEx(&wc);
    hWnd = CreateWindowW(wc.lpszClassName, (L"MonkeyWare"), WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    if (!CreateDeviceD3D(hWnd)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ShowWindow(hWnd, SW_HIDE);
    UpdateWindow(hWnd);
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    //ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg] = ImColor(28, 28, 28);
    }

    ImGui_ImplWin32_Init(hWnd);
    ImGui_ImplDX9_Init(pDevice);

   // io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 16);

    DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

    RECT screen_rect;
    GetWindowRect(GetDesktopWindow(), &screen_rect);
    auto x = float(screen_rect.right - WIDTH) / 2.f;
    auto y = float(screen_rect.bottom - HEIGHT) / 2.f;

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            ColorChange();
            ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(WIDTH, HEIGHT));
            ImGui::SetNextWindowBgAlpha(1.0f);

            ImGui::SetNextWindowSize({ 300, 300 });
            ImGui::Begin(title, &mainwindow, ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);

            int x = 30;
            int y = 20;

            ImVec2 p = ImGui::GetCursorScreenPos();
            Draw::BackgroundFilledRBG(p.x - 8, p.y + - 8, 300, 30, ImColor(30, 30, 30));
            Draw::BackgroundRBGOutline(p.x - 8, p.y - 8, 300, 300, ImColor(0, 0, 0), 3);
           // Draw::BackgroundFilledRBG(p.x - 8, p.y - 8, 300, 300, ImColor(28, 28, 28));
            Draw::BackgroundRBGOutline(p.x - 8, p.y -8, 300, 300, ImColor(48, 48, 48), 1);
            Draw::BackgroundRBGOutline(p.x - 8, p.y - 8, 300, 30, ImColor(0, 0, 0), 2);
            Draw::BackgroundRBGOutline(p.x - 8, p.y - 8, 300, 30, ImColor(color_red, color_green, color_blue), 1);
            Draw::BackgroundRBGOutline(p.x - 8, p.y - 8, 300, 300, ImColor(0, 0, 0), 2);
            Draw::BackgroundRBGOutline(p.x - 8, p.y - 8, 300, 300, ImColor(color_red, color_green, color_blue), 1);
            Draw::ShadowRGBText(p.x - 5, p.y -0, ImColor(255, 255, 255, 255), (" MonkeyWare Version | 1.1"));
            ImGui::Text("");
            ImGui::Text("");

            Draw::BackgroundFilledRBG(p.x + 1, p.y + 35, 15, 15, ImColor(color_red, color_green, color_blue));
            Draw::BackgroundRBGOutline(p.x + 1, p.y + 35, 15, 15, ImColor(0, 0, 0), 2);
            Draw::BackgroundRBGOutline(p.x + 1, p.y + 35, 15, 15, ImColor(255, 255, 255), 1);

            Draw::BackgroundFilledRBG(p.x + 1, p.y + 60, 15, 15, ImColor(color_red, color_green, color_blue));
            Draw::BackgroundRBGOutline(p.x + 1, p.y + 60, 15, 15, ImColor(0, 0, 0), 2);
            Draw::BackgroundRBGOutline(p.x + 1, p.y + 60, 15, 15, ImColor(255, 255, 255), 1);

            Draw::BackgroundFilledRBG(p.x + 1, p.y + 85, 15, 15, ImColor(color_red, color_green, color_blue));
            Draw::BackgroundRBGOutline(p.x + 1, p.y + 85, 15, 15, ImColor(0, 0, 0), 2);
            Draw::BackgroundRBGOutline(p.x + 1, p.y + 85, 15, 15, ImColor(255, 255, 255), 1);

            Draw::ToggleButtons("Spoof EAC", &SpoofEAC);
            Draw::ToggleButtons("Spoof BE", &SpoofBE);
            Draw::ToggleButtons("Spoof MAC", &SpoofMAC);
            Draw::ToggleButtons("Clean [Disabled]", &CleanPC);
            Draw::ToggleButtons("Do All", &DoAll);
            Draw::ShadowRGBText(p.x + 10, p.y + 35, ImColor(255, 255, 255, 255), ("  Spoof [EAC]"));
            Draw::ShadowRGBText(p.x + 10, p.y + 60, ImColor(255, 255, 255, 255), ("  Spoof [BE]"));
            Draw::ShadowRGBText(p.x + 10, p.y + 85, ImColor(255, 255, 255, 255), ("  Spoof [MAC], Spoofs Mac Address"));

            Draw::ShadowRGBText(p.x + 1, p.y + 150, ImColor(255, 255, 255, 255), ("Message Boxes Broken"));
            Draw::ShadowRGBText(p.x + 1, p.y + 165, ImColor(255, 255, 255, 255), ("Insert to close GUI"));
            if (SpoofEAC)
            {
                MessageBox(0, L"nigga balls.", L"Important!", MB_YESNOCANCEL);
                ::ShowWindow(::GetConsoleWindow(), SW_SHOW);// show console
                Beep(500, 500);
                std::thread freeze(me);
                g_Utils.Clear();
                Sleep(1000);
                printf("\n\n  [-] Initialized!");
                SetConsoleTextAttribute(g_Utils.ConsoleHandle, GREEN);
                g_Utils.Wait(1000);
                g_Utils.Clear();
                //g_Utils.Spoof();
                std::cout << XorStr("\n Current Serial: \n ");
                system(XorStr("wmic diskdrive get serialnumber").c_str());
                g_Utils.Spoof();
                if (g_Utils.success)
                {
                    Beep(500, 500);
                    MessageBox(0, L"it seems the spoofing process worked correctly!! ", L"YAY!!", MB_OK);
                    std::cout << XorStr("\n New Serial: \n ");
                    system(XorStr("wmic diskdrive get serialnumber").c_str());
                    printf("Closing in 3 Seconds..");
                }
                if (g_Utils.success == false)
                {
                    MessageBox(0, L"it seems the spoofer failed to succeed, contact support.", L"Error", MB_OK);
                    printf("  Serials didnt change.");
                    printf("Closing in 3 Seconds..");
                }
                g_Utils.Wait(3000);
                exit(0);
            }
        }
        if (SpoofBE)
        {
            MessageBox(0, L"Spoof EAC.", L"Important!", MB_YESNOCANCEL);
            ::ShowWindow(::GetConsoleWindow(), SW_SHOW);// show console
            Beep(500, 500);
            g_Utils.Clear();
            Sleep(1000);
            printf("\n\n  [-] Initialized!");
            SetConsoleTextAttribute(g_Utils.ConsoleHandle, PURPLE);
            g_Utils.Wait(1000);
            g_Utils.Clear();
            printf(" [>] Spoofing..");
            g_Utils.SpoofBE();
            if (g_Utils.success)
            {
                Beep(500, 500);
                printf(" [>] Spoofed!");
                MessageBox(0, L"it seems the spoofing process worked correctly!! ", L"YAY!!", MB_OK);
                std::cout << XorStr("\n New Serial: \n ");
                system(XorStr("wmic diskdrive get serialnumber").c_str());
                printf("Closing in 3 Seconds..");
            }
            if (g_Utils.success == false)
            {
                printf(" [>] Couldn't Spoof..");
                MessageBox(0, L"it seems the spoofer failed to succeed, contact support.", L"Error", MB_OK);
                printf("  Serials didnt change.");
                printf("Closing in 3 Seconds..");
            }
            g_Utils.Wait(3000);
            exit(0);
        }
        if (SpoofMAC)
        {
            MessageBox(0, L"Would you like to spoof mac?", L"Important!", MB_YESNOCANCEL);
            ::ShowWindow(::GetConsoleWindow(), SW_SHOW);// show console
            Beep(500, 500);
            g_Utils.Clear();
            Sleep(1000);
            printf("\n\n  [-] Spoofing Mac >> Waiting..");
            SetConsoleTextAttribute(g_Utils.ConsoleHandle, PURPLE);
            g_Utils.Wait(1000);
            printf("\n\n  [>] Spoofing Mac >> Waiting...");
            g_Utils.Wait(500);
            g_Utils.SpoofMac();
            printf("\n\n  [>] Spoofed Mac >> Finished Closing in 3 Seconds.");
            g_Utils.Wait(3000);
            ::ShowWindow(::GetConsoleWindow(), SW_HIDE);// hide console
            exit(0);

        }
        if (GetAsyncKeyState(VK_INSERT))
        {
            exit(1);
        }
        ImGui::End();
        ImGui::EndFrame();

        pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (pDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            pDevice->EndScene();
        }

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = pDevice->Present(NULL, NULL, NULL, NULL);

        if (result == D3DERR_DEVICELOST && pDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!mainwindow) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(hWnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (pDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            pD3Dpp.BackBufferWidth = LOWORD(lParam);
            pD3Dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

/*int main()
{
    SetConsoleTitleA(g_Utils.random_string(100).c_str());
    g_Utils.ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(g_Utils.ConsoleHandle, AQUA);
    printf("\n\n  Initializing");
    std::string Print1 = ("\n\n  Closing Files...");
    g_Utils.CloseFiles();
    g_Utils.Print_Text(Print1, 40);
    Sleep(1000);
    // renames file once closed
    std::string name = g_Utils.random_string(30) + ".exe";
    std::rename(g_Utils.path().c_str(), name.c_str());
    SetConsoleTextAttribute(g_Utils.ConsoleHandle, RED);
    std::string Print2 = ("\n\n  Info : Version : 1.1"); 
    g_Utils.Print_Text(Print2, 40);
    g_Utils.Wait(700);
    g_Utils.Clear();
    g_Utils.Wait(700);
    SetConsoleTextAttribute(g_Utils.ConsoleHandle, AQUA);
    printf("\n\n  > press f1 to spoof");
    while (true)
    {
        Sleep(10);
        if (GetAsyncKeyState(VK_F1))
        {
            Beep(500, 500);
            g_Utils.Clear();
            Sleep(300);
            SetConsoleTextAttribute(g_Utils.ConsoleHandle, RED);
            g_Utils.Spoof();
            g_Utils.Wait(1000);
            g_Utils.Clear();
            std::cout << XorStr("\n Current Serial: \n ");
            system(XorStr("wmic diskdrive get serialnumber").c_str());
            std::cout << XorStr("\n New Serial: \n ");
            system(XorStr("wmic diskdrive get serialnumber").c_str());
            printf("Closing in 5 Seconds..");
            g_Utils.Wait(5000);
        }
    }
}*/

