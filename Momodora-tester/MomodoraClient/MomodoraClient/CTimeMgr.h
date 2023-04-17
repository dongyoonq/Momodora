#pragma once

class CTimeMgr
{
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;
	// FPS
	// 1 �����Ӵ� �ð� (Delta Time) = 1/FPS

	double			m_dDeltaTime; // ������ ������ �ð���
	double			m_dAcc; // 1�� üũ�� ���� ���� �ð�
	UINT			m_iCallCount; // �Լ� ȣ�� Ƚ�� üũ
	UINT			m_iFPS; // �ʴ� ȣ�� Ƚ��

public:
	void init();
	void update();

public:
	double GetDT() { return m_dDeltaTime; }
	float GetfDT() { return (float)m_dDeltaTime; }
};

