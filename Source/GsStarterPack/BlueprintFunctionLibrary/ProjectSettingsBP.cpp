// Galactic-Shrine © 2019-2020 - Tous droits résérvés.


#include "ProjectSettingsBP.h"
//#include "GeneralProjectSettings.h" // Nécessite le module EngineSettings
#include "Misc/ConfigCacheIni.h" // Donne l'accès au GConfig

/**
 * Recuper la version du projet
 */
void UProjectSettingsBP::GameVersion(FString &PVersion) {

    PVersion = GetDefault<UGeneralProjectSettings>()->ProjectVersion;
}
/*void UProjectSettingsBP::GameVersion(FString &PVersion) {

    GConfig->GetString(
        TEXT("/Script/EngineSettings.GeneralProjectSettings"),
        TEXT("ProjectVersion"),
        PVersion,
        GGameIni
    );
}
FString UProjectSettingsBP::GameVersion() {

    FString Version;
    GConfig->GetString(
        TEXT("/Script/EngineSettings.GeneralProjectSettings"),
        TEXT("ProjectVersion"),
        PVersion,
        GGameIni
    );
    return PVersion;
}
*/

void UProjectSettingsBP::GetProjectSettings(FProjectSettings &Settings) {

    const UGeneralProjectSettings* ProjectSettings = GetDefault<UGeneralProjectSettings>();

    Settings = FProjectSettings();
    Settings.ProjectVersion = ProjectSettings->ProjectVersion;
    Settings.CopyrightNotice = ProjectSettings->CopyrightNotice;
    Settings.CompanyName = ProjectSettings->CompanyName;
    Settings.bAllowClose = ProjectSettings->bAllowClose;
}