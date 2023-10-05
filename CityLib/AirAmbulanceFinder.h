/**
 * @file AirAmbulance.h
 *
 * @author Aiden Dixon
 *
 * visitor to find if there is an air ambulance
 */

#ifndef CITY_AIRAMBULANCEFINDER_H
#define CITY_AIRAMBULANCEFINDER_H

#include "TileVisitor.h"
#include "TileHospital.h"
#include "TileGrass.h"

class AirAmbulanceFinder : public TileVisitor{
private:
    bool misAmbulance = false;
    std::shared_ptr<AirAmbulance> mAmbulance = nullptr;
    std::shared_ptr<TileLandable> mTile = nullptr;
public:
    /**
     * Find if there is an air ambuance associated with a TIle
     * @return if there is an air ambulance
     */
    int isFound() const { return misAmbulance; }

    /**
     * Find if there is an air ambuance associated with a TIle
     * @return where it is in memeory
     */
    std::shared_ptr<AirAmbulance> isFoundPtr() const { return mAmbulance; }

    /**
     * Find if there is an air ambuance associated with a TIle
     * @return the tile
     */
    std::shared_ptr<TileLandable> isFoundTile() const { return mTile; }


    /**
     * Visit a Hospital object
     * @param building Building we are visiting
     */
    void VisitHospital(TileHospital* hospital) override
    {
        if ((*hospital).GetAmbulance() != nullptr)
        {
            misAmbulance = true;
            mAmbulance = (*hospital).GetAmbulance();
        }
    }
    /**
     * Visit a TileGrass object
     * @param grass Grass tile we are visiting
     */
    void VisitGrass(TileGrass* grass)
    {
        if ((*grass).GetAmbulance() != nullptr)
        {
            misAmbulance = true;
            mAmbulance = (*grass).GetAmbulance();
        }
    }
};


#endif //CITY_AIRAMBULANCEFINDER_H
