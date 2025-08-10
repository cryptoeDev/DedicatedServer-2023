//#include "Clasess.hpp"
#include <iostream>
#include "types.hpp"
//#include "Defines.hpp"
#include <wininet.h>
#include <iostream>
#include <thread>

#pragma comment(lib, "wininet.lib")

#include "TelemetryStream.hpp"
#include <string>
#include <chrono>
#include <future>
#include <vector>
#include <iostream>
#include "pugixml.hpp"
#include <sstream> 
#include <iostream>
#include "AntiCheat.hpp"
#include <tlhelp32.h>
#include <set>
#include <random>
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>



namespace OnlineAccount_p {
    extern const char* login = "dedicated";
    extern const char* pwd = "dedicated";
    extern const char* master_server = "main_pvp_pro_001";
    extern const char* sw_port = "+sv_port";
}


void setConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { (SHORT)width, (SHORT)height };
    SetConsoleScreenBufferSize(hConsole, bufferSize);
    SMALL_RECT windowSize = { 0, 0, (SHORT)(width - 1), (SHORT)(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int maxWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int maxHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    if (width > maxWidth || height > maxHeight) SetConsoleScreenBufferSize(hConsole, { (SHORT)width, (SHORT)height });
}

#if Dedicated

ISystemEventDispatcher* m_pSystemEventDispatcher = nullptr;
CAchievementBackend* m_pBackend = nullptr;
CAchievementConfig* m_pAchievementConfig = nullptr;

#endif

enum TextColor {
    RESET = 7,  // ÷вет по умолчанию в консоли Windows
    RED = 12,
    GREEN = 10,
    YELLOW = 14,
    BLUE = 9,
    MAGENTA = 13,
    CYAN = 11,
    WHITE = 15
};

void setColor(TextColor color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RESET);
}


void PrintToConsole(const char* format, TextColor color, bool isAdminConsoleDisabled = true)
{
    if (!isAdminConsoleDisabled) {
        setColor(color);
        printf(format);

        resetColor();
    }
}


#if Dedicated




void __fastcall ResetAudio(DWORD64 this_)
{
    return;
}
void __fastcall ShutdownAudio(DWORD64 this_)
{
    return;
}

struct Node {
    Node* self;
    Node* next;
    Node* prev;
    uint16_t flag;
};


class Test {
private:
    using FN_14107E860 = void(__thiscall*)(__int64);
public:
    static void sub_14107E860(__int64 a1) {
        FN_14107E860(0x14107E860)(a1);
    }
};

void* AllocateMemory(size_t size) {
    return std::malloc(size);
}



void InitFun() {
    CGame_3 *m_pGame = CGame_3::Signlenton();
    void* v149 = nullptr; 
    PrintToConsole("m_pGame\n", GREEN);
    if (!m_pGame->fields[34]) {
    PrintToConsole("!m_pGame->fields[34]\n", GREEN);
        v149 = operator_new(0xB0);
    PrintToConsole("!operator_new\n", GREEN);
        if (v149) {
            int64_t v150 = m_pGame->CallFunction(); 
    PrintToConsole("!CallFunction\n", GREEN);
            Test::sub_14107E860((__int64)v149);
    PrintToConsole("!sub_14107E860\n", GREEN);

            *reinterpret_cast<void**>(v149) = reinterpret_cast<void*>(0x141BD09D0);
    PrintToConsole("!1\n", GREEN);

            // Выделяем память и создаем узлы вручную (без цикла)
            Node* v151 = static_cast<Node*>(operator_new(0x30));
    PrintToConsole("!2\n", GREEN);
            if (v151) {
                v151->self = v151;
                v151->next = v151;
                v151->prev = v151;
                v151->flag = 257;
                reinterpret_cast<int64_t*>(v149)[12] = reinterpret_cast<int64_t>(v151);
            }
    PrintToConsole("!3\n", GREEN);

            Node* v152 = static_cast<Node*>(operator_new(0x30));
            if (v152) {
                v152->self = v152;
                v152->next = v152;
                v152->prev = v152;
                v152->flag = 257;
                reinterpret_cast<int64_t*>(v149)[14] = reinterpret_cast<int64_t>(v152);
            }
    PrintToConsole("!4\n", GREEN);

            Node* v153 = static_cast<Node*>(operator_new(0x30));
            if (v153) {
                v153->self = v153;
                v153->next = v153;
                v153->prev = v153;
                v153->flag = 257;
                reinterpret_cast<int64_t*>(v149)[16] = reinterpret_cast<int64_t>(v153);
            }
    PrintToConsole("!5\n", GREEN);

            void* v154 = operator_new(0x40);
            if (v154) {
                reinterpret_cast<int64_t*>(v154)[0] = reinterpret_cast<int64_t>(v154);
                reinterpret_cast<int64_t*>(v154)[1] = reinterpret_cast<int64_t>(v154);
                reinterpret_cast<int64_t*>(v154)[2] = reinterpret_cast<int64_t>(v154);
                *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(v154) + 24) = 257;
                reinterpret_cast<int64_t*>(v149)[18] = reinterpret_cast<int64_t>(v154);
            }
    PrintToConsole("!6\n", GREEN);

            // Вызов функции
            //SubFunction(reinterpret_cast<void*>(reinterpret_cast<int64_t*>(v149) + 20));

            *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(v149) + 168) = 0;
            *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(v149) + 172) = -1;
            reinterpret_cast<int64_t*>(v149)[9] = v150;
    PrintToConsole("!7\n", GREEN);
        }
        else {
            v149 = nullptr;
        }
        m_pGame->fields[34] = v149;
    }
}
#include <ws2tcpip.h>

SOCKET clientSocket;

void Send(const std::string& message) {

    if (clientSocket == INVALID_SOCKET)
    {
        printf("Socket is INVALID data\n");
        return;
    }
    //printf("Message: %s\n", message);
    //uint32_t magic = 0xFEEDDEAD;
    //uint32_t length = static_cast<uint32_t>(message.length());
    //std::vector<char> buffer(12 + length);
    //std::memcpy(buffer.data(), &magic, sizeof(magic));
    //std::memcpy(buffer.data() + 4, &length, sizeof(length));
    //std::memcpy(buffer.data() + 8, message.data(), length);
    //int bytesSent = send(clientSocket, buffer.data(), buffer.size(), 0);
    int bytesSent = send(clientSocket, message.c_str(), strlen(message.c_str()), 0);
    //printf("Message: %s\n", message);
    if (bytesSent < 0) {
        printf("Error sending message: %s\n", strerror(errno));
    }
}



void Connect() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return;
    }
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        printf("Socket creation failed\n");
        WSACleanup();
        return;
    }
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(6000);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
    if (connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        printf("Connection failed\n");
        closesocket(clientSocket);
        WSACleanup();
        return;
    }
    //ListenForPackets();


}

int InitializationCVarsPort() {
    const int minValue = 55520;
    const int maxValue = 65500;



    std::random_device rd; 
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dis(minValue, maxValue); 

  
    std::set<int> generatedNumbers;

    // Генерация случайного числа
    for (int i = 0; i < 10; ++i) { 
        int randomNum;
        do {
            randomNum = dis(gen);
        } while (generatedNumbers.count(randomNum)); 

        generatedNumbers.insert(randomNum); 
        return randomNum;
    }
    return 0;
}

char __fastcall CGame_InitHook(CGame* this1, IGameFramework* pFramework) {
    char result = CGame_Init(this1, pFramework);
    SCVars* pCvars = SCVars::Singlenton();
    SSystemGlobalEnvironment* pSsge = SSystemGlobalEnvironment::Singleton();
    CSystem* pSystem = pSsge->GetCSystem();
    IConsole* pConsole = pSsge->GetIConsole();

   // printf("%s\n", pConsole->GetCVar("forward_receiver_id")->GetString());

    pCvars->online_dedicated_host_name = pConsole->RegisterString("online_dedicated_host_name", "127.0.0.1", 1, "", 0);
    pConsole->RegisterString("forward_receiver_id", OnlineAccount_p::master_server, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("g_weapon_resistance_enabled", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("g_hide_locked_attachments", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODAliveTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODMoveInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODStanceInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODDirInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODAmbientFireInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODKillZoneInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODReactionTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODReactionDistInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODReactionLeanInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODReactionDirInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_AmbientFireEnable", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODCoverFireTimeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODKillRangeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODCombatRangeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_AmbientFireUpdateInterval", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_AmbientFireQuota", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODLowHealthMercyTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_UseAlternativeReadability", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_audio_range_aggressive", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_enable_occlusion_trigger", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_audio_range_threatening", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_audio_range_interesting", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_audio_time_aggressive", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_audio_time_threatening", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_audio_time_interesting", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_visual_time_near_react", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_visual_time_aggressive", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_visual_time_threatening", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_reaction_visual_time_interesting", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODReactionTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODAliveTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODLowHealthMercyTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODAliveTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODMoveInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODStanceInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODDirInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODAmbientFireInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODKillZoneInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODReactionTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODReactionDistInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODReactionDirInc", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_AmbientFireEnable", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODCoverFireTimeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODKillRangeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODCombatRangeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_AmbientFireUpdateInterval", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_AmbientFireQuota", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_RODLowHealthMercyTime", 0, 0, "Custom line for initializing the setserver channel", 0);
    pConsole->RegisterInt("ai_UseAlternativeReadability", 0, 0, "Custom line for initializing the setserver channel", 0);

    CScriptSystem* pScrypts = pSsge->GetCSCryptSystem(); if (!pScrypts) return 0;
    //pScrypts->ExecuteFile("scripts/ai/aiconfig.lua");
    //pScrypts->ExecuteFile("scripts/ai/cover.xml");
    //pScrypts->ExecuteFile("scripts/ai/navigation.xml");



    //pConsole->ExecuteString(sv_ports, false, false);

    //printf("receiverId: %s\n", pConsole->GetCVar("sv_port")->GetString());
    
    std::string ports = "sv_port " + std::to_string(InitializationCVarsPort());
    
    pConsole->ExecuteString(ports.c_str(), false, false);

    //printf("receiverId: %s\n", pConsole->GetCVar("sv_port")->GetString());

    

    //pConsole->RegisterInt("g_weapon_resistance_enabled", 1, 1, "Custom line for initializing the setserver channel", 0);
    //pConsole->RegisterInt("ui_show_explosives_hit_indicator", 1, 1, "Custom line for initializing the setserver channel", 0);
    pConsole->ExecuteString("pl_new_movement 1", false, false);

    pConsole->ExecuteString("sv_cvars_hash_enable 0", false, false);
    pConsole->ExecuteString("g_cache_actorcc 0", false, false);
    pConsole->ExecuteString("g_metrics_enabled 0", false, false);
    pConsole->ExecuteString("g_character_manager_early_preload 1", false, false);
    pConsole->ExecuteString("g_enable_flashbang_mechanic 1", false, false);
    pConsole->ExecuteString("g_material_effects_early_preload 1", false, false);
    pConsole->ExecuteString("g_serverDfConeAngle 70", false, false);
    pConsole->ExecuteString("g_bomb_drop_enabled 1", false, false);
    pConsole->ExecuteString("hud_for_observer_enabled 1", false, false);
    pConsole->ExecuteString("i_offset_front -0.01", false, false);
    pConsole->ExecuteString("i_offset_nearFOV 60", false, false);
    pConsole->ExecuteString("i_offset_up -0.01", false, false);
    pConsole->ExecuteString("pl_lerp_depth 0.084", false, false);
    pConsole->ExecuteString("g_hide_locked_attachments 0", false, false);

    pConsole->ExecuteString("g_weapon_system_preload 1", false, false);
    pConsole->ExecuteString("g_weapon_customize_allow 1", false, false);

    //pConsole->ExecuteString("ui_show_explosives_hit_indicator 1", false, false);
    pConsole->ExecuteString("g_weapon_resistance_enabled 1", false, false);

    CBackend* pBackend = (CBackend*)operator_new(9999);
    CBackend* mBackend = CBackend_CBackend(pBackend, pFramework);
    pSsge->GetIGame()->m_pBackend = mBackend;
    //PrintToConsole("m_pBackend initialization\n", GREEN);

    CMissionBackend* pMissionBackend = (CMissionBackend*)operator_new(9999);
    CMissionBackend* mMissionBackend = CMissionBackend_CMissionBackend(pMissionBackend);
    this1->m_pMissionBackend = mMissionBackend;
    //PrintToConsole("m_pMissionBackend initialization\n", GREEN);

    IStreamEngine* m_pStreamEngine = (IStreamEngine*)operator_new(9999);
    IStreamEngine* pStreamEngine = CStreamEngine_CStreamEngine(m_pStreamEngine);
    pSystem->m_pStreamEngine = pStreamEngine;

    //PrintToConsole("m_pStreamEngine initialization\n", GREEN);


    CAbstractServerInfo* pAbstractServerInfo = (CAbstractServerInfo*)operator_new(2000);
    CAbstractServerInfo* mAbstractServerInfo = CAbstractServerInfo_CAbstractServerInfo(pAbstractServerInfo, eCS_Default);
    this1->m_pServerInfo = mAbstractServerInfo;

   // PrintToConsole("m_pServerInfo initialization\n", GREEN);

    return result;


}
bool __fastcall CanQuerySend(DWORD64* this_)
{
    return true;
}

char __fastcall CActor_SetPhysicalizationProfileHook(CActor* a1, EActorPhysProfiles a2)
{
    char result = CActor_SetPhysicalizationProfile(a1, a2);
    a1->m_pGameObjcet->ChangedNetworkState(0x2000000i64);
    return result;
}
void CryLogAlwaysRelease(const char* format, ...)
{
    //printf("%s\n", format);
    return CLogAlways(format);
}
IGameRef* __fastcall CGameStart_Init(CGameStartup* this1, IGameRef* result, SSystemInitParams* startupParams)
{
    startupParams->bDedicatedServer = true;
    startupParams->bSkipInput = true;
    ISSGE* pSSGE = ISSGE::Singleton();
    SSystemGlobalEnvironment* pSSG = SSystemGlobalEnvironment::Singleton();
    if (pSSGE) {
        pSSG->m_bServer = true;
        pSSGE->m_bClient = false;

    }

    IGameRef* result_ = UU_TES11_58271(this1, result, startupParams);
    return result_;
}



CBackend* __fastcall CGame_GetBackend(CGame* this1)  {
    SSystemGlobalEnvironment* pSsge = SSystemGlobalEnvironment::Singleton();
    return pSsge->GetIGame()->m_pBackend;

}
void __fastcall CScriptBind_System__LogString(DWORD64* this1, IFunctionHandler* pH, bool bToConsoleOnly)
{
    const char* sParam = NULL;
    std::string szText;

    typedef char(__thiscall* IFunctionHandler__GetParam)(void* this1, int nIdx, const char** value);
    IFunctionHandler__GetParam(0x140436EF0)(pH, 1, &sParam);


    if (sParam)
    {
        char sLogMessage[4096];

        if (sParam[0] <= 5 && sParam[0] != 0)
        {
            sLogMessage[0] = sParam[0];
            strcpy(&sLogMessage[1], "<Lua> ");
            strncat(sLogMessage, &sParam[1], sizeof(sLogMessage) - 7);
        }
        else
        {
            strcpy(sLogMessage, "<Lua> ");
            strncat(sLogMessage, sParam, sizeof(sLogMessage) - 7);
        }

        sLogMessage[sizeof(sLogMessage) - 1] = 0;

        printf("[Lua] %s\n", sLogMessage);
    }
    mCScriptBind_System__LogString(this1, pH, bToConsoleOnly);
}



int __fastcall sub_AD08E0(int arg0, char* Format, ...) //луа логи ошибок и вс¤кие другие(других не видел только луа пишет чето)
{
    int ret = 0;

    char log_buffer1[1024];
    ZeroMemory(log_buffer1, 1024);
    va_list args;
    va_start(args, Format);
    vsprintf(log_buffer1, Format, args);
    va_end(args);



    printf("[sub_AD08E0]RetAddr %s\n", log_buffer1);

    ret = mnsub_AD08E0(arg0, log_buffer1);


    return ret;
}




int __fastcall CScriptSystem_ErrorHandler_Hook(lua_State* L)
{
    lua_Debug ar;

    memset(&ar, 0, sizeof(lua_Debug));

    const char* sErr = sub_tolstring(0x140BF8690)(L, 1, 0);

    if (sErr)
    {
         printf("[Lua Error] %s \n", sErr);
    }
    int level = 1;
    while (sub_getstack(0x140BF9A70)(L, level++, &ar))
    {
        sub_getinfo(0x140BF9AF0)(L, "lnS", &ar);
        if (ar.name)
            printf("$CallStack: %s, (%s: %d) \n", ar.name, ar.short_src, ar.currentline);
        else
            printf("$CallStack: (null) (%s: %d) \n", ar.short_src, ar.currentline);
    }

    return 0;
}
int __fastcall CEntityLoadManager_ExtractEntityLoadParams(CEntityLoadManager* this1, XmlNodeRef* entityNode, SEntityLoadParams* outLoadParam)
{
    int ret = CEntityLoadManager_ExtractEntityLoadParams_p(this1, entityNode, outLoadParam);
    if (*(int*)((DWORD64)outLoadParam + 0x98) > 0 || *(int*)((DWORD64)outLoadParam + 0x9C) > 0) {
        *(int*)((DWORD64)outLoadParam + 0x40) |= ENTITY_FLAG_CLIENT_ONLY;
    }
    return ret;

}
bool __cdecl CCryAction_StartGameContext(void* this1, SGameStartParams* pGameStartParams)
{
    pGameStartParams->flags = eGSF_ImmersiveMultiplayer | eGSF_Server | eGSF_BlockingMapLoad | eGSF_BlockingClientConnect;
    pGameStartParams->maxPlayers = 32;



    return mCCryAction_StartGameContext_p(this1, pGameStartParams);
}
void __fastcall CDisplayModeManager_Initialize(DWORD64* this1)
{
    return;
}

int iLastState = -1;



void __fastcall Update_OnlineAccount(COnlineAccount* this1)
{
    SSystemGlobalEnvironment* mSSystemGlobalEnvironment = SSystemGlobalEnvironment::Singleton();
    if (mSSystemGlobalEnvironment)
    {
        void* pIGame = mSSystemGlobalEnvironment->GetCGame();
        if (pIGame)
        {
            typedef void(__cdecl* nCGame__OnlineTick)(void*);
            CallFunction<nCGame__OnlineTick>(pIGame, 0xD8)(pIGame);
            typedef void(__cdecl* nCOnlineChannel__Update)(void*);
            int state = *(int*)((DWORD64)this1 + 0xC0);
            // printf("status: %i\n", state);
            nCOnlineChannel__Update(0x141676DC0)(*(void**)((DWORD64)this1 + 0xD8));


            if (state == 0) // waiting connect
            {
                if (iLastState != state)
                {
                    //PrintToConsole("Establishing a connection to the lobby server...\n", GREEN);
                    //PrintToConsole("Connection state: ECS_Disconnected\n", MAGENTA);
                    typedef void(__cdecl* nCOnlineAccount__Connect)(void* this1, bool scheduleDelayed);
                    nCOnlineAccount__Connect((nCOnlineAccount__Connect)0x1412A1050)(this1, false);
                }
            }
            if (state == 1)
            {
                if (iLastState != state)
                {
                    //PrintToConsole("Connection state: eCS_WaitingCredentionals\n", MAGENTA);
                    typedef void(__cdecl* nCOnlineAccount__Login)(void* this1, const char* a2, const char* a3);
                    nCOnlineAccount__Login((nCOnlineAccount__Login)0x1412A1180)(this1, OnlineAccount_p::login, OnlineAccount_p::pwd);
                }
            }
            if (state == 2) { // connect
                if (iLastState != state)
                {
                    //PrintToConsole("Connection state: ECS_WaitingForConnection\n", MAGENTA);
                }
            }
            if (state == 3) { // disconnect
                if (iLastState != state)
                {
                    //PrintToConsole("Connection state: ECS_WaitingForDisconnect\n", MAGENTA);
                }
            }
            if (state == 4) {
                if (iLastState != state)
                {
                    Connect();
                    //PrintToConsole("Connection state: ECS_Connected\n", MAGENTA);
                    //PrintToConsole("The connection to the lobby server has been established!\n", GREEN);
                    //CGame::Signlenton()->m_pServerInfo->Update(CGame::Signlenton()->m_pServerInfo, 1);
                  
                }
            }
            iLastState = state;
        }
    }
    Update_OnlineAccount_p(this1);
}
void __fastcall CMenuObject_OnUpdate(DWORD64* this1, float uiFrameTime)
{
    return;
}
__int64 __fastcall CFlowchartManager_GetCurrentState(CFlowchartManager* this1)
{
    return 0;
}
__int64 __fastcall CFlowchartManager_IsState(CFlowchartManager* this1, int state)
{
    return state == 0;
}
void* __cdecl CGame_CGame(CGame* this1)
{
    void* ret = CGame_CGame_p(this1);
    CMissionBackend* pMissionBackend = (CMissionBackend*)operator_new(0x700);
    CMissionBackend* mMissionBackend = CMissionBackend_CMissionBackend(pMissionBackend);
    this1->m_pMissionBackend = mMissionBackend;
    return ret;

}
BOOL __fastcall SGameSerializerBase_IsValidSource(DWORD64* this1)
{
    return 1;
}
bool __fastcall SGameSerializer_CanQuerySend(DWORD64* this1)
{
    return true;
}
__int64 __fastcall CMissionBackend_OnMissionLoad(
    CMissionBackend* this1,
    const char* from_resource,
    const DWORD64* info,
    SMissionLoadSerializer__SMissionLoadConfigs* config,
    DWORD64 verbosityLevel)
{
    __int64 ret = CMissionBackend_OnMissionLoad_p(this1, from_resource, info, config, verbosityLevel);
    PrintToConsole("===============================\n", YELLOW);
    PrintToConsole("Mission loading started...\n", GREEN);
    if (ret == 0) {
        from_resource = OnlineAccount_p::master_server;
        PrintToConsole("Loading Mission: success!\n", GREEN);//
    }
    if (ret == 1)  PrintToConsole("Loading Mission: failed!\n", GREEN);
    if (ret == 2)  PrintToConsole("Loading Mission: not_owner!\n", GREEN);
    PrintToConsole("===============================\n", YELLOW);

    CGame* pGAME = CGame::Signlenton(); if (!pGAME) return 0;
    COnlineAccount* pAccount = pGAME->GetAccount(); if (!pAccount) return 0;


    typedef void(__cdecl* COnlineVariables__LoadVariables)(OnlineVariables* this1, XmlNodeRef* a3); //0x28 + 0x60
    COnlineVariables__LoadVariables((COnlineVariables__LoadVariables)0x14167ED60)(pAccount->GetVariables(), &config->online_variables_config);


     //   COnlineVariables__LoadVariables(onlineacc + offset, config->online_variables)


    return ret;
}
void __fastcall CCCacheJob_Do(DWORD64* this1)
{
    *(int*)((DWORD64)this1 + 4) = 3;
    return CCCacheJob_Do_p(this1);
}
void* __fastcall CLevelSystem__LoadLevel(CLevelSystem* this1, const char* levelName)
{
    void* ret = CLevelSystem__LoadLevel_p(this1, levelName);
    SSystemGlobalEnvironment* pSSGE = SSystemGlobalEnvironment::Singleton();
    if (pSSGE) {
        CSystem* pSystem = pSSGE->GetCSystem();
        if (pSystem) {
            ISystemEventDispatcher* pEventDispatcher = pSystem->GetISystemEventDispatcher();
            if (pEventDispatcher) {
                pEventDispatcher->OnSystemEvent();
            }
        }
    }
    return ret;

}
namespace Logging {
    typedef void* (__cdecl* nCryStringT_Format)(void*, char*, ...);
    nCryStringT_Format mCryStringT_Format = (nCryStringT_Format)0x1400BF330;

    void* CryStringT_Format(void* arg0, char* Format, ...)
    {
        char log_buffer1[4096];
        ZeroMemory(log_buffer1, 4096);
        va_list args;
        va_start(args, Format);
        vsprintf(log_buffer1, Format, args);
        va_end(args);

        // printf("[LOGS]: %s\n", log_buffer1);

        return mCryStringT_Format(arg0, log_buffer1);
    }

    typedef void* (__cdecl* nCryStackStringT_Format)(void*, char*, ...);
    nCryStackStringT_Format mCryStackStringT_Format = (nCryStackStringT_Format)0x140541D40;

    void* CryStackStringT_Format(void* arg0, char* Format, ...)
    {
        char log_buffer1[4096];
        ZeroMemory(log_buffer1, 4096);
        va_list args;
        va_start(args, Format);
        vsprintf(log_buffer1, Format, args);
        va_end(args);

        //printf("[LOGS]: %s\n", log_buffer1);

        return mCryStackStringT_Format(arg0, log_buffer1);
    }

    typedef void(__cdecl* nCLog__LogToFile)(void*, char*, ...);
    nCLog__LogToFile mCLog__LogToFile = (nCLog__LogToFile)0x1403AB530;

    void CLog__LogToFile(void* arg0, char* Format, ...)
    {
        char log_buffer1[2048];
        ZeroMemory(log_buffer1, 2048);
        va_list args;
        va_start(args, Format);
        vsprintf(log_buffer1, Format, args);
        va_end(args);

        //printf("[LOGS]: %s\n", log_buffer1);

        mCLog__LogToFile(arg0, log_buffer1);
    }

    typedef void(__fastcall* nCFlowGraphBase__FlowLoadError)(void* this1, const char* format, ...);
    nCFlowGraphBase__FlowLoadError mCFlowGraphBase__FlowLoadError = (nCFlowGraphBase__FlowLoadError)0x14061D5E0;

    void CFlowGraphBase__FlowLoadError(void* this1, const char* format, ...)
    {
        char log_buffer1[2048];
        ZeroMemory(log_buffer1, 2048);
        va_list args;
        va_start(args, format);
        vsprintf(log_buffer1, format, args);
        va_end(args);

        //printf("[LOGS]: %s\n", log_buffer1);

        mCFlowGraphBase__FlowLoadError(this1, format);
    }
}
void __fastcall AddRegisterSoundListener(void* pEst, int state)
{
    return;
}

void __fastcall CAbstractServerInfo_Update(CAbstractServerInfo* this1, bool isForceUpdate) {
    CGame* m_pGame = CGame::Signlenton();
    return CAbstractServerInfo_Update_p(m_pGame->m_pServerInfo, isForceUpdate);
}

__int64 __fastcall ScriptBind_GameRules_DisconnectToLobby(CScriptBind_GameRules* this1, IFunctionHandler* pH) {
    CGame::Signlenton()->m_pServerInfo->m_telemetrySent = true;
    //printf("[ScriptBind_GameRules::DisconnectToLobby] initialization succesfully!\n");
    //SSystemGlobalEnvironment::Singleton()->GetIConsole()->ExecuteString("disconnect", false, false);
    return CScriptBind_GameRules_DisconnectToLobby_p(this1, pH);
}

__int64 __fastcall CPassedCheckpointsTracker_GetPassedCheckpoints(CPassedCheckpointsTracker* this1, SPassedCheckpoints* result, unsigned __int64 profileId) {
    CGame* m_pGame = CGame::Signlenton();
    //printf("m_passedCheckpointsTracker Init\n");
    return 0; //CPassedCheckpointsTracker_GetPassedCheckpoints_p(m_pGame->GetFramework()->GetCGameRules()->m_passedCheckpointsTracker(), result, profileId);
}

CAbstractServerInfo* __fastcall Game_GetServerInfo(CGame* a1) {
    CGame* m_pGame = CGame::Signlenton();
    m_pGame->m_pServerInfo->m_telemetrySent = true;

    return m_pGame->m_pServerInfo;
}

void __fastcall COpticsManager__Create(void* this1, __int64 type)
{
    return;
}

void __fastcall GameRules_OnEndGame(CGameRules* this1, __int64 reason, int winningTeamId) {
    if (this1->m_achievementsTracker()) {
        printf("GameRules_OnEndGame\n");
        CAchievementsTracker::SaveAchievements(this1->m_achievementsTracker());
    }
    printf("GameRules_OnEndGame_0\n");
    return CGameRules_OnEndGame(this1, reason, winningTeamId);
}


void __fastcall CPlayerInputSerializer_OnTeleportPlayer(CGameRules* this1, SGameHitInfo* source) {
    //if (source->shared.typeId == 15) return;
    CPlayerInputSerializer_OnTeleportPlayer_p(this1, source);
}


void __fastcall CAchievementSystem_CAchievementSystem(CAchievementSystem* this1) {

    CAchievementSystem__CAchievementSystem_p(this1);

    CAchievementConfig* pAchievmentConfig = (CAchievementConfig*)operator_new(2000);
    CAchievementConfig* mAchievmentConfig = CAchievementBackend_CAchievementConfig(pAchievmentConfig);
    this1->m_pAchievementConfig = mAchievmentConfig;
    m_pAchievementConfig = this1->m_pAchievementConfig;

    CAchievementBackend* pAchievmentBackend = (CAchievementBackend*)operator_new(2000);
    CAchievementBackend* mAchievmentBackend = CAchievementBackend_CAchievementBackend(pAchievmentBackend);
    this1->m_pBackend = mAchievmentBackend;
    m_pBackend = this1->m_pBackend;

    //printf("m_pBackend: %i\n", this1->m_pBackend);

    //printf("[AchievmentBackend] initialization succesfully!\n");
}

void __fastcall CPhysCallbacks__OnFoliageTouched(void* pEvent) {
    return;
}
bool __fastcall GameRules_OnClientConnect(CGameRules* this1, __int32 channelId, bool isReset) {
    CGame* m_pGame = CGame::Signlenton();
    if (m_pGame->m_pMissionBackend) {
        __int64 profileId = m_pGame->GetFramework()->GetNetChannel(channelId)->GetProfileId();
        //printf("[CAchievementBackend::RequestAchievements] channelId: %i profileId: %i\n", channelId, profileId);
        CAchievementBackend::RequestAchievements(m_pBackend, profileId);
    }
    return CGameRules_OnClientConnect_p(this1, channelId, isReset);
}




void __fastcall CInventoryPickup_PickupWeapon(void* this1, CPlayer* player, const Vec3_tpl<float>* itemPos) {
    //printf("CInventoryPickup_PickupWeapon y: %d\n", itemPos->y);
    CInventoryPickup_PickupWeapon_p(this1, player, itemPos);
}

CAchievementBackend* __fastcall AchievementSystem_GetBackend(CAchievementSystem* this1) {
    //printf("[AchievementSystem::GetBackend] initialization succesfully!\n");
    return m_pBackend;
}

CAchievementConfig* __fastcall AchievementSystem_GetConfig(CAchievementSystem* this1) {
    //printf("[AchievementSystem::GetConfig] initialization succesfully!\n");
    return m_pAchievementConfig;
}
void __fastcall GameRules_InitSessionStatistics(CGameRules* this1) {
    if (this1->m_achievementsTracker()) {
        //printf("[m_achievementsTracker] initialization succesfully!\n");
        CAchievementsTracker::Init(this1->m_achievementsTracker());
        //printf("[CAchievementsTracker::Init] initialization succesfully!\n");
    }
    return CGameRules_InitSessionStatistics_p(this1);
}



bool __fastcall Game_Update(CGame* this1, bool haveFocus, unsigned int updateFlags) {
    TelemetryInit();


    if (this1->m_pServerInfo) {
        this1->m_pServerInfo->Update(this1->m_pServerInfo, 0);
    }
    return CGame_Update_p(this1, haveFocus, updateFlags);
}
__int64 __fastcall GetMasterServersSerializer(SLoadBalancingStrategy* this1, CMasterServerList* serverList, SMasterServerInfo::EStatus cause, Functor2<char const*, unsigned short>* callback, Functor2<enum EOnlineError, int>* errorCallback, char* failedResource, const char* priorityChannel, const char* priorityResource, EChannelSearchType searchType) {
    this1->m_getMasterServerCallback = callback;
    this1->m_getMasterServerFailedCallback = errorCallback;


    //SDedicatedMSPickPolicy v11;
    //signed __int64 v1 = SDedicatedMSPickPolicy::Operator(&v11, serverList);
    //if (v1 == CMasterServerList::ServerCount(serverList)) {
    //    using ErrorCallbackFunc = __int64(__fastcall*)(__int64, __int64, __int64);
    //    auto func = reinterpret_cast<ErrorCallbackFunc>(errorCallback + 32);
    //    return func(errorCallback, 1013i64, 0i64);
    //}
    //else {       
    //    SMasterServerInfo* Server = CMasterServerList::GetServer(serverList, v1);
    //    if (!Server) { printf("[CMasterServerList::GetServer] Not\n"); return 0; }
    //    using CallbackFunc = __int64(__thiscall*)(__int64, __int64, __int64);
    //    auto func = reinterpret_cast<CallbackFunc>(callback + 0x20);
    //    //return func(callback, *(reinterpret_cast<__int64*>(Server) + 0x8), 0);
    //}
    return 1;
}

void __fastcall SLobbyServerInfo_SerializeAllToXml(SLobbyServerInfo* this1, XmlNodeRef* outNode) {
    outNode->p->setAttr("forward_receiver_id", SSystemGlobalEnvironment::Singleton()->GetIConsole()->GetCVar("forward_receiver_id")->GetString());
    return SLobbyServerInfo_SerializeAllToXml_p(this1, outNode);
}

bool __fastcall AbstractServerInfo_IsOwner(CAbstractServerInfo* this1, const char* masterserver_resource) {
    return 1;
    //return strcmp(masterserver_resource, SSystemGlobalEnvironment::Singleton()->GetIConsole()->GetCVar("online_masterserver_forward_receiver_id")->GetString()) == 0;
}
bool __fastcall GameSerializer_CanQuerySend() {
    return 1;
}

void __fastcall GameRules_ProcessEvent(CGameRules* this1, SEntityEvent* event) {
    switch (event->event) {
    case ENTITY_EVENT_ENTER_SCRIPT_STATE:
        SSystemGlobalEnvironment* pSSG = SSystemGlobalEnvironment::Singleton();
        if (pSSG->m_bServer) {
            if (this1->IsPostGame()) {
                //CAchievementsTracker::SaveAchievements(this1->m_achievementsTracker());
                CGame* m_pGame = CGame::Signlenton();
                CAbstractServerInfo::Update(m_pGame->m_pServerInfo, true);
            }
        }
        break;
    }
    return CGameRules_ProcessEvent_p(this1, event);
}



bool __fastcall CPlayer_CreateInputClassByType(CPlayer* this1, int nPlayerInputType) {
    if (nPlayerInputType == 3) {
        return CPlayer_CreateInputClassByType_p(this1, 2);
    }
    else {
        return CPlayer_CreateInputClassByType_p(this1, nPlayerInputType);
    }
}

__int64 __fastcall CCertificateValidator_Query(__int64 a1, __int64 a2) {
    return 0;
}
__int64 __fastcall dfgdfgdfgfgd(__int64 a1, __int64 a2) {
    return 0;
}
void __fastcall SSADSDFSDFSDFSDF(__int64 a1) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF1(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF11(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF12(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF13(__int64 a1, __int64 a2) {
    return;
}
__int64 __fastcall SSADSDFSDFSDFSDF14(__int64 a1, __int64 a2) {
    return 0;
}
void __fastcall SSADSDFSDFSDFSDF15(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF16(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF17(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF18(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF19(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF20(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF21(__int64 a1, __int64 a2) {
    return;
}
void __fastcall SSADSDFSDFSDFSDF22(__int64 a1, __int64 a2) {
    return;
}

void __fastcall SSADSDFSDFSDFSDF23(__int64 a1, __int64 a2) {
    
    return;
}

void __fastcall SSADSDFSDFSDFSDF24(__int64 a1, __int64 a2) {

    return;
}
void __fastcall SSADSDFSDFSDFSDF25(__int64 a1, __int64 a2) {

    return;
}
void __fastcall SSADSDFSDFSDFSDF26(__int64 a1, __int64 a2) {

    return;
}
void __fastcall SSADSDFSDFSDFSDF27(__int64 a1, __int64 a2) {

    return;
}

void __fastcall SSADSDFSDFSDFSDF28(__int64 a1, __int64 a2) { return; }
void __fastcall SSADSDFSDFSDFSDF29(__int64 a1, __int64 a2) { return; }
float* __fastcall SSADSDFSDFSDFSDF30(__int64 a1, float* a2, void* a3, float* a4, float* a5) 
{ 
    a2 = 0;
    return SADSDFSDFSDFSDF30_p(a1, a2, a3, a4, a5);
}


void __fastcall CWeaponSystem_OnLoadingStart(__int64 a1) {
    BYTE* v2; // rdx
    __int64 v3; // r8
    DWORD64* v4; // rax
    __int64 v6; // [rsp+30h] [rbp+8h] BYREF
    char v7; // [rsp+38h] [rbp+10h] BYREF

    SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::Singleton();
    
    (*(void(__fastcall**)(DWORD64, __int64*))(**(DWORD64**)(gEnv + 192) + 40i64))(*(DWORD64*)(gEnv + 192), &v6);
    v2 = (BYTE*)0x142487DD0;
    if (*(BYTE*)(gEnv + 617)) v2 = (BYTE*)0x142487DD8;
    if (v2)
    {
        v3 = -1i64;
        do
            ++v3;
        while (v2[v3]);
    }
    else
    {
        v3 = 0i64;
    }
    typedef void(__cdecl* sub_1400A7960)(__int64, BYTE*, __int64);
    sub_1400A7960((sub_1400A7960)0x1400A7960)(a1 + 240, v2, v3);
    typedef void(__cdecl* sub_14139C510)(__int64, unsigned __int8*);
    sub_14139C510((sub_14139C510)0x14139C510)(a1, (unsigned __int8*)(SSystemGlobalEnvironment::Singleton() + 910));
}
void __fastcall CGame_ConfigureGameChannel(__int64 a1, unsigned __int8 a2, __int64 a3) 
{
    __int64 v6; // rsi
    __int64 v7; // rdi
    __int64 v8; // rax
    __int64 v9; // rax
    if (a2) {
        (*(void(__fastcall**)(DWORD64, __int64))(**(DWORD64**)(a1 + 312) + 8i64))(*(DWORD64*)(a1 + 312), a3);
        (*(void(__fastcall**)(DWORD64, __int64))(**(DWORD64**)(a1 + 1152) + 8i64))(*(DWORD64*)(a1 + 1152), a3);
    }
    else {
        v6 = (__int64)operator_new(0x170i64);
        if (v6) {
            v7 = (*(__int64(__fastcall**)(__int64))(*(DWORD64*)a1 + 104i64))(a1);
            typedef void(__cdecl* sub_1411D8AC0)(__int64);
            sub_1411D8AC0((sub_1411D8AC0)0x1411D8AC0)(v7);
            *(DWORD64*)v6 = 0x142102378;
            *(DWORD64*)(v6 + 288) = 0i64;
            *(DWORD64*)(v6 + 296) = 0i64;
            v8 = (__int64)operator_new(56i64);
            *(DWORD64*)v8 = v8;
            *(DWORD64*)(v8 + 8) = v8;
            *(DWORD64*)(v8 + 16) = v8;
            *(DWORD64*)(v8 + 24) = 257;
            *(DWORD64*)(v6 + 288) = v8;
            typedef void(__cdecl* sub_1400885A0)(__int64);
            sub_1400885A0((sub_1400885A0)0x1400885A0)(v6 + 304);
            *(DWORD64*)(v6 + 312) = 0;
            *(DWORD64*)(v6 + 316) = -1;
            *(DWORD64*)(v6 + 264) = v7;
            *(DWORD64*)(v6 + 320) = 0i64;
            *(DWORD64*)(v6 + 328) = 0i64;
            *(DWORD64*)(v6 + 336) = 0i64;
            *(DWORD64*)(v6 + 344) = 0i64;
            *(DWORD64*)(v6 + 352) = 0i64;
            *(DWORD64*)(v6 + 360) = 0i64;
        }
    }
    v9 = (*(__int64(__fastcall**)(DWORD64))(**(DWORD64**)(a1 + 0x1D0) + 168i64))(*(DWORD64*)(a1 + 0x1D0));
    (*(void(__fastcall**)(__int64, __int64))(*(DWORD64*)v9 + 8i64))(v9, a3);
}
IStreamEngine* __fastcall GetStreamEngine(CSystem* this1) {
    CSystem* pSystem = SSystemGlobalEnvironment::Singleton()->GetCSystem();
    return pSystem->m_pStreamEngine;
}
bool __fastcall CGameRules_NetSerialize(CGameRules* this1, __int64 ser, EEntityAspects aspect, unsigned __int8 profile) {
    if (aspect == EEntityAspects::eEA_GameServerD) {
        return 1;
    }
    return CGameRules_NetSerialize_p(this1, ser, aspect, profile);
}
bool __fastcall PreparePrepare() {
    return true;
}



int iq = 0;
bool isStart = false;
int countKills = 0;

std::vector<std::pair<int, int>> globalKillData;
std::vector<std::pair<int, int>> globalKillDataMatHead;
std::vector<std::pair<int, int>> globalKillDataMelee;

int i = 0;

namespace SrazuKills {
    bool SrazuKilauras   = false   ;
}

namespace BonusPlayer {
    int ID = 0;
    int bonus = 0;
    int last_achiev_id = 0;


    /* хуйня для бонуса ( т.е очки за помощь) */
    int entityId = 0;
    bool is_helper_player = false;
    int ID_helper = 0;
    int health = 0;

}

void __fastcall CGameRules_UpdateHook(CGameRules* this1, void* ctx, int updateSlot) {
    CGameRules_Update_QueuedShotHit(this1);

    if (iq <= 90) {
        SrazuKills::SrazuKilauras = 1;
    }

    if (iq >= 250) {
        iq = 0;
        isStart = false;
        globalKillData.clear();
        globalKillDataMatHead.clear();
        globalKillDataMelee.clear();
    }

    

    if (isStart) {
        iq++;
    }
    else {
        if (BonusPlayer::last_achiev_id != 0 && BonusPlayer::ID != 0) {
            using SendTrackerNotify = void(__thiscall*)(CGameRules* this1, int instantAwardId, int profileId, bool bClientOnly);
            SendTrackerNotify(0x1414B4F40)(this1, BonusPlayer::last_achiev_id, BonusPlayer::ID, 0);
        }
        iq = 0;
        BonusPlayer::last_achiev_id = 0;
        BonusPlayer::ID = 0;
    }

   //f (GetAsyncKeyState(VK_F1) & 1) {
   //   printf("award %i\n", i);
   //   using SendTrackerNotify = void(__thiscall*)(CGameRules* this1, int instantAwardId, int profileId, bool bClientOnly);
   //   SendTrackerNotify(0x1414B4F40)(this1, i, 2, 0);
   //   i++;
   //

    
   


    //  using SendTrackerNotify = void(__thiscall*)(CGameRules* this1,int instantAwardId,int profileId,bool bClientOnly);
    //  SendTrackerNotify(0x1414B4F40)(this1, 0x11, 1, 0);
    //1414B4F40

    return CGameRules_Update(this1, ctx, updateSlot);
}
unsigned __int64 __fastcall CGameRules_UpdateQueuedShotHit(CGameRules* this1) {
    return CGameRules_Update_QueuedShotHit(this1);
}
bool __fastcall CGameRules_Init(CGameRules* this1, IGameObject* pGameObject)
{
    if (this1->m_pInstantAwardSystem()) {
        CInstantAwardSystem* v1 = (CInstantAwardSystem*)operator_new(8000);



        CInstantAwardTracker* InstantTracker = CInstantAwardTracker_CInstantAwardTracker(v1);




        this1->m_pInstantAwardSystem()->m_pTracker = InstantTracker;

        PrintToConsole("m_pTracker initialization\n", GREEN);
    }
    //CRandomItemDropSystem* m_pRandomItemDropSystem = (CRandomItemDropSystem*)operator_new(2000);
    //CRandomItemDropSystem* pRandomItemDropSystem = CRandomItemDropSystem_p(m_pRandomItemDropSystem);
    //this1->m_pRandomItemDropSystem = pRandomItemDropSystem;
    ////PrintToConsole("m_pRandomItemDropSystem initialization\n", GREEN);
    return CGameRules_Init_p(this1, pGameObject);
}

CMissionStatistics* GetMissionStatistics(CGameRulesC* this1) {
    return this1->m_pMissionStatistics;
}

std::string createUrl(int profileId, const char* value, const char* itemType, const std::string& stat) {
    return "http://127.0.0.1:8000/api/?method=telemetryStreamSent&profile_id=" + std::to_string(profileId) +
        "&value=" + value +
        "&item_type=" + itemType +
        "&stat=" + stat;
}

enum KillParams {
    ComboKills = 0,
    HeadFuse = 1,
    SkullCrasher = 2,
    Braniac = 3,
    bouncer = 4,
    grenadier = 5,
    MegaGrenadier = 6,
    UltraGrenadier = 7,
    butcher = 8,
    BloodyButcher = 9,
    MercilessButcher = 10,
    AssistCSM = 11,
    discharge = 12,
    Counterattack = 13,
    Surprise = 14,
    ThreeMines = 15,
    InSlide = 16,
    TwoKill = 17,
    ThreeKill = 18,
    KillInTwoInSlide = 21,
    KillInFourInSlide = 22,
    MeatGrinder = 23,
    AdGrinder = 24,
    InSlideInHead = 26,
    KillThreeInSlide = 27,
    Dominator = 29,
    KnockbackKill = 32,
    KillInTwoSrazu = 40,
    KillInThreeSrazu = 41,
    KillInFourSrazu = 42,




    KillInFourDefault = 42,
    InJumpKill = 121,
    Drovosek = 122,
    BloodyDrovosek = 123,
    RuthlessDrovosek = 124, /* безжалостный дровосек */
    JuggernautKill = 125, 
    NindjaKill = 126, 
    PyromanKill = 127, 
    GrenadeLauncherKill = 128, 

};

/*
   0 - комбо убийство
   1 - взрыватель голов
   2 - крушитель черепов
   3 - мозголом
   4 - вышибатель
   5 - гренадер
   6 - мега-гренадер
   7 - ультра-гренадер
   8 - мясник
   9 - кровавый мясник
   10 - беспощадный мясник

   11 - помощник (по подсаду)
   12 - разряд (убить с дефов)
   13 - контратака (убить в положении нок-дауна)
   14 - сюрприз (убить с мины)
   15 - троих миной
   16 - в подкате
   17 - двоих
   18 - троих
   19 - надежный курьер (убить находясь с кодами-запуска)
   20 - всегда на страже
   21 - двоих в подкате
   22 - лавина (четырех в подкате)
   23 - мясорубка
   24 - адская мясорубка
   25 - бомбадир
   26 - в подкате в голову
   27 - троих в подкате
   29 - доминатор
   32 - нокдаун
   41 - троих сразу
   42 - четырех сразу
   */



std::chrono::steady_clock::time_point startTimeInOld;




auto findProfile(int profileId) {
    return std::find_if(globalKillData.begin(), globalKillData.end(),
        [profileId](const std::pair<int, int>& p) { return p.first == profileId; });
}

auto findProfileMatHead(int profileId) {
    return std::find_if(globalKillDataMatHead.begin(), globalKillDataMatHead.end(),
        [profileId](const std::pair<int, int>& p) { return p.first == profileId; });
}

auto findProfileMelee(int profileId) {
    return std::find_if(globalKillDataMelee.begin(), globalKillDataMelee.end(),
        [profileId](const std::pair<int, int>& p) { return p.first == profileId; });
}

void updateKillCount(int profileId, int newCount) {
    auto it = findProfile(profileId);
    if (it != globalKillData.end()) {
        it->second = newCount;
    }
    else {
        globalKillData.emplace_back(profileId, newCount);
    }
}

void updateKillCountMelee(int profileId, int newCount) {
    auto it = findProfileMelee(profileId);
    if (it != globalKillDataMelee.end()) {
        it->second = newCount;
    }
    else {
        globalKillDataMelee.emplace_back(profileId, newCount);
    }
}

void updateKillCountMatHead(int profileId, int newCount) {
    auto it = findProfileMatHead(profileId);
    if (it != globalKillDataMatHead.end()) {
        it->second = newCount;
    }
    else {
        globalKillDataMatHead.emplace_back(profileId, newCount);
    }
}

int getKillCount(int profileId) {
    auto it = findProfile(profileId);
    if (it != globalKillData.end()) {
        return it->second;
    }
    return 0;
}

int getKillCountMatHead(int profileId) {
    auto it = findProfileMatHead(profileId);
    if (it != globalKillDataMatHead.end()) {
        return it->second;
    }
    return 0;
}



int getKillCountMelee(int profileId) {
    auto it = findProfileMelee(profileId);
    if (it != globalKillDataMelee.end()) {
        return it->second;
    }
    return 0;
}

struct PlayerData {
    std::chrono::steady_clock::time_point startTime;
    bool hasStartTime = false;
};


const char* GetClassToChar(ECharacterClassId classid) {

    const char* value = "unknown";

    switch (classid)
    {
    case eCCI_Rifleman:
        value = "Rifleman";
        break;
    case eCCI_Heavy:
        value = "Heavy";
        break;
    case eCCI_Recon:
        value = "Recon";
        break;
    case eCCI_Medic:
        value = "Medic";
        break;
    case eCCI_Engineer:
        value = "Engineer";
        break;
    default:
        break;
    }

    return value;

}



pugi::xml_document g_doc;


pugi::xml_document g_xmlDoc;


void InitXML() {
    g_doc.load_string("<telemetry_stream finalize='0'></telemetry_stream>");
    //g_xmlDoc.load_string("<telemetry_stream finalize='0'></telemetry_stream>");
}
#include <ws2tcpip.h>
#include <io.h>


int id_for_jump = 0;
bool is_jump_player = false;

void Disconnect() {
    if (clientSocket != INVALID_SOCKET) {
        closesocket(clientSocket);
        clientSocket = INVALID_SOCKET;
        WSACleanup();
    }
}

bool isDataLoaded = false;


void LogKill(int profile_id, 
    const char* nickname, 
    int target_id = 0, 
    const char* target_nick = "",
    const char* body_event = "",
    int g_victorycondition = 0,
    const char* weaponName = "",
    bool isZoomedWeapon = false,
    const char* my_state = "",
    const char* targetState = "",
    const char* my_class = "",
    const char* target_class = "",
    float damage = 0, 
    const char* mission_name = "",
    const char* slide_kill = "false",
    const char* jump_kill = "false")
{
    //return;
    if (profile_id != id_for_jump) jump_kill = "false";
    if (profile_id != id_for_slide) slide_kill = "false";

    //if (target_id != 0) {

        InitXML();
        pugi::xml_node streamNode = g_doc.child("telemetry_stream");
        pugi::xml_node playerNode = streamNode.append_child("player");
        playerNode.append_attribute("profile_id") = profile_id;
        playerNode.append_attribute("nickname") = nickname;
        playerNode.append_attribute("g_victory_condition") = g_victorycondition;
        playerNode.append_attribute("weapon_name") = weaponName;
        playerNode.append_attribute("is_zoomed_weapon") = isZoomedWeapon;
        playerNode.append_attribute("state") = my_state;
        playerNode.append_attribute("class") = my_class;
        playerNode.append_attribute("damage") = damage;
        playerNode.append_attribute("mission_name") = mission_name;

        pugi::xml_node killNode = playerNode.append_child("kill_player");
        killNode.append_attribute("target_id") = target_id;
        killNode.append_attribute("nickname") = target_nick;
        killNode.append_attribute("body_event") = body_event;
        killNode.append_attribute("state") = targetState;
        killNode.append_attribute("class") = target_class;
        killNode.append_attribute("slide_kill") = slide_kill;
        killNode.append_attribute("jump_kill_target") = jump_kill;
        






    //}

    //else if ( target_id == 0 ) 
    //{
    //    pugi::xml_node streamNode = g_xmlDoc.child("telemetry_stream");
    //    pugi::xml_node playerNode = streamNode.append_child("player");
    //    playerNode.append_attribute("profile_id") = profile_id;
    //    playerNode.append_attribute("nickname") = nickname;
    //    playerNode.append_attribute("g_victory_condition") = g_victorycondition;
    //
    //    pugi::xml_node killNode = playerNode.append_child(body_event);
    //
    //
    //}

    
    std::ostringstream oss;
    g_doc.save(oss, "", pugi::format_no_declaration);
    std::string xml_str = oss.str() + "\n";
    //printf("%s\n", xml_str.c_str()); 
    Send(xml_str.c_str());
    //Disconnect();




    //WSADATA wsaData;
    //SOCKET ConnectSocket = INVALID_SOCKET;
    //struct sockaddr_in clientService;
    //
    //const char* server_ip = "127.0.0.1";
    //int port = 5222;
    //
    //
    //
    //if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    //    printf("[DedicatedServer] failed to create message.\n");
    //    return;
    //}
    //
    //ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //if (ConnectSocket == INVALID_SOCKET) {
    //    printf("[DedicatedServer] failed to create socketv4.\n");
    //    WSACleanup();
    //    return;
    //}
    //
    //clientService.sin_family = AF_INET;
    //inet_pton(AF_INET, server_ip, &clientService.sin_addr);
    //clientService.sin_port = htons(port);
    //
    //if (connect(ConnectSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
    //    printf("[DedicatedServer] failed to connect socketv4.\n");
    //    closesocket(ConnectSocket);
    //    WSACleanup();
    //    return;
    //}





   // std::ostringstream oss;
   // g_xmlDoc.save(oss, "", pugi::format_no_declaration);
   // std::string xml_str = oss.str();
   // printf("%s\n", xml_str.c_str());
   //
   // const char* data = xml_str.c_str();
   // size_t data_len = xml_str.size();
   // size_t total_sent = 0;
   //
   // while (total_sent < data_len) {
   //     int sent = send(ConnectSocket, data + total_sent, (int)(data_len - total_sent), 0);
   //     if (sent == SOCKET_ERROR) {
   //         printf("[DedicatedServer] failed to send message from socketv4.\n");
   //         closesocket(ConnectSocket);
   //         WSACleanup();
   //         return;
   //     }
   //     total_sent += sent;
   // }
   //
   //
   //
   // closesocket(ConnectSocket);
   // WSACleanup();

}



const uint32_t MAGIC = 4277001901U;

void sendPacket(SOCKET sock, const std::string& message) {
    uint32_t magic = htonl(MAGIC); // убедимся, что 60 передается как uint32
    uint32_t length = htonl(message.size());

    // Создаем весь буфер для отправки
    std::vector<uint8_t> buffer;

    // Магическое число
    uint8_t* magicBytes = reinterpret_cast<uint8_t*>(&magic);
    buffer.insert(buffer.end(), magicBytes, magicBytes + sizeof(magic));

    // Длина
    uint8_t* lengthBytes = reinterpret_cast<uint8_t*>(&length);
    buffer.insert(buffer.end(), lengthBytes, lengthBytes + sizeof(length));

    // Данные
    buffer.insert(buffer.end(), message.begin(), message.end());

    // Отправляем
    int totalSent = 0;
    int toSend = buffer.size();
    while (totalSent < toSend) {
        int sent = send(sock, reinterpret_cast<const char*>(buffer.data() + totalSent), toSend - totalSent, 0);
        if (sent == SOCKET_ERROR) {
            std::cerr << "Ошибка при отправке: " << WSAGetLastError() << std::endl;
            return;
        }
        totalSent += sent;
    }
    std::cout << "Пакет отправлен! Размер: " << buffer.size() << " байт." << std::endl;
   // printf("packet send\n");
}

using SendTrackerNotify = void(__thiscall*)(CGameRules* this1, int instantAwardId, int profileId, bool bClientOnly);


//'WSASocketA': Use WSASocketW() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings

void Reward_Player(CGameRules* pGameRules, IGameFramework* pGameFramework, int hit_type, float damage, int death_player, int material, CPlayer* m_pShoterPlayer, CPlayer* pPlayer) {

    PlayerData player;

    SCVars* pCvars = SCVars::Singlenton(); if (!pCvars) return;



    //std::string url = createUrl(death_player, "null", "player_death_weaponisnull", "death_player");
    //
    //HINTERNET hInternet4 = InternetOpen("HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    //if (hInternet4 == NULL) {
    //    std::cerr << "InternetOpen failed" << std::endl;
    //}
    //
    //HINTERNET hConnect4 = InternetOpenUrl(hInternet4, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    //if (hConnect4 == NULL) {
    //    printf("[CryOnline:Telemetry] failed to init request");
    //    //InternetCloseHandle(hInternet4);
    //    //return;
    //}


    typedef int(__fastcall* CActor_GetProfileId)(CPlayer*);
    int id = CActor_GetProfileId((CActor_GetProfileId)0x141239700)(m_pShoterPlayer);

    typedef int(__fastcall* CActor_GetProfileId)(CPlayer*);
    int idplayerforshooter = CActor_GetProfileId((CActor_GetProfileId)0x141239700)(pPlayer);


    //printf("fdslfdlsldflfdsl :%i\n", m_pShoterPlayer->Stance());

    //int currentKillCount = GetKillCount(player, id);
    //currentKillCount++;

    //countKills++;

    int currentCount = getKillCount(id);
    currentCount++;
    updateKillCount(id, currentCount);

    player.startTime = std::chrono::steady_clock::now();
    player.hasStartTime = true;
    isStart = true;

    int killCountInVector = currentCount;

   
    


   









    //playerRewards.emplace_back(id, countKills);


    auto nItem = m_pShoterPlayer->GetCurrentItem();
    if (nItem) {

        CWeaponGeneral* pGeneral = nItem->GetWeaponGeneral(); if (!pGeneral) return;
        CWeaponParameters* pParameters = pGeneral->GetWeaponParams(); if (!pParameters) return;



        const char* weaponName = nItem->GetEntity()->GetName();
        //"http://127.0.0.1:8000/api/?method=telemetryStreamSent&profile_id=1&value=melee&item_type=sr46_shop&stat=kill"

        // РАЗЛИЧНАЯ СТАТИСТИКА BEGIN

                // printf("====================== CActor_Statistics ===========================\n");
                //
                // printf("my class: %s\n", GetClassToChar(m_pShoterPlayer->GetCurrentClassId()));
                // printf("player class (to death): %s\n", GetClassToChar(pPlayer->GetCurrentClassId()));
                // printf("my state is: %s\n", GetStanceName(m_pShoterPlayer->Stance()));
                // printf("player state is: %s\n", GetStanceName(pPlayer->Stance()));
                // printf("weapon_is_zoomed: %i\n", pGeneral->IsZooming());
                // printf("weapon_name: %s\n", weaponName);
                // printf("g_victorycondition: %i\n", pCvars->g_VictoryCondition());
                // printf("hitType: %i\n", hit_type);
                // printf("material: %i\n", material);

         // проверка если убит с гранаты при этом не взрывом, то значит это хит неверный

        //14151C0F0

        using IsSilenced = bool(__thiscall*)(CWeaponParameters*);
        bool isSilenced = IsSilenced(0x14151C0F0)(pParameters);



      //  printf("%i\n", is_slide_player);
      //  printf("%i\n", is_jump_player);
      //  printf("is_silenced: %s\n", isSilenced ? "true" : "false");





        //CKillStats* v76 = (CKillStats*)operator_new(0xD0ui64);
        //if (v76) {
        //    printf("jumped: %i\n", v76->is_jumped);
        //}




        //printf("jumped: %i\n", isJumped);





















       // printf("======================== CActor_Statistics =========================\n");


        // РАЗЛИЧНАЯ СТАТИСТИКА END


     //   printf("%s\n", weaponName);

        if (strstr(weaponName, "df01")) {
            SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::discharge, id, 1);
            //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::discharge, id, 0);
            BonusPlayer::ID = id;
            BonusPlayer::bonus += 200;
            BonusPlayer::last_achiev_id = KillParams::discharge;
        }

        if (killCountInVector == 7) {
            SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::ComboKills, id, 1);
            //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::ComboKills, id, 0);
            BonusPlayer::ID = id;
            BonusPlayer::bonus += 200;
            BonusPlayer::last_achiev_id = KillParams::ComboKills;
        }
        if (killCountInVector == 8) {
            SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::Dominator, id, 1);
            //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::Dominator, id, 0);
            BonusPlayer::ID = id;
            BonusPlayer::bonus += 300;
            BonusPlayer::last_achiev_id = KillParams::Dominator;
        }

        int slide_kill_by_player = pPlayer->GetSlideKillByPlayer();

        if (id == id_for_slide) {

            if (is_slide_player) {
                if (killCountInVector == 2) {
                    SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInTwoInSlide, id, 1);
                    //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInTwoInSlide, id, 0);
                    BonusPlayer::ID = id;
                    BonusPlayer::bonus += 75;
                    BonusPlayer::last_achiev_id = KillParams::KillInTwoInSlide;
                }
            }

            if (is_slide_player) {
                if (killCountInVector == 3) {
                    SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillThreeInSlide, id, 1);
                    //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillThreeInSlide, id, 0);
                    BonusPlayer::ID = id;
                    BonusPlayer::bonus += 100;
                    BonusPlayer::last_achiev_id = KillParams::KillThreeInSlide;
                }
            }

            if (is_slide_player) {
                if (killCountInVector == 4)
                {
                    SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInFourInSlide, id, 1);
                    //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInFourInSlide, id, 0);
                    BonusPlayer::ID = id;
                    BonusPlayer::bonus += 200;
                    BonusPlayer::last_achiev_id = KillParams::KillInFourInSlide;
                }
            }
        }

        if (id == id_for_jump)
        {
            if (is_jump_player) {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::InJumpKill, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::InJumpKill, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 75;
                BonusPlayer::last_achiev_id = KillParams::InJumpKill;
            }
        }


        //if (SrazuKills::SrazuKilauras) {
        //    if (killCountInVector == 2) {
        //        SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInTwoSrazu, id, 1);
        //        SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInTwoSrazu, id, 0);
        //    }
        //    if (killCountInVector == 3) {
        //        SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInThreeSrazu, id, 1);
        //        SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInThreeSrazu, id, 0);
        //    }
        //    if (killCountInVector == 4) {
        //        SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInFourSrazu, id, 1);
        //        SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::KillInFourSrazu, id, 0);
        //    }
        //    SrazuKills::SrazuKilauras = 0;
        //}

        if (strstr(weaponName, "tw01"))
        {
            if (killCountInVector == 1) {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::Drovosek, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::Drovosek, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 100;
                BonusPlayer::last_achiev_id = KillParams::Drovosek;
            }
            if (killCountInVector == 2) {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::BloodyDrovosek, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::BloodyDrovosek, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 200;
                BonusPlayer::last_achiev_id = KillParams::BloodyDrovosek;
            }
            if (killCountInVector == 3) {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::RuthlessDrovosek, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::RuthlessDrovosek, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 300;
                BonusPlayer::last_achiev_id = KillParams::RuthlessDrovosek;
            }
        }



        if (material == 1) {
          //  printf("[TelemetryStream] mat_head kill\n");

            //for (const auto& p : player.playerRewards) 
            //{

            if (id == id_for_slide) {
                if (is_slide_player) {
                    SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::InSlideInHead, id, 1);
                    //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::InSlideInHead, id, 0);
                    BonusPlayer::ID = id;
                    BonusPlayer::bonus += 75;
                    BonusPlayer::last_achiev_id = KillParams::InSlideInHead;
                }
            }
            int currentCountMatHead = getKillCountMatHead(id);
            currentCountMatHead++;
            updateKillCountMatHead(id, currentCountMatHead);

            int currentCountMatHeadVector = currentCountMatHead;

            //printf("mat_head killed %i\n", currentCountMatHeadVector);


            if (currentCountMatHeadVector == 2)
            {
            //    printf("{Notification} %i\n", id);
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::HeadFuse, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::HeadFuse, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 100;
                BonusPlayer::last_achiev_id = KillParams::HeadFuse;
            }
            if (currentCountMatHeadVector == 3)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::SkullCrasher, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::SkullCrasher, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 200;
                BonusPlayer::last_achiev_id = KillParams::SkullCrasher;
            }
            if (currentCountMatHeadVector == 4)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::Braniac, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::Braniac, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 300;
                BonusPlayer::last_achiev_id = KillParams::Braniac;
            }
            if (currentCountMatHeadVector == 5)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::bouncer, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::bouncer, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 400;
                BonusPlayer::last_achiev_id = KillParams::bouncer;
            }
            //}



                //std::string url = createUrl(id, "mat_head", weaponName, "kill");
                //
                //HINTERNET hInternet3 = InternetOpen("HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
                //if (hInternet3 == NULL) {
                //    std::cerr << "InternetOpen failed" << std::endl;
                //}
                //
                //HINTERNET hConnect3 = InternetOpenUrl(hInternet3, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
                //if (hConnect3 == NULL) {
                //    printf("[CryOnline:Telemetry] failed to init request");
                //    //InternetCloseHandle(hInternet3);
                //    //return;
                //}
            LogKill(
                id,
                m_pShoterPlayer->GetEntity()->GetName(),
                death_player,
                pPlayer->GetEntity()->GetName(),
                "mat_head",
                pCvars->g_VictoryCondition(), weaponName, nItem->GetWeaponGeneral()->IsZooming(),
                GetStanceName(m_pShoterPlayer->m_state),
                GetStanceName(pPlayer->m_state),
                GetClassToChar(m_pShoterPlayer->GetCurrentClassId()),
                GetClassToChar(pPlayer->GetCurrentClassId()),
                damage,
                pGameFramework->GetLevelName(),
                is_slide_player ? "true" : "false",
                is_jump_player ? "true" : "false"

            );
            //InternetCloseHandle(hConnect3);
            //InternetCloseHandle(hInternet3);
        }

        else if (hit_type == 6) { // if 6 == melee (hittype is not mat_Head == 1)
        //    printf("[TelemetryStream] kill by melee!\n");

           

            int currentCountMelee = getKillCountMelee(id);
            currentCountMelee++;
            updateKillCountMelee(id, currentCountMelee);

            if (currentCountMelee == 2)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::butcher, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::butcher, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 100;
                BonusPlayer::last_achiev_id = KillParams::butcher;
            }
            if (currentCountMelee == 3)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::BloodyButcher, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::BloodyButcher, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 200;
                BonusPlayer::last_achiev_id = KillParams::BloodyButcher;
            }
            if (currentCountMelee == 5)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::MercilessButcher, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::MercilessButcher, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 300;
                BonusPlayer::last_achiev_id = KillParams::MercilessButcher;
            }
            if (currentCountMelee == 6)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::MeatGrinder, id, 1);
                if (iq == 0 && !isStart)
                    SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::MeatGrinder, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 400;
                BonusPlayer::last_achiev_id = KillParams::MeatGrinder;
            }
            if (currentCountMelee == 7)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::AdGrinder, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::AdGrinder, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 500;
                BonusPlayer::last_achiev_id = KillParams::AdGrinder;
            }


            //std::string url = createUrl(id, "melee", weaponName, "kill");
            //
            //HINTERNET hInternet1 = InternetOpen("HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
            //if (hInternet1 == NULL) {
            //    std::cerr << "InternetOpen failed" << std::endl;
            //}
            //
            //HINTERNET hConnect1 = InternetOpenUrl(hInternet1, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
            //if (hConnect1 == NULL) {
            //    printf("[CryOnline:Telemetry] failed to init request");
            //    //InternetCloseHandle(hInternet1);
            //    //return;
            //}
            LogKill(
                id,
                m_pShoterPlayer->GetEntity()->GetName(),
                death_player,
                pPlayer->GetEntity()->GetName(),
                "melee",
                pCvars->g_VictoryCondition(), weaponName, nItem->GetWeaponGeneral()->IsZooming(),
                GetStanceName(m_pShoterPlayer->m_state),
                GetStanceName(pPlayer->m_state),
                GetClassToChar(m_pShoterPlayer->GetCurrentClassId()),
                GetClassToChar(pPlayer->GetCurrentClassId()),
                damage,
                pGameFramework->GetLevelName(),
                is_slide_player ? "true" : "false",
                is_jump_player ? "true" : "false"

            );
            //InternetCloseHandle(hConnect1);
            //InternetCloseHandle(hInternet1);
        }



        else if (hit_type == pGameRules->GetHitTypeId("frag")) {
       //     printf("[TelemetryStream] kill by grenade!\n");

            //for (const auto& p : player.playerRewards)
            //{
            if (killCountInVector == 2)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::grenadier, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::grenadier, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 100;
                BonusPlayer::last_achiev_id = KillParams::grenadier;
            }
            if (killCountInVector == 3)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::MegaGrenadier, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::MegaGrenadier, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 200;
                BonusPlayer::last_achiev_id = KillParams::MegaGrenadier;
            }
            if (killCountInVector == 4)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::UltraGrenadier, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::UltraGrenadier, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 300;
                BonusPlayer::last_achiev_id = KillParams::UltraGrenadier;
            }
            //}


                //HINTERNET hInternet2 = InternetOpen("HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
                //if (hInternet2 == NULL) {
                //    std::cerr << "InternetOpen failed" << std::endl;
                //}
                //
                //std::string url = createUrl(id, "grenade", weaponName, "kill");
                //
                //HINTERNET hConnect2 = InternetOpenUrl(hInternet2, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
                //if (hConnect2 == NULL) {
                //    printf("[CryOnline:Telemetry] failed to init request");
                //    //InternetCloseHandle(hInternet2);
                //    //return;
                //}

            LogKill(
                id,
                m_pShoterPlayer->GetEntity()->GetName(),
                death_player,
                pPlayer->GetEntity()->GetName(),
                "grenade_kill",
                pCvars->g_VictoryCondition(), weaponName, nItem->GetWeaponGeneral()->IsZooming(),
                GetStanceName(m_pShoterPlayer->m_state),
                GetStanceName(pPlayer->m_state),
                GetClassToChar(m_pShoterPlayer->GetCurrentClassId()),
                GetClassToChar(pPlayer->GetCurrentClassId()),
                damage,
                pGameFramework->GetLevelName(),
                is_slide_player ? "true" : "false",
                is_jump_player ? "true" : "false"

            );


            //InternetCloseHandle(hConnect2);
            //InternetCloseHandle(hInternet2);
        }

        else if (slide_kill_by_player == 2) { //doesn't work
           // printf("[TelemetryStream] SlideKill!\n");
        }
        else {

            //std::string url = createUrl(id, "default", weaponName, "kill");
            //
            //HINTERNET hConnect5 = InternetOpenUrl(hInternet5, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
            //if (hConnect5 == NULL) {
            //    printf("[CryOnline:Telemetry] failed to init request");
            //    //InternetCloseHandle(hInternet2);
            //    //return;
            //}



            LogKill(
                id,
                m_pShoterPlayer->GetEntity()->GetName(),
                death_player,
                pPlayer->GetEntity()->GetName(),
                "default_kill",
                pCvars->g_VictoryCondition(), weaponName, nItem->GetWeaponGeneral()->IsZooming(),
                GetStanceName(m_pShoterPlayer->m_state),
                GetStanceName(pPlayer->m_state),
                GetClassToChar(m_pShoterPlayer->GetCurrentClassId()),
                GetClassToChar(pPlayer->GetCurrentClassId()),
                damage,
                pGameFramework->GetLevelName(),
                is_slide_player ? "true" : "false",
                is_jump_player ? "true" : "false"

            );

            if (killCountInVector == 2) {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::TwoKill, id, 1);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 100;
                BonusPlayer::last_achiev_id = KillParams::TwoKill;
            }
            if (killCountInVector == 3)
            {
                SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::ThreeKill, id, 1);
                //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::ThreeKill, id, 0);
                BonusPlayer::ID = id;
                BonusPlayer::bonus += 200;
                BonusPlayer::last_achiev_id = KillParams::ThreeKill;
            }

            if (id == id_for_slide) {

                if (is_slide_player) {
                    SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::InSlide, id, 1);
                    //SendTrackerNotify(0x1414B4F40)(pGameRules, KillParams::InSlide, id, 0);
                    BonusPlayer::ID = id;
                    BonusPlayer::bonus += 50;
                    BonusPlayer::last_achiev_id = KillParams::InSlide;
                }
            }



            //InternetCloseHandle(hConnect5);
            //InternetCloseHandle(hInternet5);
        }
    }
    //if (projectileId <= 0) {
    //    id_for_kick = id;
    //    is_kicked = 1;
    //}
  //  printf(u8"[TelemetryStream] Player: [%s] was death and her id: %i by killed %s and damage %i!\n", pPlayer->GetEntity()->GetName(), id, m_pShoterPlayer->GetEntity()->GetName(), damage);



    //InternetCloseHandle(hConnect4);
    //InternetCloseHandle(hInternet4);
    //taskThread.detach();

    using CGameRules_AwardPlayer = void(__thiscall*)(CGameRules* this1,
        const char* eventName,
        unsigned int entityId,
        int amount,
        int bonus,
        bool allowMultiplierChange);
    //CGameRules_AwardPlayer(0x1411E06F0)(pGameRules, "bonus_player", m_pShoterPlayer->GetEntity()->Id(), 0, BonusPlayer::bonus, 1);


}



struct HitRecord {
    int shooterId;       
    unsigned int entityId; 
    int health;     
    bool is_helper_player;

};

std::vector<HitRecord> hitHistory;



__int64 __fastcall GameRules_SendDamageIndicator(
    CScriptBind_GameRules* this1,
    void* pH,
    ScriptHandle targetId,
    ScriptHandle shooterId,
    bool silencer,
    Vec3_tpl<float>* direction,
    char* hitType)
{
    CGame* pGame = CGame::Signlenton(); if (!pGame) return 0;
    IGameFramework* pGameFramework = pGame->GetFramework_nonvtable();
    if (pGameFramework) 
    {

        IActorSystem* pActorSystem = pGameFramework->GetActorSystem();
        CPlayer* m_pShoterPlayer = pActorSystem->GetPlayer(shooterId.n);
        CPlayer* m_pTargetId = pActorSystem->GetPlayer(targetId.n);

        //printf(u8"shooterPlayer name: %s\n", m_pShoterPlayer->GetEntity()->GetName());
        //printf(u8"targetPlayer name: %s\n", m_pTargetId->GetEntity()->GetName());

        typedef int(__fastcall* CActor_GetProfileId)(CPlayer*);
        int id = CActor_GetProfileId((CActor_GetProfileId)0x141239700)(m_pShoterPlayer);

        if (id == BonusPlayer::ID_helper || BonusPlayer::ID_helper == 0) {

           


            if (!m_pTargetId->IsDead()) {
                BonusPlayer::ID_helper = id;
                BonusPlayer::health = m_pTargetId->Health();
                BonusPlayer::entityId = m_pShoterPlayer->GetEntity()->Id();
                BonusPlayer::is_helper_player = true;
            }
        }

    }


    return CGameRules_DamagePlayer(this1, pH, targetId, shooterId, silencer, direction, hitType);
}

void __fastcall CGameRules_KillPlayer(CGameRules* this1,
    CPlayer* pPlayer,
    unsigned int shooterId,
    int weaponGameObjectId,
    float damage,
    int material,
    unsigned int hit_type,
    const Vec3_tpl<float>* impulse,
    unsigned int projectileId,
    int targetsCoreTeam,
    int shootersCoreTeam,
    int vDir,
    bool bExplosion)
{

    char buffer[999999999];
    DWORD bytesRead;
  
    bool sendOriginalData = true;


//    printf("Send msg to server!\n");

    SCVars* pCvars = SCVars::Singlenton(); if (!pCvars) return;

    PlayerData player;

    SSystemGlobalEnvironment* pSSGE = SSystemGlobalEnvironment::Singleton();
    if (pSSGE) 
    {
        CGame* pGame = pSSGE->GetCGame(); if (pGame) {
            IGameFramework* pGameFramework = pGame->GetFramework_nonvtable();
            if (pGameFramework) {
                CGameRules* pGameRules = pGameFramework->GetCurrentGameRules(); if (!pGameRules) return;
                using SendTrackerNotify = void(__thiscall*)(CGameRules* this1, int instantAwardId, int profileId, bool bClientOnly);



                IActorSystem* pActorSystem = pGameFramework->GetActorSystem();
                CPlayer* m_pShoterPlayer = pActorSystem->GetPlayer(shooterId);
                if (pActorSystem) {
                    if (m_pShoterPlayer) {

                        typedef int(__fastcall* CActor_GetProfileId)(CPlayer*);
                        int death_player = CActor_GetProfileId((CActor_GetProfileId)0x141239700)(pPlayer);

                        auto nItem = m_pShoterPlayer->GetCurrentItem();
                        if (nItem) {

                            typedef int(__fastcall* CActor_GetProfileId)(CPlayer*);
                            int id = CActor_GetProfileId((CActor_GetProfileId)0x141239700)(m_pShoterPlayer);

                            CWeaponGeneral* pGeneral = nItem->GetWeaponGeneral(); if (!pGeneral) return;
                            CWeaponParameters* pParameters = pGeneral->GetWeaponParams(); if (!pParameters) return;
                            const char* weaponName = nItem->GetEntity()->GetName();

                            Vec3 shootPos = m_pShoterPlayer->GetEntity()->GetWorldTM().GetTranslation();
                            Vec3 deathPlayerShoot = pPlayer->GetEntity()->GetWorldTM().GetTranslation();

                            //if (!pCvars->g_VictoryCondition() != 3) {
                            //    if (!AiIsVisible(shootPos, deathPlayerShoot))
                            //    {
                            //        id_for_kick = id;
                            //        is_kicked = 1;
                            //
                            //    }
                            //}




                            if (strstr(weaponName, "fg") && hit_type != 7) {
                                id_for_kick = id;
                                is_kicked = 1;
                            }
                            if (strstr(weaponName, "arl0") && hit_type == 1) {
                                id_for_kick = id;
                                is_kicked = 1;
                            }

                            if (strstr(pPlayer->GetEntity()->GetName(), "Artillery") && !strstr(weaponName, "arl0")) {
                              
                                id_for_kick = id;
                                is_kicked = 1;
                            }

                        }

                        if (sendOriginalData) {

                            if (pCvars->g_VictoryCondition() == 6)
                            {
                                Reward_Player(this1, pGameFramework, hit_type, damage, death_player, material, m_pShoterPlayer, pPlayer);
                            }
                            else if (pCvars->g_VictoryCondition() == 12) {
                                Reward_Player(this1, pGameFramework, hit_type, damage, death_player, material, m_pShoterPlayer, pPlayer);
                            }
                            else {
                                if (m_pShoterPlayer->GetTeamId() != pPlayer->GetTeamId()) {
                                    Reward_Player(this1, pGameFramework, hit_type, damage, death_player, material, m_pShoterPlayer, pPlayer);
                                }
                            }
                        }
                    }
                }
            }

        }
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        startTimeInOld = std::chrono::steady_clock::now();
        //countKills = 0;
    }
    if (sendOriginalData)
        CGameRules_KillPlayer_p(this1, pPlayer, shooterId, weaponGameObjectId, damage, material, hit_type, impulse, projectileId, targetsCoreTeam, shootersCoreTeam, vDir, bExplosion);
}
  


void __fastcall Game_CAttachment_OnAttach(
    Game_CAttachment* this1,
    CWeaponGeneral* pWeapon,
    const char* pSocket,
    const char* pParent)
{
    typedef void(__fastcall* AddAttachment)(CWeaponView* this1,
        const char* name,
        const CViewSettings* vs,
        const QuatT_tpl<float>* pos,
        const char* joint,
        const char* parentAtt,
        IMaterial* pFPMaterial,
        IMaterial* pTPMateriall, 
        void* unk2, 
        void* unk1);
    CWeaponView* m_pWeaponView = this1->m_pWeapon->GetWeaponView(); if (!m_pWeaponView) return;
    const char* name = "sr46";
    CAttachementSettings* m_pSettings = this1->GetAttachSettings(); if (!m_pSettings) return;
    CViewSettings* m_pViewSettings = m_pSettings->m_pSettings; if (!m_pWeaponView) return;
    const char* joint = "Bip01 Head";
    const char* pPar = pParent;





    QuatT_tpl<float> pos;
    pos.q.v.z = 0;
    pos.t.z = 0.0;


    AddAttachment((AddAttachment)0x141639190)(m_pWeaponView, name, m_pViewSettings, &pos, joint, pPar, 0, 0, 0, 0);


    Game_CAttachment_OnAttach_p(this1, pWeapon, pSocket, pParent);
}




void __fastcall CGameRules_AwardPlayer(
    CGameRules* this1,
    const char* eventName,
    unsigned int entityId,
    int amount,
    int bonus,
    bool allowMultiplierChange)
{

    //printf("event name %s\n", eventName);

    PlayerData player;

    SSystemGlobalEnvironment* pSSGE = SSystemGlobalEnvironment::Singleton();
    if (pSSGE) {
        CGame* pGame = pSSGE->GetCGame(); if (pGame) {
            IGameFramework* pGameFramework = pGame->GetFramework_nonvtable();
            if (pGameFramework) {
                IActorSystem* pActorSystem = pGameFramework->GetActorSystem();
                CPlayer* m_pAvardPlayer = pActorSystem->GetPlayer(entityId);

                typedef int(__fastcall* CActor_GetProfileId)(CPlayer*);
                int id = CActor_GetProfileId((CActor_GetProfileId)0x141239700)(m_pAvardPlayer);

                //int bonus;


                /*if (BonusPlayer::is_helper_player) {

                    int helperId = BonusPlayer::ID_helper;
                    int healthTarget = BonusPlayer::health;

                    double healthPercent = ((double)healthTarget / 125) * 100;
                    
                    if (healthPercent > 0 && healthPercent <= 20) {
                        bonus = 10;
                    }
                    else if (healthPercent > 20 && healthPercent <= 40) {
                        bonus = 30;
                    }
                    else if (healthPercent > 40 && healthPercent <= 60) {
                        bonus = 50;
                    }
                    else if (healthPercent > 60 && healthPercent <= 80) {
                        bonus = 70;
                    }
                    else if (healthPercent > 80 && healthPercent < 100) {
                        bonus = 90;
                    }
                    else {
                        bonus = 0;
                    }
                    printf("bonus of the help assist %i\n", bonus);
                }*/

                if (BonusPlayer::bonus > 0)
                {
                    //printf("bonusAward! bonus '%i'\n", bonus);
                    CGameRules_AwardPlayer_p(this1, eventName, entityId, amount, BonusPlayer::bonus, allowMultiplierChange);
                    BonusPlayer::bonus = 0;
                    return;
                }
                

                


               // printf("bonus %i\n", bonus);
               // printf("amount %i\n", amount);

                /*if (strstr(eventName, "sm_coop_climb") == 0)
                {
                    if (killCountInVector == 2)
                    {
                        SendTrackerNotify(0x1414B4F40)(this1, KillParams::AssistCSM, id, 1);
                        SendTrackerNotify(0x1414B4F40)(this1, KillParams::AssistCSM, id, 0);
                    }
                }*/

                //HINTERNET hInternet = InternetOpen("HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
                //if (hInternet == NULL) {
                //    std::cerr << "InternetOpen failed" << std::endl;
                //}

               // printf("[TelemetryDebugView] eventName: %s and player with entity id: %s\n", eventName, m_pAvardPlayer->GetEntity()->GetName());
                //std::string url = createUrl(id, "score_id_null", "award_player_weapon_isnull", eventName);

                SCVars* pCVars = SCVars::Singlenton();
                if (!pCVars) return;


                if (!strstr(eventName, "kill")) {
                
                    if (strstr(eventName, "dogtags")) {
                
                        SendTrackerNotify(0x1414B4F40)(this1, 38, id, 1);
                        SendTrackerNotify(0x1414B4F40)(this1, 38, id, 0);
                    }
                
                    LogKill(
                        id,
                        m_pAvardPlayer->GetEntity()->GetName(),
                        0,
                        "",
                        eventName,
                        pCVars->g_VictoryCondition(), "", false,
                        GetStanceName(m_pAvardPlayer->m_state),
                        GetStanceName(m_pAvardPlayer->m_state),
                        GetClassToChar(m_pAvardPlayer->GetCurrentClassId()),
                        GetClassToChar(m_pAvardPlayer->GetCurrentClassId()),
                        0.0f,
                        pGameFramework->GetLevelName(),
                        is_slide_player ? "true" : "false",
                        is_jump_player ? "true" : "false"

                    );
                }







                //HINTERNET hConnect = InternetOpenUrl(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
                //InternetCloseHandle(hConnect);
                //InternetCloseHandle(hInternet);
                

            }
        }
    }

    CGameRules_AwardPlayer_p(this1, eventName, entityId, amount, bonus, allowMultiplierChange);
}


#include <cstdint>



CBackend* CBackendVoid(CBackend* this1, IGameFramework* fw) {
    __int64 v2 = CryOnlineGetInstance();
    if (v2) {
        (*(void(__fastcall**)(__int64, __int64, const char*))(*(DWORD64*)v2 + 88i64))(v2, this1->IOnlineQueryBinder(), "getprofile");
    }
    return CBackend_CBackend(this1, fw);;
}

void __fastcall CInstantAwardSystem_CInstantAwardSystem(CInstantAwardSystem* this1) {
	//SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::Singleton();
    //CGame* m_pGame = gEnv->GetCGame();
    //if (!m_pGame) { PrintToConsole("m_pGame not initialization\n", GREEN); return; }
    
    CInstantAwardTracker* InstantTracker = (CInstantAwardTracker*)operator_new(0x2000);
    this1->m_pTracker = InstantTracker;
    //
	//PrintToConsole("m_pTracker initialization\n", GREEN);
    CInstantAwardSystem_p(this1);
}

#endif


typedef uint8_t(__fastcall* sub_140DC22E0_t)();
typedef uint8_t(__fastcall* sub_140DBDB10_t)(__int64, uint32_t, uint64_t, uint64_t);
typedef void(__fastcall* sub_140DC31D0_t)(__int64, __int64, uint64_t);
typedef void(__fastcall* sub_140DC32E0_t)(__int64);
typedef uint8_t(__fastcall* sub_140DC2540_t)(__int64);

sub_140DC22E0_t sub_140DC22E0 = (sub_140DC22E0_t)0x140DC22E0;
sub_140DBDB10_t sub_140DBDB10 = (sub_140DBDB10_t)0x140DBDB10;
sub_140DC31D0_t sub_140DC31D0 = (sub_140DC31D0_t)0x140DC31D0;
sub_140DC32E0_t sub_140DC32E0 = (sub_140DC32E0_t)0x140DC32E0;
sub_140DC2540_t sub_140DC2540 = (sub_140DC2540_t)0x140DC2540;

char __fastcall sub_140DC2170(__int64 a1) {
    uint16_t v2;
    int16_t v3;
    int16_t v4;
    uint32_t v5;
    uint32_t v6;
    uint32_t v7;

    sub_140DC22E0();

    v2 = *reinterpret_cast<uint16_t*>(a1 + 68);
    v3 = v2 >> 15;
    v4 = v2 & 0x7FFF;
    *reinterpret_cast<uint8_t*>(a1 + 179) = static_cast<uint8_t>(v3);
    *reinterpret_cast<uint16_t*>(a1 + 68) = v4;

    if (*reinterpret_cast<uint16_t*>(a1 + 70))
        return 0;
    if (*reinterpret_cast<uint16_t*>(a1 + 72) != *reinterpret_cast<uint16_t*>(a1 + 74))
        return 0;
    v5 = *reinterpret_cast<uint32_t*>(a1 + 80); 
    v6 = *reinterpret_cast<uint32_t*>(a1 + 104);
    if (v5 > v6)
        return 0;
    v7 = *reinterpret_cast<uint32_t*>(a1 + 76);
    if (v7 > v6 || v7 + v5 > v6)
        return 0;

    sub_140DBDB10(a1 + 16, v7 + v5 + 22, 0, 0);
    if (*reinterpret_cast<uint16_t*>(a1 + 84) >= 8) {
        sub_140DC31D0(a1, a1 + 2548, 8);
        if (*reinterpret_cast<uint32_t*>(a1 + 2548) != 8)
            return 0;
        *reinterpret_cast<uint32_t*>(a1 + 188) = *reinterpret_cast<uint32_t*>(a1 + 2552);
        if (*reinterpret_cast<uint16_t*>(a1 + 84) >= 0x93C) {
            sub_140DC31D0(a1, a1 + 192, 2356);
            if (*reinterpret_cast<uint32_t*>(a1 + 192) != 2356)
                return 0;
            sub_140DC32E0(a1);
        }
    }

    if (sub_140DC2540(a1))
        return 1;

    return 0;
}

bool __cdecl ZipDir__CacheFactory__ReadHeaderData(void* this1, void* pDest, unsigned int nSize)
{
    bool ret = false;
    if (*(bool*)((DWORD64)this1 + 0xB3)) ret = mZipDir__CacheFactory__ReadHeaderData(this1, pDest, nSize);
    else
    {
        typedef __int64(__cdecl* ZipDir__FRead)(void* file, void* data, unsigned __int64 elementSize, unsigned __int64 count, void* pInternalFile);
        ret = ZipDir__FRead(0x140DBDBB0)(&*(void**)((DWORD64)this1 + 0x10), pDest, nSize, 1u, NULL) == 1;
    }

    return ret;
}




typedef void(__fastcall* SendMessageFromServer_0)(CActor*, SM_Network__SCoopAssistMessage*);
typedef void(__fastcall* nCSM_CoopAssist__Finish)(void*);
nCSM_CoopAssist__Finish mCSM_CoopAssist__Finish = (nCSM_CoopAssist__Finish)0x1416CCE80;

enum ECoopAssistState : __int32
{
    eCAS_EnteringAssistPose = 0x0,
    eCAS_Waiting = 0x1,
    eCAS_Assisting = 0x2,
};

void __cdecl CSM_CoopAssist__Finish(void* this1)
{
    mCSM_CoopAssist__Finish(this1);

    SM_Network__SCoopAssistMessage pSM_Network__SCoopAssistMessage;
    RtlSecureZeroMemory(&pSM_Network__SCoopAssistMessage, sizeof(SM_Network__SCoopAssistMessage));
    pSM_Network__SCoopAssistMessage.ptr = (void*)0;
    pSM_Network__SCoopAssistMessage.type = 8;
    pSM_Network__SCoopAssistMessage.msgType = 1;
    pSM_Network__SCoopAssistMessage.opcode = -1;
    pSM_Network__SCoopAssistMessage.instant = 0;
    pSM_Network__SCoopAssistMessage.animIndex = -1;

   
    if (*(ECoopAssistState*)((DWORD64)this1 + 0xB0) != eCAS_Assisting)
    {
        CActor* m_pPlayer = *(CActor**)((DWORD64)this1 + 16);
        if (m_pPlayer)
            SendMessageFromServer_0((SendMessageFromServer_0)0x1416CFD50)(m_pPlayer, &pSM_Network__SCoopAssistMessage);
    }
    else {
        CActor* m_pPlayer = *(CActor**)((DWORD64)this1 + 16);
        if (m_pPlayer)
        {
            Vec3 endPoint;
            typedef Vec3* (__fastcall* CPiecewiseTrajectory__GetEndPoint)(void*, Vec3*);
            CPiecewiseTrajectory__GetEndPoint((CPiecewiseTrajectory__GetEndPoint)0x1416B6540)((void*)((DWORD64)this1 + 0x38), &endPoint);

            m_pPlayer->GetEntity()->SetPos(endPoint);

            pSM_Network__SCoopAssistMessage.helperClosestPoint = endPoint;
            //pSM_Network__SCoopAssistMessage.serverTime = SSystemGlobalEnvironment::Singleton()->pCTimer()->GetFrameStartTime(0)->m_lValue;

            SendMessageFromServer_0((SendMessageFromServer_0)0x1416CFD50)(m_pPlayer, &pSM_Network__SCoopAssistMessage);
        }
    }

}

typedef void(__fastcall* nCSM_CoopClimb__Finish)(void*);
nCSM_CoopClimb__Finish mCSM_CoopClimb__Finish = (nCSM_CoopClimb__Finish)0x1416C7BC0;



typedef void(__fastcall* SendMessageFromServer_01)(CActor*, SM_Network__SCoopClimbMessage*);



struct SKnockBackMessage : SM_Network__SMessage {

    Quat_tpl<float> animStartLocalRot;
    Vec3_tpl<float> startPos;
    void* standingOn;
}; //Size=0x0040






struct CPlayer_MethodInfo_ClHoldEntityMessage {

};

struct MethodInfo_SvHoldEntityMessage {
public:

};
struct SHoldEntityMessage {

};


typedef void(__fastcall* SendMessageFromServer_Knockback)(CActor*, SKnockBackMessage*);
typedef void(__fastcall* SendMessageFromServer_Knockback_0)(CPlayer*, SKnockBackMessage*);
typedef void(__fastcall* SendMessageFromServer_Knockback_3)(CActor*, SKnockBackMessage*);

void __fastcall CSM_CoopClimb__Finish(void* this1)
{
    mCSM_CoopClimb__Finish(this1);



    

    CActor* m_pPlayer = *(CActor**)((DWORD64)this1 + 16);

    Vec3 myLastPosition = m_pPlayer->GetEntity()->GetWorldTM().GetTranslation();

    //printf(u8"%s\n", m_pPlayer->GetEntity()->GetName());                                             

    CGame* pGame = CGame::Signlenton(); 
    if (pGame) {
        IGameFramework* pFramework = pGame->GetFramework_nonvtable();
        CGameRules* pGameRules = pFramework->GetCurrentGameRules();

       // m_pPlayer->SetHealth();

                    //Vec3 v = { 50,50,50 };
                    //
                    //typedef void(__cdecl* CPlayer__ResetSM)(CGameRules* this1,
                    //    CActor* pPlayer,
                    //    unsigned int shooterId,
                    //    int weaponGameObjectId,
                    //    float damage,
                    //    int material,
                    //    unsigned int hit_type,
                    //    const Vec3_tpl<float>* impulse,
                    //    unsigned int projectileId,
                    //    int targetsCoreTeam,
                    //    int shootersCoreTeam,
                    //    Vec3 normal,
                    //    bool bExplosion); //m_pPlayer, m_pPlayer->Id(), -1, 130, 1, pGameRules->GetHitTypeId("invalid_position_kill"), Vec3(0, 0, 0), true
                    //CPlayer__ResetSM((CPlayer__ResetSM)0x1411E2840)(pGameRules, m_pPlayer, m_pPlayer->Id(), -1, 999, 1, pGameRules->GetHitTypeId("invalid_position_kill"), &v, rand(), 0, 0, Vec3(0, 0, 0), 0);
                    //
                    ////printf("%i\n", pGameRules->GetHitTypeId("healing"));
                    //
                    //
                    //typedef void(__cdecl* CGameRules_RevivePlayer)(CGameRules* this1, int entityId);
                    //
                    //CGameRules_RevivePlayer((CGameRules_RevivePlayer)0x1411F0DC0)(pGameRules, m_pPlayer->Id());
                    //typedef void(__cdecl* CPlayer_SetHealth)(CActor* this1, int health);
                    //CPlayer_SetHealth((CPlayer_SetHealth)0x141235910)(m_pPlayer, m_pPlayer->Health() - 5);
                    //
                    //m_pPlayer->SetHealth(m_pPlayer->Health() - 5);
                    //
                    //int myoriginalHealth = m_pPlayer->Health() + 5;
                    //
                    //// CPlayer_SetHealth((CPlayer_SetHealth)0x141235910)(m_pPlayer, myoriginalHealth);
                    //
                    //typedef void(__cdecl* CPlayer_SetHealth)(CActor* this1, int health);
                    //CPlayer_SetHealth((CPlayer_SetHealth)0x141235910)(m_pPlayer, myoriginalHealth);
       

    }
    IHumanPlayer* m_pHumanPlayer = m_pPlayer->GetHumanPlayer();



       

       // typedef void(__thiscall* CPlayer__StopComa)(CActor* pPlayer,bool isnew);
       //CPlayer__StopComa((CPlayer__StopComa)0x141231170)(m_pPlayer, 0);
   
        Vec3 v;

        //typedef void(__cdecl* CPlayer_GetSpawnAnimationEnd)(CActor* this1, Vec3_tpl<float>* result);
        //CPlayer_GetSpawnAnimationEnd((CPlayer_GetSpawnAnimationEnd)0x141242680)(m_pPlayer, &v);
       // m_pPlayer->m_pGameObjcet->ChangedNetworkState(128u);
     //141523550
       // Vec3 slideDir = Vec3(ZERO);
       // typedef void(__cdecl* CPlayer__SetSlide)(CActor*, bool, Vec3);
       // CPlayer__SetSlide((CPlayer__SetSlide)0x1412272C0)(m_pPlayer, 0, slideDir);
       // *(BYTE*)((DWORD64)m_pPlayer + 3695) = 0;

        SKnockBackMessage msg;
        memset(&msg, 0, sizeof(SKnockBackMessage));
        {
            msg.type = 3;
            msg.msgType = 0;
            msg.startPos = myLastPosition;
        }
        //1416C0D60
        SendMessageFromServer_Knockback((SendMessageFromServer_Knockback)0x1416C0D60)(m_pPlayer, &msg);

        SKnockBackMessage msg1;
        memset(&msg1, 0, sizeof(SKnockBackMessage));
        {
            msg1.type = 3;
            msg1.msgType = 1;
            msg1.startPos = myLastPosition;
        }
        SendMessageFromServer_Knockback((SendMessageFromServer_Knockback)0x1416C0D60)(m_pPlayer, &msg1);

    //m_pPlayer->GetEntity()->SetPos(myLastPosition);

    


        //SendMessageFromServer_0Player((SendMessageFromServer_0Player)0x1416C0EA0)(m_pPlayer, &pSM_Network__SCoopAssistMessage, 2);

}



typedef void(__fastcall* MovementCoreMoveClass)(CPlayer* player, MovementCore_SMovementCmd* cmd,MovementCore_SPlayerMovementState* in_state, MovementCore_SPlayerMovementState* out_state);
MovementCoreMoveClass MovementCore_Move_p = (MovementCoreMoveClass)0x1415E82A0;

struct CServerMovementProcessor
{
    unsigned __int64 m_cachedProfileId;
    int m_commandsThatCanBeExecuted;
    float m_stepTimer;
    float m_needStepTimer;
    float m_timeSinceLastCommand;
    void* m_commands;
    MovementCore_SMovementCmd m_lastAppliedCmd;
    unsigned int m_lastReceivedCmd;
    void* m_lastAckedState;
    CPlayer* m_player;
    void* m_latencies;
    unsigned int m_skipSlideCommands;
    void* m_stateHistory;
    void* m_lock;
};

void __fastcall CIngameShop_BuyOffer(CIngameShop* this1, SIngameShopOffer const* offer,EntityId entityId)
{
    typedef bool(__cdecl* OnBuyOffer)(CIngameShop* this1, EntityId entityId, const char* offerName);
    
    //if (this1->m_isInSync) {
    //    printf("[CIngameShop]: BuyOffer - previous call is in progress, ignore\n");
    //}
    //else {
    //    this1->m_isInSync = 1;
    //    if (entityId) {
    //        
    //        return OnBuyOffer((OnBuyOffer)0x14125A540)(this1, entityId, offer->name.m_str);
    //        //sub_14125A540(a1, v3, *(a2 + 8));
    //    }
    //    //14125C470
    //
    //    typedef EntityId(__cdecl* PickTeamRepresentative)();
    //    EntityId v3 = PickTeamRepresentative((PickTeamRepresentative)0x14125C470)();
    //    if (v3) {
    //        return OnBuyOffer((OnBuyOffer)0x14125A540)(this1, entityId, offer->name.m_str);
    //    }
    //    printf("[CIngameShop::BuyOffer] Failed picking representative for players team!\n");
    //
    //}

    OnBuyOffer((OnBuyOffer)0x14125A540)(this1, entityId, offer->name.m_str);
    
    ShopBuyOffer_p(this1, offer, entityId);
}


void __fastcall MovementCore_Move(CPlayer* player, MovementCore_SMovementCmd* cmd,MovementCore_SPlayerMovementState* in_state, MovementCore_SPlayerMovementState* out_state)
{

    MovementCore_Move_p(player, cmd, in_state, out_state);

    BYTE newState_inSlide = *(BYTE*)(out_state + 58);//newState->inSlide
    BYTE newState_inJump = *(BYTE*)(out_state + 0x3B);

    typedef int(__fastcall* CActor_GetProfileId)(CPlayer*);
    int id = CActor_GetProfileId((CActor_GetProfileId)0x141239700)(player);

    if (*(BYTE*)(in_state + 58))//oldState->inSlide
    {
        if (!newState_inSlide)
        {
            //Vec3 slideDir = Vec3(ZERO);
            //typedef void(__cdecl* CPlayer__SetSlide)(CActor*, bool, Vec3);
            //CPlayer__SetSlide((CPlayer__SetSlide)0x1412272C0)(player, 0, slideDir);
            //*(BYTE*)((DWORD64)player + 3695) = 0;

            

            id_for_slide = id;

            is_slide_player = 0;
            
        }
    }
    else if (newState_inSlide)
    {
        id_for_slide = id;
        is_slide_player = 1;

        

        //printf("in_slide!\n");
        //Vec3 slideDir = *(Vec3*)(in_state + 0x28);
        //typedef void(__cdecl* CPlayer__SetSlide)(CActor*, bool, Vec3);
        //CPlayer__SetSlide((CPlayer__SetSlide)0x1412272C0)(player, 1, slideDir);
        //*(BYTE*)((DWORD64)player + 3695) = 1;
        //
        //Quat rotate;
        //rotate.SetRotationVDir(slideDir);
        //player->GetEntity()->SetRotation(&rotate, 0);
    }

    if (*(BYTE*)(in_state + 0x3B)) //in_jump_player!
    {
        if (!newState_inJump) {
            id_for_jump = id;
            is_jump_player = 0;
            
        }
    }
    else if (newState_inJump) {
        id_for_jump = id;
        is_jump_player = 1;
       
    }

}

enum ERequestSendType
{
    eRST_Regular = 0x0,
    eRST_Immediate = 0x1,
};

SSessionRewardsInfo* new_m_pSessionRewardsInfo = nullptr;
typedef void(__cdecl* SendSSessionRewardsInfo)(void*, SSessionRewardsInfo*, ERequestSendType);


void __fastcall GameRules_ReportGameEnd(CGameRulesEnd* this1, EGameEndReason gameEndReason, int winningTeamId, SSessionRewardsInfo* m_pSessionRewardsInfo) {
    new_m_pSessionRewardsInfo = m_pSessionRewardsInfo;
    CScoringConfig* Myptr = this1->m_pScoringConfig; 
    if (Myptr) 
    {
        CScoringConfig::GetSessionRewardsInfo(Myptr, gameEndReason, winningTeamId, m_pSessionRewardsInfo);
        SendSSessionRewardsInfo((SendSSessionRewardsInfo)0x1414A0EA0)(&Myptr->m_setRewardsInfoBinder, new_m_pSessionRewardsInfo, ERequestSendType::eRST_Regular);
    }
    CGameRules_ReportGameEnd_p(this1, gameEndReason, winningTeamId, m_pSessionRewardsInfo);
}

void __fastcall SetRewardsInfoSerializer_OnRequest(void* SSetRewardsInfoSerializer, XmlNodeRef* request, SSessionRewardsInfo* rewardsInfo) {
    rewardsInfo = new_m_pSessionRewardsInfo;
   // printf("======================== SetRewardsInfoSerializer_OnRequest ===============================\n");
   // printf("winningTeamId: %i\n", rewardsInfo->winningTeamId);
   // printf("missionId: %s\n", rewardsInfo->missionId.m_str);
   // printf("=======================================================\n");
    SSetRewardsInfoSerializer_OnRequest_p(SSetRewardsInfoSerializer, request, rewardsInfo);
}

const char* GetQueryReceiverId(void* a1) {
    return "masterserver@warface/main_pve_001";
}


void __fastcall CAchievementsTracker_SaveAchievements(CAchievementsTracker* this1) //sub_141501E20
{
    std::vector<CAchievementBackend::SProfileAchievements> achievements; // [rsp+50h] [rbp-30h] BYREF
    
    CAchievementBackend* Backend;
    
    if (!achievements.empty()) 
    {
        CGame_V2* pGame = CGame_V2::Signlenton();
        if (pGame) {
            // Backend = CAchievementSystem::GetBackend(g_pGame->m_pAchievementSystem._Myptr);
            typedef CAchievementBackend*(__cdecl* nGetBackend)(CAchievementSystem* this1);
            Backend = nGetBackend((nGetBackend)0x1413A6280)(pGame->m_pAchievementSystem());
    
    
            //141A34060
            typedef void(__cdecl* CAchievementBackend_UpdateAchievements)(CAchievementBackend* this1, std::vector<CAchievementBackend::SProfileAchievements>* achievements);
            CAchievementBackend_UpdateAchievements((CAchievementBackend_UpdateAchievements)0x141A34060)(Backend, &achievements);
    
        }
    
    }

    CAchievementsTracker_SaveAchievements_p(this1);
}

void __fastcall CSM_Vault_Finish(CSM_Vault* this1)
{
    CSM_VaultFinsih_p(this1);
}

static int callCount = 0;

void __fastcall SM_NetworkSMessage_SerializeWith(CPlayer* this1,
    SM_Network_SVaultMessage* params)
{
    callCount++;

    typedef int(__fastcall* CActor_GetProfileId)(CPlayer*);
    int id = CActor_GetProfileId((CActor_GetProfileId)0x141239700)(this1);


    SM_NetworkSMessage_SerializeWith_p(this1, params);

    if (callCount % 480 == 0) 
    {
        if (params->helperClosestPoint.x <= 0)
        {
            id_for_kick = id;
            is_kicked = 1;
        }
    }

    //printf("{x: %d, y: %d, z: %d animFinished: %i, animIndex %i animStartPose (x): %d}\n", params->helperClosestPoint.x, params->helperClosestPoint.y, params->helperClosestPoint.z, params->animFinished, params->animIndex, params->animStartPose.t.x);

}




bool __fastcall CActor_NetSerialize(
    CActor* this1,
    serializer ser,
    EEntityAspects aspect,
    unsigned __int8 profile,
    int pflags)
{
    /*
     CActorInventory::SerializeForcedWeapon(this->m_actorInventory._Myptr, &sera);
     CActorInventory::SerializeInventorySlots(this->m_actorInventory._Myptr, &sera);
     CActorInventory::SerializeAttachments(this->m_actorInventory._Myptr, &sera);
     CActorInventory::SerializeCharge(this->m_actorInventory._Myptr, &sera);
    вызвать!!!!
    
    

    */

    sizeof(SPlayerParams*);

    using SerializeForcedWeapon = void(__thiscall*)(CActorInventory* this1, serializer* ser);
    using SerializeInventorySlots = void(__thiscall*)(CActorInventory* this1, serializer* ser);
    using SerializeAttachments = void(__thiscall*)(CActorInventory* this1, serializer* ser);
    using SerializeCharge = void(__thiscall*)(CActorInventory* this1, serializer* ser);

    //SerializeForcedWeapon(0x141487150)(this1->GetActorInventory(), &ser);
    //SerializeInventorySlots(0x1414871C0)(this1->GetActorInventory(), &ser);
    //SerializeCharge(0x141487410)(this1->GetActorInventory(), &ser);
    //SerializeAttachments(0x141487270)(this1->GetActorInventory(), &ser);


    return CActor_NetSerialize_p(this1, ser, aspect, profile, pflags);
}






__int64 __fastcall Teleport_Shield(__int64 a1, unsigned __int16 a2, SPathFindParams* params)
{
    SSystemGlobalEnvironment* pSSGE = SSystemGlobalEnvironment::Singleton(); if (!pSSGE) return 1;
    IEntitySystem* pEntitiesSystem = pSSGE->GetEntitySystem(); if (!pEntitiesSystem) return 1;
    IEntityIterator* pEntityIterator = pEntitiesSystem->GetEntityIt(); if (!pEntityIterator) return 1;

    IGameFramework* pGameFramework = IGameFramework::Singlenton(); if (!pGameFramework) return 1;

    SKnockBackMessage msg;

    while (IEntity* pEntity = pEntityIterator->Next()) {
        if (CPlayer* pActor = pGameFramework->GetActorSystem()->GetPlayer(pEntity->Id()))
        {
            printf("%s\n", params->m_pEntity->Name());


            memset(&msg, 0, sizeof(SKnockBackMessage));
            {
                msg.type = 1;
                msg.msgType = 0;
                msg.opcode = 0;
                msg.startPos = pActor->GetEntity()->GetWorldTM().GetTranslation();
            }
            SendMessageFromServer_Knockback_0((SendMessageFromServer_Knockback_0)0x1416BB620)(pActor, &msg);
            SKnockBackMessage msg1;
            memset(&msg1, 0, sizeof(SKnockBackMessage));
            {
                msg1.type = 1;
                msg1.msgType = 1;
                msg1.opcode = 0;
                msg1.startPos = pActor->GetEntity()->GetWorldTM().GetTranslation();
            }
            SendMessageFromServer_Knockback_0((SendMessageFromServer_Knockback_0)0x1416BB620)(pActor, &msg1);
        }
    }


  
    //1416C0D60
    return TeleportShield_p(a1, a2, params);
}



int q = 0;

void __fastcall CSMInteraction__Finish(CSM_InteractionAction* this1, __int64 a2, bool a3) { // CSM_HoldEntity_Finish
    SSystemGlobalEnvironment* pSSGE = SSystemGlobalEnvironment::Singleton(); if (!pSSGE) return;
    IEntitySystem* pEntitiesSystem = pSSGE->GetEntitySystem(); if (!pEntitiesSystem) return;
    IEntityIterator* pEntityIterator = pEntitiesSystem->GetEntityIt(); if (!pEntityIterator) return;
    printf("CSMInteraction__Finish\n");
     // [esp+18h] [ebp-34h] BYREF

    CryStringT<char>::StrHeader hdr;
    hdr.nRefCount = -1;
    hdr.nLength = 0;

    SInteractionActionMessage msg;


    printf("state is: %i\n", this1->m_pPlayer->GetMovementSMState().holdEntity);

    memset(&msg, 0, sizeof(SInteractionActionMessage));
    {
        msg.type = 0xA;
        msg.msgType = 1;
        msg.instant = 0;
        msg.opcode = -1;
        msg.itemName = { 0, &hdr };
        msg.entityId = this1->m_pPlayer->GetMovementSMState().holdEntity;
        msg.serverTime = SSystemGlobalEnvironment::Singleton()->GetTimer()->GetFrameTimer();
    }
    CActor* pActor = this1->m_pPlayer; if (!pActor) return;
    IGameObject* m_pObject = pActor->m_pGameObjcet;

    auto method = m_pObject->CreateClimb(&msg);

    if (method) {
        ::_InterlockedIncrement((volatile unsigned __int32*)((__int64)method + 0x38));
        m_pObject->DoInvokeRMI(&method, 65544, -1); // 65544
    }

 //   CSM_InteractionAction_p(this1, a2, a3);
}

void __fastcall SADSDFSDFSDFSDF31QQ(__int64 a1)
{
    return;
}


