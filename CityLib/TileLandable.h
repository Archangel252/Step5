/**
 * @file TileLandable.h
 * @author Aiden Dixon
 *
 * Intermediate base class for tiles that can be
 * landed on by the air ambulance
 */

#ifndef CITY_CITYLIB_TILELANDABLE_H
#define CITY_CITYLIB_TILELANDABLE_H

#include "Tile.h"
#include "AirAmbulance.h"
#include "TileVisitor.h"

/**
 * Intermediate base class for tiles that can be
 * landed on by the air ambulance
 */
class TileLandable : public Tile
{
private:

    /// Air Ambulance drawing offset. This is used to
    /// put the ambulance the correct x,y location on
    /// a hospital roof or a grass tile.
    wxRealPoint mAmbulanceOffset;

protected:
    TileLandable(City *city);

    std::shared_ptr<AirAmbulance> mAmbulance = nullptr;

public:
    /// Default constructor (disabled)
    TileLandable() = delete;

    /// Copy constructor (disabled)
    TileLandable(const TileLandable &) = delete;

    /// Assignment operator
    void operator=(const TileLandable &) = delete;

    /**
     * Get the ambulance offset relative to this tile.
     * @return Ambulance offset
     */
    const wxRealPoint &GetAmbulanceOffset() const {return mAmbulanceOffset;}

    /**
     * Set the ambulance offset relative to this tile.
     * @param x Ambulance X offset
     * @param y Ambulance Y offset
     */
    void SetAmbulanceOffset(double x, double y) {mAmbulanceOffset.x = x; mAmbulanceOffset.y = y;}

    ///  Handle updates for animation
    /// @param elapsed The time since the last update
    void Update(double elapsed) override;

    ///  Drawing of the AirAlbulance specifically
    /// @param dc is the object that draws
    void Draw(wxDC *dc) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(TileVisitor* visitor) override { visitor->VisitLandable(this); }

    /**
     * Set the ambulance
     * @param ambulance
     */
    void SetAirAmbulance(std::shared_ptr<AirAmbulance> ambulance) {mAmbulance = ambulance; }

    /**
     * gets the ambulance
     * @return ambulance
     */
    std::shared_ptr<AirAmbulance> GetAirAmbulance() {return mAmbulance; }


    void AirAmbulanceIsGone();
    void AirAmbulanceHasLanded();
    bool PendingDelete() override;

};

#endif //CITY_CITYLIB_TILELANDABLE_H
