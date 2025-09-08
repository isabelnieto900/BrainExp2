//---------------------- AcLinealFuente.cc -------------------------------
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "AcLinealFuente.hh"
#include "G4SystemOfUnits.hh"

AcLinealFuente::AcLinealFuente(){
    particleGun = new G4ParticleGun(1);
    G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("e-");
    particleGun->SetParticleDefinition(particle);
    particleGun->SetParticlePosition(G4ThreeVector(0.0, 0.0, 16*cm));
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0.0, 0.0, -1.0));
    particleGun->SetParticleEnergy(6.0*MeV);
}

AcLinealFuente::~AcLinealFuente(){}
void AcLinealFuente::GeneratePrimaries(G4Event* anEvent){
    particleGun->GeneratePrimaryVertex(anEvent);
}