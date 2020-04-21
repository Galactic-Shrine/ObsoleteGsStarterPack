// Galactic-Shrine © 2019-2020 - Tous droits résérvés.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GeneralProjectSettings.h" // Nécessite le module EngineSettings
#include "ProjectSettingsBP.generated.h"

USTRUCT(BlueprintType)
struct FProjectSettings {

	GENERATED_BODY()

	/** The name of the company (author, provider) that created the project. */
	UPROPERTY(BlueprintReadOnly, Category = Publisher)
	FString CompanyName;

	/** The distinguished name of the company (author, provider) that created the project. */
	UPROPERTY(BlueprintReadOnly, Category = Publisher)
		FString CompanyDistinguishedName;

	/** The project's homepage URL. */
	UPROPERTY(BlueprintReadOnly, Category = Publisher)
		FString Hompage;

	/** The project's support contact information. */
	UPROPERTY(BlueprintReadOnly, Category = Publisher)
		FString SupportContact;

	/** The project's copyright and/or trademark notices. */
	UPROPERTY(BlueprintReadOnly, Category = Legal)
		FString CopyrightNotice;

	/** The project's licensing terms. */
	UPROPERTY(BlueprintReadOnly, Category = Legal)
		FString LicensingTerms;

	/** The project's privacy policy. */
	UPROPERTY(BlueprintReadOnly, Category = Legal)
		FString PrivacyPolicy;

	/** The project's description text. */
	UPROPERTY(BlueprintReadOnly, Category = About)
		FString Description;

	/** The project's unique identifier. */
	UPROPERTY(BlueprintReadOnly, Category = About)
		FString ProjectID;

	/** The project's version number. */
	UPROPERTY(BlueprintReadOnly, Category = About)
		FString ProjectVersion;

	/** The project's name. */
	UPROPERTY(BlueprintReadOnly, Category = About)
		FGuid ProjectName;

	/** The project's title as displayed on the window title bar (can include the tokens {GameName}, {PlatformArchitecture}, {BuildConfiguration} or {RHIName}, which will be replaced with the specified text) */
	UPROPERTY(BlueprintReadOnly, Category = Displayed)
		FText ProjectDisplayedTitle;

	/** Additional data to be displayed on the window title bar in non-shipping configurations (can include the tokens {GameName}, {PlatformArchitecture}, {BuildConfiguration} or {RHIName}, which will be replaced with the specified text) */
	UPROPERTY(BlueprintReadOnly, Category = Displayed)
		FText ProjectDebugTitleInfo;

	/** Should the game's window preserve its aspect ratio when resized by user. */
	UPROPERTY(BlueprintReadOnly, Category = Settings)
		bool bShouldWindowPreserveAspectRatio;

	/** Should the game use a borderless Slate window instead of a window with system title bar and border */
	UPROPERTY(BlueprintReadOnly, Category = Settings)
		bool bUseBorderlessWindow;

	/** Should the game attempt to start in VR, regardless of whether -vr was set on the commandline */
	UPROPERTY(BlueprintReadOnly, Category = Settings)
		bool bStartInVR;

	UPROPERTY(BlueprintReadOnly, Category = Settings)
		bool bAllowClose;

	UPROPERTY(BlueprintReadOnly, Category = Settings)
		bool bAllowMaximize;

	UPROPERTY(BlueprintReadOnly, Category = Settings)
		bool bAllowMinimize;

	UPROPERTY(BlueprintReadOnly, Category = Settings)
		bool bAllowWindowResize;
};

/**
 * 
 */
UCLASS()
class GSSTARTERPACK_API UProjectSettingsBP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:
		/** Recuper la version du projet */
		UFUNCTION(BlueprintPure, meta = (DisplayName = "Game Version", CompactNodeTitle = "GameVersion"), Category = "GalacticShrine|SystemInformation|Game")
			static void GameVersion(FString &PVersion);
			//static FString GameVersion();

	public:
		//UFUNCTION(BlueprintCallable, Category = "GalacticShrine|SystemInformation|Utility")
		UFUNCTION(BlueprintCallable)
			static void GetProjectSettings(FProjectSettings &settings);
	
};
