/**
 * @file TileHospital.h
 *
 * @author Aiden Dixon
 *
 * Class that implements a hospital.
 *
 * A hospital is a landable tile for the air ambulance
 */

#pragma once

#include "TileLandable.h"


/**
 * Class that implements a hospital.
 *
 * A hospital is a landable tile for the air ambulance
*/
class TileHospital : public TileLandable
{
private:

public:
    TileHospital(City* city);

    ///  Default constructor (disabled)
    TileHospital() = delete;

    ///  Copy constructor (disabled)
    TileHospital(const TileHospital&) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(TileVisitor* visitor) override { TileLandable::Accept(visitor); visitor->VisitHospital(this); }

    /**
     * accesses the AMbulance
     * @returns Ambulance
     */
    std::shared_ptr<AirAmbulance> TileHospital::GetAmbulance(){return mAmbulance;}
    /**
     * sets the Ambulance
     */
    void TileHospital::SetAmbulance(std::shared_ptr<AirAmbulance> ambulance){ mAmbulance = ambulance;}

};

