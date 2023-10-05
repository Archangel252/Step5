/**
 * @file TileGrass.h
 * @author Aiden Dixon
 *
 * Class that implements grass tiles
 */

#ifndef CITY_CITYLIB_TILEGRASS_H
#define CITY_CITYLIB_TILEGRASS_H

#include "TileLandable.h"

/**
 * Class that implements grass tiles
 */
class TileGrass : public TileLandable
{
private:

public:
    TileGrass(City *city);

    ///  Default constructor (disabled)
    TileGrass() = delete;

    ///  Copy constructor (disabled)
    TileGrass(const TileGrass &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    /**
     * accesses the AMbulance
     * @returns Ambulance
     */
    std::shared_ptr<AirAmbulance> TileGrass::GetAmbulance(){return mAmbulance;}

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(TileVisitor* visitor) override { TileLandable::Accept(visitor); visitor->VisitGrass(this); }
};

#endif //CITY_CITYLIB_TILEGRASS_H
