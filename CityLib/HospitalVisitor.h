/**
 * @file HospitalVisitor.h
 *
 * @author Aiden Dixon
 *
 * visitor to find if there is an open hospital
 */

#ifndef CITY_HOSPITALVISITOR_H
#define CITY_HOSPITALVISITOR_H

#include "TileVisitor.h"
#include "TileHospital.h"
#include "TileLandable.h"
#include "AirAmbulance.h"

class HospitalVisitor : public TileVisitor{
private:
    TileLandable* mDelTile = nullptr;
    TileHospital* mHospital = nullptr;
    std::shared_ptr<AirAmbulance> mAirAmbi= nullptr;
public:

    HospitalVisitor(TileLandable* del);

    /**
     * Visit a Hospital object
     * @return Tile Hospital Pointer
     */
    TileHospital* GetHospital(){return mHospital;}
    /**
     * Visit a Hospital object
     * @param tile we are visiting
     */
    void VisitHospital(TileHospital* tile) override;


};


#endif //CITY_HOSPITALVISITOR_H
