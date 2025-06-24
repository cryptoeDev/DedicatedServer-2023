//#include "Defines.hpp"
#include "Clasess.hpp"
#include "hookhandler.hpp"
#include "MH/MinHook.h"
#include "AI.hpp"

namespace Data {
    int hooks = 0;
    int patches = 0;
}

void MhCreateAndEnableHook(LPVOID pTarget, LPVOID pDetour, LPVOID* ppOriginal) {

    bool F1Set = false;

    while (!F1Set)
    {
        if (MH_CreateHook(pTarget, pDetour, ppOriginal) == MH_OK)
        {
            MH_EnableHook(pTarget);
            Data::hooks++;
            F1Set = true;
        }

        Sleep(1);
    }

}


static void SetPath(void* adress, LPCVOID lpBuffer, int len)
{
    Data::patches++;
    DWORD oldProtect = 0;

    VirtualProtect(adress, len, PAGE_EXECUTE_READWRITE, &oldProtect);
    WriteProcessMemory(GetCurrentProcess(), adress, lpBuffer, len, NULL);
    VirtualProtect(adress, len, oldProtect, NULL);
}

namespace Console {
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include "MH/MinHook.h"
    using namespace std;
    void CreateConsole() {
        int hConHandle = 0;
        HANDLE lStdHandle = 0;
        FILE* fp = 0;
        AllocConsole();
        freopen("CON", "w", stdout);
        SetConsoleTitle("DedicatedServer");
        lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
        fp = _fdopen(hConHandle, "w");
        *stdout = *fp;
        setvbuf(stdout, NULL, _IONBF, 0);
    }
}

//void InitConsole() {
//    SetPath((void*)0x140E59064, "\x74", 1);
//    MhCreateAndEnableHook(*CRender_4, ResetAudio, (LPVOID*)&CRender_4);
//    MhCreateAndEnableHook(*CRender_5, ShutdownAudio, (LPVOID*)&CRender_5);
//    printf("Init Console Succesfujlity!...\n [~] Disabled render\n [~] Succesfully hooked CryOnline.dll\nSuccesfully getted requestes+ and executed!\n");
//}

#if Dedicated

void ExecuteConsole(const char* str){
    std::cout << "[System] Execute Command: " << str << std::endl;
    DWORD64* pConsole = (DWORD64*)Pointer::startAddr(0x141C140F0)->AddPointer(0xC0);
    typedef DWORD64(__thiscall* ConsoleExecuteString)(PVOID64, const char*, const bool, const bool);
    CallFunction<ConsoleExecuteString>(pConsole, 0x118)(pConsole, str, 0, 0);
}


void FixCrushCGameStart() {
    SetPath((void*)0x0000000140CE9E82, "\x0F\x84", 2);
}

#endif

void FixConnectionDedicated() {
#if Dedicated
    SetPath((void*)0x00000001411C1BB1, "\x90\x90\x90", 3);
    SetPath((void*)0x00000001411C1BB7, "\x90\x90\x90", 3);
    SetPath((void*)0x00000001411C1BBA, "\x90\x90\x90\x90\x90\x90", 6);
    SetPath((void*)0x00000001411C1BC0, "\x90\x90\x90", 3);
    SetPath((void*)0x00000001411C1BC3, "\x90\x90\x90", 3);
    SetPath((void*)0x0000000141780104, "\x90\x90\x90\x90\x90\x90", 6);
    SetPath((void*)0x000000014178011F, "\x90\x90\x90\x90\x90\x90", 6);
    SetPath((void*)0x0000000140CEA339, "\x74", 1);
    SetPath((void*)0x00000001411C18EE, "\xEB", 1);
    SetPath((void*)0x00000001411C1911, "\xEB", 1);
    SetPath((void*)0x00000001411C192B, "\x90\x90\x90", 3);
    SetPath((void*)0x00000001411C1928, "\x90\x90\x90", 3);
    SetPath((void*)0x00000001411C1907, "\x90\x90\x90\x90\x90\x90\x90", 7);
    SetPath((void*)0x00000001411C193B, "\xEB", 1);
    SetPath((void*)0x0000000141565058, "\xEB", 1);
    SetPath((void*)0x00000001411C2697, "\xEB", 1);
    SetPath((void*)0x00000001411C1DC5, "\xEB", 1);
    SetPath((void*)0x00000001411C20F3, "\xEB", 1);
    SetPath((void*)0x00000001411C212C, "\xEB", 1);
    SetPath((void*)0x00000001411C1A3E, "\xEB", 1);
    SetPath((void*)0x00000001411C216A, "\x90\x90\x90", 3);
    SetPath((void*)0x00000001411C2173, "\x90\x90\x90", 3);
    SetPath((void*)0x0000000140318870, "\x84", 1);
    SetPath((void*)0x00000001411C2658, "\xEB", 1);
    SetPath((void*)0x00000001411C1594, "\x90\x90\x90\x90\x90\x90", 6);
    SetPath((void*)0x00000001411C226B, "\x90\xE9", 2);
    SetPath((void*)0x00000001400A5E1A, "\xB1\x00", 2);
    
    SetPath((void*)0x00000001411C1DFB, "\x90\x90\x90\x90\x90", 5);
    //SetPath((void*)0x00000001407E7416, "\xEB", 1);
    //SetPath((void*)0x0000000141565B6C, "\xEB", 1);
    SetPath((void*)0x0000000140219EB9, "\x90\x90\x90\x90", 4);
    SetPath((void*)0x00000001411DB06A, "\xeb", 1);

    SetPath((void*)0x000000014143E6FD, "\x90\x90\x90\x90\x90", 5);

    SetPath((void*)0x00000001415655F9, "\x0f\x84", 2);

    SetPath((void*)0x00000001411C1A65, "\x90\x90\x90\x90\x90", 5);
    SetPath((void*)0x0000000140451661, "\x90\x90\x90\x90\x90", 5);
    SetPath((void*)0x00000001411C2D5D, "\xEB", 1);
    SetPath((void*)0x00000001411ECF22, "\x90\x90\x90\x90\x90\x90", 6);


    /* фикс магазина (в игре, за монеты) */

    SetPath((void*)0x14125B6B5, "\xEB", 1);


    /* фикс [FlowGraphProxy] Skipped loading of FG 'entityId' flowGraphs  */

    //SetPath((void*)0x1405084F9, "\x75", 1);

   

    //SetPath((void*)0x14125B702, "\x0F\x84", 2);


    /* фикс припяти */




    //FIX-ATTACHEMENTS



    //CHEAT-PATH: TODO

       



    //SetPath((void*)0x1411D921B, "\x90\x90\x90\x90\x90", 5);
    //SetPath((void*)0x1411DA6F3, "\x0f\x84", 2);



#endif
}

void DecryptClient() {
    SetPath((void*)0x0000000141D099A0, "\x75", 1);
}

#if Dedicated

typedef HANDLE(__stdcall* nCreateMutexA)(LPSECURITY_ATTRIBUTES, BOOL, LPCSTR);
nCreateMutexA mCreateMutexA;

HANDLE __stdcall CreateMutexAHook(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
    if (lpName != NULL) {
        if (strstr(lpName, "CrytekApplication")) {
            //MhCreateAndEnableHook(*CWeaponView_PlaySignal_p, CWeaponView_PlaySignal, (LPVOID*)&CWeaponView_PlaySignal_p);
            MhCreateAndEnableHook(*CEntityLoadManager_ExtractEntityLoadParams_p, CEntityLoadManager_ExtractEntityLoadParams, (LPVOID*)&CEntityLoadManager_ExtractEntityLoadParams_p);
            return INVALID_HANDLE_VALUE;
        }
    }
    return mCreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}

#endif


BYTE g_rsa_public_key_data[140] = { 0x30,0x81,0x89,0x02,0x81,0x81,0x00,0x9B,0x60,0x69,0x31,0xDC,0xF7,0x02,0x7A,0x4D,0xC0,0xE5,0x26,0x3B,0x4A,0xD0,0xD8,0xF4,0xA4,0x92,0xA1,0x6E,0x4B,0x5E,0xC0,0x85,0x0F,0x07,0x4B,0x4C,0x3D,0xA6,0x27,0xFF,0x96,0x67,0x6D,0x23,0x79,0xF8,0x90,0x62 ,0xDE,0x6C,0x91,0x7F,0x26,0x8C,0xBD,0x82,0x24,0x04,0xD2,0x6D,0x9D,0x79,0xBC,0xB0,0x18,0x2D,0x4C,0x96,0xEE,0xAF,0x2B,0x91,0x8A,0x03,0x00,0xBF,0xB8,0x16,0x19,0x62,0x2D,0x15,0x56,0xB4,0xE0,0x2D,0x16,0xFE,0x0C,0x7E,0xD7,0x2C,0x01,0xEE,0x42,0x9C,0x4C ,0x84,0x9C,0x6A,0x78,0x6B,0xCE,0xC4,0x4D,0x6C,0x50,0xCB,0x91,0x46,0x48,0xBB,0x66,0x2D,0x0B,0xA2,0x35,0x68,0x00,0x02,0xD4,0x60,0x50,0x58,0xD1,0xC3,0x0D,0xA1,0x12,0x37,0x82,0x2A,0x01,0xF2,0xEF,0x02,0x03,0x01,0x00,0x01};

void ChangeGRsaPublicKeyData() {

    BYTE* pInstruction = (BYTE*)0x141ECE8C0;
    while (true) {
        if (*pInstruction == 0x30) {
            break;
        }
        Sleep(1);
    }
    DWORD old;
    VirtualProtect((LPVOID)pInstruction, 140, PAGE_READWRITE, &old);
    memcpy_s(pInstruction, 140, g_rsa_public_key_data, 140);
    VirtualProtect((LPVOID)pInstruction, 140, old, &old);
}

void SvRequestHitFix() {
    BYTE* pCall = (BYTE*)0x00000001414DB396;
    while (true) {
        if (*pCall == 0xE8) {
            break;
        }
        Sleep(1);
    }
    DWORD* pServerHit = (DWORD*)0x00000001414DB397;
    DWORD old;
    VirtualProtect((LPDWORD)pServerHit, 4, PAGE_READWRITE, &old);
    *pServerHit = 0 - ((DWORD)pServerHit - ((DWORD)0x00000001414B24C0 - 4));
    VirtualProtect((LPDWORD)pServerHit, 4, old, &old);
}

void InitializationCVars() {
    LPSTR cmdLine = GetCommandLineA();
    std::string commandLine(cmdLine);
    std::string token = "-forward_receiver_id";
    size_t pos = commandLine.find(token);
    if (pos != std::string::npos) {
        pos += token.length() + 1;
        size_t endPos = commandLine.find(' ', pos);
        std::string value = commandLine.substr(pos, endPos - pos);

        printf("%s\n", value.c_str());

       // OnlineAccount_p::master_server = value.c_str();
        
    }
}

void FixRmiPriorities() {
    BYTE* bNoDelayRMI_CPlayer_ClSetUsableTurretMode = (BYTE*)0x016C4364 + 0x18;
    BYTE* bNoDelayRMI_CPlayer_SvSetUsableTurretFiring = (BYTE*)0x016C4380 + 0x18;

    *bNoDelayRMI_CPlayer_ClSetUsableTurretMode = 0x00;
    *bNoDelayRMI_CPlayer_SvSetUsableTurretFiring = 0x00;

}

byte publicKey[] =
{
    0xFF, 0x53, 0x25, 0x5C, 0xF2, 0x8, 0x70, 0x6, 0xAE, 0x9A, 0x32,    0xAB, 0x51, 0x11, 0xA1, 0x75, 0x7A, 0x97, 0x6C, 0x64, 0xBC,    0x67, 0x73, 0x13, 0xEF, 0x5B, 0xC0, 0xFC, 0xD3, 0xA2, 0x8A,    0xAA, 0x85, 0xB9, 0x62, 0x5E, 0xB2, 0x59, 0x6A, 0xCD, 0xF0,    0x74, 0x21, 0x89, 0xF1, 0xBB, 0x7D, 0x20, 0xDD, 0xA7, 0xCE,    0x77, 0x5F, 0xB, 0x42, 0x2F, 0xDF, 0x3A, 0xB5, 0x5D, 0x7E,    0x76, 0xE0, 0x22, 0x4, 0x46, 0xEA, 0x8B, 0xA5, 0xC3, 0x55,    0xA6, 0xE2, 0x5A, 0x58, 0x31, 0x8D, 0x7F, 0x43, 0xDC, 0x4D,    0x15, 0x3E, 0xD2, 0x56, 0x9, 0x1B, 0xDB, 0x5, 0x48, 0xF4,    0x65, 0xC4, 0x26, 0xAD, 0xD1, 0x19, 0x49, 0xD7, 0xCF, 0xD,    0x82, 0x84, 0x41, 0x1C, 0xC1, 0xBE, 0xF8, 0xE1, 0xC7, 0x94,    0xC6, 0x3C, 0xD9, 0xC2, 0xCA, 0x10, 0x1F, 0x66, 0xE8, 0x86,    0xF7, 0xDE, 0x16, 0x60, 0xED, 0x35, 0xE9, 0x29, 0xBD, 0x8C,    0x50, 0xEC, 0x6D, 0x9C, 0x88, 0x1A, 0xB4, 0x33, 0x8F, 0x1D,    0xEE, 0x57, 0x96, 0xA3, 0xE3, 0xC9, 0x14, 0xF3, 0xE6, 0xB6,    0x40, 0x30, 0x81, 0x12, 0x92, 0x37, 0x44, 0xF9, 0x3D, 0xD5,    0xB7, 0xE, 0x36, 0x3F, 0x71, 0x4A, 0xAF, 0x17, 0x91, 0xAC,    0x6E, 0x8E, 0x99, 0x52, 0xFA, 0xF, 0xA8, 0x54, 0x3, 0xB3,    0x18, 0xD8, 0xA9, 0x3B, 0x9F, 0x24, 0xFD, 0xB8, 0x83, 0xF6,    0x78, 0x39, 0xEB, 0x28, 0x72, 0xCC, 0xFB, 0x2, 0xB0, 0xBF,    0x38, 0x4F, 0x0, 0x1E, 0x6B, 0x9B, 0x9D, 0xB1, 0x87, 0xDA,    0x7B, 0x61, 0x23, 0x4B, 0xE5, 0xE4, 0xBA, 0x90, 0xE7, 0x79,    0x7C, 0x27, 0x47, 0xC5, 0xF5, 0xFE, 0x69, 0xCB, 0x45, 0x2B,    0x93, 0x2D, 0x1, 0xD6, 0xA0, 0x63, 0xD0, 0x68, 0x98, 0xD4,    0xC, 0x6F, 0x4C, 0x4E, 0x2C, 0x2E, 0xA4, 0x34, 0x7, 0x95,    0xA, 0x9E, 0x2A, 0x80, 0xC8
};

typedef BOOL(WINAPI* nReadFile)(HANDLE FileHandle, HANDLE Event, PVOID  ApcRoutine, PVOID ApcContext, PVOID IoStatusBlock, PVOID buffer, ULONG Length, PLARGE_INTEGER   ByteOffset, PULONG Key);
nReadFile mReadFile;

void Decrypt(byte* buffer, int len, byte F, byte L)
{
    for (int i = 0; i < len; i++)
    {
        byte Encrypted = *(byte*)(buffer + i);
        Encrypted ^= L - (byte)3;
        Encrypted = publicKey[(byte)Encrypted];
        Encrypted ^= F - (byte)9;

        *(byte*)(buffer + i) = Encrypted;
    }
}

char fileName[256];

BOOL __stdcall MyReadFile(HANDLE FileHandle, HANDLE Event, PVOID  ApcRoutine, PVOID ApcContext, PVOID IoStatusBlock, PVOID buffer, ULONG Length, PLARGE_INTEGER   ByteOffset, PULONG Key)
{
    BOOL result = mReadFile(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, buffer, Length, ByteOffset, Key);
    //__asm pushad;
    ZeroMemory(fileName, 256);



    GetFinalPathNameByHandle(FileHandle, fileName, 256, VOLUME_NAME_NT);
    if (strstr(fileName, ".pak")) {}
    //printf("%s\n", fileName);

    size_t fileNameLength = strlen(fileName);

    if (fileNameLength > 0)
    {
        BOOL IsPak = strcmp(fileName + fileNameLength - 4, ".pak") == 0;
        BOOL IsCfg = strcmp(fileName + fileNameLength - 4, ".cfg") == 0;

        if (IsPak || IsCfg)
        {
            size_t LastDelimiter = 0;
            for (size_t i = 0; i < fileNameLength; i++)
            {
                if (fileName[i] == '\\')
                {
                    LastDelimiter = i;
                }
            }
            LastDelimiter++;



            if (IsPak)
            {
                Decrypt((BYTE*)buffer, Length, (BYTE)fileName[LastDelimiter], (BYTE)fileName[fileNameLength - 5]);
            }
        }
    }
    // __asm popad;
    return result;
}



typedef char (__fastcall* CGameRules_IsAllPlayersInGameClass)(CGameRules* this1);
CGameRules_IsAllPlayersInGameClass CFlowGraphBase_LinkNodes_p = (CGameRules_IsAllPlayersInGameClass)0x140503A60;

bool __fastcall CFlowGraphBase_LinkNodes(void* this1, void* from, void* to)
{
    return 1;
}


DWORD WINAPI InitAll(LPVOID lpP)
{
    MH_Initialize();
    MhCreateAndEnableHook(*mZipDir__CacheFactory__ReadHeaderData, ZipDir__CacheFactory__ReadHeaderData, (LPVOID*)&mZipDir__CacheFactory__ReadHeaderData);
    MhCreateAndEnableHook(*sub_140DC2170_p, sub_140DC2170, (LPVOID*)&sub_140DC2170_p);


    DecryptClient();
    if (strstr(GetCommandLine(), "-dedicated")) 
    {
        InitializationCVars();
       // FixRmiPriorities();

        Console::CreateConsole();
        InitXML();



        PrintToConsole("DedicatedServer init...\n", GREEN);
        struct tagRECT Rect;
        HWND hWnd = GetConsoleWindow();
        GetWindowRect(hWnd, &Rect);
        MoveWindow(hWnd, Rect.left, Rect.top, 1260, 750, 1);
        PrintToConsole("==============================\n", YELLOW);
        PrintToConsole("Setup patches...\n", GREEN);
        FixCrushCGameStart();
        FixConnectionDedicated();
        SvRequestHitFix();
        InitAI();
        PrintToConsole("The patch initialization is complete!\n", GREEN); 
        PrintToConsole("==============================\n", YELLOW);
        PrintToConsole("Setup hooks...\n", GREEN);
        



        MhCreateAndEnableHook(*mAddRegisterSoundListener, AddRegisterSoundListener, (LPVOID*)&mAddRegisterSoundListener);
        MhCreateAndEnableHook(*SLobbyServerInfo_SerializeAllToXml_p, SLobbyServerInfo_SerializeAllToXml, (LPVOID*)&SLobbyServerInfo_SerializeAllToXml_p);
        MhCreateAndEnableHook(*CGame_Init, CGame_InitHook, (LPVOID*)&CGame_Init);
        MhCreateAndEnableHook(*Update_OnlineAccount_p, Update_OnlineAccount, (LPVOID*)&Update_OnlineAccount_p);
        MhCreateAndEnableHook(*UU_TES11_58271, CGameStart_Init, (LPVOID*)&UU_TES11_58271);
        MhCreateAndEnableHook(*mCCryAction_StartGameContext_p, CCryAction_StartGameContext, (LPVOID*)&mCCryAction_StartGameContext_p);
        MhCreateAndEnableHook(*CMissionBackend_OnMissionLoad_p, CMissionBackend_OnMissionLoad, (LPVOID*)&CMissionBackend_OnMissionLoad_p);
        MhCreateAndEnableHook(*CGame_Update_p, Game_Update, (LPVOID*)&CGame_Update_p);
        MhCreateAndEnableHook(*CFlowchartManager_IsState_p, CFlowchartManager_IsState, (LPVOID*)&CFlowchartManager_IsState_p);
        MhCreateAndEnableHook(*CAbstractServerInfo_IsOwner_p, AbstractServerInfo_IsOwner, (LPVOID*)&CAbstractServerInfo_IsOwner_p);
        MhCreateAndEnableHook(*CBackend_CBackend, CBackendVoid, (LPVOID*)&CBackend_CBackend);
        MhCreateAndEnableHook(*TEST_DFCNANEL5, CGame_GetBackend, (LPVOID*)&TEST_DFCNANEL5);
        MhCreateAndEnableHook(*CActor_SetPhysicalizationProfile, CActor_SetPhysicalizationProfileHook, (LPVOID*)&CActor_SetPhysicalizationProfile);
        MhCreateAndEnableHook(*CPlayer_CreateInputClassByType_p, CPlayer_CreateInputClassByType, (LPVOID*)&CPlayer_CreateInputClassByType_p);
        MhCreateAndEnableHook(*CInstantAwardSystem_p, CInstantAwardSystem_CInstantAwardSystem, (LPVOID*)&CInstantAwardSystem_p);

        MhCreateAndEnableHook(*CGameRules_Update, CGameRules_UpdateHook, (LPVOID*)&CGameRules_Update);
        //MhCreateAndEnableHook(*CGameRules_Init_p, CGameRules_Init, (LPVOID*)&CGameRules_Init_p);
        MhCreateAndEnableHook(*CGameRules_GetMissionStatistics_p, GetMissionStatistics, (LPVOID*)&CGameRules_GetMissionStatistics_p);


        //TelemetryStreamBegin & CInstantAwardSystem

                MhCreateAndEnableHook(*CGameRules_KillPlayer_p, CGameRules_KillPlayer, (LPVOID*)&CGameRules_KillPlayer_p);
                MhCreateAndEnableHook(*CGameRules_AwardPlayer_p, CGameRules_AwardPlayer, (LPVOID*)&CGameRules_AwardPlayer_p);
                //MhCreateAndEnableHook(*Game_CAttachment_OnAttach_p, Game_CAttachment_OnAttach, (LPVOID*)&Game_CAttachment_OnAttach_p);
                //MhCreateAndEnableHook(*CGameRules_DamagePlayer, GameRules_SendDamageIndicator, (LPVOID*)&CGameRules_DamagePlayer);




                
            //MhCreateAndEnableHook(*CKillStats_CKillStats_p, CKillStats_CKillStats, (LPVOID*)&CKillStats_CKillStats_p);



            //MhCreateAndEnableHook(*CGameRules_OnEndGame, GameRules_OnEndGame, (LPVOID*)&CGameRules_OnEndGame);
            //MhCreateAndEnableHook(*CGameRules_InitSessionStatistics_p, GameRules_InitSessionStatistics, (LPVOID*)&CGameRules_InitSessionStatistics_p);


        //TelemetryStreamEnd


        //anti-cheat 2023 init
            MhCreateAndEnableHook(*CSystem_Update_p, CSystem_Update, (LPVOID*)&CSystem_Update_p);
            MhCreateAndEnableHook(*SM_NetworkSMessage_SerializeWith_p, SM_NetworkSMessage_SerializeWith, (LPVOID*)&SM_NetworkSMessage_SerializeWith_p);
        //anti-cheat 2023 end

        MhCreateAndEnableHook((void*)0x1412181F0, SSADSDFSDFSDFSDF, (LPVOID*)&SADSDFSDFSDFSDF_p);
        MhCreateAndEnableHook((void*)0x1413E46B0, SSADSDFSDFSDFSDF1, (LPVOID*)&SADSDFSDFSDFSDF1_p);
        MhCreateAndEnableHook((void*)0x140D6A3A0, SSADSDFSDFSDFSDF12, (LPVOID*)&SADSDFSDFSDFSDF12_p);
        MhCreateAndEnableHook((void*)0x1419AB6B0, SSADSDFSDFSDFSDF14, (LPVOID*)&SADSDFSDFSDFSDF14_p);
        MhCreateAndEnableHook((void*)0x14177FDE0, SSADSDFSDFSDFSDF16, (LPVOID*)&SADSDFSDFSDFSDF16_p);
        MhCreateAndEnableHook((void*)0x1402187A0, SSADSDFSDFSDFSDF17, (LPVOID*)&SADSDFSDFSDFSDF17_p);
        MhCreateAndEnableHook((void*)0x140219DC0, SSADSDFSDFSDFSDF18, (LPVOID*)&SADSDFSDFSDFSDF18_p);
        MhCreateAndEnableHook((void*)0x1412CD3C0, SSADSDFSDFSDFSDF19, (LPVOID*)&SADSDFSDFSDFSDF19_p);
        MhCreateAndEnableHook((void*)0x1407B5A30, SSADSDFSDFSDFSDF20, (LPVOID*)&SADSDFSDFSDFSDF20_p);
        MhCreateAndEnableHook((void*)0x14020CF00, SSADSDFSDFSDFSDF21, (LPVOID*)&SADSDFSDFSDFSDF21_p);
        MhCreateAndEnableHook((void*)0x1411E5FD0, SSADSDFSDFSDFSDF22, (LPVOID*)&SADSDFSDFSDFSDF22_p);



        MhCreateAndEnableHook((void*)0x141498470, SSADSDFSDFSDFSDF23, (LPVOID*)&SADSDFSDFSDFSDF23_p);
        MhCreateAndEnableHook((void*)0x1411EC490, SSADSDFSDFSDFSDF24, (LPVOID*)&SADSDFSDFSDFSDF24_p);
        MhCreateAndEnableHook((void*)0x14020EEA0, SSADSDFSDFSDFSDF25, (LPVOID*)&SADSDFSDFSDFSDF25_p);
        MhCreateAndEnableHook((void*)0x1402500F0, SSADSDFSDFSDFSDF26, (LPVOID*)&SADSDFSDFSDFSDF26_p);

        MhCreateAndEnableHook((void*)0x140381DA0, SSADSDFSDFSDFSDF27, (LPVOID*)&SADSDFSDFSDFSDF27_p);
        MhCreateAndEnableHook((void*)0x14152C6F0, SSADSDFSDFSDFSDF28, (LPVOID*)&SADSDFSDFSDFSDF28_p);

        /*
        
        lua:
        
        */

        //MhCreateAndEnableHook(mCScriptBind_System__LogString, CScriptBind_System__LogString, (LPVOID*)&mCScriptBind_System__LogString);
        MhCreateAndEnableHook(mCScriptSystem_ErrorHandler_Hook, CScriptSystem_ErrorHandler_Hook, (LPVOID*)&mCScriptSystem_ErrorHandler_Hook);
        //MhCreateAndEnableHook(mnsub_AD08E0, sub_AD08E0, (LPVOID*)&mnsub_AD08E0);

        /*
        end: lua
        
        */

        MhCreateAndEnableHook((void*)CScriptBind_GameRules_DisconnectToLobby_p, ScriptBind_GameRules_DisconnectToLobby, (LPVOID*)&CScriptBind_GameRules_DisconnectToLobby_p);
        MhCreateAndEnableHook((void*)CGame_GetServerInfo_p, Game_GetServerInfo, (LPVOID*)&CGame_GetServerInfo_p);
        MhCreateAndEnableHook(*CGameRules_ReportGameEnd_p, GameRules_ReportGameEnd, (LPVOID*)&CGameRules_ReportGameEnd_p);
        MhCreateAndEnableHook(*SSetRewardsInfoSerializer_OnRequest_p, SetRewardsInfoSerializer_OnRequest, (LPVOID*)&SSetRewardsInfoSerializer_OnRequest_p);
        //MhCreateAndEnableHook(*GetQueryReceiverId_p, GetQueryReceiverId, (LPVOID*)&GetQueryReceiverId_p);




        MhCreateAndEnableHook(*mCSM_CoopAssist__Finish, CSM_CoopAssist__Finish, (LPVOID*)&mCSM_CoopAssist__Finish);
        MhCreateAndEnableHook(*mCSM_CoopClimb__Finish, CSM_CoopClimb__Finish, (LPVOID*)&mCSM_CoopClimb__Finish);
       //MhCreateAndEnableHook(*CSM_VaultFinsih_p, CSM_Vault_Finish, (LPVOID*)&CSM_VaultFinsih_p);
        //MhCreateAndEnableHook(*MovementCore_Move_p, MovementCore_Move, (LPVOID*)&MovementCore_Move_p);
        //MhCreateAndEnableHook(*CServerMovementProcessor_Update_p, CServerMovementProcessor_Update, (LPVOID*)&CServerMovementProcessor_Update_p);

        //MhCreateAndEnableHook(*CActor_NetSerialize_p, CActor_NetSerialize, (LPVOID*)&CActor_NetSerialize_p);
        //MhCreateAndEnableHook(*CAchievementsTracker_SaveAchievements_p, CAchievementsTracker_SaveAchievements, (LPVOID*)&CAchievementsTracker_SaveAchievements_p);

        bool IsCMASet = false;
        while (!IsCMASet) {
            if (DWORD64 NCreateMutexAAdr = (DWORD64)GetProcAddress(GetModuleHandle("KERNEL32"), "CreateMutexA")) {
                if (MH_CreateHook((void*)NCreateMutexAAdr, CreateMutexAHook, (LPVOID*)&mCreateMutexA) == MH_OK) {
                    MH_EnableHook((void*)NCreateMutexAAdr);
                    IsCMASet = true;
                }
            }
            Sleep(100);
        }     
        PrintToConsole("The hooks initialization is complete!\n", GREEN);
        PrintToConsole("==============================\n", YELLOW);
    }
    return 0;
}




BOOL WINAPI DllMain(HMODULE  hinstDLL, DWORD64 fdwReason, LPVOID) {
    if (fdwReason == 1) {
        CreateThread(NULL, 0, InitAll, NULL, 0, NULL);
       // CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CheckAndClearIfRecent, NULL, 0, NULL);
        Sleep(250);
        return TRUE;
    }

    return FALSE;
}



