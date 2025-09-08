//--------- AcLinealListaFisica.hh -------------------------------
#ifndef AcLinealListaFisica_hh
#define AcLinealListaFisica_hh
#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class AcLinealListaFisica : public G4VModularPhysicsList{
public:
    AcLinealListaFisica();
    virtual ~AcLinealListaFisica();
    void ConstructParticle();
    void ConstructProcess();
    void SetCuts();

private:
    G4VPhysicsConstructor* FisicaEM;
};
#endif