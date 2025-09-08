//---------AcLinealConstruccion.hh------------------
#include "G4SystemOfUnits.hh"
#ifndef AcLinealConstruccion_hh
#define AcLinealConstruccion_hh
#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4VisManager;
class AcLinealConstruccion : public G4VUserDetectorConstruction {

public:
    AcLinealConstruccion();
    ~AcLinealConstruccion();

    G4VPhysicalVolume* Construct();
    void Construct_Fuente(G4LogicalVolume* eumma, G4double posz);
    void Construct_Colimador(G4LogicalVolume* eumma, G4double posz);
    void Construct_MEsqueletico(G4LogicalVolume* eumma, G4double posz);
    void Construct_HCortical(G4LogicalVolume* eumma, G4double posz);
    void Construct_Cerebro(G4LogicalVolume* eumma, G4double posz);
private:
    G4VisManager *NIST;
};
#endif