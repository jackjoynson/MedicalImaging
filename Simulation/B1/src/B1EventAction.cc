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
// $Id: B1EventAction.cc 93886 2015-11-03 08:28:26Z gcosmo $
//
/// \file B1EventAction.cc
/// \brief Implementation of the B1EventAction class

#include "B1EventAction.hh"
#include "B1RunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1EventAction::B1EventAction(B1RunAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction),
  fEdep(0.), fEdepAbs1(0.), fEdepAbs2(0.), fEdepScat(0.)
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1EventAction::~B1EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1EventAction::BeginOfEventAction(const G4Event*)
{    
  fEdep = 0.;
  fEdepAbs1 = 0.;
  fEdepAbs2 = 0.;
  fEdepScat = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1EventAction::EndOfEventAction(const G4Event*)
{   
         std::ofstream myfile;
  // accumulate statistics in run action
  fRunAction->AddEdep(fEdep);
  if(fEdepScat > 0){

        G4int eID = 0;
        const G4Event* evt = G4RunManager::GetRunManager()->GetCurrentEvent();
          eID = evt->GetEventID();

        G4cout << "Energy deposited by this photon: " << fEdep << "MeV" << G4endl;

        myfile.open ("resultsscatter.txt", std::ios_base::app);
        myfile << eID << " " << fEdepScat*1000 << std::endl;
        myfile.close();

  }

  if(fEdepAbs1 > 0 && fEdepAbs1 < 0.661){

      G4int eID = 0;
      const G4Event* evt = G4RunManager::GetRunManager()->GetCurrentEvent();
          eID = evt->GetEventID();

        myfile.open ("resultsabsorber1.txt", std::ios_base::app);
        myfile << eID << " " << fEdepAbs1*1000 << std::endl;
        myfile.close();
  }

  if(fEdepAbs2 > 0 && fEdepAbs2 < 0.661){

      G4int eID = 0;
      const G4Event* evt = G4RunManager::GetRunManager()->GetCurrentEvent();
          eID = evt->GetEventID();

        myfile.open ("resultsabsorber2.txt", std::ios_base::app);
        myfile << eID << " " << fEdepAbs2*1000 << std::endl;
        myfile.close();
  }

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
