//--------- main(): AcLinealCerebro.cc -------------
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4ScoringManager.hh"
#include "G4UIterminal.hh"
#include "AcLinealConstruccion.hh"
#include "AcLinealListaFisica.hh"
#include "AcLinealFuente.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisExecutive.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

int main(int argc, char** argv){
    G4RunManager* runManager = new G4RunManager;
    G4ScoringManager* scoringManager = G4ScoringManager::GetScoringManager();
    scoringManager->SetVerboseLevel(1);
#ifdef G4VIS_USE
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
#endif

    runManager->SetUserInitialization(new AcLinealConstruccion);
    runManager->SetUserInitialization(new AcLinealListaFisica);
    runManager->SetUserAction(new AcLinealFuente);

    runManager->Initialize();

    if(argc>1){
#ifdef G4UI_USE
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);
        ui->SessionStart();
        delete ui;
#else
        G4UImanager* UIManager = G4UImanager::GetUIpointer();
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UIManager->ApplyCommand(command+fileName);
#endif
    }

#ifdef G4VIS_USE
    delete visManager;
#endif
}
    delete runManager;
    return 0;
}