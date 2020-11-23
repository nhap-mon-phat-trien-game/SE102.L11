#pragma once
#include "GameObject.h"
#include "Koopa.h"


#define MARIO_WALKING_SPEED		0.01f 
#define MARIO_ACCELERATION_X    0.001f
#define MARIO_SPEED_MAX    0.1f
#define MARIO_SPEED_RUN_MAX    0.2f
#define MARIO_SPEED_RUN  0.15f
#define MARIO_FLY_X    0.1f
#define MARIO_FLY_Y    0.1f
#define SPEED_FIRE_X     0.05f
#define SPEED_FIRE_Y     0.015f

#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_JUMP_DEFLECT_SPEED 0.2f
#define MARIO_GRAVITY			0.002f
#define MARIO_DIE_DEFLECT_SPEED	 0.5f

#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200
#define MARIO_STATE_JUMP			300
#define MARIO_STATE_DIE				400
#define MARIO_STATE_RUN_RIGHT 		500
#define MARIO_STATE_RUN_LEFT 		600
#define MARIO_STATE_FLY_RIGHT 		700
#define MARIO_STATE_FLY_LEFT 		800
#define MARIO_STATE_FIRE_RIGHT 		900
#define MARIO_STATE_FIRE_LEFT 		1000
#define MARIO_STATE_FIRE			1100




#define MARIO_ANI_BIG_IDLE_RIGHT			0
#define MARIO_ANI_BIG_IDLE_LEFT				1
#define MARIO_ANI_SMALL_IDLE_RIGHT			2
#define MARIO_ANI_SMALL_IDLE_LEFT			3
#define MARIO_ANI_RACCOON_IDLE_RIGHT		4
#define MARIO_ANI_RACCOON_IDLE_LEFT			5
#define MARIO_ANI_FIRE_IDLE_RIGHT			6
#define MARIO_ANI_FIRE_IDLE_LEFT			7

#define MARIO_ANI_BIG_WALKING_RIGHT			8
#define MARIO_ANI_BIG_WALKING_LEFT			9
#define MARIO_ANI_SMALL_WALKING_RIGHT		10
#define MARIO_ANI_SMALL_WALKING_LEFT		11
#define MARIO_ANI_RACCOON_WALKING_RIGHT		12
#define MARIO_ANI_RACCOON_WALKING_LEFT		13
#define MARIO_ANI_FIRE_WALKING_RIGHT		14
#define MARIO_ANI_FIRE_WALKING_LEFT			15

#define MARIO_ANI_DIE				16

#define MARIO_ANI_RUN_FLY_RIGHT				17
#define MARIO_ANI_RUN_FLY_LEFT				18
#define MARIO_ANI_FLY_RIGHT					19
#define MARIO_ANI_FLY_LEFT					20
#define ANI_FIRE							21

#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2
#define	MARIO_LEVEL_RACCOON		3
#define	MARIO_LEVEL_FIRE		4

#define MARIO_BIG_BBOX_WIDTH  15
#define MARIO_BIG_BBOX_HEIGHT 27

#define MARIO_RACCOON_BBOX_WIDTH  20
#define MARIO_RACCOON_BBOX_HEIGHT 27

#define MARIO_FIRE_BBOX_WIDTH  15
#define MARIO_FIRE_BBOX_HEIGHT 27

#define MARIO_SMALL_BBOX_WIDTH  15
#define MARIO_SMALL_BBOX_HEIGHT 15

#define MARIO_UNTOUCHABLE_TIME 5000
#define MARIO_FLY_TIME 3000
#define DIE_TIME 100


class CMario : public CGameObject
{
	bool BolFLy = false;
	bool fire =false;
	int level;
	int untouchable;
	float x_fire;
	float y_fire;
	float vx_fire=0;
	float vy_fire=0;
	DWORD untouchable_start;
	DWORD fly_start;
	bool hold = false;
	bool Runhold=false;
public: 
	CMario() : CGameObject()
	{
		level = MARIO_LEVEL_RACCOON;
		untouchable = 0;
	}
	
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	int GetLevel() { return level; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void GetPosition(float& x, float& y) { x = this->x; y = this->y; }
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	float GetVX() { return vx; }
	float GetVY() { return vy; }
	float GetX() { return x; }
	float GetY() { return y; }
	void LevelUp() { if (level < MARIO_LEVEL_FIRE) level++; }
	void LevelDo() { if (level > MARIO_LEVEL_SMALL) level--; }
	void Fly();
	void StopFly(){
		BolFLy = false;
	}
	void Fire() { if(level==MARIO_LEVEL_FIRE) fire = true; }
	void StopFire() { fire = false; }

	~CMario();


public:
	void HoldKoopa();
private: 
	Koopa* koopa;

};