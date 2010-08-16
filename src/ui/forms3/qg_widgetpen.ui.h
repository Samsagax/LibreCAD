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

void QG_WidgetPen::setPen(RS_Pen pen, bool showByLayer, 
                          bool showUnchanged, const QString& title) {
    cbColor->init(showByLayer, showUnchanged);
    cbWidth->init(showByLayer, showUnchanged);
    cbLineType->init(showByLayer, showUnchanged);
    if (!showUnchanged) {
       cbColor->setColor(pen.getColor());
       cbWidth->setWidth(pen.getWidth());
       cbLineType->setLineType(pen.getLineType());
    }

    if (!title.isEmpty()) {
        bgPen->setTitle(title);
    }
}

RS_Pen QG_WidgetPen::getPen() {
    RS_Pen pen;

    pen.setColor(cbColor->getColor());
    pen.setWidth(cbWidth->getWidth());
    pen.setLineType(cbLineType->getLineType());

    return pen;
}

bool QG_WidgetPen::isColorUnchanged() {
    return cbColor->isUnchanged();
}

bool QG_WidgetPen::isLineTypeUnchanged() {
    return cbLineType->isUnchanged();
}

bool QG_WidgetPen::isWidthUnchanged() {
    return cbWidth->isUnchanged();
}