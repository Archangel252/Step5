/**
 * @file TileHospital.cpp
 *
 * @author Aiden Dixon
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "City.h"
#include "TileHospital.h"
#include "MemberReport.h"
#include "AirAmbulance.h"
#include "AirAmbulanceFinder.h"


/// The image to display for the hospital tile
const std::wstring HospitalImage = L"hospital.png";


/// AirAmbulance offset to draw in the x dimension in pixels
const double HospitalAmbulanceOffsetX = -24;

/// AirAmbulance offset to draw in the y dimension in pixels
const double HospitalAmbulanceOffsetY = -122;


/**
 * Constructor
 * @param city The city this is a member of
 */
TileHospital::TileHospital(City* city) : TileLandable(city)
{
    SetImage(HospitalImage);
    SetAmbulanceOffset(HospitalAmbulanceOffsetX, HospitalAmbulanceOffsetY);


    AirAmbulanceFinder visitor;
    city->Accept(&visitor);
    bool found = visitor.isFound();
    if (!found)
    {
        ///AirAmbulance ambulance(city); // Create an AirAmbulance object
        std::shared_ptr<AirAmbulance> ambulance = std::make_shared<AirAmbulance>(city);
        ambulance->SetLaunchingTile(this);
        this->SetAmbulance(ambulance);
    }


}



/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileHospital::XmlSave(wxXmlNode* node)
{
    auto itemNode = TileLandable::XmlSave(node);

    itemNode->AddAttribute(L"type", L"hospital");

    return itemNode;
}


/**
 * Generate a report for this  tile.
 * @param report
*/
void TileHospital::Report(std::shared_ptr<MemberReport> report)
{
    std::wstringstream str;
    str << L"Hospital";

    report->SetReport(str.str());
}

