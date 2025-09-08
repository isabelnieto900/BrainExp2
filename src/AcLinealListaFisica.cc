//--------- AcLinealListaFisica.cc -------------------------------
#include "G4eIonisation.hh"
#include "G4hIonisation.hh"
#include "G4IonConstructor.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4Decay.hh"
#include "AcLinealListaFisica.hh"
#include "G4SystemOfUnits.hh"

AcLinealListaFisica::AcLinealListaFisica(): G4VModularPhysicsList(){
    FisicaEM = new G4EmStandardPhysics(1);
}
AcLinealListaFisica::~AcLinealListaFisica(){}
void AcLinealListaFisica::ConstructParticle(){
    FisicaEM->ConstructParticle();
    G4IonConstructor ions;
    ions.ConstructParticle();
}

void AcLinealListaFisica::ConstructProcess(){
    AddTransportation();
    FisicaEM->ConstructProcess();
}

void AcLinealListaFisica::SetCuts(){
    defaultCutValue = 0.1*mm;
    G4double cutForGamma   = defaultCutValue;
    G4double cutForElectron = defaultCutValue;
    G4double cutForPositron = defaultCutValue;
    SetCutValue(cutForGamma, "gamma");
    SetCutValue(cutForElectron, "e-");
    SetCutValue(cutForPositron, "e+");
    DumpCutValuesTable();
}