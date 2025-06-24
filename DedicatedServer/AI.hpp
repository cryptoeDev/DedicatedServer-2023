#include <unordered_map>
void MhCreateAndEnableHook_AI(LPVOID pTarget, LPVOID pDetour, LPVOID* ppOriginal) {

	bool F1Set = false;

	while (!F1Set)
	{
		if (MH_CreateHook(pTarget, pDetour, ppOriginal) == MH_OK)
		{
			MH_EnableHook(pTarget);
			F1Set = true;
		}

		Sleep(1);
	}

}

static void SetPathAI(void* adress, LPCVOID lpBuffer, int len)
{
	DWORD oldProtect = 0;

	VirtualProtect(adress, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(GetCurrentProcess(), adress, lpBuffer, len, NULL);
	VirtualProtect(adress, len, oldProtect, NULL);
}

std::vector <AIActor*> vAIActors;
std::vector <IAITarget*> vAITargets;

typedef bool (__fastcall* CSystemClassW)(__int64 a1, unsigned int a2, int a3);
CSystemClassW CSystem_Update_pw = (CSystemClassW)0x140CC91D0;



bool __fastcall CSystem_Updateq(__int64 a1, unsigned int a2, int a3)
{
	//SSystemGlobalEnvironment* pSSGE = SSystemGlobalEnvironment::Singleton(); if (!pSSGE) return false;
	//IGameFramework* pFramework = IGameFramework::Singlenton(); if (!pFramework) return 0;
	//IActorSystem* pActorSystem = pFramework->GetActorSystem(); if (!pActorSystem) return 0;
	//CScriptSystem* pScryptSystem = pSSGE->GetCSCryptSystem(); if (!pScryptSystem) return 0;
	//
	//CActorIterator* pIterator = NULL;
	//pActorSystem->GetActorIterator(&pIterator);
	//if (pIterator) {
	//	for (; CPlayer * Player = pIterator->Next();)
	//	{
	//		//if (!Player) continue;
	//		//Vec3 pos = Player->GetEntity()->GetWorldTM().GetTranslation();
	//		//std::ostringstream luaCommand;
	//		//luaCommand << "System.SpawnEntity({class = 'Soldier', archetype = 'AIJapan.JP_Stormtrooper.JP_Stormtrooper_Easy', position = {"
	//		//	<< pos.x << ", " << pos.y << ", " << pos.z << "}, name = 'Trip Sitter'});";
	//		//pScryptSystem->ExecLua(luaCommand.str());
	//	}
	//}



	return CSystem_Update_pw(a1, a2, a3);
}

typedef bool(__thiscall* CPlayer_InitClass)(CPlayer* this1, IGameObject* pGameObject);
CPlayer_InitClass CPlayer_Init = (CPlayer_InitClass)0x1412232E0;


void AiRegisterTarget(CPlayer* pActor, IEntity* pEntity) {
	IAITarget* pAITarget = new IAITarget;
	ZeroMemory(pAITarget, sizeof(IAITarget));
	pAITarget->pActor = pActor;
	pAITarget->pEntity = pEntity;
	vAITargets.push_back(pAITarget);
	//printf("AiRegisterTarget Add IAITarget %u %u %i\n", pActor, pEntity, (int)vAITargets.size());
}

//find the function containing 'aicharacter_character' and not containing 'return 0;'
AIActor* pActorAI = NULL;
bool MoveToActorShoot = false;

typedef const char* (__fastcall* CAIHandler_GetInitialCharacterNameClass)(AIHandler* this1);
CAIHandler_GetInitialCharacterNameClass CAIHandler_GetInitialCharacterName = (CAIHandler_GetInitialCharacterNameClass)0x1405782D0;

typedef void(__fastcall* CPiecewiseTrajectory__GetEndPoint)(AIHandler* pHandler, EAIAGInput input, const char* value);


void AiRegister(CPlayer* pActor, IGameObject* pGameObject) {

	IEntityArchetype* pEntityArchetype = pActor->GetEntity()->GetAcrhetype();
	
	if (!pEntityArchetype) {
		AiRegisterTarget(pActor, 0);
		return;
	}



	IAIProxy* pAIProxy = (IAIProxy*)CryModuleMalloc(99999, 1);
	if (!pAIProxy) {
		//printf("AiRegisterObject Failed pAIProxy %u\n", pActor);
		return;
	}

	CAIProxy_CAIProxy(pAIProxy, pGameObject);

	if (!pAIProxy->GetAIHandler()) {
		//printf("AIHandler is failed\n");
		return;
	}

	const char* sInitialCharacterName = CAIHandler_GetInitialCharacterName(pAIProxy->GetAIHandler());

	EActorArchetype eActorArchetype = eAA_Other;
	float fSpeed = 0.0f;
	float fFireMaxDistance = -1.0f;
	float fFireMeleeMaxDistance = -1.0f;



	if (strstr(sInitialCharacterName, "Sniper")) {
		eActorArchetype = eAA_Sniper;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	else if (strstr(sInitialCharacterName, "AR_Bug_Range"))
	{
		eActorArchetype = eAA_Assault;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	
	else if (strstr(sInitialCharacterName, "Shotgunner")) {
		eActorArchetype = eAA_Shotgunner;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	else if (strstr(sInitialCharacterName, "Assault")) {
		eActorArchetype = eAA_Assault;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	else if (strstr(sInitialCharacterName, "CQB")) {
		eActorArchetype = eAA_Assault;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	//else if (strstr(sInitialCharacterName, ""))
	else if (strstr(sInitialCharacterName, "HST_CQB")) {
		eActorArchetype = eAA_Assault;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	else if (strstr(sInitialCharacterName, "SED")) {
		eActorArchetype = eAA_Assault;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
		CPiecewiseTrajectory__GetEndPoint((CPiecewiseTrajectory__GetEndPoint)0x140575C60)(pAIProxy->GetAIHandler(), AIAG_ACTION, "hitReaction");
	}
	
	else if (strstr(sInitialCharacterName, "Melee")) {
		eActorArchetype = eAA_Melee;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 0.4f;
	}
	else if (strstr(sInitialCharacterName, "ShieldBearer")) {
		eActorArchetype = eAA_ShieldBearer;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	else if (strstr(sInitialCharacterName, "SMGShieldBearer")) {
		eActorArchetype = eAA_SMGShieldBearer;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	else if (strstr(sInitialCharacterName, "HeavyGunner")) {
		eActorArchetype = eAA_HeavyGunner;
		fSpeed = 1.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 0.0f;
	}
	else if (strstr(sInitialCharacterName, "Demoman")) {
		eActorArchetype = eAA_Demoman;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	else if (strstr(sInitialCharacterName, "Specop")) {
		eActorArchetype = eAA_Specop;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}
	else if (strstr(sInitialCharacterName, "Helicopter")) {
		eActorArchetype = eAA_Helicopter;
		fSpeed = 0.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 0.0f;
	}
	else if (strstr(sInitialCharacterName, "IB_Black_Wolf"))
	{
		eActorArchetype = eAA_Helicopter;
		fSpeed = 0.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 0.0f;
	}
	else if (strstr(sInitialCharacterName, "Mantis")) {
		eActorArchetype = eAA_Helicopter;
		fSpeed = 0.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 0.0f;
	}


	else if (strstr(sInitialCharacterName, "Drone")) {
		eActorArchetype = eAA_Drone;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 0.0f;
	}
	else if (strstr(sInitialCharacterName, "Robot")) {
		eActorArchetype = eAA_Robot;
		fSpeed = 6.4f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 0.0f;
	}
	else if (strstr(sInitialCharacterName, "Cyborg")) {
		eActorArchetype = eAA_Cyborg;
		fSpeed = 4.0f;
		fFireMaxDistance = 0.0f;
		fFireMeleeMaxDistance = 4.0f;
	}
	else if (strstr(sInitialCharacterName, "CyborgScreamer")) {
		eActorArchetype = eAA_CyborgScreamer;
		fSpeed = 4.0f;
		fFireMaxDistance = 0.0f;
		fFireMeleeMaxDistance = 4.0f;
	}
	else if (strstr(sInitialCharacterName, "CyborgBarrelman")) {
		eActorArchetype = eAA_CyborgBarrelman;
		fSpeed = 4.0f;
		fFireMaxDistance = 0.0f;
		fFireMeleeMaxDistance = 0.0f;
	}
	else if (strstr(sInitialCharacterName, "CyborgDestroyer")) {
		eActorArchetype = eAA_CyborgDestroyer;
		fSpeed = 2.0f;
		fFireMaxDistance = 0.0f;
		fFireMeleeMaxDistance = 4.0f;
	}
	else if (strstr(sInitialCharacterName, "CyborgTurtle")) {
		eActorArchetype = eAA_CyborgTurtle;
		fSpeed = 1.0f;
		fFireMaxDistance = 0.0f;
		fFireMeleeMaxDistance = 4.0f;
	}
	else if (strstr(sInitialCharacterName, "CyborgCrusher")) {
		eActorArchetype = eAA_CyborgCrusher;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 4.0f;
	}

	else if (strstr(sInitialCharacterName, "Turret")) {
		//140575C60


		CPiecewiseTrajectory__GetEndPoint((CPiecewiseTrajectory__GetEndPoint)0x140575C60)(pAIProxy->GetAIHandler(), AIAG_ACTION, "attack");
		//printf("Turret\n");

		eActorArchetype = eAA_Turret;
		fSpeed = 0.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = -0.0f;

		//pActor->SetAGInput(AIAG_ACTION, "attack");
	}

	else if (strstr(sInitialCharacterName, "Other")) {
		eActorArchetype = eAA_Other;
		fSpeed = 0.0f;
		fFireMaxDistance = 0.0f;
		fFireMeleeMaxDistance = 0.0f;
	}
	else {
		printf("AiRegister Unknown ActorArchetype %s\n", sInitialCharacterName);
		eActorArchetype = eAA_Assault;
		fSpeed = 3.0f;
		fFireMaxDistance = -1.0f;
		fFireMeleeMaxDistance = 1.5f;
	}

	//AiRegisterTarget(pActor, 0);

	//IEntityArchetype* pEntityArchetype = pActor->GetEntity()->GetAcrhetype();
	//
	//if (!pEntityArchetype) {
	//	AiRegisterTarget(pActor, 0);
	//	return;
	//}

	

	AIActor* pAIActor = new AIActor;
	ZeroMemory(pAIActor, sizeof(AIActor));
	pAIActor->pActor = pActor;
	pAIActor->pAIProxy = pAIProxy;
	pAIActor->eActorArchetype = eActorArchetype;
	pAIActor->fSpeed = fSpeed;
	pAIActor->fFireMaxDistance = fFireMaxDistance;
	pAIActor->fFireMeleeMaxDistance = fFireMeleeMaxDistance;
	pAIActor->IsStunAction = false;
	vAIActors.push_back(pAIActor);
	//printf("%s Has registration!\n", pActor->GetEntity()->GetName());
}

bool __fastcall AiCPlayer_InitHook(CPlayer* this1, IGameObject* pGameObject) {

	bool bResult = CPlayer_Init(this1, pGameObject);

	printf("CPlayer_InitHook\n");

	AiRegister(this1, pGameObject);

	return bResult;
}







void WriteMemSilentNop(DWORD64 dwAdress, int size)
{
	string aboba;
	for (int i = 0; i < size; i++)
	{
		aboba += "\x90";
	}
	SetPathAI((void*)dwAdress, aboba.c_str(), size);
}

typedef int(__cdecl* CryModuleFreeClass)(int a1, int a2);
CryModuleFreeClass CryModuleFree = (CryModuleFreeClass)0x140089550;

void AiUnregister(CPlayer* pActor) {
	for (int e = 0; e < (int)vAIActors.size(); e++) {
		if (vAIActors[e]->pActor == pActor) {
			//printf("AiUnregister Delete IAIActor %u %i\n", vAIActors[e]->pActor, (int)vAIActors.size());
			CryModuleFree((int)vAIActors[e]->pAIProxy, 1); //140089550
			delete vAIActors[e];
			vAIActors.erase(vAIActors.begin() + e);
			return;
		}
	}
}

void AiUnregisterTarget(CPlayer* pActor, IEntity* pEntity) {
	for (int e = 0; e < (int)vAITargets.size(); e++) {
		if (vAITargets[e]->pActor == pActor && vAITargets[e]->pEntity == pEntity) {
			//printf("AiUnregisterTarget Delete IAITarget %u %u %i\n", pActor, pEntity, (int)vAITargets.size());
			for (int a = 0; a < (int)vAIActors.size(); a++) {
				if (vAIActors[a]->pTarget == vAITargets[e]) {
					vAIActors[a]->pTarget = 0;
				}
			}
			delete vAITargets[e];
			vAITargets.erase(vAITargets.begin() + e);
			return;
		}
	}
}

typedef void(__thiscall* CPlayer_Destructor_CPlayerClass)(CPlayer* this1);
CPlayer_Destructor_CPlayerClass CPlayer_Destructor_CPlayer = (CPlayer_Destructor_CPlayerClass)0x141222830;



void __fastcall AiCPlayer_Destructor_CPlayerHook(CPlayer* this1, void* None) {

	//printf("CPlayer_Destructor_CPlayerHook %u\n", this1->GetEntity()->Id());

	if (pActorAI != NULL) {
		if (pActorAI->pActor != NULL) {
			if (this1 == pActorAI->pActor)
			{
				pActorAI = NULL;
				MoveToActorShoot = false;
			}
		}
		else {
			pActorAI = NULL;
			MoveToActorShoot = false;
		}
	}

	AiUnregister(this1);
	AiUnregisterTarget(this1, 0);

	CPlayer_Destructor_CPlayer(this1);
	return;
}

struct SEntitySpawnParams {

};

//008D7400 OnBeingReused
typedef void(__thiscall* CEntity_Destructor_CEntityClass)(IEntity* this1);
CEntity_Destructor_CEntityClass CEntity_Destructor_CEntity = (CEntity_Destructor_CEntityClass)0x14080EB80;

void __fastcall CEntity_Destructor_CEntityHook(IEntity* this1, void* None) {

	//printf("CEntity_Destructor_CEntityHook %s\n", this1->GetName());

	AiUnregisterTarget(0, this1);

	CEntity_Destructor_CEntity(this1);
	return;
}



void AISetTarget(AIActor* pAIActor)
{
	if (pAIActor->pActor->IsDead()) {
		pAIActor->pTarget = 0;
		return;
	}
	Vec3 vActorHeadPos;
	CActor_GetBonePos(pAIActor->pActor, &vActorHeadPos, "Bip01 Head");


	std::vector <IAITarget*> vAITargetsAlive;
	std::vector <IAITarget*> vAITargetsAliveAndVisible;

	for (int i = 0; i < (int)vAITargets.size(); i++) {

		IAITarget* pAITarget = vAITargets[i];

		if (pAITarget->pActor && pAITarget->pActor->IsDead()) {
			continue;
		}

		if (!pAITarget->pActor) {
			continue;
		}

		vAITargetsAlive.push_back(pAITarget);

		Vec3 vTargetHeadPos;

		if (pAITarget->pActor) {
			CActor_GetBonePos(pAITarget->pActor, &vTargetHeadPos, "Bip01 Head");
		}
		else {
			vTargetHeadPos = pAITarget->pEntity->GetWorldTM().GetTranslation();
		}

		if (!pAITarget->pActor) {
			vTargetHeadPos.z += 1.0f;
		}

		if (!AiIsVisible(vActorHeadPos, vTargetHeadPos)) {
			continue;
		}

		vAITargetsAliveAndVisible.push_back(pAITarget);
	}

	if (!pAIActor->pTarget || (pAIActor->pTarget->pActor && pAIActor->pTarget->pActor->IsDead()))
	{
		if ((int)vAITargetsAliveAndVisible.size() > 0) {
			pAIActor->pTarget = vAITargetsAliveAndVisible[(rand() % (int)vAITargetsAliveAndVisible.size())];
			return;
		}
		if ((int)vAITargetsAlive.size() > 0) {
			pAIActor->pTarget = vAITargetsAlive[(rand() % (int)vAITargetsAlive.size())];
			return;
		}
		pAIActor->pTarget = 0;
		return;
	}

	Vec3 vTargetHeadPos;

	if (pAIActor->pTarget->pActor) {
		CActor_GetBonePos(pAIActor->pTarget->pActor, &vTargetHeadPos, "Bip01 Head");
	}
	else {
		vTargetHeadPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
	}

	if (!pAIActor->pTarget->pActor) {
		vTargetHeadPos.z += 1.0f;
	}

	

	if (!AiIsVisible(vActorHeadPos, vTargetHeadPos)) {
		if ((int)vAITargetsAliveAndVisible.size() > 0) {
			pAIActor->pTarget = vAITargetsAliveAndVisible[(rand() % (int)vAITargetsAliveAndVisible.size())];
		}
	}



}


bool IsWall(Vec3 currentPos, Vec3 direction, float distance) {
	IPhysicalWorld* pPhysicalWorld = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld();
	stRayHit hits[99];
	Vec3 endPos = currentPos + (direction * distance);
	// Вызов RayWorldIntersection
	int hitCount = pPhysicalWorld->RayWorldIntersection(
		currentPos,       // Начальная точка (origin)
		endPos,          // Конечная точка (direction)
		ent_all,         // Тип объекта. Используй нужный объект (например, стену)
		0,               // Флаги
		hits,            // Массив для хранения результатов
		1                // Максимальное количество результатов
	);

	return (hitCount > 0);

}


static int zalupa = 0;

Vec3 RotateDirectionAroundZ(const Vec3& dir, float degrees)
{
	const float radians = degrees * -90.0f + i * 15.0f;
	const float cosA = cosf(radians);
	const float sinA = sinf(radians);

	return Vec3(
		dir.x * cosA - dir.y * sinA,
		dir.x * sinA + dir.y * cosA,
		dir.z // остаётся неизменным
	);
}

//Моя первая логика: (более менее)

/*

if (MoveToActorShoot) {

			if (pActorAI != NULL) {




				if (pActorAI->eActorArchetype != eAA_Melee) {
					if (MoveToActorShoot) {
						if (pActorAI->pActor) {
							if (!pActorAI->pActor->IsDead())
							{
								if (pActorAI != pAIActor && MoveToActorShoot) {

									if (AiIsVisible(vActorHeadPos, pActorAI->pActor->GetEntity()->GetWorldTM().GetTranslation()))
									{
										if (pActorAI == NULL && !MoveToActorShoot) {
											pAIActor->m_State.vMoveTarget.x = 0;
											pAIActor->m_State.vMoveTarget.y = 0;
											pAIActor->m_State.vMoveTarget.z = 0;
											pAIActor->m_State.vMoveDir.x = 0;
											pAIActor->m_State.vMoveDir.y = 0;
											pAIActor->m_State.vMoveDir.z = 0;
											pAIActor->m_State.fMovementUrgency = 0;
											pAIActor->m_State.fDesiredSpeed = 0;
											return;
										}
										if (pActorAI->pActor)
											vTargetWorldPos = pActorAI->pActor->GetEntity()->GetWorldTM().GetTranslation();
									}
								}
								else if (pActorAI == pAIActor) {
									if (pAIActor->pTarget->pActor) {
										vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
									}
									else {
										vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
									}
								}
							}
							else {
								if (pAIActor->pTarget->pActor) {
									if (AiIsVisible(vActorHeadPos, pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation()))
										vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
								}
								else {
									if (AiIsVisible(vActorHeadPos, pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation()))
										vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
								}
							}
						}
					}

				}
				else {
					if (pAIActor->pTarget->pActor) {
						if (AiIsVisible(vActorHeadPos, pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation()))
							vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
					}
					else {
						if (AiIsVisible(vActorHeadPos, pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation()))
							vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
					}
				}



			}
			else {




				if (pAIActor->pTarget->pActor) {
					if (AiIsVisible(vActorHeadPos, pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation()))
						vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
				}
				else {
					if (AiIsVisible(vActorHeadPos, pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation()))
						vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
				}
			}
		}
		else {
			if (pAIActor->pTarget->pActor) {
				if (AiIsVisible(vActorHeadPos, pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation()))
					vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
			}
			else {
				if (AiIsVisible(vActorHeadPos, pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation()))
					vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
			}
		}

*/


#define RWI_NAME_TAG "RayWorldIntersection"
#define MAX_PHYS_THREADS 4



struct AvoidanceState {
	Vec3 currentDir;
	bool avoiding = false;
};
std::unordered_map<AIActor*, AvoidanceState> s_avoidanceMap;

int isRay(Vec3 CamPos, Vec3 vDiff)
{
	SSystemGlobalEnvironment* pSSystemGlobalEnvironment = SSystemGlobalEnvironment::Singleton();

	IPhysicalWorld* v1 = pSSystemGlobalEnvironment->GetIPhysicalWorld();
	ray_hit RayHit;
	int rayFlags(0x0F | 0x400);

	return CPhysicalWorld_RayWorldIntersection(v1, CamPos, vDiff, 0x100 | 1, rayFlags, &RayHit, 1, 0, 0, 0, 0, RWI_NAME_TAG, 0, MAX_PHYS_THREADS);
}

bool IsBlocked(Vec3 from, Vec3 direction, float distance = 15000.f)
{
	IPhysicalWorld* pWorld = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld();
	if (!pWorld)
		return false;

	Vec3 to = from + direction.GetNormalized() * distance;

	stRayHit hit;
	int objTypes = ent_all;  
	int flags = rwi_ignore_terrain_holes | rwi_ignore_noncolliding | rwi_ignore_back_faces | rwi_ignore_solid_back_faces
		//| rwi_stop_at_pierceable | rwi_separate_important_hits
		//| rwi_colltype_bit  | rwi_colltype_any | rwi_queue | rwi_force_pierceable_noncoll
		;             // Всё что можно столкнуть	

	int hits = pWorld->RayWorldIntersection(
		from,
		to - from,           // Направление
		objTypes,
		flags,
		&hit,
		1                   // Только одно попадание
	);

	// Проверим что препятствие ближе, чем мы хотим пройти
	if (hits > 0)
	{
		//printf("1\n");
		return true;
	}

	return false;


}

Vec3 GetAvoidanceDirection(AIActor* pAIActor, Vec3 vNewDirection, Vec3 vCurrentPosition, Vec3 vTargetPosition)
{
	vNewDirection = vNewDirection.GetNormalized();
	const float rayLength = 1.5f;

	if (pAIActor->state == MOVING_TO_TARGET)
	{
		if (isRay(vCurrentPosition, vNewDirection))
		{
			pAIActor->state = AVOIDING_OBSTACLE;

			Vec3 leftDir = Vec3(vNewDirection.z, 0, -vNewDirection.x);
			Vec3 rightDir = Vec3(-vNewDirection.z, 0, vNewDirection.x);

			bool leftFree = !isRay(vCurrentPosition, leftDir); // IsBlocked
			bool rightFree = !isRay(vCurrentPosition, rightDir);

			if (leftFree && !rightFree)
				pAIActor->avoidanceDirection = leftDir;
			else if (!leftFree && rightFree)
				pAIActor->avoidanceDirection = rightDir;
			else if (leftFree && rightFree)
			{
				// Выбираем направление, ближе к цели
				Vec3 toTarget = (vTargetPosition - vCurrentPosition).GetNormalized();
				if (leftDir.Dot(toTarget) > rightDir.Dot(toTarget))
					pAIActor->avoidanceDirection = leftDir;
				else
					pAIActor->avoidanceDirection = rightDir;
			}
			else
			{
				
				pAIActor->avoidanceDirection = +vNewDirection;
			}

			return pAIActor->avoidanceDirection;
		}
		else
		{
			// Путь свободен, двигаемся к цели
			return vNewDirection;
		}
	}
	else if (pAIActor->state == AVOIDING_OBSTACLE)
	{
		if (isRay(vCurrentPosition, pAIActor->avoidanceDirection))
		{
			// Обход свободен, идем в обходном направлении
			return pAIActor->avoidanceDirection;
		}
		else
		{
			// Обход заблокирован, пытаемся сменить сторону
			Vec3 leftDir = Vec3(vNewDirection.z, 0, -vNewDirection.x);
			Vec3 rightDir = Vec3(-vNewDirection.z, 0, vNewDirection.x);

			bool leftFree = !isRay(vCurrentPosition, leftDir);
			bool rightFree = !isRay(vCurrentPosition, rightDir); //rayLength IsBlocked

			if (leftFree)
			{
				pAIActor->avoidanceDirection = leftDir;
				return leftDir;
			}
			else if (rightFree)
			{
				pAIActor->avoidanceDirection = rightDir;
				return rightDir;
			}
			else
			{
				// Нет вариантов — идем назад
				pAIActor->avoidanceDirection = +vNewDirection;
				return pAIActor->avoidanceDirection;
			}
		}
	}
	return vNewDirection;
}

bool AiIsVisible_Unknown(Vec3 CamPos, Vec3 LocPos) { // CamPos - моя позиция, LocPos - позиция додича

	IPhysicalWorld* v1 = SSystemGlobalEnvironment::Singleton()->GetIPhysicalWorld(); if (!v1) return false;

	Vec3 vDiff;
	ray_hit RayHit;
	int rayFlags(0x0F | 0x400);

	vDiff.x = LocPos.x - CamPos.x;
	vDiff.y = LocPos.y - CamPos.y;
	vDiff.z = LocPos.z - CamPos.z;

	Vec3 v20 = CamPos;
	v20.z = v20.z + 1.0;

	Vec3 v21 = CamPos;
	v21.z = v21.z - 1.0;

	Vec3 v22 = CamPos;
	v22.y = v22.y + 1.0;
	v22.z = v22.z + 1.0;

	Vec3 v23 = CamPos;
	v23.y = v23.y - 1.0;
	v23.z = v23.z + 1.0;





	if (!CPhysicalWorld_RayWorldIntersection(v1, v20, vDiff, 257, 1039, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4))
		return false;
	if (!CPhysicalWorld_RayWorldIntersection(v1, v21, vDiff, 257, 1039, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4))
		return false;
	if (!CPhysicalWorld_RayWorldIntersection(v1, v22, vDiff, 257, 1039, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4))
		return false;
	if (!CPhysicalWorld_RayWorldIntersection(v1, v23, vDiff, 0x101, 1039, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4))
		return false;

	return true;

	//return !CPhysicalWorld_RayWorldIntersection(v1, CamPos, vDiff, 0x100 | 1, rayFlags, &RayHit, 1, 0, 0, 0, 0, "RayWorldIntersection", 0, 4);

}

Vec3 GetActorLookDirection(CPlayer* pActor)
{
	CPlayerV2* pActorPlayer = pActor->GetPlayerV2(); if (!pActorPlayer) return ZERO;
	Vec3 vDir = pActorPlayer->m_viewQuatFinal.ToForwardVector();
	Vec3 positionNew = pActor->GetEntity()->GetWorldTM().GetTranslation();
	vDir.GetNormalized();
	positionNew += vDir * 1.25;
	return positionNew;
}

void AiUpdateActorMovement(AIActor* pAIActor) {
	SSystemGlobalEnvironment* pSSGE = SSystemGlobalEnvironment::Singleton(); if (!pSSGE) return;
	IPhysicalWorld* pPhysicalWorld = pSSGE->GetIPhysicalWorld(); if (!pPhysicalWorld) return;

	bool GOTO_LABEL_22 = false;

	if (!pAIActor->pTarget) {
		pAIActor->m_State.vMoveTarget.x = 0;
		pAIActor->m_State.vMoveTarget.y = 0;
		pAIActor->m_State.vMoveTarget.z = 0;
		pAIActor->m_State.vMoveDir.x = 0;
		pAIActor->m_State.vMoveDir.y = 0;
		pAIActor->m_State.vMoveDir.z = 0;
		pAIActor->m_State.fMovementUrgency = 0;
		pAIActor->m_State.fDesiredSpeed = 0;
		return;
	}




	Vec3 vActorWorldPos;
	Vec3 vTargetWorldPos;

	vActorWorldPos = pAIActor->pActor->GetEntity()->GetWorldTM().GetTranslation();

	if (pAIActor->pTarget->pActor) {
		vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
	}
	else {
		vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
	}

	float fDistance = AiGetDistance(vActorWorldPos, vTargetWorldPos);

	if (fDistance <= 4.0f)
		vTargetWorldPos = GetActorLookDirection(pAIActor->pActor);


	if (fDistance <= 1.5f) {
		pAIActor->m_State.vMoveTarget.x = 0;
		pAIActor->m_State.vMoveTarget.y = 0;
		pAIActor->m_State.vMoveTarget.z = 0;
		pAIActor->m_State.vMoveDir.x = 0;
		pAIActor->m_State.vMoveDir.y = 0;
		pAIActor->m_State.vMoveDir.z = 0;
		pAIActor->m_State.fMovementUrgency = 0;
		pAIActor->m_State.fDesiredSpeed = 0;
		return;
	}

	if (AiIsSide(pAIActor->pActor->GetEntity()->GetWorldTM().GetTranslation())) {
		pAIActor->m_State.vMoveTarget.x = 0;
		pAIActor->m_State.vMoveTarget.y = 0;
		pAIActor->m_State.vMoveTarget.z = 0;
		pAIActor->m_State.vMoveDir.x = 0;
		pAIActor->m_State.vMoveDir.y = 0;
		pAIActor->m_State.vMoveDir.z = 0;
		pAIActor->m_State.fMovementUrgency = 0;
		pAIActor->m_State.fDesiredSpeed = 0;
		return;
	}

	Vec3 vActorHeadPos;
	CActor_GetBonePos(pAIActor->pActor, &vActorHeadPos, "Bip01 Head");

	Vec3 vTargetHeadPos;

	if (pAIActor->pTarget->pActor) {
		CActor_GetBonePos(pAIActor->pTarget->pActor, &vTargetHeadPos, "Bip01 Head");
	}
	else {
		vTargetHeadPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
	}

	if (AiIsVisible(vActorHeadPos, vTargetHeadPos))
	{
		if (pAIActor->pTarget->pActor) {
			vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
		}
		else {
			vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
		}
	}

	//if (!AiIsVisible_Unknown(vActorHeadPos, vTargetHeadPos)) {
	//	pAIActor->m_State.vMoveTarget.x = 0;
	//	pAIActor->m_State.vMoveTarget.y = 0;
	//	pAIActor->m_State.vMoveTarget.z = 0;
	//	pAIActor->m_State.vMoveDir.x = 0;
	//	pAIActor->m_State.vMoveDir.y = 0;
	//	pAIActor->m_State.vMoveDir.z = 0;
	//	pAIActor->m_State.fMovementUrgency = 1;
	//	GOTO_LABEL_22 = true;
	//}


	CWeaponGeneral* pWeaponGeneral = CActor_GetCurrentWeapon(pAIActor->pActor);

	if (pWeaponGeneral && CWeaponGeneral_IsReloading(pWeaponGeneral)) {
		pAIActor->m_State.vMoveTarget.x = 0;
		pAIActor->m_State.vMoveTarget.y = 0;
		pAIActor->m_State.vMoveTarget.z = 0;
		pAIActor->m_State.vMoveDir.x = 0;
		pAIActor->m_State.vMoveDir.y = 0;
		pAIActor->m_State.vMoveDir.z = 0;
		pAIActor->m_State.fMovementUrgency = 0;
		pAIActor->m_State.fDesiredSpeed = 0;
		return;
	}

	if ( pAIActor->eActorArchetype == eAA_Robot) {
		pAIActor->m_State.vMoveTarget.x = 0;
		pAIActor->m_State.vMoveTarget.y = 0;
		pAIActor->m_State.vMoveTarget.z = 0;
		pAIActor->m_State.vMoveDir.x = 0;
		pAIActor->m_State.vMoveDir.y = 0;
		pAIActor->m_State.vMoveDir.z = 0;
		pAIActor->m_State.fMovementUrgency = 0;
		pAIActor->m_State.fDesiredSpeed = 0;
		return;
	}


	if (!GOTO_LABEL_22) {

		pAIActor->m_State.vMoveTarget = vTargetWorldPos;
		pAIActor->m_State.vMoveDir.x = 1;
		pAIActor->m_State.vMoveDir.y = 0;
		pAIActor->m_State.vMoveDir.z = 0;
		pAIActor->m_State.fMovementUrgency = 1;
	}

	if (fDistance <= 6.0f && (pAIActor->eActorArchetype == eAA_ShieldBearer || pAIActor->eActorArchetype == eAA_SMGShieldBearer)) {
		pAIActor->m_State.fDesiredSpeed = pAIActor->fSpeed * 2;
		return;
	}

	pAIActor->m_State.fDesiredSpeed = pAIActor->fSpeed;



}

typedef void(__thiscall* Returner)();
Returner Returner_p = (Returner)0x0000000140CCA238;



void AiUpdateActorShoot_OLD_CODE(AIActor* pAIActor, __int64 frameStartTime) {
	if (!pAIActor->pTarget) {
		pAIActor->m_State.vShootTargetPos.x = 0;
		pAIActor->m_State.vShootTargetPos.y = 0;
		pAIActor->m_State.vShootTargetPos.z = 0;
		pAIActor->m_State.vAimTargetPos.x = 0;
		pAIActor->m_State.vAimTargetPos.y = 0;
		pAIActor->m_State.vAimTargetPos.z = 0;
		pAIActor->m_State.vLookTargetPos.x = 0;
		pAIActor->m_State.vLookTargetPos.y = 0;
		pAIActor->m_State.vLookTargetPos.z = 0;
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_Off;
		return;
	}

	CWeaponGeneral* pWeaponGeneral = CActor_GetCurrentWeapon(pAIActor->pActor);

	if (pWeaponGeneral && CWeaponGeneral_IsReloading(pWeaponGeneral)) {
		pAIActor->m_State.vShootTargetPos.x = 0;
		pAIActor->m_State.vShootTargetPos.y = 0;
		pAIActor->m_State.vShootTargetPos.z = 0;
		pAIActor->m_State.vAimTargetPos.x = 0;
		pAIActor->m_State.vAimTargetPos.y = 0;
		pAIActor->m_State.vAimTargetPos.z = 0;
		pAIActor->m_State.vLookTargetPos.x = 0;
		pAIActor->m_State.vLookTargetPos.y = 0;
		pAIActor->m_State.vLookTargetPos.z = 0;
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_Off;
		return;
	}

	if (pWeaponGeneral && CWeaponGeneral_GetAmmoCount(pWeaponGeneral) < 1) {
		CWeaponGeneral_Reload(pWeaponGeneral, false, true);
	}

	Vec3 vActorHeadPos;
	CActor_GetBonePos(pAIActor->pActor, &vActorHeadPos, "Bip01 Head");

	Vec3 vTargetHeadPos;

	if (pAIActor->pTarget->pActor) {
		CActor_GetBonePos(pAIActor->pTarget->pActor, &vTargetHeadPos, "Bip01 Head");
	}
	else {
		vTargetHeadPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
	}

	if (!AiIsVisible(vActorHeadPos, vTargetHeadPos)) {
		pAIActor->m_State.vShootTargetPos.x = 0;
		pAIActor->m_State.vShootTargetPos.y = 0;
		pAIActor->m_State.vShootTargetPos.z = 0;
		pAIActor->m_State.vAimTargetPos.x = 0;
		pAIActor->m_State.vAimTargetPos.y = 0;
		pAIActor->m_State.vAimTargetPos.z = 0;
		pAIActor->m_State.vLookTargetPos.x = 0;
		pAIActor->m_State.vLookTargetPos.y = 0;
		pAIActor->m_State.vLookTargetPos.z = 0;
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_Off;
		return;
	}

	//If actor fallen
	if (pAIActor->eActorArchetype == eAA_Robot) {
		pAIActor->m_State.vShootTargetPos.x = 0;
		pAIActor->m_State.vShootTargetPos.y = 0;
		pAIActor->m_State.vShootTargetPos.z = 0;
		pAIActor->m_State.vAimTargetPos.x = 0;
		pAIActor->m_State.vAimTargetPos.y = 0;
		pAIActor->m_State.vAimTargetPos.z = 0;
		pAIActor->m_State.vLookTargetPos.x = 0;
		pAIActor->m_State.vLookTargetPos.y = 0;
		pAIActor->m_State.vLookTargetPos.z = 0;
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_Off;
		return;
	}



	pAIActor->m_State.vShootTargetPos = vTargetHeadPos;
	pAIActor->m_State.vAimTargetPos = vTargetHeadPos;
	pAIActor->m_State.vLookTargetPos = vTargetHeadPos;

	//pAIActor->m_State.vDesiredBodyDirectionAtTarget = vTargetHeadPos;
	//pAIActor->m_State.aimTargetIsValid = true;
	//pAIActor->m_State.bodystate = 0;
	//
	//pAIActor->m_State.eLookStyle = LOOKSTYLE_HARD_NOLOWER;

	Vec3 vActorWorldPos;
	Vec3 vTargetWorldPos;

	vActorWorldPos = pAIActor->pActor->GetEntity()->GetWorldTM().GetTranslation();

	if (pAIActor->pTarget->pActor) {
		vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
	}
	else {
		vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
	}

	float fDistance = AiGetDistance(vActorWorldPos, vTargetWorldPos);

	if (pAIActor->fFireMeleeMaxDistance != 0.0f && (pAIActor->fFireMeleeMaxDistance == -1.0f || pAIActor->fFireMeleeMaxDistance >= fDistance)) {
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_On;
	}

	else if (pAIActor->fFireMaxDistance != 0.0f && (pAIActor->fFireMaxDistance == -1.0f || pAIActor->fFireMaxDistance >= fDistance)) {

		if (frameStartTime - pAIActor->iTempStartShootTime > 300000 || frameStartTime - pAIActor->iTempStartShootTime < 100000 || pAIActor->eActorArchetype != eAA_Assault) {
			pAIActor->m_State.fire = eAIFS_On;
			pAIActor->m_State.fireSecondary = eAIFS_Off;
			pAIActor->m_State.fireMelee = eAIFS_Off;

			if (frameStartTime - pAIActor->iTempStartShootTime > 300000) {
				pAIActor->iTempStartShootTime = frameStartTime;
			}
		}
		else {
			pAIActor->m_State.fire = eAIFS_Off;
			pAIActor->m_State.fireSecondary = eAIFS_Off;
			pAIActor->m_State.fireMelee = eAIFS_Off;
		}

	}
	else {
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_Off;
	}
}

void AiUpdateActorShoot(AIActor* pAIActor, __int64 frameStartTime)
{

	if (pAIActor->pTarget == 0) {
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_Off;
		return;
	}



	CWeaponGeneral* pWeaponGeneral = CActor_GetCurrentWeapon(pAIActor->pActor);

	if (pWeaponGeneral) {

		int ammoCount = CWeaponGeneral_GetAmmoCount(pWeaponGeneral);

		if (ammoCount < 1) {//TODO is Reloading

			CWeaponGeneral_Reload(pWeaponGeneral, false, false);

			if (pAIActor->eActorArchetype == eAA_HeavyGunner) {
				return;
			}
		}
	}

	Vec3 pMyPos = pAIActor->pActor->GetEntity()->GetWorldTM().GetTranslation();
	Vec3 myPos = { pMyPos.x, pMyPos.y, pMyPos.z };

	float distanceToTarget = AiGetDistance(myPos, pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation());

	Vec3 targetBodyPos;
	Vec3 vActorHeadPos;
	CActor_GetBonePos(pAIActor->pActor, &vActorHeadPos, "Bip01 Head");



	if (pAIActor->pTarget->pActor) {
		CActor_GetBonePos(pAIActor->pTarget->pActor, &targetBodyPos, "Bip01 Head");
	}
	else {
		targetBodyPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
	}

	if (!AiIsVisible(vActorHeadPos, targetBodyPos)) {
		pAIActor->m_State.vShootTargetPos.x = 0;
		pAIActor->m_State.vShootTargetPos.y = 0;
		pAIActor->m_State.vShootTargetPos.z = 0;
		pAIActor->m_State.vAimTargetPos.x = 0;
		pAIActor->m_State.vAimTargetPos.y = 0;
		pAIActor->m_State.vAimTargetPos.z = 0;
		pAIActor->m_State.vLookTargetPos.x = 0;
		pAIActor->m_State.vLookTargetPos.y = 0;
		pAIActor->m_State.vLookTargetPos.z = 0;
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_Off;
		MoveToActorShoot = false;
		return;
	}

	if ((pAIActor->eActorArchetype == eAA_Melee || pAIActor->eActorArchetype == eAA_ShieldBearer || pAIActor->eActorArchetype == eAA_SMGShieldBearer) && distanceToTarget < 6) {
		if (distanceToTarget < 1.5f) {
			pAIActor->m_State.fire = eAIFS_Off;
			pAIActor->m_State.fireSecondary = eAIFS_Off;
			pAIActor->m_State.fireMelee = eAIFS_On;

		}
		else {
			pAIActor->m_State.fire = eAIFS_Off;
			pAIActor->m_State.fireSecondary = eAIFS_Off;
			pAIActor->m_State.fireMelee = eAIFS_Off;
		}
	}
	else if ((pAIActor->eActorArchetype == eAA_Sniper || pAIActor->eActorArchetype == eAA_Shotgunner || pAIActor->eActorArchetype == eAA_Assault || pAIActor->eActorArchetype == eAA_Demoman || pAIActor->eActorArchetype == eAA_Specop) && distanceToTarget < 1) {
		pAIActor->m_State.fire = eAIFS_Off;
		pAIActor->m_State.fireSecondary = eAIFS_Off;
		pAIActor->m_State.fireMelee = eAIFS_On;
	}
	else {

		if (frameStartTime - pAIActor->iTempStartShootTime > 200000 || frameStartTime - pAIActor->iTempStartShootTime < 100000 || pAIActor->eActorArchetype != eAA_Assault) {
			pAIActor->m_State.fire = eAIFS_On;
			pAIActor->m_State.fireSecondary = eAIFS_Off;
			pAIActor->m_State.fireMelee = eAIFS_Off;

			if (frameStartTime - pAIActor->iTempStartShootTime > 200000) {
				pAIActor->iTempStartShootTime = frameStartTime;
			}
		}
		else {
			pAIActor->m_State.fire = eAIFS_Off;
			pAIActor->m_State.fireSecondary = eAIFS_Off;
			pAIActor->m_State.fireMelee = eAIFS_Off;
		}
	}

	pAIActor->m_State.vShootTargetPos = targetBodyPos;
	pAIActor->m_State.vAimTargetPos = targetBodyPos;
	pAIActor->m_State.vLookTargetPos = targetBodyPos;
	pActorAI = pAIActor;
}


/*1414807B0*/

typedef bool(__thiscall* CActorInventory_SelectWeaponByNameClass)(ActorInventory* this1, const char* name);
CActorInventory_SelectWeaponByNameClass CActorInventory_SelectWeaponByName = (CActorInventory_SelectWeaponByNameClass)0x1414807B0;


void AiUpdateWeapon(AIActor* pAIActor) {
	if (!pAIActor->pTarget) {
		return;
	}
	ActorInventory* pActorInventory = pAIActor->pActor->GetInventory();

	Vec3 vActorWorldPos;
	Vec3 vTargetWorldPos;

	vActorWorldPos = pAIActor->pActor->GetEntity()->GetWorldTM().GetTranslation();

	if (pAIActor->pTarget->pActor) {
		vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
	}
	else {
		vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
	}

	float distanceToTarget = AiGetDistance(vActorWorldPos, vTargetWorldPos);

	if (pAIActor->eActorArchetype == eAA_Assault) {
		
		if (distanceToTarget > 4 && distanceToTarget < 11) {
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_u");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_h");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_n");
		}
		else {
			CActorInventory_SelectWeaponByName(pActorInventory, "ar57"); //ar16_hst_ai_n
			CActorInventory_SelectWeaponByName(pActorInventory, "ar57"); //ar16_hst_ai_u
			CActorInventory_SelectWeaponByName(pActorInventory, "ar57"); //ar16_hst_ai_w
		}
		
		//CActorInventory_SelectWeaponByName(pActorInventory, "pt01_ai_e");
		//CActorInventory_SelectWeaponByName(pActorInventory, "pt01_ai");
		//CActorInventory_SelectWeaponByName(pActorInventory, "pt01_ai_h");
	}
	else if (pAIActor->eActorArchetype == eAA_Shotgunner) {
		if (distanceToTarget > 9) {
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_u");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_h");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_n");
		}
		else {
			CActorInventory_SelectWeaponByName(pActorInventory, "shg12_v_ai_n");
			CActorInventory_SelectWeaponByName(pActorInventory, "shg12_v_ai_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "shg12_v_ai_h");
		}
	}
	else if (pAIActor->eActorArchetype == eAA_Sniper) {
		if (distanceToTarget > 9) {
			CActorInventory_SelectWeaponByName(pActorInventory, "sr08_ib_ai_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "sr08_ib_ai_h");
			CActorInventory_SelectWeaponByName(pActorInventory, "sr08_ib_ai_n");
		}
		else {
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_u");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_h");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_n");
		}
	}
	else if (pAIActor->eActorArchetype == eAA_Melee) {

	}
	else if (pAIActor->eActorArchetype == eAA_ShieldBearer) {
		if (distanceToTarget > 5) {
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_u");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_h");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_n");
		}
		else {
			CActorInventory_SelectWeaponByName(pActorInventory, "ml01_ai_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "ml01_ai");
			CActorInventory_SelectWeaponByName(pActorInventory, "ml01_ai_h");
		}
	}
	else if (pAIActor->eActorArchetype == eAA_SMGShieldBearer) {

	}
	else if (pAIActor->eActorArchetype == eAA_HeavyGunner) {

	}
	else if (pAIActor->eActorArchetype == eAA_Demoman) {
		if (distanceToTarget > 9) {
			CActorInventory_SelectWeaponByName(pActorInventory, "rl01_ai_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "rl01_ai");
			CActorInventory_SelectWeaponByName(pActorInventory, "rl01_ai_h");
		}
		else {
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_u");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_h");
			CActorInventory_SelectWeaponByName(pActorInventory, "pt23_ct01_ai_n");
		}
	}
	else if (pAIActor->eActorArchetype == eAA_Specop) {

	}
	else if (pAIActor->eActorArchetype == eAA_Helicopter) {
		if (distanceToTarget > 30) {
			CActorInventory_SelectWeaponByName(pActorInventory, "mg_helicopter_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "mg_helicopter");
			CActorInventory_SelectWeaponByName(pActorInventory, "mg_helicopter_h");
		}
		else if (distanceToTarget > 15) {
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_left_helicopter_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_left_helicopter");
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_left_helicopter_h");
		}
		else {
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_right_helicopter_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_right_helicopter");
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_right_helicopter_h");
		}
	}
	else if (pAIActor->eActorArchetype == eAA_Drone) {

	}
	else if (pAIActor->eActorArchetype == eAA_Robot) {
		if (distanceToTarget > 20) {
			CActorInventory_SelectWeaponByName(pActorInventory, "mg_robot_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "mg_robot");
			CActorInventory_SelectWeaponByName(pActorInventory, "mg_robot_h");
		}
		else {
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_robot_e");
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_robot");
			CActorInventory_SelectWeaponByName(pActorInventory, "rl_robot_h");
		}
	}
	else if (pAIActor->eActorArchetype == eAA_Other) {

	}

}

/*void AiUpdateCyborgBarrelmanExplosion(AIActor* pAIActor) {

	if (!pAIActor->pTarget) {
		return;
	}

	if (pAIActor->eActorArchetype != eAA_CyborgBarrelman) {
		return;
	}

	Vec3 vActorWorldPos;
	Vec3 vTargetWorldPos;

	vActorWorldPos = pAIActor->pActor->GetEntity()->GetWorldTM().GetTranslation();

	if (pAIActor->pTarget->pActor) {
		vTargetWorldPos = pAIActor->pTarget->pActor->GetEntity()->GetWorldTM().GetTranslation();
	}
	else {
		vTargetWorldPos = pAIActor->pTarget->pEntity->GetWorldTM().GetTranslation();
	}

	float distanceToTarget = AiGetDistance(vActorWorldPos, vTargetWorldPos);

	if (distanceToTarget < 2) {
		SGameHitInfo mGameHitInfo;
		SGameHitInfo_SGameHitInfo0(&mGameHitInfo);
		IGameRules* pGameRules = CGame_GetGameRules(gGame());
		mGameHitInfo.shared.shooterId = pAIActor->pActor->GetEntity()->GetId();
		mGameHitInfo.shared.targetId = pAIActor->pActor->GetEntity()->GetId();
		mGameHitInfo.shared.typeId = pGameRules->GetHitTypeId("fall");
		mGameHitInfo.damage = (float)pAIActor->pActor->GetHealth();
		CGameRules_AddServerHit(pGameRules, &mGameHitInfo);
	}
}*/

void __fastcall AiAI_UpdateHook(__int64 frameStartTime1, float frameDeltaTime2)
{
	//printf("AiAI_UpdateHook\n");
	//Returner_p();
	IGameFramework* pFramework = IGameFramework::Singlenton();
	IActorSystem* pActorSystem = pFramework->GetActorSystem();



	for (int i = 0; i < (int)vAIActors.size(); i++) {
	
		
		AIActor* pAIActor = vAIActors[i];
		AISetTarget(pAIActor);

		IGameFramework* pFramework = IGameFramework::Singlenton(); if (!pFramework) continue;
		float frameStartTime = SSystemGlobalEnvironment::Singleton()->GetTimer()->GetFrameTimer();

		AiUpdateActorMovement(pAIActor);

		AiUpdateActorShoot(pAIActor, frameStartTime);
		AiUpdateWeapon(pAIActor);
		//AiUpdateActorShoot(pAIActor);
		CAIProxy_Update(pAIActor->pAIProxy, pAIActor->m_State, true);

	

	}

}

//find the function containing 'BreakListenerThread' and find like '(*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)v4[26] + 48))(*v80, v80[1])' in asm '004220D6 mov ecx, [esi+68h]',and find ~10bytes down in asm '004220E0 movss xmm0, [ebp+70h+var_50]' and calc 004220E0-004220D6 = 10,and find like '&& v4[26]' in asm '00422086 jz short loc_4220E0'

void AIHookAI_Update_0() {
	BYTE* pInstructionMov = (BYTE*)0x0000000140CCA21A;

	while (*pInstructionMov != 0x90) {
		Sleep(1);
	}

	DWORD old1;
	VirtualProtect((LPVOID)pInstructionMov, 6, PAGE_READWRITE, &old1);
	memset(pInstructionMov, 0x90, 6);
	*pInstructionMov = 0xE8;
	*(DWORD*)(pInstructionMov + 0x01) = 0 - ((DWORD)(pInstructionMov + 0x01) - ((DWORD)&AiAI_UpdateHook - 4));
	VirtualProtect((LPVOID)pInstructionMov, 6, old1, &old1);
}

void WriteAbsoluteJump64(void* absJumpMemory, void* addrToJumpTo)
{
	uint8_t absJumpInstructions[] =
	{
	  0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //mov r10, addr
	  0x41, 0xFF, 0xE2 //jmp r10
	};

	uint64_t addrToJumpTo64 = (uint64_t)addrToJumpTo;
	memcpy(&absJumpInstructions[2], &addrToJumpTo64, sizeof(addrToJumpTo64));
	memcpy(absJumpMemory, absJumpInstructions, sizeof(absJumpInstructions));
}

void AiHookAI_Update_1() {

	

	BYTE* pInstructionJe = (BYTE*)0x140CCA1D2;

	while (*pInstructionJe != 0x0F) {
		Sleep(1);
	}

	DWORD old2;
	VirtualProtect((LPVOID)pInstructionJe, 6, PAGE_READWRITE, &old2);
	memset(pInstructionJe, 0x90, 6);
	VirtualProtect((LPVOID)pInstructionJe, 6, old2, &old2);
}

//140CCA1ED

void* AllocatePageNearAddress(void* targetAddr)
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	const uint64_t PAGE_SIZE = sysInfo.dwPageSize;

	uint64_t startAddr = (uint64_t(targetAddr) & ~(PAGE_SIZE - 1)); //round down to nearest page boundary
	uint64_t minAddr = min(startAddr - 0x7FFFFF00, (uint64_t)sysInfo.lpMinimumApplicationAddress);
	uint64_t maxAddr = max(startAddr + 0x7FFFFF00, (uint64_t)sysInfo.lpMaximumApplicationAddress);

	uint64_t startPage = (startAddr - (startAddr % PAGE_SIZE));

	uint64_t pageOffset = 1;
	while (1)
	{
		uint64_t byteOffset = pageOffset * PAGE_SIZE;
		uint64_t highAddr = startPage + byteOffset;
		uint64_t lowAddr = (startPage > byteOffset) ? startPage - byteOffset : 0;

		bool needsExit = highAddr > maxAddr && lowAddr < minAddr;

		if (highAddr < maxAddr)
		{
			void* outAddr = VirtualAlloc((void*)highAddr, PAGE_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
			if (outAddr)
				return outAddr;
		}

		if (lowAddr > minAddr)
		{
			void* outAddr = VirtualAlloc((void*)lowAddr, PAGE_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
			if (outAddr != nullptr)
				return outAddr;
		}

		pageOffset++;

		if (needsExit)
		{
			break;
		}
	}

	return nullptr;
}

void InstallHook(void* func2hook, void* payloadFunction)
{
	void* relayFuncMemory = AllocatePageNearAddress(func2hook);
	WriteAbsoluteJump64(relayFuncMemory, payloadFunction); //write relay func instructions

	//now that the relay function is built, we need to install the E9 jump into the target func,
	//this will jump to the relay function
	DWORD oldProtect;
	VirtualProtect(func2hook, 1024, PAGE_EXECUTE_READWRITE, &oldProtect);

	//32 bit relative jump opcode is E9, takes 1 32 bit operand for jump offset
	uint8_t jmpInstruction[5] = { 0xE8, 0x0, 0x0, 0x0, 0x0 };

	//to fill out the last 4 bytes of jmpInstruction, we need the offset between 
	//the relay function and the instruction immediately AFTER the jmp instruction
	const uint64_t relAddr = (uint64_t)relayFuncMemory - ((uint64_t)func2hook + sizeof(jmpInstruction));
	memcpy(jmpInstruction + 1, &relAddr, 4);

	//install the hook
	memcpy(func2hook, jmpInstruction, sizeof(jmpInstruction));
}


void InitAI() 
{
	MhCreateAndEnableHook_AI(*CPlayer_Init, AiCPlayer_InitHook, (LPVOID*)&CPlayer_Init);
	MhCreateAndEnableHook_AI(*CPlayer_Destructor_CPlayer, AiCPlayer_Destructor_CPlayerHook, (LPVOID*)&CPlayer_Destructor_CPlayer);
	MhCreateAndEnableHook_AI(*CEntity_Destructor_CEntity, CEntity_Destructor_CEntityHook, (LPVOID*)&CEntity_Destructor_CEntity);
	//MhCreateAndEnableHook_AI((void*)0x1413E4710, SSADSDFSDFSDFSDF29, (LPVOID*)&SADSDFSDFSDFSDF29_p);
	//MhCreateAndEnableHook_AI((void*)0x140A25B80, SSADSDFSDFSDFSDF30, (LPVOID*)&SADSDFSDFSDFSDF30_p);
	MhCreateAndEnableHook_AI(CallBehaviorConstructor_p, CallBehaviorConstructor, (LPVOID*)&CallBehaviorConstructor_p);
	printf("[CryAISystem] Initialization successfully!\n");
	SetPathAI((void*)0x140591FE4, "\x85", 1);
	SetPathAI((void*)0x140576D9F, "\x90\x90", 1);
	WriteMemSilentNop(0x140576D9F, 39);
	WriteMemSilentNop(0x140591FE1, 11);
	WriteMemSilentNop(0x140CCA1ED,	82);
	AiHookAI_Update_1();
	
	SetPathAI((void*)0x1405952F6, "\xE9\xF5\x01\x00\x00\x90\x90", 7);
	//0x0000000140CCA21A

	InstallHook((void*)0x0000000140CCA21A, AiAI_UpdateHook);

	//AIHookAI_Update_0();


	//SetPathAI((void*)0x140577FF3, "\x90\x90\x90\x90", 4);
	//SetPathAI((void*)0x140578027, "\x90\x90", 2);
	//SetPathAI((void*)0x14059206F, "\x75", 1);

	/* 1405923E4 */




	//SetPathAI((void*)0x1411BF9F6, "\xEB", 1);

}


