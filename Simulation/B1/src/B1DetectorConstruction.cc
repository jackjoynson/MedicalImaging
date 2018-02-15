//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B1DetectorConstruction.cc 94307 2015-11-11 13:42:46Z gcosmo $
//
/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "B1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction(G4double theta)
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{
fAngle = theta;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();

  // Envelope parameters
  //
  G4double env_sizeXY = 1.5*m, env_sizeZ = 1.5*m;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_AIR");

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //
  // World
  //
  G4double world_sizeXY = 1.01*env_sizeXY;
  G4double world_sizeZ  = 1.01*env_sizeZ;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  G4Box* solidWorld =
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size

  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name

  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking

  //
  // Envelope
  //
  G4Box* solidEnv =
    new G4Box("Envelope",                    //its name
        0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size

  G4LogicalVolume* logicEnv =
    new G4LogicalVolume(solidEnv,            //its solid
                        env_mat,             //its material
                        "Envelope");         //its name


  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(0, 0, 0), //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  G4Material* scatterer_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
  G4Material* scattererPMT_mat = nist->FindOrBuildMaterial("G4_Al");
  G4Material* absorberPMT_mat = nist->FindOrBuildMaterial("G4_Al");

  //Defining Lanthanum Bromide:
  //Lanthanum as an element
  G4double aLa = 138.90547*g/mole;
  G4Element* elLa = new G4Element("Lanthanum", "La", 57, aLa);

  //Bromium as an element:
  G4double aBr = 79.904*g/mole;
  G4Element* elBr = new G4Element("Bromine", "Br", 35, aBr);

  G4double densityLaBr3 = 5.06*g/cm3;
  G4Material* LaBr3 = new G4Material("Lanthanum Bromide", densityLaBr3, 2);
  LaBr3->AddElement(elLa, 1);
  LaBr3->AddElement(elBr, 3);

  G4double phi = -(fAngle + 90)*deg;
  // u, v, w are the daughter axes, projected on the mother frame
  G4ThreeVector u = G4ThreeVector(0, 0, -1*cm);
  G4ThreeVector v = G4ThreeVector(std::sin(phi), 0, -std::cos(phi));
  G4ThreeVector w = G4ThreeVector( std::cos(phi), 0, std::sin(phi));
  G4RotationMatrix rotm1 = G4RotationMatrix(u, v, w);
  G4RotationMatrix* rotm1Inv = new G4RotationMatrix(rotm1.inverse());

  G4double phi1 = (fAngle + 90)*deg;
  // u, v, w are the daughter axes, projected on the mother frame
  G4ThreeVector u1 = G4ThreeVector(0, 0, -1*cm);
  G4ThreeVector v1 = G4ThreeVector(std::sin(phi1), 0, -std::cos(phi1));
  G4ThreeVector w1 = G4ThreeVector( std::cos(phi1), 0, std::sin(phi1));
  G4RotationMatrix rotm4 = G4RotationMatrix(u1, v1, w1);
  G4RotationMatrix* rotm4Inv = new G4RotationMatrix(rotm4.inverse());

  //Rotation of absorption detector
  G4double theta = fAngle*deg;
  // u, v, w are the daughter axes, projected on the mother frame
  G4ThreeVector r = G4ThreeVector(0, 0, -1*cm);
  G4ThreeVector f = G4ThreeVector(std::sin(theta), 0,-std::cos(theta));
  G4ThreeVector p = G4ThreeVector( std::cos(theta), 0,std::sin(theta));
  G4RotationMatrix rotm2 = G4RotationMatrix(r, f, p);
  G4RotationMatrix* rotm2Inv = new G4RotationMatrix(rotm2.inverse());


  //Rotation of scattering detector
  G4double thetaScat = 90*deg;
  // u, v, w are the daughter axes, projected on the mother frame
  G4ThreeVector r2 = G4ThreeVector(0, 0, -1*cm);
  G4ThreeVector f2 = G4ThreeVector(-std::sin(thetaScat), std::cos(thetaScat),0);
  G4ThreeVector g2 = G4ThreeVector( std::cos(thetaScat), std::sin(thetaScat),0);
  G4RotationMatrix rotm3 = G4RotationMatrix(r2, f2, g2);
  G4RotationMatrix* rotm3Inv = new G4RotationMatrix(rotm3.inverse());

  G4double absorberz = (38.089)*std::cos(theta) + 16.8;
  G4double absorberx = (38.089)*std::sin(theta);

  G4ThreeVector pos1 = G4ThreeVector(0*cm, 0*cm, 16.8*cm);
  //G4ThreeVector pos2 = G4ThreeVector(0*cm, 0*cm, 13.28*cm); //7.54cm + 2.54 cm + 3.20 cm... strange
  G4ThreeVector pos3 = G4ThreeVector(absorberx*cm, 0*cm, absorberz*cm);
  G4ThreeVector pos4= G4ThreeVector(-absorberx*cm, 0*cm, absorberz*cm);

  //Placement of NaI crystal for the scatterer.
  G4double innerRadiusScat=0.*cm;
  G4double outerRadiusScat=2.54 *cm;
  G4double ThicknessScat=2.54 *cm;
  G4double startAngleScat = 0.*deg;
  G4double spanningAngleScat = 360.*deg;

  G4Tubs* ScatterCrystal=
          new G4Tubs("ScatterDetector",
                     innerRadiusScat,
                     outerRadiusScat,
                     ThicknessScat,
                     startAngleScat,
                     spanningAngleScat);

  G4LogicalVolume* logicScat =
        new G4LogicalVolume(ScatterCrystal, scatterer_mat, "LogScatter");

  new G4PVPlacement(rotm3Inv,
                    pos1,
                    logicScat,
                    "ScatterDetector",
                    logicEnv,
                    false,
                    1,
                    checkOverlaps);


  //Placement of NaI PMT
  /*G4double innerRadiusScatPMT=3*cm;
  G4double outerRadiusScatPMT=3.5 *cm;
  G4double ThicknessScatPMT=3.20*cm;
  G4double startAngleScatPMT = 0.*deg;
  G4double spanningAngleScatPMT = 360.*deg;

  G4Tubs* ScatterCrystalPMT=
          new G4Tubs("ScatterPMT",
                     innerRadiusScatPMT,
                     outerRadiusScatPMT,
                     ThicknessScatPMT,
                     startAngleScatPMT,
                     spanningAngleScatPMT);

  G4LogicalVolume* logicScatPMT =
        new G4LogicalVolume(ScatterCrystalPMT, scattererPMT_mat, "LogScatterPMT");

  new G4PVPlacement(0,
                    pos2,
                    logicScatPMT,
                    "ScatterPMT",
                    logicEnv,
                    false,
                    2,
                    checkOverlaps);*/

  //Placement of LaBr3 crystal
  G4double innerRadiusAbs=0.*cm;
  G4double outerRadiusAbs=1.905 *cm;
  G4double ThicknessAbs=1.905 *cm;
  G4double startAngleAbs = 0.*deg;
  G4double spanningAngleAbs = 360.*deg;

  G4Tubs* Absorber=
          new G4Tubs("AbsorptionDetector",
                     innerRadiusAbs,
                     outerRadiusAbs,
                     ThicknessAbs,
                     startAngleAbs,
                     spanningAngleAbs);

  G4LogicalVolume* logicAbs =
        new G4LogicalVolume(Absorber, scatterer_mat, "LogAbs");

  new G4PVPlacement(rotm3Inv,
                  pos3,
                  logicAbs,
                  "AbsorptionDetector1",
                  logicEnv,
                  false,
                  2,
                  checkOverlaps);

//  new G4PVPlacement(rotm3Inv,
//                  pos4,
//                  logicAbs,
//                  "AbsorptionDetector2",
//                  logicEnv,
//                  false,
//                  3,
//                  checkOverlaps);

  fScoringVolume = logicEnv;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
