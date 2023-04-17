#pragma once

#define SINGLE(Type) \
private:\
	Type();\
	~Type();\
public: \
static Type* GetInst()\
{\
	static Type Inst;\
	return &Inst;\
}

#define fDT CTimeMgr::GetInst()->GetfDT()
#define DT CTimeMgr::GetInst()->GetDT()

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MISSILE,
	MONSTER,

	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END,
};