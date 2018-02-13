//
// ******************************************************************
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
// ******************************************************************
//
// $Id: B1DetectorConstruction.cc 94307 2015-11-11 13:42:46Z gcosmo $
//
/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "B1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

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
  G4double env_sizeXY = 2*m, env_sizeZ = 2*m;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_AIR");

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //
  // World
  //
  G4double world_sizeXY = 1.2*env_sizeXY;
  G4double world_sizeZ  = 1.2*env_sizeZ;
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
                    G4ThreeVector(0*cm, 0*cm, 0*cm), //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //
  // Shape 1
  //
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

  G4ThreeVector pos1 = G4ThreeVector(0*cm, 0*cm, 13.64*cm);
  //G4ThreeVector pos2 = G4ThreeVector(0*cm, 0*cm, 13.28*cm); //7.54cm + 2.54 cm + 3.20 cm... strange
  G4ThreeVector pos3 = G4ThreeVector(14.13*cm, 0*cm, 31.08*cm);
  //G4ThreeVector pos4= G4ThreeVector(0*cm, 0*cm, 65.435*cm);

  G4double phi = 90*deg;
  // u, v, w are the daughter axes, projected on the mother frame
  G4ThreeVector u = G4ThreeVector(0, 0, 0);
  G4ThreeVector v = G4ThreeVector(-std::sin(phi), 0, std::cos(phi));
  G4ThreeVector w = G4ThreeVector( std::cos(phi), 0, std::sin(phi));
  G4RotationMatrix rotm1 = G4RotationMatrix(u, v, w);
  G4RotationMatrix* rotm1Inv = new G4RotationMatrix(rotm1.inverse());
  G4cout << "\n --> phi = " << phi/deg << " deg;  inverse rotation matrix : ";

  //Rotation of absorption detector
  G4double theta = 39*deg;
  // u, v, w are the daughter axes, projected on the mother frame
  G4ThreeVector r = G4ThreeVector(0, 0, -1*cm);
  G4ThreeVector f = G4ThreeVector(-std::sin(theta), 0,std::cos(theta));
  G4ThreeVector g = G4ThreeVector( std::cos(theta), 0,std::sin(theta));
  G4RotationMatrix rotm2 = G4RotationMatrix(r, f, g);
  G4RotationMatrix* rotm2Inv = new G4RotationMatrix(rotm2.inverse());
  G4cout << "\n --> phi = " << theta/deg << " deg;  inverse rotation matrix : ";


  //Rotation of scattering detector
  G4double thetaScat = 90*deg;
  // u, v, w are the daughter axes, projected on the mother frame
  G4ThreeVector r2 = G4ThreeVector(0, 0, -1*cm);
  G4ThreeVector f2 = G4ThreeVector(-std::sin(thetaScat), std::cos(thetaScat),0);
  G4ThreeVector g2 = G4ThreeVector( std::cos(thetaScat), std::sin(thetaScat),0);
  G4RotationMatrix rotm3 = G4RotationMatrix(r2, f2, g2);
  G4RotationMatrix* rotm3Inv = new G4RotationMatrix(rotm3.inverse());
  G4cout << "\n --> phi = " << theta/deg << " deg;  inverse rotation matrix : ";

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
        new G4LogicalVolume(Absorber, LaBr3, "LogAbs");

  new G4PVPlacement(rotm2Inv,
                  pos3,
                  logicAbs,
                  "AbsorptionDetector",
                  logicEnv,
                  false,
                  2,
                  checkOverlaps);

  //Placement of absorber PMT.
  /*G4double innerRadiusAbs2=2.7*cm;
  G4double outerRadiusAbs2= 2.935*cm;
  G4double ThicknessAbs2=5.625 *cm;
  G4double startAngleAbs2 = 0.*deg;
  G4double spanningAngleAbs2 = 360.*deg;

  G4Tubs* Absorber2=
          new G4Tubs("AbsorptionPMT",
                     innerRadiusAbs2,
                     outerRadiusAbs2,
                     ThicknessAbs2,
                     startAngleAbs2,
                     spanningAngleAbs2);

  G4LogicalVolume* logicAbs2 =
        new G4LogicalVolume(Absorber2, absorberPMT_mat, "LogAbs2");

  new G4PVPlacement(rotm2Inv,
                  pos4,
                  logicAbs2,
                  "AbsorptionPMT",
                  logicEnv,
                  false,
                  3,
                  checkOverlaps);*/



/*  new G4PVPlacement(rotm1Inv,
                    pos2,
                    logicScat,
                    "ScatterCrystal2",
                    logicEnv,
                    false,
                    2,
                    checkOverlaps);
*/


/*
  new G4PVPlacement(rotm1Inv,
                    pos4,
                    logicAbs,
                    "Detector2",
                    logicEnv,
                    false,
                    4,
                    checkOverlaps);
*/
//  // Conical section shape
//  G4double shape1_rmina =  1.*cm, shape1_rmaxa = 2.*cm;
//  G4double shape1_rminb =  1.*cm, shape1_rmaxb = 2.*cm;
//  G4double shape1_hz = 5.*cm;
//  G4double shape1_phimin = 0.*deg, shape1_phimax = 360.*deg;
//  G4Cons* solidShape1 =
//    new G4Cons("Shape1",
//    shape1_rmina, shape1_rmaxa, shape1_rminb, shape1_rmaxb, shape1_hz,
//    shape1_phimin, shape1_phimax);

//  G4LogicalVolume* logicShape1 =
//    new G4LogicalVolume(solidShape1,         //its solid
//                        shape1_mat,          //its material
//                        "Shape1");           //its name

//  new G4PVPlacement(0,                       //no rotation
//                    pos1,                    //at position
//                    logicShape1,             //its logical volume
//                    "Shape1",                //its name
//                    logicEnv,                //its mother  volume
//                    false,                   //no boolean operation
//                    0,                       //copy number
//                    checkOverlaps);          //overlaps checking

  //
  // Shape 2
  //
//  G4Material* shape2_mat = nist->FindOrBuildMaterial("G4_BONE_COMPACT_ICRU");
//  G4ThreeVector pos2 = G4ThreeVector(0, -1*cm, 7*cm);

//  // Trapezoid shape
//  G4double shape2_dxa = 3*cm, shape2_dxb = 5*cm;
//  G4double shape2_dya = 1*cm, shape2_dyb = 6*cm;
//  G4double shape2_dz  = 5*cm;
//  G4Trd* solidShape2 =
//    new G4Trd("Shape2",                      //its name
//              0.5*shape2_dxa, 0.5*shape2_dxb,
//              0.5*shape2_dya, 0.5*shape2_dyb, 0.5*shape2_dz); //its size

//  G4LogicalVolume* logicShape2 =
//    new G4LogicalVolume(solidShape2,         //its solid
//                        shape2_mat,          //its material
//                        "Shape2");           //its name

//  new G4PVPlacement(0,                       //no rotation
//                    pos2,                    //at position
//                    logicShape2,             //its logical volume
//                    "Shape2",                //its name
//                    logicEnv,                //its mother  volume
//                    false,                   //no boolean operation
//                    0,                       //copy number
//                    checkOverlaps);          //overlaps checking

  // Set Shape2 as scoring volume
  //



  fScoringVolume = logicEnv;

  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
