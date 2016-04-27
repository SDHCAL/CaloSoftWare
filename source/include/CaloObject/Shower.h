#ifndef SHOWER_HH
#define SHOWER_HH

#include <iostream>
#include <vector>
#include <cstring>

#include <CaloObject/CaloHit.h>
#include <CaloObject/CaloCluster.h>
#include <CLHEP/Vector/ThreeVector.h>

namespace algorithm 
{ 
  class ShowerAnalyser; 
} 

namespace caloobject
{
  class Shower
  {
    friend class algorithm::ShowerAnalyser;
  public:
    Shower(std::vector<caloobject::CaloHit*> &vec);
    Shower(std::vector<caloobject::CaloCluster2D*> &vec);
    ~Shower(){;}

    inline const std::vector<caloobject::CaloHit*> &getHits(){return hits;}
    
    inline CLHEP::Hep3Vector getStartingPosition(){return startingPosition;}
    inline int getNhit(){return hits.size();}
    inline float getEnergy(){return energy;}
    inline float getEdep(){return edep;}
    inline int getNlayer(){return nlayer;}
    inline std::vector<float> getThrust()const{return thrust;}
    inline float getReconstructedCosTheta(){return reconstructedCosTheta;}
    inline float getTransverseRatio(){return transverseRatio;}
    inline float getEta(){return eta;}
    inline float getPhi(){return phi;}
    inline float getF1(){return f1;}
    inline float getShowerMax(){return showerMax;}
    inline float getEdepAtMax(){return edepAtMax;}
    inline std::vector<double> &getEdepPerCell(){return edepPerCell;}
    inline bool findInteraction(){return findInteraction_;}
    inline std::vector<double> &getLongitudinal(){return longitudinal;}
    inline std::vector<double> &getTransverse(){return transverse;}
    inline std::vector<double> &getDistancesToAxis(){return distanceToAxis;}
    inline std::vector<double> &getClustersEnergy(){return clustersEnergy;}
    
  protected:
    std::vector<caloobject::CaloHit*> hits;
    std::vector<caloobject::CaloCluster2D*> clusters;
    caloobject::CaloCluster2D* firstIntCluster;
    CLHEP::Hep3Vector startingPosition;
    float energy;
    float edep;
    std::vector<double> edepPerCell;
    int nlayer;
    //shower thrust ; x = thrust[0] + thrust[1]*z ; y = thrust[2] + thrust[3]*z ; 
    std::vector<float> thrust;
    float reconstructedCosTheta;
    float transverseRatio;
    float eta;
    float phi;
    
    float f1; //edep in 10 first layers/total edep
    float showerMax; //x0 unit
    float edepAtMax;

    bool findInteraction_;

    std::vector<double> longitudinal;
    std::vector<double> transverse;
    std::vector<double> distanceToAxis;
    std::vector<double> clustersEnergy;
  };

}
#endif
