/****************************************************************************
**
** This file is part of the CADuntu project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (caduntu@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software 
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/

#ifndef QG_PENTOOLBAR_H
#define QG_PENTOOLBAR_H

#include <qtoolbar.h>

#include "rs_layerlistlistener.h"
#include "rs_pen.h"

#include "qg_colorbox.h"
#include "qg_widthbox.h"
#include "qg_linetypebox.h"

/**
 * A toolbar that offers all widgets for choosing a pen.
 */
class QG_PenToolBar: public QToolBar,
    public RS_LayerListListener {
    Q_OBJECT

public:
	QG_PenToolBar( const QString & title, QWidget * parent = 0 );
    virtual ~QG_PenToolBar();

    RS_Pen getPen() {
        return currentPen;
    }

    // Methods from RS_LayerListListener Interface:
    virtual void layerActivated(RS_Layer*);
    virtual void layerEdited(RS_Layer*);

public slots:
    void slotColorChanged(const RS_Color& color);
    void slotWidthChanged(RS2::LineWidth w);
    void slotLineTypeChanged(RS2::LineType w);

signals:
    void penChanged(RS_Pen);

private:
    RS_Pen currentPen;
    QG_ColorBox* colorBox;
    QG_WidthBox* widthBox;
    QG_LineTypeBox* lineTypeBox;
};

#endif