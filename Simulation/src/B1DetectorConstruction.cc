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
                    G4ThreeVector(0, 0, 0), //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
 
  //     
  // Shape 1
  //  
  G4Material* detector_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
  G4ThreeVector pos1 = G4ThreeVector(50*cm, 50*cm, 0);
  G4ThreeVector pos2 = G4ThreeVector(-50*cm, 50*cm, 0);
  G4ThreeVector pos3 = G4ThreeVector(50*cm, 75*cm, 0);
  G4ThreeVector pos4 = G4ThreeVector(-50*cm, 75*cm, 0);

    G4double phi = 90*deg;
    // u, v, w are the daughter axes, projected on the mother frame
    G4ThreeVector u = G4ThreeVector(0, 0, -1*cm);
    G4ThreeVector v = G4ThreeVector(-std::sin(phi), std::cos(phi),0.);
    G4ThreeVector w = G4ThreeVector( std::cos(phi), std::sin(phi),0.);
    G4RotationMatrix rotm1 = G4RotationMatrix(u, v, w);
    G4RotationMatrix* rotm1Inv = new G4RotationMatrix(rotm1.inverse());
    G4cout << "\n --> phi = " << phi/deg << " deg;  inverse rotation matrix : ";


  G4double Detector_SizeXY = 50*cm;
  G4double Detector_SizeZ = 10*cm;

  G4Box* NaIDetector =
          new G4Box("Detector", 0.5*Detector_SizeXY, 0.5*Detector_SizeXY, 0.5*Detector_SizeZ);

  G4LogicalVolume* logicDet =
          new G4LogicalVolume(NaIDetector, detector_mat, "Detector1");

  new G4PVPlacement(rotm1Inv,
                    pos1,
                    logicDet,
                    "ScatterCrystal1",
                    logicEnv,
                    false,
                    1,
                    checkOverlaps);

  new G4PVPlacement(rotm1Inv,
                    pos2,
                    logicDet,
                    "ScatterCrystal2",
                    logicEnv,
                    false,
                    2,
                    checkOverlaps);

  new G4PVPlacement(rotm1Inv,
                    pos3,
                    logicDet,
                    "Detector1",
                    logicEnv,
                    false,
                    3,
                    checkOverlaps);

  new G4PVPlacement(rotm1Inv,
                    pos4,
                    logicDet,
                    "Detector2",
                    logicEnv,
                    false,
                    4,
                    checkOverlaps);
        
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
