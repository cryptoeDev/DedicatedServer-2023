#include <unordered_set>
#include "Utils.hpp"


int id_for_kick = -1;
BYTE is_kicked = 0;



typedef const char* (__fastcall* CSystemClass)(__int64 a1, char a2, int a3);
CSystemClass CSystem_Update_p = (CSystemClass)0x140CC91D0;

int spawnBotCountMS = 1020;
int CountToSpawnOld = 0;
bool continueToSpawn = true;


static const char* GetArchetype(const char* levelName) {
	if (strstr(levelName, "swarm") || strstr(levelName, "arachnid")) {
		return "AIBugs.AR_Bugs_Melee.AR_Bug_Melee";
	}
	if (strstr(levelName, "mars")) {
		return "AIMars.MR_SED_SR.MR_SED_SR_Easy";
	}
	if (strstr(levelName, "arena"))
	{
		return "AIArena.Arena_CQB_Fast.Arena_CQB_Fast2_Hard";
	}
	
	return "AIJapan.JP_Stormtrooper.JP_Stormtrooper_Easy";
}

std::vector<int> ActorsNades;

struct AIHandler {

};

class IAIProxy {
public:
	AIHandler* GetAIHandler()
	{
		return *(AIHandler**)((DWORD64)this + 0x20);
	}
};




typedef int(__cdecl* CryModuleMallocClass)(LONG Value, int a2);
CryModuleMallocClass CryModuleMalloc = (CryModuleMallocClass)0x140089110;

struct IAITarget {
public:
	CPlayer* pActor;
	IEntity* pEntity;
};

enum EActorArchetype
{
	eAA_Sniper,
	eAA_Shotgunner,
	eAA_Assault,
	eAA_Melee,
	eAA_ShieldBearer,
	eAA_SMGShieldBearer,
	eAA_HeavyGunner,
	eAA_Demoman,
	eAA_Specop,
	eAA_Helicopter,
	eAA_Drone,
	eAA_Robot,
	eAA_Cyborg,
	eAA_CyborgScreamer,
	eAA_CyborgBarrelman,
	eAA_CyborgDestroyer,
	eAA_CyborgTurtle,
	eAA_CyborgCrusher,
	eAA_Turret,
	eAA_Other,
	eAA_Count,
};

enum BotState {
	MoveLeft,
	MoveRight,
	MoveForward,
	Idle
};

struct AIActor {
public:
	CPlayer* pActor;
	IAIProxy* pAIProxy;
	SOBJECTSTATE m_State;
	EActorArchetype eActorArchetype;
	float fSpeed;
	float fFireMaxDistance;
	float fFireMeleeMaxDistance;
	IAITarget* pTarget;
	__int64 iTempStartShootTime;
	bool IsTargetMovPos;
	bool IsStunAction;
	Vec3 avoidanceDirection;
	BotState currentState;
	float stateChangeTimer;
	int i = 0;
};

int iqqq = eAPP_Alive;

enum EAIAGInput
{
	AIAG_SIGNAL = 0x0,
	AIAG_ACTION = 0x1,
	AIAG_COVERBODYDIR = 0x2,
};

typedef bool(__fastcall* CAIProxy_SetAGInputClass)(IAIProxy* this1, EAIAGInput input, const char* value);
CAIProxy_SetAGInputClass CAIProxy_SetAGInput = (CAIProxy_SetAGInputClass)0x140575C60; //140575C60

typedef __int64(__fastcall* CAIProxy_UpdateClass)(IAIProxy* this1, SOBJECTSTATE& state, bool bFullUpdate);
CAIProxy_UpdateClass CAIProxy_Update = (CAIProxy_UpdateClass)0x140591FC0;



Vec3 vecBonePos_CLIENT = ZERO;

struct ray_hit
{
	int Unknown001[0x100];
};
struct ray_hit_cached;


typedef int(__thiscall* CPhysicalWorld_RayWorldIntersectionClass)(IPhysicalWorld*, const Vec3& org, const Vec3& dir, int objtypes, unsigned int flags, ray_hit* hits, int nMaxHits, IPhysicalEntity** pSkipEnts, int nSkipEnts, void* pForeignData, int iForeignData, const char* pNameTag, ray_hit_cached* phitLast, int iCaller);
extern CPhysicalWorld_RayWorldIntersectionClass CPhysicalWorld_RayWorldIntersection = (CPhysicalWorld_RayWorldIntersectionClass)0x1409F6220;


bool AiIsVisible(Vec3 CamPos, Vec3 LocPos)
{
	IPhysicalWorld* v1 = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld(); if (!v1) return false;

	Vec3 vDiff;
	ray_hit RayHit;
	int rayFlags(0x0F | 0x400);

	vDiff.x = LocPos.x - CamPos.x;
	vDiff.y = LocPos.y - CamPos.y;
	vDiff.z = LocPos.z - CamPos.z;

	return !CPhysicalWorld_RayWorldIntersection(v1, CamPos, vDiff, 0x100 | 1, rayFlags, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4);
}

bool AiIsSide(Vec3 Pos)
{
	IPhysicalWorld* v1 = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld(); if (!v1) return false;


	ray_hit RayHit;
	int rayFlags(0x0F | 0x400);

	Vec3 sideDir = { 0,0,-3 };

	Vec3 sidePos1 = { Pos.x + 1,Pos.y,Pos.z + 1 };
	Vec3 sidePos2 = { Pos.x - 1,Pos.y,Pos.z + 1 };
	Vec3 sidePos3 = { Pos.x,Pos.y + 1,Pos.z + 1 };
	Vec3 sidePos4 = { Pos.x,Pos.y - 1,Pos.z + 1 };

	return (!CPhysicalWorld_RayWorldIntersection(v1, sidePos1, sideDir, 0x100 | 1, rayFlags, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4) || !CPhysicalWorld_RayWorldIntersection(v1, sidePos2, sideDir, 0x100 | 1, rayFlags, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4) || !CPhysicalWorld_RayWorldIntersection(v1, sidePos3, sideDir, 0x100 | 1, rayFlags, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4) || !CPhysicalWorld_RayWorldIntersection(v1, sidePos4, sideDir, 0x100 | 1, rayFlags, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4));
}

Vec3 vActorHeadPos;
Vec3 vTargetPos;
CPlayer* TargetPlayer = NULL;

typedef CActor* (__thiscall* CActor_GetBonePosClass)(CPlayer* this1, Vec3* result, const char* boneName);
CActor_GetBonePosClass CActor_GetBonePos = (CActor_GetBonePosClass)0x1412F6AB0;

typedef void(__thiscall* CGameRules_AddServerHitClass)(CGameRules*, const SGameHitInfo*);

//find a function containing  the strings only 'OnHit' and 'cmd_kill', and will be 'LOBYTE(v7) = (unsigned int)sub_11FC9A0(v2, (int)&v18);
CGameRules_AddServerHitClass CGameRules_AddServerHit = (CGameRules_AddServerHitClass)0x1414B2760;

typedef void(__thiscall* SGameHitInfo_SGameHitInfo0Class)(SGameHitInfo*);
SGameHitInfo_SGameHitInfo0Class SGameHitInfo_SGameHitInfo0 = (SGameHitInfo_SGameHitInfo0Class)0x14145D100;


std::vector<CPlayer*> AIPlayers; // Вектор с AI игроками
std::vector<CPlayer*> TargetPlayers; // Вектор с целевыми игроками

int id_for_slide = 0;
bool is_slide_player = false;

float AiGetDistance(Vec3 VecA, Vec3 VecB)
{
	return sqrt(((VecA.x - VecB.x) * (VecA.x - VecB.x)) + ((VecA.y - VecB.y) * (VecA.y - VecB.y)) + ((VecA.z - VecB.z) * (VecA.z - VecB.z)));
}

struct MovementCore_SMovementCmd
{
public:

};




struct MovementCore_SPlayerMovementState {
public:
	
};

typedef CWeaponGeneral* (__thiscall* CActor_GetCurrentWeaponClass)(CPlayer* this1);
CActor_GetCurrentWeaponClass CActor_GetCurrentWeapon = (CActor_GetCurrentWeaponClass)0x1412F65A0;

typedef bool(__thiscall* CWeaponGeneral_IsReloadingClass)(CWeaponGeneral* this1);
CWeaponGeneral_IsReloadingClass CWeaponGeneral_IsReloading = (CWeaponGeneral_IsReloadingClass)0x141466500;

const char* GetStanceName(int stance)
{
	const char* result; // rax

	switch (stance)
	{
	case -1:
		result = "Null";
		break;
	case 0:
		result = "Stand";
		break;
	case 1:
		result = "Crouch";
		break;
	case 2:
		result = "Prone";
		break;
	case 3:
		result = "Stealth";
		break;
	case 4:
		result = "LowCover";
		break;
	case 5:
		result = "HighCover";
		break;
	case 6:
		result = "Patrol";
		break;
	case 7:
		result = "Range";
		break;
	default:
		result = "<Unknown>";
		break;
	}
	return result;
}

struct pe_action_impulse : pe_action
{
	Vec3_tpl<float> impulse;
	Vec3_tpl<float> angImpulse;
	Vec3_tpl<float> point;
	int partid;
	int ipart;
	int iApplyTime;
	int iSource;
};


//find a function containing the string 'needIcon'
typedef int(__thiscall* CWeaponGeneral_GetAmmoCountClass)(CWeaponGeneral* this1);
CWeaponGeneral_GetAmmoCountClass CWeaponGeneral_GetAmmoCount = (CWeaponGeneral_GetAmmoCountClass)0x141465D40;

//find a function containing the string 'manual' and 'auto'
typedef void(__thiscall* CWeaponGeneral_ReloadClass)(CWeaponGeneral* this1, bool manual, char a3);
CWeaponGeneral_ReloadClass CWeaponGeneral_Reload = (CWeaponGeneral_ReloadClass)0x141469450;

CPlayer* AIPlayer = NULL;

enum entity_query_flags : __int32
{
	ent_static = 0x1,
	ent_sleeping_rigid = 0x2,
	ent_rigid = 0x4,
	ent_living = 0x8,
	ent_independent = 0x10,
	ent_deleted = 0x80,
	ent_terrain = 0x100,
	ent_all = 0x11F,
	ent_flagged_only = 0x800,
	ent_skip_flagged = 0x1000,
	ent_areas = 0x20,
	ent_triggers = 0x40,
	ent_ignore_noncolliding = 0x10000,
	ent_sort_by_mass = 0x20000,
	ent_allocate_list = 0x40000,
	ent_addref_results = 0x100000,
	ent_water = 0x200,
	ent_no_ondemand_activation = 0x80000,
	ent_delayed_deformations = 0x80000,
};
enum rwi_flags : __int32
{
	rwi_ignore_terrain_holes = 0x20,
	rwi_ignore_noncolliding = 0x40,
	rwi_ignore_back_faces = 0x80,
	rwi_ignore_solid_back_faces = 0x100,
	rwi_pierceability_mask = 0xF,
	rwi_pierceability0 = 0x0,
	rwi_stop_at_pierceable = 0xF,
	rwi_separate_important_hits = 0x200,
	rwi_colltype_bit = 0x10,
	rwi_colltype_any = 0x400,
	rwi_queue = 0x800,
	rwi_force_pierceable_noncoll = 0x1000,
	rwi_debug_trace = 0x2000,
	rwi_update_last_hit = 0x4000,
	rwi_any_hit = 0x8000,
};



bool CanSeeTarget(M_PEntity* pBot, M_PEntity* pTarget)
{
	if (!pBot || !pTarget)
		return false;

	Vec3 botEyePos = pBot->GetWorldTM().GetTranslation() + Vec3(0, 0, 1.6f);    // глаза бота
	Vec3 targetPos = pTarget->GetWorldTM().GetTranslation() + Vec3(0, 0, 1.6f); // грудь цели

	stRayHit hit;
	static const int objTypes = ent_static | ent_rigid | ent_sleeping_rigid;
	static const unsigned int flags = rwi_stop_at_pierceable | rwi_colltype_any;

	int result = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld()->RayWorldIntersection(
		botEyePos,
		targetPos - botEyePos,
		objTypes,
		flags,
		&hit, 1
	);

	return result == 0;
}

bool IsWallBetween(const Vec3& from, const Vec3& to)
{
	stRayHit hit;
	const int objTypes = ent_static | ent_terrain; 
	const int flags = rwi_stop_at_pierceable | rwi_colltype_any;

	int result = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld()->RayWorldIntersection(
		from,
		to - from,
		objTypes,
		flags,
		&hit, 1
	);

	return result > 0;
}





enum pe_type : __int32
{
	PE_NONE = 0x0,
	PE_STATIC = 0x1,
	PE_RIGID = 0x2,
	PE_WHEELEDVEHICLE = 0x3,
	PE_LIVING = 0x4,
	PE_PARTICLE = 0x5,
	PE_ARTICULATED = 0x6,
	PE_ROPE = 0x7,
	PE_SOFT = 0x8,
	PE_AREA = 0x9,
};

std::unordered_set<int> initializedBots;


void InitBotPhysics(M_PEntity* pEntity)
{



	SEntityPhysicalizeParams physParams;
	memset(&physParams, 0, sizeof(SEntityPhysicalizeParams));
	physParams.type = PE_LIVING;
	physParams.mass = 80.0f;

	pe_player_dimensions dims;
	memset(&dims, 0, sizeof(pe_player_dimensions));
	dims.heightCollider = 1.8f;
	dims.sizeCollider = Vec3(0.45f, 0.45f, 0.2f);
	dims.heightEye = 1.6f;
	dims.bUseCapsule = 1;
	physParams.pPlayerDimensions = &dims;

	pe_player_dynamics dyn;
	memset(&dyn, 0, sizeof(pe_player_dynamics));
	dyn.kInertia = 3.0f;
	dyn.kAirResistance = 1.0f;
	dyn.kInertiaAccel = 1.0f;
	dyn.kAirControl = 1.0f;
	dyn.gravity = Vec3(1, 1, -9.81f);
	dyn.maxVelGround = 2.5f;
	physParams.pPlayerDynamics = &dyn;

	pEntity->Physicalize(&physParams);
}

bool bInit = false;

struct pe_params_pos : pe_params
{
	Vec3_tpl<float> pos;
	Quat_tpl<float> q;
	float scale;
	Matrix34 pMtx3x4;
	Matrix33 pMtx3x3;
	int iSimClass;
	int bRecalcBounds;
	bool bEntGridUseOBB;
};

struct SActorStats
{
public:
	float inAir;
	float onGround;
	float speedFlat;
	Vec3_tpl<float> velocity;
	Vec3_tpl<float> gravity;
	float mass;
	bool isRagDoll;
	char inFreefall;
	int groundMaterialIdx;
};


int FireAI = 5;

bool IsFiring = false;

struct SPlayerStats : SActorStats 
{
public:
	float inMovement;
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
	void*  heightPivot;
	void*  heightCollider;
	void* sizeCollider;
	float fallSpeed;
	float fallVelocityLastFrame;
	float fallVelocity;
	bool isFiring;
	void* followCharacterHead;
	bool isStandingUp;
	void* firstPersonBody;
	Vec3_tpl<float> groundNormal;
	Ang3_tpl<float> angularVel;
	Ang3_tpl<float> angularImpulse;
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
	float distNearClipPlane;
};


struct SActorFrameMovementParams {

};

struct SPlayerParams {};

enum ECharacterMoveType : int32 {
	eCMT_None = 0x0,
	eCMT_Normal = 0x1,
	eCMT_Fly = 0x2,
	eCMT_Swim = 0x3,
	eCMT_ZeroG = 0x4,
	eCMT_Impulse = 0x5,
	eCMT_JumpInstant = 0x6,
	eCMT_JumpAccumulate = 0x7,
};

struct SCharacterMoveRequest
{
	ECharacterMoveType type;
	Vec3_tpl<float> velocity;
	Quat_tpl<float> rotation;
	SPredictedCharacterStates prediction;
	bool allowStrafe;
	float proceduralLeaning;
	bool jumping;
	bool disableGravity;
};



struct CPlayerMovement
{
	float m_frameTime;
	const SPlayerParams* m_params;
	const SPlayerStats* m_stats;
	SActorFrameMovementParams m_movement;
	CPlayer* m_player;
	Quat_tpl<float>* m_viewQuat;
	Quat_tpl<float>* m_baseQuat;
	Vec3_tpl<float>* m_upVector;
	int m_actions;
	SCharacterMoveRequest m_request;
	bool m_jumped;
	bool m_hasJumped;
};

bool IsShielded = false;
bool IsCyborg = false;

typedef void(__thiscall* CAIProxy_CAIProxyClass)(IAIProxy* this1, IGameObject* a2);
CAIProxy_CAIProxyClass CAIProxy_CAIProxy = (CAIProxy_CAIProxyClass)0x140596B80;

struct SM_Network__SMessageAI
{
	void* ptr; //0x0000
	int type;  //0x0008
	int msgType; //0x0012
	__int64 serverTime; //0x0016
	int opcode;         // 0x0024
	char instant;       // 0x0028
}; //size 0x0032

struct SKnockBackMessageAI : SM_Network__SMessageAI {

	Quat_tpl<float> animStartLocalRot;
	Vec3_tpl<float> startPos;
	void* standingOn;
}; //Size=0x0040

void __fastcall CSystem_Update(__int64 a1, char a2, int a3)
{
											//SSystemGlobalEnvironment* pSSGE = SSystemGlobalEnvironment::Singleton(); if (!pSSGE) return;
											IGameFramework* pFramework = IGameFramework::Singlenton(); if (!pFramework) return;
											//IPhysicalWorld* pPhysicalWorld = pSSGE->GetIPhysicalWorld(); if (!pPhysicalWorld) return;
											//
											//CGameServerNub* pGameServerNub = pFramework->GetServerNub(); if (!pGameServerNub) return;
											////TServerChannelMap* m_channel = pGameServerNub->GetServerChannelMap(); if (!m_channel) return;
											//IActorSystem* pActorSystem = pFramework->GetActorSystem(); if (!pActorSystem) return;
											//CScriptSystem* pScryptSystem = pSSGE->GetCSCryptSystem(); if (!pScryptSystem) return;
											//SCVars* pCVARS = SCVars::Singlenton(); if (!pCVARS) return;
											//IEntitySystem* pEntitySystem = pSSGE->GetEntitySystem(); if (!pEntitySystem) return;
											//IEntityIterator* pEntityIterator = pEntitySystem->GetEntityIt(); if (!pEntityIterator) return;
											//CGameRules* pGameRules = pFramework->GetCurrentGameRules(); if (!pGameRules) return;
											//
											//const char* levelName = pFramework->GetLevelName();
											//
											//CActorIterator* pIterator = NULL;
											//pActorSystem->GetActorIterator(&pIterator);
											//
											//
											//
											//
											//Vec3 clientPos;
											//
											//
											//
											//
											//if (pIterator) {
											//	for (; CPlayer * Player = pIterator->Next();)
											//	{
											//		CEntityClass* pEntityClass = Player->GetEntity()->GetClass(); if (!pEntityClass) continue;
											//		//printf("Class name: %s\n", pEntityClass->Name());
											//		if (!Player) continue;
											//		if (Player->Health() <= 0) continue;
											//		if (strstr(pEntityClass->Name(), "Player")) {
											//			CActor_GetBonePos(Player, &vTargetPos, "Bip01 Head");
											//			TargetPlayer = Player;
											//			TargetPlayers.push_back(Player);
											//		}
											//
											//
											//
											//
											//
											//		if (strstr(pEntityClass->Name(), "Player")) continue;
											//		IItem* pItemProxy = Player->GetCurrentItem(); if (!pItemProxy) continue;
											//		CWeapon* pWeapon = pItemProxy->GetWeapon(); if (!pWeapon) continue;
											//
											//		CActor_GetBonePos(Player, &vActorHeadPos, "Bip01 Head");
											//
											//		std::vector<SvRequestShootHit::RequestHit> hit;
											//		clear(vActorHeadPos, Player->HitGett());
											//
											//		const char* sInitialCharacterName = Player->GetEntity()->GetName();
											//
											//		if (TargetPlayer == NULL) continue;
											//		if (TargetPlayer->IsDead()) continue;
											//
											//		//CWeaponGeneral* pWeaponGeneral = CActor_GetCurrentWeapon(Player);
											//		//if (pWeaponGeneral && CWeaponGeneral_IsReloading(pWeaponGeneral)) {
											//		//	continue;
											//		//}
											//		//
											//		//
											//		//if (pWeaponGeneral && CWeaponGeneral_GetAmmoCount(pWeaponGeneral) < 1) {
											//		//	CWeaponGeneral_Reload(pWeaponGeneral, false, false);
											//		//}
											//
											//		if (!CanSeeTarget(Player->GetEntity(), TargetPlayer->GetEntity())) {
											//			if (IsFiring) {
											//				pWeapon->StopFire();
											//				IsFiring = false;
											//			}
											//			
											//			continue;
											//		}
											//
											//		static uint64_t Timer{ 0 };
											//		if (GetTickCount64() - Timer > 500) {
											//			if (TargetPlayer->Health() <= 5) {
											//				typedef void(__fastcall* KillPlayer)(CGameRules* this1,
											//					CPlayer* pPlayer,
											//					unsigned int shooterId,
											//					int weaponGameObjectId,
											//					float damage,
											//					int material,
											//					unsigned int hit_type,
											//					Vec3_tpl<float>* impulse,
											//					unsigned int projectileId,
											//					int targetsCoreTeam,
											//					int shootersCoreTeam,
											//					bool bExplosion);
											//
											//				Vec3 p = Vec3(1, 1, 1);
											//				KillPlayer((KillPlayer)0x1411E2840)(pGameRules, TargetPlayer, Player->GetEntity()->Id(), 11, 5, pGameRules->GetHitMaterialId("mat_torso"), 1, &p, rand(), 1, 1, TRUE);
											//				TargetPlayer = NULL;
											//				TargetPlayers.erase(
											//					std::remove_if(TargetPlayers.begin(), TargetPlayers.end(),
											//						[](CPlayer* p) {
											//							return !p || p->IsDead();
											//						}),
											//					TargetPlayers.end()
											//				);
											//				continue;
											//			}
											//			if (!strstr(sInitialCharacterName, "Sniper") && !strstr(sInitialCharacterName, "Demoman")) {
											//				float lerpSpeed = 4.0f;
											//				Vec3 currentPos = Player->GetEntity()->GetWorldTM().GetTranslation();
											//				Vec3 targetPos = TargetPlayer->GetEntity()->GetWorldTM().GetTranslation();
											//
											//				Vec3 newPos = Vec3::CreateLerp(currentPos, targetPos, min(1.0f, SSystemGlobalEnvironment::Singleton()->GetTimer()->GetFrameTimer() * lerpSpeed));
											//
											//				Matrix34 tm = Player->GetEntity()->GetWorldTM();
											//				tm.SetTranslation(newPos);
											//				Player->GetEntity()->SetWorldTM(tm, ENTITY_XFORM_POS);
											//
											//				CPlayerV2* pActorPlayer = Player->GetPlayerV2(); if (!pActorPlayer) continue;
											//
											//				Vec3 vDir = pActorPlayer->m_viewQuatFinal.ToForwardVector();
											//				vDir.GetNormalized();
											//
											//				Ang3 result;
											//				Player->GetEntity()->GetWorldAngles(&result);
											//
											//				////pos.z = pos.z + 0;
											//				//Player->Move(newPos, result);
											//			}
											//			else {
											//
											//				Vec3 pos = Player->GetEntity()->GetWorldTM().GetTranslation();
											//
											//				CPlayerV2* pActorPlayer = Player->GetPlayerV2(); if (!pActorPlayer) continue;
											//				Vec3 vDir = pActorPlayer->m_viewQuatFinal.ToForwardVector();
											//				vDir.GetNormalized();
											//				Matrix34 tm = Player->GetEntity()->GetWorldTM();
											//				tm.SetTranslation(pos);
											//				Player->GetEntity()->SetWorldTM(tm, ENTITY_XFORM_POS);
											//				//pos.z = pos.z + 0;
											//
											//				Ang3 result;
											//				Player->GetEntity()->GetWorldAngles(&result);
											//
											//				//Player->Move(pos, result);
											//			}
											//			Timer = GetTickCount64();
											//
											//
											//			std::srand(static_cast<unsigned int>(std::time(0)));
											//			int randomNumber = std::rand() % 5 + 1;
											//
											//			//if (strstr(sInitialCharacterName, "Shield")) {
											//			//	if (AiGetDistance(Player->GetEntity()->GetWorldTM().GetTranslation(), TargetPlayer->GetEntity()->GetWorldTM().GetTranslation()) <= 1.5f) {
											//			//		if (randomNumber == 4) {
											//			//			SKnockBackMessageAI msg;
											//			//			memset(&msg, 0, sizeof(SKnockBackMessageAI));
											//			//			{
											//			//				msg.type = 3;
											//			//				msg.msgType = 0;
											//			//				msg.startPos = TargetPlayer->GetEntity()->GetWorldTM().GetTranslation();
											//			//			}
											//			//			typedef void(__fastcall* SendMessageFromServer_KnockbackAI)(CPlayer*, SKnockBackMessageAI*);
											//			//			SendMessageFromServer_KnockbackAI((SendMessageFromServer_KnockbackAI)0x1416C0D60)(TargetPlayer, &msg);
											//			//		}
											//			//		printf("IsShielded %i\n", randomNumber);
											//			//	}
											//			//	IsShielded = true;
											//			//}
											//			//else if (strstr(sInitialCharacterName, "Cyborg")) {
											//			//	if (AiGetDistance(Player->GetEntity()->GetWorldTM().GetTranslation(), TargetPlayer->GetEntity()->GetWorldTM().GetTranslation()) <= 1.5f) {
											//			//		if (randomNumber == 4) {
											//			//			SKnockBackMessageAI msg;
											//			//			memset(&msg, 0, sizeof(SKnockBackMessageAI));
											//			//			{
											//			//				msg.type = 3;
											//			//				msg.msgType = 0;
											//			//				msg.startPos = TargetPlayer->GetEntity()->GetWorldTM().GetTranslation();
											//			//			}
											//			//			typedef void(__fastcall* SendMessageFromServer_KnockbackAI)(CPlayer*, SKnockBackMessageAI*);
											//			//			SendMessageFromServer_KnockbackAI((SendMessageFromServer_KnockbackAI)0x1416C0D60)(TargetPlayer, &msg);
											//			//		}
											//			//	}
											//			//	IsCyborg = true;
											//			//}
											//
											//			if (!IsShielded && !IsCyborg) {
											//				pWeapon->StartFire();
											//
											//				static uint64_t Timer1{ 0 };
											//				if (GetTickCount64() - Timer1 > 750) {
											//
											//					TargetPlayer->SetHealth(TargetPlayer->Health() - FireAI);
											//					TargetPlayer->SetArmor(TargetPlayer->Armor() - FireAI);
											//
											//
											//					pWeapon->StopFire();
											//					Timer1 = GetTickCount64();
											//				}
											//			}
											//			else {
											//				pWeapon->StartFire();
											//				IsFiring = true;
											//
											//			}
											//			IsCyborg = false;
											//			IsShielded = false;
											//			TargetPlayer = NULL;
											//		}
											//
											//
											//	}
											//}
	IActorSystem* pActorSystem = pFramework->GetActorSystem(); if (!pActorSystem) return;
	CActorIterator* pIterator = NULL;
	pActorSystem->GetActorIterator(&pIterator);
	
	if (pIterator) {
		for (; CPlayer * Player = pIterator->Next();)
		{
			if (GetAsyncKeyState(VK_F1) & 1) {
				typedef void(__fastcall* CPlayerSendInput)(CPlayer*, bool);
				CPlayerSendInput((CPlayerSendInput)0x141231170)(Player, 1);
				printf("IQQQQQ: %i\n", iqqq);
			}
		}
	
	}




	INetChannel* pChannel = pFramework->GetNetChannel(); 
	if (pChannel) {
	
	
		if (is_kicked)
		{
			printf("kicked!");
			if (!pChannel->GetProfileId()) return;
	
			if (pChannel->GetProfileId() == id_for_kick)
			{
				pChannel->Disconnect(5, "is kicked by anti-cheat");
				is_kicked = 0;
			}
		}
	}




	CSystem_Update_p(a1, a2, a3);
}

typedef void(__thiscall* CallBehaviorConstructorClass)(IAIProxy* this1, IGameObject* a2);
CallBehaviorConstructorClass CallBehaviorConstructor_p = (CallBehaviorConstructorClass)0x140577FC0;

void __fastcall CallBehaviorConstructor(void* this1, const void* pData) { //140577FC0
	typedef int(__thiscall* sub_10727E0)(void* a1, unsigned int a2, const char* funcName, float* pValue, IEntity* pSender, const void* pData);
	sub_10727E0(0x1405798F0)(this1, *(DWORD*)((DWORD)this1 + 0x70), "Constructor", 0, 0, pData);
}


