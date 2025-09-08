//---------AcLinealFuente.hh-------------------------------
#ifndef AcLinealFuente_hh
#define AcLinealFuente_hh
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"

class G4Event;
class AcLinealFuente: public G4VUserPrimaryGeneratorAction{
public:
    AcLinealFuente();
    ~AcLinealFuente();

    void GeneratePrimaries(G4Event*);
private:
    G4ParticleGun* particleGun;
};
#endif