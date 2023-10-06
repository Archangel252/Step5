/**
 * @file HospitalVisitor.h
 *
 * @author Aiden Dixon
 *
 * visitor to find if there is an open hospital
 */

#include "pch.h"
#include "HospitalVisitor.h"

HospitalVisitor::HospitalVisitor(TileLandable* del)
{
    mDelTile = del;
    mAirAmbi = mDelTile->GetAirAmbulance();
}

void HospitalVisitor::VisitHospital(TileHospital* tile)
{
    if (tile != mDelTile &&  mHospital == nullptr)
        {
            mHospital = tile;
            mAirAmbi->SetLaunchingTile(mHospital);
            mHospital->SetAmbulance(mAirAmbi);

        }
}