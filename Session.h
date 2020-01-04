#pragma once
#include "Node.h"
#include "Mal.h"
#include "Player.h"

class Session
{

	Node *addNode(NodeType type, Node *pNode = nullptr)
	{
		Node *pNewNode = new Node(type);
		if (pNode)
			pNode->SetNextNode(pNewNode);
		return pNewNode;
	}
	Node *pHomeNode;
	Node *pCrossNode;
	Node *pOutNode;
	Node *pBranchNode[4];
	Node *pReadyNode;

	int mUpdateNumber;
	int mTurn;

public:
	Player Player1;
	Player Player2;
	Player Player3;

	Node *getHomeNode()
	{
		return pHomeNode;
	};

	Node *getReadyNode()
	{
		return pReadyNode;
	};

	Session() : Player1(this, 1), Player2(this, 2), Player3(this, 3)
	{
		pHomeNode = NULL;
		pCrossNode = NULL;
		mTurn = -1;
		Player1.GetBrush()->CreateSolidBrush(RGB(100, 0, 0));
		Player2.GetBrush()->CreateSolidBrush(RGB(00, 100,100));
		Player3.GetBrush()->CreateSolidBrush(RGB(200, 150, 0));


		InitalizeNuytPlat();
	}

	void Draw(CDC* pDC)
	{

		DrawPlat(pDC);
	//	DrawMal(pDC);
	
	}

	void DrawPlat(CDC* pDC)
	{
		pDC->Rectangle(0, 0, 1500, 1500);
		mUpdateNumber++;
		if(pHomeNode)
			pHomeNode->Draw(pDC, mUpdateNumber);


		
	}

	void DrawMal(CDC* pDC)
	{
		Player1.Draw(pDC);
		Player2.Draw(pDC);
		Player3.Draw(pDC);

		int count;
		CString strmsg;
		count = Player1.GetSuccessCount();
		strmsg.Format(_T("Player 1: %d"), count);
		pDC->TextOutW(1200, 10, strmsg);
		count = Player2.GetSuccessCount();
		strmsg.Format(_T("Player 2: %d"), count);
		pDC->TextOutW(1200, 110, strmsg);
		count = Player3.GetSuccessCount();
		strmsg.Format(_T("Player 3: %d"), count);
		pDC->TextOutW(1200, 210, strmsg);

	}
	void InitalizeNuytPlat();
	int GetNyutNumber();
	void Run();
};
