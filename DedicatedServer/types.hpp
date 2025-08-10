#include "structures.hpp"


namespace Offsets {

    namespace Global {
        const int SSystemGlobalEnvironment = 0x142293718;
        const int Cvars = 0x142511DC0;
        const int IConsoleRegister = 0x141EE0E60;
        const int CGameRegister = 0x14249D570;
    }
    namespace MinHookesAddresses {
        const int CPlayerInputSerializer_OnTeleportPlayer_p = 0x14120E940;
        const int CAbstractServerInfo_CAbstractServerInfo = 0x1415131E0;
        const int CryOnlineGetInstance = 0x141E61D00;
        const int CMissionBackend_CMissionBackend = 0x141416040;
        const int CBackend_CBackend = 0x1413274B0;
        const int CStreamEngine_CStreamEngine = 0x140D2BEA0;
        const int CRandomItemDropSystem_p = 0x1413BFE10;
        const int CGame_Init = 0x1411C0CC0;
        const int CActor_SetPhysicalizationProfile = 0x1412F0C70;
        const int CGameStart_Init = 0x1411D18B0;
        const int CEntityLoadManager_ExtractEntityLoadParams_p = 0x140860E20;
        const int mCCryAction_StartGameContext_p = 0x14039E3A0;
        const int CDisplayModeManager_Initialize_p = 0x1417D7020;
        const int Update_OnlineAccount_p = 0x1412A1120;
        const int CMenuObject_OnUpdate_p = 0x1412C5C20;
        const int CFlowchartManager_GetCurrentState_p = 0x1410C65D0;
        const int CFlowchartManager_IsState_p = 0x141218180;
        const int CGame_CGame_p = 0x140FA3E40;
        const int SGameSerializerBase_IsValidSource_p = 0x14106AFC0;
        const int CMissionBackend_OnMissionLoad_p = 0x141417440;
        const int CCCacheJob_Do_p = 0x14070EC80;
        const int CLevelSystem__LoadLevel_p = 0x1404A5A50;
        const int mAddRegisterSoundListener = 0x1412181D0;
        const int GetBackendRegister = 0x1411C4D30;
        const int CAbstractServerInfo_Update_p = 0x1413A73D0;
        const int CPassedCheckpointsTracker_GetPassedCheckpoints_p = 0x141323350;
        const int CGameRules_ProcessEvent_p = 0x140FBB500;
        const int CGame_GetServerInfo_p = 0x14107B420;
        const int CGameRules_OnEndGame = 0x0000000140FC8C30;
        const int CScriptBind_GameRules_DisconnectToLobby_p = 0x00000001411018F0;
        const int CAchievementBackend_CAchievementBackend = 0x1413FD7C0;
        const int CAchievementBackend_CAchievementConfig = 0x1413FBC20;
        const int CAchievementSystem__CAchievementSystem_p = 0x1411273C0;
        const int CAchievementSystem_GetBackend_p = 0x0141127670;
        const int CAchievementSystem_GetConfig_p = 0x00000001411275F0;
        const int CGameRules_OnClientConnect_p = 0x0000000140FBC6C0;
        const int CGameRules_InitSessionStatistics_p = 0x0000000140FD0E60;
        const int CItemsPickupSystem__SpawnInventoryPickup_p = 0x1410165B0;
        const int CInventoryPickup_PickupWeapon_p = 0x1413ECA20;
        const int CGame_Update_p = 0x1411C2A80;
        const int FSGetMasterServersSerializer_p = 0x0000000141375690;
        const int SLobbyServerInfo_SerializeAllToXml_p = 0x1417C0320;
        const int CAbstractServerInfo_IsOwner_p = 0x141512FA0;
        const int SGameSerializer_CanQuerySend_p = 0x000000014106B9C0;
        const int CPlayer_CreateInputClassByType_p = 0x14123E5B0;
        const int CGameRules_NetSerialize_p = 0x14108EA80;
        const int GetStreamEngine_p = 0x140CA1470;
        const int CGameRules_Update_QueuedShotHit = 0x1411F69B0;
        const int CGameRules_Update = 0x1411DA6F0;
        const int CGameRules_Init_p = 0x1411D8840;
        const int CGameRules_GetMissionStatistics_p = 0x1411ED730;
        const int CGame_ConfigureGameChannel_p = 0x1411D0AE0;
        const int CWeaponSystem_OnLoadingStart_p = 0x141397E60;
        const int CInstantAwardSystem_p = 0x141506CB0;
        const int CInstantAwardTracker_CInstantAwardTracker = 0x141507100;
        const int sub_140DC2170_p = 0x140DC2170;
        const int mZipDir__CacheFactory__ReadHeaderData = 0x140DC3220;

    }
    namespace LoggingAddresses {
        const int mCScriptBind_System__LogString = 0x140D13DD0;
        const int mnsub_AD08E0 = 0x140D305C0;
        const int mCScriptSystem_ErrorHandler_Hook = 0x140CF0930;
        const int CLogAlways = 0x14026B520;
    }
}

#if Dedicated
enum EEntityAspects
{
	eEA_All = 0xFFFFFFFF,
	eEA_Script = 0x2,
	eEA_Physics = 0x8,
	eEA_GameClientStatic = 0x10,
	eEA_GameServerStatic = 0x20,
	eEA_GameClientDynamic = 0x40,
	eEA_GameServerDynamic = 0x80,
	eEA_GameClientA = 0x100,
	eEA_GameServerA = 0x200,
	eEA_GameClientB = 0x400,
	eEA_GameServerB = 0x800,
	eEA_GameClientC = 0x1000,
	eEA_GameServerC = 0x2000,
	eEA_GameClientD = 0x4000,
	eEA_GameClientE = 0x8000,
	eEA_GameClientF = 0x10000,
	eEA_GameClientG = 0x20000,
	eEA_GameClientH = 0x40000,
	eEA_GameClientI = 0x80000,
	eEA_GameClientJ = 0x100000,
	eEA_GameServerD = 0x200000,
	eEA_GameClientK = 0x400000,
	eEA_Aspect23 = 0x800000,
	eEA_Aspect24 = 0x1000000,
	eEA_Aspect25 = 0x2000000,
	eEA_Aspect26 = 0x4000000,
	eEA_Aspect27 = 0x8000000,
	eEA_Aspect28 = 0x10000000,
	eEA_Aspect29 = 0x20000000,
	eEA_Aspect30 = 0x40000000,
	eEA_Aspect31 = 0x80000000,
};

struct SSharedHitInfo {
public:
	unsigned int shooterId; //0x0000
    int targetId; // 0x04
    int material; // 0x08
    int typeId; // 0x0C
    int partId; // 0x014
    Vec3 pos;
};

struct SSourceGameHitInfo {
public:
	int weaponGameObjectId;
	unsigned int projectileId;
	unsigned __int16 ammoClassId;
};

struct SGameHitInfo {
public:
    int shooterId;
    int targetId; // 0x00
    int material; // 0x04
    int typeId; // 0x08
    int partId; // 0x0C
    Vec3 pos; // 0x10
    float damageReduction; // 0x1C
    char physCounter; // 0x20
    Vec3 shootPos; // 0x00
    int predictionHandle; // 0x0C
    Vec3 dir; // 0x10
};


typedef char(__fastcall* CPlayerInputSerializer_OnTeleportPlayerClass)(CGameRules* this1, SGameHitInfo* source);
CPlayerInputSerializer_OnTeleportPlayerClass CPlayerInputSerializer_OnTeleportPlayer_p = (CPlayerInputSerializer_OnTeleportPlayerClass)0x14120E940;

typedef CAbstractServerInfo* (__fastcall* CAbstractServerInfoClass)(CAbstractServerInfo* this1, __int64 compressType);
CAbstractServerInfoClass CAbstractServerInfo_CAbstractServerInfo = (CAbstractServerInfoClass)0x1415131E0;

typedef void* (__fastcall* operator_newClass)(size_t Size);
operator_newClass operator_new = (operator_newClass)0x141AE7CC4;


typedef __int64(__fastcall* CryOnlineGetInstance_newClass)();
CryOnlineGetInstance_newClass CryOnlineGetInstance = (CryOnlineGetInstance_newClass)0x141E61D00;

typedef CMissionBackend* (__fastcall* CBackend_CMissionBackendClass)(CMissionBackend* this1);
CBackend_CMissionBackendClass CMissionBackend_CMissionBackend = (CBackend_CMissionBackendClass)0x141416040;

typedef CBackend* (__fastcall* CBackend_CBackendClass)(CBackend* this1, IGameFramework* fw);
CBackend_CBackendClass CBackend_CBackend = (CBackend_CBackendClass)0x1413274B0;

typedef IStreamEngine* (__fastcall* CStreamEngine_CStreamEngineClass)(IStreamEngine*);
CStreamEngine_CStreamEngineClass CStreamEngine_CStreamEngine = (CStreamEngine_CStreamEngineClass)0x140D2BEA0;

typedef CRandomItemDropSystem*(__fastcall* CCRandomItemDropSystem_CRandomItemDropSystem)(CRandomItemDropSystem*);
CCRandomItemDropSystem_CRandomItemDropSystem CRandomItemDropSystem_p = (CCRandomItemDropSystem_CRandomItemDropSystem)0x1413BFE10;

typedef char(__fastcall* CGame_InitClass)(CGame* this1, IGameFramework* pFramework);
CGame_InitClass CGame_Init = (CGame_InitClass)0x1411C0CC0;



typedef char(__fastcall* CActor_SetPhysicalizationProfileClass)(CActor* a1, EActorPhysProfiles a2);
CActor_SetPhysicalizationProfileClass CActor_SetPhysicalizationProfile = (CActor_SetPhysicalizationProfileClass)0x1412F0C70;

typedef IGameRef* (__thiscall* HJGQZZZQQQDSADSADASdASDSADSASADSGDFGFSAAQQADFSQSASZQGAQQW)(CGameStartup* this1, IGameRef* result, SSystemInitParams* startupParams);

HJGQZZZQQQDSADSADASdASDSADSASADSGDFGFSAAQQADFSQSASZQGAQQW UU_TES11_58271 = (HJGQZZZQQQDSADSADASdASDSADSASADSGDFGFSAAQQADFSQSASZQGAQQW)0x1411D18B0;




typedef void(__fastcall* nCScriptBind_System__LogString)(DWORD64* this1, IFunctionHandler* pH, bool bToConsoleOnly);
nCScriptBind_System__LogString mCScriptBind_System__LogString = (nCScriptBind_System__LogString)0x140C1B6E0;


typedef int(__fastcall* nsub_AD08E0)(int, char*, ...);
nsub_AD08E0 mnsub_AD08E0 = (nsub_AD08E0)0x140C38B60;

typedef const char* (__fastcall* sub_tolstring)(lua_State* a1, int a2, DWORD64* a3);
typedef int(__fastcall* sub_getinfo)(lua_State* L, const char* what, lua_Debug* ar);
typedef int(__fastcall* sub_getstack)(lua_State* a1, int a2, lua_Debug* a3);

typedef bool(__fastcall* nCScriptSystem_ErrorHandler_Hook)(lua_State*);
nCScriptSystem_ErrorHandler_Hook mCScriptSystem_ErrorHandler_Hook = (nCScriptSystem_ErrorHandler_Hook)0x140BF6640;

typedef int(__thiscall* Extract_FFFF)(CEntityLoadManager* this1, XmlNodeRef* entityNode, SEntityLoadParams* outLoadParams);
Extract_FFFF CEntityLoadManager_ExtractEntityLoadParams_p = (Extract_FFFF)0x140860E20;

typedef bool(__cdecl* nCCryAction_StartGameContext)(void* this1, SGameStartParams* pGameStartParams);
nCCryAction_StartGameContext mCCryAction_StartGameContext_p = (nCCryAction_StartGameContext)0x14039E3A0;

typedef void(__fastcall* nnCNetNub__Discqqqonnect)(DWORD64* dis);
nnCNetNub__Discqqqonnect CDisplayModeManager_Initialize_p = (nnCNetNub__Discqqqonnect)0x1417D7020;


typedef void(__fastcall* nnCNetNutttb__Discqqqonnect)(COnlineAccount* dis);
nnCNetNutttb__Discqqqonnect Update_OnlineAccount_p = (nnCNetNutttb__Discqqqonnect)0x1412A1120;

typedef void(__fastcall* qqqweqweqw)(DWORD64* this1, float uiFrameTime);
qqqweqweqw CMenuObject_OnUpdate_p = (qqqweqweqw)0x1412C5C20;

typedef void(__fastcall* qqqweqweqweE)(CFlowchartManager* this1);
qqqweqweqweE CFlowchartManager_GetCurrentState_p = (qqqweqweqweE)0x1410C65D0;

typedef void(__fastcall* qqqweqweqweE0)(CFlowchartManager* this1);
qqqweqweqweE0 CFlowchartManager_IsState_p = (qqqweqweqweE0)0x141218180;

typedef void* (__cdecl* qqqweqweqweEQQQ0)(CGame* this1);
qqqweqweqweEQQQ0 CGame_CGame_p = (qqqweqweqweEQQQ0)0x140FA3E40;

typedef BOOL(__fastcall* qq)(DWORD64* this1);
qq SGameSerializerBase_IsValidSource_p = (qq)0x14106AFC0;


typedef __int64(__fastcall* qqqeww)(CMissionBackend* this1, const char* from_resource, const DWORD64* info, SMissionLoadSerializer__SMissionLoadConfigs* config, DWORD64 verbosityLevel);
qqqeww CMissionBackend_OnMissionLoad_p = (qqqeww)0x141417440;

typedef void(__fastcall* qqqq919191)(DWORD64* this1);
qqqq919191 CCCacheJob_Do_p = (qqqq919191)0x14070EC80;

typedef void* (__fastcall* q9191qqqqqQWWQwq9T19191)(CLevelSystem* this1, const char* levelName);
q9191qqqqqQWWQwq9T19191 CLevelSystem__LoadLevel_p = (q9191qqqqqQWWQwq9T19191)0x1404A5A50;

typedef void(__fastcall* nAddRegisterSoundListener)(void* pEst, int state);
nAddRegisterSoundListener mAddRegisterSoundListener = (nAddRegisterSoundListener)0x1412181D0;




typedef void(__fastcall* DADSADASdADSADSGDFGFDFGA)(const char* format, ...);
DADSADASdADSADSGDFGFDFGA CLogAlways = (DADSADASdADSADSGDFGFDFGA)0x14026B520;

typedef void(__fastcall* QWQQWE)(CGame* this1);
QWQQWE TEST_DFCNANEL5 = (QWQQWE)0x1411C4D30;

typedef void(__fastcall* HHJHGDFGHGF)(CAbstractServerInfo* this1, bool isForceUpdate);
HHJHGDFGHGF CAbstractServerInfo_Update_p = (HHJHGDFGHGF)0x1413A73D0;

typedef __int64(__fastcall* FN_CPassedCheckpointsTracker_GetPassedCheckpoints_p)(CPassedCheckpointsTracker*, SPassedCheckpoints*, unsigned __int64);
FN_CPassedCheckpointsTracker_GetPassedCheckpoints_p CPassedCheckpointsTracker_GetPassedCheckpoints_p = (FN_CPassedCheckpointsTracker_GetPassedCheckpoints_p)0x141323350;


typedef void(__fastcall* FN_CGameRules_ProcessEvent_p)(CGameRules*, SEntityEvent*);
FN_CGameRules_ProcessEvent_p CGameRules_ProcessEvent_p = (FN_CGameRules_ProcessEvent_p)0x140FBB500;

typedef CAbstractServerInfo* (__fastcall* FN_CGame__GetServerInfo_p)(CGame*);
FN_CGame__GetServerInfo_p CGame_GetServerInfo_p = (FN_CGame__GetServerInfo_p)0x1411C4D40;

typedef void(__fastcall* FN_CGameRules_OnEndGame_p)(CGameRules*, __int64, int);
FN_CGameRules_OnEndGame_p CGameRules_OnEndGame = (FN_CGameRules_OnEndGame_p)0x1411EA6E0;

typedef __int64(__fastcall* FN_CScriptBind_GameRules_DisconnectToLobby)(CScriptBind_GameRules*, IFunctionHandler*);
FN_CScriptBind_GameRules_DisconnectToLobby CScriptBind_GameRules_DisconnectToLobby_p = (FN_CScriptBind_GameRules_DisconnectToLobby)0x1413875E0;

typedef const char* (__cdecl* COpticsManager__CreateClass)(void* this1, __int64 type);
COpticsManager__CreateClass COpticsManager__Create_p;;

typedef CAchievementBackend* (__fastcall* CAchievementBackendClass)(CAchievementBackend* this1);
CAchievementBackendClass CAchievementBackend_CAchievementBackend = (CAchievementBackendClass)0x1413FD7C0;

typedef CAchievementConfig* (__fastcall* CAchievementConfigClass)(CAchievementConfig* this1);
CAchievementConfigClass CAchievementBackend_CAchievementConfig = (CAchievementConfigClass)0x1413FBC20;

typedef void(__fastcall* CAchievementSystem__CAchievementSystemClass)(CAchievementSystem* this1);
CAchievementSystem__CAchievementSystemClass CAchievementSystem__CAchievementSystem_p = (CAchievementSystem__CAchievementSystemClass)0x1411273C0;


typedef CAchievementBackend* (__fastcall* FCAchievementSystem_GetBackend)(CAchievementSystem*);
FCAchievementSystem_GetBackend CAchievementSystem_GetBackend_p = (FCAchievementSystem_GetBackend)0x0141127670;

typedef CAchievementBackend* (__fastcall* FCAchievementSystem_GetConfig)(CAchievementSystem*);
FCAchievementSystem_GetConfig CAchievementSystem_GetConfig_p = (FCAchievementSystem_GetConfig)0x00000001411275F0;

typedef bool(__fastcall* FCGameRules_OnClientConnect_p)(CGameRules*, __int32, bool);
FCGameRules_OnClientConnect_p CGameRules_OnClientConnect_p = (FCGameRules_OnClientConnect_p)0x0000000140FBC6C0;

typedef void(__fastcall* CGameRules__InitSessionStatistics)(CGameRules*);
CGameRules__InitSessionStatistics CGameRules_InitSessionStatistics_p = (CGameRules__InitSessionStatistics)0x1411F4EF0;

typedef void* (__fastcall* CItemsPickupSystem__SpawnInventoryPickupClass)(CPlayer* this1, Vec3* pos, Quat_tpl<float>* rot);
CItemsPickupSystem__SpawnInventoryPickupClass CItemsPickupSystem__SpawnInventoryPickup_p = (CItemsPickupSystem__SpawnInventoryPickupClass)0x1410165B0;

typedef void(__fastcall* CInventoryPickup_PickupWeaponClass)(void* this1, CPlayer* player, const Vec3_tpl<float>* itemPos);
CInventoryPickup_PickupWeaponClass CInventoryPickup_PickupWeapon_p = (CInventoryPickup_PickupWeaponClass)0x1413ECA20;

typedef bool(__fastcall* FCGame_Update)(CGame*, bool, unsigned int);
FCGame_Update CGame_Update_p = (FCGame_Update)0x1411C2A80;

typedef __int64(__fastcall* FSGetMasterServersSerializer)(SLoadBalancingStrategy*,
	SLoadBalancingStrategy*,
	CMasterServerList*,
	SMasterServerInfo::EStatus,
	Functor2<char const*, unsigned short>*,
	Functor2<enum EOnlineError, int>*,
	char*,
	const char*,
	const char*,
	EChannelSearchType);
FSGetMasterServersSerializer FSGetMasterServersSerializer_p = (FSGetMasterServersSerializer)0x0000000141375690;



typedef void(__fastcall* FSLobbyServerInfo_SerializeAllToXml_p)(SLobbyServerInfo*, XmlNodeRef*);
FSLobbyServerInfo_SerializeAllToXml_p SLobbyServerInfo_SerializeAllToXml_p = (FSLobbyServerInfo_SerializeAllToXml_p)0x1417C0320;

typedef bool(__fastcall* FCAbstractServerInfo_IsOwner)(CAbstractServerInfo*, const char*);
FCAbstractServerInfo_IsOwner CAbstractServerInfo_IsOwner_p = (FCAbstractServerInfo_IsOwner)0x141512FA0;

typedef bool(__fastcall* FGameSerializer_CanQuerySend)();
FGameSerializer_CanQuerySend SGameSerializer_CanQuerySend_p = (FGameSerializer_CanQuerySend)0x000000014106B9C0;

typedef bool(__cdecl* CPlayer_CreateInputClassByTypeClass)(CPlayer* this1, int nPlayerInputType);
CPlayer_CreateInputClassByTypeClass CPlayer_CreateInputClassByType_p = (CPlayer_CreateInputClassByTypeClass)0x14123E5B0;


typedef __int64(__fastcall* CCertificateValidator_QueryClass)(__int64, __int64);
CCertificateValidator_QueryClass CCertificateValidator_Query_p;

typedef void(__fastcall* SADSDFSDFSDFSDF)(__int64, __int64);
SADSDFSDFSDFSDF SADSDFSDFSDFSDF_p;
typedef void(__fastcall* SADSDFSDFSDFSDF1)(__int64, __int64);
SADSDFSDFSDFSDF1 SADSDFSDFSDFSDF1_p;
typedef void(__fastcall* SADSDFSDFSDFSDF11)(__int64, __int64);
SADSDFSDFSDFSDF11 SADSDFSDFSDFSDF11_p;
typedef void(__fastcall* SADSDFSDFSDFSDF12)(__int64, __int64);
SADSDFSDFSDFSDF12 SADSDFSDFSDFSDF12_p;
typedef void(__fastcall* SADSDFSDFSDFSDF13)(__int64, __int64);
SADSDFSDFSDFSDF13 SADSDFSDFSDFSDF13_p;
typedef __int64(__fastcall* SADSDFSDFSDFSDF14)(__int64, __int64);
SADSDFSDFSDFSDF14 SADSDFSDFSDFSDF14_p;

typedef void(__fastcall* SADSDFSDFSDFSDF15)(__int64, __int64);
SADSDFSDFSDFSDF15 SADSDFSDFSDFSDF15_p;
typedef void(__fastcall* SADSDFSDFSDFSDF16)(__int64, __int64);
SADSDFSDFSDFSDF16 SADSDFSDFSDFSDF16_p;
typedef void(__fastcall* SADSDFSDFSDFSDF17)(__int64, __int64);
SADSDFSDFSDFSDF17 SADSDFSDFSDFSDF17_p;
typedef void(__fastcall* SADSDFSDFSDFSDF18)(__int64, __int64);
SADSDFSDFSDFSDF18 SADSDFSDFSDFSDF18_p;
typedef void(__fastcall* SADSDFSDFSDFSDF19)(__int64, __int64);
SADSDFSDFSDFSDF19 SADSDFSDFSDFSDF19_p;
typedef void(__fastcall* SADSDFSDFSDFSDF20)(__int64, __int64);
SADSDFSDFSDFSDF20 SADSDFSDFSDFSDF20_p;
typedef void(__fastcall* SADSDFSDFSDFSDF21)(__int64, __int64);
SADSDFSDFSDFSDF21 SADSDFSDFSDFSDF21_p;
typedef void(__fastcall* SADSDFSDFSDFSDF22)(__int64, __int64);
SADSDFSDFSDFSDF22 SADSDFSDFSDFSDF22_p;
typedef void(__fastcall* SADSDFSDFSDFSDF23)(__int64, __int64);
SADSDFSDFSDFSDF23 SADSDFSDFSDFSDF23_p;
typedef void(__fastcall* SADSDFSDFSDFSDF24)(__int64, __int64);
SADSDFSDFSDFSDF24 SADSDFSDFSDFSDF24_p;
typedef void(__fastcall* SADSDFSDFSDFSDF25)(__int64, __int64);
SADSDFSDFSDFSDF25 SADSDFSDFSDFSDF25_p;
typedef void(__fastcall* SADSDFSDFSDFSDF26)(__int64, __int64);
SADSDFSDFSDFSDF26 SADSDFSDFSDFSDF26_p;
typedef void(__fastcall* SADSDFSDFSDFSDF27)(__int64, __int64);
SADSDFSDFSDFSDF27 SADSDFSDFSDFSDF27_p;
typedef void(__fastcall* SADSDFSDFSDFSDF28)(__int64, __int64);
SADSDFSDFSDFSDF28 SADSDFSDFSDFSDF28_p;
typedef void(__fastcall* SADSDFSDFSDFSDF29)(__int64, __int64);
SADSDFSDFSDFSDF29 SADSDFSDFSDFSDF29_p;
typedef float*(__fastcall* SADSDFSDFSDFSDF30)(__int64 a1, float* a2, void* a3, float* a4, float* a5);
SADSDFSDFSDFSDF30 SADSDFSDFSDFSDF30_p;


typedef void(__fastcall* SADSDFSDFSDFSDF31)(__int64 a1, float* a2, void* a3, float* a4, float* a5);
SADSDFSDFSDFSDF31 SADSDFSDFSDFSDF31_p;





typedef bool(__fastcall* FCGameRules_NetSerialize)(CGameRules* this1, __int64 ser, EEntityAspects aspect, unsigned __int8 profile);
FCGameRules_NetSerialize CGameRules_NetSerialize_p = (FCGameRules_NetSerialize)0x14108EA80;




typedef IStreamEngine*(__fastcall* FGetStreamEngine)(CSystem*);
FGetStreamEngine GetStreamEngine_p = (FGetStreamEngine)0x140CA1470;
typedef bool(__fastcall* TESTEST)(__int64*);
TESTEST Prepare_p = (TESTEST)0x140D92550;

typedef unsigned __int64(__fastcall* CGameRules_Update_QueuedShotHitClass)(CGameRules* this1);
CGameRules_Update_QueuedShotHitClass CGameRules_Update_QueuedShotHit = (CGameRules_Update_QueuedShotHitClass)0x1411F69B0; //find 48 89 87 ? ? ? ? 48 8B 5C 24 ? 48 8B 74 24 ? 48 83 C4 20 5F C3 48 8B 74 24 ? 48 89 9F ? ? ? ? 48 8B 5C 24 ? 48 83 C4 20 5F C3 CC CC CC CC CC CC CC CC CC 44 89 4C 24 ?


typedef void(__fastcall* CGameRules_UpdateClass)(CGameRules* this1, void* ctx, int updateSlot);
CGameRules_UpdateClass CGameRules_Update = (CGameRules_UpdateClass)0x1411DA6F0;

typedef bool(__fastcall* CGameRules_InitClass)(CGameRules* this1, IGameObject* pGameObject);
CGameRules_InitClass CGameRules_Init_p = (CGameRules_InitClass)0x1411D8840;

typedef CMissionStatistics*(__fastcall* CCGameRules_GetMissionStatistics)(CGameRulesC* this1);
CCGameRules_GetMissionStatistics CGameRules_GetMissionStatistics_p = (CCGameRules_GetMissionStatistics)0x1411ED730;

typedef void (__fastcall* CGameRules_KillPlayerClass)(CGameRules* this1,
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
    bool bExplosion);
CGameRules_KillPlayerClass CGameRules_KillPlayer_p = (CGameRules_KillPlayerClass)0x1411E2840;

typedef void(__fastcall* CGameRules_AwardPlayerClass)(CGameRules* this1,
    const char* eventName,
    unsigned int entityId,
    int amount,
    int bonus,
    bool allowMultiplierChange);
CGameRules_AwardPlayerClass CGameRules_AwardPlayer_p = (CGameRules_AwardPlayerClass)0x1411E06F0;

typedef void(__fastcall* CKillStatsCKillStats)(CKillStats* this1,
    unsigned int target,
    bool isPlayer,
    unsigned int projectile,
    const char* weapon,
    const char* hitType,
    const char* weaponSlot,
    const char* weaponSkin,
    const char* stance,
    const char* specialMove,
    const char* weaponTags,
    bool inJump,
    bool friendlyFire,
    bool withFlag,
    int targetsCoreTeam,
    int shootersCoreTeam,
    int materialId,
    bool isSilencedWeapon,
    bool isZoomedWeapon,
    const char* targetStance,
    const char* targetSpecialMove,
    bool targetInJump);
CKillStatsCKillStats CKillStats_CKillStats_p = (CKillStatsCKillStats)0x1414ECF20;

struct ScriptHandle {
public:
    unsigned __int64 n;
};

typedef __int64(__fastcall* ClassDamagePlayer)(CScriptBind_GameRules* this1,
    void* pH,
    ScriptHandle targetId,
    ScriptHandle shooterId,
    bool silencer,
    Vec3_tpl<float>* direction,
    char* hitType);
ClassDamagePlayer CGameRules_DamagePlayer = (ClassDamagePlayer)0x141386870;



typedef void(__fastcall* CGame_ConfigureGameChannel_InitClass)(__int64, unsigned __int8, __int64);
CGame_ConfigureGameChannel_InitClass CGame_ConfigureGameChannel_p = (CGame_ConfigureGameChannel_InitClass)0x1411D0AE0;
typedef void(__fastcall* CWeaponSystem_OnLoadingStart_InitClass)(__int64);
CWeaponSystem_OnLoadingStart_InitClass CWeaponSystem_OnLoadingStart_p = (CWeaponSystem_OnLoadingStart_InitClass)0x141397E60;

typedef void(__fastcall* CInstantAwardSystemClass)(CInstantAwardSystem* this1);
CInstantAwardSystemClass CInstantAwardSystem_p = (CInstantAwardSystemClass)0x141506CB0;

/*__int64 __fastcall sub_141506D90(__int64 a1) (CINstantAwardSystem::Init -> xrefs -> goto up -> 3x functions -> goto ur addresses of function!)*/

typedef CInstantAwardTracker* (__fastcall* CInstantAwardTrackerClassClass)(CInstantAwardSystem* this1);
CInstantAwardTrackerClassClass CInstantAwardTracker_CInstantAwardTracker = (CInstantAwardTrackerClassClass)0x141506DE0;

#endif


typedef bool(__fastcall* nsub_140DC2170)(__int64 a1);
nsub_140DC2170 sub_140DC2170_p = (nsub_140DC2170)0x140DC2170;

typedef bool(__cdecl* nZipDir__CacheFactory__ReadHeaderData)(void* this1, void* pDest, unsigned int nSize);
nZipDir__CacheFactory__ReadHeaderData mZipDir__CacheFactory__ReadHeaderData = (nZipDir__CacheFactory__ReadHeaderData)0x140DC3220;

typedef void(__fastcall* CCGameRules_ReportGameEnd)(CGameRulesEnd*, EGameEndReason, int, SSessionRewardsInfo*);
CCGameRules_ReportGameEnd CGameRules_ReportGameEnd_p = (CCGameRules_ReportGameEnd)0x1411EE2A0;

typedef void(__fastcall* CSSetRewardsInfoSerializer_OnRequest)(void*, XmlNodeRef* request, SSessionRewardsInfo* rewardsInfo);
CSSetRewardsInfoSerializer_OnRequest SSetRewardsInfoSerializer_OnRequest_p = (CSSetRewardsInfoSerializer_OnRequest)0x14149CE30;

typedef const char* (__fastcall* CGetQueryReceiverId_p)(void*);
CGetQueryReceiverId_p GetQueryReceiverId_p = (CGetQueryReceiverId_p)0x141298580;

typedef const char* (__fastcall* CAchievementsTrackerSaveClass)(CAchievementsTracker* this1);
CAchievementsTrackerSaveClass CAchievementsTracker_SaveAchievements_p = (CAchievementsTrackerSaveClass)0x141501E20;

struct CSM_Vault {
public:

};

typedef void (__fastcall* CPlayerSlideClass)(CPlayer* this1, bool state);
CPlayerSlideClass CPlayer_SetSlide_p = (CPlayerSlideClass)0x1412272C0;


typedef void(__fastcall* CSM_VaultClassF)(CSM_Vault* this1);
CSM_VaultClassF CSM_VaultFinsih_p = (CSM_VaultClassF)0x1416C42F0;

struct SM_Network_SVaultMessage {

    int animIndex;
    QuatT_tpl<float> animStartPose;
    Vec3_tpl<float> helperClosestPoint;
    bool animFinished;
}; //Size=0x0040

typedef void(__fastcall* SM_NetworSerializeWithClass)(CPlayer* this1,
     SM_Network_SVaultMessage* params);
SM_NetworSerializeWithClass SM_NetworkSMessage_SerializeWith_p = (SM_NetworSerializeWithClass)0x141244660;

struct IMaterial {
public:

};

struct CViewSettings {
public:

};

struct CAttachementSettings {
public:
    char pad_0x0098[0x98];
    CViewSettings* m_pSettings;
};

struct Game_CAttachment {
public:
    char pad_0x0040[0x40];
    CWeaponGeneral* m_pWeapon;

    CAttachementSettings* GetAttachSettings() {
        return *(CAttachementSettings**)((DWORD64)this + 0x28);
    }

};

typedef void(__fastcall* AttachClass)(Game_CAttachment* this1,
    CWeaponGeneral* pWeapon,
    const char* pSocket,
    const char* pParent);
AttachClass Game_CAttachment_OnAttach_p = (AttachClass)0x141683F30;

struct serializer {

};

typedef bool(__fastcall* SerializeClass)(CActor* this1,
    serializer ser,
    EEntityAspects aspect,
    unsigned __int8 profile,
    int pflags);
SerializeClass CActor_NetSerialize_p = (SerializeClass)0x141234800;

struct SPathFindParams {
public:
    char pad_0x00010[0x10];
    IEntityCSM* m_pEntity;
};

typedef __int64(__fastcall* ShieldClass)(__int64 a1, unsigned __int16 a2, SPathFindParams* a3);
ShieldClass TeleportShield_p = (ShieldClass)0x1403C91A0;

struct SIngameShopOffer {
    void* __vftable /*VFT*/;
    CryStringT<char> name;
    CryStringT<char> category;
    int classes;
    CryStringT<char> description;
    CryStringT<char> icon;
    CryStringT<char> label;
    CryStringT<char> sound;
    void* subitems;
    void* currencyValues;
};



struct CIngameShop {
public:
    bool m_isInSync;
    unsigned int m_soundId;
    void* m_IngameShopList;
    void* m_IngameShopListIterator;
};




typedef void(__fastcall* ShopBuyOfferClass)(CIngameShop* this1, SIngameShopOffer const* offer, unsigned int entityId);
ShopBuyOfferClass ShopBuyOffer_p = (ShopBuyOfferClass)0x14125B6A0;


typedef void(__fastcall* CSM_InteractionActionClass)(CSM_InteractionAction* this1, __int64 a2, bool a3);
CSM_InteractionActionClass CSM_InteractionAction_p = (CSM_InteractionActionClass)0x1418F6A50;





