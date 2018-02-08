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
// $Id: B1SteppingAction.cc 74483 2013-10-09 13:37:06Z gcosmo $
//
/// \file B1SteppingAction.cc
/// \brief Implementation of the B1SteppingAction class

#include <fstream>
#include <iostream>

#include "B1SteppingAction.hh"
#include "B1EventAction.hh"
#include "B1DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4VPhysicalVolume.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::B1SteppingAction(B1EventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fScoringVolume(0)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1SteppingAction::~B1SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1SteppingAction::UserSteppingAction(const G4Step* step)
{

  // get volume of the current step
  G4VPhysicalVolume* volume
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume();

  G4StepPoint* point1 = step->GetPreStepPoint();
  G4ThreeVector pos1 = point1->GetPosition();

  G4Track* track = step->GetTrack();
  G4int trackID = track->GetTrackID();
      
  // check if we are in scoring volume
  //if (volume != fScoringVolume) return;

  // collect energy deposited in this step
  G4double edepStep = step->GetTotalEnergyDeposit();
  G4double edepStepAbsorber = step->GetTotalEnergyDeposit();
  G4double edepStepScatter = step->GetTotalEnergyDeposit();

  const G4VProcess* whichProcess = step->GetPostStepPoint()->GetProcessDefinedStep();
  G4String process = whichProcess->GetProcessName();

  if(volume->GetName() == "Detector1" || volume->GetName() == "Detector2"){


  G4cout << "Energy deposited in volume " << volume->GetName() << " is: " << edepStep
         << "... Through the process: " << process << " AT THE POINT " << pos1 << G4endl;

  fEventAction->AddEdepAbsorb(edepStepAbsorber);
  fEventAction->AddEdep(edepStepAbsorber);

  std::ofstream myfile;
  myfile.open ("results.txt", std::ios_base::app);
  myfile << "This is the volume" << volume->GetName() << "  trackID" << trackID << "  " << edepStepAbsorber <<std::endl;
  myfile.close();
  }

  if(volume->GetName() == "ScatterCrystal1" || volume->GetName() == "ScatterCrystal2"){

      fEventAction->AddEdepScatter(edepStepScatter);
      fEventAction->AddEdep(edepStepScatter);

      std::ofstream myfile;
      myfile.open ("results.txt", std::ios_base::app);
      myfile << "This is the volume" << volume->GetName() << "  track ID" << trackID << "  " << edepStepScatter <<std::endl;
      myfile.close();
  }




}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
