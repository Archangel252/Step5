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

class AirAmbulanceFinder : public TileVisitor{
private:
    bool misAmbulance = false;
public:
    /**
     * Find if there is an air ambuance associated with a TIle
     * @return if there is an air ambulance
     */
    int isFound() const { return misAmbulance; }

    /**
     * Visit a Hospital object
     * @param building Building we are visiting
     */
    void VisitHospital(TileHospital* hospital) override
    {
        if ((*hospital).GetAmbulance() != nullptr)
        {
            misAmbulance = true;
        }
    }
};


#endif //CITY_AIRAMBULANCEFINDER_H
