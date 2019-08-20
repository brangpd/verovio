/////////////////////////////////////////////////////////////////////////////
// Name:        beam.h
// Author:      Rodolfo Zitellini
// Created:     26/06/2012
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_BEAM_H__
#define __VRV_BEAM_H__

#include "atts_cmn.h"
#include "drawinginterface.h"
#include "layerelement.h"

namespace vrv {

// the maximum allowed number of partials
#define MAX_DURATION_PARTIALS 16

enum { PARTIAL_NONE = 0, PARTIAL_THROUGH, PARTIAL_RIGHT, PARTIAL_LEFT };

//----------------------------------------------------------------------------
// BeamDrawingParams
//----------------------------------------------------------------------------

/**
 * Class for storing drawing parameters when calculating beams.
 * See View::DrawBeam and View::CalcBeam
 * This could be turned into a BeamDrawingInterface
 */

class BeamSegment {
public:
    /**
     * @name Constructors, destructors, and other standard methods
     */
    ///@{
    BeamSegment();
    virtual ~BeamSegment();

    void Reset();

    void CalcBeam(
        Layer *layer, Staff *staff, Doc *doc, BeamDrawingInterface *beamInterface, data_BEAMPLACE place = BEAMPLACE_NONE);

    /**
     *
     */
    const ArrayOfBeamElementCoords *GetElementCoordRefs();

    /**
     * Initializes the m_beamElementCoords vector objects.
     * This is called by Beam::FilterList
     */
    void InitCoordRefs(const ArrayOfBeamElementCoords *beamElementCoords);

    /**
     * Clear the m_beamElementCoords vector and delete all the objects.
     */
    void ClearCoordRefs();

public:
    // values set by CalcBeam
    int m_startingX; // the initial X position of the beam
    int m_startingY; // the initial Y position of the beam
    double m_beamSlope; // the slope of the beam

    /**
     * An array of coordinates for each element
     **/
    ArrayOfBeamElementCoords m_beamElementCoordRefs;
};

//----------------------------------------------------------------------------
// Beam
//----------------------------------------------------------------------------

class Beam : public LayerElement,
             public ObjectListInterface,
             public BeamDrawingInterface,
             public AttColor,
             public AttBeamedWith,
             public AttBeamRend {
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method resets all attribute classes.
     */
    ///@{
    Beam();
    virtual ~Beam();
    virtual void Reset();
    virtual std::string GetClassName() const { return "Beam"; }
    virtual ClassId GetClassId() const { return BEAM; }
    ///@}

    int GetNoteCount() const { return this->GetChildCount(NOTE); }

    /**
     * Add an element (a note or a rest) to a beam.
     * Only Note or Rest elements will be actually added to the beam.
     */
    virtual void AddChild(Object *object);

    /**
     * Return information about the position in the beam.
     * (no const since the cached list is updated)
     */
    ///@{
    bool IsFirstInBeam(LayerElement *element);
    bool IsLastInBeam(LayerElement *element);
    ///@}

    /**
     *
     */
    const ArrayOfBeamElementCoords *GetElementCoords();

    //----------//
    // Functors //
    //----------//

    /**
     * See Object::CalcStem
     */
    virtual int CalcStem(FunctorParams *functorParams);

    /**
     * See Object::ResetDrawing
     */
    virtual int ResetDrawing(FunctorParams *functorParams);

protected:
    /**
     * Filter the flat list and keep only Note and Chords elements.
     * This also initializes the m_beamElementCoords vector
     */
    virtual void FilterList(ArrayOfObjects *childList);

    /**
     * Return the position of the element in the beam.
     * For notes, lookup the position of the parent chord.
     */
    int GetPosition(LayerElement *element);

private:
    //
public:
    /** */
    BeamSegment m_beamSegment;
};

//----------------------------------------------------------------------------
// BeamElementCoord
//----------------------------------------------------------------------------

class BeamElementCoord {
public:
    /**
     * @name Constructors, destructors, and other standard methods
     */
    ///@{
    BeamElementCoord()
    {
        m_element = NULL;
        m_stem = NULL;
    }
    virtual ~BeamElementCoord();

    int m_x;
    int m_y; // represents the point farthest from the beam
    int m_yTop; // y value of topmost note
    int m_yBottom; // y value of bottom-most note
    int m_yBeam; // y value of stem top position
    int m_dur; // drawing duration
    int m_breaksec;
    char m_partialFlags[MAX_DURATION_PARTIALS];
    LayerElement *m_element;
    Stem *m_stem; // a pointer to the stem in order to avoid to have to re-cast it
};

} // namespace vrv

#endif
