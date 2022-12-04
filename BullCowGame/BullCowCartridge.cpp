// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Math/UnrealMathUtility.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
        ProcessGuess(Input);
}

FString UBullCowCartridge::PickWord(const TArray<FString>& WordList)
{
    int32 length = WordList.Num() - 1;
    int32 current = FMath::RandRange(0, length);
    return WordList[current];
}

void UBullCowCartridge::SetupGame()
{
    // set the word
    HiddenWord = PickWord(WordList);

    // set the lives
    Lives = HiddenWord.Len();
    PrintLine(FString::Printf(TEXT(".....!@?station h.%as ..E!coun%tered critical$@. damage ... %$log in as# root to se#&nd for help .... \n")));
    PrintLine(FString::Printf(TEXT("pass#w@rd lengtHH: %d, attempts remai..ng: %d \n"), HiddenWord.Len(), Lives));

    // set the win condition
    bGameOver = false;
}

void UBullCowCartridge::ProcessGuess(const FString &Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(FString::Printf(TEXT("[passW0rd3 %s acc3pt..E$3D \n"), *HiddenWord));
        EndGame();
    }
    else if (Lives > 1)
    {
        if (Guess.Len() != HiddenWord.Len())
        {
            Lives--;
            PrintLine(FString::Printf(TEXT("Lives left: %d \n"), Lives));
            PrintLine(TEXT("passW0rd rej3cte$d: ..lengthh $32! invalid .."));
        }
        else if (!IsIsogram(Guess))
        {
            Lives--;
            PrintLine(FString::Printf(TEXT("Lives left: %d \n"), Lives));
            PrintLine(TEXT("passW0rd rej3cte$d: ..not a23#ann isogram ."));
        }
        else
        {
            Lives--;
            PrintLine(FString::Printf(TEXT("Lives left: %d \n"), Lives));
            PrintLine(TEXT("pass.W0rd.. rej.3cte$d:\n"));
        }
    }
    else
    {
        PrintLine(TEXT("passW0rd rese...t $@#!\n"));
        EndGame();
    }
}

bool UBullCowCartridge::IsIsogram(const FString& Guess)
{
    for (int32 i = 0; i < Guess.Len() - 1; i ++)
    {
        for (int32 j = i + 1; j < Guess.Len(); j++)
        {
            if (Guess[i] == Guess[j])
                return false;
        }
    }
    return true;
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("preS3S enter..r to re..try \n"));
}