#include "pch.h"
#include "CTimeMgr.h"

#include "CCore.h"

CTimeMgr::CTimeMgr()
	: m_llPrevCount{}
	, m_llCurCount{}
	, m_llFrequency{}
	, m_dDeltaTime(0.f)
	, m_dAcc(0.f)
	, m_iCallCount(0)

{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// �ʱ� ī��Ʈ
	QueryPerformanceCounter(&m_llPrevCount);

	// �ʴ� ī��Ʈ Ƚ��
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	// ���� ī��Ʈ
	QueryPerformanceCounter(&m_llCurCount);

	// ���� �������� ī���ð�, ���� ������ ī���� ���� ���̸� ���Ѵ�.
	m_dDeltaTime = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;
	
	// ���� ī��Ʈ ���� ���� ������ ����(������ ����� ���ؼ�)
	m_llPrevCount = m_llCurCount;

	++m_iCallCount;
	m_dAcc += m_dDeltaTime; // DeltaTime ����

	if (m_dAcc >= 1.f)
	{
		m_iFPS = m_iCallCount;
		m_dAcc = 0.f;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DeltaTime : %f", m_iFPS, m_dDeltaTime);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}
}
