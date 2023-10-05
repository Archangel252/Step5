/**
 * @file TileLandable.cpp
 * @author Aiden Dixon
 */

#include "pch.h"
#include "TileLandable.h"
#include "City.h"

/**
 * Constructor
 * @param city City this tile belongs to
 */
TileLandable::TileLandable(City *city) : Tile(city)
{
}


/**
 * Indicate that this object is about to be deleted by
 * begin dragged into the trash can. If the function
 * override returns false, the delete will not occur.
 * @return true if okay to delete.
*/
bool TileLandable::PendingDelete()
{

    return true;
}

/**
 * This function is called when the AirAmbulance has
 * landed on some other tile. It is no longer accessible to
 * this tile.
*/
void TileLandable::AirAmbulanceIsGone()
{
    mAmbulance = nullptr;
}

/**
 * This function is called when the AirAmbulance has landed on this
 * tile. This tile should now become the launching tile.
*/
void TileLandable::AirAmbulanceHasLanded()
{
    mAmbulance->SetLaunchingTile(this);
}

/**
* Update function
* @param elapsed, time elapsed since update
*/
void TileLandable::Update(double elapsed)
{
    Tile::Update(elapsed);
    if (mAmbulance != nullptr)
    {
        mAmbulance->Update(this, elapsed);
    }

}

/**
* Draw function
* @param dc object that draws
*/
void TileLandable::Draw(wxDC *dc)
{
    Tile::Draw(dc);
    if (mAmbulance != nullptr)
    {
        mAmbulance->Draw(this,dc);
    }

}