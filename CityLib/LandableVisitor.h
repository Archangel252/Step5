/**
 * @file LandableVisitor.h
 *
 * @author Aiden Dixon
 *
 * visitor to count buildings.
 */

#ifndef CITY_LANDABLEVISITOR_H
#define CITY_LANDABLEVISITOR_H

#include "TileVisitor.h"
#include "TileLandable.h"

class LandableVisitor : public TileVisitor {
private:
    bool mIsLandable = false;
public:
    /**
     * return if the land is landable
     * @return a bool
     */
    bool isLandable(){return mIsLandable;}

    ///std::shared_ptr<AirAmbulance> getambulance(){}
    /**
     * Visit a Landable object
     * @param tile we are visiting
     */
    void VisitLandable(TileLandable* tile) override
    {
        mIsLandable = true;
    }
};


#endif //CITY_LANDABLEVISITOR_H
