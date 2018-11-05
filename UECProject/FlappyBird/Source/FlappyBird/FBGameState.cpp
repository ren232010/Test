// Fill out your copyright notice in the Description page of Project Settings.

#include "FBGameState.h"




void AFBGameState::AddScore()
{
	Score++;
}

int32 AFBGameState::GetScore()
{
	return Score;
}

void AFBGameState::ResetScore()
{
	Score = 0;
}

