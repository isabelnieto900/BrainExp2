//---------AcLinealConstruccion.cc------------------
#include "G4Material.hh"
#include "G4VisManager.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Box.hh"
#include "G4ThreeVector.hh"
#include "G4VisAttributes.hh"
#include "AcLinealConstruccion.hh"
#include "G4SystemOfUnits.hh"

AcLinealConstruccion::AcLinealConstruccion():NIST(G4VisManager::Instance()){}
AcLinealConstruccion::~AcLinealConstruccion(){}

G4VPhysicalVolume* AcLinealConstruccion::Construct(){
    G4Material* Aire = NIST->FindOrBuildMaterial("G4_AIR");

    // World
    G4Box* World_geo = new G4Box("World", 60.*cm, 60.*cm, 60.*cm);
    G4LogicalVolume* World_log = new G4LogicalVolume(World_geo, Aire, "World_log", 0, 0, 0);
    G4VPhysicalVolume* World_phys = new G4PVPlacement(0, G4ThreeVector(), World_log, "World", 0, false, 0);

    Construct_Fuente(World_log, -9.6*cm);
    Construct_Colimador(World_log, -6.9*cm);
    Construct_Cerebro(World_log, -6.9*cm);
    Construct_MEsqueletico(World_log, -6.9*cm);
    Construct_HCortical(World_log, -2.9*cm);

    return World_phys;
}

// ----------- Fuente de Radiacion -----------
void AcLinealConstruccion::Construct_Fuente(G4LogicalVolume* mother, G4double posz){
    const G4double Fuente_Espesor = 2.0*cm;
    const G4double Fuente_pos = posz-(Fuente_Espesor/2.0);

    G4Material* Tungsteno = NIST->FindOrBuildMaterial("G4_W");
    G4VisAttributes* Fuente_vis = new G4VisAttributes(G4Colour(0.4, 0.36, 0.91, 1.0));
    Fuente_vis->SetForceSolid(true);
    G4Box* Fuente_geo = new G4Box("Fuente", 0.9*cm, 0.9*cm, Fuente_Espesor/2.0);
    G4LogicalVolume* Fuente_log = new G4LogicalVolume(Fuente_geo, Tungsteno, "Fuente_log");
    Fuente_log->SetVisAttributes(Fuente_vis);

    new G4PVPlacement(0, G4ThreeVector(0,0,Fuente_pos), Fuente_log, "Fuente", mother, false, 0);
}

// ----------- Colimador -----------
void AcLinealConstruccion::Construct_Colimador(G4LogicalVolume* mother, G4double posz){
    G4double r[] = {1.5*cm, 5.5*cm, 5*cm, 5*cm, 1.9*cm};
    G4double z[] = {0, 0.5*cm, 1.5*cm, 3.5*cm, 4.9*cm};
    const G4double ZColi[] = {1.5*cm, 6.1*cm};
    const G4double Z[] = {0, -ZColi[0], -ZColi[0], -(ZColi[0]+ZColi[1])};

    G4Material* Tungsteno = NIST->FindOrBuildMaterial("G4_W");

    G4Polycone* Col_geo = new G4Polycone("Col", 0., 360.*deg, nZ, Z, r, rOut);
    G4LogicalVolume* Col_log = new G4LogicalVolume(Col_geo, Tungsteno, "Coli_1", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0,0,posz), Col_log, "Col", mother, false, 0);

    G4VisAttributes* VAttW = new G4VisAttributes(G4Colour(0.75, 0.76, 0.8, 1.0));
    VAttW->SetForceAuxEdgeVisible(true);
    Col_log->SetVisAttributes(VAttW);
}

//---------------- Musculo Esqueletico -----------------
void AcLinealConstruccion::Construct_MEsqueletico(G4LogicalVolume* mother, G4double posz){
//("G4_MUSCLE_SKELETAL_ICRP");
    G4Material* Musculo = G4NistManager::Instance()->FindOrBuildMaterial("G4_SKIN_ICRP");
    G4cout << Musculo << G4endl;

    G4double musculo_tam=30.0*cm;

    G4Box* ME_geo = new G4Box("BP_g", musculo_tam/2.0, musculo_tam/2.0, musculo_tam/100.0);
    G4LogicalVolume* ME_log = new G4LogicalVolume(ME_geo, Musculo, "ME_l", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0.0*cm, 0.0*cm, posz), ME_log, "MEsqueletico", mother, false, 0);

    G4VisAttributes* vAttMusculo = new G4VisAttributes(G4Colour(1.0, 0.6, 0.6, 0.6));
    vAttMusculo->SetForceSolid(true);
    ME_log->SetVisAttributes(vAttMusculo);
}

//---------------- Hueso cortical -----------------
void AcLinealConstruccion::Construct_HCortical(G4LogicalVolume* mother, G4double posz){
    G4Material* Hueso = G4NistManager::Instance()->FindOrBuildMaterial("G4_BONE_CORTICAL_ICRP");
    G4cout << Hueso << G4endl;

    G4double hueso_tam=30.0*cm;

    G4Box* HC_geo = new G4Box("HC_g", hueso_tam/2.0, hueso_tam/2.0, hueso_tam/30.0);
    G4LogicalVolume* HC_log = new G4LogicalVolume(HC_geo, Hueso, "HC_l", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0.0*cm, 0.0*cm, posz), HC_log, "HCortical", mother, false, 0);

    G4VisAttributes* vAttHueso = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0, 1.0));
    vAttHueso->SetForceSolid(true);
    HC_log->SetVisAttributes(vAttHueso);
}

// ----------- Cerebro -----------
void AcLinealConstruccion::Construct_Cerebro(G4LogicalVolume* mother, G4double posz){
    G4Material* Cerebro = G4NistManager::Instance()->FindOrBuildMaterial("G4_BRAIN_ICRP");
    G4double cerebro_tam=6.0*cm;

    G4Box* Cereb_geo = new G4Box("Cereb", cerebro_tam/2., cerebro_tam/2., cerebro_tam/19.0);
    G4LogicalVolume* Cereb_log = new G4LogicalVolume(Cereb_geo, Cerebro, "Cereb_log", 0, 0, 0);
    new G4PVPlacement(0, G4ThreeVector(0,0,posz), Cereb_log, "Cerebro", mother, false, 0);

    G4VisAttributes* vAttCerebro = new G4VisAttributes(G4Colour(0.8, 0.4, 0.8, 1.0));
    vAttCerebro->SetForceSolid(true);
    Cereb_log->SetVisAttributes(vAttCerebro);
}