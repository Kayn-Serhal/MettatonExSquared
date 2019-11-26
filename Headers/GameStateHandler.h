#pragma once


enum class GamePlayState
{
	FIGHT = 0,
	OVERWORLD = 1,
	LOADING = 2,
	MOCKTITLE = 3
};

class GameStateHandler {
	
public :
	static GamePlayState currentGamePlayState;
};

