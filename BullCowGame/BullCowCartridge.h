// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
		virtual void BeginPlay() override;
		virtual void OnInput(const FString &Input) override;
		void SetupGame();
		void EndGame();
		void ProcessGuess(const FString &Guess);
		bool IsIsogram(const FString &Guess);
		FString PickWord(const TArray<FString>& WordList);

	private:
		FString HiddenWord; // string variable wrapped in the TEXT unreal macro for encoding
		int32 Lives;
		bool bGameOver;
		const TArray<FString> WordList {TEXT("admin"), TEXT("root"), TEXT("password"), TEXT("user")};
};
