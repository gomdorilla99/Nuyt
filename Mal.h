#pragma once
#include "Node.h"

enum MALStatus
{
	MAL_ON_BOARD,
	MAL_ON_BOARD_DOUBLE,
	MAL_ON_BOARD_TRIPLE,
	MAL_SUCCESS_TRIP,
	MAL_READYTOGO,
	MAL_STATE_MAX
};
class Player;
class Game;
class Phys
{
public:
	double x;
	double y;
	double vx;
	double vy;
	double ax;
	double ay;

};

class Mal:public Phys
{
	Player* mpPlayer;
	Phys Particals[10];
	enum MALStatus mStatus;
	Game* mpGame;

	CFont bigFont;

public:
	Node* mpMalLocation;
	//Node* mpDeferedMalLocation;
	Node* mpDestNode;
	Node* mpStartNode;
	Node* mpBackNode;
	bool isDouble;
	bool isTriple;
	
	Mal(Player * pPlayer,Game *pGame)
	{
		mpGame = pGame;
		mpPlayer = pPlayer;
		setMalStatus(MAL_READYTOGO);
		bigFont.CreatePointFont(300, _T("±Ã¼­"));
		isDouble = false;
		isTriple = false;
		mpMalLocation = NULL;
	}

	void setMalLocation(Node * pNode)
	{
		mpMalLocation = pNode;
		x = pNode->getLocation().x;
		y = pNode->getLocation().y;

		vx = 0;
		vy = 0;
		ax = 0;
		ay = 0;
	}

	Node* getMalLocation(Node * pNode)
	{
		if (pNode->getType() == NODE_TYPE_HOME)
		{
			x = mpMalLocation->getLocation().x;
			y = mpMalLocation->getLocation().y;
			vx = 0;
			vy = 0;
			ax = 0;
			ay = 0;
		};
		return mpMalLocation;
	}


	void setMalStatus(enum MALStatus status)
	{
		mStatus = status;
	}
	enum MALStatus getMalStatus()
	{
		return mStatus;
	}
	Node* kickoff(Node* pNode);
	int GetPlayerID();
	void Draw(CDC* pDC);
	Phys* getPhyical();
};