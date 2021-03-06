/***************************************************************************
**                                                                        **
**  This file is part of SpineCreator, an easy to use, GUI for            **
**  describing spiking neural network models.                             **
**  Copyright (C) 2013 Alex Cope, Paul Richmond                           **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Alex Cope                                            **
**  Website/Contact: http://bimpa.group.shef.ac.uk/                       **
****************************************************************************/

#ifndef LAYOUTEDITPREVIEWDIALOG_H
#define LAYOUTEDITPREVIEWDIALOG_H

#include <QDialog>
#include "globalHeader.h"
#include "nineml_layout_classes.h"
#include "glconnectionwidget.h"

class layoutEditPreviewDialog : public QDialog
{
    Q_OBJECT
public:
    explicit layoutEditPreviewDialog(NineMLLayout *, glConnectionWidget *glConn, QWidget *parent = 0);

    
private:
    NineMLLayout * srcNineMLLayout;
    QFormLayout * contentLayoutRef;
    glConnectionWidget * glView;

signals:
    void drawLayout(vector <loc>);
    
public slots:
    void reDraw(QString);
    
};

#endif // LAYOUTEDITPREVIEWDIALOG_H
