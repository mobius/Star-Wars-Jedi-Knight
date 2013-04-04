/**********************************************************************
	Copyright (c) 1997 Immersion Corporation

	Permission to use, copy, modify, distribute, and sell this
	software and its documentation may be granted without fee;
	interested parties are encouraged to request permission from
		Immersion Corporation
		2158 Paragon Drive
		San Jose, CA 95131
		408-467-1900

	IMMERSION DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
	INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
	IN NO EVENT SHALL IMMERSION BE LIABLE FOR ANY SPECIAL, INDIRECT OR
	CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
	LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
	NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
	CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

  FILE:		FeelEllipse.h

  PURPOSE:	Base Ellipse Class for Feelit API Foundation Classes

  STARTED:	10/29/97

  NOTES/REVISIONS:
     3/2/99 jrm (Jeff Mallett): Force-->Feel renaming
	 3/2/99 jrm: Added GetIsCompatibleGUID
	 3/15/99 jrm: __declspec(dllimport/dllexport) the whole class

**********************************************************************/


#if !defined(AFX_FEELELLIPSE_H__135B88C4_4175_11D1_B049_0020AF30269A__INCLUDED_)
#define AFX_FEELELLIPSE_H__135B88C4_4175_11D1_B049_0020AF30269A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef _FFCDLL_
#define DLLFFC __declspec(dllimport)
#else
#define DLLFFC __declspec(dllexport)
#endif

#include "FeelBaseTypes.h"
#include "FeelEffect.h"



//================================================================
// Constants
//================================================================

#define     FEEL_ELLIPSE_DEFAULT_STIFFNESS      5000
#define     FEEL_ELLIPSE_DEFAULT_SATURATION     10000
#define     FEEL_ELLIPSE_DEFAULT_WIDTH          10
#define     FEEL_ELLIPSE_HEIGHT_AUTO            MAXDWORD
#define     FEEL_ELLIPSE_DEFAULT_HEIGHT         FEEL_ELLIPSE_HEIGHT_AUTO
#define     FEEL_ELLIPSE_WALL_WIDTH_AUTO        MAXDWORD
#define     FEEL_ELLIPSE_DEFAULT_WALL_WIDTH     FEEL_ELLIPSE_WALL_WIDTH_AUTO
#define     FEEL_ELLIPSE_DEFAULT_STIFFNESS_MASK FEELIT_FSTIFF_ANYWALL
#define     FEEL_ELLIPSE_DEFAULT_CLIPPING_MASK  FEELIT_FCLIP_NONE

#define     FEEL_ELLIPSE_DEFAULT_CENTER_POINT   FEEL_EFFECT_MOUSE_POS_AT_START

//
// FEEL --> FORCE Wrappers
//
#define     FORCE_ELLIPSE_DEFAULT_STIFFNESS      FEEL_ELLIPSE_DEFAULT_STIFFNESS
#define     FORCE_ELLIPSE_DEFAULT_SATURATION     FEEL_ELLIPSE_DEFAULT_SATURATION
#define     FORCE_ELLIPSE_DEFAULT_WIDTH          FEEL_ELLIPSE_DEFAULT_WIDTH
#define     FORCE_ELLIPSE_HEIGHT_AUTO            FEEL_ELLIPSE_HEIGHT_AUTO
#define     FORCE_ELLIPSE_DEFAULT_HEIGHT         FEEL_ELLIPSE_DEFAULT_HEIGHT
#define     FORCE_ELLIPSE_WALL_WIDTH_AUTO        FEEL_ELLIPSE_WALL_WIDTH_AUTO
#define     FORCE_ELLIPSE_DEFAULT_WALL_WIDTH     FEEL_ELLIPSE_DEFAULT_WALL_WIDTH
#define     FORCE_ELLIPSE_DEFAULT_STIFFNESS_MASK FEEL_ELLIPSE_DEFAULT_STIFFNESS_MASK
#define     FORCE_ELLIPSE_DEFAULT_CLIPPING_MASK  FEEL_ELLIPSE_DEFAULT_CLIPPING_MASK

#define     FORCE_ELLIPSE_DEFAULT_CENTER_POINT   FEEL_ELLIPSE_DEFAULT_CENTER_POINT




//================================================================
// CFeelEllipse
//================================================================

//
// ------ PUBLIC INTERFACE ------ 
//

class DLLFFC CFeelEllipse : public CFeelEffect
{
    //
    // CONSTRUCTOR/DESCTRUCTOR
    //

    public:
    
    // Constructor
	CFeelEllipse();

	// Destructor
	virtual
	~CFeelEllipse();


    //
    // ATTRIBUTES
    //

    public:

	virtual BOOL
	GetIsCompatibleGUID(
		GUID &guid
		);

    BOOL
    ChangeParameters( 
        POINT pntCenter,
        DWORD dwWidth = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwHeight = FEEL_EFFECT_DONT_CHANGE,
        LONG lStiffness = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwWallWidth = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwSaturation = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwStiffnessMask = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwClippingMask = FEEL_EFFECT_DONT_CHANGE,
        CFeelEffect* pInsideEffect = (CFeelEffect*) FEEL_EFFECT_DONT_CHANGE  
        );

    BOOL
    ChangeParameters( 
        LPCRECT pRectOutside,
        LONG lStiffness = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwWallWidth = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwSaturation = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwStiffnessMask = FEEL_EFFECT_DONT_CHANGE,
        DWORD dwClippingMask = FEEL_EFFECT_DONT_CHANGE,
        CFeelEffect* pInsideEffect = (CFeelEffect*) FEEL_EFFECT_DONT_CHANGE  
        );


    BOOL
    SetRect( 
        LPCRECT pRect 
        );


    BOOL
    SetCenter( 
        POINT pntCenter 
        );


    BOOL
    SetCenter( 
        LONG x, 
        LONG y 
        );


    //
    // OPERATIONS
    //

    public:

    BOOL 
    Initialize( 
        CFeelDevice* pDevice, 
        DWORD dwWidth = FEEL_ELLIPSE_DEFAULT_WIDTH,
        DWORD dwHeight = FEEL_ELLIPSE_DEFAULT_HEIGHT,
        LONG lStiffness = FEEL_ELLIPSE_DEFAULT_STIFFNESS,
        DWORD dwWallWidth = FEEL_ELLIPSE_DEFAULT_WALL_WIDTH,
        DWORD dwSaturation = FEEL_ELLIPSE_DEFAULT_SATURATION,
        DWORD dwStiffnessMask = FEEL_ELLIPSE_DEFAULT_STIFFNESS_MASK,
        DWORD dwClippingMask = FEEL_ELLIPSE_DEFAULT_CLIPPING_MASK,
        POINT pntCenter = FEEL_ELLIPSE_DEFAULT_CENTER_POINT,
        CFeelEffect* pInsideEffect = NULL  
        );


    BOOL 
    Initialize( 
        CFeelDevice* pDevice, 
        LPCRECT pRectOutside,
        LONG lStiffness = FEEL_ELLIPSE_DEFAULT_STIFFNESS,
        DWORD dwWallWidth = FEEL_ELLIPSE_DEFAULT_WALL_WIDTH,
        DWORD dwSaturation = FEEL_ELLIPSE_DEFAULT_SATURATION,
        DWORD dwStiffnessMask = FEEL_ELLIPSE_DEFAULT_STIFFNESS_MASK,
        DWORD dwClippingMask = FEEL_ELLIPSE_DEFAULT_CLIPPING_MASK,
        CFeelEffect* pInsideEffect = NULL  
        );


    virtual BOOL 
#ifdef FFC_START_DELAY
	StartNow(
#else
	Start(
#endif
        DWORD dwFlags = 0
        );

        
//
// ------ PRIVATE INTERFACE ------ 
//

    //
    // HELPERS
    //

    protected:

    BOOL
        set_parameters( 
        LPCRECT pRectOutside,
        LONG lStiffness,
        DWORD dwWallWidth,
        DWORD dwSaturation,
        DWORD dwStiffnessMask,
        DWORD dwClippingMask,
        CFeelEffect* pInsideEffect  
        );

    //
    // INTERNAL DATA
    //
    
    protected:

    FEELIT_ELLIPSE m_ellipse;
    BOOL m_bUseMousePosAtStart;

};



//
// INLINES
//

inline BOOL
CFeelEllipse::GetIsCompatibleGUID(GUID &guid)
{
	return IsEqualGUID(guid, GUID_Feel_Ellipse);
}

#endif // !defined(AFX_FEELELLIPSE_H__135B88C4_4175_11D1_B049_0020AF30269A__INCLUDED_)
