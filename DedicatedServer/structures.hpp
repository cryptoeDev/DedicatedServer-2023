#if Dedicated

struct CItemProxy {
public:
    char pad_0x0000[0x18];
    IGameObject* m_pGameObject;


    IGameObject* GetIGameObject() {
        return *(IGameObject**)((DWORD64)this + 0x18);
    }

};




struct CAchievementClient {};
struct CAchievementConfig {};



struct IExternalAchievements {};




class CAchievementBackend {
private:
    using FN_RequestAchievements = void(__thiscall*)(CAchievementBackend*, __int64);
public:
    struct SProfileAchievements {
        int achievementId;
        std::string achievementName;
        SProfileAchievements(int id, const std::string& name)
            : achievementId(id), achievementName(name) {
        }
    };
    static void RequestAchievements(CAchievementBackend* a1, __int64 profileId) {
        FN_RequestAchievements(0x00000001413FDCD0)(a1, profileId);
    }
};


struct CAchievementSystem
{
    void* __vftable /*VFT*/;
    CAchievementConfig* m_pAchievementConfig;
    std::auto_ptr<CAchievementClient> m_pClient;
    CAchievementBackend* m_pBackend;
    std::auto_ptr<IExternalAchievements> m_pExternalAchievements;
};

struct CGame_V2 {
public:
    CAchievementSystem* m_pAchievementSystem() {
        return *(CAchievementSystem**)((DWORD64)this + 0x1C8);
    }
    static CGame_V2* Signlenton()
    {
        return (CGame_V2*)*(__int64*)(0x142511DE0);
    }
};


struct CPhysSerializer {
public:
    char pad_0x0000[0x38];
    bool m_pTeleport;
};



struct ISignal {
public:

};


struct CNetChannel;



struct ILevelSystemListener {
public:

};

struct ILevel {
public:


};

struct CLevelSystem {
public:
};


struct  CMovementErrAggregator
{
public:

};

struct IXmlNode {
public:
    void setAttr(const char* name, const char* attribute) {
        CallFunction<void(__thiscall*)(PVOID64, const char*, const char*) >(this, 0x208)(this, name, attribute);
    }
};

struct IEntityClass {};
struct CEntityLoadManager {};
struct  XmlNodeRef {
public:
    IXmlNode* p;
};
struct SEntityLoadParams {};


struct SMissionLoadSerializer__SMissionLoadConfigs {
public:
    XmlNodeRef anticheat_config;
    XmlNodeRef online_variables_config;
};

struct SGameContextParams
{
    const char* levelName;
    const char* gameRules;
    const char* demoRecorderFilename;
    const char* demoPlaybackFilename;

    SGameContextParams()
    {

    }
};

typedef unsigned __int32 CrySessionHandle;

const struct SGameStartParams
{
    const char* hostname;
    const char* connectionString;
    const SGameContextParams* pContextParams;
    unsigned int flags;
    int maxPlayers;
    unsigned int session;
    unsigned __int16 port;
    const char* nickname;
};


enum EGameStartFlags : __int32
{
    eGSF_NoLevelLoading = 0x1,
    eGSF_Server = 0x2,
    eGSF_Client = 0x4,
    eGSF_NoDelayedStart = 0x8,
    eGSF_BlockingClientConnect = 0x10,
    eGSF_NoGameRules = 0x20,
    eGSF_LocalOnly = 0x40,
    eGSF_NoQueries = 0x80,
    eGSF_NoSpawnPlayer = 0x100,
    eGSF_BlockingMapLoad = 0x200,
    eGSF_DemoRecorder = 0x400,
    eGSF_DemoPlayback = 0x800,
    eGSF_ImmersiveMultiplayer = 0x1000,
    eGSF_RequireController = 0x2000,
    eGSF_RequireKeyboardMouse = 0x4000,
    eGSF_HostMigrated = 0x8000,
    eGSF_NonBlockingConnect = 0x10000,
};

enum EEntityFlags : __int32
{
    ENTITY_FLAG_CASTSHADOW = 0x2,
    ENTITY_FLAG_UNREMOVABLE = 0x4,
    ENTITY_FLAG_GOOD_OCCLUDER = 0x8,
    ENTITY_FLAG_NO_DECALNODE_DECALS = 0x10,
    ENTITY_FLAG_WRITE_ONLY = 0x20,
    ENTITY_FLAG_NOT_REGISTER_IN_SECTORS = 0x40,
    ENTITY_FLAG_CALC_PHYSICS = 0x80,
    ENTITY_FLAG_CLIENT_ONLY = 0x100,
    ENTITY_FLAG_SERVER_ONLY = 0x200,
    ENTITY_FLAG_CUSTOM_VIEWDIST_RATIO = 0x400,
    ENTITY_FLAG_CALCBBOX_USEALL = 0x800,
    ENTITY_FLAG_VOLUME_SOUND = 0x1000,
    ENTITY_FLAG_HAS_AI = 0x2000,
    ENTITY_FLAG_TRIGGER_AREAS = 0x4000,
    ENTITY_FLAG_NO_SAVE = 0x8000,
    ENTITY_FLAG_CAMERA_SOURCE = 0x10000,
    ENTITY_FLAG_CLIENTSIDE_STATE = 0x20000,
    ENTITY_FLAG_SEND_RENDER_EVENT = 0x40000,
    ENTITY_FLAG_NO_PROXIMITY = 0x80000,
    ENTITY_FLAG_ON_RADAR = 0x100000,
    ENTITY_FLAG_UPDATE_HIDDEN = 0x200000,
    ENTITY_FLAG_NEVER_NETWORK_STATIC = 0x400000,
    ENTITY_FLAG_IGNORE_PHYSICS_UPDATE = 0x800000,
    ENTITY_FLAG_SPAWNED = 0x1000000,
    ENTITY_FLAG_SLOTS_CHANGED = 0x2000000,
    ENTITY_FLAG_MODIFIED_BY_PHYSICS = 0x4000000,
    ENTITY_FLAG_OUTDOORONLY = 0x8000000,
    ENTITY_FLAG_SEND_NOT_SEEN_TIMEOUT = 0x10000000,
    ENTITY_FLAG_RECVWIND = 0x20000000,
    ENTITY_FLAG_LOCAL_PLAYER = 0x40000000,
    ENTITY_FLAG_AI_HIDEABLE = 0x80000000,
};




struct lua_Debug
{
    int event;
    const char* name;
    const char* namewhat;
    const char* what;
    const char* source;
    int currentline;
    int nups;
    int linedefined;
    int lastlinedefined;
    char short_src[60];
    int i_ci;
};


struct lua_State
{
    DWORD64* next;
    unsigned __int8 tt;
    unsigned __int8 marked;
    unsigned __int8 status;
    DWORD64* top;
    DWORD64* base;
    DWORD64* l_G;
    DWORD64* ci;
    const unsigned int* savedpc;
    DWORD64* stack_last;
    DWORD64* stack;
    DWORD64* end_ci;
    DWORD64* base_ci;
    int stacksize;
    int size_ci;
    unsigned __int16 nCcalls;
    unsigned __int8 hookmask;
    unsigned __int8 allowhook;
    int basehookcount;
    int hookcount;
    void(__fastcall* hook)(lua_State*, lua_Debug*);
    DWORD64 l_gt;
    DWORD64 env;
    DWORD64* openupval;
    DWORD64* gclist;
    DWORD64* errorJmp;
    __int64 errfunc;
};


struct CTexture {};




struct CNetNub;


struct CCryAction;



struct XmlNodeRef;
struct SOpenRoomSerializer;
struct SGameRoomPlayerInfo;
struct SRoomCustomParameters;






struct CFlowchartManager;

struct VehicleSeatActionSound {};
struct CVehicleParams {};

struct CNetwork* this1{};

enum EEntityEvent : __int32
{
    ENTITY_EVENT_XFORM = 0x0,
    ENTITY_EVENT_TIMER = 0x1,
    ENTITY_EVENT_INIT = 0x2,
    ENTITY_EVENT_DONE = 0x3,
    ENTITY_EVENT_VISIBLITY = 0x4,
    ENTITY_EVENT_RESET = 0x5,
    ENTITY_EVENT_ATTACH = 0x6,
    ENTITY_EVENT_ATTACH_THIS = 0x7,
    ENTITY_EVENT_DETACH = 0x8,
    ENTITY_EVENT_DETACH_THIS = 0x9,
    ENTITY_EVENT_LINK = 0xA,
    ENTITY_EVENT_DELINK = 0xB,
    ENTITY_EVENT_HIDE = 0xC,
    ENTITY_EVENT_UNHIDE = 0xD,
    ENTITY_EVENT_ENABLE_PHYSICS = 0xE,
    ENTITY_EVENT_PHYSICS_CHANGE_STATE = 0xF,
    ENTITY_EVENT_SCRIPT_EVENT = 0x10,
    ENTITY_EVENT_ENTERAREA = 0x11,
    ENTITY_EVENT_LEAVEAREA = 0x12,
    ENTITY_EVENT_ENTERNEARAREA = 0x13,
    ENTITY_EVENT_LEAVENEARAREA = 0x14,
    ENTITY_EVENT_MOVEINSIDEAREA = 0x15,
    ENTITY_EVENT_MOVENEARAREA = 0x16,
    ENTITY_EVENT_RESURRECTINAREA = 0x17,
    ENTITY_EVENT_PHYS_POSTSTEP = 0x18,
    ENTITY_EVENT_PHYS_BREAK = 0x19,
    ENTITY_EVENT_AI_DONE = 0x1A,
    ENTITY_EVENT_SOUND_DONE = 0x1B,
    ENTITY_EVENT_NOT_SEEN_TIMEOUT = 0x1C,
    ENTITY_EVENT_COLLISION = 0x1D,
    ENTITY_EVENT_RENDER = 0x1E,
    ENTITY_EVENT_PREPHYSICSUPDATE = 0x1F,
    ENTITY_EVENT_LEVEL_LOADED = 0x20,
    ENTITY_EVENT_START_LEVEL = 0x21,
    ENTITY_EVENT_START_GAME = 0x22,
    ENTITY_EVENT_ENTER_SCRIPT_STATE = 0x23,
    ENTITY_EVENT_LEAVE_SCRIPT_STATE = 0x24,
    ENTITY_EVENT_PRE_SERIALIZE = 0x25,
    ENTITY_EVENT_POST_SERIALIZE = 0x26,
    ENTITY_EVENT_INVISIBLE = 0x27,
    ENTITY_EVENT_VISIBLE = 0x28,
    ENTITY_EVENT_MATERIAL = 0x29,
    ENTITY_EVENT_MATERIAL_LAYER = 0x2A,
    ENTITY_EVENT_ONHIT = 0x2B,
    ENTITY_EVENT_PICKUP = 0x2C,
    ENTITY_EVENT_ANIM_EVENT = 0x2D,
    ENTITY_EVENT_SCRIPT_REQUEST_COLLIDERMODE = 0x2E,
    ENTITY_EVENT_ACTIVE_FLOW_NODE_OUTPUT = 0x2F,
    ENTITY_EVENT_LAST = 0x30,
};


struct  SEntityEvent
{
    EEntityEvent event;
    __int64 nParam[4];
    float fParam[2];
};





struct CScriptBind_GameRules {};





struct  CBackgroundServer //: //IRemoteControlClientListener, ISystemEventListener
{
public:
};

struct GameStartup;


enum EActorPhysProfiles
{
    eAPP_NotPhysicalized = 0x0,
    eAPP_Alive = 0x1,
    eAPP_Ragdoll = 0x2,
    eAPP_Spectator = 0x3,
};

struct IAnimGraphState {
public:

};

struct CActorAnimation {
public:
    //IAnimGraphState* GetAnimGraphState() {
    //    return CallFunction<IAnimGraphState * (__thiscall*)(PVOID64, __int64, __int64)>(this, 0xC8)(this, 20, 0);
    //}
};

enum EEntityXFormFlags : __int32
{
    ENTITY_XFORM_POS = 0x2,
    ENTITY_XFORM_ROT = 0x4,
    ENTITY_XFORM_SCL = 0x8,
    ENTITY_XFORM_NO_PROPOGATE = 0x10,
    ENTITY_XFORM_FROM_PARENT = 0x20,
    ENTITY_XFORM_PHYSICS_STEP = 0x2000,
    ENTITY_XFORM_EDITOR = 0x4000,
    ENTITY_XFORM_TRACKVIEW = 0x8000,
    ENTITY_XFORM_TIMEDEMO = 0x10000,
    ENTITY_XFORM_NOT_REREGISTER = 0x20000,
    ENTITY_XFORM_NO_EVENT = 0x40000,
    ENTITY_XFORM_NO_SEND_TO_ENTITY_SYSTEM = 0x80000,
    ENTITY_XFORM_USER = 0x1000000,
};

struct IEntityCSM {
public:
    void SetRotation(Quat* vAngles, int nWhyFlags = 0) 
    { 
        CallFunction<void(__thiscall*)(PVOID64, Quat*, int)>(this, 0xE8)(this, vAngles, nWhyFlags);
        //__virtual< void >(this, 29, vAngles, nWhyFlags); 
    }

    const char* Name()
    {
        return CallFunction<const char* (__fastcall*)(PVOID64)>(this, 0x60)(this);
    }

    void SetPos(Vec3 p) {
        CallFunction<void(__fastcall*)(PVOID, Vec3, INT64)>(this, 0xD8)(this, p, 0);
    }

    Matrix34& GetWorldTM()
    {
        return CallFunction<Matrix34 & (__thiscall*)(PVOID64)>(this, 0xB8)(this);
    }

    void SetWorldPos(Vec3 vec3, EEntityXFormFlags flags) {
        CallFunction<void(__fastcall*)(PVOID64, Vec3, EEntityXFormFlags)>(this, 0xA8)(this, vec3, flags);
    }


};

struct CPlayerResurrector {
public:

};

struct IHumanPlayer {
    CPlayerResurrector* GetResurrector() {
        return *(CPlayerResurrector**)((DWORD64)this + 8);
    }
};

struct CSMMovementController {
public:

};

struct CActorInventory {
public:

};

struct CActorInv {
public:
    char pad_0x408[0x408];
    CActorInventory m_inventory;
};

struct SSpecialMovementState {
public:
    char pad_0x0x168[0x168];
    unsigned int holdEntity;
};


struct CActor
{
public:
    char pad_0x18[0x18];
    IGameObject* m_pGameObjcet;
    char pad_0x20[0x20];
    unsigned int m_entityId;
    EActorPhysProfiles m_physicalizationProfile;

    //0x1010

    SSpecialMovementState GetMovementSMState() {
        return *(SSpecialMovementState*)((DWORD64)this + 0x1010);
    }


    unsigned int holdEntity() {
        return *(unsigned int*)((DWORD64)this + 4280);
    }


    int Id() {
        return *(int*)((DWORD64)this + 0x20);
    }

    CActorInventory* GetActorInventory() {//0x408
        return *(CActorInventory**)((DWORD64)this + 0x408);
    }

    IEntityCSM* GetEntity() {
        return *(IEntityCSM**)((DWORD64)this + 0x10);
    }
    IEntity* GetEntityDefault() {
        return *(IEntity**)((DWORD64)this + 0x10);
    }

    //0x200
    CSMMovementController* GetCSMMovementController() {
        return *(CSMMovementController**)((DWORD64)this + 0x200);
    }

    bool IsLocalClient() {
        return CallFunction<bool(__fastcall*)(PVOID64)>(this, 0x380)(this);
    }

    void SetPhysicalizationProfile(EActorPhysProfiles profile) {
        CallFunction<void(__fastcall*)(PVOID64, EActorPhysProfiles)>(this, 0x3E0)(this, profile);
    }

    //0xD78

    IHumanPlayer* GetHumanPlayer() {
        return *(IHumanPlayer**)((DWORD64)this + 0xD78);
    }


    CActorAnimation* GetActorAnimation() {
        return CallFunction<CActorAnimation *(__thiscall*)(PVOID64, __int64, __int64)>(this, 0x298)(this, 20, 0);
    }

    int Health() {
        return CallFunction<int(__thiscall*)(PVOID64)>(this, 0xE0)(this);
    }

    void SetHealth(int health = 0) {
        CallFunction<void(__fastcall*)(PVOID64, int)>(this, 0xE8)(this, health);
    }


    bool IsDead() {
        return Health() <= 0;
    }


    void StanceChanged(int lastStance, int newStance)
    {
        //CallFunction<void(__fastcall*)(PVOID64, __int64, __int64)>(this, 1304)(this, lastStance, newStance);
        typedef void(__thiscall* StanceChanged)(PVOID, int, int);
        CallFunction<StanceChanged>(this, 1304)(this, lastStance, newStance);
    }
};

struct CSpecialMove {
public:
    void* __vftable /*VFT*/;
    const CSpecialMoveClass* m_pClass;
    CActor* m_pPlayer;
};

enum EInstallState : __int32
{
    Denied = 0x0,
    Allowed = 0x1,
    Started = 0x2,
};


struct CSM_InteractionAction : CSpecialMove {
public:
    const CTimeValue m_allowActionEventTime;
    CTimeValue m_lastInstallCheckTime;
    CTimeValue m_modelAttachTime;
    EInstallState m_installState;
};

class Pointer {
public:


    static Pointer* startAddr(DWORD64 dw)
    {
        return (Pointer*)*(DWORD64*)(dw);
    }

    Pointer* AddPointer(DWORD64 dw)
    {
        return (Pointer*)*(DWORD64*)((DWORD64)this + dw);
    }

};


struct IFunctionHandler {};

struct ISystem {};
struct ILog {};
struct ILogCallback {};
struct ISystemUserCallback {};
struct IValidator {};
struct IOutputPrintSink {};
struct SCvarsDefault {};



struct SSystemInitParams {
    char pad_0xA43[2627];
    bool bDedicatedServer;
    char pad_0xA4F[9];
    bool bSkipInput;
};

enum ECompressType : __int32
{
    eCS_Default = 0x0,
    eCS_NoCompression = 0x1,
    eCS_ForceNoCompression = 0x2,
    eCS_Compress = 0x3,
    eCS_SmartCompress = 0x4,
};




struct CGameStartup {};
struct IGameRef {};

#endif