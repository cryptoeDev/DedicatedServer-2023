#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

#include "SDK.hpp"
#include <vector>
#include <map>
#include <string>


#if Dedicated
enum EOnlineError : __int32 {

};

enum EChannelSearchType : __int32
{
	eChannelSearch_None = 0,
	eChannelSearch_QuickPlay = 1,
	eChannelSearch_Survival = 2,
	eChannelSearch_ClanWar = 3,
	eChannelSearch_Pve = 4
};

template<typename T1, typename T2>
class Functor2 {
public:
	virtual void operator()(T1, T2) = 0;
	virtual ~Functor2() = default;

};


template<typename ClassData>
__forceinline ClassData CallFunction(PVOID64 BaseClass, INT vIndex)
{
	PDWORD64* vPointer = (PDWORD64*)BaseClass;
	PDWORD64 vFunction = *vPointer;
	DWORD64 dwAddress = vFunction[vIndex / 8];
	return (ClassData)(dwAddress);
}

class SMasterServerRoomInfo {
public:
	class SRoomPlayer {
		__int64 profile_id;
		__int64 team;
		__int64 observer;
		__int64 undefined_0x0A;
		__int64 undefined_0x0B;
		__int64 status;
	};
};


class CRandomItemDropSystem;

class SPassedCheckpoints;

class CPassedCheckpointsTracker {

};
typedef unsigned __int64 ImPtr;

struct IRenderer {
public:

	Vec3 GetViewCamera(void) { return *(Vec3*)((ImPtr)this + 0x17C0); }

	HWND GetHWND()
	{
		return *(HWND*)((DWORD64)this + 0x0A568);
	}

	using FN_SetRenderer = void(__thiscall*)(IRenderer*, int, int);
	using FN_SetActive = void(__thiscall*)(IRenderer*, bool);

	void SetRenderTarget() {

		//printf("Init Console staps [1/2] Succesfully!\n");

		return FN_SetRenderer(0x140DA1B80)(this, 0, 0);

	}

	//140E84640

	void SetActive() {
		return FN_SetActive(0x140E84640)(this, 0);
	}


};



enum EConnectionState
{
	ECS_Disconnected = 0x0,
	ECS_WaitingForCredentials = 0x1,
	ECS_WaitingForConnection = 0x2,
	ECS_WaitingForDisconnect = 0x3,
	ECS_Connected = 0x4,
};

struct IOnlineConfiguration {
public:
};

struct COnlineProfile {
public:
	void Update() {
		CallFunction<void(__thiscall*)(PVOID64)>(this, 0x50)(this);
	}
};

struct OnlineVariables {
public:

};

struct COnlineAccount {
public:
	char pad_0x0000[0xC0]; //0x0000
	EConnectionState m_state; //0x00C0
	char pad_0x00C0[0x20]; // 0x00C0 - 0x00E0
	COnlineProfile* m_profile;





	using FN_Connect = void(__thiscall*)(COnlineAccount*, bool);

	using FN_Login = void(__thiscall*)(COnlineAccount*, const char*, const char*);
	using FN_Disconnect = void(__thiscall*)(COnlineAccount*, int);

	void Login(const char* login, const char* pwd) {

		return FN_Login(0x1410722B0)(this, login, pwd); //1410722B0

	}

	void Disconnect() {

		return FN_Disconnect(0x1412A23E0)(this, 0); //1410722B0

	}


	void Connect() {

		this->Login("1", "1");

		return FN_Connect(0x140DA1B80)(this, false);

	}


	//0xBB0

	COnlineProfile* GetCOnlineProfile() {
		return *(COnlineProfile**)((DWORD64)this + 0xE0);
	}
	OnlineVariables* GetVariables() {
		return *(OnlineVariables**)((DWORD64)this + 0x60);
	}


};

enum EBombState : __int32
{
	eBS_Unknown = 0x0,
	eBS_Initial = 0x1,
	eBS_Dropped = 0x2,
	eBS_PickedUp = 0x3,
	eBS_Planted = 0x4,
	eBS_Exploded = 0x5,
	eBS_Defusing = 0x6,
	eBS_Count = 0x7,
};

enum EPlantSite : __int32
{
	ePlantSite_Unknown = 0x0,
	ePlantSite_A = 0x1,
	ePlantSite_B = 0x2,
	ePlantSite_Count = 0x3,
};


struct XMVec4;


struct CPTBGameRules
{
public:
	char pad_8[8];
	EBombState* m_pBombState;
	char pad_0xC[0xC];
	EPlantSite m_plantSite;
	char pad_0x10[0x10];
	unsigned int m_pBombOwner;

	void SetBombPos(Vec3_tpl<float>* pos)
	{

		/*

				IEntity* v3; // rax
				IEntity* v4; // rax
				Matrix34 v15; // rax
				Matrix34 v16; // rax
				v3 = gEnv->GetEntitySystem()->FindEntityByName("BombGeometry");
				v4 = gEnv->GetEntitySystem()->FindEntityByName("bomb");

				if (v3)
				{
					v3->DeHide();
					v15 = v3->GetWorldTM();
				}
				if (v4)
				{
					v4->DeHide();
					v16 = v4->GetWorldTM();
				}*/

	}

};

struct SStanceState {
	Vec3 pos;
	Vec3 entityDirection;
	Vec3 animationBodyDirection;
	Vec3 upDirection;
	Vec3 weaponPosition;
	Vec3 aimDirection;
	Vec3 fireDirection;
	Vec3 eyePosition;
	Vec3 eyeDirection;
	AABB m_StanceSize;
	AABB m_ColliderSize;
};

struct SMovementState : SStanceState
{
	Vec3_tpl<float> fireTarget;
	EStance stance;
	Vec3_tpl<float> animationEyeDirection;
	Vec3_tpl<float> movementDirection;
	Vec3_tpl<float> lastMovementDirection;
	float desiredSpeed;
	float minSpeed;
	float normalSpeed;
	float maxSpeed;
	float slopeAngle;
	bool atMoveTarget;
	bool isAiming;
	bool isVisible;
};

template <typename F> struct Ang3_tpl {

	float x;
	float y;
	float z;

	~Ang3_tpl(void) {};
};

struct SActorTargetParams
{
	Vec3 location;
	Vec3 direction;
	char vehicleName;
	int vehicleSeat;
	float speed;
	float directionTolerance;
	float startArcAngle;
	float startWidth;
	bool signalAnimation;
	bool projectEnd;
	bool navSO;
	char animation;
	EStance stance;
	unsigned int* pQueryStart;
	unsigned int* pQueryEnd;
	void* triggerUser;
};

struct SPredictedCharacterStates
{
	void* states[10];
	int nStates;
};

enum ELookStyle
{
	LOOKSTYLE_DEFAULT = 0,
	LOOKSTYLE_HARD,
	LOOKSTYLE_HARD_NOLOWER,
	LOOKSTYLE_SOFT,
	LOOKSTYLE_SOFT_NOLOWER,
	LOOKSTYLE_COUNT
};

struct CMovementRequest {
	unsigned __int64 m_flags;
	Vec3 m_lookTarget;
	Vec3 m_aimTarget;
	Vec3 m_bodyTarget;
	Vec3 m_fireTarget;
	float m_desiredSpeed;
	float m_lookImportance;
	float m_distanceToPathEnd;
	EStance m_stance;
	Vec3_tpl<float> m_moveTarget;
	Vec3_tpl<float> m_inflectionPoint;
	Vec3_tpl<float> m_desiredBodyDirectionAtTarget;
	Vec3_tpl<float> m_deltaMovement;
	Ang3_tpl<float> m_deltaRotation;
	float m_desiredLean;
	float m_desiredPeekOver;
	SActorTargetParams m_actorTarget;
	int m_alertness;
	int m_alertnessLast;
	float m_pseudoSpeed;
	SPredictedCharacterStates m_prediction;
	Vec3_tpl<float> m_forcedNavigation;
	ELookStyle m_eLookStyle;
	unsigned int m_context;

	typedef unsigned __int64 MovementRequestFlags;
	static const unsigned __int64 eMRF_LookTarget = 1ULL << 0;
	static const unsigned __int64 eMRF_AimTarget = 1ULL << 1;
	static const unsigned __int64 eMRF_DesiredSpeed = 1ULL << 2;
	static const unsigned __int64 eMRF_Stance = 1ULL << 3;
	static const unsigned __int64 eMRF_MoveTarget = 1ULL << 4;
	static const unsigned __int64 eMRF_DeltaMovement = 1ULL << 5;
	static const unsigned __int64 eMRF_DeltaRotation = 1ULL << 6;
	static const unsigned __int64 eMRF_LookStyle = 1ULL << 7;
	static const unsigned __int64 eMRF_DesiredLean = 1ULL << 8;
	static const unsigned __int64 eMRF_DesiredPeekOver = 1ULL << 9;
	static const unsigned __int64 eMRF_ActorTarget = 1ULL << 10;
	static const unsigned __int64 eMRF_FireTarget = 1ULL << 11;
	static const unsigned __int64 eMRF_PseudoSpeed = 1ULL << 12;
	static const unsigned __int64 eMRF_Prediction = 1ULL << 13;
	static const unsigned __int64 eMRF_ForcedNavigation = 1ULL << 14;
	static const unsigned __int64 eMRF_BodyTarget = 1ULL << 15;
	static const unsigned __int64 eMRF_InflectionPoint = 1ULL << 16;
	static const unsigned __int64 eMRF_Context = 1ULL << 17;
	static const unsigned __int64 eMRF_DesiredBodyDirectionAtTarget = 1ULL << 18;
	static const unsigned __int64 eMRF_RemoveLookTarget = eMRF_LookTarget << 31;
	static const unsigned __int64 eMRF_RemoveAimTarget = eMRF_AimTarget << 31;
	static const unsigned __int64 eMRF_RemoveDesiredSpeed = eMRF_DesiredSpeed << 31;
	static const unsigned __int64 eMRF_RemovEStance = eMRF_Stance << 31;
	static const unsigned __int64 eMRF_RemoveMoveTarget = eMRF_MoveTarget << 31;
	static const unsigned __int64 eMRF_RemoveDesiredLean = eMRF_DesiredLean << 31;
	static const unsigned __int64 eMRF_RemoveDesiredPeekOver = eMRF_DesiredPeekOver << 31;
	static const unsigned __int64 eMRF_RemoveActorTarget = eMRF_ActorTarget << 31;
	static const unsigned __int64 eMRF_RemoveFireTarget = eMRF_FireTarget << 31;
	static const unsigned __int64 eMRF_RemovePseudoSpeed = eMRF_PseudoSpeed << 31;
	static const unsigned __int64 eMRF_RemovePrediction = eMRF_Prediction << 31;
	static const unsigned __int64 eMRF_RemoveForcedNavigation = eMRF_ForcedNavigation << 31;
	static const unsigned __int64 eMRF_RemoveBodyTarget = eMRF_BodyTarget << 31;
	static const unsigned __int64 eMRF_RemoveInflectionPoint = eMRF_InflectionPoint << 31;
	static const unsigned __int64 eMRF_RemoveContext = eMRF_Context << 31;
	static const unsigned __int64 eMRF_RemoveDesiredBodyDirectionAtTarget = eMRF_DesiredBodyDirectionAtTarget << 31;



	inline void ClearFlag(MovementRequestFlags flag)
	{
		m_flags &= ~flag;
	}

	inline void SetFlag(MovementRequestFlags flag)
	{
		m_flags |= flag;
	}
	inline bool CheckFlag(MovementRequestFlags flag) const
	{
		return (m_flags & flag) != 0;
	}

	void SetLookTarget(const Vec3& position, float importance = 1.0f)
	{
		m_lookTarget = position;
		m_lookImportance = importance;
		SetFlag(eMRF_LookTarget);
		ClearFlag(eMRF_RemoveLookTarget);
	}

	void SetStance(EStance stance)
	{
		m_stance = stance;
		SetFlag(eMRF_Stance);
		ClearFlag(eMRF_RemovEStance);
	}

	void SetAimTarget(const Vec3& position)
	{
		m_aimTarget = position;
		SetFlag(eMRF_AimTarget);
		ClearFlag(eMRF_RemoveAimTarget);
	}

	void SetFireTarget(const Vec3& position)
	{
		m_fireTarget = position;
		SetFlag(eMRF_FireTarget);
		ClearFlag(eMRF_RemoveFireTarget);
	}




};




struct IMovementController {
public:
	void GetMovementState(SMovementState* state) {
		CallFunction<IMovementController* (__fastcall*)(PVOID64, SMovementState*)>(this, 0x10)(this, state);
	}
	void RequestMovement(CMovementRequest* mr) {
		CallFunction<void(__fastcall*)(PVOID64, CMovementRequest*)>(this, 8)(this, mr);
	}
	void UpdateMoveRequest(CMovementRequest* mr) {
		CallFunction<void(__fastcall*)(PVOID64, CMovementRequest*)>(this, 0x20)(this, mr);
	}
};

class IGameObject {
public:

	IMovementController* GetMovementController() {
		return CallFunction<IMovementController * (__thiscall*)(PVOID64)>(this, 0x1A8)(this);
	}

	IGameObject* ChangedNetworkState(unsigned int a1)
	{
		return CallFunction<IGameObject * (__thiscall*)(PVOID64, unsigned int)>(this, 0x20)(this, a1);
	}
	IGameObject* ChangedNetworkStateW(unsigned int a1)
	{
		return CallFunction<IGameObject * (__thiscall*)(PVOID64, unsigned int)>(this, 0x20)(this, a1);
	}
	IGameObject* SetAspectProfile(__int64 aspect, unsigned __int8 profile, bool fromNetwork)
	{
		return CallFunction<IGameObject * (__thiscall*)(PVOID64, __int64, unsigned __int8, bool)>(this, 0xA8)(this, aspect, profile, fromNetwork);
	}

	void InvokeRMI() {

	}

};

struct CBombFeedBack {
public:
	char pad_0x000[0xC];
	unsigned int bomb_Owner;

	using FN_Bo = void(__thiscall*)(CBombFeedBack*);

	void InitFromBombEntity() {
		FN_Bo(0x1412DDE20)(this);
	}

};

struct CGameFeedBack {
public:
	char pad_0x0000[0xE0];
	CBombFeedBack* m_pBombEvent;
	char pad_0x0001[0xD8];
	bool m_isClientPlayerAttacker;
	void SetClientAttacker()
	{
		*(bool*)((DWORD64)this + 0xD8) = false;
	}
};

class CAchievementsTracker {
private:
	using FN_Init = void(__thiscall*)(CAchievementsTracker*);
	using FN_SaveAchievements = void(__thiscall*)(CAchievementsTracker*);
	using FN_CAchievementsTracker = void(__thiscall*)(CAchievementsTracker*);
public:
	static void Init(CAchievementsTracker* m_achievementsTracker) {
		FN_Init(0x0000000141260140)(m_achievementsTracker);
	}
	static void SaveAchievements(CAchievementsTracker* m_achievementsTracker) {
		FN_SaveAchievements(0x00000001412602E0)(m_achievementsTracker);
	}
};

struct CGameRulesS
{
public:
	char pad_0x588[0x588];
	CRandomItemDropSystem* m_pRandomItemDropSystem;
};


struct SInstantAwardNotifications {
public:
	__int64 m_profileId;
	char pad_0x0000[0x6];
	void* m_awards;
};

struct CInstantAwardTracker {
public:
	char pad_0x0000[0x18];
	std::vector<SInstantAwardNotifications*> m_instantAwardNotifications;
};

struct CInstantAwardSystem {
public:
	char pad_0x0000[0x10];
	CInstantAwardTracker* m_pTracker;
};


class CMissionStatistics {
public:
};


class CGameRulesC {
public:
	char pad_0x3C0[0x3C0];
	CMissionStatistics* m_pMissionStatistics;
};

enum ECommunicationEvent : __int32
{
	eCE_None = 0x0,
	eCE_Quickchat_First = 0x1,
	eCE_SayNeedMedic = 0x1,
	eCE_SayNeedAmmo = 0x2,
	eCE_SayNeedArmor = 0x3,
	eCE_SayFollowMe = 0x4,
	eCE_SayCoverMe = 0x5,
	eCE_SayReady = 0x6,
	eCE_SayEnemySpotted = 0x7,
	eCE_SaySectorClear = 0x8,
	eCE_SayRegroup = 0x9,
	eCE_SayKeepMoving = 0xA,
	eCE_SayMoveOut = 0xB,
	eCE_SayFallBack = 0xC,
	eCE_SayAffirmative = 0xD,
	eCE_SayNegative = 0xE,
	eCE_SayEnemyDown = 0xF,
	eCE_SayTaunt = 0x10,
	eCE_Quickchat_AfterLast = 0x11,
	eCE_SayOverHere = 0x11,
	eCE_SendingEnemyCoord = 0x12,
	eCE_EnemySpotted = 0x13,
	eCE_ClaymoreSpotted = 0x14,
	eCE_GrenadeSpotted = 0x15,
	eCE_HelpToPush = 0x16,
	eCE_LiftMeOn = 0x17,
	eCE_FollowMe = 0x18,
	eCE_FireInTheHole = 0x19,
	eCE_FlagPickup = 0x1A,
	eCE_FlagDrop = 0x1B,
	eCE_FlagReturn = 0x1C,
	eCE_CaptureStart = 0x1D,
	eCE_CaptureEnd = 0x1E,
	eCE_BombPickup = 0x1F,
	eCE_BombDrop = 0x20,
	eCE_BombDropManual = 0x21,
	eCE_BombPlant = 0x22,
	eCE_BombDefuse = 0x23,
	eCE_StopBombDefuse = 0x24,
	eCE_EnemyDown = 0x25,
	eCE_DeathRattle = 0x26,
	eCE_OutOfAmmo = 0x27,
	eCE_TakeAmmo = 0x28,
	eCE_ResupplyAmmo = 0x29,
	eCE_ResupplyMedkit = 0x2A,
	eCE_ResupplyWeapons = 0x2B,
	eCE_HealingSelf = 0x2C,
	eCE_RepairingSelf = 0x2D,
	eCE_HealingTeammate = 0x2E,
	eCE_RepairingTeammate = 0x2F,
	eCE_BeingHealed = 0x30,
	eCE_BeingRepaired = 0x31,
	eCE_ImDown = 0x32,
	eCE_SniperSpotted = 0x33,
	eCE_SoldierSpotted = 0x34,
	eCE_ShieldBearerSpotted = 0x35,
	eCE_IronManSpotted = 0x36,
	eCE_SniperDown = 0x37,
	eCE_SoldierDown = 0x38,
	eCE_ShieldBearerDown = 0x39,
	eCE_IronManDown = 0x3A,
	eCE_EnemyDamaged = 0x3B,
	eCE_PickedReward = 0x3C,
	eCE_PickedScore = 0x3D,
	eCE_PickedIngameCurrency = 0x3E,
	eCE_ClassSelectedIngame = 0x3F,
	eCE_TeammateProtected = 0x40,
	eCE_CoreStartUse = 0x41,
	eCE_AIKnockBack = 0x42,
	eCE_PlayerEnteredSession = 0x43,
	eCE_PlayerLeftSession = 0x44,
	eCE_Last = 0x45,
};

struct CGameRules {
	char pad_0x18[24];
	IGameObject* m_pGameObjcet;
	char pad_0x2F8[760];
	CGameFeedBack* m_pFeedBack;

	void SendCommunicationEvent(int playerId, ECommunicationEvent events, int entityId = 0) {
		CallFunction<int(__thiscall*)(PVOID64, ECommunicationEvent, int source, int target, const char*, int)>(this, 0x2E8)(this, events, playerId, entityId, 0, 0);
	}

	int GetHitMaterialId(const char* materialName) { return CallFunction<int(__thiscall*)(PVOID64, const char*)>(this, 0x3A8)(this, materialName); }

	CAchievementsTracker* m_achievementsTracker() {
		return *(CAchievementsTracker**)((DWORD64)this + 0x3B8);
	}

	void Restart() {
		CallFunction<void(__thiscall*)(PVOID64)>(this, 0x4B0)(this);
	}
	using FN_Shutdown = void(__thiscall*)(CGameRules*);
	using FN_Shutdown2 = void(__thiscall*)(CGameRules*);

	void ResetRound() {
		FN_Shutdown(0x140FC4240)(this);
	}

	void Reset() {
		//140FC8910
		FN_Shutdown2(0x140FC8910)(this);
	}

	void ResetGameTime() {
		//140FC8910
		FN_Shutdown2(0x140FBEC80)(this);
	}

	void ResetRoundEntities() {
		FN_Shutdown2(0x140FC4320)(this);
	}


	void SetTeam() {
		CallFunction<void(__thiscall*)(PVOID64, int, int)>(this, 0x350)(this, 1, 1);
	}

	int GetHitTypeId(const char* name) {
		return CallFunction<int(__thiscall*)(PVOID64, const char*)>(this, 0x148)(this, name);
	}
	bool IsPostGame() {
		return CallFunction<bool(__thiscall*)(PVOID64)>(this, 0x1D0)(this);
	}



	CPTBGameRules* GetCPTBGameRules() {
		return *(CPTBGameRules**)((DWORD64)this + 0x428);
	}
    CInstantAwardSystem* m_pInstantAwardSystem() {
		return *(CInstantAwardSystem**)((DWORD64)this + 1048);
	}

	//CGameFeedBack* GetFeedBack() {
	//	return *(CGameFeedBack**)((DWORD64)this + 0x2F8);
	//}

};

struct INetChannel {
public:
	__int64 GetProfileId() {

		typedef __int64(__thiscall* INetChannelGetProfileId)(PVOID);
		return CallFunction<INetChannelGetProfileId>(this, 0x138)(this);


		//return CallFunction<__int64(__thiscall*)(PVOID64)>(this, 0x138)(this);
	}

	void Disconnect(int cause, const char* message) {
		CallFunction<void(__fastcall*)(PVOID64, int, const char*)>(this, 0x50i64)(this, cause, message);
	}


};



class CGameServerChannel
{
public:
	INetChannel* GetNetChannel() {
		//0x260i64
		
		return CallFunction<INetChannel*(__thiscall*)(PVOID64)>(this, 0x260)(this);

		//return m_pNetChannel;
	}
private:
	char pad_0x0000[0x8];
	INetChannel* m_pNetChannel;
};



typedef std::map<unsigned __int16, CGameServerChannel*> TServerChannelMap;


struct CVehicleSeat {
public:
	char pad_0x0000[0x18];
	IGameObject* p_mObject;
};

struct CVehicle {
public:
	char pad_0000[0x1B8];
	CVehicleSeat* m_pVehicleSeat;
};

struct CVehicleSystem {
public:
	char pad_0000[8];
	CVehicle* m_pVehicle;
};

struct CGameObj {
public:
	__int16 GetChannelId() {
		return CallFunction<__int16(__thiscall*)(PVOID64)>(this, 0x68)(this);
	}
};

struct IEntityArchetype {
public:

};

struct ÑSkeletonPose {
public:
	QuatT& GetAbsJointID(int nJointID) { return CallFunction<QuatT & (__thiscall*)(PVOID, int)>(this, 0x38)(this, nJointID); }
	short GetJointIdName(const char* sz_joint_name) { return CallFunction<short(__fastcall*)(PVOID, const char*)>(this, 0x18)(this, sz_joint_name); }
};

struct CryCharAnimationParams {
public:
	float m_fTransTime;
	float m_fKeyTime;
	float m_fPlaybackSpeed;
	float m_fAllowMultilayerAnim;
	int m_nLayerID;
	float m_fLayerWeight;
	unsigned int m_nFlags;
	__int16 m_nSubStateAAC;
	__int16 m_nIndexAAC;
	unsigned int m_nUserToken;
	unsigned int m_nAnimActionToken;
	float m_fUserData[8];
};



struct ISkeletonAnim {
private:
	enum CA_AnimationFlags : __int32
	{
		CA_MANUAL_UPDATE = 0x1,
		CA_LOOP_ANIMATION = 0x2,
		CA_REPEAT_LAST_KEY = 0x4,
		CA_TRANSITION_TIMEWARPING = 0x8,
		CA_START_AT_KEYTIME = 0x10,
		CA_START_AFTER = 0x20,
		CA_IDLE2MOVE = 0x40,
		CA_ALLOW_ANIM_RESTART = 0x80,
		CA_KEYFRAME_SAMPLE_30Hz = 0x100,
		CA_DISABLE_MULTILAYER = 0x200,
		CA_FORCE_SKELETON_UPDATE = 0x400,
		CA_TRACK_VIEW_EXCLUSIVE = 0x800,
		CA_SUPPRESS_WARNINGS = 0x1000,
		CA_MOVE2IDLE = 0x2000,
		CA_REMOVE_FROM_FIFO = 0x4000,
		CA_FULL_ROOT_PRIORITY = 0x8000,
		CA_PLAY_ON_DEDICATED_SERVER = 0x10000,
		CA_FORCE_TRANSITION_TO_ANIM = 0x10000,
		CA_CONTROL_CAMERA = 0x20000,
	};

public:
	void StartAnimation(const char* animation) {
		CryCharAnimationParams params;
		params.m_nLayerID = 0;
		params.m_nFlags = CA_LOOP_ANIMATION;
		params.m_fTransTime = 0.2f;
		CallFunction<void(__fastcall*)(PVOID64, const char*, CryCharAnimationParams* params)>(this, 0x48)(this, animation, &params);
	}
};

struct ICharacterInstance {
public:
	ÑSkeletonPose* GetISkeletonPose() { return CallFunction<ÑSkeletonPose * (__thiscall*)(void*)>(this, 0x28)(this); }
	ISkeletonAnim* GetISkeletonAnim() {
		return CallFunction<ISkeletonAnim * (__thiscall*)(void*)>(this, 0x20)(this);
	}
};



struct CEntityClass {
public:
	const char* Name()
	{
		return CallFunction<const char* (__fastcall*)(PVOID)>(this, 0x10)(this);
	}
};



typedef Ang3_tpl<float> Ang3;

struct pe_action
{
	int type;
};

struct pe_action_move : pe_action
{
	Vec3 dir;
	Vec3 velGround;
	int iJump;
	float dt;
};

struct pe_action_set_velocity : pe_action
{
	int ipart;
	int partid;
	Vec3_tpl<float> v;
	Vec3_tpl<float> w;
	int bRotationAroundPivot;
};



struct pe_params
{
	int type;
};


struct pe_player_dynamics : pe_params
{
	float kInertia;
	float kInertiaAccel;
	float kAirControl;
	float kAirResistance;
	Vec3_tpl<float> gravity;
	float nodSpeed;
	int bSwimming;
	float mass;
	int surface_idx;
	float minSlideAngle;
	float maxClimbAngle;
	float maxJumpAngle;
	float minFallAngle;
	float maxVelGround;
	float timeImpulseRecover;
	int collTypes;
	void* pLivingEntToIgnore;
	void* pCinematicPlatform;
	int bNetwork;
	int bActive;
	int iRequestedTime;
};


struct IPhysicalEntity {
public:
	void Action(pe_action* action, int q = 0) {
		CallFunction<void(__fastcall*)(PVOID64, pe_action*, int)>(this, 0x50)(this, action, q);
	}
	void SetParams(pe_params* params, int q = 0) 
	{
		CallFunction<void(__fastcall*)(PVOID64, pe_params*, int)>(this, 0x38)(this, params, q);
	}
};

struct pe_params_particle {

};
struct pe_params_buoyancy {

};



struct pe_player_dimensions : pe_params 
{
	float heightPivot;
	float heightEye;
	Vec3_tpl<float> sizeCollider;
	float heightCollider;
	float headRadius;
	float heightHead;
	Vec3_tpl<float> dirUnproj;
	float maxUnproj;
	int bUseCapsule;
};
struct pe_params_car {

};

struct SEntityPhysicalizeParams
{
	int type;
	int nSlot;
	float density;
	float mass;
	int nFlagsAND;
	int nFlagsOR;
	int nLod;
	void* pAttachToEntity;
	int nAttachToPart;
	float fStiffnessScale;
	bool bCopyJointVelocities;
	bool bExcludeFromAINavigation;
	pe_params_particle* pParticle;
	pe_params_buoyancy* pBuoyancy;
	pe_player_dimensions* pPlayerDimensions;
	pe_player_dynamics* pPlayerDynamics;
	pe_params_car* pCar;
	void* pAreaDef;
	const char* szPropsOverride;
};

struct M_PEntity {
public:
	Ang3* GetWorldAngles(Ang3* result) {
		return CallFunction<Ang3 * (__thiscall*)(PVOID64, Ang3*)>(this, 0x110)(this, result);
	}

	IPhysicalEntity* GetPhysics() {
		return CallFunction<IPhysicalEntity * (__thiscall*)(PVOID64)>(this, 0x1F8)(this);
	}

	void SetScale(Vec3 scale) {
		CallFunction<void(__thiscall*)(PVOID, Vec3)>(this, 0xF8)(this, scale);
	}

	void Physicalize(SEntityPhysicalizeParams* mParams) {
		CallFunction<void(__thiscall*)(PVOID, SEntityPhysicalizeParams*)>(this, 0x1F0)(this, mParams);
	}

	void Move(Vec3 pos, Ang3 a3) {

		CallFunction<void(__fastcall*)(PVOID64, Vec3*, Ang3*)>(this, 0x420)(this, &pos, &a3);
	}

	void SetWorldTM(Matrix34 set, int q) {
		//0xA8
		CallFunction<void(__fastcall*)(PVOID, Matrix34, int)>(this, 0xA8)(this, set, q);
	}

	ICharacterInstance* GetCharacter(int nSlot) { return CallFunction<ICharacterInstance * (__thiscall*)(PVOID64, int)>(this, 0x298)(this, nSlot); }

	CEntityClass* GetClass()
	{
		return CallFunction<CEntityClass*(__fastcall*)(PVOID)>(this, 0x18)(this);
	}

	int Id()
	{
		return CallFunction<int(__fastcall*)(PVOID)>(this, 0x8)(this);
	}

	IEntityArchetype* GetAcrhetype()
	{
		return CallFunction<IEntityArchetype*(__fastcall*)(PVOID64)>(this, 0x20)(this);
	}

	Quat GetViewRotation()
	{
		return CallFunction<Quat(__fastcall*)(PVOID64)>(this, 0xF0)(this);
	}
	const char* GetName()
	{
		return CallFunction<const char* (__fastcall*)(PVOID64)>(this, 0x60)(this);
	}

	Matrix34& GetWorldTM()
	{
		return CallFunction<Matrix34 & (__thiscall*)(PVOID64)>(this, 0xB8)(this);
	}

	void SetPos(Vec3 p) {
		CallFunction<void(__fastcall*)(PVOID, Vec3, INT64)>(this, 0xD8)(this, p, 0);
	}

	

	void SetRotation(Quat_tpl<float> p) 
	{
		CallFunction<void(__fastcall*)(PVOID, Quat_tpl<float>, INT64)>(this, 0xE8)(this, p, 0);
	}

	

	Vec3_tpl<float> GetPlayerPos(M_PEntity* pEntit) {
		Vec3_tpl<float> vOffset = Vec3_tpl<float>();
		Matrix34_tpl<float> pWorld = pEntit->GetWorldTM();
		vOffset = pWorld.GetTranslation();
		return vOffset;
	}
};


static Vec3 GetBonePosID(M_PEntity* pExp, ÑSkeletonPose* m_pSkeleton, int vBoneId)
{
	return pExp->GetWorldTM() * m_pSkeleton->GetAbsJointID(vBoneId).t;
}



struct CWeaponVisitor {
public:

};

struct CWeaponParameters
{
public:

};

struct CWeapon {
public:
	void StartFire() { CallFunction<void(__fastcall*)(PVOID64)>(this, 0x58)(this); }
	void StopFire() { CallFunction<void(__fastcall*)(PVOID64)>(this, 0x60)(this); }
	void SetFirePos(Vec3& vPosition) { CallFunction<void(__fastcall*)(PVOID64, Vec3&)>(this, 0x2F0)(this, vPosition); }

};

struct SvRequestShootHit {
	struct RequestHit {
		RequestHit(int targetId, int material, int type, int partId, Vec3 pos, float damageReduction, char physCounter)
			: targetId(targetId), material(material), typeId(type), partId(partId), pos(pos), damageReduction(damageReduction), physCounter(physCounter) {
		}
		int targetId; // 0x00
		int material; // 0x04
		int typeId; // 0x08
		int partId; // 0x0C
		Vec3 pos; // 0x10
		float damageReduction; // 0x1C
		char physCounter; // 0x20
	};

								int shooterId; // 0x00
								int targetId; // 0x04
								int material; // 0x08
								int typeId; // 0x0C
								int partId; // 0x010
								Vec3 pos; // 0x12
								float damageReduction; // 0x1C
								char physCounter; // 0x20

	//Vec3 shootPos; // 0x00
	//int predictionHandle; // 0x0C
	//Vec3 dir; // 0x10
	//char physCounter; // 0x1C
	//std::vector<std::pair<int, std::vector<RequestHit>>> projectiles; // 0x20
	//char fireCounter; // 0x38
	//float spreadMax; // 0x3C
	//char b_0x40; // 0x40
	//char pad_0x41[7]; // 0x41
	//__int64 prevTimestamp; // 0x48
	//__int64 timestamp; // 0x50
	//int dw_0x58; // 0x58
	//int pAmmoCount; // 0x5C
	//char pad_0x000[8]; //0x60
	//BYTE bFromRemote; //0x68
};
static SvRequestShootHit request;

inline void clear(const Vec3& vecShootingPosition, uint8_t ActorHit) {

	//for (auto it = request.projectiles.begin(); it != request.projectiles.end(); ++it) it->second.clear();
	//	request.projectiles.clear();
	//
	//request.shootPos = vecShootingPosition;
	//request.physCounter = ActorHit;
	//request.dw_0x58 = 1;
	//request.dir = request.vDirFire = { 0, 0, 1 };
}

inline void AddProjectile(std::vector<SvRequestShootHit::RequestHit> hits) {

	//request.pAmmoCount = 1;
	//request.projectiles.push_back({ 1, hits });
	//request.bFromRemote = TRUE;
}

template <class CVirtualAddres> CVirtualAddres pVirtualHookAddr(uintptr_t Address) {
	return (CVirtualAddres)(Address);
}






struct CWeaponView {
public:
	CWeapon* GetIWeapon() {
		return *(CWeapon**)((DWORD64)this + 0x10);
	}

};

struct CWeaponGeneral {
public:
	bool IsZooming() {
		uintptr_t state = *(uintptr_t*)((uintptr_t)this + 0x118);
		return (EWeaponStates)state == EWeaponStates::eWS_IdleZoomed
			|| (EWeaponStates)state == EWeaponStates::eWS_ZoomedFire
			|| (EWeaponStates)state == EWeaponStates::eWS_ZoomIn
			|| (EWeaponStates)state == EWeaponStates::eWS_ZoomOut
			|| (EWeaponStates)state == EWeaponStates::eWS_ZoomInFire
			|| (EWeaponStates)state == EWeaponStates::eWS_ZoomOutFire;
	}
	CWeaponParameters* GetWeaponParams()
	{
		return *(CWeaponParameters**)((DWORD64)this + 0xC0);
	}
	CWeaponView* GetWeaponView() {
		return CallFunction<CWeaponView*(__thiscall*)(PVOID64)>(this, 0)(this);
	}
};

struct CGameObject {
public:

};

struct IItem {
public:
	CGameObject* GetGameObject() {
		return *(CGameObject**)((DWORD64)this + 0x18);
	}
	auto GetWeapon()
	{
		return CallFunction<CWeapon * (__fastcall*)(PVOID)>(this, 0x280)(this);
		//return *(CWeapon**)((DWORD64)this + 0x24);//0x280
	}
	auto GetWeaponGeneral()
	{
		return *(CWeaponGeneral**)((DWORD64)this + 0x30);
	}
	auto GetEntity() 
	{ 
		return *(M_PEntity**)((DWORD64)this + 0x10);
	}
};

inline void RequestShootHit(IItem* pItem)
{
	if (pItem)
	{
		pVirtualHookAddr<void(__stdcall*)(CGameObject*, void*, SvRequestShootHit*, __int32, __int32)>(0x1414B2760)(pItem->GetGameObject(), *(void**)0x14252E988, &request, 256, -1);
	}
}

struct CFFPlayer {
public:
	char pad_0x0000[0x94]; // 0x0000
	Quat m_viewQuatFinal; //0x0094
};



struct IActorVVVV {
public:
	auto GetEntity()
	{
		return *(M_PEntity**)((DWORD64)this + 0x10);
	}
	int Health() {
		return CallFunction<int(__thiscall*)(PVOID64)>(this, 0xE0)(this);
	}
	bool IsDead() {
		return Health() <= 0;
	}
};



struct CPlayerStats {
public:
	char pad_0xD4[0xC2];
	bool isSliding;
	/*float inMovement;
	float inRest;
	Vec3_tpl<float> stationaryPos;
	float stationaryTime;
	bool tryingToMove;
	bool landed;
	bool jumped;
	bool wasStuck;
	bool wasFlying;
	float stuckTimeout;
	bool transitionAnimationInProgress;
	float jumpLock;
	void* heightPivot;
	void* heightCollider;
	void* sizeCollider;
	float fallSpeed;
	float fallVelocityLastFrame;
	float fallVelocity;
	bool isFiring;
	void* followCharacterHead;
	bool isStandingUp;
	void* firstPersonBody;
	void* groundNormal;
	void* angularVel;
	void* angularImpulse;
	float angularImpulseDeceleration;
	float angularImpulseTime;
	float angularImpulseTimeMax;
	bool isInTrigger;
	bool isInHaste;
	bool isSliding;
	bool isVaulting;
	Quat_tpl<float> playerRotation;
	bool bSprinting;
	bool bProneCrouchFPFix;
	bool bLightWeaponOnly;
	bool bAllowItemPickup;
	bool bDisablePickup;
	void* isPushing;
	bool setPushFinalStance;
	Vec3_tpl<float> sustainedVelocity;
	bool bAlignChatToPt;
	int alignX;
	int alignY;
	unsigned int cameraId;
	bool useHasteFastAccelMult;
	bool canRaiseWeapon;
	void* reviveTime;
	int viewID;
	float distNearClipPlane;*/
};


enum ESMType : __int32
{
	eSMT_None = 0xFFFFFFFF,
	eSMT_Haste = 0x0,
	eSMT_Climb = 0x1,
	eSMT_Slide = 0x2,
	eSMT_KnockBack = 0x3,
	eSMT_RaiseAssist = 0x4,
	eSMT_Vault = 0x5,
	eSMT_CoopCinematic = 0x6,
	eSMT_CoopClimb = 0x7,
	eSMT_CoopAssist = 0x8,
	eSMT_InteractionAction = 0x9,
	eSMT_HoldEntity = 0xA,
	eSMT_NumSpecialMoves = 0xB,
};

enum EPlayerStance : __int32
{
	ePS_Stand = 0x0,
	ePS_Crouch = 0x1,
	ePS_Prone = 0x2,
	ePS_Walk = 0x3,
	ePS_Run = 0x4,
	ePS_Haste = 0x5,
	ePS_Slide = 0x6,
	ePS_Last = 0x6,
};

struct CPlayerV3 {
public:
	char pad_0x0000[0xe0];
	EStance m_state;
};

struct CPlayerFeedBack {
public:
	char pad_0x0028[0x28];
	EPlayerStance m_CurrentStance;
};

enum ECharacterClassId : __int32
{
	eCCI_First = 0x0,
	eCCI_Rifleman = 0x0,
	eCCI_Heavy = 0x1,
	eCCI_Recon = 0x2,
	eCCI_Medic = 0x3,
	eCCI_Engineer = 0x4,
	eCCI_Count = 0x5,
	eCCI_Other = 0xFFFFFFFF,
};





struct CKillStats {
public:
	char pad_0x90[0x90];
	bool is_jumped;
};

enum EUpdateMode {

};

struct CSpecialMoveClass {
public:
	ESMType m_type;
	const char* m_name;
	EUpdateMode m_updateMode;
	void* m_pClassExt;
};

struct CSpecialMovementController {
public:
	char pad_0x0038[0x38];
	CSpecialMoveClass* class_;

	bool RequestMovement(CMovementRequest* req) {
		typedef bool(__thiscall* RequestMovement)(PVOID, CMovementRequest*);
		return CallFunction<RequestMovement>(this, 8)(this, req);
	}

};

struct CPlayerStatistics {
public:
	char pad_0x1000[0x1000];
	CSpecialMovementController* m_pController;

};

struct PlayerAnimation {
public:

};

struct ActorInventory {

};

enum EActorTargetPhase
{
	eATP_None,
	eATP_Waiting,
	eATP_Starting,
	eATP_Started,
	eATP_Playing,
	eATP_StartedAndFinished,
	eATP_Finished,
	eATP_Error,
};


enum ERequestedGrenadeType
{
	eRGT_INVALID = -1,

	eRGT_ANY,
	eRGT_SMOKE_GRENADE,
	eRGT_FLASHBANG_GRENADE,
	eRGT_FRAG_GRENADE,
	eRGT_EMP_GRENADE,

	eRGT_COUNT,
};

enum EAIFireState
{
	eAIFS_Off = 0,
	eAIFS_On,
	eAIFS_Blocking,	// Fire command handler is doing extra work and is not ready to fire yet

	eAIFS_COUNT,
};





struct SFireCommandProjectileInfo
{
	unsigned int trackingId;
	float fSpeedScale;
};

struct SAIPredictedCharacterState
{
	Vec3 position;
	Vec3 velocity;
	float predictionTime; // Time of prediction relative to when it was made.
};

struct SAIPredictedCharacterStates
{
	SAIPredictedCharacterState states[32];
	int nStates;
};

const struct SAIActorTargetRequest
{
	int id;
	Vec3 approachLocation;
	Vec3 approachDirection;
	Vec3 animLocation;
	Vec3 animDirection;
	char* vehicleName;
	int vehicleSeat;
	float speed;
	float directionTolerance;
	float startArcAngle;
	float startWidth;
	bool signalAnimation;
	bool projectEndPoint;
	bool lowerPrecision;
	bool useAssetAlignment;
	char* animation;
	EStance stance;
	unsigned int* pQueryStart;
	unsigned int* pQueryEnd;
};

enum EAITargetType
{
	// Atomic types.
	AITARGET_NONE,				// No target.
	AITARGET_SOUND,				// Primary sensory from sound event.
	AITARGET_MEMORY,			// Primary sensory from vis event, not visible.
	AITARGET_VISUAL,			// Primary sensory from vis event, visible.

	// Backwards compatibility for scriptbind.
	AITARGET_ENEMY,
	AITARGET_FRIENDLY,
	AITARGET_BEACON,
	AITARGET_GRENADE,
	AITARGET_RPG,

	// For serialization.
	AITARGET_LAST
};

enum EAITargetThreat
{
	AITHREAT_NONE,
	AITHREAT_SUSPECT,
	AITHREAT_INTERESTING,
	AITHREAT_THREATENING,
	AITHREAT_AGGRESSIVE,
	AITHREAT_LAST	// For serialization.
};

enum EAITargetContextType
{
	// Atomic types.
	AITARGET_CONTEXT_UNKNOWN,				// No specific subtype.
	AITARGET_CONTEXT_GUNFIRE,				// Gunfire subtype.

	// For serialization.
	AITARGET_CONTEXT_LAST
};

typedef unsigned __int32	tAIObjectID;

enum EAITargetStuntReaction
{
	AITSR_NONE,
	AITSR_SEE_STUNT_ACTION,
	AITSR_SEE_CLOAKED,
	AITSR_LAST
};

struct 	SOBJECTSTATE {
	bool jump;
	bool aimObstructed;
	bool aimTargetIsValid;
	bool forceWeaponAlertness;
	EAIFireState fire;
	EAIFireState fireSecondary;
	EAIFireState fireMelee;
	ERequestedGrenadeType requestedGrenadeType;
	int weaponAccessories;
	int bodystate;
	float lean;
	float peekOver;
	float fHitProbability;
	Vec3_tpl<float> vShootTargetPos;
	Vec3_tpl<float> vAimTargetPos;
	Vec3_tpl<float> vLookTargetPos;
	SFireCommandProjectileInfo projectileInfo;
	ELookStyle eLookStyle;
	Vec3_tpl<float> vMoveDir;
	Vec3_tpl<float> vForcedNavigation;
	Vec3_tpl<float> vBodyTargetDir;
	Vec3_tpl<float> vDesiredBodyDirectionAtTarget;
	float fForcedNavigationSpeed;
	unsigned int movementContext;
	SAIPredictedCharacterStates predictedCharacterStates;
	Vec3_tpl<float> vMoveTarget;
	Vec3_tpl<float> vInflectionPoint;
	float fMovementUrgency;
	float fDesiredSpeed;
	bool allowStrafing;
	bool allowEntityClampingByAnimation;
	void* remainingPath;
	float fDistanceToPathEnd;
	EActorTargetPhase curActorTargetPhase;
	Vec3_tpl<float> curActorTargetFinishPos;
	SAIActorTargetRequest actorTargetReq;
	bool bCloseContact;
	bool bHurryNow;
	bool bReevaluate;
	bool bTargetEnabled;
	bool bTargetIsGroupTarget;
	bool continuousMotion;
	EAITargetType eTargetType;
	EAITargetContextType eTargetContextType;
	EAITargetThreat eTargetThreat;
	unsigned int eTargetID;
	EAITargetType ePeakTargetType;
	EAITargetThreat ePeakTargetThreat;
	unsigned int ePeakTargetID;
	EAITargetType ePreviousPeakTargetType;
	EAITargetThreat ePreviousPeakTargetThreat;
	unsigned int ePreviousPeakTargetID;
	Vec3_tpl<float> vTargetPos;
	float fDistanceFromTarget;
	EAITargetStuntReaction eTargetStuntReaction;
	int nTargetType;
	void* Signals;
	int nAuxSignal;
	char* szAuxSignalText;
	float fAuxDelay;
	int nAuxPriority;
	int secondaryIndex;
};

struct CPlayerV2 {
public:
	char pad_0x0000[0x94]; // 0x0000
	Quat m_viewQuatFinal; //0x0094
};

struct AnimationGraphState {
public:
	void SetInput(const char* name, float value)
	{
		unsigned __int8 id = GetInputId(name);
		SetInput(id, value);
	}

	void SetInput(const char* name, const char* value)
	{
		unsigned __int64 id = GetInputId(name);

		printf("%i\n", id);

		SetInput(id, value);
	}

	void SetInput(const char* name, bool value)
	{
		unsigned __int8 id = GetInputId(name);
		SetInput(id, value);
	}



	void SetInput(unsigned __int8 id, float value)
	{
		CallFunction<void(__fastcall*)(void*, unsigned __int8, float, void*)>(this, 8)(this, id, value, 0);
	}

	void SetInput(unsigned __int8 id, const char* value)
	{
		CallFunction<void(__fastcall*)(void*, unsigned __int8, const char*, void*)>(this, 8)(this, id, value, 0);
	}

	void SetInput(unsigned __int8 id, bool value)
	{
		CallFunction<void(__fastcall*)(void*, unsigned __int8, bool, void*)>(this, 8)(this, id, value, 0);
	}

	unsigned __int64 GetInputId(const char* name)
	{
		return CallFunction<unsigned __int64(__fastcall*)(PVOID64, const char*)>(this, 0xD8)(this, name);
	}
};

struct CPlayerAnimation {
	AnimationGraphState* GetAnimationGraphState() {
		return CallFunction<AnimationGraphState*(__fastcall*)(PVOID64)>(this, 0xC8)(this);
	}
};







struct CMovementController {
public:
	void Request(CMovementRequest* request) {
		CallFunction<PlayerAnimation* (__thiscall*)(PVOID64, CMovementRequest*)>(this, 8)(this, request);
	}
};

struct CBodyAttractor {
public:
	char pad_0x0000[0x10];
	Vec3_tpl<float> m_pPos;
};

struct CPlayer 
{
public:
	char pad_0xe0[0xE0];
	int m_state;

	//0x3A8

	CMovementController* MoveController() {
		return *(CMovementController**)((DWORD64)this + 0x3A8);
	}

	CBodyAttractor* GetBodyAtractor() {
		return *(CBodyAttractor**)((DWORD64)this + 0x1390);
	}

	CPlayerV2* GetPlayerV2() {
		return(CPlayerV2*)*(DWORD*)((DWORD)this + 0xD80);
	}

	CPlayerAnimation* GetPlayerAnimation() {
		return(CPlayerAnimation*)*(DWORD*)((DWORD)this + 0x1388);
	}

	void SetAGInput() {

	}


	SOBJECTSTATE m_State0;

	

	__int8 HitGett() { return *(__int8*)((DWORD64)this + 0xCE4); }//m_pPhysCounter

	IGameObject* GetObjectAI() {
		return *(IGameObject**)((DWORD64)this + 0x18);
	}

	ActorInventory* GetInventory() {
		return *(ActorInventory**)((DWORD64)this + 0x408);
	}

	PlayerAnimation* GetAnimation() {
		return CallFunction<PlayerAnimation*(__thiscall*)(PVOID64)>(this, 664)(this);
	}


	bool is_jumped;
	bool is_sliding;

	bool IsSlide() {
		return *(bool*)((DWORD64)this + 0xE6F); //0xE6F
	}

	int Health() {
		return CallFunction<int(__thiscall*)(PVOID64)>(this, 0xE0)(this);
	}

	int Armor() {
		return CallFunction<int(__thiscall*)(PVOID64)>(this, 0x108)(this);
	}

	void SetHealth(int setHealth) {
		CallFunction<void(__thiscall*)(PVOID64, int)>(this, 0xE8)(this, setHealth);
	}

	void SetArmor(int setArmor) {
		CallFunction<void(__thiscall*)(PVOID64, int)>(this, 0x4D0)(this, setArmor);
	}

	bool IsDead() {
		return Health() <= 0;
	}

	CSpecialMovementController* GetMovementController() 
	{
		return CallFunction<CSpecialMovementController*(__fastcall*)(PVOID)>(this, 0x1F0)(this);
	}

	ECharacterClassId GetCurrentClassId() {
		return CallFunction<ECharacterClassId(__fastcall*)(PVOID)>(this, 0x3C8i64)(this);
		//return *(ECharacterClassId*)((DWORD64)this + 0x3C8);
	}

	CPlayerStatistics* GetStatistics() {
		return *(CPlayerStatistics**)((DWORD64)this);
	}

	EStance Stance() {
		return *(EStance*)((DWORD64)this + 0xE0);
	}
	//0xDA8
	//0x1290

	CPlayerFeedBack* GetPlayerFeedBack() {
		return *(CPlayerFeedBack**)((DWORD64)this + 0x1290);
	}


	int GetState()
	{
		return *(int*)((DWORD64)this + 4112);
	}

	CPlayerStats* GetPlayerStats() {
		return *(CPlayerStats**)((DWORD64)this + 0xDA8);
	}

	CFFPlayer* GetCFPlayer() {
		return *(CFFPlayer**)((DWORD64)this + 3456);
	}

	int GetSlideKillByPlayer() {
		return *(int*)((DWORD64)this + 4112);
	}

	
	void SetViewRotation(const Vector4& rot)
	{
		CallFunction<void(__thiscall*)(PVOID64, const Vector4&)>(this, 0x1A0)(this, rot);
	}

	int GetTeamId() {
		return *(int*)((DWORD64)this + 0x3E0);
	}


	M_PEntity* GetEntity()
	{
		return *(M_PEntity**)((DWORD64)this + 0x10);
	}

	IItem* GetCurrentItem(bool includeVehicle = false) {
		return CallFunction<IItem* (__fastcall*)(PVOID, bool)>(this, 0x1D0)(this, includeVehicle);
	}

};

struct CActorIterator {
public:
	CPlayer* Next() {
		return CallFunction<CPlayer * (__fastcall*)(PVOID)>(this, 8)(this);
	}
};

struct IActorSystem {
public:
	CPlayer* GetPlayer(unsigned int id)
	{
		return CallFunction<CPlayer * (__thiscall*)(PVOID64, unsigned int)>(this, 0x78)(this, id);
	}

	void GetActorIterator(CActorIterator** pIterators)
	{
		CallFunction<void(__thiscall*)(PVOID, CActorIterator**)>(this, 0x90)(this, pIterators);
	}

};



struct IGameR {
public:
	using FN_Shutdown2 = void(__fastcall*)(IGameR*);

	void InGame()
	{
		FN_Shutdown2(0x140FC8A30)(this);
	}
};



class CGameServerNub {
public:
	TServerChannelMap* GetServerChannelMap() {
		return &m_channels;
	}
private:
	char pad_0x0000[0x4];
	TServerChannelMap m_channels;
};

struct IGameFramework {
public:

	INetChannel* GetNetChannel() {
		return CallFunction<INetChannel * (__thiscall*)(PVOID64, unsigned __int16)>(this, 0x260)(this, 1);
	}

	CGameServerNub* GetServerNub()
	{
		return *(CGameServerNub**)((DWORD64)this + 0x50);
	}

	IActorSystem* GetActorSystem()
	{
		return CallFunction<IActorSystem * (__thiscall*)(PVOID64)>(this, 0xC8)(this);
	}

	IGameObject* GetGameObject(int eid) {
		return CallFunction<IGameObject * (__thiscall*)(PVOID64, int)>(this, 0x268)(this, eid);
	}


	IGameR* GetGameR()
	{
		return CallFunction<IGameR * (__thiscall*)(PVOID)>(this, 0x448)(this);
	}


	//char pad_0000[0x4B0];
	//CVehicle* m_pVehicle;
	char pad_0003[0x80F];
	bool m_bDedicatedServer;

	CVehicleSystem* GetVehicleS()
	{
		return *(CVehicleSystem**)((DWORD64)this + 0x4F0);
	}

	const char* GetLevelName() {
		return CallFunction<const char* (__fastcall*)(PVOID)>(this, 0x2F8)(this);
	}


	using FN_NetChannelGet = INetChannel * (__thiscall*)(IGameFramework*, __int16);

	//CVehicle* GetCVehicle() {
	//	0x4B0
	//}

	INetChannel* GetNetChannel(__int16 channedl_id) {

		//1404C00D0

		return CallFunction<INetChannel * (__thiscall*)(PVOID64, __int16)>(this, 0x260)(this, channedl_id);

		//return FN_NetChannelGet(0x1404C00D0)(this, channedl_id);


	}

	CPlayer* GetObservedPlayer()
	{
		CPlayer* pLocalActor = 0;
		bool bGetActorResult = CallFunction<bool(__fastcall*)(PVOID, CPlayer**)>(this, 0x480)(this, &pLocalActor);
		if (!bGetActorResult) pLocalActor = 0;
		return pLocalActor;
		//return CallFunction<CPlayer * (__thiscall*)(PVOID64, CPlayer**)>(this, 0x480)(this, bValue);
	}

	CGameRules* GetCurrentGameRules()
	{
		return CallFunction<CGameRules * (__fastcall*)(PVOID)>(this, 0x448)(this);
	}

	static IGameFramework* Singlenton()
	{
		return *(IGameFramework**)0x142512A58;
	}
};



class CMissionBackend {
private:
	using FN_GetRoomPlayer = bool(__fastcall*)(CMissionBackend*, unsigned __int64, SMasterServerRoomInfo::SRoomPlayer*);
public:
	static bool GetRoomPlayer(CMissionBackend* this1, unsigned __int64 profileId, SMasterServerRoomInfo::SRoomPlayer* player) {
		return FN_GetRoomPlayer(0x0000000141271E60)(this1, profileId, player);
	}
};

struct SMasterServerInfo {
public:
	char pad_0x10[0x10];
	char session_id;

	enum EStatus : __int32 {
		None,
		SolidColor = 1,
		Texture = 2,
		GlyphTexture = 3,
		GlyphAlphaTexture = 4,
		GlyphTextureYUV = 5,
		GlyphTextureYUVA = 6,
		G1Texture = 8,
		G1TextureColor = 9,
	};
};


class CMasterServerList {
private:
	using FN_ServerCount = signed __int64(__thiscall*)(CMasterServerList*);
	using FN_FindServer = signed __int64(__thiscall*)(CMasterServerList*, SMasterServerInfo::EStatus);
	using FN_GetServer = SMasterServerInfo * (__thiscall*)(CMasterServerList*, unsigned __int64);
public:
	static signed __int64 ServerCount(CMasterServerList* serverList) {
		return FN_ServerCount(0x000000014106A660)(serverList);
	}
	static signed __int64 FindServer(CMasterServerList* serverList, SMasterServerInfo::EStatus status) {
		return FN_FindServer(0x000000014106A730)(serverList, status);
	}
	static SMasterServerInfo* GetServer(CMasterServerList* serverList, unsigned __int64 i) {
		return FN_GetServer(0x000000014106A690)(serverList, i);
	}
};

class SDedicatedMSPickPolicy {
private:
	using FN_Operator = signed __int64(__thiscall*)(SDedicatedMSPickPolicy*, CMasterServerList*);
public:
	static signed __int64 Operator(SDedicatedMSPickPolicy* this1, CMasterServerList* servers) {
		return FN_Operator(0x000000014106A950)(this1, servers);
	}
};

class SLoadBalancingStrategy {
public:
	Functor2<char const*, unsigned short>* m_getMasterServerCallback = nullptr;
	Functor2<enum EOnlineError, int>* m_getMasterServerFailedCallback = nullptr;
};

class CBackend {
public:
	__int64 IOnlineQueryBinder()
	{
		return *(__int64*)((DWORD64)this + 200);
	}
};



struct CRemotePlayerInfo;

struct ICVar {
public:
	const char* GetString() {
		return CallFunction<const char* (__thiscall*)(PVOID64)>(this, 40)(this);
	}
};

struct SLobbyServerInfo;

struct SLobbyServerInfo
{
	char pad_0000[0x88];
	const char* sMasterServerResource;
};


class CAbstractServerInfo {
private:
	using FN_Update = void(__thiscall*)(CAbstractServerInfo*, bool);
public:
	/*	char pad_0000[56];
		int eStatus;

		char pad_003C[328];
		bool m_gameEnd;    */

	char pad_0185[329];
	bool m_telemetrySent;


	void SendServerInfo() {
		return CallFunction<void(__thiscall*)(PVOID64) >(this, 0x40)(this);
	}

	static void Update(CAbstractServerInfo* m_pServerInfo, bool isForceUpdate) {
		FN_Update(0x141512DB0)(m_pServerInfo, isForceUpdate);
	}
};

enum EGameEndReason : __int32
{
	eGER_Unknown = 0x0,
	eGER_Completed = 0x1,
	eGER_Failed = 0x2,
	eGER_Timelimit = 0x3,
	eGER_NotEnoughPlayers = 0x4,
	eGER_NoPlayers = 0x5,
	eGER_ModeratorStopSession = 0x6,
};

struct SPlayerScoresInfo {};
struct SPlayerPerformanceInfo {};


template <typename T>
class CryStringT {
public:

	struct StrHeader {
		volatile int nRefCount;
		int nLength;
		int nAllocSize;
	};

public:

	T* m_str;
	CryStringT<T>::StrHeader* m_header;
};
typedef CryStringT<char>    CryString;

struct SSessionRewardsInfo {
	std::map<int, std::vector<SPlayerScoresInfo, std::allocator<SPlayerScoresInfo> >, std::less<int>, std::allocator<std::pair<int const, std::vector<SPlayerScoresInfo, std::allocator<SPlayerScoresInfo> > > > > teamRewards;
	std::vector<SPlayerPerformanceInfo, std::allocator<SPlayerPerformanceInfo> > playersPerformances;
	CryStringT<char> missionId;
	bool incompleteSession;
	float sessionTime;
	unsigned int sessionKillCount;
	int winningTeamId;
	int maxSessionScore;
	int passedSublevelsCount;
	int passedCheckpointsCount;
	int totalPerformance;
	int totalPerformanceNotMultiplied;
	unsigned __int8 secondaryObjectivesCompleted;
	//public:
	//    using FN_SessionRewardsInfo = void(__thiscall*)(SSessionRewardsInfo**);
	//    static void SessionRewardsInfo(SSessionRewardsInfo** this1) {
	//        FN_SessionRewardsInfo(0x14149CDA0)(this1);
	//    }
};

class SSetRewardsInfoSerializer;




class CScoringConfig {
public:
	char pad_0x10[0x10];
	void* m_setRewardsInfoBinder;

	using FN_GetSessionRewardsInfo = void(__thiscall*)(CScoringConfig*, EGameEndReason, int, SSessionRewardsInfo*);
	static void GetSessionRewardsInfo(CScoringConfig* this1, EGameEndReason gameEndReason, int winningTeamId, SSessionRewardsInfo* result) {
		FN_GetSessionRewardsInfo(0x14149E7C0)(this1, gameEndReason, winningTeamId, result);
	}
};


struct CGameRulesEnd {
	char pad_0x18[0x500];
	CScoringConfig* m_pScoringConfig;
};



struct CMissionInfo {};

struct SCVars {
public:

	char none[2624];
	SCVars* online_dedicated_host_name;

	char none1[2360];
	SCVars* online_masterserver_resource;


	//SCVars* online_masterserver_resource() {
	//	return *(SCVars**)((DWORD64)this + 2360);
	//}

	//char none[0x968];
	//SCVars* online_dedicated_host_name;
	//
	//char nonez[0x98];
	//SCVars* online_splash;
	//
	//char nonezy[0x98];
	//SCVars* online_splashw;


	auto SetCvars(DWORD64 Offset, int Value)
	{
		*(int*)((DWORD64)this + Offset) = Value;
	}

	void Set(const char* name) {
		return CallFunction<void(__thiscall*)(PVOID64, const char*) >(this, 0x40)(this, name);
	}

	const char* GetString() {
		return CallFunction<const char* (__thiscall*)(PVOID64) >(this, 0x28)(this);
	}

	int g_VictoryCondition() {
		return *(int*)((DWORD64)this + 0x640);
	}

	static SCVars* Singlenton()
	{
		return *(SCVars**)0x142511DC0;
	}


};

class IConsole
{
public:
	static IConsole* GetInstance() {
		return *(IConsole**)0x141EE0E60;
	}

	SCVars* Register() {

	}

	SCVars* RegisterString(const char* sName, const char* sValue, int nFlags, const char* help, void(__cdecl* pChangeFunc)(SCVars*))
	{
		return CallFunction<SCVars * (__thiscall*)(PVOID64, const char*, const char*, int, const char*, void(__cdecl*)(SCVars*))>(this, 0x10)(this, sName, sValue, nFlags, help, pChangeFunc);
	}
	SCVars* RegisterInt(const char* sName, int sValue, int nFlags, const char* help, void(__cdecl* pChangeFunc)(SCVars*))
	{
		return CallFunction<SCVars * (__thiscall*)(PVOID64, const char*, int, int, const char*, void(__cdecl*)(SCVars*))>(this, 0x18)(this, sName, sValue, nFlags, help, pChangeFunc);
	}
	IConsole* ExecuteString(const char* a1, bool a2, bool a3) {
		return CallFunction<IConsole * (__thiscall*)(PVOID64, const char*, bool, bool) >(this, 0x118)(this, a1, a2, a3);
	}

	ICVar* GetCVar(const char* pName) { return CallFunction<ICVar * (__thiscall*)(PVOID64, const char*)>(this, 0xB8)(this, pName); }
};






class CClientSynchedStorage;

struct CBackendManager {
public:

};

struct CMissionApplyA {
public:
	using FN_Shutdown = void(__thiscall*)(CMissionApplyA*, CBackendManager);


	void SetMission() {
		CBackendManager ctx;

		FN_Shutdown(0x141258660)(this, ctx);
	}
};

struct CMissionSystem
{
public:
	char pad_0x0001[0x10];
	CMissionApplyA* m_Aply;
};


struct CGame_2 {
public:
	char pad_0x0000[0x190]; //0x01A0
	CAbstractServerInfo* m_pServerInfo;
	static CGame_2* Signlenton()
	{
		return (CGame_2*)*(__int64*)(0x142511DE0);
	}
};

struct CGame_1 {
public:
	char pad_0x0000[384];
	CBackend* m_pBackend;

	static CGame_1* Signlenton() {
		return (CGame_1*)*(__int64*)(0x142511DE0);
	}
};

struct CGame_3 {
public:
	void* fields[35]; // Ïîëÿ êëàññà (a1[34] = fields[34])

	int64_t CallFunction() {
		return reinterpret_cast<int64_t(__fastcall*)(CGame_3*)>(reinterpret_cast<int64_t>(this) + 112)(this);
	}
	static CGame_3* Signlenton()
	{
		return (CGame_3*)*(__int64*)(0x142511DE0);
	}
};


class CGame
{
public:
	char pad_0x0001[952];
	CMissionBackend* m_pMissionBackend;

	char pad_01A0[0x198];
	CAbstractServerInfo* m_pServerInfo;



	char pad_0x130[0x130];
	SCVars* m_pCVars;

	char pad_0x120[0x120];
	CClientSynchedStorage* m_pClientSynchedStorage;
	char pad_0003[0x80F];
	bool m_bDedicatedServer;

	IGameFramework* GetFramework() {
		return *(IGameFramework**)((DWORD64)this + 0x78);
	}

	IGameFramework* GetFramework_nonvtable() {
		return *(IGameFramework**)((DWORD64)this + 0x48);
	}

	COnlineAccount* GetAccount()
	{
		return *(COnlineAccount**)((DWORD64)this + 0x250);
	}

	static CGame* Signlenton()
	{
		return (CGame*)*(__int64*)(0x142511DE0);
	}



};

template <typename t>
t VIRTUAL(PVOID BASE, DWORD64 INDEX)
{
	return (*(t**)BASE)[INDEX];
}

struct IProcess {};

struct ISystemEventDispatcher {
public:
	void OnSystemEvent()
	{
		CallFunction<void(__fastcall*)(PVOID64, __int64, __int64)>(this, 0x18)(this, 20, 0);
	}
};

class IStreamEngine {
public:

};

struct CCamera {
public:
public:
	Vec3 GetViewPos() { return Vec3(mMatrix.m03, mMatrix.m13, mMatrix.m23); }
private:
	Matrix34 mMatrix;
	Matrix34_tpl<float> m_Matrix;
};

struct CSystem {
public:
	char pad_0x9A8[2472];
	IStreamEngine* m_pStreamEngine;

	CCamera* GetViewCamera()
	{
		return (CCamera*)((char*)this + 0x658);
	}

	using FN_Dev = void(__thiscall*)(CSystem*, bool);
	using FN_Shutdown = void(__thiscall*)(CSystem*);


	void ShutDown() {
		return FN_Shutdown(0x14030DB20)(this);
	}


	void SetDevMode() {
		return FN_Dev(0x1403117E0)(this, true);
	}

	void IsTestMode()
	{
		VIRTUAL<bool(__thiscall*)(PVOID, bool)>(this, 114)(this, true);
	}	
	IStreamEngine* GetStreamEngine()
	{
		return CallFunction<IStreamEngine*(__thiscall*)(PVOID)>(this, 0x1E8)(this);
	}


	void ProcessWndMessages()
	{
		VIRTUAL<void(__thiscall*)(PVOID)>(this, 159)(this);
	}

	ISystemEventDispatcher* GetISystemEventDispatcher() {
		return CallFunction<ISystemEventDispatcher * (__fastcall*)(PVOID64)>(this, 632)(this);
	}

	auto SetCvars(DWORD64 Offset, bool Value)
	{
		//VIRTUAL<IEntity * (__thiscall*)(PVOID, bool)>(this, 46)(this, true);
	}
	static CSystem* Singleton()
	{
		return *(CSystem**)0x141EF7480;
	}
};



struct ISoundSystem {
public:

	using FN_MasterVolume = void(__thiscall*)(ISoundSystem*, float fvol);

	void SetMasterVolume(float fv) {



		return FN_MasterVolume(0x140D39480)(this, fv);

	}


};

enum EEntityProxy : __int32
{
	ENTITY_PROXY_RENDER = 0x0,
	ENTITY_PROXY_PHYSICS = 0x1,
	ENTITY_PROXY_SCRIPT = 0x2,
	ENTITY_PROXY_SOUND = 0x3,
	ENTITY_PROXY_AI = 0x4,
	ENTITY_PROXY_AREA = 0x5,
	ENTITY_PROXY_BOIDS = 0x6,
	ENTITY_PROXY_BOID_OBJECT = 0x7,
	ENTITY_PROXY_CAMERA = 0x8,
	ENTITY_PROXY_FLOWGRAPH = 0x9,
	ENTITY_PROXY_TRACKVIEW = 0xA,
	ENTITY_PROXY_SUBSTITUTION = 0xB,
	ENTITY_PROXY_TRIGGER = 0xC,
	ENTITY_PROXY_ROPE = 0xD,
	ENTITY_PROXY_ENTITYNODE = 0xE,
	ENTITY_PROXY_USER = 0xF,
	ENTITY_PROXY_LAST = 0x10,
};


struct IProxy {
public:

};

struct IEntity {
public:
	char pad_0x18[0x18];
	IGameObject* m_pGameObjcet;

	using FN_MasterVolume = void(__thiscall*)(IEntity*);

	const char* GetName()
	{
		return CallFunction<const char* (__fastcall*)(PVOID64)>(this, 0x60)(this);
	}

	void SetUpdateStatus()
	{
		FN_MasterVolume(0x14090AD60)(this);
	}

	IProxy* GetProxy(EEntityProxy proxy) {
		return CallFunction<IProxy * (__thiscall*)(PVOID64, EEntityProxy)>(this, 0x1D8)(this, proxy);
	}


	Matrix34& GetWorldTM()
	{
		return CallFunction<Matrix34 & (__thiscall*)(PVOID64)>(this, 0xB8)(this);
	}

	void SetWorldTM() {
		return CallFunction<void(__thiscall*)(PVOID64)>(this, 0xA8)(this);
	}

	IEntity* Hide() {
		return VIRTUAL<IEntity * (__thiscall*)(PVOID, bool)>(this, 46)(this, true);
	}
	IEntity* DeHide() {
		return VIRTUAL<IEntity * (__thiscall*)(PVOID, bool)>(this, 46)(this, false);
	}


	int Id()
	{
		return CallFunction<int(__fastcall*)(PVOID)>(this, 0x8)(this);
	}



	Vec3_tpl<float> GetPlayerPos(IEntity* pEntit) {
		Vec3_tpl<float> vOffset = Vec3_tpl<float>();
		Matrix34_tpl<float> pWorld = pEntit->GetWorldTM();
		vOffset = pWorld.GetTranslation();
		return vOffset;
	}

};




struct IEntityIterator {
public:
	IEntity* Next() {
		return CallFunction<IEntity * (__thiscall*)(PVOID)>(this, 0x30)(this);
	}
};

struct IEntitySystem {
public:
	M_PEntity* GetEntityFromPhysics(IPhysicalEntity* pPhysEntity) { return CallFunction<M_PEntity * (__thiscall*)(PVOID64, IPhysicalEntity*)>(this, 0xD0)(this, pPhysEntity); }

	void OnNetworkGameSync(int false_true)
	{
		VIRTUAL<void(__thiscall*)(PVOID, bool)>(this, 2)(this, false_true); // 0x10
	}

	IEntityIterator* GetEntityIt() {
		return CallFunction<IEntityIterator * (__thiscall*)(PVOID)>(this, 0xA0)(this);
	}

	IEntity* FindEntityByName(const char* name) {
		return VIRTUAL<IEntity * (__thiscall*)(PVOID, const char*)>(this, 12)(this, name);
	}



};
enum ScriptAnyType
{
	ANY_ANY = 0,
	ANY_TNIL,
	ANY_TBOOLEAN,
	ANY_THANDLE,
	ANY_TNUMBER,
	ANY_TSTRING,
	ANY_TTABLE,
	ANY_TFUNCTION,
	ANY_TUSERDATA,
	ANY_TVECTOR,
	ANY_COUNT,
};

struct ScriptAnyValue {
public:
	ScriptAnyType type;
	const char* str;
};

class CScriptSystem {
public:
	virtual void function0();
	virtual void function1();
	virtual void function2();
	virtual void function3();
	virtual void function4();
	virtual void function5();
	virtual bool ExecuteBuffer(const char* sBuffer, size_t nSize, const char* sBufferDescription = "", interface IScriptTable* pEnv = 0) = 0;
	void ExecLua(std::string lua)
	{
		this->ExecuteBuffer(lua.c_str(), lua.size());
	}
	void ExecuteFile(const char* file) {
		CallFunction<void(__fastcall*)(PVOID, const char*, bool, bool, IScriptTable*)>(this, 0x28)(this, file, 1, 0, 0i64);
	}
};





struct ISSGE {
public:
	char pad_0001[0x32D];
	bool m_bClient;

	static ISSGE* Singleton()
	{
		return *(ISSGE**)0x142293718;
	}
};

struct stRayHit
{
	float_t dist;
	IPhysicalEntity* pCollider;
	int32_t ipart;
	int32_t partid;
	int16_t surface_idx;
	int16_t idmatOrg;
	int32_t foreignIdx;
	int32_t iNode;
	Vec3 pt;
	Vec3 n;
	int32_t bTerrain;
	int32_t iPrim;
	stRayHit* next;
};

struct IPhysicalWorld {

public:
private:
	

	struct stRayHitCached : stRayHit
	{
		stRayHitCached() { pCollider = 0; ipart = 0; }
		stRayHitCached(const stRayHit& hit)
		{
			pCollider = hit.pCollider; ipart = hit.ipart;
			iNode = hit.iNode;
		}
		stRayHitCached& operator=(const stRayHit& hit)
		{
			pCollider = hit.pCollider; ipart = hit.ipart;
			iNode = hit.iNode; return *this;
		}
	};

	

public:
	__int32 RayWorldIntersection(const Vec3& org, const Vec3& dir, __int32 objtypes, unsigned __int32 flags, stRayHit* hits, __int32 nMaxHits, IPhysicalEntity** pSkipEnts = 0, __int32 nSkipEnts = 0, PVOID64 pForeignData = 0, __int32 iForeignData = 0, const char* pNameTag = "RayWorldIntersection(Game)", stRayHitCached* phitLast = 0, __int32 iCaller = 4)
	{
		using tRayWorld = __int32(__fastcall*)(PVOID64, const Vec3&, const Vec3&, __int32, unsigned __int32, stRayHit*, __int32, IPhysicalEntity**, __int32, PVOID64, __int32, const char*, stRayHitCached*, __int32);
		return CallFunction<tRayWorld>(this, 776)(this, org, dir, objtypes, flags, hits, nMaxHits, pSkipEnts, nSkipEnts, pForeignData, iForeignData, pNameTag, phitLast, iCaller);
	}//+
	bool isVisible(IEntitySystem* pEntitySystem, M_PEntity* pEntity, Vec3 shootPos, Vec3 pos, IPhysicalEntity** pSkipEnts = 0, int nSkipEnts = 0, int pierceability = 10) {
		stRayHit rayhit;
		if (this->RayWorldIntersection(shootPos, pos - shootPos, 1 | 2 | 4 | 256, 0xA0001500 | pierceability, &rayhit, 1, pSkipEnts, nSkipEnts) > 0) {
			return pEntitySystem->GetEntityFromPhysics(rayhit.pCollider) == pEntity;
		}
		return true;
	}

};

struct CTimerStruct {
public:
	float GetFrameTimer(ETimer timer = ETIMER_GAME) {
		return CallFunction<float(__fastcall*)(PVOID, ETimer)>(this, 0x38)(this, timer);
	}
};

struct SSystemGlobalEnvironment
{
public:
	char pad_0001[0x218];
	bool m_bServer;

	CTimerStruct* GetTimer() {
		return *(CTimerStruct**)((DWORD64)this + 0xC0);
	}

	CScriptSystem* GetCSCryptSystem() {
		return *(CScriptSystem**)((DWORD64)this + 0x40);
	}


	IEntitySystem* GetEntitySystem() {
		return *(IEntitySystem**)((DWORD64)this + 0xE0);
	}

	CSystem* GetCSystem() {
		return *(CSystem**)((DWORD64)this + 0xF0);
	}

	CGame* GetCGame() {
		return *(CGame**)((DWORD64)this + 0xD0);
	}
	CGame_1* GetIGame() {
		return *(CGame_1**)((DWORD64)this + 0xD0);
	}

	ISoundSystem* GetSoundSystem() {
		return *(ISoundSystem**)((DWORD64)this + 0xE0);
	}

	//IEntitySystem* GetEntitySystem()
	//{
	//	return *(IEntitySystem**)((DWORD64)this + 0xE0);
	//}

	auto SetCvars(DWORD64 Offset, bool Value)
	{
		*(bool*)((DWORD64)this + Offset) = Value;
	}

	auto GetCvars(DWORD64 Offset)
	{
		return *(bool*)((DWORD64)this + Offset);
	}




	IRenderer* GetRenderer() {
		return *(IRenderer**)((DWORD64)this + 0x48);
	}

	IConsole* GetIConsole() {
		return *(IConsole**)((DWORD64)this + 0xC8);
	}

	IPhysicalWorld* GetIPhysicalWorld() { return *(IPhysicalWorld**)((DWORD64)this + 0x70); }

	static SSystemGlobalEnvironment* Singleton()
	{
		return *(SSystemGlobalEnvironment**)0x142293718;
	}
};

struct SOnlineQuery {

};
struct SQueryError{};
struct IXmlNodeHandler{};

enum EConnectionMode : __int32
{
	eCM_Polling = 0x0,
	eCM_Blocking = 0x1,
};

struct IOnlineChat {

};

struct IOnlineBandwidthStats {

};

enum EOnlineConnectionState : __int32
{
	eOnlineConnectionState_Disconnected = 0x0,
	eOnlineConnectionState_Connecting = 0x1,
	eOnlineConnectionState_Connected = 0x2,
	eOnlineConnectionState_Unknown = 0x3,
};


struct IOnlineQueryBinder {
public:
	//virtual bool Connect(EConnectionMode mode);
	//virtual int Query(IXmlNodeHandler*, const char* receiverId, const char* const* hz, unsigned __int64 p, IOnlineQueryBinder* binder, ECompressType compression, ERequestSendType type);
	//virtual int Query(IXmlNodeHandler*, const char* receiverId, IOnlineQueryBinder* binder, ECompressType compression, ERequestSendType type);
	//virtual int Query(const char* request, const char* receiverId, IOnlineQueryBinder* binder, ECompressType compression);
	//virtual int Query(const char* request, const char* receiverId);
	//virtual void Response(const SOnlineQuery* query, const char* data, ECompressType compression);
	//virtual void ResponseError(const SQueryError* error, const char* data);
	//virtual void ScheduleFailedQuery(EOnlineError error, const char* data, IOnlineQueryBinder* binder);
	//virtual EOnlineConnectionState GetConnectionState();
	//virtual IOnlineConfiguration* GetConfiguration();
	//virtual IOnlineChat* GetChat(const char* domain);
	//virtual void RegisterQueryStatsListener(interface IOnlineQueryStatsListener* listener);
	//virtual void UnregisterQueryStatsListener(IOnlineQueryStatsListener* listener);
	//virtual IOnlineBandwidthStats* GetBandwidthStatistics();
	//virtual void RegisterDataProtect(interface IOnlineDataProtect* protect);
	//virtual void UnregisterDataProtect();
	//virtual void SendProtectionData(const char* data, const char* data1, unsigned __int64 salt);
	//virtual void SetCertificateValidator(interface ICertificateValidator* validator);


	//void Request(ECompressType m_type) {
	//	//&xmmword_14251AD68 - getQueryReceiverId - unknown
	//	//v18 - getQueryReceiverId
	//
	//
	//	(*(__int64(__fastcall**)(__int64, void**, char*, __int128*, __int64, int, int))(*(_QWORD*)v13 + 8i64))(
	//		v13,
	//		&v31,
	//		0,
	//		NULL,
	//		//&xmmword_14251AD68,
	//		this,
	//		m_type,
	//		0);
	//}
};

#include <string>




struct COnline {
public:

};

struct CGlooxAdapter {
public:
	char pad_0x0030[0x30];
	std::string name;
};

struct CScryptSystem {
public:
	virtual void function0();
	virtual void function1();
	virtual void function2();
	virtual void function3();
	virtual void function4();
	virtual void function5();
	virtual bool ExecuteBuffer(const char* sBuffer, size_t nSize, const char* sBufferDescription = "", interface IScriptTable* pEnv = 0) = 0;
	void WriteBuffer(const char* buffer) { ExecuteBuffer(buffer, sizeof(buffer)); }
};

struct IOnlineConnection {
	char pad_0x09E8[0x9B0];
	CGlooxAdapter GetTag;

	COnline* m_onlineq()
	{
		return *(COnline**)((DWORD64)this + 0x9E8);
	}


	CScryptSystem* GetScryptSystem()
	{
		return *(CScryptSystem**)((DWORD64)this + 0x40);
	}

	//CGlooxAdapter* GetTag()
	//{
	//	return *(CGlooxAdapter**)((DWORD64)this + 0x9B0);
	//}

	void send(std::string message = "<testfdslfdslfdslgfldlgfdlgdf/>") {
		CallFunction<void(__fastcall*)(PVOID64, std::string*)>(this, 0x28)(this, &message);
	}
};

struct CryOnline {
public:
	virtual void Tick();
	virtual void Shutdown();
	virtual IOnlineConnection* CreateConnection(const char* domain);
	char pad_0x0078[0x78];
	IOnlineQueryBinder m_binder;

	//ECompressType m_CopressType() 
	//{ 
	//	return *(ECompressType*)((DWORD64)this + 0xA8);
	//}



	static CryOnline* Singleton()
	{
		return *(CryOnline**)0x14278E780;
	}
};

#endif